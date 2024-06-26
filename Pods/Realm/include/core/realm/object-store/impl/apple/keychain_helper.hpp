////////////////////////////////////////////////////////////////////////////
//
// Copyright 2016 Realm Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
////////////////////////////////////////////////////////////////////////////

#ifndef REALM_OS_KEYCHAIN_HELPER_HPP
#define REALM_OS_KEYCHAIN_HELPER_HPP

#include <realm/util/features.h>

#if REALM_PLATFORM_APPLE

#include <optional>
#include <string_view>
#include <vector>

namespace realm::keychain {

// Get the stored encryption key for the metadata realm if one exists.
std::optional<std::vector<char>> get_existing_metadata_realm_key(std::string_view app_id,
                                                                 std::string_view access_group);
// Create a new encryption key and store it in the keychain. Returns none if
// the key could not be stored.
std::optional<std::vector<char>> create_new_metadata_realm_key(std::string_view app_id,
                                                               std::string_view access_group);

// Delete the encryption key for the metadata realm from the keychain.
void delete_metadata_realm_encryption_key(std::string_view app_id, std::string_view access_group);

} // namespace realm::keychain

#endif // REALM_PLATFORM_APPLE

#endif // REALM_OS_KEYCHAIN_HELPER_HPP
