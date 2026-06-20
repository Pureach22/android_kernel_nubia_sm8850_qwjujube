__int64 __fastcall rmnet_map_flush_tx_packet_work(__int64 a1)
{
  void (*v2)(void); // x8

  raw_spin_lock_bh(a1 + 32);
  if ( *(_DWORD *)(a1 + 56) == -115 )
  {
    if ( *(_QWORD *)(a1 + 40) )
    {
      v2 = *(void (**)(void))(a1 + 48);
      *(_QWORD *)(a1 + 40) = 0;
      *(_BYTE *)(a1 + 60) = 0;
      *(_QWORD *)(a1 - 96) = 0;
      *(_QWORD *)(a1 - 88) = 0;
      *(_DWORD *)(a1 + 56) = 0;
      if ( *((_DWORD *)v2 - 1) != -1282094308 )
        __break(0x8228u);
      v2();
    }
    else
    {
      *(_DWORD *)(a1 + 56) = 0;
    }
  }
  return raw_spin_unlock_bh(a1 + 32);
}
