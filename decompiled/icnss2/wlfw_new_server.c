__int64 __fastcall wlfw_new_server(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v4; // x2
  _DWORD *v5; // x3
  int v6; // w9

  v2 = a1 - 624;
  if ( a1 != 624 )
  {
    v4 = *(_QWORD *)(a1 + 1208);
    if ( (v4 & 0x100000) != 0 )
    {
      printk("%sicnss2_qmi: WLFW server delete in progress, Ignore server arrive: 0x%lx\n", byte_13289B, v4);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2_qmi: WLFW server delete in progress, Ignore server arrive: 0x%lx\n",
        (const char *)&unk_12DBF3,
        *(_QWORD *)(a1 + 1208));
      return 0;
    }
  }
  ipc_log_string(
    icnss_ipc_log_context,
    "icnss2_qmi: WLFW server arrive: node %u port %u\n",
    *(_DWORD *)(a2 + 12),
    *(_DWORD *)(a2 + 16));
  v5 = (_DWORD *)_kmalloc_cache_noprof(pm_stay_awake, 3520, 8);
  if ( v5 )
  {
    v6 = *(_DWORD *)(a2 + 16);
    *v5 = *(_DWORD *)(a2 + 12);
    v5[1] = v6;
    icnss_driver_event_post(v2, 0, 0, (__int64)v5);
    return 0;
  }
  return 4294967284LL;
}
