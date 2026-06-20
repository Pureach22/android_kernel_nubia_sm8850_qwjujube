__int64 __fastcall pld_pcie_set_wfc_mode(__int64 a1, unsigned int a2)
{
  if ( a2 > 1 )
    return 4294967274LL;
  else
    return cnss_set_wfc_mode(a1, a2);
}
