__int64 __fastcall cali_time_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x8
  __int64 v6; // x22
  int v7; // w0
  __int64 *v9; // x8
  int v10; // w21
  __int64 v11; // x1
  __int64 *v12; // x8
  __int64 v13; // x1
  unsigned int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v14 = 0;
  v6 = *(_QWORD *)(v5 + 96);
  v7 = kstrtoint(a3, 0, &v14);
  if ( v7 < 0 )
  {
    v9 = *(__int64 **)(v6 + 112);
    v10 = v7;
    v11 = v9[14];
    if ( !v11 )
      v11 = *v9;
    printk(&unk_24012, v11, "cali_time_store");
    a4 = v10;
  }
  else if ( v14 <= 0x18F )
  {
    v12 = *(__int64 **)(v6 + 112);
    v13 = v12[14];
    if ( !v13 )
      v13 = *v12;
    printk(&unk_25DB0, v13, "cali_time_store");
    a4 = -22;
  }
  else
  {
    g_cali_re_time = v14;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
