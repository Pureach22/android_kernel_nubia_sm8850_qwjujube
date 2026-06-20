void *__fastcall lim_intersect_eht_caps(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x22
  void *result; // x0
  __int64 v8; // x10
  _DWORD *v9; // x8
  unsigned __int64 v10; // x9
  __int64 v11; // x10
  __int64 v12; // x11
  unsigned __int64 v13; // x10
  unsigned __int64 v14; // x9
  unsigned __int64 v15; // x9
  unsigned __int64 v16; // x9
  unsigned __int64 v17; // x8

  v6 = a3 + 0x2000;
  result = qdf_mem_copy((void *)a2, (const void *)a1, 0x5Cu);
  v8 = *(_QWORD *)(a2 + 1);
  v9 = (_DWORD *)(a3 + 10073);
  v10 = v8 & 0xFFFFFFFFFFDFFFFFLL
      | ((((unsigned __int64)((unsigned int)v8 & (*(_DWORD *)(a3 + 10073) >> 1)) >> 21) & 1) << 21);
  *(_QWORD *)(a2 + 1) = v10;
  if ( (*(_BYTE *)(v6 + 1883) & 0x20) != 0 || (*(_BYTE *)(v6 + 1891) & 7) != 0 )
    v11 = v8 & 0x400000;
  else
    v11 = 0;
  v12 = *(_QWORD *)(a2 + 9);
  v13 = v11 | v10 & 0xFFFFFFFFFFBFFFFFLL;
  *(_QWORD *)(a2 + 1) = v13;
  v14 = v12 & 0xFFFFFFFFFFFEFFFFLL | ((((unsigned __int64)((unsigned int)v12 & (*v9 >> 6)) >> 16) & 1) << 16);
  *(_QWORD *)(a2 + 9) = v14;
  v15 = v14 & 0xFFFFFFFFFFFDFFFFLL | ((((unsigned __int64)((unsigned int)v12 & (*v9 >> 5)) >> 17) & 1) << 17);
  *(_QWORD *)(a2 + 9) = v15;
  v16 = v15 & 0xFFFFFFFFFFFBFFFFLL | ((((unsigned __int64)((unsigned int)v12 & (*v9 >> 4)) >> 18) & 1) << 18);
  *(_QWORD *)(a2 + 9) = v16;
  if ( (*(_BYTE *)(a3 + 10075) & 2) != 0 && (*(_BYTE *)(a1 + 3) & 2) != 0 )
    v17 = v13 | 0x20000;
  else
    v17 = v13 & 0xFFFFFFFFFFFDFFFFLL;
  *(_QWORD *)(a2 + 1) = v17;
  *(_QWORD *)(a2 + 9) = v16 & 0xFFFFFFFFFFFFF87FLL
                      | ((((unsigned __int64)(unsigned int)(*(_DWORD *)(v6 + 1889) & *(_DWORD *)(a1 + 9)) >> 7) & 0xF) << 7);
  return result;
}
