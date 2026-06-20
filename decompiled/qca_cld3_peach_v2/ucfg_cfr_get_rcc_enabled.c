bool __fastcall ucfg_cfr_get_rcc_enabled(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  _BOOL4 v18; // w19
  int v19; // w5
  unsigned int *v20; // x8
  __int64 v22; // [xsp+8h] [xbp-18h] BYREF
  __int64 v23[2]; // [xsp+10h] [xbp-10h] BYREF

  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = 0;
  v23[0] = 0;
  if ( (unsigned int)dev_sanity_check(a1, &v22, v23, a2, a3, a4, a5, a6, a7, a8, a9) )
  {
    v18 = 0;
  }
  else
  {
    v19 = *(unsigned __int8 *)(v23[0] + 153);
    if ( v19 == 255 || v19 == *(unsigned __int8 *)(a1 + 168) )
    {
      v20 = (unsigned int *)*(unsigned __int8 *)(v23[0] + 176);
      v18 = ((unsigned __int8)v20 & 0x3F) != 0;
    }
    else
    {
      qdf_trace_msg(
        0x6Au,
        8u,
        "%s: vdev id mismatch, input %d, pcfr %d",
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        "ucfg_cfr_get_rcc_enabled");
      v18 = 0;
    }
    wlan_objmgr_pdev_release_ref(v22, 0x30u, v20, v10, v11, v12, v13, v14, v15, v16, v17);
  }
  _ReadStatusReg(SP_EL0);
  return v18;
}
