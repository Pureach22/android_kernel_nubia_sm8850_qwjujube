__int64 __fastcall venus_hfi_session_close(__int64 a1)
{
  __int64 v1; // x21
  __int64 v2; // x19
  unsigned int v3; // w20

  v1 = *(_QWORD *)(a1 + 320);
  v2 = a1;
  v3 = *(_DWORD *)(a1 + 332);
  core_lock(v1);
  LODWORD(v2) = venus_hfi_session_command_locked(
                  v2,
                  0x1000004u,
                  7,
                  0,
                  v3,
                  0,
                  nullptr,
                  0,
                  (__int64)"venus_hfi_session_close");
  core_unlock(v1);
  return (unsigned int)v2;
}
