__int64 __fastcall cds_packet_free(__int64 result)
{
  if ( result )
    return _qdf_nbuf_free(result);
  return result;
}
