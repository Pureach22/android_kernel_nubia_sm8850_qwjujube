void __fastcall ipareg_construct_qsb_max_reads_v4_0(__int64 a1, _DWORD *a2, int *a3)
{
  int v3; // w8
  int v4; // w8
  int v5; // w8

  v3 = *a3 | *a2 & 0xF;
  *a3 = v3;
  v4 = (16 * (a2[1] & 0xF)) | v3;
  *a3 = v4;
  v5 = ((unsigned __int8)a2[2] << 16) | v4;
  *a3 = v5;
  *a3 = v5 | (a2[3] << 24);
}
