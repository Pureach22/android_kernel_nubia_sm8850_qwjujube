__int64 __fastcall ucfg_cfr_set_capture_duration(
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
  unsigned int v21; // w10
  unsigned int v22; // w9
  unsigned int v23; // w19
  __int64 v24; // [xsp+8h] [xbp-18h] BYREF
  __int64 v25[2]; // [xsp+10h] [xbp-10h] BYREF

  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = 0;
  v25[0] = 0;
  result = dev_sanity_check(a1, &v24, v25, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !(_DWORD)result )
  {
    v20 = (unsigned int *)v25[0];
    v21 = *(_DWORD *)(v25[0] + 160);
    v22 = *(_DWORD *)(a2 + 44) & 0xFFFFFF;
    if ( v21 && v22 > v21 )
    {
      qdf_trace_msg(
        0x6Au,
        2u,
        "%s: Capture duration is exceeding capture interval",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "ucfg_cfr_set_capture_duration");
      v23 = 4;
    }
    else
    {
      v23 = 0;
      *(_DWORD *)(v25[0] + 156) = v22;
    }
    wlan_objmgr_pdev_release_ref(v24, 0x30u, v20, v12, v13, v14, v15, v16, v17, v18, v19);
    result = v23;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
