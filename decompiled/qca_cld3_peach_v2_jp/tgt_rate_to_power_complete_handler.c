__int64 __fastcall tgt_rate_to_power_complete_handler(
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
  __int64 psoc_from_scn_hdl; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x24
  __int64 v24; // x8
  __int64 v25; // x23
  __int64 v26; // x22
  unsigned int *v27; // x19
  unsigned int v28; // w20
  const char *v29; // x2
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v39; // x1
  unsigned int (__fastcall *v40)(__int64, __int64); // x8

  qdf_trace_msg(0x49u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "tgt_rate_to_power_complete_handler");
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( psoc_from_scn_hdl )
  {
    v23 = *(_QWORD *)(psoc_from_scn_hdl + 2136);
    if ( v23 )
    {
      if ( *(_QWORD *)(v23 + 656) )
      {
        v24 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
        if ( v24 && (v25 = *(_QWORD *)(v24 + 16)) != 0 )
        {
          v26 = psoc_from_scn_hdl;
          v27 = (unsigned int *)_qdf_mem_malloc(8u, "tgt_rate_to_power_complete_handler", 1497);
          if ( !v27 )
          {
            v28 = -12;
            goto LABEL_14;
          }
          if ( (unsigned int)wmi_extract_tgtr2p_table_event(v25, a2, v27, a3) )
          {
            v28 = -14;
            v29 = "%s: Extraction of r2p update response event failed";
          }
          else
          {
            v39 = *v27;
            v40 = *(unsigned int (__fastcall **)(__int64, __int64))(v23 + 656);
            if ( *((_DWORD *)v40 - 1) != 787953853 )
              __break(0x8228u);
            if ( !v40(v26, v39) )
            {
              v28 = 0;
              goto LABEL_14;
            }
            v28 = -14;
            v29 = "%s: Failed to process r2p update response";
          }
        }
        else
        {
          v27 = nullptr;
          v28 = -22;
          v29 = "%s: invalid wmi handle";
        }
      }
      else
      {
        v27 = nullptr;
        v28 = -22;
        v29 = "%s: reg_r2p_table_update_response_handler is NULL";
      }
    }
    else
    {
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: rx_ops is NULL",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "target_if_regulatory_get_rx_ops");
      v27 = nullptr;
      v28 = -22;
      v29 = "%s: reg_rx_ops is NULL";
    }
  }
  else
  {
    v27 = nullptr;
    v28 = -22;
    v29 = "%s: psoc ptr is NULL";
  }
  qdf_trace_msg(0x49u, 2u, v29, v15, v16, v17, v18, v19, v20, v21, v22, "tgt_rate_to_power_complete_handler");
LABEL_14:
  _qdf_mem_free((__int64)v27);
  qdf_trace_msg(0x49u, 8u, "%s: exit", v30, v31, v32, v33, v34, v35, v36, v37, "tgt_rate_to_power_complete_handler");
  return v28;
}
