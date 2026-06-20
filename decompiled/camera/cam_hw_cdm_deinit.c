__int64 __fastcall cam_hw_cdm_deinit(__int64 a1)
{
  __int64 v1; // x20
  unsigned int v3; // w22
  unsigned int **v4; // x8
  unsigned __int64 StatusReg; // x20
  __int64 v6; // x1
  __int64 result; // x0
  const char *v8; // x6
  int v9; // w7
  unsigned int v10; // w19
  unsigned __int64 v13; // x9
  unsigned __int64 v20; // x10

  if ( !a1 )
    return 4294967274LL;
  v1 = *(_QWORD *)(a1 + 3680);
  if ( **(_DWORD **)(*(_QWORD *)(v1 + 232) + 72LL) )
  {
    mutex_lock(v1 + 2352);
    if ( **(_DWORD **)(*(_QWORD *)(v1 + 232) + 72LL) > 1u )
    {
      mutex_lock(v1 + 2992);
      if ( **(_DWORD **)(*(_QWORD *)(v1 + 232) + 72LL) >= 3u )
      {
        mutex_lock(v1 + 3632);
        if ( **(_DWORD **)(*(_QWORD *)(v1 + 232) + 72LL) >= 4u )
        {
          mutex_lock(v1 + 4272);
          if ( **(_DWORD **)(*(_QWORD *)(v1 + 232) + 72LL) > 4u )
            goto LABEL_51;
        }
      }
    }
  }
  ((void (__fastcall *)(__int64))cam_hw_cdm_clear_bl_requests)(v1);
  while ( 1 )
  {
    _X8 = (unsigned __int64 *)(v1 + 4856);
    __asm { PRFM            #0x11, [X8] }
    do
      v13 = __ldxr(_X8);
    while ( __stxr(v13 | 0x10, _X8) );
    *(_DWORD *)(v1 + 144) = 0;
    v3 = 1;
    cam_hw_cdm_pause_core(a1, 1u);
    v4 = *(unsigned int ***)(v1 + 232);
    if ( !*v4[9] )
      goto LABEL_59;
    if ( *(_DWORD *)(v1 + 2404) )
    {
      if ( cam_cdm_write_hw_reg(a1, *v4[5], 0x70003u) )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          1,
          1,
          "cam_hw_cdm_deinit",
          2207,
          "Failed to Write CDM HW IRQ mask");
      v3 = 9;
    }
    v4 = *(unsigned int ***)(v1 + 232);
    if ( *v4[9] < 2 )
      goto LABEL_59;
    if ( *(_DWORD *)(v1 + 3044) )
    {
      v3 |= 0x10u;
      if ( cam_cdm_write_hw_reg(a1, *v4[6], 0x70003u) )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          1,
          1,
          "cam_hw_cdm_deinit",
          2207,
          "Failed to Write CDM HW IRQ mask");
    }
    v4 = *(unsigned int ***)(v1 + 232);
    if ( *v4[9] < 3 )
      goto LABEL_59;
    if ( *(_DWORD *)(v1 + 3684) )
    {
      v3 |= 0x20u;
      if ( cam_cdm_write_hw_reg(a1, *v4[7], 0x70003u) )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          1,
          1,
          "cam_hw_cdm_deinit",
          2207,
          "Failed to Write CDM HW IRQ mask");
    }
    v4 = *(unsigned int ***)(v1 + 232);
    if ( *v4[9] < 4 )
      goto LABEL_59;
    if ( *(_DWORD *)(v1 + 4324) )
    {
      v3 |= 0x40u;
      if ( cam_cdm_write_hw_reg(a1, *v4[8], 0x70003u) )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          1,
          1,
          "cam_hw_cdm_deinit",
          2207,
          "Failed to Write CDM HW IRQ mask");
    }
    v4 = *(unsigned int ***)(v1 + 232);
    if ( *v4[9] <= 4 )
    {
LABEL_59:
      if ( cam_cdm_write_hw_reg(a1, (*v4)[4], v3) )
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          1,
          1,
          "cam_hw_cdm_deinit",
          2213,
          "Failed to Write CDM HW reset");
      if ( (debug_mdl & 1) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          4,
          "cam_hw_cdm_deinit",
          2217,
          "Waiting for %s%u HW reset done",
          *(const char **)(a1 + 152),
          *(_DWORD *)(a1 + 116));
      if ( cam_common_wait_for_completion_timeout(v1 + 144) <= 0 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          1,
          1,
          "cam_hw_cdm_deinit",
          2225,
          "%s%u HW reset Wait failed rc=%d",
          *(const char **)(a1 + 152),
          *(_DWORD *)(a1 + 116),
          -110);
      _X8 = (unsigned __int64 *)(v1 + 4856);
      __asm { PRFM            #0x11, [X8] }
      do
        v20 = __ldxr(_X8);
      while ( __stxr(v20 & 0xFFFFFFFFFFFFFFEFLL, _X8) );
      if ( !**(_DWORD **)(*(_QWORD *)(v1 + 232) + 72LL) )
        break;
      mutex_unlock(v1 + 2352);
      if ( **(_DWORD **)(*(_QWORD *)(v1 + 232) + 72LL) < 2u )
        break;
      mutex_unlock(v1 + 2992);
      if ( **(_DWORD **)(*(_QWORD *)(v1 + 232) + 72LL) < 3u )
        break;
      mutex_unlock(v1 + 3632);
      if ( **(_DWORD **)(*(_QWORD *)(v1 + 232) + 72LL) < 4u )
        break;
      mutex_unlock(v1 + 4272);
      if ( **(_DWORD **)(*(_QWORD *)(v1 + 232) + 72LL) <= 4u )
        break;
    }
LABEL_51:
    __break(0x5512u);
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    v6 = 0;
  else
    v6 = raw_spin_lock_irqsave(a1 + 48);
  *(_DWORD *)(a1 + 92) = 0;
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 )
    raw_spin_unlock_irqrestore(a1 + 48, v6);
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64))cam_soc_util_disable_platform_resource)(
             a1 + 96,
             0xFFFFFFFFLL,
             1,
             1);
  if ( (_DWORD)result )
  {
    v8 = *(const char **)(a1 + 152);
    v9 = *(_DWORD *)(a1 + 116);
    v10 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_deinit",
      2238,
      "disable platform failed for %s%u",
      v8,
      v9);
    return v10;
  }
  else if ( (debug_mdl & 1) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_hw_cdm_deinit",
      2241,
      "%s%u Deinit success",
      *(const char **)(a1 + 152),
      *(_DWORD *)(a1 + 116));
    return 0;
  }
  return result;
}
