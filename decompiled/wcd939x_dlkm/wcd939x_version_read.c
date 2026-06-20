__int64 __fastcall wcd939x_version_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x9
  unsigned int v7; // w9
  const char *v8; // x9
  __int64 result; // x0
  __int64 v10; // x10
  __int64 v11; // x9
  __int64 v12; // x9
  __int64 v13; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v14[5]; // [xsp+8h] [xbp-28h] BYREF

  v14[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 64);
  v13 = a6;
  memset(v14, 0, 32);
  if ( v6 )
  {
    v7 = *(_DWORD *)(v6 + 3176);
    if ( v7 >= 2 )
    {
      if ( v7 != 2 )
      {
        strcpy((char *)v14, "VER_UNDEFINED\n");
        v12 = 14;
LABEL_11:
        result = simple_read_from_buffer(a4, a5, &v13, v14, v12);
        goto LABEL_12;
      }
      v8 = "WCD939X_2_0\n";
    }
    else
    {
      v8 = "WCD939X_1_0\n";
    }
    v10 = *(_QWORD *)v8;
    v11 = *(_QWORD *)(v8 + 5);
    v14[0] = v10;
    *(_QWORD *)((char *)v14 + 5) = v11;
    v12 = 12;
    goto LABEL_11;
  }
  if ( (unsigned int)__ratelimit(&wcd939x_version_read__rs, "wcd939x_version_read") )
    printk(&unk_1A4C7, "wcd939x_version_read");
  result = -22;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
