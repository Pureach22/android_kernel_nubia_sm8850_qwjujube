__int64 __fastcall dp_mst_fixed_connector_detect(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 v5; // x9

  v4 = *(_QWORD *)(a4 + 40);
  if ( *(_QWORD *)(v4 + 2720) == a1 )
  {
    v5 = 1336;
  }
  else
  {
    if ( *(_QWORD *)(v4 + 4112) != a1 )
      return 2;
    v5 = 2728;
  }
  if ( *(_BYTE *)(v4 + v5 + 1380) == 1 )
    return dp_mst_connector_detect(a1, a2);
  return 2;
}
