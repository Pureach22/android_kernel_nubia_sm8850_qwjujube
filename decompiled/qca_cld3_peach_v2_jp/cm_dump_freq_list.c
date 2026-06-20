__int64 __fastcall cm_dump_freq_list(unsigned __int8 *a1)
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
  unsigned __int64 v12; // x21
  unsigned __int8 v13; // w8
  __int64 v14; // x24
  char v15; // w0

  result = _qdf_mem_malloc(0x190u, "cm_dump_freq_list", 1210);
  if ( result )
  {
    v11 = result;
    if ( *((_QWORD *)a1 + 1) && *a1 )
    {
      v12 = 0;
      v13 = 0;
      do
      {
        v14 = v13;
        v3 = scnprintf(v11 + v14, (unsigned int)(400 - v14), "%d ", *(_DWORD *)(*((_QWORD *)a1 + 1) + 4 * v12++));
        v13 = v15 + v14;
      }
      while ( v12 < *a1 );
    }
    else
    {
      LODWORD(v12) = 0;
    }
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: frequency list [%u]: %s",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "cm_dump_freq_list",
      (unsigned int)v12,
      v11);
    return _qdf_mem_free(v11);
  }
  return result;
}
