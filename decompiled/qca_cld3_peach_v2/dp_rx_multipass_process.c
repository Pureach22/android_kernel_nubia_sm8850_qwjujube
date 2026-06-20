__int64 __fastcall dp_rx_multipass_process(__int64 a1, __int64 a2, int a3)
{
  _WORD *v3; // x8
  int v4; // w10

  if ( !*(_WORD *)(a1 + 168) )
    return 1;
  v3 = *(_WORD **)(a2 + 224);
  if ( v3[6] == 129 && !v3[7] )
  {
    v4 = (unsigned __int16)v3[8];
    v3[7] = bswap32(*(_WORD *)(a1 + 168) & 0xFFF | (a3 << 13)) >> 16;
    if ( v4 == 36488 )
    {
      dp_tx_remove_vlan_tag(*(_QWORD *)a1, a2);
      return 1;
    }
    return 1;
  }
  return 0;
}
