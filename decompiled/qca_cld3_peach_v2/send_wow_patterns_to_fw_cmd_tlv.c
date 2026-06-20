__int64 __fastcall send_wow_patterns_to_fw_cmd_tlv(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        const void *a4,
        unsigned __int8 a5,
        unsigned __int8 a6,
        const void *a7,
        unsigned __int8 a8,
        char a9)
{
  __int64 v17; // x0
  __int64 v18; // x28
  __int64 v19; // x19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x4
  __int64 v29; // x5
  int v30; // w6
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  int v47; // w1
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 result; // x0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7

  v17 = wmi_buf_alloc_fl(a1, 0x168u, "send_wow_patterns_to_fw_cmd_tlv", 0xCBu);
  if ( !v17 )
    return 2;
  v18 = *(_QWORD *)(v17 + 224);
  v19 = v17;
  *(_DWORD *)v18 = 11730956;
  *(_DWORD *)(v18 + 4) = a2;
  *(_QWORD *)(v18 + 12) = 0x12013C00000000LL;
  *(_DWORD *)(v18 + 8) = a3;
  *(_DWORD *)(v18 + 20) = 11796792;
  qdf_mem_copy((void *)(v18 + 24), a4, a5);
  qdf_mem_copy((void *)(v18 + 172), a7, a8);
  v28 = *(unsigned int *)(v18 + 4);
  v29 = *(unsigned int *)(v18 + 8);
  if ( a5 >= 0x92u )
    v30 = 146;
  else
    v30 = a5;
  *(_DWORD *)(v18 + 320) = a6;
  *(_DWORD *)(v18 + 324) = v30;
  *(_DWORD *)(v18 + 328) = v30;
  *(_DWORD *)(v18 + 332) = a3;
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: vdev: %d, ptrn id: %d, ptrn len: %d, ptrn offset: %d user %d",
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    "send_wow_patterns_to_fw_cmd_tlv",
    v28,
    v29,
    a9 & 1);
  qdf_trace_msg(0x31u, 8u, "%s: Pattern: ", v31, v32, v33, v34, v35, v36, v37, v38, "send_wow_patterns_to_fw_cmd_tlv");
  ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(
    49,
    8,
    v18 + 24,
    *(unsigned int *)(v18 + 324));
  qdf_trace_msg(0x31u, 8u, "%s: Mask: ", v39, v40, v41, v42, v43, v44, v45, v46, "send_wow_patterns_to_fw_cmd_tlv");
  ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(
    49,
    8,
    v18 + 172,
    *(unsigned int *)(v18 + 324));
  v47 = *(_DWORD *)(v18 + 4);
  *(_QWORD *)(v18 + 336) = 0x12000000120000LL;
  *(_QWORD *)(v18 + 344) = 0x10000000120000LL;
  *(_QWORD *)(v18 + 352) = 1048580;
  wmi_mtrace(0x13001u, v47, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v19,
             0x168u,
             0x13001u,
             "send_wow_patterns_to_fw_cmd_tlv",
             0x11Bu,
             v48,
             v49,
             v50,
             v51,
             v52,
             v53,
             v54,
             v55);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send wow ptrn to fw %d",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      "send_wow_patterns_to_fw_cmd_tlv",
      (unsigned int)result);
    wmi_buf_free();
    return 16;
  }
  return result;
}
