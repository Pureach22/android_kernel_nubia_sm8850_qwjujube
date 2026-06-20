__int64 __fastcall hdd_add_he_oper_info(__int64 a1, __int64 a2)
{
  __int64 v2; // x2
  __int64 v3; // x3
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w20

  v2 = *(unsigned int *)(a2 + 1424);
  if ( (_DWORD)v2 && (v3 = *(_QWORD *)(a2 + 1416)) != 0 )
  {
    if ( (unsigned int)nla_put(a1, 39, v2, v3) )
    {
      v13 = -22;
    }
    else
    {
      qdf_trace_msg(0x33u, 8u, "STA HE operation:", v5, v6, v7, v8, v9, v10, v11, v12);
      ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(
        51,
        8,
        a2 + 1416,
        *(unsigned int *)(a2 + 1424));
      v13 = 0;
    }
    _qdf_mem_free(*(_QWORD *)(a2 + 1416));
    *(_QWORD *)(a2 + 1416) = 0;
    *(_DWORD *)(a2 + 1424) = 0;
  }
  else
  {
    return 0;
  }
  return v13;
}
