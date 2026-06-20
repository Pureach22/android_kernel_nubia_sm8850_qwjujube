__int64 __fastcall user_input_param_save(__int64 a1, char *string)
{
  size_t v4; // x0
  unsigned __int64 v5; // x2
  __int64 v6; // x23
  char *v7; // x0
  const char *v8; // x22
  unsigned int v9; // w0
  bool v10; // zf
  __int64 result; // x0
  __int64 v12; // x8
  unsigned int v13; // w19
  _BYTE v14[4]; // [xsp+Ch] [xbp-114h] BYREF
  char *stringp; // [xsp+10h] [xbp-110h] BYREF
  _QWORD v16[33]; // [xsp+18h] [xbp-108h] BYREF

  v16[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v16, 0, 256);
  v14[0] = 0;
  v4 = strnlen(string, 0x100u);
  if ( v4 == -1 )
  {
    _fortify_panic(2, -1, 0);
    goto LABEL_19;
  }
  if ( v4 == 256 )
    v5 = 256;
  else
    v5 = v4 + 1;
  if ( v5 >= 0x101 )
LABEL_19:
    _fortify_panic(7, 256, v5);
  sized_strscpy(v16, string);
  v6 = 0;
  stringp = (char *)strim(v16);
  while ( 1 )
  {
    v7 = strsep(&stringp, ",");
    if ( !v7 )
      break;
    v8 = v7;
    v9 = kstrtou8(v7, 16, v14);
    if ( v9 )
    {
      v12 = *(_QWORD *)(a1 + 16);
      v13 = v9;
      dev_err(v12, "kstrtou8 failed for value '%s'\n", v8);
      result = v13;
      goto LABEL_15;
    }
    v10 = v6 == 11;
    *(_BYTE *)(*(_QWORD *)(a1 + 96) + v6++) = v14[0];
    if ( v10 )
    {
      result = 12;
LABEL_14:
      *(_DWORD *)(a1 + 104) = result;
      goto LABEL_15;
    }
  }
  if ( (v6 & 1) == 0 )
  {
    result = (unsigned int)v6;
    goto LABEL_14;
  }
  dev_err(*(_QWORD *)(a1 + 16), "invalid user_param_override_seq_cnt %s\n", string);
  result = 4294967274LL;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
