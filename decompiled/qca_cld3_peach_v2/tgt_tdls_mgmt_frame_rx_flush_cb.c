__int64 __fastcall tgt_tdls_mgmt_frame_rx_flush_cb(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x0

  v1 = *(_QWORD *)(a1 + 8);
  if ( v1 )
  {
    v3 = *(_QWORD *)(v1 + 8);
    if ( v3 )
      _qdf_mem_free(v3);
    _qdf_mem_free(v1);
  }
  *(_QWORD *)(a1 + 8) = 0;
  return 0;
}
