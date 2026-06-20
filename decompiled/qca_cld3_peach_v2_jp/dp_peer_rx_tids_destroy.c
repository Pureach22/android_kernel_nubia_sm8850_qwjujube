__int64 __fastcall dp_peer_rx_tids_destroy(__int64 a1)
{
  __int64 result; // x0

  result = _qdf_mem_free(*(_QWORD *)(a1 + 88));
  *(_QWORD *)(a1 + 88) = 0;
  return result;
}
