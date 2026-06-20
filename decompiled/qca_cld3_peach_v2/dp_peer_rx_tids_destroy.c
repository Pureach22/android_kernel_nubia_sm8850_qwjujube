__int64 __fastcall dp_peer_rx_tids_destroy(__int64 result)
{
  __int64 v1; // x19

  v1 = result;
  if ( *(_DWORD *)(result + 408) != 1 || !*(_QWORD *)(result + 416) )
    result = _qdf_mem_free(*(_QWORD *)(result + 88));
  *(_QWORD *)(v1 + 88) = 0;
  return result;
}
