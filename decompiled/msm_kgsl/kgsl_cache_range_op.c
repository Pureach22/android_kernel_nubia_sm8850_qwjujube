__int64 __fastcall kgsl_cache_range_op(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 result; // x0
  _QWORD *v6; // x8
  __int64 v8; // x9
  unsigned int v9; // w8
  unsigned __int64 v10; // x23
  int v11; // w21
  unsigned int v12; // w22
  unsigned __int64 v13; // x24
  _QWORD *v14; // [xsp+0h] [xbp-20h] BYREF
  __int64 v15; // [xsp+8h] [xbp-18h]
  __int64 v16; // [xsp+10h] [xbp-10h]
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_BYTE *)(a1 + 75) & 0x80) != 0 )
    goto LABEL_13;
  if ( (unsigned __int64)(a3 - 0x100000000LL) < 0xFFFFFFFF00000001LL )
  {
    result = 4294967274LL;
    goto LABEL_14;
  }
  if ( __CFADD__(a3, a2) || (unsigned __int64)(a3 + a2) > *(_QWORD *)(a1 + 40) )
  {
    result = 4294967262LL;
    goto LABEL_14;
  }
  v6 = *(_QWORD **)(a1 + 56);
  v8 = (a2 & 0xFFFFFFFFFFFFF000LL) + a3;
  if ( v6 )
  {
    v15 = 0;
    v16 = 0;
    v14 = nullptr;
    _sg_page_iter_start(&v14, *v6, (unsigned __int64)(v8 + 4095) >> 12, 0);
    while ( (_sg_page_iter_next(&v14) & 1) != 0 )
      ((void (__fastcall *)(_QWORD, unsigned __int64, _QWORD))dma_cache_op)(
        *(_QWORD *)(a1 + 80),
        (*v14 & 0xFFFFFFFFFFFFFFFCLL) + ((unsigned __int64)(unsigned int)v15 << 6),
        a4);
    goto LABEL_13;
  }
  v9 = *(_DWORD *)(a1 + 104);
  if ( !v9 )
  {
LABEL_13:
    result = 0;
    goto LABEL_14;
  }
  v10 = a2 & 0xFFF;
  v11 = 0;
  v12 = 0;
  v13 = v8 + v10;
  do
  {
    if ( v10 <= v11 && v13 > v11 )
    {
      ((void (__fastcall *)(_QWORD, _QWORD, _QWORD))dma_cache_op)(
        *(_QWORD *)(a1 + 80),
        *(_QWORD *)(*(_QWORD *)(a1 + 96) + 8LL * (int)v12),
        a4);
      v9 = *(_DWORD *)(a1 + 104);
    }
    ++v12;
    result = 0;
    v11 += 4096;
  }
  while ( v12 < v9 );
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
