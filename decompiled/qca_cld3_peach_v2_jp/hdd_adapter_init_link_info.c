__int64 __fastcall hdd_adapter_init_link_info(__int64 result)
{
  __int64 v1; // x22
  __int64 v2; // x21
  __int64 v3; // x23
  int v4; // w19
  __int64 v5; // x25

  v1 = result + 52832;
  if ( result != -52832 )
  {
    v2 = result;
    v3 = 52832;
    v4 = result;
    while ( 1 )
    {
      v5 = v2 + v3;
      *(_QWORD *)v5 = v2;
      *(_BYTE *)(v5 + 8) = -1;
      *(_DWORD *)(v5 + 16) = 0;
      *(_QWORD *)(v5 + 24) = 0;
      *(_DWORD *)(v5 + 40) = 0;
      _init_swait_queue_head(v2 + v3 + 48, "&x->wait", &init_completion___key_1);
      result = qdf_event_create((_DWORD *)(v2 + v3 + 2376));
      if ( 19 * (unsigned __int8)((unsigned int)(v4 - *(_DWORD *)(v2 + v3)) >> 4) )
        break;
      v3 += 4528;
      v4 += 4528;
      *(_BYTE *)(v2 + 1632) = 0;
      *(_QWORD *)(v5 + 4480) = hdd_chan_change_notify_work_handler;
      *(_QWORD *)(v5 + 4488) = v5;
      *(_QWORD *)(v5 + 4448) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v5 + 4456) = v5 + 4456;
      *(_QWORD *)(v5 + 4464) = v5 + 4456;
      *(_QWORD *)(v5 + 4472) = _qdf_defer_func;
      if ( v5 + 4528 != v1 )
        return result;
    }
    __break(0x5512u);
    return hdd_adapter_feature_update_work_init(result);
  }
  return result;
}
