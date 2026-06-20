__int64 __fastcall _reg_dmav1_setup_demurav1_en(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v7; // x8
  int v8; // w22
  int v9; // w21
  int v10; // w6
  int v11; // w7
  __int64 (__fastcall *v12)(_QWORD); // x8
  unsigned int v13; // w19
  char v15; // [xsp+0h] [xbp-10h]
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 72);
  v8 = *(_DWORD *)(a1 + 8);
  v16 = 0;
  v9 = *(_DWORD *)(*(_QWORD *)(v7 + 48) + 568LL);
  _reg_dmav1_setup_demura_common_en(a2, a5, &v16);
  _drm_dev_dbg(0, 0, 1, "demura v1 en 0x%x\n", v16);
  sde_evtlog_log(sde_dbg_base_evtlog, "__reg_dmav1_setup_demurav1_en", 8020, -1, v16, -1059143953, v10, v11, v15);
  *(_DWORD *)a3 = 1;
  *(_QWORD *)(a3 + 12) = 0;
  *(_DWORD *)(a3 + 20) = v9 + v8 + 4;
  *(_QWORD *)(a3 + 32) = &v16;
  *(_QWORD *)(a3 + 40) = 0x400000000LL;
  v12 = *(__int64 (__fastcall **)(_QWORD))(a4 + 8);
  if ( *((_DWORD *)v12 - 1) != -1839634494 )
    __break(0x8228u);
  v13 = v12(a3);
  if ( v13 )
    _drm_err("0x4: REG_SINGLE_WRITE failed ret %d\n", v13);
  _ReadStatusReg(SP_EL0);
  return v13;
}
