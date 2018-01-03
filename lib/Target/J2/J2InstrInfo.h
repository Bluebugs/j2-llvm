//===-- J2InstrInfo.h - J2 Instruction Information --------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the J2 implementation of the TargetInstrInfo class.
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_J2_J2INSTRINFO_H
#define LLVM_LIB_TARGET_J2_J2INSTRINFO_H

#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "J2GenInstrInfo.inc"

namespace llvm {
class J2InstrInfo : public J2GenInstrInfo {
  void copyPhysReg(MachineBasicBlock &MBB, MachineBasicBlock::iterator MI,
                   const DebugLoc &DL, unsigned DestReg, unsigned SrcReg,
                   bool KillSrc) const override;

  void storeRegToStackSlot(MachineBasicBlock &MBB,
                           MachineBasicBlock::iterator MI, unsigned SrcReg,
                           bool isKill, int FrameIndex,
                           const TargetRegisterClass *RC,
                           const TargetRegisterInfo *TRI) const override;

  void loadRegFromStackSlot(MachineBasicBlock &MBB,
                          MachineBasicBlock::iterator MI, unsigned DstReg,
                          int FrameIndex, const TargetRegisterClass *RC,
                          const TargetRegisterInfo *TRI) const override;
};
}

#endif
