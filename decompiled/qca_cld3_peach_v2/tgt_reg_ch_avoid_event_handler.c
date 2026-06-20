__int64 __fastcall tgt_reg_ch_avoid_event_handler(__int64 a1, __int64 a2, unsigned int a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 psoc_from_scn_hdl; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  __int64 rx_ops; // x0
  __int64 v25; // x8
  __int64 v26; // x8
  __int64 v27; // x22
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  const char *v36; // x2
  const char *v37; // x2
  __int64 result; // x0
  _DWORD *v39; // x8
  _BYTE v40[680]; // [xsp+0h] [xbp-2B0h] BYREF
  __int64 v41; // [xsp+2A8h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v40, 0, sizeof(v40));
  qdf_trace_msg(0x49u, 8u, "%s: enter", v6, v7, v8, v9, v10, v11, v12, v13, "tgt_reg_ch_avoid_event_handler");
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v37 = "%s: psoc ptr is NULL";
LABEL_12:
    qdf_trace_msg(0x49u, 2u, v37, v15, v16, v17, v18, v19, v20, v21, v22, "tgt_reg_ch_avoid_event_handler");
    result = 4294967274LL;
    goto LABEL_13;
  }
  v23 = psoc_from_scn_hdl;
  rx_ops = target_if_regulatory_get_rx_ops(psoc_from_scn_hdl, v15, v16, v17, v18, v19, v20, v21, v22);
  if ( !rx_ops )
  {
    v37 = "%s: reg_rx_ops is NULL";
    goto LABEL_12;
  }
  if ( !*(_QWORD *)(rx_ops + 72) )
  {
    v37 = "%s: reg_ch_avoid_event_handler is NULL";
    goto LABEL_12;
  }
  v25 = *(_QWORD *)(v23 + 2800);
  if ( !v25 || (v26 = *(_QWORD *)(v25 + 16)) == 0 )
  {
    v37 = "%s: Invalid WMI handle";
    goto LABEL_12;
  }
  v27 = rx_ops;
  if ( (unsigned int)wmi_extract_reg_ch_avoid_event(v26, a2, v40, a3) )
  {
    v36 = "%s: Extraction of CH avoid event failed";
  }
  else
  {
    v39 = *(_DWORD **)(v27 + 72);
    if ( *(v39 - 1) != 387901415 )
      __break(0x8228u);
    if ( !((unsigned int (__fastcall *)(__int64, _BYTE *))v39)(v23, v40) )
    {
      qdf_trace_msg(0x49u, 8u, "%s: exit", v28, v29, v30, v31, v32, v33, v34, v35, "tgt_reg_ch_avoid_event_handler");
      result = 0;
      goto LABEL_13;
    }
    v36 = "%s: Failed to process CH avoid event";
  }
  qdf_trace_msg(0x49u, 2u, v36, v28, v29, v30, v31, v32, v33, v34, v35, "tgt_reg_ch_avoid_event_handler");
  result = 4294967282LL;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
