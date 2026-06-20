__int64 __fastcall sde_hw_sspp_get_source_addr_v1(__int64 result, char a2)
{
  __int64 v3; // x20
  int v4; // w8
  int v5; // w8
  int v6; // w9
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v7 = 0;
    v3 = result;
    v4 = sspp_subblk_offset(result, 1, &v7);
    result = 0;
    if ( !v4 )
    {
      v5 = v7;
      v7 += 4096;
      if ( (a2 & 1) != 0 )
        v6 = 4176;
      else
        v6 = 4172;
      result = sde_reg_read(v3, v5 + v6);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
