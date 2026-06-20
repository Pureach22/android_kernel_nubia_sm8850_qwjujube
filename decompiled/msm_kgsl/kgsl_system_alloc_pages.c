__int64 __fastcall kgsl_system_alloc_pages(__int64 a1, __int64 *a2)
{
  unsigned __int64 v3; // x20
  unsigned __int64 v4; // x24
  unsigned __int64 v5; // x19
  __int64 v6; // x23
  __int64 v7; // x8
  unsigned __int64 v8; // x27
  int v9; // w26
  unsigned __int64 StatusReg; // x28
  __int64 v11; // x22
  __int64 v12; // x0
  __int64 v13; // x24
  __int64 v14; // x25
  char v15; // w10
  __int64 result; // x0
  unsigned __int64 v17; // x9
  unsigned __int64 v18; // x9
  bool v19; // cf
  unsigned __int64 v20; // x22
  unsigned __int64 v21; // x25
  unsigned __int64 v22; // x8
  __int64 v23; // x24
  __int64 v24; // [xsp+8h] [xbp-38h]
  __int64 v26; // [xsp+18h] [xbp-28h] BYREF
  __int64 v27; // [xsp+20h] [xbp-20h]
  __int64 v28; // [xsp+28h] [xbp-18h]
  __int64 v29; // [xsp+30h] [xbp-10h]
  __int64 v30; // [xsp+38h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 40);
  v4 = v3 >> 12;
  if ( ((v3 >> 12 << 32) & 0x8000000000000000LL) != 0 )
    goto LABEL_28;
  v5 = (8 * (v3 >> 12)) & 0x7FFFFFFFFLL;
  v6 = _kvmalloc_node_noprof(v5, 0, 3520, 0xFFFFFFFFLL);
  if ( !v6 )
    goto LABEL_28;
  while ( 1 )
  {
    v24 = v4;
    if ( (int)v4 < 1 )
      break;
    v7 = (v3 >> 12) & 0x7FFFFFFF;
    v8 = 0;
    v9 = 1;
    v3 = v5;
    StatusReg = _ReadStatusReg(SP_EL0);
    v11 = 8 * v7;
    while ( 1 )
    {
      if ( (*(_QWORD *)StatusReg & 1) != 0 && (*(_BYTE *)(StatusReg + 2449) & 1) != 0 )
      {
        if ( v5 >= v8 && v3 >= 8 )
        {
          *(_QWORD *)(v6 + v8) = 0;
LABEL_20:
          if ( v9 == 1 )
          {
LABEL_27:
            kvfree(v6);
            goto LABEL_28;
          }
          while ( 1 )
          {
            v17 = 8LL * (unsigned int)(v9 - 2);
            v19 = v5 >= v17;
            v18 = v5 - v17;
            v19 = v19 && v18 >= 8;
            if ( !v19 )
              break;
            _free_pages(*(_QWORD *)(v6 + 8LL * (unsigned int)(v9 - 2)), 0);
            if ( --v9 <= 1 )
              goto LABEL_27;
          }
        }
LABEL_30:
        __break(1u);
      }
      v12 = _alloc_pages_noprof(3522, 0, 0, 0);
      v13 = v12;
      if ( v5 < v8 )
        goto LABEL_30;
      v19 = v3 >= 8;
      v3 -= 8LL;
      if ( !v19 )
        goto LABEL_30;
      *(_QWORD *)(v6 + v8) = v12;
      if ( !v12 )
        goto LABEL_20;
      v14 = *(_QWORD *)(a1 + 80);
      if ( v14 )
        break;
LABEL_5:
      v8 += 8LL;
      ++v9;
      if ( v11 == v8 )
        goto LABEL_16;
    }
    v28 = 0;
    v29 = 0;
    v26 = 0;
    v27 = 0;
    sg_init_table(&v26, 1);
    if ( (v13 & 3) == 0 )
    {
      v26 = v26 & 3 | v13;
      v15 = *(_BYTE *)(v14 + 844);
      v27 = 0x100000000000LL;
      v28 = ((v13 - -64LL * (memstart_addr >> 12)) << 6) + 0x5000000000LL;
      if ( (v15 & 0x40) == 0 )
        _dma_sync_sg_for_device(v14, &v26, 1, 1);
      goto LABEL_5;
    }
    __break(0x800u);
    v20 = _ReadStatusReg(SP_EL0);
    v21 = v13;
    v22 = v13 << 32;
    v23 = *(_QWORD *)(v20 + 80);
    *(_QWORD *)(v20 + 80) = &kgsl_system_alloc_pages__alloc_tag;
    if ( (v22 & 0x8000000000000000LL) != 0 )
    {
      v5 = 0;
      v6 = 0;
    }
    else
    {
      v5 = v22 >> 29;
      v6 = _kvmalloc_node_noprof(v22 >> 29, 0, 3520, 0xFFFFFFFFLL);
    }
    *(_QWORD *)(v20 + 80) = v23;
    v4 = v21;
    if ( !v6 )
    {
LABEL_28:
      result = 4294967284LL;
      goto LABEL_29;
    }
  }
LABEL_16:
  result = v24;
  *a2 = v6;
  *(_DWORD *)(a1 + 104) = v24;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
