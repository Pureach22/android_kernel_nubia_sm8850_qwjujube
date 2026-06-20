__int64 __fastcall _qdf_nbuf_data_get_icmp_subtype(__int64 a1)
{
  if ( *(_BYTE *)(a1 + 34) == 8 )
    return 15;
  else
    return 16 * (unsigned int)(*(_BYTE *)(a1 + 34) == 0);
}
