__int64 __fastcall aw_cali_class_time_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v6; // w0
  int v8; // w21
  unsigned int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v6 = kstrtoint(a3, 0, &v9);
  if ( v6 < 0 )
  {
    v8 = v6;
    printk(&unk_246B7, "aw_cali_class_time_store", a3);
    a4 = v8;
  }
  else if ( v9 <= 0x18F )
  {
    printk(&unk_26CB9, "aw_cali_class_time_store", v9);
    a4 = -22;
  }
  else
  {
    g_cali_re_time = v9;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
