void *__fastcall hal_reo_qdesc_setup_be(
        int a1,
        int a2,
        unsigned int a3,
        unsigned int a4,
        _DWORD *a5,
        __int64 a6,
        int a7)
{
  void *result; // x0
  int v13; // w8
  int v14; // w10
  int v15; // w9
  int v16; // w11
  unsigned int v17; // w8
  int v18; // w12
  int v19; // w8
  unsigned int v20; // w10
  int v21; // w8
  int v22; // w11
  unsigned int v23; // w9
  unsigned int v24; // w8
  unsigned int v25; // w9
  int v26; // w10
  unsigned int v27; // w9

  result = qdf_mem_set(a5, 0x80u, 0);
  v13 = 0;
  v14 = a2 | (*((unsigned __int16 *)a5 + 3) << 16);
  v15 = a5[2];
  *a5 = (*a5 & 0xFFFFF00 | 0xF00000A4) - 32;
  a5[1] = v14;
  if ( a2 && a2 != 3 )
  {
    if ( (unsigned int)(a2 - 1) >= 2 )
    {
      if ( (a2 & 0xFFFFFFFE) == 4 )
        v13 = 64;
      else
        v13 = 96;
    }
    else
    {
      v13 = 32;
    }
  }
  if ( a3 <= 1 )
    v16 = 1;
  else
    v16 = a3;
  v17 = v15 & 0xFFFFFF98 | v13;
  v18 = v17 | 3;
  v19 = v17 | 0x103;
  if ( a3 >= 2 )
    v19 = v18;
  v20 = v19 & 0xFFE007FB | ((v16 << 11) - 2048);
  if ( (unsigned int)(a7 - 2) >= 2 )
  {
    if ( a7 == 1 )
    {
      v23 = v20 | 0x200000;
      v21 = 0x2000000;
      goto LABEL_22;
    }
    v22 = 0;
    v21 = 0;
  }
  else
  {
    v21 = 0x4000000;
    v22 = 0x200000;
  }
  v23 = v22 | v20 & 0xFFDFFFFB;
  if ( a7 == 3 )
  {
    v23 |= 0x800000u;
  }
  else if ( a7 == 2 )
  {
    v23 |= 0x400000u;
  }
LABEL_22:
  v24 = v21 | v23 & 0xF1FFFFFF | 0x8000000;
  if ( a4 >= 0x1000 )
    v25 = a5[3];
  else
    v25 = a5[3] & 0xFFFFE000 | (2 * a4);
  a5[2] = v24;
  a5[3] = v25 & 0xFFFFFFFE;
  if ( a2 != 16 )
  {
    result = qdf_mem_set(a5 + 32, 0x180u, 0);
    v26 = a5[96] & 0xFFFFF00;
    v27 = a5[64] & 0xFFFFF00 | 0xF00000A4;
    a5[32] = a5[32] & 0xFFFFF00 | 0xF00000A4;
    a5[64] = v27;
    a5[96] = v26 | 0xF00000A4;
  }
  return result;
}
