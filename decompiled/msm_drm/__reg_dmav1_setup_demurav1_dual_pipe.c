__int64 __fastcall _reg_dmav1_setup_demurav1_dual_pipe(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v5; // w9
  int v6; // w8
  int v7; // w10
  unsigned int v8; // w10
  unsigned int v9; // w11
  __int64 (__fastcall *v10)(_QWORD); // x8
  unsigned int v11; // w20
  char v13; // [xsp+0h] [xbp-10h]
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD *)(a1 + 8);
  v6 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 568LL);
  if ( *(_DWORD *)(*(_QWORD *)(a2 + 48) + 64LL) == *(_DWORD *)(a1 + 64) )
  {
    v7 = 0;
  }
  else
  {
    v8 = *(_DWORD *)(a2 + 96);
    if ( v8 >= *(_DWORD *)(a2 + 92) )
      v9 = 0x2000000;
    else
      v9 = 0x1000000;
    v7 = v9 / v8 * (v8 >> 1);
  }
  *(_QWORD *)(a3 + 12) = 0;
  *(_DWORD *)(a3 + 20) = v6 + v5 + 88;
  *(_DWORD *)a3 = 1;
  *(_QWORD *)(a3 + 32) = &v14;
  *(_QWORD *)(a3 + 40) = 0x400000000LL;
  v10 = *(__int64 (__fastcall **)(_QWORD))(a4 + 8);
  v14 = v7;
  if ( *((_DWORD *)v10 - 1) != -1839634494 )
    __break(0x8228u);
  v11 = v10(a3);
  if ( v11 )
    _drm_err("0x58: REG_SINGLE_WRITE failed ret %d\n", v11);
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "__reg_dmav1_setup_demurav1_dual_pipe",
    8131,
    -1,
    88,
    v14,
    *(_DWORD *)(a1 + 64),
    -1059143953,
    v13);
  _ReadStatusReg(SP_EL0);
  return v11;
}
