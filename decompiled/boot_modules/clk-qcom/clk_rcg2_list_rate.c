__int64 __fastcall clk_rcg2_list_rate(__int64 a1, unsigned int a2)
{
  _QWORD *v2; // x8
  __int64 *v3; // x10
  unsigned __int64 v4; // x9
  __int64 v5; // t1
  unsigned int v6; // w10

  v2 = *(_QWORD **)(a1 - 8);
  if ( !v2 )
    return -6;
  if ( *v2 )
  {
    v3 = v2 + 3;
    v4 = -1;
    do
    {
      v5 = *v3;
      v3 += 3;
      ++v4;
    }
    while ( v5 );
    v6 = a2;
    if ( v4 < a2 )
      return -22;
  }
  else
  {
    v6 = a2;
  }
  return v2[3 * v6];
}
