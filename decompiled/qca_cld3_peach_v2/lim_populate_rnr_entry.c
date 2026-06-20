__int64 __fastcall lim_populate_rnr_entry(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  __int64 v15; // x25
  unsigned __int64 v16; // x21
  unsigned int v17; // t1
  unsigned __int64 v18; // x22
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 result; // x0
  unsigned __int64 v28; // x22
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w19
  unsigned __int16 *v38; // x21
  unsigned int v39; // w8
  int v40; // w23
  unsigned int v41; // w22
  __int64 v42; // [xsp+0h] [xbp-10h]

  qdf_mem_set((void *)(a2 + 13224), 0x38u, 0);
  if ( !a3 )
  {
    qdf_trace_msg(0x35u, 8u, "%s: remove rnrie", v6, v7, v8, v9, v10, v11, v12, v13, "lim_populate_rnr_entry");
    return 0;
  }
  v14 = *(unsigned __int8 *)(a3 + 1);
  v15 = a3 + v14;
  if ( a3 + v14 <= a3 )
    return 1;
  v17 = *(unsigned __int16 *)(a3 + 2);
  v16 = a3 + 2;
  v18 = (unsigned __int64)v17 >> 8;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: chan %d, opclass %d tbtt_cnt %d, tbtt_len %d, fieldtype %d",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "lim_populate_rnr_entry",
    *(unsigned __int8 *)(v16 + 3),
    *(unsigned __int8 *)(v16 + 2),
    (unsigned __int8)v17 >> 4,
    (unsigned int)v18,
    v17 & 3);
  if ( (unsigned __int8)v17 >> 4 )
  {
LABEL_4:
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Not support MBSSID case or rnr content wrong",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "lim_populate_rnr_entry");
    return 1;
  }
  v28 = v18 + 4;
  LODWORD(result) = dot11f_unpack_ie_reduced_neighbor_report(a1, v16, (unsigned int)v28, a2 + 13224, 0);
  if ( (_DWORD)result )
    goto LABEL_9;
  v38 = (unsigned __int16 *)(v16 + v28);
  if ( (unsigned __int64)v38 >= v15 + 2 )
    return 0;
  v39 = *v38;
  v40 = (unsigned __int8)v39 >> 4;
  v41 = v39 >> 8;
  LODWORD(v42) = v39 & 3;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: chan %d, opclass %d tbtt_cnt %d, tbtt_len %d, fieldtype %d",
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    "lim_populate_rnr_entry",
    *((unsigned __int8 *)v38 + 3),
    *((unsigned __int8 *)v38 + 2),
    (unsigned __int8)v39 >> 4,
    v39 >> 8,
    v42);
  if ( v40 )
    goto LABEL_4;
  result = dot11f_unpack_ie_reduced_neighbor_report(a1, v38, v41 + 4, a2 + 13252, 0);
  if ( (_DWORD)result )
  {
LABEL_9:
    v37 = result;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: unpack failed, ret: %d",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "lim_populate_rnr_entry",
      (unsigned int)result);
    return v37;
  }
  return result;
}
