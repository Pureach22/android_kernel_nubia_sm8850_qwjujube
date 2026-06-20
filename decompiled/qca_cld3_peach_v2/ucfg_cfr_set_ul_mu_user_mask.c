__int64 __fastcall ucfg_cfr_set_ul_mu_user_mask(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x9
  unsigned int *v21; // x8
  __int64 v22; // x0
  unsigned int *v23; // [xsp+8h] [xbp-18h] BYREF
  __int64 v24[2]; // [xsp+10h] [xbp-10h] BYREF

  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = nullptr;
  v24[0] = 0;
  result = dev_sanity_check(a1, (__int64 *)&v23, v24, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !(_DWORD)result )
  {
    v20 = v24[0];
    *(_DWORD *)(v24[0] + 164) = *(_DWORD *)(a2 + 68);
    v21 = v23;
    v22 = (__int64)v23;
    *(_DWORD *)(v20 + 168) = *(_DWORD *)(a2 + 72);
    wlan_objmgr_pdev_release_ref(v22, 0x30u, v21, v12, v13, v14, v15, v16, v17, v18, v19);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
