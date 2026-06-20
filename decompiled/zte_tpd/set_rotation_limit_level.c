__int64 __fastcall set_rotation_limit_level(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x20
  void (__fastcall *v6)(__int64, __int64); // x8
  __int64 v7; // x1
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v3 = a3;
  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = tpd_cdev;
  v8 = 0;
  if ( (unsigned int)kstrtouint_from_user(a2, a3, 10, &v8) )
  {
    v3 = -22;
  }
  else
  {
    printk(&unk_374F7, "set_rotation_limit_level", v8);
    v6 = *(void (__fastcall **)(__int64, __int64))(v4 + 3272);
    if ( v6 )
    {
      v7 = v8;
      if ( *((_DWORD *)v6 - 1) != 1794684057 )
        __break(0x8228u);
      v6(v4, v7);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
