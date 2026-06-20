__int64 __fastcall aw9620x_aot_cail_set(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  __int64 v6; // x20
  int v8; // [xsp+0h] [xbp-10h] BYREF
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v8 = 0;
  if ( !(unsigned int)kstrtouint(a3, 0, &v8) )
  {
    if ( v8 == 1 )
    {
      v6 = v5 - 56;
      v9 = 0;
      aw9620x_i2c_read(v6, 0x1A00u, &v9);
      aw9620x_i2c_write(v6, 0x1A00u, v9 | 0xFF00);
    }
    else
    {
      dev_printk(&unk_134C0, *(_QWORD *)(v5 - 8), "[%s:%d] fail to set aot cali\n", "aw9620x_aot_cail_set", 3946);
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
