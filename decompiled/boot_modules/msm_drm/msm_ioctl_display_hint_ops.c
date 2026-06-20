__int64 __fastcall msm_ioctl_display_hint_ops(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v8; // x25
  __int64 v11; // x21
  unsigned __int64 v12; // x8
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v14; // x10
  unsigned __int64 v15; // x10
  unsigned __int64 v21; // x9
  size_t v22; // x2
  int v23; // w6
  int v24; // w7
  unsigned __int64 v25; // x8
  unsigned __int64 v27; // x9
  void (__fastcall *v28)(__int64, __int64); // x8
  __int64 result; // x0
  __int64 v30; // x1
  __int64 v31; // x0
  char v32[8]; // [xsp+0h] [xbp-10h] BYREF
  __int64 v33; // [xsp+8h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)v32 = 0;
  if ( !a2 )
  {
    _drm_err("invalid ioctl data\n");
    goto LABEL_21;
  }
  v11 = *(_QWORD *)(*(_QWORD *)(a1 + 56) + 8LL);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "msm_ioctl_display_hint_ops",
    1911,
    -1,
    *(_DWORD *)(a2 + 8),
    -1059143953,
    a7,
    a8,
    v32[0]);
  if ( *(_DWORD *)(a2 + 8) != 1 )
  {
LABEL_16:
    result = 0;
LABEL_22:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v12 = *(_QWORD *)a2;
  if ( !*(_QWORD *)a2 )
  {
    _drm_err("early_wakeup: wrong parameter\n");
LABEL_21:
    result = 4294967274LL;
    goto LABEL_22;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v14 = v12, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v14 = v12 & ((__int64)(v12 << 8) >> 8);
  if ( v14 > 0x7FFFFFFFF8LL )
  {
    v22 = 8;
  }
  else
  {
    v15 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v21 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v21 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v21);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v15);
    v22 = _arch_copy_from_user(v32, v12 & 0xFF7FFFFFFFFFFFFFLL, 8);
    v25 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v27 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v27 - 4096);
    _WriteStatusReg(TTBR1_EL1, v27);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v25);
    if ( !v22 )
    {
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "msm_ioctl_display_hint_ops",
        1929,
        -1,
        *(int *)v32,
        -1059143953,
        v23,
        v24,
        v32[0]);
      if ( v11 && *(_QWORD *)v11 )
      {
        v28 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v11 + 192LL);
        result = 0;
        if ( !v28 || !*(_DWORD *)v32 )
          goto LABEL_22;
        v30 = *(unsigned int *)&v32[4];
        if ( *((_DWORD *)v28 - 1) != -118148984 )
          __break(0x8228u);
        v28(a1, v30);
      }
      goto LABEL_16;
    }
  }
  if ( v22 < 9 )
  {
    memset(&v32[-v22 + 8], 0, v22);
    _drm_err("early_wakeup: copy from user failed\n");
    goto LABEL_21;
  }
  v31 = _fortify_panic(15, 0, v22);
  if ( !v8 )
    JUMPOUT(0x19AD34);
  return msm_ioctl_display_early_ept(v31);
}
