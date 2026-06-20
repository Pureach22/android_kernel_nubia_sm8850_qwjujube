__int64 __fastcall _dump(__int64 result, int a2)
{
  const char **v2; // x19
  __int64 v3; // x28
  const char *v4; // x23
  const char *v5; // x27
  _QWORD v6[16]; // [xsp+0h] [xbp-110h] BYREF
  char s[8]; // [xsp+80h] [xbp-90h] BYREF
  __int64 v8; // [xsp+88h] [xbp-88h]
  __int64 v9; // [xsp+90h] [xbp-80h]
  __int64 v10; // [xsp+98h] [xbp-78h]
  __int64 v11; // [xsp+A0h] [xbp-70h]
  __int64 v12; // [xsp+A8h] [xbp-68h]
  __int64 v13; // [xsp+B0h] [xbp-60h]
  __int64 v14; // [xsp+B8h] [xbp-58h]
  __int64 v15; // [xsp+C0h] [xbp-50h]
  __int64 v16; // [xsp+C8h] [xbp-48h]
  __int64 v17; // [xsp+D0h] [xbp-40h]
  __int64 v18; // [xsp+D8h] [xbp-38h]
  __int64 v19; // [xsp+E0h] [xbp-30h]
  __int64 v20; // [xsp+E8h] [xbp-28h]
  __int64 v21; // [xsp+F0h] [xbp-20h]
  __int64 v22; // [xsp+F8h] [xbp-18h]
  __int64 v23; // [xsp+100h] [xbp-10h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 >= 1 )
  {
    v2 = (const char **)result;
    v3 = (unsigned int)a2;
    while ( 1 )
    {
      v4 = v2[2];
      v21 = 0;
      v22 = 0;
      v19 = 0;
      v20 = 0;
      v17 = 0;
      v18 = 0;
      v15 = 0;
      v16 = 0;
      v13 = 0;
      v14 = 0;
      v11 = 0;
      v12 = 0;
      v9 = 0;
      v10 = 0;
      *(_QWORD *)s = 0;
      v8 = 0;
      memset(v6, 0, sizeof(v6));
      if ( v4 == (const char *)3735928559LL )
        break;
      v5 = v2[1];
      if ( strcmp(v5, "%FP") )
      {
        snprintf(s, 0x80u, "    %-35s: %s\n", *v2, v5);
        result = snprintf((char *)v6, 0x80u, s, v2[2]);
LABEL_4:
        if ( (msm_vidc_debug & 0x20) != 0 )
          goto LABEL_10;
        goto LABEL_5;
      }
      result = snprintf(
                 (char *)v6,
                 0x80u,
                 "    %-35s: %zd + %zd/%zd\n",
                 *v2,
                 (unsigned __int64)v4 >> 16,
                 (unsigned __int16)v4,
                 0xFFFFu);
      if ( (msm_vidc_debug & 0x20) != 0 )
LABEL_10:
        result = printk(&unk_917FC, "bus ", 0xFFFFFFFFLL, "codec", v6);
LABEL_5:
      --v3;
      v2 += 3;
      if ( !v3 )
        goto LABEL_11;
    }
    result = snprintf((char *)v6, 0x80u, "%s\n", *v2);
    goto LABEL_4;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
