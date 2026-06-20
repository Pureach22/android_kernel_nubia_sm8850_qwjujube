__int64 __fastcall reg_is_country_code_valid(unsigned __int8 *a1)
{
  unsigned __int16 v2; // w9
  __int16 *v3; // x13
  __int16 *v4; // x13
  int v5; // t1
  __int64 result; // x0
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  reg_get_num_countries(&v7);
  if ( v7 < 1 )
  {
LABEL_7:
    result = 16;
  }
  else
  {
    v2 = 0;
    while ( 1 )
    {
      v3 = &g_all_countries_0[7 * v2];
      v5 = *((unsigned __int8 *)v3 + 4);
      v4 = v3 + 2;
      if ( v5 == *a1 && *((unsigned __int8 *)v4 + 1) == a1[1] )
        break;
      if ( v7 <= (unsigned int)++v2 )
        goto LABEL_7;
    }
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
