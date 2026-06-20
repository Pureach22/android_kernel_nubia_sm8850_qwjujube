bool __fastcall ll_lt_sap_is_freq_in_avoid_list(_DWORD *a1, int a2)
{
  if ( a1[54] == a2 )
    return 1;
  if ( a1[58] == a2 )
    return 1;
  return a1[62] == a2;
}
