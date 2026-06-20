__int64 __fastcall wsa883x_codec_version_read(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 v6; // x9
  int v7; // w9
  const char *v8; // x9
  __int64 v9; // x10
  __int64 v10; // x9
  __int64 v11; // x9
  __int64 result; // x0
  __int64 v13; // [xsp+0h] [xbp-30h] BYREF
  _QWORD v14[5]; // [xsp+8h] [xbp-28h] BYREF

  v14[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 64);
  v13 = a6;
  memset(v14, 0, 32);
  if ( !v6 )
  {
    printk(&unk_ACB6, "wsa883x_codec_version_read");
    result = -22;
    goto LABEL_9;
  }
  v7 = *(_DWORD *)(v6 + 196);
  if ( v7 == 1 )
  {
    v8 = "WSA883X_1_1\n";
  }
  else
  {
    if ( v7 )
    {
      strcpy((char *)v14, "VER_UNDEFINED\n");
      v11 = 14;
      goto LABEL_8;
    }
    v8 = "WSA883X_1_0\n";
  }
  v9 = *(_QWORD *)v8;
  v10 = *(_QWORD *)(v8 + 5);
  v14[0] = v9;
  *(_QWORD *)((char *)v14 + 5) = v10;
  v11 = 12;
LABEL_8:
  result = simple_read_from_buffer(a4, a5, &v13, v14, v11);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
