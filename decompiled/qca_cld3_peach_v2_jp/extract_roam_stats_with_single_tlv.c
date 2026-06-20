__int64 __fastcall extract_roam_stats_with_single_tlv(__int64 a1, __int64 a2, unsigned __int8 *a3)
{
  unsigned int v3; // w19
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 result; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7

  v3 = *a3;
  if ( (unsigned int)wmi_unified_extract_roam_scan_stats(a1) )
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Roam scan stats extract failed vdev %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "extract_roam_stats_with_single_tlv",
      v3);
  if ( (unsigned int)wmi_unified_extract_roam_11kv_stats(a1) )
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Roam 11kv stats extract failed vdev %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "extract_roam_stats_with_single_tlv",
      v3);
  if ( (unsigned int)wmi_unified_extract_roam_trigger_stats(a1) )
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Extract roamtrigger stats failed vdev %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "extract_roam_stats_with_single_tlv",
      v3);
  result = wmi_unified_extract_roam_btm_response(a1);
  if ( (_DWORD)result )
    return qdf_trace_msg(
             0x31u,
             8u,
             "%s: Roam btm rsp stats extract fail vdev %d",
             v30,
             v31,
             v32,
             v33,
             v34,
             v35,
             v36,
             v37,
             "extract_roam_stats_with_single_tlv",
             v3);
  return result;
}
