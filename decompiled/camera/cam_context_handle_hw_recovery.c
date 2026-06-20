__int64 __fastcall cam_context_handle_hw_recovery(__int64 a1, __int64 a2)
{
  unsigned int v4; // w10
  unsigned int v5; // w6
  __int64 (__fastcall *v6)(__int64, __int64); // x8
  unsigned int v7; // w20

  if ( a1 )
  {
    mutex_lock(a1 + 72);
    v4 = (debug_priority == 0) & ((unsigned int)debug_mdl >> 1);
    if ( *(_DWORD *)(a1 + 240) == 5 )
    {
      if ( v4 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 2,
          4,
          "cam_context_handle_hw_recovery",
          704,
          "try hw recovery for ctx:%d dev:%s",
          *(_DWORD *)(a1 + 32),
          (const char *)a1);
        v5 = *(_DWORD *)(a1 + 240);
      }
      else
      {
        v5 = 5;
      }
      v6 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 248) + 192LL * v5 + 160);
      if ( v6 )
      {
        if ( *((_DWORD *)v6 - 1) != 1863972096 )
          __break(0x8228u);
        v7 = v6(a1, a2);
        goto LABEL_14;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        2,
        2,
        "cam_context_handle_hw_recovery",
        709,
        "no recovery op in state:%d for ctx:%d dev:%s",
        v5,
        *(_DWORD *)(a1 + 32),
        (const char *)a1);
    }
    else if ( v4 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 2,
        4,
        "cam_context_handle_hw_recovery",
        701,
        "skipping recovery for ctx:%d dev:%s in state:%d",
        *(_DWORD *)(a1 + 32),
        (const char *)a1,
        *(_DWORD *)(a1 + 240));
    }
    v7 = 0;
LABEL_14:
    mutex_unlock(a1 + 72);
    return v7;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    2,
    1,
    "cam_context_handle_hw_recovery",
    694,
    "null context");
  return (unsigned int)-22;
}
