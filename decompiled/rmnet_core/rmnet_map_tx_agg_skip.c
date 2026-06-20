__int64 __fastcall rmnet_map_tx_agg_skip(__int64 a1, int a2)
{
  int v2; // w9
  unsigned __int8 *v3; // x8
  int v5; // w9

  v2 = *(unsigned __int16 *)(a1 + 180);
  v3 = (unsigned __int8 *)(*(_QWORD *)(a1 + 224) + a2);
  if ( v2 != 56710 )
  {
    if ( v2 == 8 )
      return v3[9] == 1;
    return 0;
  }
  v5 = v3[6];
  if ( v5 != 58 )
  {
    if ( v5 == 44 )
      return v3[40] == 58;
    return 0;
  }
  return 1;
}
