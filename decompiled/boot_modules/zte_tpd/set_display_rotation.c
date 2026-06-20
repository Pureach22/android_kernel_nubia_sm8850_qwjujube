size_t __fastcall set_display_rotation(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v4; // x20
  size_t v5; // x19
  __int64 v7; // x2
  void (__fastcall *v8)(__int64, __int64); // x8
  __int64 v9; // x1
  unsigned int v10; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-18h] BYREF
  __int16 v12; // [xsp+10h] [xbp-10h]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = tpd_cdev;
  v10 = 0;
  if ( a3 >= 9 )
    v5 = 9;
  else
    v5 = a3;
  v12 = 0;
  v11 = 0;
  _check_object_size(&v11, v5, 0);
  if ( (unsigned int)inline_copy_from_user((__int64)&v11, a2, v5) || (unsigned int)kstrtouint(&v11, 0, &v10) )
  {
    v5 = -22;
  }
  else
  {
    v7 = v10;
    *(_DWORD *)(v4 + 16) = v10;
    printk(&unk_31DC4, "set_display_rotation", v7);
    v8 = *(void (__fastcall **)(__int64, __int64))(v4 + 3288);
    if ( v8 )
    {
      v9 = v10;
      if ( *((_DWORD *)v8 - 1) != 1794684057 )
        __break(0x8228u);
      v8(v4, v9);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
