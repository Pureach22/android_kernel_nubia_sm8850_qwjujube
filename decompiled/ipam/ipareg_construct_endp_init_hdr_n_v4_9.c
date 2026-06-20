void __fastcall ipareg_construct_endp_init_hdr_n_v4_9(__int64 a1, _DWORD *a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8
  int v6; // w8
  int v7; // w8
  int v8; // w8
  int v9; // w8
  int v10; // w8

  v3 = *a3 | (a2[2] >> 6 << 30);
  *a3 = v3;
  v4 = (*a2 << 22) & 0x30000000 | v3;
  *a3 = v4;
  v5 = ((a2[7] & 1) << 27) | v4;
  *a3 = v5;
  v6 = ((a2[5] & 0x3F) << 20) | v5;
  *a3 = v6;
  v7 = ((a2[4] & 1) << 19) | v6;
  *a3 = v7;
  v8 = ((a2[3] & 0x3F) << 13) | v7;
  *a3 = v8;
  v9 = ((a2[2] & 0x3F) << 7) | v8;
  *a3 = v9;
  v10 = ((a2[1] & 1) << 6) | v9;
  *a3 = v10;
  *a3 = v10 | *a2 & 0x3F;
}
