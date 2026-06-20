void __fastcall ipareg_construct_rx_hps_clients_depth0(__int64 a1, _DWORD *a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8

  v3 = *a3 | *a2 & 0x7F;
  *a3 = v3;
  v4 = ((a2[1] & 0x7F) << 8) | v3;
  *a3 = v4;
  v5 = ((a2[2] & 0x7F) << 16) | v4;
  *a3 = v5;
  *a3 = ((a2[3] & 0x7F) << 24) | v5;
}
