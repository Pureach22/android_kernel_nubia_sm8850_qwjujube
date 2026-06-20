__int64 __fastcall devm_icc_release(__int64 a1)
{
  __int64 result; // x0
  int v3; // w8
  __int64 v4; // x21
  _BYTE *v5; // x22
  __int64 v6; // x20

  icc_provider_deregister(a1);
  result = icc_nodes_remove(a1);
  v3 = *(_DWORD *)(a1 + 104);
  if ( v3 >= 1 )
  {
    v4 = 0;
    v5 = (_BYTE *)(a1 + 120);
    do
    {
      if ( *v5 == 1 )
      {
        v6 = *((_QWORD *)v5 - 1);
        clk_disable(v6);
        result = clk_unprepare(v6);
        v3 = *(_DWORD *)(a1 + 104);
      }
      ++v4;
      v5 += 16;
    }
    while ( v4 < v3 );
  }
  return result;
}
