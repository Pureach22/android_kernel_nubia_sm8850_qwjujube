__int64 __fastcall cam_csiphy_subdev_compat_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v4; // x22
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x8
  unsigned __int64 v15; // x9
  size_t v16; // x2
  unsigned __int64 v17; // x8
  unsigned __int64 v19; // x9
  __int64 v20; // x0
  int v21; // w0
  int v22; // w20
  const char *v23; // x5
  __int64 v24; // x4
  __int64 result; // x0
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x8
  unsigned __int64 v29; // x9
  unsigned __int64 v30; // x8
  unsigned __int64 v32; // x9
  __int64 v33; // x0
  __int64 v34; // x1
  __int64 v35; // x2
  __int64 v36; // x3
  __int64 v37; // [xsp+0h] [xbp-20h] BYREF
  __int64 v38; // [xsp+8h] [xbp-18h]
  __int64 v39; // [xsp+10h] [xbp-10h]
  __int64 v40; // [xsp+18h] [xbp-8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v4 = _ReadStatusReg(SP_EL0);
  v40 = *(_QWORD *)(StatusReg + 1808);
  LOBYTE(StatusReg) = *(_BYTE *)(v4 + 70);
  v38 = 0;
  v39 = 0;
  v37 = 0;
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
    v16 = _arch_copy_from_user(&v37, a3 & 0xFF7FFFFFFFFFFFFFLL, 24);
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
          0x8000,
          1,
          "cam_csiphy_subdev_compat_ioctl",
          477,
          "Invalid compat ioctl cmd: %d",
          a2);
        result = -515;
        goto LABEL_17;
      }
      v20 = *(_QWORD *)(a1 + 240);
      if ( !v20 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x8000,
          1,
          "cam_csiphy_subdev_ioctl",
          424,
          "csiphy_dev ptr is NULL");
        v22 = -22;
        goto LABEL_16;
      }
      v21 = cam_csiphy_core_cfg(v20, &v37, 0);
      if ( v21 )
      {
        v22 = v21;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x8000,
          1,
          "cam_csiphy_subdev_ioctl",
          433,
          "Failed in configuring the device: %d",
          v21);
LABEL_16:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x8000,
          1,
          "cam_csiphy_subdev_compat_ioctl",
          474,
          "Failed in subdev_ioctl: %d",
          v22);
        result = v22;
        goto LABEL_17;
      }
      if ( (*(_BYTE *)(v4 + 70) & 0x20) != 0 || (v26 = a3, (*(_QWORD *)v4 & 0x4000000) != 0) )
        v26 = a3 & ((__int64)(a3 << 8) >> 8);
      if ( v26 < 0x7FFFFFFFE9LL )
      {
        v27 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v29 = *(_QWORD *)(v4 + 8);
        _WriteStatusReg(TTBR1_EL1, v29 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v29);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v27);
        result = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL);
        v30 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v32 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v32 - 4096);
        _WriteStatusReg(TTBR1_EL1, v32);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v30);
        if ( !result )
          goto LABEL_17;
      }
      v23 = "Failed to copy to user_ptr=%pK size=%zu";
      v24 = 487;
LABEL_13:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int64, __int64, __int64, __int64, __int64, __int64))cam_print_log)(
        3,
        0x8000,
        1,
        "cam_csiphy_subdev_compat_ioctl",
        v24,
        v23,
        a3,
        24,
        v37,
        v38,
        v39,
        v40);
      result = -14;
LABEL_17:
      _ReadStatusReg(SP_EL0);
      return result;
    }
  }
  if ( v16 < 0x19 )
  {
    memset((char *)&v37 - v16 + 24, 0, v16);
    v23 = "Failed to copy from user_ptr=%pK size=%zu";
    v24 = 462;
    goto LABEL_13;
  }
  v33 = _fortify_panic(15, 0, v16);
  return cam_csiphy_drv_ops_util(v33, v34, v35, v36);
}
