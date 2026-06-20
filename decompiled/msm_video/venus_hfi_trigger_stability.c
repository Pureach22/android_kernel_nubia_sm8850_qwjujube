__int64 __fastcall venus_hfi_trigger_stability(__int64 a1, int a2, int a3, int a4)
{
  __int64 v4; // x19
  __int64 v5; // x21
  unsigned int v6; // w20
  _DWORD v8[2]; // [xsp+10h] [xbp-10h] BYREF
  __int64 v9; // [xsp+18h] [xbp-8h]

  v4 = a1;
  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 320);
  v6 = *(_DWORD *)(a1 + 332);
  v8[0] = a2 | (16 * a3);
  v8[1] = a4;
  core_lock(v5);
  LODWORD(v4) = venus_hfi_session_command_locked(
                  v4,
                  0x100000Eu,
                  3,
                  0,
                  v6,
                  3,
                  v8,
                  8u,
                  (__int64)"venus_hfi_trigger_stability");
  core_unlock(v5);
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v4;
}
