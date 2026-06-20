__int64 __fastcall temperature_threshold_store(__int64 a1, int a2, char *s, __int64 a4)
{
  _QWORD *v6; // x20
  int v7; // w22
  int v8; // w22
  int v9; // w22
  int v10; // w22
  int v11; // w22
  int v12; // w22
  __int64 result; // x0
  __int64 v14; // [xsp+0h] [xbp-30h] BYREF
  _DWORD v15[6]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v16; // [xsp+20h] [xbp-10h]
  __int64 v17; // [xsp+28h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD **)(a1 + 152);
  v14 = 0;
  if ( sscanf(s, "%d %n", &v14, (char *)&v14 + 4) != 1 )
    goto LABEL_12;
  v7 = HIDWORD(v14);
  v15[0] = v14;
  if ( sscanf(&s[SHIDWORD(v14)], "%d %n", &v14, (char *)&v14 + 4) != 1 )
    goto LABEL_12;
  v8 = HIDWORD(v14) + v7;
  v15[1] = v14;
  if ( sscanf(&s[v8], "%d %n", &v14, (char *)&v14 + 4) != 1 )
    goto LABEL_12;
  v9 = HIDWORD(v14) + v8;
  v15[2] = v14;
  if ( sscanf(&s[v9], "%d %n", &v14, (char *)&v14 + 4) != 1 )
    goto LABEL_12;
  v10 = HIDWORD(v14) + v9;
  v15[3] = v14;
  if ( sscanf(&s[v10], "%d %n", &v14, (char *)&v14 + 4) == 1
    && (v11 = HIDWORD(v14) + v10, v15[4] = v14, sscanf(&s[v11], "%d %n", &v14, (char *)&v14 + 4) == 1)
    && (v12 = HIDWORD(v14) + v11, v15[5] = v14, sscanf(&s[v12], "%d %n", &v14, (char *)&v14 + 4) == 1)
    && (v16 = (unsigned int)v14, sscanf(&s[HIDWORD(v14) + v12], "%d %n", &v14, (char *)&v14 + 4) == 1) )
  {
    HIDWORD(v16) = v14;
    LODWORD(result) = btl_set_temp_thresholds(v6, v15);
    if ( (int)result >= 0 )
      result = a4;
    else
      result = (int)result;
  }
  else
  {
LABEL_12:
    dev_err(*v6, "Failed to read temperature threshold list\n");
    result = -22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
