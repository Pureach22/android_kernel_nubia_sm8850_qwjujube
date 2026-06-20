__int64 __fastcall enable_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v6; // w0
  int v8; // w21
  _BYTE v9[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  v6 = kstrtobool(a3, v9);
  if ( v6 )
  {
    v8 = v6;
    printk(&unk_7B45, "enable_store");
    a4 = v8;
  }
  else
  {
    *(_BYTE *)(a1 + 144) = v9[0];
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
