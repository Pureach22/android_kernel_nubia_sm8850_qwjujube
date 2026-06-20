__int64 __fastcall venus_hfi_session_set_secure_mode(__int64 a1)
{
  __int64 v1; // x19
  __int64 v2; // x21
  unsigned int v3; // w20
  int v5; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+18h] [xbp-8h]

  v1 = a1;
  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a1 + 332);
  v2 = *(_QWORD *)(a1 + 320);
  v5 = *(_QWORD *)(a1 + 21824);
  core_lock(v2);
  LODWORD(v1) = venus_hfi_session_command_locked(
                  v1,
                  0x3000102u,
                  0,
                  0,
                  v3,
                  1,
                  &v5,
                  4u,
                  (__int64)"venus_hfi_session_set_secure_mode");
  core_unlock(v2);
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v1;
}
