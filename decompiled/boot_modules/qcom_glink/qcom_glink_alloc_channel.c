__int64 __fastcall qcom_glink_alloc_channel(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x19
  __int64 v6; // x0

  v4 = _kmalloc_cache_noprof(ipc_log_string, 3520, 456);
  v5 = v4;
  if ( !v4 )
    return -12;
  *(_DWORD *)(v4 + 124) = 0;
  *(_DWORD *)(v4 + 144) = 0;
  _mutex_init(v4 + 344, "&channel->intent_req_lock", &qcom_glink_alloc_channel___key);
  *(_QWORD *)(v5 + 112) = a1;
  v6 = kstrdup(a2, 3264);
  *(_QWORD *)(v5 + 128) = v6;
  if ( !v6 )
  {
    kfree(v5);
    return -12;
  }
  *(_DWORD *)(v5 + 312) = 0;
  _init_swait_queue_head(v5 + 320, "&x->wait", &init_completion___key);
  *(_DWORD *)(v5 + 280) = 0;
  _init_swait_queue_head(v5 + 288, "&x->wait", &init_completion___key);
  _init_waitqueue_head(v5 + 400, "&channel->intent_req_wq", &qcom_glink_alloc_channel___key_61);
  *(_DWORD *)(v5 + 428) = 0;
  *(_QWORD *)(v5 + 200) = v5 + 200;
  *(_QWORD *)(v5 + 208) = v5 + 200;
  *(_QWORD *)(v5 + 224) = v5 + 224;
  *(_QWORD *)(v5 + 232) = v5 + 224;
  _init_waitqueue_head(v5 + 240, "&channel->rx_wq", &qcom_glink_alloc_channel___key_63);
  *(_QWORD *)(v5 + 184) = 0;
  *(_QWORD *)(v5 + 192) = 0;
  *(_QWORD *)(v5 + 152) = 0x1000000400000000LL;
  *(_QWORD *)(v5 + 160) = 0;
  *(_QWORD *)(v5 + 168) = 0;
  *(_QWORD *)(v5 + 176) = 0x1000000400000000LL;
  *(_DWORD *)(v5 + 120) = 1;
  return v5;
}
