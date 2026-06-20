// positive sp value has been detected, the output may be wrong!
__int64 sub_12F9B8()
{
  unsigned __int64 v0; // x19
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v8; // x9

  result = _arch_copy_to_user(v0 & 0xFF7FFFFFFFFFFFFFLL);
  StatusReg = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v8 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v8 - 4096);
  _WriteStatusReg(TTBR1_EL1, v8);
  __isb(0xFu);
  _WriteStatusReg(DAIF, StatusReg);
  if ( result )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      2,
      1,
      "cam_subdev_compat_ioctl",
      112,
      "Failed to copy to user_ptr=%pK size=%zu",
      (const void *)v0,
      0x18u);
    result = -14;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
