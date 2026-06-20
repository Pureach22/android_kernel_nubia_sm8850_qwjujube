__int64 __fastcall hif_exec_create(int a1, int a2)
{
  __int64 result; // x0
  __int64 v5; // x19
  __int64 v6; // x19

  qdf_trace_msg(61, 8, "%s: %s: create exec_type %d budget %d", "hif_exec_create", "hif_exec_create", a1, a2 << 6);
  if ( a1 == 1 )
  {
    result = _qdf_mem_malloc(3504, "hif_exec_tasklet_create", 1018);
    if ( result )
    {
      v6 = result;
      *(_QWORD *)result = &tasklet_sched_ops;
      tasklet_init(result + 3464, hif_exec_tasklet_fn, result);
      *(_BYTE *)(v6 + 2680) = 1;
      return v6;
    }
  }
  else if ( a1 )
  {
    return 0;
  }
  else
  {
    result = _qdf_mem_malloc(6656, "hif_exec_napi_create", 963);
    if ( result )
    {
      *(_DWORD *)(result + 236) = a2;
      *(_QWORD *)result = &napi_sched_ops;
      v5 = result;
      *(_BYTE *)(result + 2680) = 1;
      init_dummy_netdev(result + 3520);
      qdf_status_from_os_return(0);
      netif_napi_add_weight(v5 + 3520, v5 + 6208, hif_exec_poll, 64);
      napi_enable(v5 + 6208);
      return v5;
    }
  }
  return result;
}
