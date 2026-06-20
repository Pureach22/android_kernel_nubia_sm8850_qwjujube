__int64 __fastcall nl80211_validate_key_link_id(__int64 a1, __int64 a2, int a3, char a4)
{
  const char **v4; // x20
  const char *v5; // x19

  if ( (a4 & 1) == 0 )
  {
    if ( *(_WORD *)(a2 + 1472) )
    {
      if ( a3 == -1 )
      {
        v4 = *(const char ***)(a1 + 64);
        v5 = "link ID must for MLO group key";
        goto LABEL_12;
      }
      if ( (((unsigned __int64)*(unsigned __int16 *)(a2 + 1472) >> a3) & 1) == 0 )
      {
        v4 = *(const char ***)(a1 + 64);
        v5 = "invalid link ID for MLO group key";
        goto LABEL_12;
      }
    }
    else if ( a3 != -1 )
    {
      v4 = *(const char ***)(a1 + 64);
      v5 = "link ID not allowed for non-MLO group key";
      goto LABEL_12;
    }
    return 0;
  }
  if ( a3 == -1 )
    return 0;
  v4 = *(const char ***)(a1 + 64);
  v5 = "link ID not allowed for pairwise key";
LABEL_12:
  do_trace_netlink_extack(v5);
  if ( v4 )
    *v4 = v5;
  return 4294967274LL;
}
