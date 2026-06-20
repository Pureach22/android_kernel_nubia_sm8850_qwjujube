__int64 __fastcall rmnet_wlan_genl_act_encap_port_drop(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  _QWORD *v4; // x20

  v2 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 40LL);
  if ( v2 )
    return rmnet_wlan_act_encap_port_drop(*(unsigned __int16 *)(v2 + 4));
  v4 = *(_QWORD **)(a2 + 64);
  do_trace_netlink_extack("Must specify encap port");
  if ( v4 )
    *v4 = "Must specify encap port";
  return 4294967274LL;
}
