__int64 __fastcall _qdf_nbuf_data_get_arp_subtype(__int64 a1)
{
  int v1; // w9
  unsigned int v2; // w8

  v1 = *(unsigned __int16 *)(a1 + 20);
  if ( v1 == 512 )
    v2 = 14;
  else
    v2 = 0;
  if ( v1 == 256 )
    return 13;
  else
    return v2;
}
