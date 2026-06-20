__int64 __fastcall hal_reo_ring_remap_value_get_be(unsigned __int8 a1)
{
  if ( a1 <= 7u )
    return (unsigned int)reo_dest_ring_remap[a1];
  else
    return 5;
}
