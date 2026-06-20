__int64 __fastcall ucfg_cfr_set_frame_type_subtype(
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
  __int64 v23; // x10
  unsigned int *v24; // x8
  unsigned int *v25; // [xsp+8h] [xbp-18h] BYREF
  __int64 v26[2]; // [xsp+10h] [xbp-10h] BYREF

  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = nullptr;
  v26[0] = 0;
  result = dev_sanity_check(a1, (__int64 *)&v25, v26, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !(_DWORD)result )
  {
    v20 = *(_QWORD *)(a2 + 52);
    v21 = v26[0];
    v22 = v26[0] + 35 * ((v20 >> 14) & 0xF);
    *(_WORD *)(v22 + 183) = WORD2(v20);
    *(_WORD *)(v22 + 185) = *(_WORD *)(a2 + 58);
    LODWORD(v20) = *(_DWORD *)(v22 + 179) | 0x1C00000;
    *(_WORD *)(v22 + 187) = *(_QWORD *)(a2 + 60);
    v23 = *(_QWORD *)(v21 + 744);
    *(_DWORD *)(v22 + 179) = v20;
    v24 = v25;
    *(_QWORD *)(v21 + 744) = (1LL << ((*(_QWORD *)(a2 + 52) >> 14) & 0xF)) | v23;
    wlan_objmgr_pdev_release_ref((__int64)v24, 0x30u, v24, v12, v13, v14, v15, v16, v17, v18, v19);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
