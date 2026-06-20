__int64 __fastcall rmnet_wlan_genl_set_device(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  __int64 v3; // x8
  __int64 v4; // x9
  unsigned int v5; // w9
  const char *v6; // x19
  const char **v7; // x20
  char *v9; // x0

  v2 = *(_QWORD *)(a2 + 32);
  v3 = *(_QWORD *)(v2 + 16);
  if ( v3 && (v4 = *(_QWORD *)(v2 + 48)) != 0 )
  {
    v5 = *(unsigned __int8 *)(v4 + 4);
    if ( v5 < 3 )
    {
      v9 = (char *)(v3 + 4);
      if ( v5 == 1 )
        return rmnet_wwan_set_device(v9);
      else
        return ((__int64 (__fastcall *)(char *))rmnet_wlan_set_device)(v9);
    }
    v6 = "Network type not supported!";
  }
  else
  {
    v6 = "Must specify device and network info";
  }
  v7 = *(const char ***)(a2 + 64);
  do_trace_netlink_extack(v6);
  if ( v7 )
    *v7 = v6;
  return 4294967274LL;
}
