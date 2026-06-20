__int64 __fastcall tgt_reg_11d_new_cc_handler(
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
  unsigned int (__fastcall *v39)(__int64, __int16 *); // x8
  __int16 v40; // [xsp+4h] [xbp-Ch] BYREF
  char v41; // [xsp+6h] [xbp-Ah]
  __int64 v42; // [xsp+8h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41 = 0;
  v40 = 0;
  qdf_trace_msg(0x49u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "tgt_reg_11d_new_cc_handler");
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v37 = "%s: psoc ptr is NULL";
    goto LABEL_11;
  }
  v23 = psoc_from_scn_hdl;
  rx_ops = target_if_regulatory_get_rx_ops();
  if ( !rx_ops || !*(_QWORD *)(rx_ops + 24) )
  {
    v37 = "%s: reg_11d_new_cc_handler is NULL";
LABEL_11:
    qdf_trace_msg(0x49u, 2u, v37, v15, v16, v17, v18, v19, v20, v21, v22, "tgt_reg_11d_new_cc_handler");
    result = 4294967274LL;
    goto LABEL_12;
  }
  v25 = *(_QWORD *)(v23 + 2800);
  if ( !v25 || (v26 = *(_QWORD *)(v25 + 16)) == 0 )
  {
    v37 = "%s: Invalid WMI handle";
    goto LABEL_11;
  }
  v27 = rx_ops;
  if ( (unsigned int)wmi_extract_reg_11d_new_cc_event(v26, a2, &v40, a3) )
  {
    v36 = "%s: Extraction of new country event failed";
  }
  else
  {
    v39 = *(unsigned int (__fastcall **)(__int64, __int16 *))(v27 + 24);
    if ( *((_DWORD *)v39 - 1) != -529016636 )
      __break(0x8228u);
    if ( !v39(v23, &v40) )
    {
      qdf_trace_msg(
        0x49u,
        8u,
        "%s: processed 11d new country code event",
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        "tgt_reg_11d_new_cc_handler");
      result = 0;
      goto LABEL_12;
    }
    v36 = "%s: Failed to process new country code event";
  }
  qdf_trace_msg(0x49u, 2u, v36, v28, v29, v30, v31, v32, v33, v34, v35, "tgt_reg_11d_new_cc_handler");
  result = 4294967282LL;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
