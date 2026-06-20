void *__fastcall lim_intersect_he_caps(const void *a1, _BYTE *a2, __int64 a3)
{
  __int64 v5; // x21
  void *result; // x0
  __int64 v7; // x11
  unsigned int v8; // w9
  unsigned __int64 v9; // x10
  unsigned __int64 v10; // x11
  unsigned __int64 v11; // x9
  unsigned int v12; // w11
  __int64 *v13; // x10
  __int64 v14; // x11
  __int64 v15; // x12
  unsigned __int64 v16; // x13
  __int64 v17; // x12
  unsigned __int64 v18; // x12
  unsigned __int64 v19; // x10

  v5 = a3 + 0x2000;
  result = qdf_mem_copy(a2, a1, 0x3Cu);
  v7 = *(_QWORD *)(a2 + 1);
  v8 = (*(_DWORD *)(a3 + 8681) >> 3) & 3;
  if ( v8 >= (((unsigned int)v7 >> 3) & 3) )
    v8 = ((unsigned int)v7 >> 3) & 3;
  v9 = v7 & 0xFFFFFFFFFFFFFFE7LL | (8 * v8);
  *(_QWORD *)(a2 + 1) = v9;
  v10 = v7 & *(_QWORD *)(a3 + 8681);
  v11 = v9 & 0xBFFFFFFFFFFFFFFFLL | (((v10 >> 62) & 1) << 62);
  *(_QWORD *)(a2 + 1) = v11;
  if ( (v10 & 0x4000000000000000LL) == 0 )
  {
    if ( *(_DWORD *)(a3 + 7176)
      || (v12 = *((unsigned __int16 *)a2 + 10), ((v12 >> (2 * *(_BYTE *)(v5 + 443) - 2)) & 3) == 2)
      || ((*((unsigned __int16 *)a2 + 11) >> (2 * *(_BYTE *)(v5 + 443) - 2)) & 3) == 2
      || *(_BYTE *)(v5 + 484) == 1 && v12 >> 8 <= 0xFE && *a2 )
    {
      v11 = v9 | 0x4000000000000000LL;
      *(_QWORD *)(a2 + 1) = v9 | 0x4000000000000000LL;
    }
  }
  v13 = (__int64 *)(v5 + 497);
  v14 = *(_QWORD *)(a2 + 9);
  v15 = *(_QWORD *)(v5 + 497);
  if ( (v15 & 8) == 0 || (v14 & 0x10) == 0 )
  {
    v14 &= ~0x10uLL;
    *(_QWORD *)(a2 + 9) = v14;
    v15 = *v13;
  }
  if ( (v15 & 0x10) == 0 || (v14 & 8) == 0 )
  {
    v14 &= ~8uLL;
    *(_QWORD *)(a2 + 9) = v14;
    v15 = *v13;
  }
  if ( (v15 & 0x2000000000000LL) == 0 || (v14 & 0x4000000000000LL) == 0 )
  {
    v14 &= ~0x4000000000000uLL;
    *(_QWORD *)(a2 + 9) = v14;
    v15 = *v13;
  }
  if ( (v15 & 0x4000000000000LL) == 0 || (v14 & 0x2000000000000LL) == 0 )
  {
    v14 &= ~0x2000000000000uLL;
    *(_QWORD *)(a2 + 9) = v14;
    v15 = *v13;
  }
  if ( (v15 & 0x60) != 0 )
  {
    v14 &= 0xFFFFFFFFFFFFFF9FLL;
    *(_QWORD *)(a2 + 9) = v14;
    v15 = *v13;
  }
  *(_QWORD *)(a2 + 9) = v14 & 0xFFFFFFFFFFFEFFFFLL
                      | ((((unsigned __int64)((unsigned int)v14 & ((unsigned int)v15 >> 1)) >> 16) & 1) << 16);
  v16 = v14 & 0xFFFFFFFFFFFCFFFFLL
      | ((((unsigned __int64)((unsigned int)v14 & ((unsigned int)v15 >> 1)) >> 16) & 1) << 16) & 0xFFFFFFFFFFFDFFFFLL;
  if ( (*v13 & 0x50000) != 0 )
    v17 = v14 & 0x20000;
  else
    v17 = 0;
  v18 = v17 | v16;
  *(_QWORD *)(a2 + 9) = v18;
  *(_QWORD *)(a2 + 9) = v18 & 0xFFFFFFFFFFFBFFFFLL
                      | ((((unsigned __int64)((unsigned int)v14 & (2 * *(_DWORD *)v13)) >> 18) & 1) << 18);
  v19 = (unsigned __int64)((unsigned int)v11 & (*(_DWORD *)(a3 + 8681) >> 1)) >> 1;
  *(_QWORD *)(a2 + 1) = v11 & 0xFFFFFFFFFFFFFFFDLL
                      | (2LL * (((unsigned int)v11 & (*(_DWORD *)(a3 + 8681) >> 1) & 2LL) != 0));
  *(_QWORD *)(a2 + 1) = v11 & 0xFFFFFFFFFFFFFFF9LL
                      | (unsigned __int8)(2 * (v19 & 1)) & 0xFB
                      | (4 * (((unsigned __int64)((unsigned int)v11 & (2 * *(_DWORD *)(a3 + 8681))) >> 2) & 1));
  return result;
}
