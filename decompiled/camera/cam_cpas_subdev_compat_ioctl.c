__int64 __fastcall cam_cpas_subdev_compat_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 v3; // x8
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  const void *v8; // x6
  unsigned __int64 v9; // x9
  unsigned __int64 v10; // x9
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x8
  unsigned __int64 v19; // x9
  _QWORD v20[4]; // [xsp+0h] [xbp-20h] BYREF

  v20[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 240);
  memset(v20, 0, 24);
  if ( v3 && (*(_BYTE *)(v3 + 852) & 1) != 0 )
  {
    if ( inline_copy_from_user_3((__int64)v20, a3, 0x18u) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_subdev_compat_ioctl",
        1988,
        "Failed to copy from user_ptr=%pK size=%zu",
        (const void *)a3,
        0x18u);
      result = -14;
    }
    else
    {
      if ( a2 == -1072146752 )
      {
        LODWORD(result) = cam_cpas_subdev_cmd(0, (unsigned int *)v20);
        if ( !(_DWORD)result )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          v8 = (const void *)a3;
          if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v9 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
            v9 = a3 & ((__int64)(a3 << 8) >> 8);
          if ( v9 > 0x7FFFFFFFE8LL )
            goto LABEL_14;
          v10 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v16 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v16 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v16);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v10);
          result = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL);
          v17 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v19 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v19 - 4096);
          _WriteStatusReg(TTBR1_EL1, v19);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v17);
          v8 = (const void *)a3;
          if ( result )
          {
LABEL_14:
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              4,
              1,
              "cam_cpas_subdev_compat_ioctl",
              2007,
              "Failed to copy to user_ptr=%pK size=%zu",
              v8,
              0x18u);
            LODWORD(result) = -14;
          }
        }
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_subdev_compat_ioctl",
          1997,
          "Invalid command %d for CPAS!",
          a2);
        LODWORD(result) = -22;
      }
      result = (int)result;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_subdev_compat_ioctl",
      1981,
      "CPAS not initialized");
    result = -19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
