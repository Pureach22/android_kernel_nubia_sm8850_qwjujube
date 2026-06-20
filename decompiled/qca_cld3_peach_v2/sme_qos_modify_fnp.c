__int64 __fastcall sme_qos_modify_fnp(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  int v19; // w8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7

  if ( a10 )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: reason %d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "sme_qos_modify_fnp",
      *(unsigned int *)(a10 + 20));
    v19 = *(_DWORD *)(a10 + 20);
    if ( v19 == 2 )
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Deleting original entry at %pK with flowID %d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "sme_qos_modify_fnp",
        a10,
        *(unsigned int *)(a10 + 24));
      csr_ll_remove_entry((__int64)&unk_91F2E0, (__int64 *)a10, 1, v21, v22, v23, v24, v25, v26, v27, v28);
      _qdf_mem_free(a10);
    }
    else if ( v19 == 3 )
    {
      *(_DWORD *)(a10 + 20) = 4;
      return 0;
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: Entry is NULL", a1, a2, a3, a4, a5, a6, a7, a8, "sme_qos_modify_fnp");
    return 16;
  }
}
