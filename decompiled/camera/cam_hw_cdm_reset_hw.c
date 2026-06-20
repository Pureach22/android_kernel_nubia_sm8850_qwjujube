__int64 __fastcall cam_hw_cdm_reset_hw(__int64 a1, unsigned int a2)
{
  __int64 v2; // x22
  unsigned int v5; // w20
  unsigned int v6; // w0
  __int64 v7; // x6
  __int64 v8; // x7
  const char *v9; // x5
  __int64 v10; // x4
  unsigned __int64 v18; // x9
  unsigned __int64 v21; // x10

  v2 = *(_QWORD *)(a1 + 3680);
  if ( **(_DWORD **)(*(_QWORD *)(v2 + 232) + 72LL) )
  {
    mutex_lock(v2 + 2352);
    if ( **(_DWORD **)(*(_QWORD *)(v2 + 232) + 72LL) > 1u )
    {
      mutex_lock(v2 + 2992);
      if ( **(_DWORD **)(*(_QWORD *)(v2 + 232) + 72LL) >= 3u )
      {
        mutex_lock(v2 + 3632);
        if ( **(_DWORD **)(*(_QWORD *)(v2 + 232) + 72LL) >= 4u )
        {
          mutex_lock(v2 + 4272);
          if ( **(_DWORD **)(*(_QWORD *)(v2 + 232) + 72LL) > 4u )
            goto LABEL_26;
        }
      }
    }
  }
  while ( 1 )
  {
    _X8 = (unsigned __int64 *)(v2 + 4856);
    __asm { PRFM            #0x11, [X8] }
    do
      v18 = __ldxr(_X8);
    while ( __stxr(v18 | 0x10, _X8) );
    *(_DWORD *)(v2 + 144) = 0;
    cam_hw_cdm_pause_core(a1, 1u);
    if ( cam_cdm_write_hw_reg(a1, *(_DWORD *)(**(_QWORD **)(v2 + 232) + 16LL), 1u) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        1,
        "cam_hw_cdm_reset_hw",
        1724,
        "Failed to Write %s%u HW reset",
        *(const char **)(a1 + 152),
        *(_DWORD *)(a1 + 116));
      v5 = -5;
    }
    else
    {
      if ( (debug_mdl & 1) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          4,
          "cam_hw_cdm_reset_hw",
          1728,
          "Waiting for %s%u HW reset done",
          *(const char **)(a1 + 152),
          *(_DWORD *)(a1 + 116));
      if ( cam_common_wait_for_completion_timeout(v2 + 144) <= 0 )
      {
        v5 = -110;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          1,
          "cam_hw_cdm_reset_hw",
          1738,
          "%s%u HW reset Wait failed rc=%d",
          *(const char **)(a1 + 152),
          *(_DWORD *)(a1 + 116),
          -110);
        cam_hw_cdm_dump_core_debug_registers(a1, 0);
        cam_hw_cdm_pause_core(a1, 0);
      }
      else
      {
        v6 = cam_hw_cdm_set_cdm_core_cfg(a1);
        if ( v6 )
        {
          v7 = *(_QWORD *)(a1 + 152);
          v8 = *(unsigned int *)(a1 + 116);
          v5 = v6;
          v9 = "Failed to configure %s%u rc=%d";
          v10 = 1749;
        }
        else
        {
          v5 = ((__int64 (__fastcall *)(__int64))cam_hw_cdm_set_cdm_blfifo_cfg)(a1);
          if ( !v5 )
          {
            ((void (__fastcall *)(__int64, _QWORD))cam_hw_cdm_reset_cleanup)(a1, a2);
            goto LABEL_30;
          }
          v7 = *(_QWORD *)(a1 + 152);
          v8 = *(unsigned int *)(a1 + 116);
          v9 = "Failed to configure %s%u fifo rc=%d";
          v10 = 1757;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, unsigned int))cam_print_log)(
          3,
          1,
          1,
          "cam_hw_cdm_reset_hw",
          v10,
          v9,
          v7,
          v8,
          v5);
      }
    }
LABEL_30:
    _X8 = (unsigned __int64 *)(v2 + 4856);
    __asm { PRFM            #0x11, [X8] }
    do
      v21 = __ldxr(_X8);
    while ( __stxr(v21 & 0xFFFFFFFFFFFFFFEFLL, _X8) );
    if ( !**(_DWORD **)(*(_QWORD *)(v2 + 232) + 72LL) )
      return v5;
    mutex_unlock(v2 + 2352);
    if ( **(_DWORD **)(*(_QWORD *)(v2 + 232) + 72LL) < 2u )
      return v5;
    mutex_unlock(v2 + 2992);
    if ( **(_DWORD **)(*(_QWORD *)(v2 + 232) + 72LL) < 3u )
      return v5;
    mutex_unlock(v2 + 3632);
    if ( **(_DWORD **)(*(_QWORD *)(v2 + 232) + 72LL) < 4u )
      return v5;
    mutex_unlock(v2 + 4272);
    if ( **(_DWORD **)(*(_QWORD *)(v2 + 232) + 72LL) <= 4u )
      return v5;
LABEL_26:
    __break(0x5512u);
  }
}
