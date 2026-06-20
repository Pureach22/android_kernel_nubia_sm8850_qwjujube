__int64 __fastcall hdd_send_roam_full_scan_period_to_sme(
        __int64 a1,
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
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 result; // x0
  unsigned __int16 full_roam_scan_period_global; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w19
  int v43; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v44; // [xsp+8h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v43 = 0;
  if ( ucfg_mlme_validate_full_roam_scan_period(a3, a5, a6, a7, a8, a9, a10, a11, a12) )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Received Command to Set full roam scan period = %u",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "hdd_send_roam_full_scan_period_to_sme",
      a3);
    result = sme_get_full_roam_scan_period(*(_QWORD *)(a1 + 16), a2, &v43);
    if ( !(_DWORD)result )
    {
      full_roam_scan_period_global = sme_get_full_roam_scan_period_global(*(_QWORD *)(a1 + 16));
      if ( (a4 & 1) != 0 && v43 != full_roam_scan_period_global )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Full roam scan period is already updated, value: %u",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "hdd_send_roam_full_scan_period_to_sme");
        result = 0;
      }
      else
      {
        result = sme_update_full_roam_scan_period(*(_QWORD *)(a1 + 16), a2, a3);
        if ( (_DWORD)result )
        {
          v42 = result;
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to set full scan period",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "hdd_send_roam_full_scan_period_to_sme");
          result = v42;
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
