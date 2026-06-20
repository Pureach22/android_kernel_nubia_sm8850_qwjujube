bool __fastcall _qdf_nbuf_data_is_arp_req(__int64 a1)
{
  return *(unsigned __int16 *)(a1 + 20) == 256;
}
