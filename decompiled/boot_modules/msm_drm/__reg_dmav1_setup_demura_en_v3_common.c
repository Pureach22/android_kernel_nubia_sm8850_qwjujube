__int64 __fastcall _reg_dmav1_setup_demura_en_v3_common(
        __int64 a1,
        __int64 *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        int a6)
{
  __int64 v10; // x8
  int v11; // w24
  int v12; // w23
  int v13; // w6
  int v14; // w7
  __int64 v15; // x8
  unsigned int v16; // w10
  int v17; // w9
  int v18; // w24
  __int64 (__fastcall *v19)(_QWORD); // x8
  unsigned int v20; // w0
  int v21; // w6
  int v22; // w7
  unsigned int v23; // w23
  char v24; // w9
  int v25; // w8
  __int64 (__fastcall *v26)(_QWORD); // x8
  char v28; // [xsp+0h] [xbp-10h]
  char v29; // [xsp+0h] [xbp-10h]
  int v30; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 72);
  v11 = *(_DWORD *)(a1 + 8);
  v30 = 0;
  v12 = *(_DWORD *)(*(_QWORD *)(v10 + 48) + 568LL);
  _reg_dmav1_setup_demura_common_en(a2, a5, &v30);
  v15 = *a2;
  v16 = ((unsigned int)*a2 >> 2) & 3;
  v17 = v30 & 0x7FFFFFFF;
  v30 &= ~0x80000000;
  if ( v16 && v16 != 3 )
  {
    v17 |= (((unsigned int)v15 >> 2) & 3) << 28;
    v30 = v17;
  }
  v18 = v11 + v12;
  if ( (v15 & 3) != 0 )
    v30 = v17 | ((_DWORD)v15 << 6) & 0x80 | ((_DWORD)v15 << 6) & 0x40;
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "__reg_dmav1_setup_demura_en_v3_common",
    8598,
    -1,
    v17 | ((_DWORD)v15 << 6) & 0x80 | ((_DWORD)v15 << 6) & 0x40,
    -1059143953,
    v13,
    v14,
    v28);
  *(_QWORD *)(a3 + 12) = 0;
  *(_DWORD *)a3 = 1;
  *(_DWORD *)(a3 + 20) = v18 + 4;
  *(_QWORD *)(a3 + 32) = &v30;
  *(_QWORD *)(a3 + 40) = 0x400000000LL;
  v19 = *(__int64 (__fastcall **)(_QWORD))(a4 + 8);
  if ( *((_DWORD *)v19 - 1) != -1839634494 )
    __break(0x8228u);
  v20 = v19(a3);
  if ( v20 )
  {
    v23 = v20;
    _drm_err("0x4: REG_SINGLE_WRITE failed ret %d\n", v20);
  }
  else
  {
    v24 = *(_BYTE *)a2;
    if ( *((_DWORD *)a2 + 2093) == 8 )
      v25 = 3;
    else
      v25 = 1;
    v30 = v25;
    if ( (v24 & 2) != 0 )
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "__reg_dmav1_setup_demura_en_v3_common",
        8611,
        -1,
        a6,
        -1059143953,
        v21,
        v22,
        v29);
    *(_QWORD *)(a3 + 12) = 0;
    *(_DWORD *)a3 = 1;
    *(_DWORD *)(a3 + 20) = v18 + 24;
    *(_QWORD *)(a3 + 32) = &v30;
    *(_QWORD *)(a3 + 40) = 0x400000000LL;
    v26 = *(__int64 (__fastcall **)(_QWORD))(a4 + 8);
    if ( *((_DWORD *)v26 - 1) != -1839634494 )
      __break(0x8228u);
    v23 = v26(a3);
    if ( v23 )
      _drm_err("0x18: REG_SINGLE_WRITE failed ret %d\n", v23);
  }
  _ReadStatusReg(SP_EL0);
  return v23;
}
