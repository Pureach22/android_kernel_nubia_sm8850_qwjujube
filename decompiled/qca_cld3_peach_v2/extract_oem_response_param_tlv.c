__int64 __fastcall extract_oem_response_param_tlv(
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
        __int64 a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  int v13; // w8
  int v14; // w8
  __int64 v15; // x8

  if ( a10 )
  {
    v13 = *(_DWORD *)(a10 + 8);
    if ( v13 )
    {
      *(_DWORD *)a11 = v13;
      *(_QWORD *)(a11 + 8) = *(_QWORD *)a10;
    }
    v14 = *(_DWORD *)(a10 + 40);
    if ( v14 )
    {
      *(_DWORD *)(a11 + 4) = v14;
      *(_QWORD *)(a11 + 16) = *(_QWORD *)(a10 + 32);
    }
    v15 = *(_QWORD *)(a10 + 16);
    if ( v15 )
    {
      *(_DWORD *)(a11 + 24) = *(_DWORD *)(v15 + 4);
      *(_QWORD *)(a11 + 32) = *(unsigned int *)(*(_QWORD *)(a10 + 16) + 8LL)
                            | ((unsigned __int64)(*(_DWORD *)(*(_QWORD *)(a10 + 16) + 12LL) & 0xF) << 32);
      *(_DWORD *)(a11 + 28) = *(_DWORD *)(*(_QWORD *)(a10 + 16) + 16LL);
    }
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid OEM response",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_oem_response_param_tlv",
      v11,
      v12);
    return 4;
  }
}
