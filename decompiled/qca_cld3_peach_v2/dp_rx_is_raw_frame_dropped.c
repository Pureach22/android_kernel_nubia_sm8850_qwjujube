__int64 __fastcall dp_rx_is_raw_frame_dropped(__int64 a1)
{
  unsigned __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 72);
  if ( a1 && (v1 & 0x800000) != 0 )
    _qdf_nbuf_free(a1);
  return (v1 >> 23) & 1;
}
