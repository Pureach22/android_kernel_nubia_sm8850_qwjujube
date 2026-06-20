__int64 __fastcall wlan_hdd_qmi_get_sync_resume(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  _QWORD *context; // x20
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  _QWORD *v17; // x19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  context = _cds_get_context(51, (__int64)"wlan_hdd_qmi_get_sync_resume", a1, a2, a3, a4, a5, a6, a7, a8);
  v17 = _cds_get_context(64, (__int64)"wlan_hdd_qmi_get_sync_resume", v9, v10, v11, v12, v13, v14, v15, v16);
  if ( (unsigned int)_wlan_hdd_validate_context(
                       (__int64)context,
                       (__int64)"wlan_hdd_qmi_get_sync_resume",
                       v18,
                       v19,
                       v20,
                       v21,
                       v22,
                       v23,
                       v24,
                       v25) )
    return 4294967274LL;
  if ( (*(_BYTE *)(context[13] + 124LL) & 1) != 0 )
  {
    if ( !v17 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: qdf_ctx is null",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "wlan_hdd_qmi_get_sync_resume");
      return 4294967274LL;
    }
    return pld_qmi_send_get(v17[5]);
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: periodic stats over qmi is disabled",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "wlan_hdd_qmi_get_sync_resume");
    return 0;
  }
}
