__int64 __fastcall msm_clk_bulk_get_clock(__int64 a1, int a2, const char *a3)
{
  __int64 result; // x0
  unsigned __int64 v7; // x22
  __int64 *v8; // x23
  const char *v9; // x20
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v11; // [xsp+10h] [xbp-20h]
  __int64 v12; // [xsp+18h] [xbp-18h]
  __int64 v13; // [xsp+20h] [xbp-10h]
  __int64 v14; // [xsp+28h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  v13 = 0;
  *(_QWORD *)s = 0;
  v11 = 0;
  snprintf(s, 0x20u, "%s_clk", a3);
  result = 0;
  if ( a1 && a2 >= 1 )
  {
    v7 = 0;
    v8 = (__int64 *)(a1 + 8);
    while ( 1 )
    {
      v9 = (const char *)*(v8 - 1);
      if ( !strcmp(v9, a3) || !strcmp(v9, s) )
        break;
      ++v7;
      v8 += 2;
      if ( v7 >= (unsigned int)a2 )
      {
        result = 0;
        goto LABEL_9;
      }
    }
    result = *v8;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
