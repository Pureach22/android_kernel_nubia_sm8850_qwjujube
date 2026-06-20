__int64 __fastcall dsi_parser_read_u32_array(__int64 a1, char *s2, _DWORD *a3)
{
  __int64 v4; // x21
  __int64 v5; // x28
  __int64 v7; // x21
  __int64 v8; // x8
  const char *v9; // x26
  size_t v10; // x0
  unsigned __int64 v11; // x2
  char *v12; // x0
  char *v13; // x8
  unsigned int v14; // w27
  unsigned int v15; // w26
  int v16; // w6
  char *stringp; // [xsp+8h] [xbp-98h] BYREF
  int v19; // [xsp+14h] [xbp-8Ch] BYREF
  _QWORD v20[17]; // [xsp+18h] [xbp-88h] BYREF

  v20[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned int *)(a1 + 24);
  if ( (int)v4 < 1 )
    goto LABEL_21;
  v5 = *(_QWORD *)(a1 + 16);
  while ( !*(_QWORD *)v5 || strcmp(*(const char **)v5, s2) )
  {
    --v4;
    v5 += 40;
    if ( !v4 )
      goto LABEL_21;
  }
  if ( v5 )
  {
    if ( *(int *)(v5 + 36) >= 1 )
    {
      v7 = 0;
      while ( 1 )
      {
        memset(v20, 0, 128);
        stringp = nullptr;
        v8 = *(_QWORD *)(v5 + 24);
        v19 = 0;
        v9 = *(const char **)(v8 + 8 * v7);
        v10 = strnlen(v9, 0x80u);
        if ( v10 == -1 )
          break;
        if ( v10 == 128 )
          v11 = 128;
        else
          v11 = v10 + 1;
        if ( v11 >= 0x81 )
          goto LABEL_25;
        sized_strscpy(v20, v9);
        stringp = (char *)v20;
        v12 = strsep(&stringp, "x");
        v13 = stringp;
        if ( stringp )
        {
          v14 = 16;
        }
        else
        {
          v14 = 10;
          v13 = v12;
          stringp = v12;
        }
        v15 = kstrtoint(v13, v14, &v19);
        if ( v15 )
        {
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: prop=%s error(%d) converting %s(%d), base=%d\n",
            s2,
            v15,
            stringp,
            v7,
            v14);
        }
        else
        {
          v16 = v19;
          *a3++ = v19;
          _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: [%d]=%d\n", s2, v7, v16);
        }
        if ( ++v7 >= *(int *)(v5 + 36) )
          goto LABEL_22;
      }
      _fortify_panic(2, -1, 0);
LABEL_25:
      _fortify_panic(7, 128, v11);
    }
    v15 = 0;
  }
  else
  {
LABEL_21:
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s not found\n", s2);
    v15 = -22;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return v15;
}
