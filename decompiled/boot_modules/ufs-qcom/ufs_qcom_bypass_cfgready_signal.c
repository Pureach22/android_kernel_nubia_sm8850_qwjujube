__int64 __fastcall ufs_qcom_bypass_cfgready_signal(__int64 a1)
{
  __int64 result; // x0
  _QWORD v3[2]; // [xsp+0h] [xbp-10h] BYREF

  v3[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = 0;
  result = ufshcd_dme_get_attr(a1, 2415919104LL, (char *)v3 + 4, 0);
  if ( !(_DWORD)result )
  {
    result = ufshcd_dme_set_attr(a1, 2415919104LL, 0, HIDWORD(v3[0]) | 0x800000u, 0);
    if ( !(_DWORD)result )
    {
      result = ufshcd_dme_get_attr(a1, 2416246784LL, v3, 0);
      if ( !(_DWORD)result )
      {
        LODWORD(v3[0]) = v3[0] & 0xFBFFFF1F | 0x80;
        result = ufshcd_dme_set_attr(a1, 2416246784LL, 0, LODWORD(v3[0]), 0);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
