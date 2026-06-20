__int64 __fastcall sme_qos_delete_existing_flows(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x24
  unsigned int v31; // w8
  __int64 v32; // x1
  _DWORD *v33; // x8
  __int64 v34; // x4

  result = csr_ll_peek_head((__int64)&unk_91F2E0, 1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    v21 = result;
    do
    {
      result = csr_ll_next((__int64)&unk_91F2E0, v21, 1, v13, v14, v15, v16, v17, v18, v19, v20);
      v30 = result;
      if ( *(unsigned __int8 *)(v21 + 16) == a2 )
      {
        v31 = *(_DWORD *)(v21 + 20);
        if ( v31 <= 4 && v31 != 3 )
        {
          v32 = *(_QWORD *)(v21 + 112);
          v33 = *(_DWORD **)(v21 + 120);
          v34 = *(unsigned int *)(v21 + 24);
          if ( *(v33 - 1) != -518755401 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, __int64, _QWORD, __int64, __int64))v33)(a1, v32, 0, 102, v34);
        }
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: Deleting entry at %pK with flowID %d",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "sme_qos_delete_existing_flows",
          v21,
          *(unsigned int *)(v21 + 24));
        csr_ll_remove_entry((__int64)&unk_91F2E0, (__int64 *)v21, 1, v22, v23, v24, v25, v26, v27, v28, v29);
        result = _qdf_mem_free(v21);
      }
      v21 = v30;
    }
    while ( v30 );
  }
  return result;
}
