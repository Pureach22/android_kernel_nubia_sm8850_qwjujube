__int64 __fastcall dp_mst_find_fixed_port_num(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v3; // x22
  unsigned int v5; // w20
  __int64 v6; // x0

  v2 = *(_QWORD *)(a1 + 48);
  v3 = a1 + 40;
  if ( v2 != a1 + 40 )
  {
    v5 = 0;
    while ( 1 )
    {
      v6 = *(_QWORD *)(v2 + 16);
      if ( v6 )
      {
        v5 += dp_mst_find_fixed_port_num(v6, a2);
      }
      else if ( (*(_BYTE *)(v2 - 15) & 1) == 0 )
      {
        ++v5;
        if ( v2 - 24 == a2 )
          return v5;
      }
      v2 = *(_QWORD *)(v2 + 8);
      if ( v2 == v3 )
        return v5;
    }
  }
  return 0;
}
