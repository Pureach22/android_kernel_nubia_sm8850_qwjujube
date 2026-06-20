__int64 __fastcall kgsl_iopgtbl_map_child(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned __int64 a5,
        unsigned __int64 a6)
{
  unsigned __int64 v6; // x23
  unsigned __int64 v7; // x25
  __int64 v12; // x8
  __int64 result; // x0
  __int64 v14; // x24
  __int64 v15; // x9
  __int64 v16; // x10
  __int64 v17; // x8
  unsigned int v18; // w8
  int v19; // w10
  int v20; // w9
  int v21; // w10
  __int64 v22; // x22
  unsigned int v23; // w8
  __int64 v24; // x0
  __int64 v25; // x4
  int v26; // w0
  _QWORD *v27; // x21
  __int64 v28; // [xsp+0h] [xbp-30h] BYREF
  __int64 v29; // [xsp+8h] [xbp-28h]
  _QWORD *v30; // [xsp+10h] [xbp-20h] BYREF
  __int64 v31; // [xsp+18h] [xbp-18h]
  __int64 v32; // [xsp+20h] [xbp-10h]
  __int64 v33; // [xsp+28h] [xbp-8h]

  v6 = a6 >> 12;
  v7 = a5 >> 12;
  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a4 + 96);
  v28 = 0;
  v29 = 0;
  v31 = 0;
  v32 = 0;
  v30 = nullptr;
  if ( v12 )
  {
    result = sg_alloc_table_from_pages_segment(&v28, v12 + 8LL * (int)v7, (unsigned int)v6, 0, a6, 0xFFFFFFFFLL, 3264);
    if ( (_DWORD)result )
      goto LABEL_19;
  }
  else
  {
    result = sg_alloc_table(&v28, (unsigned int)v6, 3264);
    if ( (_DWORD)result )
      goto LABEL_19;
    v14 = v28;
    _sg_page_iter_start(&v30, **(_QWORD **)(a4 + 56), *(unsigned int *)(*(_QWORD *)(a4 + 56) + 12LL), (int)v7);
    do
    {
      if ( (_sg_page_iter_next(&v30) & 1) == 0 )
        break;
      v15 = (unsigned int)v31;
      v16 = *(_QWORD *)v14;
      v17 = *v30;
      *(_DWORD *)(v14 + 8) = 0;
      *(_DWORD *)(v14 + 12) = 4096;
      *(_QWORD *)v14 = ((v17 & 0xFFFFFFFFFFFFFFFCLL) + (v15 << 6)) & 0xFFFFFFFFFFFFFFFCLL | v16 & 3;
      LODWORD(v6) = v6 - 1;
      v14 = sg_next(v14);
    }
    while ( (_DWORD)v6 );
  }
  v18 = (unsigned int)*(_QWORD *)(a4 + 72) >> 31;
  if ( (*(_QWORD *)(a4 + 72) & 0x1000000LL) != 0 )
    v19 = 9;
  else
    v19 = 11;
  v20 = v19 | (*(_DWORD *)(a4 + 48) >> 1) & 0x20;
  v21 = *(_DWORD *)(a4 + 48);
  v22 = *(_QWORD *)(a2 + 24);
  v23 = v20 | (4 * v18);
  v24 = a1[25];
  v30 = nullptr;
  if ( (v21 & 0x80) != 0 )
    v25 = v23 & 0xFFFFFFE7;
  else
    v25 = v23;
  v26 = qcom_arm_lpae_map_sg(v24, v22 + a3, v28, (unsigned int)v29, v25, 3264, &v30);
  v27 = v30;
  if ( v26 )
  {
    iopgtbl_unmap(a1, v22 + a3, (unsigned __int64)v30);
    sg_free_table(&v28);
  }
  else
  {
    sg_free_table(&v28);
    if ( v27 )
    {
      result = 0;
      goto LABEL_19;
    }
  }
  result = 4294967284LL;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
