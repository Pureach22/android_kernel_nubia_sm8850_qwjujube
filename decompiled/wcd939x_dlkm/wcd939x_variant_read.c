__int64 __fastcall wcd939x_variant_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x9
  int v7; // w9
  const char *v8; // x9
  __int64 result; // x0
  __int64 v10; // x9
  __int64 v11; // x9
  __int64 v12; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v13[5]; // [xsp+8h] [xbp-28h] BYREF

  v13[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 64);
  v12 = a6;
  memset(v13, 0, 32);
  if ( v6 )
  {
    v7 = *(_DWORD *)(v6 + 8);
    if ( v7 == 5 )
    {
      v8 = "WCD9395\n";
    }
    else
    {
      if ( v7 )
      {
        strcpy((char *)v13, "VER_UNDEFINED\n");
        v11 = 14;
        goto LABEL_11;
      }
      v8 = "WCD9390\n";
    }
    v10 = *(_QWORD *)v8;
    LOBYTE(v13[1]) = 0;
    v13[0] = v10;
    v11 = 8;
LABEL_11:
    result = simple_read_from_buffer(a4, a5, &v12, v13, v11);
    goto LABEL_12;
  }
  if ( (unsigned int)__ratelimit(&wcd939x_variant_read__rs, "wcd939x_variant_read") )
    printk(&unk_1A4C7, "wcd939x_variant_read");
  result = -22;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
