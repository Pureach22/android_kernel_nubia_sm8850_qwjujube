__int64 __fastcall cam_context_add_evt_inject(__int64 a1, __int64 a2)
{
  unsigned int v4; // w7
  __int64 (__fastcall *v5)(__int64, __int64); // x8
  unsigned int v6; // w20

  if ( *(_QWORD *)(a1 + 248) )
  {
    mutex_lock(a1 + 72);
    v4 = *(_DWORD *)(a1 + 240);
    if ( v4 - 2 > 3 )
    {
      v6 = -22;
    }
    else
    {
      v5 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 248) + 192LL * v4 + 176);
      if ( v5 )
      {
        if ( *((_DWORD *)v5 - 1) != 1863972096 )
          __break(0x8228u);
        v6 = v5(a1, a2);
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          2,
          2,
          "cam_context_add_evt_inject",
          831,
          "No evt inject ops in dev %d, state %d",
          *(unsigned int *)(a1 + 60));
        v6 = 0;
      }
    }
    mutex_unlock(a1 + 72);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      1,
      "cam_context_add_evt_inject",
      819,
      "Context is not ready");
    return (unsigned int)-22;
  }
  return v6;
}
