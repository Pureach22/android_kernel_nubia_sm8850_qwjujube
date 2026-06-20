__int64 __fastcall tgt_reg_txpb_event_handler(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 psoc_from_scn_hdl; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x23
  __int64 v22; // x8
  __int64 v23; // x22
  __int64 v24; // x21
  __int64 v25; // x0
  __int64 v26; // x20
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  const char *v35; // x2
  const char *v36; // x2
  unsigned int (__fastcall *v38)(__int64, __int64); // x8
  unsigned int v39; // w19
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7

  qdf_trace_msg(0x49u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "tgt_reg_txpb_event_handler");
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( psoc_from_scn_hdl )
  {
    v21 = *(_QWORD *)(psoc_from_scn_hdl + 2136);
    if ( v21 )
    {
      if ( *(_QWORD *)(v21 + 672) )
      {
        v22 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
        if ( v22 )
        {
          v23 = *(_QWORD *)(v22 + 16);
          if ( v23 )
          {
            v24 = psoc_from_scn_hdl;
            v25 = _qdf_mem_malloc(0x50u, "tgt_reg_txpb_event_handler", 1654);
            if ( !v25 )
              return 4294967284LL;
            v26 = v25;
            if ( (unsigned int)wmi_extract_pdev_power_boost_ev_params(v23, a2, v25) )
            {
              v35 = "%s: TPB: Failed to extract power boost event params";
            }
            else
            {
              v38 = *(unsigned int (__fastcall **)(__int64, __int64))(v21 + 672);
              if ( *((_DWORD *)v38 - 1) != 1902538048 )
                __break(0x8228u);
              if ( !v38(v24, v26) )
              {
                v39 = 0;
                goto LABEL_21;
              }
              v35 = "%s: TPB: Failed to process txpb event handler";
            }
            qdf_trace_msg(0x49u, 2u, v35, v27, v28, v29, v30, v31, v32, v33, v34, "tgt_reg_txpb_event_handler");
            v39 = -14;
LABEL_21:
            _qdf_mem_free(v26);
            qdf_trace_msg(0x49u, 8u, "%s: exit", v40, v41, v42, v43, v44, v45, v46, v47, "tgt_reg_txpb_event_handler");
            return v39;
          }
        }
        v36 = "%s: invalid wmi handle";
      }
      else
      {
        v36 = "%s: txpb_event_handler is NULL";
      }
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: rx_ops is NULL",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "target_if_regulatory_get_rx_ops");
      v36 = "%s: reg_rx_ops is NULL";
    }
  }
  else
  {
    v36 = "%s: psoc ptr is NULL";
  }
  qdf_trace_msg(0x49u, 2u, v36, v13, v14, v15, v16, v17, v18, v19, v20, "tgt_reg_txpb_event_handler");
  return 4294967274LL;
}
