__int64 __fastcall get_supported_sscan_bw_pos(unsigned int a1)
{
  if ( a1 > 7 )
    return 0xFFFFFFFFLL;
  else
    return dword_B354A8[a1];
}
