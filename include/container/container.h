/**
 * @file container.h
 * @author M Zaki (zaki.x86@gmail.com)
 * @brief container library header file
 * @version 0.1
 * @date 2022-12-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef _CONTAINER_H_

#define _CONTAINER_H_

#include "sequence_container/array.h"
#include "sequence_container/darray.h"
#include "sequence_container/forward_list.h"
#include "sequence_container/list.h"
#include "associative_container/hash_table.h"
#include "associative_container/set.h"
#include "associative_container/map.h"
#include "associative_container/multiset.h"
#include "associative_container/multimap.h"
#include "associative_container/unordered_set.h"
#include "associative_container/unordered_map.h"
#include "associative_container/unordered_multiset.h"
#include "associative_container/unordered_multimap.h"
#include "adaptor_container/stack.h"
#include "adaptor_container/queue.h"


/**
 * @brief Main namespace for all `zxx::` libraries.
 */
namespace zxx
{
    /**
     * @brief Core namespace for all basic facilities that `zxx` provides, including but not limited to: algorithm, container, memory, ... etc.
     */
    namespace core {

        /**
         * @brief Container namespace for all data structures defines with `zxx::core` library.
         */
        namespace container {
            
            /**
             * @brief Test namespace, in which test cases and mocks of `zxx::core::container` components are defined.
             */
            namespace test
            {
                
            } // namespace test
            
        }

    }
}

#endif