﻿/*
 * [The "BSD license"]
 *  Copyright (c) 2016 Mike Lischke
 *  Copyright (c) 2013 Terence Parr
 *  Copyright (c) 2013 Dan McLaughlin
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. The name of the author may not be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 *  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 *  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 *  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 *  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 *  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include "ANTLRErrorListener.h"

namespace antlrcpp {
  class BitSet;
}

namespace org {
namespace antlr {
namespace v4 {
namespace runtime {

  class BaseErrorListener : public ANTLRErrorListener {

    void syntaxError(IRecognizer *recognizer, void *offendingSymbol, size_t line, int charPositionInLine,
                     const std::wstring &msg, RecognitionException *e) { }

    virtual void reportAmbiguity(Parser *recognizer, dfa::DFA *dfa, size_t startIndex, size_t stopIndex, bool exact,
                                 antlrcpp::BitSet *ambigAlts, atn::ATNConfigSet *configs) override;

    virtual void reportAttemptingFullContext(Parser *recognizer, dfa::DFA *dfa, size_t startIndex, size_t stopIndex,
                                             antlrcpp::BitSet *conflictingAlts, atn::ATNConfigSet *configs) override;

    virtual void reportContextSensitivity(Parser *recognizer, dfa::DFA *dfa, size_t startIndex, size_t stopIndex,
                                          int prediction, atn::ATNConfigSet *configs) override;
  };

} // namespace runtime
} // namespace v4
} // namespace antlr
} // namespace org