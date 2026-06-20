__int64 __fastcall hdd_send_roam_scan_period_to_sme(
        __int64 *a1,
        unsigned int a2,
        unsigned int a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v13; // w21
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w19
  _WORD v44[2]; // [xsp+0h] [xbp-10h] BYREF
  unsigned __int16 v45; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v46; // [xsp+8h] [xbp-8h]

  v13 = 1000 * a3;
  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = *a1;
  v45 = 0;
  v44[0] = 0;
  if ( ucfg_mlme_validate_scan_period(a5, a6, a7, a8, a9, a10, a11, a12, v17, 1000 * a3) )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Received Command to Set roam scan period (Empty Scan refresh period) = %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "hdd_send_roam_scan_period_to_sme",
      a3);
    result = ucfg_cm_get_empty_scan_refresh_period(*a1, a2, &v45);
    if ( !(_DWORD)result )
    {
      ucfg_cm_get_empty_scan_refresh_period_global(*a1, v44);
      if ( (a4 & 1) != 0 && v45 != v44[0] )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: roam scan period is already updated, value: %u",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "hdd_send_roam_scan_period_to_sme",
          v45 / 0x3E8uLL);
        result = 0;
      }
      else
      {
        result = sme_update_empty_scan_refresh_period(a1[2], a2, v13);
        if ( (_DWORD)result )
        {
          v43 = result;
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to set scan period",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "hdd_send_roam_scan_period_to_sme");
          result = v43;
        }
      }
    }
  }
  else
  {
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
