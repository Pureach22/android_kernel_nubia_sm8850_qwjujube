__int64 __fastcall wma_process_ch_avoid_update_req(__int64 *a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  if ( (unsigned int)_wma_validate_handle(a1, "wma_process_ch_avoid_update_req") )
    return 16;
  v12 = *a1;
  if ( (unsigned int)_wmi_validate_handle(
                       v12,
                       (__int64)"wma_process_ch_avoid_update_req",
                       v4,
                       v5,
                       v6,
                       v7,
                       v8,
                       v9,
                       v10,
                       v11) )
    return 16;
  if ( !a2 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: ch_avoid_update_req is NULL",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_process_ch_avoid_update_req");
    return 16;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: WMA --> WMI_CHAN_AVOID_UPDATE",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "wma_process_ch_avoid_update_req");
  result = wmi_unified_process_ch_avoid_update_cmd(v12);
  if ( !(_DWORD)result )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: WMA --> WMI_CHAN_AVOID_UPDATE sent through WMI",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wma_process_ch_avoid_update_req");
    return 0;
  }
  return result;
}
