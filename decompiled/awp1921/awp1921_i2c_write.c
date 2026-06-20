__int64 __fastcall awp1921_i2c_write(__int64 *a1, unsigned __int8 a2, __int16 a3)
{
  unsigned __int64 v3; // x25
  int v5; // w22
  __int64 v6; // x24
  __int16 v7; // w8
  size_t v8; // x28
  size_t v9; // x0
  size_t v10; // x2
  char *v11; // x0
  __int64 v12; // x28
  size_t v13; // x2
  char *v14; // x0
  __int64 v15; // x28
  size_t v16; // x2
  char *v17; // x0
  __int64 v18; // x28
  __int64 result; // x0
  _QWORD v20[2]; // [xsp+8h] [xbp-438h] BYREF
  unsigned __int8 v21; // [xsp+1Ch] [xbp-424h] BYREF
  unsigned __int8 v22; // [xsp+1Dh] [xbp-423h]
  unsigned __int8 v23; // [xsp+1Eh] [xbp-422h]
  char string[8]; // [xsp+20h] [xbp-420h] BYREF
  __int16 v25; // [xsp+28h] [xbp-418h]
  char s[1024]; // [xsp+30h] [xbp-410h] BYREF
  __int64 v27; // [xsp+430h] [xbp-10h]

  v5 = 5;
  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = HIBYTE(a3);
  v21 = a2;
  v23 = a3;
  while ( 1 )
  {
    v6 = *a1;
    v20[0] = 0;
    v7 = *(_WORD *)(v6 + 2);
    WORD2(v20[0]) = 3;
    v20[1] = &v21;
    LOWORD(v20[0]) = v7;
    memset(s, 0, sizeof(s));
    v25 = 0;
    *(_QWORD *)string = 0;
    sprintf(string, "%02X ", v21);
    v8 = strnlen(s, 0x400u);
    if ( v8 >= 0x401 )
    {
LABEL_44:
      v9 = _fortify_panic(2, 1024, v8 + 1);
LABEL_45:
      _fortify_panic(2, 10, v9 + 1);
LABEL_46:
      _fortify_panic(4, 10, 11);
LABEL_47:
      _fortify_panic(11, 1024, v3 + 1);
    }
    v9 = strnlen(string, 0xAu);
    if ( v9 >= 0xB )
      goto LABEL_45;
    if ( v9 == 10 )
      goto LABEL_46;
    v3 = v9 + v8;
    if ( v8 != 1024 )
    {
      if ( v3 >= 0x400 )
        v10 = 1023 - v8;
      else
        v10 = v9;
      v11 = &s[v8];
      if ( v3 >= 0x400 )
        v12 = 1023;
      else
        v12 = v3;
      memcpy(v11, string, v10);
      s[v12] = 0;
    }
    if ( v3 >= 0x400 )
      goto LABEL_47;
    sprintf(string, "%02X ", v22);
    v8 = strnlen(s, 0x400u);
    if ( v8 > 0x400 )
      goto LABEL_44;
    v9 = strnlen(string, 0xAu);
    if ( v9 > 0xA )
      goto LABEL_45;
    if ( v9 == 10 )
      goto LABEL_46;
    v3 = v9 + v8;
    if ( v8 != 1024 )
    {
      if ( v3 >= 0x400 )
        v13 = 1023 - v8;
      else
        v13 = v9;
      v14 = &s[v8];
      if ( v3 >= 0x400 )
        v15 = 1023;
      else
        v15 = v3;
      memcpy(v14, string, v13);
      s[v15] = 0;
    }
    if ( v3 > 0x3FF )
      goto LABEL_47;
    sprintf(string, "%02X ", v23);
    v8 = strnlen(s, 0x400u);
    if ( v8 > 0x400 )
      goto LABEL_44;
    v9 = strnlen(string, 0xAu);
    if ( v9 > 0xA )
      goto LABEL_45;
    if ( v9 == 10 )
      goto LABEL_46;
    v3 = v9 + v8;
    if ( v8 != 1024 )
    {
      if ( v3 >= 0x400 )
        v16 = 1023 - v8;
      else
        v16 = v9;
      v17 = &s[v8];
      if ( v3 >= 0x400 )
        v18 = 1023;
      else
        v18 = v3;
      memcpy(v17, string, v16);
      s[v18] = 0;
    }
    if ( v3 > 0x3FF )
      goto LABEL_47;
    printk(&unk_81F8, "dump_data", 56);
    result = i2c_transfer(*(_QWORD *)(v6 + 24), v20, 1);
    if ( (_DWORD)result == 1 )
      break;
    printk(&unk_7FC8, "awp1921_i2c_write", 94);
    usleep_range_state(2000, 3000, 2);
    if ( --v5 == -1 )
      goto LABEL_43;
  }
  if ( (v5 & 0x80) != 0 )
LABEL_43:
    result = printk(&unk_82FA, "awp1921_i2c_write", 102);
  _ReadStatusReg(SP_EL0);
  return result;
}
