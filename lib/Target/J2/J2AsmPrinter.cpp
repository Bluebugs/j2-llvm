//===-- J2AsmPrinter.cpp - J2 Register Information -== --------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// J2 Assembly printer class.
//
//===----------------------------------------------------------------------===//

#include "J2AsmPrinter.h"
#include "InstPrinter/J2InstPrinter.h"
#include "MCTargetDesc/J2MCTargetDesc.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

void J2AsmPrinter::EmitFunctionEntryLabel() {
  OutStreamer->EmitLabel(CurrentFnSym);
}

extern "C" void LLVMInitializeJ2AsmPrinter() {
  RegisterAsmPrinter<J2AsmPrinter> X(getTheJ2Target());
}
