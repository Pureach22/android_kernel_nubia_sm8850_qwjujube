void __fastcall qcom_slim_ngd_ssr_pdr_notify(__int64 a1, __int64 a2)
{
  int v4; // w8
  int v5; // w8
  __int64 *v6; // x8
  __int64 v7; // x1
  __int64 v8; // x1
  int v9; // w8
  int v10; // w8
  int v11; // w8
  __int64 v12; // x9
  _QWORD *v13; // x10
  int v14; // w8
  int v15; // w8
  unsigned int v22; // w9

  _slimbus_dbg();
  v4 = *(_DWORD *)(a1 + 5476);
  if ( v4 >= 3 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 5488), "SLIM DSP SSR/PDR notify cb:0x%lx\n", a2);
    v4 = *(_DWORD *)(a1 + 5476);
  }
  if ( !v4 )
    ipc_log_string(*(_QWORD *)(a1 + 5496), "SLIM DSP SSR/PDR notify cb:0x%lx\n", a2);
  if ( a2 <= 2 )
  {
    if ( a2 != 1 )
    {
      if ( a2 != 2 )
        return;
LABEL_12:
      _slimbus_dbg();
      v5 = *(_DWORD *)(a1 + 5476);
      if ( v5 >= 3 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 5488), "SLIM SSR Before Shutdown\n");
        v5 = *(_DWORD *)(a1 + 5476);
      }
      if ( !v5 )
        ipc_log_string(*(_QWORD *)(a1 + 5496), "SLIM SSR Before Shutdown\n");
      v6 = *(__int64 **)(a1 + 1968);
      v7 = v6[14];
      if ( !v7 )
        v7 = *v6;
      if ( *(_DWORD *)(a1 + 5384) != 3 )
      {
        mutex_lock(a1 + 5200, v7);
        mutex_lock(a1 + 5152, v8);
        *(_DWORD *)(a1 + 5384) = 4;
        *(_BYTE *)(a1 + 5509) = 0;
        _slimbus_dbg();
        v9 = *(_DWORD *)(a1 + 5476);
        if ( v9 >= 3 )
        {
          ipc_log_string(*(_QWORD *)(a1 + 5488), "SLIM SSR going down\n");
          v9 = *(_DWORD *)(a1 + 5476);
        }
        if ( !v9 )
          ipc_log_string(*(_QWORD *)(a1 + 5496), "SLIM SSR going down\n");
        _X8 = (unsigned int *)(*(_QWORD *)(a1 + 928) + 480LL);
        __asm { PRFM            #0x11, [X8] }
        do
          v22 = __ldxr(_X8);
        while ( __stxr(v22 + 1, _X8) );
        _slimbus_dbg();
        v10 = *(_DWORD *)(a1 + 5476);
        if ( v10 >= 3 )
        {
          ipc_log_string(
            *(_QWORD *)(a1 + 5488),
            "SLIM %s: PM get_no_resume count:%d\n",
            "qcom_slim_ngd_ssr_pdr_notify",
            *(_DWORD *)(*(_QWORD *)(a1 + 928) + 480LL));
          v10 = *(_DWORD *)(a1 + 5476);
        }
        if ( !v10 )
          ipc_log_string(
            *(_QWORD *)(a1 + 5496),
            "SLIM %s: PM get_no_resume count:%d\n",
            "qcom_slim_ngd_ssr_pdr_notify",
            *(_DWORD *)(*(_QWORD *)(a1 + 928) + 480LL));
        device_for_each_child(*(_QWORD *)(a1 + 928), 0, qcom_slim_ngd_update_device_status);
        qcom_slim_ngd_exit_dma(a1);
        *(_DWORD *)(a1 + 5384) = 3;
        _slimbus_dbg();
        v11 = *(_DWORD *)(a1 + 5476);
        if ( v11 >= 3 )
        {
          ipc_log_string(*(_QWORD *)(a1 + 5488), "SLIM SSR down\n");
          v11 = *(_DWORD *)(a1 + 5476);
        }
        if ( !v11 )
          ipc_log_string(*(_QWORD *)(a1 + 5496), "SLIM SSR down\n");
        mutex_unlock(a1 + 5152);
        mutex_unlock(a1 + 5200);
      }
      if ( a2 != 0xFFFFFFF )
        return;
LABEL_45:
      mutex_lock(a1 + 5248, v7);
      qcom_slim_ngd_enable(a1, 0);
      mutex_unlock(a1 + 5248);
      return;
    }
  }
  else
  {
    if ( a2 == 3 )
    {
      _slimbus_dbg();
      v15 = *(_DWORD *)(a1 + 5476);
      if ( v15 >= 3 )
      {
        ipc_log_string(*(_QWORD *)(a1 + 5488), "SLIM SSR After Shutdown\n");
        v15 = *(_DWORD *)(a1 + 5476);
      }
      if ( !v15 )
        ipc_log_string(*(_QWORD *)(a1 + 5496), "SLIM SSR After Shutdown\n");
      goto LABEL_45;
    }
    if ( a2 != 0x1FFFFFFF )
    {
      if ( a2 != 0xFFFFFFF )
        return;
      goto LABEL_12;
    }
  }
  if ( *(_BYTE *)(a1 + 5468) == 1 )
  {
    v12 = *(unsigned int *)(a1 + 5464);
    v13 = *(_QWORD **)(a1 + 5440);
    *(_QWORD *)(a1 + 5448) = *(_QWORD *)(a1 + 5456);
    *v13 = v12;
  }
  queue_work_on(32, system_wq, a1 + 4976);
  _slimbus_dbg();
  v14 = *(_DWORD *)(a1 + 5476);
  if ( v14 >= 3 )
  {
    ipc_log_string(*(_QWORD *)(a1 + 5488), "SLIM SSR up\n");
    v14 = *(_DWORD *)(a1 + 5476);
  }
  if ( !v14 )
    ipc_log_string(*(_QWORD *)(a1 + 5496), "SLIM SSR up\n");
}
