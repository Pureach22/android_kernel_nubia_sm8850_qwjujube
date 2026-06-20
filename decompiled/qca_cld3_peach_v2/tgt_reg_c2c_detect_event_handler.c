__int64 __fastcall tgt_reg_c2c_detect_event_handler(
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
  __int64 v21; // x21
  __int64 v22; // x8
  __int64 v23; // x8
  __int64 v24; // x20
  unsigned int v25; // w19
  const char *v26; // x2
  unsigned int (__fastcall *v28)(__int64, __int64); // x8
  __int64 v29; // x1
  _BYTE v30[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v31; // [xsp+8h] [xbp-8h]

  v31 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30[0] = 0;
  qdf_trace_msg(0x49u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "tgt_reg_c2c_detect_event_handler");
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( psoc_from_scn_hdl )
  {
    v21 = *(_QWORD *)(psoc_from_scn_hdl + 2136);
    if ( v21 )
    {
      if ( *(_QWORD *)(v21 + 440) )
      {
        v22 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
        if ( v22 && (v23 = *(_QWORD *)(v22 + 16)) != 0 )
        {
          v24 = psoc_from_scn_hdl;
          if ( (unsigned int)wmi_extract_reg_c2c_detect_event(v23, a2, v30) )
          {
            v25 = -14;
            v26 = "%s: Extraction of c2c detect event failed";
          }
          else
          {
            v28 = *(unsigned int (__fastcall **)(__int64, __int64))(v21 + 440);
            v29 = v30[0];
            if ( *((_DWORD *)v28 - 1) != -132374536 )
              __break(0x8228u);
            if ( !v28(v24, v29) )
            {
              v25 = 0;
              goto LABEL_13;
            }
            v25 = -14;
            v26 = "%s: Failed to process c2c_detect_event_handler";
          }
        }
        else
        {
          v25 = -22;
          v26 = "%s: invalid wmi handle";
        }
      }
      else
      {
        v25 = -22;
        v26 = "%s: c2c_detect_event_handler is NULL";
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
      v25 = -22;
      v26 = "%s: reg_rx_ops is NULL";
    }
  }
  else
  {
    v25 = -22;
    v26 = "%s: psoc ptr is NULL";
  }
  qdf_trace_msg(0x49u, 2u, v26, v13, v14, v15, v16, v17, v18, v19, v20, "tgt_reg_c2c_detect_event_handler");
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v25;
}
