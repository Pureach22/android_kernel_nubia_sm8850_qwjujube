__int64 __fastcall get_mi2s_tdm_auxpcm_intf_index(const char *a1)
{
  size_t v2; // x0
  size_t v3; // x0
  size_t v4; // x0
  size_t v5; // x0
  size_t v7; // x0
  size_t v8; // x0
  size_t v9; // x0
  __int64 v10; // x20
  size_t v11; // x2
  size_t v12; // x0
  size_t v13; // x0
  size_t v14; // x0

  v2 = strlen(a1);
  if ( strnstr(a1, "TDM", v2)
    || (v3 = strlen(a1), strnstr(a1, "MI2S", v3))
    || (v4 = strlen(a1), strnstr(a1, "AUXPCM", v4)) )
  {
    v5 = strlen(a1);
    if ( strnstr(a1, "LPAIF_RXTX", v5) )
      return 3;
    v7 = strlen(a1);
    if ( strnstr(a1, "LPAIF_WSA", v7) )
      return 5;
    v8 = strlen(a1);
    if ( strnstr(a1, "LPAIF_VA", v8) )
      return 4;
    v9 = strlen(a1);
    v10 = strnstr(a1, "LPAIF_AUD", v9);
    v11 = strlen(a1);
    if ( v10 )
    {
      if ( strnstr(a1, "PRIMARY", v11) )
        return 6;
      v13 = strlen(a1);
      if ( strnstr(a1, "SECONDARY", v13) )
        return 2;
    }
    else if ( strnstr(a1, "LPAIF", v11) )
    {
      v12 = strlen(a1);
      if ( strnstr(a1, "PRIMARY", v12) )
        return 0;
      v14 = strlen(a1);
      if ( strnstr(a1, "SECONDARY", v14) )
        return 1;
    }
  }
  return 4294967274LL;
}
