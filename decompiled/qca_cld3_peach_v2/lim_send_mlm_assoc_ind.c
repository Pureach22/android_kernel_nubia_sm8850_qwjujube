__int64 __fastcall lim_send_mlm_assoc_ind(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 v14; // x24
  _BOOL4 v15; // w21
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x23
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x8
  int v37; // w9
  char is_mlo_conn; // w0
  __int64 v40; // x1

  v11 = *(_QWORD *)(a3 + 384);
  if ( v11 )
  {
    v12 = *(unsigned __int16 *)(a2 + 348);
    v14 = *(_QWORD *)(v11 + 8 * v12);
    if ( v14 )
    {
      v15 = *(unsigned __int8 *)(v14 + 3257) == 1;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Sessionid: %d ssid: %.*s sub_type: %d Associd: %d staAddr: %02x:%02x:%02x:**:**:%02x",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "lim_send_mlm_assoc_ind",
        *(unsigned __int16 *)(a3 + 8),
        *(unsigned __int8 *)(v14 + 10),
        v14 + 11,
        *(unsigned __int8 *)(v14 + 3257) == 1,
        v12,
        *(unsigned __int8 *)(a2 + 350),
        *(unsigned __int8 *)(a2 + 351),
        *(unsigned __int8 *)(a2 + 352),
        *(unsigned __int8 *)(a2 + 355));
      v18 = _qdf_mem_malloc(0xB58u, "lim_send_mlm_assoc_ind", 3931);
      if ( v18 )
      {
        v27 = v18;
        if ( (lim_fill_lim_assoc_ind_params(v18, a1, a2, a3, v19, v20, v21, v22, v23, v24, v25, v26) & 1) != 0 )
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: assoc_ind->akm_type:%d ",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "lim_send_mlm_assoc_ind",
            *(unsigned int *)(v27 + 12));
          if ( *(_DWORD *)(v27 + 12) == 4 )
          {
            v36 = *(_QWORD *)(v14 + 3272);
            if ( (*(_BYTE *)(v36 + 68) & 4) != 0 )
              v37 = *(unsigned __int16 *)(v36 + 66);
            else
              v37 = 0;
            lim_send_sme_mgmt_frame_ind(
              a1,
              v15,
              *(_QWORD *)(v36 + 224),
              (unsigned int)(*(_DWORD *)(v36 + 112) + v37),
              *(unsigned __int8 *)(a3 + 10),
              0,
              0,
              0);
          }
          lim_process_mlm_rsp_messages(a1, 1011, v27);
          _qdf_mem_free(v27);
          return 0;
        }
        else
        {
          _qdf_mem_free(v27);
          return 4;
        }
      }
      else
      {
        is_mlo_conn = lim_is_mlo_conn(a3, a2);
        v40 = *(unsigned __int16 *)(a2 + 348);
        if ( (is_mlo_conn & 1) != 0 )
          lim_release_mlo_conn_idx(a1, v40, a3, 0);
        else
          lim_release_peer_idx(a1, v40, a3);
        return 4;
      }
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: assoc req for assoc_id:%d is NULL",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "lim_send_mlm_assoc_ind",
        *(unsigned __int16 *)(a2 + 348));
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s:  Parsed Assoc req is NULL",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "lim_send_mlm_assoc_ind");
    return 4;
  }
}
