__int64 __fastcall venus_hfi_session_command(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        __int64 a7,
        unsigned int a8,
        __int64 a9)
{
  __int64 v9; // x27
  unsigned int v18; // w19

  v9 = *(_QWORD *)(a1 + 320);
  core_lock(v9);
  v18 = venus_hfi_session_command_locked(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  core_unlock(v9);
  return v18;
}
