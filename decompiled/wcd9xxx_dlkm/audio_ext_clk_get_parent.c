__int64 __fastcall audio_ext_clk_get_parent(__int64 a1)
{
  int num_parents; // w0
  unsigned int v3; // w21
  const char *v5; // x20
  __int64 v6; // x8
  unsigned int v7; // w19
  __int64 v8; // x22
  unsigned int v9; // w23

  num_parents = clk_hw_get_num_parents();
  if ( *(_DWORD *)(a1 - 56) )
    return 0;
  v5 = *(const char **)(a1 + 48);
  if ( !v5 )
  {
    return 0;
  }
  else
  {
    v6 = *(_QWORD *)(a1 + 16);
    v7 = num_parents;
    v3 = *(unsigned __int8 *)(v6 + 40) + 1;
    if ( num_parents >= 1 )
    {
      v8 = *(_QWORD *)(v6 + 16);
      v9 = 0;
      do
      {
        if ( !strcmp(*(const char **)(v8 + 8LL * (unsigned __int8)v9), v5) )
          v3 = v9;
        ++v9;
      }
      while ( v7 > (unsigned __int8)v9 );
    }
  }
  return v3;
}
