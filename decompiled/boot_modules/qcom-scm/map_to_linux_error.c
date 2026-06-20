__int64 __fastcall map_to_linux_error(unsigned int a1)
{
  if ( a1 > 8 )
    return 4294967291LL;
  else
    return dword_13608[a1];
}
