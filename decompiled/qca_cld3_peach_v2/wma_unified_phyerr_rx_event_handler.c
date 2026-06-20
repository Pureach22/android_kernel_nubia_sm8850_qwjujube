__int64 __fastcall wma_unified_phyerr_rx_event_handler(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int comb_phyerr; // w0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w22
  __int64 result; // x0
  __int16 v20; // [xsp+4h] [xbp-9Ch]
  __int64 v21; // [xsp+50h] [xbp-50h]
  __int64 v22; // [xsp+58h] [xbp-48h]
  __int64 v23; // [xsp+60h] [xbp-40h]
  __int64 v24; // [xsp+68h] [xbp-38h]
  __int64 v25; // [xsp+70h] [xbp-30h]
  __int64 v26; // [xsp+78h] [xbp-28h]
  __int64 v27; // [xsp+80h] [xbp-20h]
  __int64 v28; // [xsp+88h] [xbp-18h]
  __int64 v29; // [xsp+90h] [xbp-10h]
  __int64 v30; // [xsp+98h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v21 = 0;
  v20 = 0;
  if ( !a1 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Invalid WMA handle (via %s)",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "__wma_validate_handle",
      "wma_unified_phyerr_rx_event_handler");
LABEL_5:
    result = 4294967274LL;
    goto LABEL_6;
  }
  comb_phyerr = wmi_extract_comb_phyerr(*a1);
  if ( !comb_phyerr )
  {
    v20 = 0;
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Unknown phy error event",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "wma_unified_phyerr_rx_event_handler");
    goto LABEL_5;
  }
  v18 = comb_phyerr;
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: extract phyerr failed: %d",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    "wma_unified_phyerr_rx_event_handler",
    comb_phyerr);
  result = qdf_status_to_os_return(v18);
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
