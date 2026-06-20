bool __fastcall wlansap_is_channel_present_in_acs_list(int a1, _DWORD *a2, unsigned __int8 a3)
{
  __int64 v4; // x10
  unsigned __int64 v5; // x9

  if ( !a3 )
    return 0;
  if ( *a2 == a1 )
    return 1;
  v4 = 1;
  do
  {
    v5 = v4;
    if ( a3 == v4 )
      break;
  }
  while ( a2[v4++] != a1 );
  return v5 < a3;
}
