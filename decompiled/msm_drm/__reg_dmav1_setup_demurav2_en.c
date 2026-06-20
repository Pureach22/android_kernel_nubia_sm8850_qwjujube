__int64 __fastcall _reg_dmav1_setup_demurav2_en(__int64 a1, __int64 *a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v8; // x8
  int v9; // w23
  int v10; // w22
  __int64 v11; // x8
  unsigned int v12; // w9
  int v13; // w4
  int v14; // w6
  int v15; // w7
  __int64 (__fastcall *v16)(_QWORD); // x8
  unsigned int v17; // w19
  char v19; // [xsp+0h] [xbp-10h]
  int v20; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(_QWORD *)(a1 + 72);
  v9 = *(_DWORD *)(a1 + 8);
  v20 = 0;
  v10 = *(_DWORD *)(*(_QWORD *)(v8 + 48) + 568LL);
  _reg_dmav1_setup_demura_common_en(a2, a5, &v20);
  v11 = *a2;
  v12 = ((unsigned int)*a2 >> 2) & 3;
  if ( v12 && v12 != 3 )
    v20 |= (((unsigned int)v11 >> 2) & 3) << 28;
  v13 = v20 | ((_DWORD)v11 << 6) & 0x80 | ((_DWORD)v11 << 6) & 0x40;
  if ( (v11 & 3) != 0 )
    v20 |= ((_DWORD)v11 << 6) & 0x80 | ((_DWORD)v11 << 6) & 0x40;
  _drm_dev_dbg(0, 0, 1, "demura v2 en 0x%x\n", v13);
  sde_evtlog_log(sde_dbg_base_evtlog, "__reg_dmav1_setup_demurav2_en", 8054, -1, v20, -1059143953, v14, v15, v19);
  *(_DWORD *)a3 = 1;
  *(_QWORD *)(a3 + 12) = 0;
  *(_DWORD *)(a3 + 20) = v10 + v9 + 4;
  *(_QWORD *)(a3 + 32) = &v20;
  *(_QWORD *)(a3 + 40) = 0x400000000LL;
  v16 = *(__int64 (__fastcall **)(_QWORD))(a4 + 8);
  if ( *((_DWORD *)v16 - 1) != -1839634494 )
    __break(0x8228u);
  v17 = v16(a3);
  if ( v17 )
    _drm_err("0x4: REG_SINGLE_WRITE failed ret %d\n", v17);
  _ReadStatusReg(SP_EL0);
  return v17;
}
