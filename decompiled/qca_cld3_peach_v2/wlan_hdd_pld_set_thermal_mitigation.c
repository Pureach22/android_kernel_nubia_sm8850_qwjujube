__int64 __fastcall wlan_hdd_pld_set_thermal_mitigation(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  _QWORD *context; // x21
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned int v49; // w0
  unsigned int v50; // w20
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59[2]; // [xsp+0h] [xbp-10h] BYREF

  v59[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v59[0] = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "wlan_hdd_pld_set_thermal_mitigation");
  result = _osif_psoc_sync_op_start(a1, v59, (__int64)"wlan_hdd_pld_set_thermal_mitigation");
  if ( !(_DWORD)result )
  {
    context = _cds_get_context(
                51,
                (__int64)"__wlan_hdd_pld_set_thermal_mitigation",
                v15,
                v16,
                v17,
                v18,
                v19,
                v20,
                v21,
                v22);
    v32 = _wlan_hdd_validate_context(
            (__int64)context,
            (__int64)"__wlan_hdd_pld_set_thermal_mitigation",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31);
    if ( v32 )
    {
LABEL_10:
      v50 = v32;
      _osif_psoc_sync_op_stop(v59[0], (__int64)"wlan_hdd_pld_set_thermal_mitigation");
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: exit",
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        "wlan_hdd_pld_set_thermal_mitigation");
      result = v50;
      goto LABEL_11;
    }
    if ( *((_DWORD *)context + 366) == 2 )
    {
LABEL_4:
      v32 = -22;
      goto LABEL_10;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: PDL_SET for monitor_id: %d, state: %lu",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "__wlan_hdd_pld_set_thermal_mitigation",
      a3,
      a2);
    if ( a3 - 1 >= 2 )
    {
      if ( a3 != 3 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Invalid monitor ID",
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          "__wlan_hdd_pld_set_thermal_mitigation");
        goto LABEL_4;
      }
      v49 = 0;
    }
    else
    {
      v49 = hdd_send_thermal_mitigation_val(context, a2, a3);
    }
    v32 = qdf_status_to_os_return(v49);
    goto LABEL_10;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
