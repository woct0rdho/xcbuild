/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree.
 */

#ifndef __builtin_copyStrings_Options_h
#define __builtin_copyStrings_Options_h

#include <libutil/Options.h>

#include <string>
#include <vector>
#include <utility>

namespace builtin {
namespace copyStrings {

class Options {
private:
    std::vector<std::string>   _inputs;
    ext::optional<std::string> _outputDirectory;
    ext::optional<std::string> _outputFileName;

public:
    ext::optional<bool>        _validate;

public:
    ext::optional<std::string> _inputEncoding;
    ext::optional<std::string> _outputEncoding;

public:
    bool                       _separator;

public:
    Options();
    ~Options();

public:
    std::vector<std::string> const &inputs() const
    { return _inputs; }
    ext::optional<std::string> const &outputDirectory() const
    { return _outputDirectory; }
    ext::optional<std::string> const &outputFileName() const
    { return _outputFileName; }

public:
    bool validate() const
    { return _validate.value_or(false); }

public:
    ext::optional<std::string> const &inputEncoding() const
    { return _inputEncoding; }
    ext::optional<std::string> const &outputEncoding() const
    { return _outputEncoding; }

private:
    friend class libutil::Options;
    std::pair<bool, std::string>
    parseArgument(std::vector<std::string> const &args, std::vector<std::string>::const_iterator *it);
};

}
}

#endif // !__builtin_copyStrings_Options_h
