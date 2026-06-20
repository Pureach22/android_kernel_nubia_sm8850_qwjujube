__int64 __fastcall kgsl_iopgtbl_map(_QWORD *a1, __int64 a2)
{
  _QWORD *v2; // x26
  int v4; // w10
  __int64 v5; // x8
  unsigned int v6; // w28
  unsigned __int64 v7; // x23
  int v8; // w0
  unsigned __int64 v9; // x22
  unsigned __int64 v10; // x27
  __int64 result; // x0
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 v14; // x4
  unsigned __int64 v15; // x23
  __int64 v16; // x0
  int v17; // w0
  __int64 v18; // x23
  __int64 v19; // x8
  _DWORD **v20; // x24
  unsigned __int64 v21; // x25
  unsigned __int64 v22; // x26
  __int64 v23; // x27
  _DWORD *v24; // x9
  __int64 v25; // x2
  unsigned __int64 v26; // [xsp+0h] [xbp-30h]
  _QWORD *v27; // [xsp+8h] [xbp-28h]
  unsigned __int64 v28; // [xsp+10h] [xbp-20h] BYREF
  __int64 v29; // [xsp+18h] [xbp-18h]
  unsigned __int64 v30[2]; // [xsp+20h] [xbp-10h] BYREF

  v2 = a1;
  v30[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*(_QWORD *)(a2 + 72) & 0x1000000LL) != 0 )
    v4 = 9;
  else
    v4 = 11;
  v5 = *(_QWORD *)(a2 + 56);
  if ( (*(_DWORD *)(a2 + 48) & 0x80) != 0 )
    v6 = v4 & 0xFFFFFFE7
       | (*(_DWORD *)(a2 + 48) >> 1) & 0x20
       | (4 * ((unsigned int)*(_QWORD *)(a2 + 72) >> 31)) & 0xFFFFFFE7;
  else
    v6 = v4 | (*(_DWORD *)(a2 + 48) >> 1) & 0x20 | (4 * ((unsigned int)*(_QWORD *)(a2 + 72) >> 31));
  if ( v5 )
  {
    v7 = *(_QWORD *)(a2 + 24);
    v28 = 0;
    v8 = qcom_arm_lpae_map_sg(a1[25], v7, *(_QWORD *)v5, *(unsigned int *)(v5 + 8), v6, 3264, &v28);
    v9 = v28;
    if ( v8 )
    {
      iopgtbl_unmap(v2, v7, v28);
      v9 = 0;
    }
    if ( !v9 )
      goto LABEL_38;
  }
  else
  {
    v12 = *(_QWORD *)(a2 + 96);
    v13 = *(unsigned int *)(a2 + 104);
    v14 = *(_QWORD *)(a2 + 40);
    v28 = 0;
    v29 = 0;
    result = sg_alloc_table_from_pages_segment(&v28, v12, v13, 0, v14, 0xFFFFFFFFLL, 3264);
    if ( (_DWORD)result )
      goto LABEL_39;
    v15 = *(_QWORD *)(a2 + 24);
    v16 = v2[25];
    v30[0] = 0;
    v17 = qcom_arm_lpae_map_sg(v16, v15, v28, (unsigned int)v29, v6, 3264, v30);
    v9 = v30[0];
    if ( v17 )
    {
      iopgtbl_unmap(v2, v15, v30[0]);
      v9 = 0;
    }
    sg_free_table(&v28);
    if ( !v9 )
    {
LABEL_38:
      result = 4294967284LL;
      goto LABEL_39;
    }
  }
  if ( (*(_DWORD *)(a2 + 48) & 1) != 0 )
    v10 = (*(_QWORD *)(a2 + 40) + 0x1FFFLL) & 0xFFFFFFFFFFFFF000LL;
  else
    v10 = *(_QWORD *)(a2 + 40);
  if ( v10 != v9 )
  {
    if ( a2 && (*(_DWORD *)(a2 + 48) & 0x10) != 0 )
    {
      v18 = kgsl_secure_guard_page;
      if ( !kgsl_secure_guard_page )
      {
        v18 = kgsl_alloc_secure_page();
        kgsl_secure_guard_page = v18;
        if ( !v18 )
          goto LABEL_37;
      }
    }
    else
    {
      v18 = kgsl_guard_page;
      if ( !kgsl_guard_page )
      {
        v18 = _alloc_pages_noprof(69058, 0, 0, 0);
        kgsl_guard_page = v18;
        if ( !v18 )
        {
LABEL_37:
          iopgtbl_unmap(v2, *(_QWORD *)(a2 + 24), v9);
          goto LABEL_38;
        }
      }
    }
    v19 = *(_QWORD *)(a2 + 24);
    v20 = (_DWORD **)v2[25];
    v28 = 0;
    if ( v10 != v9 )
    {
      v27 = v2;
      v21 = 0;
      v22 = v9 - v10;
      v23 = v19 + v9;
      v26 = v19 + v9;
      do
      {
        v24 = *v20;
        v25 = ((v18 - -64LL * (memstart_addr >> 12)) << 6) + 0x5000000000LL;
        if ( *(*v20 - 1) != 2054949561 )
          __break(0x8229u);
        if ( ((unsigned int (__fastcall *)(_DWORD **, __int64, __int64, __int64, __int64, _QWORD, __int64, unsigned __int64 *))v24)(
               v20,
               v23,
               v25,
               4096,
               1,
               v6 & 0x2D,
               3264,
               &v28) )
        {
          v2 = v27;
          iopgtbl_unmap(v27, v26, v21);
          goto LABEL_37;
        }
        v22 += 4096LL;
        v23 += 4096;
        v21 += v28;
      }
      while ( v22 );
      v2 = v27;
      if ( v21 )
        goto LABEL_15;
    }
    goto LABEL_37;
  }
LABEL_15:
  result = 0;
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
