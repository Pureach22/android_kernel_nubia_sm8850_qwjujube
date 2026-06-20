__int64 __fastcall hdd_get_wifi_standard(__int64 *a1, int a2, char a3)
{
  bool v3; // zf
  __int64 v4; // x0
  __int64 result; // x0
  bool v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    if ( (unsigned int)(a2 - 13) >= 2 )
    {
      if ( (unsigned int)(a2 - 11) > 1 )
      {
        result = (a2 & 0xFFFFFFFE) == 8;
        goto LABEL_12;
      }
      v3 = (a3 & 4) == 0;
      goto LABEL_8;
    }
LABEL_6:
    result = 4;
    goto LABEL_12;
  }
  v4 = *a1;
  v7 = 0;
  ucfg_psoc_mlme_get_11be_capab(v4, &v7);
  if ( v7 )
    goto LABEL_6;
  v3 = (a3 & 4) == 0;
LABEL_8:
  if ( v3 )
    result = 2;
  else
    result = 3;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
