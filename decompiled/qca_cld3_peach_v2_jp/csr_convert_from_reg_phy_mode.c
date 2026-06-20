__int64 __fastcall csr_convert_from_reg_phy_mode(int a1)
{
  if ( (unsigned int)(a1 - 1) > 5 )
    return 1024;
  else
    return dword_A17808[a1 - 1];
}
