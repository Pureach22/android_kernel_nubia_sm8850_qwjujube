void __fastcall sme_rrm_scan_event_callback(
        __int64 a1,
        _DWORD *a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v12; // w21
  unsigned int v13; // w20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x8
  _DWORD *v24; // x22
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  int v33; // w4
  unsigned int *v34; // x3
  _BYTE v35[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+8h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35[0] = 0;
  if ( a3 )
  {
    v12 = a2[5];
    v13 = *(unsigned __int8 *)(a1 + 168);
    qdf_mtrace(21, 52, a2[1], *a2, v12);
    if ( (util_is_scan_completed((__int64)a2, v35) & 1) != 0 )
    {
      if ( a3[4407] == v12 )
      {
        v23 = 4372;
      }
      else if ( a3[4543] == v12 )
      {
        v23 = 4508;
      }
      else if ( a3[4679] == v12 )
      {
        v23 = 4644;
      }
      else if ( a3[4815] == v12 )
      {
        v23 = 4780;
      }
      else
      {
        if ( a3[4951] != v12 )
          goto LABEL_23;
        v23 = 4916;
      }
      v24 = &a3[v23];
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: vdev: %d : Scan completed for scan_id:%d idx:%d, type:%d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "sme_rrm_scan_event_callback",
        v13,
        v12,
        BYTE1(a3[v23 + 2]),
        (unsigned int)a3[v23 + 3]);
      v33 = v24[3];
      if ( v33 == 1 )
      {
        v34 = *((unsigned int **)v24 + 8);
        if ( v34 )
        {
          sme_rrm_send_scan_result((__int64)a3, *((unsigned __int8 *)v24 + 9), *((_BYTE *)v24 + 56), v34, 1u);
          _qdf_mem_free(*((_QWORD *)v24 + 8));
          *((_QWORD *)v24 + 8) = 0;
          *((_BYTE *)v24 + 56) = 0;
          if ( !v24 )
            goto LABEL_23;
        }
        else
        {
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: [802.11 RRM]: Global freq list is null",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "sme_rrm_scan_request_callback");
          *((_BYTE *)v24 + 56) = 0;
          if ( !v24 )
            goto LABEL_23;
        }
        *((_BYTE *)v24 + 532) = 0;
        goto LABEL_23;
      }
      if ( v33 )
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Unknown measurement_type: %d",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "sme_rrm_scan_event_callback");
      else
        sme_rrm_send_chan_load_report_xmit_ind(a3, v24, v13, 1);
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: invalid mac_ctx", a4, a5, a6, a7, a8, a9, a10, a11, "sme_rrm_scan_event_callback");
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
}
