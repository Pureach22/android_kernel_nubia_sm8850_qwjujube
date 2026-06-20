__int64 __fastcall ucfg_cfr_set_en_bitmap(
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
  unsigned int *v20; // x8
  __int64 v21; // x0
  unsigned int *v22; // [xsp+8h] [xbp-18h] BYREF
  __int64 v23[2]; // [xsp+10h] [xbp-10h] BYREF

  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = nullptr;
  v23[0] = 0;
  result = dev_sanity_check(a1, (__int64 *)&v22, v23, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !(_DWORD)result )
  {
    v20 = v22;
    v21 = (__int64)v22;
    *(_WORD *)(v23[0] + 174) = *(_DWORD *)(a2 + 64);
    wlan_objmgr_pdev_release_ref(v21, 0x30u, v20, v12, v13, v14, v15, v16, v17, v18, v19);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
