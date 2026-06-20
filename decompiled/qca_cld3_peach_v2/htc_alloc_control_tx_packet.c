__int64 __fastcall htc_alloc_control_tx_packet(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  __int64 v3; // x19
  __int64 v4; // x0
  __int64 v5; // x8

  v1 = *(_QWORD *)(a1 + 3456);
  result = _qdf_mem_malloc(112, "build_htc_tx_ctrl_packet", 77);
  if ( result )
  {
    v3 = result;
    v4 = _qdf_nbuf_alloc(v1, 264, 20, 4, 1, "build_htc_tx_ctrl_packet", 81);
    if ( v4 )
    {
      v5 = v4;
      *(_QWORD *)(v3 + 96) = v5;
      return v3;
    }
    else
    {
      _qdf_mem_free(v3);
      return 0;
    }
  }
  return result;
}
