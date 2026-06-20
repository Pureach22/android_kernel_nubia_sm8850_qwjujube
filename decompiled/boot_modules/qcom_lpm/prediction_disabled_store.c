__int64 __fastcall prediction_disabled_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v5; // w0
  int v7; // w20
  char v8[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8[0] = 0;
  v5 = kstrtobool(a3, v8);
  if ( v5 )
  {
    v7 = v5;
    printk(&unk_CB2C);
    a4 = v7;
  }
  else
  {
    prediction_disabled = v8[0];
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
