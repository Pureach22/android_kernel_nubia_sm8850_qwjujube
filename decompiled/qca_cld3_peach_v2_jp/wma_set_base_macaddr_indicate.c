__int64 __fastcall wma_set_base_macaddr_indicate(_QWORD *a1, unsigned __int8 *a2)
{
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x4
  __int64 v13; // x5
  __int64 v14; // x6
  __int64 v15; // x7

  result = wmi_unified_set_base_macaddr_indicate_cmd(*a1);
  if ( !(_DWORD)result )
  {
    if ( a2 )
    {
      v12 = *a2;
      v13 = a2[1];
      v14 = a2[2];
      v15 = a2[5];
    }
    else
    {
      v14 = 0;
      v12 = 0;
      v13 = 0;
      v15 = 0;
    }
    return qdf_trace_msg(
             0x36u,
             8u,
             "%s: Base MAC Addr: %02x:%02x:%02x:**:**:%02x",
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             "wma_set_base_macaddr_indicate",
             v12,
             v13,
             v14,
             v15);
  }
  return result;
}
