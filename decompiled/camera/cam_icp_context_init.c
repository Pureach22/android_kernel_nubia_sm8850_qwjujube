__int64 __fastcall cam_icp_context_init(__int64 *a1, __int64 a2, int a3, int a4, const char *a5)
{
  const char *v5; // x6
  __int64 result; // x0
  unsigned int v9; // w20
  const char *v10; // x8
  const char *v11; // x7

  if ( a1 )
  {
    v5 = "Non-NULL";
    if ( a5 && a2 && *a1 )
    {
      result = cam_context_init(*a1, a5, 256, a3, 0, a2, (__int64)(a1 + 2), 40, a4);
      if ( (_DWORD)result )
      {
        v9 = result;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_context_init",
          556,
          "[%s] Camera Context Base init failed",
          a5);
        return v9;
      }
      else
      {
        *(_QWORD *)(*a1 + 248) = &cam_icp_ctx_state_machine;
        *(_QWORD *)(*a1 + 256) = a1;
        *(_DWORD *)(*a1 + 468) = 20;
        *(_DWORD *)(*a1 + 472) = 20;
        *(_DWORD *)(*a1 + 476) = 20;
        a1[723] = 0;
      }
      return result;
    }
  }
  else
  {
    v5 = "NULL";
  }
  v10 = "Non-NULL";
  if ( a2 )
    v11 = "Non-NULL";
  else
    v11 = "NULL";
  if ( !a5 )
    v10 = "NULL";
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_context_init",
    548,
    "Invalid params: ctx: %s hw intf: %s dev name: %s",
    v5,
    v11,
    v10);
  return 4294967274LL;
}
