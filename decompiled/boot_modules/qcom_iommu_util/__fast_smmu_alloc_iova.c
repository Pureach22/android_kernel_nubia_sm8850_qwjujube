__int64 __fastcall _fast_smmu_alloc_iova(__int64 a1, unsigned __int64 a2)
{
  unsigned __int64 v3; // x10
  unsigned __int64 v4; // x20
  bool v5; // cf
  __int64 v6; // x22
  __int64 v7; // x1
  __int64 v8; // x0
  char v9; // w10
  __int64 v10; // x21
  unsigned __int64 next_zero_area_off; // x0
  unsigned __int64 v12; // x1
  unsigned __int64 v13; // x23
  unsigned __int64 v14; // x8
  unsigned __int64 v16; // x0
  unsigned __int64 v17; // x8
  void (__fastcall *v18)(_QWORD); // x9
  __int64 v19; // x0
  __int64 v20; // x1

  v3 = (a2 - 1) >> 12;
  v4 = a2 >> 12;
  v5 = a2 - 1 >= 0x1000;
  v6 = *(_QWORD *)(a1 + 8);
  v7 = *(_QWORD *)(a1 + 40);
  v8 = *(_QWORD *)(a1 + 64);
  v9 = __clz(v3);
  if ( v5 )
    v10 = (unsigned int)~(-1 << -v9);
  else
    v10 = 0;
  next_zero_area_off = bitmap_find_next_zero_area_off(v8, v7, *(_QWORD *)(a1 + 72), (unsigned int)v4, v10, 0);
  v12 = *(_QWORD *)(a1 + 40);
  v13 = next_zero_area_off;
  if ( next_zero_area_off > v12 )
  {
    v16 = bitmap_find_next_zero_area_off(*(_QWORD *)(a1 + 64), v12, 0, (unsigned int)v4, v10, 0);
    v17 = *(_QWORD *)(a1 + 40);
    v13 = v16;
    if ( v16 > v17 )
    {
      if ( *(_BYTE *)(a1 + 80) != 1 )
        return -1;
      v18 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v6 + 8) + 32LL);
      if ( v18 )
      {
        if ( *((_DWORD *)v18 - 1) != -1056074712 )
          __break(0x8229u);
        v18(v6);
        v17 = *(_QWORD *)(a1 + 40);
      }
      memcpy(*(void **)(a1 + 64), *(const void **)(a1 + 56), ((unsigned int)(v17 + 63) >> 3) & 0x1FFFFFF8);
      v19 = *(_QWORD *)(a1 + 64);
      v20 = *(_QWORD *)(a1 + 40);
      *(_BYTE *)(a1 + 80) = 0;
      v13 = bitmap_find_next_zero_area_off(v19, v20, 0, (unsigned int)v4, v10, 0);
      if ( v13 > *(_QWORD *)(a1 + 40) )
        return -1;
    }
  }
  _bitmap_set(*(_QWORD *)(a1 + 56), (unsigned int)v13, (unsigned int)v4);
  _bitmap_set(*(_QWORD *)(a1 + 64), (unsigned int)v13, (unsigned int)v4);
  v14 = *(_QWORD *)(a1 + 40);
  *(_QWORD *)(a1 + 72) = v13 + v4;
  if ( v13 + v4 >= v14 )
    *(_QWORD *)(a1 + 72) = 0;
  return *(_QWORD *)(a1 + 24) + (v13 << 12);
}
