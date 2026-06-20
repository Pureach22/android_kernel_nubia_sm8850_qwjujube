__int64 __fastcall hdd_adapter_init_link_info(__int64 result)
{
  __int64 v1; // x22
  __int64 v2; // x19
  __int64 v3; // x23
  __int64 v4; // x24
  __int64 v5; // x27
  __int64 v6; // x1
  __int64 v7; // x8

  v1 = result + 52840;
  if ( result != -52840 )
  {
    v2 = result;
    v3 = 0;
    v4 = result + 1632;
    while ( (unsigned __int64)(0x71B3F945A27B1F49LL * (v3 >> 3)) <= 2 )
    {
      v5 = v1 + v3;
      *(_QWORD *)v5 = v2;
      *(_BYTE *)(v5 + 8) = -1;
      *(_DWORD *)(v5 + 16) = 0;
      *(_QWORD *)(v5 + 24) = 0;
      *(_DWORD *)(v5 + 40) = 0;
      _init_swait_queue_head(v1 + v3 + 48, "&x->wait", &init_completion___key_1);
      result = qdf_event_create((_DWORD *)(v1 + v3 + 2648));
      v7 = 0x71B3F945A27B1F49LL * ((v2 + v3 - *(_QWORD *)(v1 + v3)) >> 3);
      if ( (unsigned __int8)(73 * ((v2 + v3 - *(_QWORD *)(v1 + v3)) >> 3)) > 2u )
      {
        __break(0x5512u);
        return hdd_adapter_enable_links(result, v6);
      }
      v3 += 6088;
      *(_BYTE *)(v4 + (v7 & 3)) = v7;
      *(_QWORD *)(v5 + 6040) = hdd_chan_change_notify_work_handler;
      *(_QWORD *)(v5 + 6048) = v5;
      *(_QWORD *)(v5 + 6008) = 0xFFFFFFFE00000LL;
      *(_QWORD *)(v5 + 6016) = v5 + 6016;
      *(_QWORD *)(v5 + 6024) = v5 + 6016;
      *(_QWORD *)(v5 + 6032) = _qdf_defer_func;
      if ( v5 == -6088 )
        return result;
    }
  }
  return result;
}
