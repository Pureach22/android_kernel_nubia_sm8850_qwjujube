__int64 __fastcall ucfg_cfr_set_capture_interval(
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
  unsigned int v21; // w9
  unsigned int v22; // w19
  __int64 v23; // [xsp+8h] [xbp-18h] BYREF
  __int64 v24[2]; // [xsp+10h] [xbp-10h] BYREF

  v24[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v24[0] = 0;
  result = dev_sanity_check(a1, &v23, v24, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !(_DWORD)result )
  {
    v20 = (unsigned int *)v24[0];
    v21 = *(_DWORD *)(a2 + 48) & 0xFFFFFF;
    if ( *(_DWORD *)(v24[0] + 156) <= v21 )
    {
      v22 = 0;
      *(_DWORD *)(v24[0] + 160) = v21;
    }
    else
    {
      qdf_trace_msg(
        0x6Au,
        2u,
        "%s: Capture interval should be more than capture duration",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "ucfg_cfr_set_capture_interval");
      v22 = 4;
    }
    wlan_objmgr_pdev_release_ref(v23, 0x30u, v20, v12, v13, v14, v15, v16, v17, v18, v19);
    result = v22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
