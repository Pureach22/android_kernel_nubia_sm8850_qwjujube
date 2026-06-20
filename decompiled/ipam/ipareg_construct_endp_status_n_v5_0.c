void __fastcall ipareg_construct_endp_status_n_v5_0(__int64 a1, unsigned __int8 *a2, int *a3)
{
  int v3; // w8
  int v4; // w8

  v3 = *a3 | *a2;
  *a3 = v3;
  v4 = v3 | (2 * a2[1]);
  *a3 = v4;
  *a3 = ((a2[3] & 1) << 9) | v4;
}
