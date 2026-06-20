__int64 __fastcall gsi_ntn3_client_stats_get(int a1, int a2, __int64 a3)
{
  __int64 v3; // x0
  __int64 v4; // x1
  unsigned int v6; // w8

  if ( a2 <= 5 )
  {
    switch ( a2 )
    {
      case -1:
        a3 = 0;
        v6 = 80 * a1 + 76;
        v3 = 138;
        v4 = v6 >> 2;
        return gsihal_read_reg_nk(v3, v4, a3);
      case 4:
        return ((unsigned int)gsihal_read_reg_nk(60, *(unsigned int *)(gsi_ctx + 20), a3) >> 18) & 1;
      case 5:
        v3 = 61;
LABEL_14:
        v4 = *(unsigned int *)(gsi_ctx + 20);
        return gsihal_read_reg_nk(v3, v4, a3);
    }
  }
  else
  {
    if ( a2 <= 7 )
    {
      if ( a2 == 6 )
        v3 = 62;
      else
        v3 = 63;
      goto LABEL_14;
    }
    if ( a2 == 8 )
    {
      v3 = 64;
      goto LABEL_14;
    }
    if ( a2 == 9 )
    {
      v3 = 65;
      goto LABEL_14;
    }
  }
  dev_err(*(_QWORD *)(gsi_ctx + 8), "%s:%d invalid scratch id %d\n", "gsi_ntn3_client_stats_get", 5498, a2);
  return 0;
}
