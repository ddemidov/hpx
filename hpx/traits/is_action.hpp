//  Copyright (c) 2007-2012 Hartmut Kaiser
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#if !defined(HPX_TRAITS_IS_ACTION_APR_15_2012_0601PM)
#define HPX_TRAITS_IS_ACTION_APR_15_2012_0601PM

#include <hpx/traits.hpp>
#include <hpx/util/always_void.hpp>
#include <boost/mpl/bool.hpp>

namespace hpx { namespace traits
{
    template <typename Action, typename Enable>
    struct is_action
      : boost::mpl::false_
    {};

    template <typename Action>
    struct is_action<Action
      , typename util::always_void<typename Action::action_tag>::type>
      : boost::mpl::true_
    {};

    ///////////////////////////////////////////////////////////////////////////
    template <typename Action>
    struct is_bound_action
      : boost::mpl::false_
    {};
}}

#endif

