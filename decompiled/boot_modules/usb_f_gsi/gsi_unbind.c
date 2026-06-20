__int64 __fastcall gsi_unbind(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  void (__fastcall *v4)(_QWORD); // x8
  int v5; // w9
  __int64 v6; // x0
  __int64 result; // x0

  if ( a2 )
    ipc_log_string(*(_QWORD *)(a2 + 1344), "%s:id:%d: dwq start", "gsi_unbind", *(_DWORD *)(a2 + 224));
  if ( *(_DWORD *)(a2 + 272) )
    gsi_disable(a2);
  drain_workqueue(*(_QWORD *)(a2 + 680));
  if ( a2 )
    ipc_log_string(*(_QWORD *)(a2 + 1344), "%s:id:%d: dwq end", "gsi_unbind", *(_DWORD *)(a2 + 224));
  v3 = *(unsigned int *)(a2 + 224);
  v4 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a2 + 1048) + 24LL);
  if ( *((_DWORD *)v4 - 1) != 438878351 )
    __break(0x8228u);
  v4(v3);
  rndis_gsi_string_defs = 0;
  ecm_gsi_string_defs = 0;
  v5 = *(_DWORD *)(a2 + 224);
  rmnet_gsi_string_defs = 0;
  mbim_gsi_string_defs = 0;
  qdss_gsi_string_defs = 0;
  if ( !v5 )
  {
    v6 = *(_QWORD *)(a2 + 264);
    *(_DWORD *)(a2 + 688) = 0;
    rndis_deregister(v6);
  }
  result = usb_free_all_descriptors(a2);
  if ( *(_QWORD *)(a2 + 1208) )
  {
    kfree(**(_QWORD **)(a2 + 1216));
    return usb_ep_free_request(*(_QWORD *)(a2 + 1208));
  }
  return result;
}
