__int64 __fastcall extract_host_mem_req_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        int a12,
        int a13,
        int a14,
        unsigned __int16 a15)
{
  __int64 v15; // x29
  __int64 v16; // x30
  __int64 v17; // x8
  int v18; // w10
  int v19; // w7
  unsigned int v20; // w8
  int v21; // w9

  v17 = 20LL * a15;
  *(_DWORD *)a11 = *(_DWORD *)(*(_QWORD *)(a10 + 48) + v17 + 4);
  v18 = *(_DWORD *)(*(_QWORD *)(a10 + 48) + v17 + 8);
  *(_DWORD *)(a11 + 4) = v18;
  v19 = *(_DWORD *)(*(_QWORD *)(a10 + 48) + v17 + 12);
  *(_DWORD *)(a11 + 8) = v19;
  v20 = *(_DWORD *)(*(_QWORD *)(a10 + 48) + v17 + 16);
  *(_QWORD *)(a11 + 12) = v20;
  if ( a14 == 1 )
  {
    if ( (v19 & 8) == 0 )
    {
      v21 = v20;
      *(_DWORD *)(a11 + 16) = v20;
      if ( !v19 )
      {
LABEL_13:
        qdf_trace_msg(
          0x31u,
          8u,
          "%s: idx %d req %d  num_units %d num_unit_info %dunit size %d actual units %d",
          a1,
          a2,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          "extract_host_mem_req_tlv",
          a15,
          v18,
          v21,
          v15,
          v16);
        return 0;
      }
LABEL_7:
      v21 = v20;
      if ( (v19 & 2) != 0 )
      {
        v21 = a13 + 1;
        *(_DWORD *)(a11 + 16) = a13 + 1;
      }
      if ( (v19 & 4) != 0 )
      {
        v21 = a13 + 1;
        if ( a12 )
          v21 = a12 + 1;
        *(_DWORD *)(a11 + 16) = v21;
      }
      goto LABEL_13;
    }
  }
  else if ( !a14 && (v19 & 8) != 0 )
  {
    *(_DWORD *)(a11 + 16) = v20;
    goto LABEL_7;
  }
  return 0;
}
