__int64 __fastcall config_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x20
  int v6; // w0
  unsigned int v7; // w9
  int v8; // w8
  __int64 result; // x0
  unsigned int v10; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v11; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v12; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v12 = 0;
  v10 = 0;
  v11 = 0;
  v6 = sscanf(s, "%x %i %d", &v10, &v12, &v11);
  v7 = v6 - 4;
  v8 = v6;
  result = -22;
  if ( v7 >= 0xFFFFFFFD && v11 <= 1 )
  {
    if ( v8 == 1 )
    {
      v12 = 1;
    }
    else if ( v8 == 3 && v11 == 1 )
    {
      v11 = 1;
      goto LABEL_9;
    }
    v11 = 0;
LABEL_9:
    LODWORD(result) = dcc_config_add(v5, v10, v12);
    if ( (_DWORD)result )
      result = (int)result;
    else
      result = a4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
