__int64 __fastcall pe_set_ie_for_roam_invoke(__int64 a1, __int64 a2, unsigned __int16 a3)
{
  if ( a1 )
    return lim_send_ies_per_band(a1, a2, a3);
  else
    return 16;
}
