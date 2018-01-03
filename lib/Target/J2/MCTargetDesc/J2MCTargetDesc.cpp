//===-- J2MCTargetDesc.cpp - J2 Target Descriptions -----------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides J2 specific target descriptions.
//
//===----------------------------------------------------------------------===//

#include "J2MCTargetDesc.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/MC/MCInstrDesc.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#define GET_REGINFO_ENUM
#include "J2GenRegisterInfo.inc"

static MCRegisterInfo *createJ2MCRegisterInfo(const Triple &TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  InitJ2MCRegisterInfo(X, J2::PR);
  return X;
}

extern "C" void LLVMInitializeJ2TargetMC() {
  Target *T = &getTheJ2Target();
  // Register the MC register info.
  TargetRegistry::RegisterMCRegInfo(*T, createJ2MCRegisterInfo);
}
