/* Copyright 2017 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_CORE_GRAPPLER_COSTS_VIRTUAL_PLACER_H_
#define TENSORFLOW_CORE_GRAPPLER_COSTS_VIRTUAL_PLACER_H_

#include <unordered_map>
#include "tensorflow/core/platform/types.h"
#include "tensorflow/core/protobuf/device_properties.pb.h"

namespace tensorflow {
class NodeDef;

namespace grappler {
class Cluster;

// The virtual placer emulates the behavior of the TF placer.
class VirtualPlacer {
 public:
  VirtualPlacer(const Cluster* cluster);

  const DeviceProperties& get_device(const NodeDef& node) const;

  // Returns canonical device name that has a corresponding device in the
  // cluster; returns empty string if no device found or the node.device() can
  // not be parsed.
  string get_canonical_device_name(const NodeDef& node) const;

 private:
  std::unordered_map<string, DeviceProperties> devices_;
  string default_device_;
  const string& get_default_device_name() const;
};

}  // namespace grappler
}  // end namespace tensorflow

#endif  // TENSORFLOW_CORE_GRAPPLER_COSTS_VIRTUAL_PLACER_H_
