bool __fastcall rmnet_shs_wq_is_hash_rx_new_pkt(__int64 a1, __int64 a2)
{
  if ( a1 && a2 )
    return *(_QWORD *)(a2 + 144) != *(_QWORD *)(a1 + 136);
  ++qword_1A448;
  return 0;
}
