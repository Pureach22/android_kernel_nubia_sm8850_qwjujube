__int64 __fastcall qdf_status_to_os_return(unsigned int a1)
{
  if ( a1 > 0x19 )
    return 0xFFFFFFFFLL;
  else
    return dword_ACFEC0[a1];
}
