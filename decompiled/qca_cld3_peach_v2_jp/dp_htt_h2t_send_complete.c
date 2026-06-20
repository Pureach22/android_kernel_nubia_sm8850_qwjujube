__int64 __fastcall dp_htt_h2t_send_complete(__int64 a1, __int64 a2)
{
  if ( *(_QWORD *)(a2 + 96) )
    _qdf_nbuf_free(*(_QWORD *)(a2 + 96));
  return htt_htc_pkt_free(a1, a2 - 16);
}
