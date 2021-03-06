#include "common.h"
#include "caffe2/core/tensor.h"

namespace caffe2 {

void signalFailure(Blob* status_blob, ::gloo::IoException& /* unused */) {
  auto* res = status_blob->GetMutable<TensorCPU>();
  res->Resize(1);
  res->template mutable_data<int32_t>()[0] = 1;
}
}
