// Copyright (c) 2016-2017 Kumina, https://kumina.nl/
//
// This file is distributed under a 2-clause BSD license.
// See the LICENSE file for details.

#ifndef METRICS_PAGE_H
#define METRICS_PAGE_H

#include <ostream>
#include <string>
#include <string_view>

class MetricsLabels;

// Adapter for rendering pages containing metrics.
//
// Instead of letting all of the code print metrics straight to an
// ostream, this class acts like an adapter. Callers can simply call
// PrintMetric(), providing it a name, a set of labels and a value.
class MetricsPage {
 public:
  MetricsPage(std::string_view prefix, std::ostream* output)
      : prefix_(prefix), output_(output) {
  }

  // Writes a metric to the output in the form '$prefix$name{$labels} $value'.
  void PrintMetric(std::string_view name, const MetricsLabels& labels,
                   std::uint64_t value);

 private:
  const std::string prefix_;
  std::ostream* const output_;
};

#endif
