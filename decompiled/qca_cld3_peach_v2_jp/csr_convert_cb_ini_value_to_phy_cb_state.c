__int64 __fastcall csr_convert_cb_ini_value_to_phy_cb_state(int a1)
{
  if ( (unsigned int)(a1 - 1) > 9 )
    return 0;
  else
    return dword_A174D8[a1 - 1];
}
