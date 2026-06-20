__int64 __fastcall wmi_send_reset_peer_mumimo_tx_count_cmd(__int64 a1)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 2528LL);
  if ( !v1 )
    return 16;
  if ( *((_DWORD *)v1 - 1) != -2034668364 )
    __break(0x8228u);
  return v1();
}
