__int64 __fastcall hdd_convert_dot11mode(int a1)
{
  if ( (unsigned int)(a1 - 1) > 0xB )
    return 7;
  else
    return (unsigned int)dword_B2D5B0[a1 - 1];
}
