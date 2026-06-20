void __fastcall ipareg_construct_tx_cfg_v4_0(__int64 a1, _DWORD *a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8
  int v6; // w8
  int v7; // w8

  v3 = (4 * (a2[1] & 0xF)) | *a3;
  *a3 = v3;
  v4 = ((a2[2] & 0xF) << 13) | v3;
  *a3 = v4;
  v5 = ((a2[3] & 0xF) << 6) | v4;
  *a3 = v5;
  v6 = ((a2[4] & 1) << 10) | v5;
  *a3 = v6;
  v7 = ((a2[5] & 1) << 11) | v6;
  *a3 = v7;
  *a3 = ((a2[6] & 1) << 12) | v7;
}
