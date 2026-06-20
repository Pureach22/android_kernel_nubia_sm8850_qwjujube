__int64 __fastcall wlan_ipa_uc_loaded_uc_cb(__int64 a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7

  result = ipa_cb_is_ready();
  if ( (result & 1) == 0 )
    return qdf_trace_msg(0x61u, 4u, "%s: IPA is not READY", v3, v4, v5, v6, v7, v8, v9, v10, "wlan_ipa_uc_loaded_uc_cb");
  if ( !a1 )
    return qdf_trace_msg(
             0x61u,
             2u,
             "%s: Invalid IPA context",
             v3,
             v4,
             v5,
             v6,
             v7,
             v8,
             v9,
             v10,
             "wlan_ipa_uc_loaded_uc_cb");
  if ( *(_QWORD *)(a1 + 2264) != a1 + 2264 )
  {
    *(_BYTE *)(a1 + 6984) = 1;
    return result;
  }
  result = _qdf_mem_malloc(0x20u, "wlan_ipa_uc_loaded_uc_cb", 253);
  if ( result )
  {
    *(_WORD *)(result + 2) = 8;
    if ( !*(_QWORD *)(a1 + 2304) )
    {
      *(_QWORD *)(a1 + 2304) = result;
      if ( !*(_DWORD *)(a1 + 7452) )
        return queue_work_on(32, system_wq, a1 + 2256);
      *(_QWORD *)(a1 + 2304) = 0;
    }
    return _qdf_mem_free(result);
  }
  return result;
}
