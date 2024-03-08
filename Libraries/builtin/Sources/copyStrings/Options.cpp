/**
 Copyright (c) 2015-present, Facebook, Inc.
 All rights reserved.

 This source code is licensed under the BSD-style license found in the
 LICENSE file in the root directory of this source tree.
 */

#include <builtin/copyStrings/Options.h>

using builtin::copyStrings::Options;

Options::
Options() :
    _separator(false)
{
}

Options::
~Options()
{
}

std::pair<bool, std::string> Options::
parseArgument(std::vector<std::string> const &args, std::vector<std::string>::const_iterator *it)
{
    std::string const &arg = **it;

    if (!_separator) {
        if (arg == "--validate") {
            return libutil::Options::Current<bool>(&_validate, arg);
        } else if (arg == "--inputencoding") {
            return libutil::Options::Next<std::string>(&_inputEncoding, args, it);
        } else if (arg == "--outputencoding") {
            return libutil::Options::Next<std::string>(&_outputEncoding, args, it);
        } else if (arg == "--outdir") {
            return libutil::Options::Next<std::string>(&_outputDirectory, args, it);
        } else if (arg == "--outfilename") {
            return libutil::Options::Next<std::string>(&_outputFileName, args, it);
        } else if (arg == "--") {
            _separator = true;
            return std::make_pair(true, std::string());
        }
    }

    if (_separator || (!arg.empty() && arg[0] != '-')) {
        return libutil::Options::AppendCurrent<std::string>(&_inputs, arg);
    } else {
        return std::make_pair(false, "unknown argument " + arg);
    }
}

