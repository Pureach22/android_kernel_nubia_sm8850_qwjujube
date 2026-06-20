__int64 __fastcall reg_debug_bypass_enable_get(__int64 a1, _QWORD *a2)
{
  _DWORD *v3; // x20
  _DWORD *v4; // x8
  unsigned int v5; // w21
  bool v7[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD **)(a1 + 32);
  v7[0] = 0;
  ww_mutex_lock(v3 + 38, 0);
  v4 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)v3 + 64LL) + 232LL);
  if ( v4 )
  {
    if ( *(v4 - 1) != -812487039 )
      __break(0x8228u);
    v5 = ((__int64 (__fastcall *)(_DWORD *, bool *))v4)(v3, v7);
    if ( v5 )
      printk(&unk_8119, "reg_debug_bypass_enable_get");
  }
  else
  {
    v5 = 0;
    v7[0] = v3[5] == v3[4];
  }
  ww_mutex_unlock(v3 + 38);
  *a2 = v7[0];
  _ReadStatusReg(SP_EL0);
  return v5;
}
