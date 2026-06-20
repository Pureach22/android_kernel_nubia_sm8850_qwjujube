__int64 __fastcall pld_pcie_get_ce_id(__int64 a1, int a2)
{
  if ( (unsigned int)(a2 - 100) >= 8 )
    return 4294967274LL;
  else
    return (unsigned int)(a2 - 100);
}
