__int64 __fastcall cam_flash_subdev_do_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  const char *v6; // x5
  __int64 v7; // x4
  __int64 result; // x0
  int v9; // w20
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v11; // x9
  unsigned __int64 v12; // x9
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x8
  unsigned __int64 v21; // x9
  _QWORD v22[4]; // [xsp+0h] [xbp-20h] BYREF

  v22[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v22, 0, 24);
  if ( inline_copy_from_user_12(v22, a3) )
  {
    v6 = "Failed to copy from user_ptr=%pK size=%zu";
    v7 = 439;
LABEL_3:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int64, __int64))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_subdev_do_ioctl",
      v7,
      v6,
      a3,
      24);
    result = -14;
    goto LABEL_8;
  }
  if ( a2 != -1072146752 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_subdev_do_ioctl",
      452,
      "Invalid compat ioctl cmd_type:%d",
      a2);
    result = -515;
    goto LABEL_8;
  }
  v9 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD *))cam_flash_subdev_ioctl)(a1, 3222820544LL, v22);
  if ( v9 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_subdev_do_ioctl",
      447,
      "cam_flash_ioctl failed");
    result = v9;
    goto LABEL_8;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v11 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v11 = a3 & ((__int64)(a3 << 8) >> 8);
  if ( v11 > 0x7FFFFFFFE8LL )
    goto LABEL_14;
  v12 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v18 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v18 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v18);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v12);
  result = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL);
  v19 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v21 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v21 - 4096);
  _WriteStatusReg(TTBR1_EL1, v21);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v19);
  if ( result )
  {
LABEL_14:
    v6 = "Failed to copy to user_ptr=%pK size=%zu";
    v7 = 462;
    goto LABEL_3;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
