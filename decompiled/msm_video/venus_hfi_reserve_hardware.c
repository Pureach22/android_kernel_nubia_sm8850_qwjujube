__int64 __fastcall venus_hfi_reserve_hardware(__int64 a1, int a2)
{
  __int64 v3; // x21
  int v4; // w8
  unsigned int v5; // w20
  unsigned int v6; // w19
  int v8; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 320);
  if ( a2 )
    v4 = 1;
  else
    v4 = 2;
  v5 = *(_DWORD *)(a1 + 332);
  v8 = v4;
  core_lock(v3);
  v6 = venus_hfi_session_command_locked(a1, 0x100000Fu, 0, 0, v5, 9, &v8, 4u, (__int64)"venus_hfi_reserve_hardware");
  core_unlock(v3);
  _ReadStatusReg(SP_EL0);
  return v6;
}
