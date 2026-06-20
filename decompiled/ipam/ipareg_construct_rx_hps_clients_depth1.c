void __fastcall ipareg_construct_rx_hps_clients_depth1(__int64 a1, _DWORD *a2, int *a3)
{
  int v3; // w8

  v3 = *a3 | *a2 & 0x7F;
  *a3 = v3;
  *a3 = ((a2[1] & 0x7F) << 8) | v3;
}
