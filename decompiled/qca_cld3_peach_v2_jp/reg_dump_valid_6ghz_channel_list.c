__int64 __fastcall reg_dump_valid_6ghz_channel_list(__int64 a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x19
  int v12; // w25
  unsigned int v13; // w26
  __int64 v14; // x23
  int v15; // w24
  int v16; // w4
  int v17; // w0

  result = _qdf_mem_malloc(0x1B1u, "reg_dump_valid_6ghz_channel_list", 2083);
  if ( !result )
    return result;
  v11 = result;
  v12 = 0;
  v13 = 0;
  v14 = a1 + 16;
  v15 = 42;
  while ( 1 )
  {
    while ( 1 )
    {
      v16 = *(_DWORD *)(v14 - 8);
      if ( !v16 )
        goto LABEL_6;
      v3 = scnprintf(
             v11 + v13,
             433 - v13,
             "%d:%d:%d:%d:%d:%x ",
             *(_DWORD *)(v14 - 16),
             v16,
             *(unsigned __int8 *)(v14 + 11),
             *(_DWORD *)v14,
             *(__int16 *)(v14 + 12),
             *(_DWORD *)(v14 - 4));
      if ( (unsigned int)++v12 <= 0x11 )
        break;
      qdf_trace_msg(0x51u, 8u, "%s", v3, v4, v5, v6, v7, v8, v9, v10, v11);
      if ( ++v15 == 102 )
        return _qdf_mem_free(v11);
      v12 = 0;
      v13 = 0;
      v14 += 36;
    }
    v13 += v17;
LABEL_6:
    if ( ++v15 == 102 )
      break;
    v14 += 36;
  }
  if ( v13 )
    qdf_trace_msg(0x51u, 8u, "%s", v3, v4, v5, v6, v7, v8, v9, v10, v11);
  return _qdf_mem_free(v11);
}
