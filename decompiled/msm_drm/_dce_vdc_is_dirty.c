bool __fastcall dce_vdc_is_dirty(_DWORD *a1)
{
  if ( a1[120] )
    return 1;
  if ( a1[121] )
    return 1;
  if ( a1[122] )
    return 1;
  return a1[123] != 0;
}
