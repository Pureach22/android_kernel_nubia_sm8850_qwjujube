void __fastcall ipareg_construct_coal_evict_lru_v5_5(__int64 a1, unsigned __int8 *a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8
  int v6; // w8
  int v7; // w8
  int v8; // w8

  v3 = *a3 | a2[4];
  *a3 = v3;
  v4 = (2 * (a2[5] & 3)) | v3;
  *a3 = v4;
  v5 = (8 * (a2[6] & 0x1F)) | v4;
  *a3 = v5;
  v6 = ((a2[7] & 0x1F) << 8) | v5;
  *a3 = v6;
  v7 = v6 | (a2[8] << 13);
  *a3 = v7;
  v8 = v7 | (a2[9] << 14);
  *a3 = v8;
  *a3 = v8 | (a2[10] << 15);
}
