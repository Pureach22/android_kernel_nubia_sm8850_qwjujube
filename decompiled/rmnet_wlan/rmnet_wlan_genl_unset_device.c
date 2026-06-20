__int64 __fastcall rmnet_wlan_genl_unset_device(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x20
  __int64 v4; // x8
  unsigned int v5; // w8
  const char *v6; // x19
  const char **v7; // x20
  __int64 dev; // x0
  __int64 v11; // x0

  v2 = *(_QWORD *)(a2 + 32);
  v3 = *(_QWORD *)(v2 + 16);
  if ( v3 && (v4 = *(_QWORD *)(v2 + 48)) != 0 )
  {
    v5 = *(unsigned __int8 *)(v4 + 4);
    if ( v5 < 3 )
    {
      if ( v5 == 1 )
      {
        dev = rmnet_wwan_get_dev(a1);
        if ( !(unsigned int)rmnet_wlan_strlcmp(dev, v3 + 4, 16) )
          return rmnet_wwan_unset_device(v3 + 4, a2);
      }
      else
      {
        v11 = rmnet_wlan_get_dev(a1);
        if ( !(unsigned int)rmnet_wlan_strlcmp(v11, v3 + 4, 16) )
          return rmnet_wlan_unset_device(v3 + 4, a2);
      }
      return 0;
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
