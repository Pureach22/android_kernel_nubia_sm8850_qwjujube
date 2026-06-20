__int64 __fastcall wlan_hdd_get_linkspeed_for_peermac(
        __int64 *a1,
        int *a2,
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
  __int64 v12; // x25
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x21
  __int64 v25; // x24
  __int64 v26; // x0
  int v27; // w9
  __int64 v28; // x22
  unsigned int link_speed; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w23
  unsigned int v39; // w23
  __int64 result; // x0
  unsigned int v41; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7

  if ( a3 )
  {
    v12 = *a1;
    v15 = osif_request_alloc(wlan_hdd_get_linkspeed_for_peermac_params);
    if ( v15 )
    {
      v24 = v15;
      v25 = osif_request_cookie(v15);
      v26 = osif_request_priv(v24);
      v27 = *a2;
      v28 = v26;
      *(_WORD *)(v26 + 4) = *((_WORD *)a2 + 2);
      *(_DWORD *)v26 = v27;
      link_speed = sme_get_link_speed(*(_QWORD *)(*(_QWORD *)(v12 + 24) + 16LL), v26, v25, hdd_get_link_speed_cb);
      if ( link_speed )
      {
        v38 = link_speed;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Unable to retrieve statistics for link speed",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "wlan_hdd_get_linkspeed_for_peermac");
        v39 = qdf_status_to_os_return(v38);
      }
      else
      {
        v41 = osif_request_wait_for_response(v24);
        if ( v41 )
        {
          v39 = v41;
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: SME timed out while retrieving link speed",
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            "wlan_hdd_get_linkspeed_for_peermac");
        }
        else
        {
          v39 = 0;
          *((_DWORD *)a1 + 675) = *(_DWORD *)(v28 + 8);
        }
      }
      osif_request_put(v24);
      result = v39;
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Request allocation failure",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "wlan_hdd_get_linkspeed_for_peermac");
      result = 4294967284LL;
    }
    *a3 = *((_DWORD *)a1 + 675);
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: NULL argument",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_hdd_get_linkspeed_for_peermac");
    return 4294967274LL;
  }
  return result;
}
