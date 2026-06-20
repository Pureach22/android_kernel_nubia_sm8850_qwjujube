__int64 __fastcall ucfg_cfr_set_bw_nss(
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
  unsigned __int64 v20; // x8
  __int64 v21; // x11
  __int64 v22; // x9
  int v23; // w10
  __int64 v24; // x10
  unsigned int *v25; // x8
  unsigned int *v26; // [xsp+8h] [xbp-18h] BYREF
  __int64 v27[2]; // [xsp+10h] [xbp-10h] BYREF

  v27[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = nullptr;
  v27[0] = 0;
  result = dev_sanity_check(a1, (__int64 *)&v26, v27, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !(_DWORD)result )
  {
    v20 = *(_QWORD *)(a2 + 52);
    v21 = v27[0];
    v22 = v27[0] + 35 * ((v20 >> 14) & 0xF);
    v23 = *(_DWORD *)(v22 + 179) & 0xFFFFFFC0 | v20 & 0x3F;
    *(_DWORD *)(v22 + 179) = v23;
    LODWORD(v20) = v23 & 0xFFFFC03F | *(_DWORD *)(a2 + 52) & 0x3FC0;
    v24 = *(_QWORD *)(v21 + 744);
    *(_DWORD *)(v22 + 179) = v20 | 0x300000;
    v25 = v26;
    *(_QWORD *)(v21 + 744) = (1LL << ((*(_QWORD *)(a2 + 52) >> 14) & 0xF)) | v24;
    wlan_objmgr_pdev_release_ref((__int64)v25, 0x30u, v25, v12, v13, v14, v15, v16, v17, v18, v19);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
