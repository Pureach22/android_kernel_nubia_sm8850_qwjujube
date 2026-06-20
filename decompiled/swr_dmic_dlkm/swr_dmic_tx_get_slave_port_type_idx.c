__int64 __fastcall swr_dmic_tx_get_slave_port_type_idx(const char *a1, int *a2)
{
  size_t v4; // x0
  int v5; // w8
  size_t v6; // x0
  __int64 result; // x0

  v4 = strlen(a1);
  if ( strnstr(a1, "HIFI", v4) )
  {
    v5 = 0;
  }
  else
  {
    v6 = strlen(a1);
    if ( !strnstr(a1, "LP", v6) )
      return 4294967274LL;
    v5 = 1;
  }
  result = 0;
  *a2 = v5;
  return result;
}
