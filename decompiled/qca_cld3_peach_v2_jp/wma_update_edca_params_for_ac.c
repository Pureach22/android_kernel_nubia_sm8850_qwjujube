void __fastcall wma_update_edca_params_for_ac(
        unsigned __int8 *a1,
        int *a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5,
        int a6,
        _DWORD *a7)
{
  unsigned int v8; // w9
  unsigned int v9; // w10
  int v10; // w0

  v8 = ~(-1 << (a1[1] & 0xF));
  a2[2] = v8;
  a2[3] = ~(-1 << (a1[1] >> 4));
  v9 = *a1 & 0xF;
  a2[1] = v9;
  a2[4] = *((unsigned __int16 *)a1 + 1);
  *a2 = (*a1 >> 4) & 1;
  a2[5] = a1[4];
  scnprintf(
    a5 + (unsigned int)*a7,
    (unsigned int)(a6 - *a7),
    "AC[%d]: AIFS %d Min %d Max %d %s %d ACM %d NOACK %d, ",
    a3,
    v9,
    v8);
  *a7 += v10;
}
