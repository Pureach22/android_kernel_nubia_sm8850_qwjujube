__int64 __fastcall set_dspp_ad_backlight_feature(__int64 a1)
{
  __int64 v1; // x9
  void (*v2)(void); // x8
  __int64 result; // x0
  __int64 v4; // x0

  _ReadStatusReg(SP_EL0);
  if ( !a1 )
  {
    result = 4294967274LL;
LABEL_11:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v1 = *(unsigned int *)(a1 + 28);
  if ( (unsigned int)v1 < 3 )
  {
    v2 = *(void (**)(void))(a1 + 8 * v1 + 520);
    if ( v2 )
    {
      if ( *((_DWORD *)v2 - 1) != 1841204718 )
        __break(0x8228u);
      v2();
      result = 0;
    }
    else if ( (_DWORD)v1 == 1 )
    {
      result = 0;
    }
    else
    {
      result = 4294967274LL;
    }
    goto LABEL_11;
  }
  __break(0x5512u);
  v4 = MEMORY[0x25254BC]();
  return set_dspp_ad_strength_feature(v4);
}
