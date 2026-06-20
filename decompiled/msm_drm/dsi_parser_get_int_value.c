__int64 __fastcall dsi_parser_get_int_value(__int64 result, unsigned int a2)
{
  __int64 v2; // x19
  __int64 v4; // x21
  __int64 v5; // x8
  const char *v6; // x25
  size_t v7; // x0
  unsigned __int64 v8; // x2
  const char *v9; // x1
  char *v10; // x25
  __int64 v11; // x1
  char *v12; // x0
  char *stringp; // [xsp+8h] [xbp-98h] BYREF
  int v14; // [xsp+14h] [xbp-8Ch] BYREF
  _QWORD v15[17]; // [xsp+18h] [xbp-88h] BYREF

  v15[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(int *)(result + 36) >= 1 )
  {
    v2 = result;
    v4 = 0;
    do
    {
      v5 = *(_QWORD *)(v2 + 24);
      stringp = nullptr;
      memset(v15, 0, 128);
      v6 = *(const char **)(v5 + 8 * v4);
      v14 = 0;
      v7 = strnlen(v6, 0x80u);
      if ( v7 == -1 )
      {
        _fortify_panic(2, -1, 0);
LABEL_18:
        _fortify_panic(7, 128, v8);
      }
      if ( v7 == 128 )
        v8 = 128;
      else
        v8 = v7 + 1;
      if ( v8 >= 0x81 )
        goto LABEL_18;
      v9 = v6;
      v10 = (char *)v15;
      sized_strscpy(v15, v9);
      v11 = a2;
      stringp = (char *)v15;
      if ( !a2 )
      {
        v12 = strsep(&stringp, "x");
        v10 = stringp;
        if ( stringp )
        {
          v11 = 16;
        }
        else
        {
          v11 = 10;
          v10 = v12;
          stringp = v12;
        }
      }
      result = kstrtoint(v10, v11, &v14);
      if ( (_DWORD)result )
        result = drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: error converting %s at %d\n", stringp, v4);
      else
        *(_BYTE *)(*(_QWORD *)(v2 + 16) + v4) = v14;
      ++v4;
    }
    while ( v4 < *(int *)(v2 + 36) );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
