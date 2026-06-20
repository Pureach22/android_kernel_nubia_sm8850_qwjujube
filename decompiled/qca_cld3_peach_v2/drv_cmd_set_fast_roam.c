__int64 __fastcall drv_cmd_set_fast_roam(__int64 a1, __int64 *a2, __int64 a3, unsigned __int8 a4)
{
  unsigned int v6; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x21
  __int64 result; // x0
  unsigned __int8 v26[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26[0] = 1;
  v6 = kstrtou8(a3 + a4 + 1, 10, v26);
  if ( (v6 & 0x80000000) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: kstrtou8 failed range [%d - %d]",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "drv_cmd_set_fast_roam",
      0,
      1);
    result = 4294967274LL;
  }
  else
  {
    v15 = v6;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Received Command to change lfr mode = %d",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "drv_cmd_set_fast_roam",
      v26[0]);
    if ( (sme_roaming_in_progress(a2[2], *(unsigned __int8 *)(a1 + 8)) & 1) != 0 )
    {
      v24 = jiffies;
      if ( drv_cmd_set_fast_roam___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Roaming in progress for vdev %d",
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          "drv_cmd_set_fast_roam",
          *(unsigned __int8 *)(a1 + 8));
        drv_cmd_set_fast_roam___last_ticks = v24;
      }
      result = 4294967285LL;
    }
    else
    {
      ucfg_mlme_set_lfr_enabled(*a2, v26[0] != 0);
      sme_update_is_fast_roam_ini_feature_enabled(a2[2], *(unsigned __int8 *)(a1 + 8), v26[0] != 0);
      result = v15;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
