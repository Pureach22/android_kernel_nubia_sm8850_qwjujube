__int64 __fastcall ll_lt_store_to_avoid_list_and_flush_old(__int64 a1, int a2, unsigned int a3)
{
  unsigned __int64 comp_private_obj; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w21
  unsigned __int64 v15; // x19
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w8
  unsigned __int64 v26; // x23
  __int64 v27; // x8
  __int64 v28; // x10
  bool v29; // nf
  __int64 v30; // x8
  unsigned __int64 v31; // x23
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  int v40; // w3
  __int64 v41; // x20
  unsigned __int8 v42; // w0
  unsigned __int8 v43; // w21
  int v44; // w3
  char v45; // w0
  int v46; // w3

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x34u);
  if ( !comp_private_obj )
    return qdf_trace_msg(
             0xA1u,
             2u,
             "%s: psoc_ll_sap_obj is null",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "ll_lt_store_to_avoid_list_and_flush_old");
  v14 = *(unsigned __int8 *)(comp_private_obj + 264);
  v15 = comp_private_obj;
  result = ll_lt_sap_flush_old_entries(comp_private_obj);
  if ( a2 && a3 == 1 )
  {
    v25 = *(unsigned __int8 *)(v15 + 264);
    v26 = v15 + 216;
    if ( v25 <= 2 )
    {
      if ( !*(_DWORD *)v26 && !*(_QWORD *)(v15 + 224)
        || (v26 = v15 + 232, !*(_DWORD *)(v15 + 232)) && !*(_QWORD *)(v15 + 240)
        || (v26 = v15 + 248, !*(_DWORD *)(v15 + 248)) && !*(_QWORD *)(v15 + 256) )
      {
        *(_DWORD *)v26 = a2;
        result = qdf_get_time_of_the_day_ms();
        *(_QWORD *)(v26 + 8) = result;
        LOBYTE(v25) = *(_BYTE *)(v15 + 264) + 1;
        *(_BYTE *)(v15 + 264) = v25;
      }
    }
    else
    {
      v27 = *(_QWORD *)(v15 + 224);
      v28 = *(_QWORD *)(v15 + 240) - v27;
      if ( v28 < 0 )
        v27 = *(_QWORD *)(v15 + 240);
      v29 = *(_QWORD *)(v15 + 256) - v27 < 0;
      v30 = 2;
      if ( !v29 )
        v30 = (unsigned __int64)v28 >> 63;
      v31 = v26 + 16 * v30;
      *(_DWORD *)v31 = a2;
      result = qdf_get_time_of_the_day_ms();
      LOBYTE(v25) = *(_BYTE *)(v15 + 264);
      *(_QWORD *)(v31 + 8) = result;
    }
  }
  else
  {
    LOBYTE(v25) = *(_BYTE *)(v15 + 264);
    if ( a3 != 1 && v14 )
      goto LABEL_22;
  }
  if ( v14 == (unsigned __int8)v25 )
    return result;
LABEL_22:
  qdf_trace_msg(
    0xA1u,
    8u,
    "%s: src %d old count %d new count %d",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "ll_lt_store_to_avoid_list_and_flush_old",
    a3,
    v14,
    (unsigned __int8)v25);
  result = _qdf_mem_malloc(0x64u, "ll_lt_sap_dump_stored_freq_list", 320);
  if ( !result )
    return result;
  v40 = *(_DWORD *)(v15 + 216);
  v41 = result;
  if ( !v40 )
  {
    v43 = 0;
    v44 = *(_DWORD *)(v15 + 232);
    if ( !v44 )
      goto LABEL_26;
    goto LABEL_25;
  }
  v32 = scnprintf(result, 100, "%d[%lu] ", v40, *(_QWORD *)(v15 + 224));
  v43 = v42;
  v44 = *(_DWORD *)(v15 + 232);
  if ( v44 )
  {
LABEL_25:
    v32 = scnprintf(v41 + v43, 100LL - v43, "%d[%lu] ", v44, *(_QWORD *)(v15 + 240));
    v43 += v45;
  }
LABEL_26:
  v46 = *(_DWORD *)(v15 + 248);
  if ( v46 )
    v32 = scnprintf(v41 + v43, 100LL - v43, "%d[%lu] ", v46, *(_QWORD *)(v15 + 256));
  qdf_trace_msg(0xA1u, 8u, "freq[timestamp]: %s", v32, v33, v34, v35, v36, v37, v38, v39, v41);
  return _qdf_mem_free(v41);
}
