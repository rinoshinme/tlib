#ifndef tlib_h
#define tlib_h

// dynamic sized memory
#include "core/array.h"
#include "core/image.h"
#include "core/signal.h"

// fixed sized memory
#include "core/matrix.h"
#include "core/point.h"
#include "core/rect.h"
#include "core/hpoint.h"
#include "core/vector.h"

// extensions
#include "core/sound.h"

// utility functions
#include "core/utility/counter.h"
#include "core/utility/logger.h"
#include "core/utility/stop_watch.h"
#include "core/system/stringops.h"
#include "core/system/path.h"
#include "core/math/rng.h"
#include "core/math/stat.h"
#include "core/math/distribution.h"

// image processing functions
#include "improc/image_filtering.h"
#include "improc/image_integral.h"
#include "improc/image_features.h"
#include "improc/colors.h"
#include "improc/image_io.h"

// supervised learning
#include "supervised_ml/linear_regression.h"
#include "supervised_ml/logistic_regression.h"
#include "supervised_ml/bayesian.h"
#include "supervised_ml/batch.h"
#include "supervised_ml/batch_classify.h"
#include "supervised_ml/perceptron.h"

// unsupervised learning

// neural networks

#endif /* tlib_h */
