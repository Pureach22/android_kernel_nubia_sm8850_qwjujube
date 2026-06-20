void __fastcall ipareg_construct_endp_init_hdr_ext_n(__int64 a1, __int64 a2, int *a3)
{
  int v3; // w8
  int v4; // w9
  int v5; // w8
  int v6; // w8
  int v7; // w8

  v3 = ((*(_DWORD *)a2 & 0xF) << 10) | *a3;
  v4 = *(unsigned __int8 *)(a2 + 17);
  *a3 = v3;
  v5 = (16 * (*(_DWORD *)(a2 + 4) & 0x3F)) | v3;
  *a3 = v5;
  v6 = v5 | (8 * *(unsigned __int8 *)(a2 + 8));
  *a3 = v6;
  v7 = (4 * (*(_DWORD *)(a2 + 12) & 1)) | v6;
  *a3 = v7;
  *a3 = v7 | (v4 | (2 * *(unsigned __int8 *)(a2 + 16))) ^ 1;
}
