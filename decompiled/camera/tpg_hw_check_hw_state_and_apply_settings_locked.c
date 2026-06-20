__int64 __fastcall tpg_hw_check_hw_state_and_apply_settings_locked(unsigned int *a1, __int64 a2)
{
  __int64 v3; // x20
  unsigned int v4; // w8
  __int64 v5; // x0

  if ( a2 )
  {
    if ( !*(_DWORD *)(a2 + 8) )
      return tpg_hw_apply_settings_to_hw_locked(a1, a2);
    v3 = a2;
    cam_presil_mode_enabled(a1);
    v4 = a1[2];
    if ( v4 != 3 )
    {
LABEL_6:
      a2 = v3;
      if ( v4 == 2 )
      {
        a1[62] = 1;
        v5 = raw_spin_lock_irqsave(a1 + 24);
        a1[2] = 3;
        raw_spin_unlock_irqrestore(a1 + 24, v5);
        a2 = v3;
        if ( (debug_mdl & 0x200000000LL) != 0 && !debug_priority )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            debug_mdl & 0x200000000LL,
            4,
            "tpg_hw_check_hw_state_and_apply_settings_locked",
            601,
            "HW State ready to busy");
          a2 = v3;
        }
      }
      return tpg_hw_apply_settings_to_hw_locked(a1, a2);
    }
    a1[26] = 0;
    if ( cam_common_wait_for_completion_timeout((__int64)(a1 + 26)) )
    {
      v4 = a1[2];
      goto LABEL_6;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "tpg_hw_check_hw_state_and_apply_settings_locked",
      591,
      "TPG[%d] hw timeout %llu",
      *a1,
      0);
    return 4294967280LL;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "tpg_hw_check_hw_state_and_apply_settings_locked",
      570,
      "Invalid param");
    return 4294967274LL;
  }
}
