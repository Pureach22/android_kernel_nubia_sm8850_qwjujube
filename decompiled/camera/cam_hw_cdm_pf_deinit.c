__int64 __fastcall cam_hw_cdm_pf_deinit(__int64 a1)
{
  __int64 v1; // x20
  unsigned __int64 StatusReg; // x20
  __int64 v4; // x1
  __int64 result; // x0
  const char *v6; // x6
  int v7; // w7
  unsigned int v8; // w19

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
            goto LABEL_24;
        }
      }
    }
  }
  ((void (__fastcall *)(__int64))cam_hw_cdm_clear_bl_requests)(v1);
  if ( **(_DWORD **)(*(_QWORD *)(v1 + 232) + 72LL) )
  {
    mutex_unlock(v1 + 2352);
    if ( **(_DWORD **)(*(_QWORD *)(v1 + 232) + 72LL) >= 2u )
    {
      mutex_unlock(v1 + 2992);
      if ( **(_DWORD **)(*(_QWORD *)(v1 + 232) + 72LL) >= 3u )
      {
        mutex_unlock(v1 + 3632);
        if ( **(_DWORD **)(*(_QWORD *)(v1 + 232) + 72LL) >= 4u )
        {
          mutex_unlock(v1 + 4272);
          if ( **(_DWORD **)(*(_QWORD *)(v1 + 232) + 72LL) > 4u )
          {
LABEL_24:
            __break(0x5512u);
            JUMPOUT(0x16E914);
          }
        }
      }
    }
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    v4 = 0;
  else
    v4 = raw_spin_lock_irqsave(a1 + 48);
  *(_DWORD *)(a1 + 92) = 0;
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 )
    raw_spin_unlock_irqrestore(a1 + 48, v4);
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64, __int64))cam_soc_util_disable_platform_resource)(
             a1 + 96,
             0xFFFFFFFFLL,
             1,
             1);
  if ( (_DWORD)result )
  {
    v6 = *(const char **)(a1 + 152);
    v7 = *(_DWORD *)(a1 + 116);
    v8 = result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_pf_deinit",
      2162,
      "disable platform failed for %s%u",
      v6,
      v7);
    return v8;
  }
  else if ( (debug_mdl & 1) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      4,
      "cam_hw_cdm_pf_deinit",
      2165,
      "%s%u Deinit success",
      *(const char **)(a1 + 152),
      *(_DWORD *)(a1 + 116));
    return 0;
  }
  return result;
}
