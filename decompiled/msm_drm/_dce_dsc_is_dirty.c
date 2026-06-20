bool __fastcall dce_dsc_is_dirty(_DWORD *a1)
{
  if ( a1[116] )
    return 1;
  if ( a1[117] )
    return 1;
  if ( a1[118] )
    return 1;
  return a1[119] != 0;
}
