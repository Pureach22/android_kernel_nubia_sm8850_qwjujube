__int64 __fastcall icc_clk_unregister(__int64 a1)
{
  __int64 result; // x0
  int v3; // w8
  unsigned __int8 *v4; // x9
  __int64 v5; // x21
  unsigned __int8 *v6; // x22
  int v7; // t1
  __int64 v8; // x20

  icc_provider_deregister(a1);
  result = icc_nodes_remove(a1);
  v3 = *(_DWORD *)(a1 + 104);
  if ( v3 >= 1 )
  {
    v4 = (unsigned __int8 *)(a1 + 120);
    v5 = 0;
    v6 = (unsigned __int8 *)(a1 + 120);
    do
    {
      v7 = *v6;
      v6 += 16;
      if ( v7 == 1 )
      {
        v8 = *((_QWORD *)v4 - 1);
        clk_disable(v8);
        result = clk_unprepare(v8);
        v3 = *(_DWORD *)(a1 + 104);
      }
      ++v5;
      v4 = v6;
    }
    while ( v5 < v3 );
  }
  return result;
}
