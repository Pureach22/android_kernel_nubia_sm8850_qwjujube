__int64 __fastcall nl80211_vendor_check_policy(__int64 a1, const char *a2, const char **a3)
{
  __int64 v3; // x3
  int v4; // w8
  const char *v7; // x21

  v3 = *(_QWORD *)(a1 + 32);
  v4 = *((__int16 *)a2 + 1);
  if ( v3 == -61 )
  {
    if ( (v4 & 0x80000000) == 0 )
      return 0;
    v7 = "unexpected nested data";
  }
  else
  {
    if ( v4 < 0 )
      return _nla_validate(a2 + 4, (unsigned __int16)(*(_WORD *)a2 - 4), *(unsigned int *)(a1 + 40), v3, 31, a3);
    v7 = "expected nested data";
  }
  do_trace_netlink_extack(v7);
  if ( a3 )
  {
    *a3 = v7;
    a3[1] = a2;
    a3[2] = nullptr;
  }
  return 4294967274LL;
}
