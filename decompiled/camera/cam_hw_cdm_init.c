__int64 __fastcall cam_hw_cdm_init(__int64 a1)
{
  __int64 v2; // x21
  unsigned int v3; // w0
  const char *v4; // x6
  int v5; // w7
  unsigned int v6; // w19
  __int64 result; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v9; // x1
  __int64 v10; // x8
  __int64 v11; // x1
  unsigned __int64 v18; // x10
  unsigned __int64 v21; // x10
  unsigned __int64 v24; // x10
  unsigned __int64 v27; // x10
  unsigned __int64 v30; // x10

  if ( !a1 )
    return 4294967274LL;
  v2 = *(_QWORD *)(a1 + 3680);
  v3 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64))cam_soc_util_enable_platform_resource)(
         a1 + 96,
         0xFFFFFFFFLL,
         1,
         *(unsigned int *)(a1 + 2968),
         1);
  if ( v3 )
  {
    v4 = *(const char **)(a1 + 152);
    v5 = *(_DWORD *)(a1 + 116);
    v6 = v3;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      1,
      1,
      "cam_hw_cdm_init",
      2065,
      "Enable platform failed for %s%d",
      v4,
      v5);
    return v6;
  }
  else
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      v9 = 0;
    else
      v9 = raw_spin_lock_irqsave(a1 + 48);
    *(_DWORD *)(a1 + 92) = 1;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 )
      raw_spin_unlock_irqrestore(a1 + 48, v9);
    if ( (debug_mdl & 1) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        4,
        "cam_hw_cdm_init",
        2073,
        "Enable soc done for %s%d",
        *(const char **)(a1 + 152),
        *(_DWORD *)(a1 + 116));
    while ( 1 )
    {
      _X8 = (unsigned __int64 *)(v2 + 4856);
      __asm { PRFM            #0x11, [X8] }
      do
        v18 = __ldxr(_X8);
      while ( __stxr(v18 & 0xFFFFFFFFFFFFFFDFLL, _X8) );
      _X8 = (unsigned __int64 *)(v2 + 4856);
      __asm { PRFM            #0x11, [X8] }
      do
        v21 = __ldxr(_X8);
      while ( __stxr(v21 & 0xFFFFFFFFFFFFFFFELL, _X8) );
      *(_DWORD *)(v2 + 2296) = 0;
      _X8 = (unsigned __int64 *)(v2 + 4856);
      __asm { PRFM            #0x11, [X8] }
      do
        v24 = __ldxr(_X8);
      while ( __stxr(v24 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
      *(_DWORD *)(v2 + 2936) = 0;
      _X8 = (unsigned __int64 *)(v2 + 4856);
      __asm { PRFM            #0x11, [X8] }
      do
        v27 = __ldxr(_X8);
      while ( __stxr(v27 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
      *(_DWORD *)(v2 + 3576) = 0;
      _X8 = (unsigned __int64 *)(v2 + 4856);
      __asm { PRFM            #0x11, [X8] }
      do
        v30 = __ldxr(_X8);
      while ( __stxr(v30 & 0xFFFFFFFFFFFFFFF7LL, _X8) );
      v10 = *(_QWORD *)(v2 + 232);
      *(_DWORD *)(v2 + 4216) = 0;
      if ( !**(_DWORD **)(v10 + 72) )
        break;
      *(_BYTE *)(v2 + 2408) = -1;
      *(_DWORD *)(v2 + 2412) = 0;
      if ( **(_DWORD **)(v10 + 72) <= 1u )
        break;
      *(_BYTE *)(v2 + 3048) = -1;
      *(_DWORD *)(v2 + 3052) = 0;
      if ( **(_DWORD **)(v10 + 72) < 3u )
        break;
      *(_BYTE *)(v2 + 3688) = -1;
      *(_DWORD *)(v2 + 3692) = 0;
      if ( **(_DWORD **)(v10 + 72) < 4u )
        break;
      *(_BYTE *)(v2 + 4328) = -1;
      *(_DWORD *)(v2 + 4332) = 0;
      if ( **(_DWORD **)(v10 + 72) <= 4u )
        break;
      __break(0x5512u);
    }
    result = cam_hw_cdm_reset_hw(a1, 0);
    if ( (_DWORD)result )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        1,
        "cam_hw_cdm_init",
        2091,
        "%s%u HW reset Wait failed rc=%d",
        *(const char **)(a1 + 152),
        *(_DWORD *)(a1 + 116),
        result);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        v11 = 0;
      else
        v11 = raw_spin_lock_irqsave(a1 + 48);
      *(_DWORD *)(a1 + 92) = 0;
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 )
        raw_spin_unlock_irqrestore(a1 + 48, v11);
      ((void (__fastcall *)(__int64, __int64, __int64, __int64))cam_soc_util_disable_platform_resource)(
        a1 + 96,
        0xFFFFFFFFLL,
        1,
        1);
      return 4294967291LL;
    }
    else if ( (debug_mdl & 1) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        4,
        "cam_hw_cdm_init",
        2095,
        "%s%u Init success",
        *(const char **)(a1 + 152),
        *(_DWORD *)(a1 + 116));
      return 0;
    }
  }
  return result;
}
