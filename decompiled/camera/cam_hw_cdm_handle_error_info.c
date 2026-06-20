__int64 __fastcall cam_hw_cdm_handle_error_info(__int64 a1)
{
  unsigned int hw_reg; // w20
  __int64 v3; // x23
  unsigned int v4; // w22
  unsigned __int64 v5; // x24
  unsigned int **v6; // x8
  unsigned int v7; // w9
  unsigned int v8; // w0
  const char *v9; // x5
  __int64 v10; // x4
  unsigned int v11; // w0
  __int64 v12; // x8
  int *v13; // x21
  int v14; // w8
  int *v15; // x0
  unsigned __int64 v22; // x9
  unsigned __int64 v25; // x9
  unsigned __int64 v29; // x10
  unsigned __int64 v32; // x10
  unsigned __int64 v35; // x10
  unsigned __int64 v38; // x9
  unsigned int v39; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v40; // [xsp+18h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 3680);
  v39 = 0;
  if ( **(_DWORD **)(*(_QWORD *)(v3 + 232) + 72LL) )
  {
    mutex_lock(v3 + 2352);
    if ( **(_DWORD **)(*(_QWORD *)(v3 + 232) + 72LL) > 1u )
    {
      mutex_lock(v3 + 2992);
      if ( **(_DWORD **)(*(_QWORD *)(v3 + 232) + 72LL) >= 3u )
      {
        mutex_lock(v3 + 3632);
        if ( **(_DWORD **)(*(_QWORD *)(v3 + 232) + 72LL) >= 4u )
        {
          mutex_lock(v3 + 4272);
          if ( **(_DWORD **)(*(_QWORD *)(v3 + 232) + 72LL) > 4u )
            goto LABEL_59;
        }
      }
    }
  }
  *(_DWORD *)(v3 + 144) = 0;
  _X8 = (unsigned __int64 *)(v3 + 4856);
  __asm { PRFM            #0x11, [X8] }
  do
    v22 = __ldxr(_X8);
  while ( __stxr(v22 | 0x10, _X8) );
  _X8 = (unsigned __int64 *)(v3 + 4856);
  __asm { PRFM            #0x11, [X8] }
  do
    v25 = __ldxr(_X8);
  while ( __stxr(v25 | 0x40, _X8) );
  if ( !*(_DWORD *)(a1 + 92) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      2,
      "cam_hw_cdm_handle_error_info",
      1792,
      "CDM is in power down state");
    hw_reg = -5;
    goto LABEL_60;
  }
  v4 = 1;
  cam_hw_cdm_pause_core(a1, 1u);
  hw_reg = cam_cdm_read_hw_reg(a1, *(_DWORD *)(**(_QWORD **)(v3 + 232) + 88LL), (int *)&v39);
  v5 = ((unsigned __int64)v39 >> 22) & 3;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    1,
    1,
    "cam_hw_cdm_handle_error_info",
    1814,
    "Hang detected for %s%u's fifo %d with tag 0x%x",
    *(const char **)(a1 + 152),
    *(_DWORD *)(a1 + 116),
    (v39 >> 22) & 3,
    HIBYTE(v39));
  cam_hw_cdm_dump_core_debug_registers(a1, 0);
  v6 = *(unsigned int ***)(v3 + 232);
  v7 = *v6[9];
  if ( !v7 )
    goto LABEL_26;
  if ( *(_DWORD *)(v3 + 2404) )
  {
    if ( cam_cdm_write_hw_reg(a1, *v6[5], 0x70003u) )
      goto LABEL_23;
    v6 = *(unsigned int ***)(v3 + 232);
    v4 = 9;
    v7 = *v6[9];
    if ( v7 < 2 )
      goto LABEL_26;
  }
  else
  {
    v4 = 1;
    if ( v7 < 2 )
      goto LABEL_26;
  }
  if ( *(_DWORD *)(v3 + 3044) )
  {
    if ( cam_cdm_write_hw_reg(a1, *v6[6], 0x70003u) )
      goto LABEL_23;
    v6 = *(unsigned int ***)(v3 + 232);
    v4 |= 0x10u;
    v7 = *v6[9];
  }
  if ( v7 < 3 )
    goto LABEL_26;
  if ( !*(_DWORD *)(v3 + 3684) )
    goto LABEL_20;
  if ( cam_cdm_write_hw_reg(a1, *v6[7], 0x70003u) )
  {
LABEL_23:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_handle_error_info",
      1828,
      "Failed to Write CDM HW IRQ mask");
    goto LABEL_60;
  }
  v6 = *(unsigned int ***)(v3 + 232);
  v4 |= 0x20u;
  v7 = *v6[9];
LABEL_20:
  if ( v7 >= 4 )
  {
    if ( *(_DWORD *)(v3 + 4324) )
    {
      if ( cam_cdm_write_hw_reg(a1, *v6[8], 0x70003u) )
        goto LABEL_23;
      v6 = *(unsigned int ***)(v3 + 232);
      v4 |= 0x40u;
      v7 = *v6[9];
    }
    if ( v7 > 4 )
      goto LABEL_59;
  }
LABEL_26:
  if ( cam_cdm_write_hw_reg(a1, (*v6)[4], v4) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_handle_error_info",
      1835,
      "Failed to Write CDM HW reset");
    goto LABEL_60;
  }
  if ( (debug_mdl & 1) != 0 && !debug_priority )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      4,
      "cam_hw_cdm_handle_error_info",
      1839,
      "Waiting for CDM HW resetdone");
  if ( cam_common_wait_for_completion_timeout(v3 + 144) <= 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_handle_error_info",
      1846,
      "CDM HW reset Wait failed rc=%d",
      -110);
    _X8 = (unsigned __int64 *)(v3 + 4856);
    __asm { PRFM            #0x11, [X8] }
    do
      v38 = __ldxr(_X8);
    while ( __stxr(v38 | 0x80, _X8) );
  }
  v8 = cam_hw_cdm_set_cdm_core_cfg(a1);
  if ( v8 )
  {
    hw_reg = v8;
    v9 = "Failed to configure CDM rc=%d";
    v10 = 1853;
LABEL_37:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_handle_error_info",
      v10,
      v9,
      hw_reg);
    goto LABEL_60;
  }
  v11 = ((__int64 (__fastcall *)(__int64))cam_hw_cdm_set_cdm_blfifo_cfg)(a1);
  if ( v11 )
  {
    hw_reg = v11;
    v9 = "Failed to configure CDM fifo rc=%d";
    v10 = 1860;
    goto LABEL_37;
  }
  v12 = v3 + 640LL * (unsigned int)v5;
  v13 = *(int **)(v12 + 2336);
  if ( v13 != (int *)(v12 + 2336) && v13 != &dword_20 )
  {
    v14 = *(v13 - 7);
    if ( v14 == 2 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        1,
        "cam_hw_cdm_handle_error_info",
        1875,
        "Invalid node=%pK %d",
        v13 - 8,
        2);
    }
    else if ( v14 == 1 )
    {
      cam_cdm_notify_clients(a1, 7, (__int64)(v13 - 8));
    }
    list_del_init_0(v13);
    v15 = v13 - 8;
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v15, 0);
    else
      kvfree(v15);
  }
  ((void (__fastcall *)(__int64, _QWORD))cam_hw_cdm_reset_cleanup)(a1, 0);
  hw_reg = 0;
LABEL_60:
  while ( 1 )
  {
    _X8 = (unsigned __int64 *)(v3 + 4856);
    __asm { PRFM            #0x11, [X8] }
    do
      v29 = __ldxr(_X8);
    while ( __stxr(v29 & 0xFFFFFFFFFFFFFFBFLL, _X8) );
    _X8 = (unsigned __int64 *)(v3 + 4856);
    __asm { PRFM            #0x11, [X8] }
    do
      v32 = __ldxr(_X8);
    while ( __stxr(v32 & 0xFFFFFFFFFFFFFFEFLL, _X8) );
    _X8 = (unsigned __int64 *)(v3 + 4856);
    __asm { PRFM            #0x11, [X8] }
    do
      v35 = __ldxr(_X8);
    while ( __stxr(v35 & 0xFFFFFFFFFFFFFF7FLL, _X8) );
    if ( !**(_DWORD **)(*(_QWORD *)(v3 + 232) + 72LL) )
      break;
    mutex_unlock(v3 + 2352);
    if ( **(_DWORD **)(*(_QWORD *)(v3 + 232) + 72LL) < 2u )
      break;
    mutex_unlock(v3 + 2992);
    if ( **(_DWORD **)(*(_QWORD *)(v3 + 232) + 72LL) < 3u )
      break;
    mutex_unlock(v3 + 3632);
    if ( **(_DWORD **)(*(_QWORD *)(v3 + 232) + 72LL) < 4u )
      break;
    mutex_unlock(v3 + 4272);
    if ( **(_DWORD **)(*(_QWORD *)(v3 + 232) + 72LL) <= 4u )
      break;
LABEL_59:
    __break(0x5512u);
  }
  _ReadStatusReg(SP_EL0);
  return hw_reg;
}
