#ifndef INCLUDE_LAYERS_DROPOUT_H_
#define INCLUDE_LAYERS_DROPOUT_H_

#include <list>
#include <string>

#include "layers/layer.h"
#include "utils/common.h"

namespace blitz {

template<template <typename> class TensorType, typename DType>
class Dropout : public Layer<TensorType, DType> {
 public:
  explicit Dropout(const string& name, const DType keep) :
    Layer<TensorType, DType>(name), keep_(keep) {}
  ~Dropout() {}

  virtual void InitImpl(const Shape& input_shape);
  virtual void ForwardPropImpl(shared_ptr<TensorType<DType> > forward_input);
  virtual void BackwardPropImpl(shared_ptr<TensorType<DType> > backward_input);

 private:
  const DType keep_;

  shared_ptr<TensorType<DType> > mask_;

  DISABLE_COPY_AND_ASSIGN(Dropout);
};

}  // namespace blitz

#endif  // INCLUDE_LAYERS_DROPOUT_H_
