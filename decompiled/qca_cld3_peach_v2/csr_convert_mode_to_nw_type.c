__int64 __fastcall csr_convert_mode_to_nw_type(int a1, int a2)
{
  if ( (unsigned int)(a1 - 1) >= 3 )
    return 2 * (unsigned int)(a2 == 0);
  else
    return (unsigned int)(a1 - 1);
}
