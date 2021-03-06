//  Copyright (c) 2007-2014 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/// \file migrate_component.hpp

#if !defined(HPX_RUNTIME_COMPONENTS_COPY_MIGRATE_COMPONENT_JAN_31_2014_1009AM)
#define HPX_RUNTIME_COMPONENTS_COPY_MIGRATE_COMPONENT_JAN_31_2014_1009AM

#include <hpx/hpx_fwd.hpp>
#include <hpx/runtime/actions/plain_action.hpp>
#include <hpx/runtime/components/server/migrate_component.hpp>
#include <hpx/runtime/naming/name.hpp>
#include <hpx/lcos/future.hpp>
#include <hpx/lcos/async_colocated.hpp>
#include <hpx/traits/is_component.hpp>

#include <boost/utility/enable_if.hpp>

namespace hpx { namespace components
{
    /// \brief Migrate the given component to the specified target locality
    ///
    /// The function \a migrate<Component> will migrate the component
    /// referenced by \a to_migrate to the locality specified with
    /// \a target_locality. It returns a future referring to the migrated
    /// component instance.
    ///
    /// \param to_migrate      [in] The global id of the component to migrate.
    /// \param target_locality [in] The locality where the component should be 
    ///                        migrated to.
    ///
    /// \tparam  The only template argument specifies the component type of the
    ///          component to migrate.
    ///
    /// \returns A future representing the global id of the newly (copied)
    ///          component instance.
    ///
    /// \note If the second argument is omitted (or is invalid_id) the
    ///       new component instance is created on the locality of the
    ///       component instance which is to be copied.
    ///
    template <typename Component>
#if defined(DOXYGEN)
    future<naming::id_type>
#else
    inline typename boost::enable_if<
        traits::is_component<Component>, future<naming::id_type>
    >::type 
#endif
    migrate(naming::id_type const& to_migrate,
        naming::id_type const& target_locality)
    {
        typedef server::migrate_component_action<Component> action_type;
        return async_colocated<action_type>(to_migrate, to_migrate, target_locality);
    }
}}

#endif
