__int64 __fastcall dp_wdi_event_handler(
        unsigned int a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        unsigned __int8 a6)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w8
  __int64 i; // x23
  __int64 v21; // x0
  __int64 (__fastcall *v22)(__int64, _QWORD, __int64, _QWORD, _QWORD); // x8

  result = dp_get_pdev_for_mac_id(a2, a6);
  if ( !a1 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "Invalid WDI event in %s",
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             "dp_wdi_event_handler");
  if ( !result || *(_BYTE *)(result + 3) == 1 )
    return qdf_trace_msg(0x45u, 2u, "Invalid pdev in WDI event handler", v11, v12, v13, v14, v15, v16, v17, v18);
  v19 = a1 - 256;
  if ( a1 - 256 >= 0x33 )
  {
    __break(0x5512u);
    return dp_wdi_event_sub();
  }
  else
  {
    ++*(_DWORD *)(result + 4LL * v19 + 8616);
    for ( i = *(_QWORD *)(*(_QWORD *)(result + 95928) + 8LL * v19); i; i = *(_QWORD *)(i + 16) )
    {
      v22 = *(__int64 (__fastcall **)(__int64, _QWORD, __int64, _QWORD, _QWORD))i;
      v21 = *(_QWORD *)(i + 8);
      if ( *(_DWORD *)(*(_QWORD *)i - 4LL) != 1330779045 )
        __break(0x8228u);
      result = v22(v21, a1, a3, a4, a5);
    }
  }
  return result;
}
