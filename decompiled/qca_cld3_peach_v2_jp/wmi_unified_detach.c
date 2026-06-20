__int64 __fastcall wmi_unified_detach(__int64 a1)
{
  __int64 v2; // x19
  __int64 v3; // x0
  _QWORD *v4; // x19
  __int64 v5; // x21
  _QWORD *v6; // x20
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 *v9; // x0
  __int64 *v10; // x10
  __int64 v11; // x9
  __int64 v12; // x9
  __int64 *v13; // x8
  __int64 *v14; // x11
  __int64 v15; // x8
  __int64 *v16; // x0
  __int64 *v17; // x10
  __int64 v18; // x9
  __int64 v19; // x9
  __int64 *v20; // x8
  __int64 *v21; // x11
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0

  v2 = (unsigned int)(48 * *(_DWORD *)(a1 + 464));
  qdf_ssr_driver_dump_unregister_region("wmi_debug_log_info");
  qdf_ssr_driver_dump_unregister_region("wmi_rx_event_idx");
  qdf_ssr_driver_dump_unregister_region("wmi_rx_event");
  qdf_ssr_driver_dump_unregister_region("wmi_event_log_idx");
  qdf_ssr_driver_dump_unregister_region("wmi_event_log");
  qdf_ssr_driver_dump_unregister_region("wmi_command_log_idx");
  qdf_ssr_driver_dump_unregister_region("wmi_command_log");
  qdf_ssr_driver_dump_unregister_region("wmi_tx_cmp_idx");
  qdf_ssr_driver_dump_unregister_region("wmi_tx_cmp");
  v3 = _qdf_minidump_remove(*(_QWORD *)(a1 + 440), v2, "wmi_tx_cmp");
  wmi_hang_event_notifier_unregister(v3);
  wbuff_module_deregister(*(_QWORD *)(a1 + 16));
  v4 = *(_QWORD **)(a1 + 760);
  v5 = 0;
  *(_QWORD *)(a1 + 16) = 0;
  v6 = v4 + 648;
  do
  {
    v7 = v6[v5];
    if ( v7 )
    {
      _flush_workqueue(*(_QWORD *)(v7 + 160));
      destroy_workqueue(*(_QWORD *)(v6[v5] + 160LL));
      v8 = v6[v5];
      if ( *(_QWORD *)(v8 + 688) )
      {
        if ( *(_QWORD *)(v8 + 776) )
          *(_QWORD *)(v8 + 776) = 0;
        if ( *(_QWORD *)(v8 + 784) )
          *(_QWORD *)(v8 + 784) = 0;
        if ( *(_QWORD *)(v8 + 792) )
          *(_QWORD *)(v8 + 792) = 0;
        if ( *(_QWORD *)(v8 + 800) )
          *(_QWORD *)(v8 + 800) = 0;
        if ( *(_QWORD *)(v8 + 808) )
          *(_QWORD *)(v8 + 808) = 0;
        if ( *(_QWORD *)(v8 + 816) )
          *(_QWORD *)(v8 + 816) = 0;
        if ( *(_QWORD *)(v8 + 824) )
          *(_QWORD *)(v8 + 824) = 0;
        if ( *(_QWORD *)(v8 + 832) )
          *(_QWORD *)(v8 + 832) = 0;
        if ( *(_QWORD *)(v8 + 840) )
          *(_QWORD *)(v8 + 840) = 0;
        qdf_debugfs_remove_dir_recursive();
        v8 = v6[v5];
      }
      v9 = *(__int64 **)(v8 + 88);
      if ( v9 )
      {
        v10 = *(__int64 **)(v8 + 96);
        --*(_DWORD *)(v8 + 104);
        if ( v9 == v10 )
        {
          v11 = 0;
          *(_QWORD *)(v8 + 96) = 0;
        }
        else
        {
          v11 = *v9;
        }
        *(_QWORD *)(v8 + 88) = v11;
        while ( 1 )
        {
          *v9 = 0;
          _qdf_nbuf_free((__int64)v9);
          v12 = v6[v5];
          v13 = (__int64 *)(v12 + 88);
          v9 = *(__int64 **)(v12 + 88);
          if ( !v9 )
            break;
          v14 = *(__int64 **)(v12 + 96);
          --*(_DWORD *)(v12 + 104);
          if ( v9 == v14 )
          {
            *(_QWORD *)(v12 + 96) = 0;
            *v13 = 0;
          }
          else
          {
            *v13 = *v9;
          }
        }
      }
      _flush_workqueue(*(_QWORD *)(v6[v5] + 168LL));
      destroy_workqueue(*(_QWORD *)(v6[v5] + 168LL));
      v15 = v6[v5];
      v16 = *(__int64 **)(v15 + 192);
      if ( v16 )
      {
        v17 = *(__int64 **)(v15 + 200);
        --*(_DWORD *)(v15 + 208);
        if ( v16 == v17 )
        {
          v18 = 0;
          *(_QWORD *)(v15 + 200) = 0;
        }
        else
        {
          v18 = *v16;
        }
        *(_QWORD *)(v15 + 192) = v18;
        while ( 1 )
        {
          *v16 = 0;
          _qdf_nbuf_free((__int64)v16);
          v19 = v6[v5];
          v20 = (__int64 *)(v19 + 192);
          v16 = *(__int64 **)(v19 + 192);
          if ( !v16 )
            break;
          v21 = *(__int64 **)(v19 + 200);
          --*(_DWORD *)(v19 + 208);
          if ( v16 == v21 )
          {
            *(_QWORD *)(v19 + 200) = 0;
            *v20 = 0;
          }
          else
          {
            *v20 = *v16;
          }
        }
      }
      v22 = v6[v5];
      v23 = *(_QWORD *)(v22 + 328);
      if ( v23 )
      {
        _qdf_mem_free(v23);
        v22 = v6[v5];
      }
      *(_DWORD *)(v22 + 716) = 0;
      _qdf_mem_free(v6[v5]);
    }
    ++v5;
  }
  while ( v5 != 3 );
  v24 = v4[792];
  if ( v24 )
  {
    _qdf_mem_free(v24);
    v4[792] = 0;
  }
  v25 = v4[793];
  if ( v25 )
  {
    _qdf_mem_free(v25);
    v4[793] = 0;
  }
  v26 = v4[795];
  if ( v26 )
  {
    _qdf_mem_free(v26);
    v4[795] = 0;
  }
  *v4 = 0;
  return _qdf_mem_free((__int64)v4);
}
