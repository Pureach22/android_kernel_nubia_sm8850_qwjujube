__int64 __fastcall wsa883x_variant_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x9
  int v7; // w9
  __int64 v8; // x9
  const char *v9; // x9
  __int64 v10; // x9
  __int64 result; // x0
  __int64 v12; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v13[5]; // [xsp+8h] [xbp-28h] BYREF

  v13[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 64);
  v12 = a6;
  memset(v13, 0, 32);
  if ( !v6 )
  {
    printk(&unk_ACB6, "wsa883x_variant_read");
    result = -22;
    goto LABEL_13;
  }
  v7 = *(_DWORD *)(v6 + 192);
  if ( v7 > 1 )
  {
    if ( v7 == 2 )
    {
      v9 = "WSA8832\n";
      goto LABEL_11;
    }
    if ( v7 != 5 )
      goto LABEL_5;
    goto LABEL_8;
  }
  if ( !v7 )
  {
    v9 = "WSA8830\n";
    goto LABEL_11;
  }
  if ( v7 == 1 )
  {
LABEL_8:
    v9 = "WSA8835\n";
LABEL_11:
    v10 = *(_QWORD *)v9;
    LOBYTE(v13[1]) = 0;
    v13[0] = v10;
    v8 = 8;
    goto LABEL_12;
  }
LABEL_5:
  v8 = 10;
  strcpy((char *)v13, "UNDEFINED\n");
LABEL_12:
  result = simple_read_from_buffer(a4, a5, &v12, v13, v8);
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
