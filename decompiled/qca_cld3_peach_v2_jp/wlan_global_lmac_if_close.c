__int64 __fastcall wlan_global_lmac_if_close(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x20

  if ( a1 )
  {
    target_if_wake_lock_deinit();
    v2 = *(_QWORD *)(a1 + 2128);
    v3 = *(_QWORD *)(a1 + 2136);
    *(_QWORD *)(a1 + 2128) = 0;
    *(_QWORD *)(a1 + 2136) = 0;
    _qdf_mem_free(v2);
    _qdf_mem_free(v3);
    return 0;
  }
  else
  {
    qdf_trace_msg(56, 2, "%s: psoc is NULL", "wlan_global_lmac_if_close");
    return 4;
  }
}
