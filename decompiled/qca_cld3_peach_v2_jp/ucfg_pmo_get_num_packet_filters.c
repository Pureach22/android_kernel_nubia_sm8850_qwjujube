__int64 __fastcall ucfg_pmo_get_num_packet_filters(__int64 result)
{
  if ( result )
    return pmo_get_num_packet_filters();
  return result;
}
