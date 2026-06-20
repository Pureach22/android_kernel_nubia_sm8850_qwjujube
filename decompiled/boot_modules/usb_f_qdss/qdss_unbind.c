__int64 __fastcall qdss_unbind(__int64 a1, __int64 a2)
{
  __int64 v3; // x1
  const char *v4; // x3
  _QWORD *v5; // x8
  _QWORD *v6; // x8
  _QWORD *v7; // x20
  const char *v8; // x21

  ipc_log_string(qdss_ipc_log, "%s: channel:%s\n", "qdss_unbind", *(const char **)(a2 + 296));
  qdss_disable(a2);
  _flush_workqueue(*(_QWORD *)(a2 + 464));
  v3 = *(_QWORD *)(a2 + 288);
  if ( v3 )
  {
    usb_ep_free_request(*(_QWORD *)(a2 + 240), v3);
    *(_QWORD *)(a2 + 288) = 0;
  }
  v4 = *(const char **)(a2 + 296);
  qdss_string_defs = 0;
  byte_188 = 0;
  ipc_log_string(qdss_ipc_log, "%s: channel:%s\n", "clear_eps", v4);
  v5 = *(_QWORD **)(a2 + 232);
  if ( v5 )
    *v5 = 0;
  v6 = *(_QWORD **)(a2 + 224);
  if ( v6 )
    *v6 = 0;
  v7 = *(_QWORD **)(a2 + 240);
  if ( v7 )
  {
    v8 = *(const char **)(a2 + 296);
    if ( strcmp(v8, "qdss_mdm") && strcmp(v8, "qdss_sw") )
    {
      msm_ep_clear_ops(v7);
      msm_ep_set_mode(*(_QWORD *)(a2 + 240), 0);
      v7 = *(_QWORD **)(a2 + 240);
    }
    *v7 = 0;
  }
  ipc_log_string(qdss_ipc_log, "%s: channel:%s\n", "clear_desc", *(const char **)(a2 + 296));
  return usb_free_all_descriptors(a2);
}
