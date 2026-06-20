__int64 __fastcall target_if_pmo_lphb_evt_handler(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _BYTE *v20; // x0
  __int64 v21; // x21
  unsigned int v22; // w19
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7

  qdf_trace_msg(0x49u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_pmo_lphb_evt_handler");
  if ( a1 )
  {
    if ( a2 )
    {
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: lphb indication received with\nvdev_id=%d, session=%d, reason=%d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "target_if_pmo_lphb_evt_handler",
        a2[1],
        a2[2],
        a2[3]);
      v20 = (_BYTE *)_qdf_mem_malloc(3u, "target_if_pmo_lphb_evt_handler", 261);
      if ( v20 )
      {
        v21 = (__int64)v20;
        *v20 = a2[2];
        v20[1] = a2[3];
        v20[2] = a2[3];
        v22 = pmo_tgt_lphb_rsp_evt(a1);
        if ( v22 )
          qdf_trace_msg(
            0x49u,
            2u,
            "%s: Failed to lphb_rsp_event",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "target_if_pmo_lphb_evt_handler");
        _qdf_mem_free(v21);
        return v22;
      }
      else
      {
        return 2;
      }
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: Invalid wmi_hb_ind_event_fixed_param buffer",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "target_if_pmo_lphb_evt_handler");
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: psoc ptr is NULL",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "target_if_pmo_lphb_evt_handler");
    return 29;
  }
}
