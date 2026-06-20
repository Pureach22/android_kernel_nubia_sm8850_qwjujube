__int64 __fastcall rmnet_perf_cmd_ingress_handler(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x8

  if ( *(_DWORD *)(a1 + 116) && (v1 = a1, v2 = _pskb_pull_tail(), a1 = v1, !v2) )
    return printk(&unk_F4A5, "rmnet_perf_cmd_ingress_handler");
  else
    return rmnet_perf_nl_map_cmd_multicast(a1);
}
