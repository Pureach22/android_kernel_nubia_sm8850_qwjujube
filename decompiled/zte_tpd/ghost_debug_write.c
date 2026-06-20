size_t __fastcall ghost_debug_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x21
  size_t v4; // x19
  __int64 v6; // x1
  __int64 v7; // x2
  char *v8; // x0
  unsigned int v9; // w22
  int v10; // w11
  int v11; // w10
  int v12; // w9
  int v13; // w8
  char v14; // w12
  char v15; // w13
  char v16; // w14
  char v17; // w15
  char v18; // w16
  int v20; // [xsp+Ch] [xbp-A4h] BYREF
  char *stringp; // [xsp+10h] [xbp-A0h] BYREF
  __int64 v22; // [xsp+18h] [xbp-98h]
  __int64 v23; // [xsp+20h] [xbp-90h]
  __int64 v24; // [xsp+28h] [xbp-88h]
  __int64 v25; // [xsp+30h] [xbp-80h]
  __int64 v26; // [xsp+38h] [xbp-78h]
  _QWORD v27[12]; // [xsp+40h] [xbp-70h] BYREF
  int v28; // [xsp+A0h] [xbp-10h]
  __int64 v29; // [xsp+A8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = tpd_cdev;
  v28 = 0;
  if ( a3 >= 0x64 )
    v4 = 100;
  else
    v4 = a3;
  memset(v27, 0, sizeof(v27));
  v20 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v22 = 0;
  if ( a2 && (_check_object_size(v27, v4, 0), inline_copy_from_user((__int64)v27, a2, v4)) )
  {
    printk(&unk_31DF8, v6, v7);
    v4 = -22;
  }
  else
  {
    stringp = (char *)v27;
    v8 = strsep(&stringp, ",");
    if ( v8 )
    {
      v9 = 0;
      do
      {
        if ( !(unsigned int)kstrtouint(v8, 10, &v20) )
          *((_WORD *)&v22 + v9++) = v20;
        v8 = strsep(&stringp, ",");
      }
      while ( v8 && v9 < 0xA );
      v10 = WORD1(v23);
      v11 = WORD2(v23);
      v12 = HIWORD(v23);
      v13 = (unsigned __int16)v24;
      v14 = v23;
      v15 = BYTE6(v22);
      v16 = BYTE4(v22);
      v17 = BYTE2(v22);
      v18 = v22;
    }
    else
    {
      v13 = 0;
      v12 = 0;
      v11 = 0;
      v10 = 0;
      v14 = 0;
      v15 = 0;
      v16 = 0;
      v17 = 0;
      v18 = 0;
    }
    *(_BYTE *)(v3 + 1169) = v18;
    *(_BYTE *)(v3 + 1170) = v17;
    *(_BYTE *)(v3 + 1171) = v16;
    *(_BYTE *)(v3 + 1172) = v15;
    *(_BYTE *)(v3 + 1173) = v14;
    *(_DWORD *)(v3 + 1176) = v10;
    *(_DWORD *)(v3 + 1180) = v11;
    *(_DWORD *)(v3 + 1184) = v12;
    *(_DWORD *)(v3 + 1188) = v13;
  }
  _ReadStatusReg(SP_EL0);
  return v4;
}
