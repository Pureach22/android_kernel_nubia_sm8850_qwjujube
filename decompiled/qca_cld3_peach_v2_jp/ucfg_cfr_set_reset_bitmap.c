__int64 __fastcall ucfg_cfr_set_reset_bitmap(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  __int64 v13; // x1
  unsigned int *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v24[2]; // [xsp+10h] [xbp-10h] BYREF

  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v24[0] = 0;
  result = dev_sanity_check(a1, &v23, v24);
  if ( !(_DWORD)result )
  {
    v12 = v23;
    v13 = v24[0] + 152LL;
    *(_QWORD *)(v24[0] + 744LL) |= *(unsigned __int16 *)(a2 + 66);
    tgt_cfr_default_ta_ra_cfg(v12, v13, 1, *(unsigned __int16 *)(a2 + 66), v4, v5, v6, v7, v8, v9, v10, v11);
    wlan_objmgr_pdev_release_ref(v12, 0x30u, v14, v15, v16, v17, v18, v19, v20, v21, v22);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
