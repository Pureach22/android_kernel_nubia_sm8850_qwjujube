__int64 __fastcall hdd_to_csr_wmm_mode(char a1)
{
  if ( a1 == 1 )
    return 1;
  else
    return 2 * (unsigned int)(a1 == 2);
}
