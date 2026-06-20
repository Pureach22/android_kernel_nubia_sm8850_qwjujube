__int64 __fastcall set_fake_sleep(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x20
  _BOOL8 v6; // x2
  void (__fastcall *v7)(__int64, _BOOL8); // x8
  _BOOL8 v8; // x1
  _BOOL4 v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v3 = a3;
  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = tpd_cdev;
  v9 = 0;
  if ( (unsigned int)kstrtouint_from_user(a2, a3, 10, &v9) )
  {
    v3 = -22;
  }
  else
  {
    v6 = v9;
    v9 = v9;
    printk(&unk_374F7, "set_fake_sleep", v6);
    v7 = *(void (__fastcall **)(__int64, _BOOL8))(v4 + 3608);
    if ( v7 )
    {
      v8 = v9;
      if ( *((_DWORD *)v7 - 1) != 1794684057 )
        __break(0x8228u);
      v7(v4, v8);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
