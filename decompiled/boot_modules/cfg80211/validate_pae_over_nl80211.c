__int64 __fastcall validate_pae_over_nl80211(__int64 *a1, __int64 a2)
{
  __int64 v2; // x9
  __int64 result; // x0
  _QWORD *v5; // x20

  if ( *(_QWORD *)(*(_QWORD *)(a2 + 32) + 1632LL) )
  {
    v2 = *a1;
    result = 4294967201LL;
    if ( *(_QWORD *)(v2 + 864) )
    {
      if ( (*((_BYTE *)a1 + 1107) & 4) != 0 )
        return 0;
      else
        return 4294967201LL;
    }
  }
  else
  {
    v5 = *(_QWORD **)(a2 + 64);
    do_trace_netlink_extack("SOCKET_OWNER not set");
    if ( v5 )
      *v5 = "SOCKET_OWNER not set";
    return 4294967274LL;
  }
  return result;
}
