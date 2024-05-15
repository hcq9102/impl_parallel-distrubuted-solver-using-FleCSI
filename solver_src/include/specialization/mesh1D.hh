#ifndef SPRINGMASS_SPECIALIZATION_MESH1D_HH
#define SPRINGMASS_SPECIALIZATION_MESH1D_HH

#include <flecsi/topo/narray/coloring_utils.hh>
#include <flecsi/topo/narray/interface.hh>

#include "types.hh"

namespace springmass {

// Define a specialization for a 1D mesh
struct mesh : flecsi::topo::specialization<flecsi::topo::narray, mesh>  {
  // Define the index space for the nodes
  enum index_space { vertices };
  using index_spaces = has<vertices>;

  // Define the domain and axis
  enum domain {interior, logical, all, global, boundary_low, boundary_high}; 
  enum axis { x_axis };
  using axes = has<x_axis>;
  // enum boundary { low, high };

  // define the dimension
  static constexpr std::size_t dimension = 1;

  template<auto>
  static constexpr std::size_t privilege_count = 2; // owned & ghost  cells

  using gcoord = typename mesh::base::gcoord;
  //using axis_definition = typename mesh::base::axis_definition;
  using index_definition = typename mesh::base::index_definition;

  struct meta_data {
    // empty
  };

  /*--------------------------------------------------------------------------*
    Color Method.
   *--------------------------------------------------------------------------*/
  // Define a distributed color type
  // only have x, so axis_extents only have x. so can directly access halo depth
  // =1, which means need one halo cell--the ghost cell.
  static coloring color(std::size_t num_colors, const gcoord & axis_extents) {
    index_definition idef;
    idef.axes = flecsi::topo::narray_utils::make_axes(num_colors, axis_extents);
    idef.axes[0].hdepth = 1; // add one layer of ghost
    idef.axes[0].bdepth = 1; // add one layer of boundary - boundary layer

    return {{idef}};
  } // color

  /*--------------------------------------------------------------------------*
    Interface
   *--------------------------------------------------------------------------*/
  template <class B> struct interface : B {

    // provide a method to iterate/traverse all the vertices i.e.
    // for (auto i : mesh.vertices()) { ... }
    template <axis A, domain DM = interior>
    FLECSI_INLINE_TARGET auto vertices() const {
      if constexpr (DM == interior) {
        // The outermost layer is either ghosts or fixed boundaries:
        return flecsi::topo::make_ids<mesh::vertices>(
            flecsi::util::iota_view<flecsi::util::id>(
                1,B::template size<mesh::vertices, A, base::domain::all>() - 1));
      } else if constexpr (DM == logical) {
        return B::template range<mesh::vertices, A, base::domain::logical>();
      } else if constexpr (DM == all) {
        return B::template range<mesh::vertices, A, base::domain::all>();
      }else if constexpr (DM == boundary_low) {
        return B::template range<mesh::vertices, A, base::domain::boundary_low>();
      }else if constexpr (DM == boundary_high) {
        return B::template range<mesh::vertices, A, base::domain::boundary_high>();
      }
    }

    // given a local id, returns the corresponding global id
    template<axis A>
    FLECSI_INLINE_TARGET auto global_id(std::size_t localid) const {
      return B::template global_id<mesh::vertices, A>(localid);
    }



  }; // struct interface
};

} // namespace springmass

#endif