__int64 __fastcall dsi_parser_read_u32(__int64 a1, char *s2, _DWORD *a3)
{
  __int64 v4; // x21
  const char **v5; // x22
  const char *v7; // x21
  size_t v8; // x0
  unsigned __int64 v9; // x2
  char *v10; // x0
  char *v11; // x8
  unsigned int v12; // w21
  __int64 result; // x0
  int v14; // w0
  unsigned int v15; // w20
  int v16; // w0
  char *v17; // x1
  char *v18; // [xsp+0h] [xbp-90h] BYREF
  _QWORD v19[17]; // [xsp+8h] [xbp-88h] BYREF

  v19[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned int *)(a1 + 24);
  v18 = nullptr;
  memset(v19, 0, 128);
  if ( (int)v4 < 1 )
    goto LABEL_15;
  v5 = *(const char ***)(a1 + 16);
  while ( !*v5 || strcmp(*v5, s2) )
  {
    --v4;
    v5 += 5;
    if ( !v4 )
      goto LABEL_15;
  }
  if ( !v5 )
  {
LABEL_15:
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s not found\n", s2);
    result = 4294967274LL;
LABEL_16:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v7 = v5[2];
  if ( !v7 )
  {
LABEL_21:
    result = 0;
    goto LABEL_16;
  }
  v8 = strnlen(v5[2], 0x80u);
  if ( v8 == -1 )
  {
    _fortify_panic(2, -1, 0);
  }
  else
  {
    if ( v8 == 128 )
      v9 = 128;
    else
      v9 = v8 + 1;
    if ( v9 < 0x81 )
    {
      sized_strscpy(v19, v7);
      v18 = (char *)v19;
      v10 = strsep(&v18, "x");
      v11 = v18;
      if ( v18 )
      {
        v12 = 16;
      }
      else
      {
        v12 = 10;
        v11 = v10;
        v18 = v10;
      }
      v14 = kstrtoint(v11, v12, a3);
      if ( v14 )
      {
        v15 = v14;
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: prop=%s error(%d) converting %s, base=%d\n",
          s2,
          v14,
          v18,
          v12);
        result = v15;
        goto LABEL_16;
      }
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s=%d\n", s2, *a3);
      goto LABEL_21;
    }
  }
  v16 = _fortify_panic(7, 128, v9);
  return dsi_parser_read_u32_index(v16, v17);
}
