__int64 __fastcall out_mode_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v6; // x8
  __int64 v7; // x20
  __int64 result; // x0
  __int64 v9; // [xsp+8h] [xbp-18h] BYREF
  __int16 v10; // [xsp+10h] [xbp-10h]
  __int64 v11; // [xsp+18h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 96);
  v10 = 0;
  v9 = 0;
  v7 = *(_QWORD *)(v6 + 152);
  if ( strlen(s) <= 9 && sscanf(s, "%s", &v9) == 1 )
  {
    LODWORD(result) = tmc_etr_switch_mode(v7, (const char *)&v9);
    if ( (_DWORD)result )
      result = (int)result;
    else
      result = a4;
  }
  else
  {
    result = -22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
