__int64 __fastcall get_secure_vmid(int a1)
{
  if ( (a1 & 0x10000) != 0 )
    return 1;
  if ( (a1 & 0x20000) != 0 )
    return 8;
  if ( (a1 & 0x40000) != 0 )
    return 9;
  if ( (a1 & 0x80000) != 0 )
    return 10;
  if ( (a1 & 0x100000) != 0 )
    return 11;
  if ( (a1 & 0x200000) != 0 )
    return 13;
  if ( (a1 & 0x2000000) != 0 )
    return 17;
  if ( (a1 & 0x4000000) != 0 )
    return 18;
  if ( (a1 & 0x8000000) != 0 )
    return 29;
  if ( (a1 & 0x800000) != 0 )
    return 26;
  if ( (a1 & 0x1000000) != 0 )
    return 34;
  if ( (a1 & 0x40000000) != 0 )
    return 36;
  if ( (a1 & 0x20000000) != 0 )
    return 42;
  if ( (a1 & 0x10000000) != 0 )
    return 15;
  return 4294967274LL;
}
