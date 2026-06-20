__int64 __fastcall zs_malloc(__int64 a1, unsigned __int64 a2, unsigned int a3)
{
  unsigned __int64 v3; // x20
  __int64 v6; // x19
  unsigned __int64 v7; // x8
  _QWORD *v8; // x24
  __int64 v9; // x8
  unsigned int *v10; // x23
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x8
  __int64 v19; // x8
  _QWORD *v20; // x8
  unsigned int v21; // w8
  int v22; // w9
  unsigned int v23; // w10
  unsigned __int64 v24; // x11
  unsigned int **v25; // x8
  unsigned int *v26; // x9
  __int64 v27; // x12
  unsigned int *v28; // x1
  __int64 v29; // x2
  __int64 v30; // x0
  __int64 v31; // x22
  int v32; // w8
  int v33; // w9
  __int64 v34; // x2
  __int64 v36; // x8
  __int64 v37; // x9
  unsigned __int64 StatusReg; // x23
  __int64 v39; // x24
  unsigned __int64 v46; // x10

  if ( !a2 )
    return -22;
  v3 = a2;
  if ( a2 > 0x1000 )
    return -28;
  v6 = kmem_cache_alloc_noprof(*(_QWORD *)(a1 + 2048), a3 & 0xFFFFFFF5);
  if ( !v6 )
    return -12;
  while ( 1 )
  {
    v7 = (v3 + 0xFFFFFFFF7LL) >> 4;
    if ( (int)v7 >= 254 )
      LODWORD(v7) = 254;
    if ( (unsigned int)v3 <= 0x18 )
      LODWORD(v7) = 0;
    if ( (unsigned int)v7 >= 0xFF )
      goto LABEL_64;
    v3 = *(_QWORD *)(a1 + 8LL * (unsigned int)v7 + 8);
    raw_spin_lock(v3);
    v8 = (_QWORD *)(v3 + 8);
    v9 = *(_QWORD *)(v3 + 168);
    if ( v9 == v3 + 168 || (v10 = (unsigned int *)(v9 - 24), v9 == 24) )
    {
      v11 = *(_QWORD *)(v3 + 152);
      if ( v11 == v3 + 152 || (v10 = (unsigned int *)(v11 - 24), v11 == 24) )
      {
        v12 = *(_QWORD *)(v3 + 136);
        if ( v12 == v3 + 136 || (v10 = (unsigned int *)(v12 - 24), v12 == 24) )
        {
          v13 = *(_QWORD *)(v3 + 120);
          if ( v13 == v3 + 120 || (v10 = (unsigned int *)(v13 - 24), v13 == 24) )
          {
            v14 = *(_QWORD *)(v3 + 104);
            if ( v14 == v3 + 104 || (v10 = (unsigned int *)(v14 - 24), v14 == 24) )
            {
              v15 = *(_QWORD *)(v3 + 88);
              if ( v15 == v3 + 88 || (v10 = (unsigned int *)(v15 - 24), v15 == 24) )
              {
                v16 = *(_QWORD *)(v3 + 72);
                if ( v16 == v3 + 72 || (v10 = (unsigned int *)(v16 - 24), v16 == 24) )
                {
                  v17 = *(_QWORD *)(v3 + 56);
                  if ( v17 == v3 + 56 || (v10 = (unsigned int *)(v17 - 24), v17 == 24) )
                  {
                    v18 = *(_QWORD *)(v3 + 40);
                    if ( v18 == v3 + 40 || (v10 = (unsigned int *)(v18 - 24), v18 == 24) )
                    {
                      v19 = *(_QWORD *)(v3 + 24);
                      if ( v19 == v3 + 24 || (v10 = (unsigned int *)(v19 - 24), v19 == 24) )
                      {
                        v20 = (_QWORD *)*v8;
                        if ( (_QWORD *)*v8 == v8 )
                          break;
                        v10 = (unsigned int *)(v20 - 3);
                        if ( v20 == &_ksymtab_zs_destroy_pool )
                          break;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    obj_malloc(a1, v10, v6);
    v21 = v10[1];
    if ( v21 )
    {
      v22 = *(_DWORD *)(v3 + 204);
      if ( v21 == v22 )
        v23 = 11;
      else
        v23 = (int)(100 * v21) / v22 / 10 + 1;
    }
    else
    {
      v23 = 0;
    }
    v24 = ((unsigned __int64)*v10 >> 1) & 0xF;
    if ( v23 == (_DWORD)v24 )
      goto LABEL_48;
    v25 = *((unsigned int ***)v10 + 4);
    v26 = v10 + 6;
    if ( *v25 == v10 + 6 && (v27 = *(_QWORD *)v26, *(unsigned int **)(*(_QWORD *)v26 + 8LL) == v26) )
    {
      *(_QWORD *)(v27 + 8) = v25;
      *v25 = (unsigned int *)v27;
    }
    else
    {
      _list_del_entry_valid_or_report(v10 + 6);
    }
    *((_QWORD *)v10 + 3) = v10 + 6;
    *((_QWORD *)v10 + 4) = v26;
    if ( (unsigned int)v24 < 0xE )
    {
      --*(_QWORD *)(v3 + 216 + 8 * v24);
      if ( v23 < 0xE )
      {
        ++*(_QWORD *)(v3 + 216 + 8LL * v23);
        if ( v23 != 13 )
        {
          v28 = (unsigned int *)&v8[2 * v23];
          v29 = *(_QWORD *)v28;
          if ( *(unsigned int **)(*(_QWORD *)v28 + 8LL) != v28 || v26 == v28 || (unsigned int *)v29 == v26 )
          {
            _list_add_valid_or_report(v26);
          }
          else
          {
            *(_QWORD *)(v29 + 8) = v26;
            *((_QWORD *)v10 + 3) = v29;
            *((_QWORD *)v10 + 4) = v28;
            *(_QWORD *)v28 = v26;
          }
          *v10 = *v10 & 0xFFFFFFE1 | (2 * v23);
LABEL_48:
          ++*(_QWORD *)(v3 + 320);
LABEL_49:
          raw_spin_unlock(v3);
          return v6;
        }
      }
    }
LABEL_64:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v39 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cache_alloc_handle__alloc_tag;
    v6 = kmem_cache_alloc_noprof(*(_QWORD *)(a1 + 2048), a3 & 0xFFFFFFF5);
    *(_QWORD *)(StatusReg + 80) = v39;
    if ( !v6 )
      return -12;
  }
  raw_spin_unlock(v3);
  v30 = alloc_zspage(a1, v3, a3);
  if ( v30 )
  {
    v31 = v30;
    raw_spin_lock(v3);
    obj_malloc(a1, v31, v6);
    v32 = *(_DWORD *)(v31 + 4);
    if ( v32 )
    {
      v33 = *(_DWORD *)(v3 + 204);
      if ( v32 == v33 )
        v34 = 11;
      else
        v34 = (unsigned int)(100 * v32 / v33 / 10 + 1);
    }
    else
    {
      v34 = 0;
    }
    insert_zspage(v3, v31, v34);
    v36 = *(int *)(v3 + 208);
    _X9 = (unsigned __int64 *)(a1 + 2064);
    __asm { PRFM            #0x11, [X9] }
    do
      v46 = __ldxr(_X9);
    while ( __stxr(v46 + v36, _X9) );
    v37 = *(_QWORD *)(v3 + 320) + 1LL;
    *(_QWORD *)(v3 + 312) += *(int *)(v3 + 204);
    *(_QWORD *)(v3 + 320) = v37;
    SetZsPageMovable(v31);
    goto LABEL_49;
  }
  kmem_cache_free(*(_QWORD *)(a1 + 2048), v6);
  return -12;
}
