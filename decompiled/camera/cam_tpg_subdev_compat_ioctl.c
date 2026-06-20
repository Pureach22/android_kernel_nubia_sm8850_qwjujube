__int64 __fastcall cam_tpg_subdev_compat_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v4; // x22
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x8
  unsigned __int64 v15; // x9
  size_t v16; // x2
  unsigned __int64 v17; // x8
  unsigned __int64 v19; // x9
  int v20; // w0
  int v21; // w20
  __int64 result; // x0
  const char *v23; // x5
  __int64 v24; // x4
  unsigned __int64 v25; // x8
  unsigned __int64 v26; // x8
  unsigned __int64 v28; // x9
  unsigned __int64 v29; // x8
  unsigned __int64 v31; // x9
  __int64 v32; // x0
  __int64 v33; // [xsp+0h] [xbp-20h] BYREF
  __int64 v34; // [xsp+8h] [xbp-18h]
  __int64 v35; // [xsp+10h] [xbp-10h]
  __int64 v36; // [xsp+18h] [xbp-8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v4 = _ReadStatusReg(SP_EL0);
  v36 = *(_QWORD *)(StatusReg + 1808);
  LOBYTE(StatusReg) = *(_BYTE *)(v4 + 70);
  v34 = 0;
  v35 = 0;
  v33 = 0;
  if ( (StatusReg & 0x20) != 0 || (v8 = a3, (*(_QWORD *)v4 & 0x4000000) != 0) )
    v8 = a3 & ((__int64)(a3 << 8) >> 8);
  if ( v8 >= 0x7FFFFFFFE9LL )
  {
    v16 = 24;
  }
  else
  {
    v9 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v15 = *(_QWORD *)(v4 + 8);
    _WriteStatusReg(TTBR1_EL1, v15 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v15);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v9);
    v16 = _arch_copy_from_user(&v33, a3 & 0xFF7FFFFFFFFFFFFFLL, 24);
    v17 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v19 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v19 - 4096);
    _WriteStatusReg(TTBR1_EL1, v19);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v17);
    if ( !v16 )
    {
      if ( a2 != -1072146752 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x200000000LL,
          1,
          "cam_tpg_subdev_compat_ioctl",
          101,
          "Invalid compat ioctl cmd: %d",
          a2);
        result = -515;
        goto LABEL_14;
      }
      v20 = cam_tpg_core_cfg(*(_QWORD *)(a1 + 240), &v33);
      if ( v20 )
      {
        v21 = v20;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x200000000LL,
          1,
          "cam_tpg_subdev_compat_ioctl",
          98,
          "Failed in subdev_ioctl: %d",
          v20);
        result = v21;
LABEL_14:
        _ReadStatusReg(SP_EL0);
        return result;
      }
      if ( (*(_BYTE *)(v4 + 70) & 0x20) != 0 || (v25 = a3, (*(_QWORD *)v4 & 0x4000000) != 0) )
        v25 = a3 & ((__int64)(a3 << 8) >> 8);
      if ( v25 < 0x7FFFFFFFE9LL )
      {
        v26 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v28 = *(_QWORD *)(v4 + 8);
        _WriteStatusReg(TTBR1_EL1, v28 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v28);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v26);
        result = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL);
        v29 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v31 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v31 - 4096);
        _WriteStatusReg(TTBR1_EL1, v31);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v29);
        if ( !result )
          goto LABEL_14;
      }
      v23 = "Failed to copy to user_ptr=%pK size=%zu";
      v24 = 111;
LABEL_12:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int64, __int64, __int64, __int64, __int64, __int64))cam_print_log)(
        3,
        0x200000000LL,
        1,
        "cam_tpg_subdev_compat_ioctl",
        v24,
        v23,
        a3,
        24,
        v33,
        v34,
        v35,
        v36);
      result = -14;
      goto LABEL_14;
    }
  }
  if ( v16 < 0x19 )
  {
    memset((char *)&v33 - v16 + 24, 0, v16);
    v23 = "Failed to copy from user_ptr=%pK size=%zu";
    v24 = 86;
    goto LABEL_12;
  }
  v32 = _fortify_panic(15, 0, v16);
  return cam_tpg_irq_handler(v32, 0x805F000000000000LL);
}
