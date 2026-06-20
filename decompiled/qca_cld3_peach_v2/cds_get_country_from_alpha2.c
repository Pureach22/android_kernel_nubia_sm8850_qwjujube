__int64 __fastcall cds_get_country_from_alpha2(unsigned __int8 *a1)
{
  __int64 v1; // x8
  unsigned __int8 **i; // x9

  v1 = (unsigned __int16)word_14D32;
  if ( !word_14D32 )
    return 0;
  for ( i = (unsigned __int8 **)((char *)off_14D20 + 8); **i != *a1 || (*i)[1] != a1[1]; i += 3 )
  {
    if ( !--v1 )
      return 0;
  }
  return *((unsigned __int16 *)i - 4);
}
