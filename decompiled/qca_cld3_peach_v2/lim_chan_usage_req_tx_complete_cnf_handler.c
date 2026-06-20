__int64 __fastcall lim_chan_usage_req_tx_complete_cnf_handler(__int64 a1, __int64 a2, int a3, __int64 a4)
{
  __int64 session_by_vdev_id; // x0
  __int64 v8; // x20
  __int64 result; // x0

  if ( a2 )
    _qdf_nbuf_free(a2);
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, *(unsigned __int8 *)(a4 + 10));
  if ( !session_by_vdev_id )
    return 4;
  *(_BYTE *)(a1 + 3770) = *(_BYTE *)(session_by_vdev_id + 8);
  if ( a3 || (v8 = session_by_vdev_id, result = tx_timer_activate((char *)(a1 + 3720)), (_DWORD)result) )
  {
    lim_timer_handler(a1, 5120);
    return 0;
  }
  else
  {
    *(_BYTE *)(v8 + 13288) |= 2u;
  }
  return result;
}
