__int64 __fastcall cmbchan_mode_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x8
  __int64 v6; // x21
  _BYTE v8[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 96);
  v8[0] = 0;
  v6 = *(_QWORD *)(v5 + 152);
  if ( (unsigned int)kstrtobool(a3, v8) )
  {
    a4 = -22;
  }
  else
  {
    raw_spin_lock(v6 + 24);
    *(_BYTE *)(v6 + 49) = v8[0];
    if ( v6 != -24 )
      raw_spin_unlock(v6 + 24);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
