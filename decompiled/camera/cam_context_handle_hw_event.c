__int64 __fastcall cam_context_handle_hw_event(__int64 a1, int a2)
{
  __int64 v2; // x8
  unsigned int v3; // w9
  unsigned int (*v4)(void); // x8
  unsigned int v5; // w8

  if ( a1 && (v2 = *(_QWORD *)(a1 + 248)) != 0 )
  {
    v3 = *(_DWORD *)(a1 + 240);
    v4 = *(unsigned int (**)(void))(v2 + 192LL * v3 + 136);
    if ( v4 )
    {
      if ( *((_DWORD *)v4 - 1) != 414296116 )
        __break(0x8228u);
      return v4();
    }
    else
    {
      v5 = 0;
      if ( (debug_mdl & 2) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 2,
          4,
          "cam_context_handle_hw_event",
          33,
          "No function to handle event %d in dev %d, state %d",
          a2,
          *(_DWORD *)(a1 + 60),
          v3);
        return 0;
      }
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      1,
      "cam_context_handle_hw_event",
      23,
      "Context is not ready");
    return (unsigned int)-22;
  }
  return v5;
}
