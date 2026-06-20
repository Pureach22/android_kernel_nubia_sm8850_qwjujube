__int64 __fastcall kgsl_pwrctrl_set_state(__int64 a1, int a2)
{
  __int64 v3; // x21
  __int64 v4; // x20
  bool v5; // w8

  v3 = a1 + 0x2000;
  *(_DWORD *)(a1 + 11120) = a2;
  *(_DWORD *)(a1 + 11124) = 0;
  v4 = a1 + 11080;
  if ( a2 == 128 )
  {
    *(_BYTE *)(a1 + 10952) = 0;
    raw_spin_lock(a1 + 11080);
    v5 = 1;
  }
  else
  {
    raw_spin_lock(a1 + 11080);
    v5 = a2 != 2;
  }
  *(_BYTE *)(v3 + 2892) = v5;
  return raw_spin_unlock(v4);
}
