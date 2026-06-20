__int64 __fastcall dsi_parser_read_u32_index(__int64 a1, char *s2, unsigned int a3, _DWORD *a4)
{
  __int64 v5; // x22
  __int64 v6; // x23
  const char *v9; // x21
  size_t v10; // x0
  unsigned __int64 v11; // x2
  char *v12; // x0
  char *v13; // x8
  unsigned int v14; // w21
  __int64 result; // x0
  int v16; // w0
  unsigned int v17; // w20
  int v18; // w0
  char *v19; // x1
  int v20; // w30
  char *v21; // [xsp+0h] [xbp-90h] BYREF
  _QWORD v22[17]; // [xsp+8h] [xbp-88h] BYREF

  v22[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(unsigned int *)(a1 + 24);
  v21 = nullptr;
  memset(v22, 0, 128);
  if ( (int)v5 < 1 )
    goto LABEL_15;
  v6 = *(_QWORD *)(a1 + 16);
  while ( !*(_QWORD *)v6 || strcmp(*(const char **)v6, s2) )
  {
    --v5;
    v6 += 40;
    if ( !v5 )
      goto LABEL_15;
  }
  if ( !v6 )
  {
LABEL_15:
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s not found\n", s2);
    goto LABEL_16;
  }
  if ( *(_DWORD *)(v6 + 36) <= a3 )
  {
LABEL_16:
    result = 4294967274LL;
LABEL_17:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v9 = *(const char **)(*(_QWORD *)(v6 + 24) + 8LL * a3);
  v10 = strnlen(v9, 0x80u);
  if ( v10 == -1 )
  {
    _fortify_panic(2, -1, 0);
  }
  else
  {
    if ( v10 == 128 )
      v11 = 128;
    else
      v11 = v10 + 1;
    if ( v11 < 0x81 )
    {
      sized_strscpy(v22, v9);
      v21 = (char *)v22;
      v12 = strsep(&v21, "x");
      v13 = v21;
      if ( v21 )
      {
        v14 = 16;
      }
      else
      {
        v14 = 10;
        v13 = v12;
        v21 = v12;
      }
      v16 = kstrtoint(v13, v14, a4);
      if ( v16 )
      {
        v17 = v16;
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: prop=%s error(%d) converting %s, base=%d\n",
          s2,
          v16,
          v21,
          v14);
        result = v17;
      }
      else
      {
        _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s=%d\n", s2, *a4);
        result = 0;
      }
      goto LABEL_17;
    }
  }
  v18 = _fortify_panic(7, 128, v11);
  if ( v20 )
    JUMPOUT(0x1EE6F4);
  return dsi_parser_read_u32_array(v18, v19);
}
