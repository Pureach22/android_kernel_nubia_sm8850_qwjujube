void __fastcall ipareg_construct_rx_hps_clients_depth0_v4_5(__int64 a1, _DWORD *a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8
  int v6; // w8

  v3 = *a3 | *a2 & 0xF;
  *a3 = v3;
  v4 = ((a2[1] & 0xF) << 8) | v3;
  *a3 = v4;
  v5 = ((a2[2] & 0xF) << 16) | v4;
  *a3 = v5;
  v6 = ((a2[3] & 0xF) << 24) | v5;
  *a3 = v6;
  *a3 = v6 | (a2[4] << 28);
}
