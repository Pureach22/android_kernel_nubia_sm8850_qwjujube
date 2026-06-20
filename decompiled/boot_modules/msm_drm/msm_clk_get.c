unsigned __int64 __fastcall msm_clk_get(__int64 a1, const char *a2)
{
  unsigned __int64 result; // x0
  unsigned __int64 v5; // x21
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v7; // [xsp+10h] [xbp-20h]
  __int64 v8; // [xsp+18h] [xbp-18h]
  __int64 v9; // [xsp+20h] [xbp-10h]
  __int64 v10; // [xsp+28h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  v9 = 0;
  *(_QWORD *)s = 0;
  v7 = 0;
  result = devm_clk_get(a1 + 16, a2);
  if ( result >= 0xFFFFFFFFFFFFF001LL && result != -517 )
  {
    snprintf(s, 0x20u, "%s_clk", a2);
    result = devm_clk_get(a1 + 16, s);
    if ( result <= 0xFFFFFFFFFFFFF000LL )
    {
      v5 = result;
      dev_warn(a1 + 16, "Using legacy clk name binding.  Use \"%s\" instead of \"%s\"\n", a2, s);
      result = v5;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
