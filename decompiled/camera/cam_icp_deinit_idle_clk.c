__int64 __fastcall cam_icp_deinit_idle_clk(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 v4; // x22
  __int64 v5; // x21
  __int64 v6; // x0
  unsigned int v7; // w20
  unsigned int *v9; // x0

  v2 = *(_QWORD *)(a2 + 8);
  mutex_lock(a1);
  v4 = 0;
  v5 = 0;
  *(_QWORD *)(v2 + 24) = 0;
  *(_DWORD *)(v2 + 40) = 0;
  while ( 1 )
  {
    mutex_lock(*(_QWORD *)(a1 + 88) + v5);
    v6 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + v4);
    if ( !v6 || *(_DWORD *)(v6 + 104) != 2 || *(_DWORD *)(*(_QWORD *)(v6 + 16) + 8LL) != *(_DWORD *)(v2 + 8) )
      goto LABEL_2;
    if ( (**(_QWORD **)(v6 + 1720) & 0xFFFFFFFFFFLL) != 0 )
      break;
    cam_icp_ctx_clk_info_init(v6);
LABEL_2:
    mutex_unlock(*(_QWORD *)(a1 + 88) + v5);
    v4 += 8;
    v5 += 48;
    if ( v4 == 432 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_deinit_idle_clk",
        493,
        "[%s] No acquired ctx data found",
        (const char *)(a1 + 112));
      v7 = -14;
      goto LABEL_9;
    }
  }
  mutex_unlock(*(_QWORD *)(a1 + 88) + v5);
  v9 = *(unsigned int **)(v2 + 552);
  if ( v9 )
  {
    if ( (debug_mdl & 0x2000100) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x2000100,
        4,
        "cam_icp_device_timer_reset",
        441,
        "[%s] reset timer for device: %s",
        (const char *)(a1 + 112),
        *(const char **)v2);
      v9 = *(unsigned int **)(v2 + 552);
    }
    crm_timer_reset(v9);
    ++*(_DWORD *)(v2 + 560);
  }
  v7 = -16;
LABEL_9:
  mutex_unlock(a1);
  return v7;
}
