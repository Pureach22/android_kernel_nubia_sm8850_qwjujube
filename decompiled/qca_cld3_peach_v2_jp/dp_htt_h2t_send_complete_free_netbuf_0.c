__int64 __fastcall dp_htt_h2t_send_complete_free_netbuf_0(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0

  if ( a3 )
    return _qdf_nbuf_free(a3);
  return result;
}
