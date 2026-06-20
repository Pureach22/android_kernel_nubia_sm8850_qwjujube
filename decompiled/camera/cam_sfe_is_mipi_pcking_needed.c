bool __fastcall cam_sfe_is_mipi_pcking_needed(__int64 a1, int a2)
{
  unsigned int v2; // w8
  int v3; // w9
  bool v4; // w11
  int *v5; // x13
  int v6; // w13

  v2 = *(_DWORD *)(a1 + 27548);
  if ( !v2 )
    return 0;
  v3 = 0;
  v4 = 1;
  do
  {
    v5 = (int *)(*(_QWORD *)(a1 + 27608) + 56LL * v3);
    if ( v5[10] == a2 )
    {
      v6 = *v5;
      if ( v6 == 5 || v6 == 16 )
        break;
    }
    v4 = ++v3 < v2;
  }
  while ( v2 != v3 );
  return v4;
}
