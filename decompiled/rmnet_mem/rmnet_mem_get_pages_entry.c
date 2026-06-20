__int64 __fastcall rmnet_mem_get_pages_entry(int a1, unsigned int a2, _DWORD *a3, unsigned int *a4, unsigned int a5)
{
  __int64 v5; // x22
  __int64 v6; // x25
  unsigned __int64 v7; // x26
  __int64 v10; // x23
  __int64 v13; // x0
  char *v14; // x10
  __int64 v15; // x0
  _QWORD **v16; // x8
  _QWORD *v17; // x9
  _QWORD *v18; // x11
  __int64 v19; // x13
  _QWORD *v20; // x8
  __int64 v21; // x10
  _QWORD *v22; // x8
  __int64 v23; // x12
  char *v24; // x2
  char **v25; // x1
  __int64 v26; // x8
  char *v27; // x11
  __int64 *v28; // x12
  __int64 *v29; // x13
  unsigned __int64 v30; // x15
  unsigned __int64 v31; // x27
  char *v32; // x9
  char *v33; // x28
  __int64 *v34; // x8
  char **v35; // x8
  __int64 v36; // x16
  char *v37; // x1
  char **v38; // x8
  __int64 v39; // x16
  char *v40; // x1
  char *v41; // x8
  char *v42; // x9
  char **v43; // x10
  unsigned int v49; // w10
  int v50; // w27
  __int64 v51; // x28
  int v53; // w8
  unsigned int v54; // w8
  __int64 v56; // x11
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  unsigned int v62; // w9
  unsigned int v65; // w9
  unsigned int v68; // w9
  int v69; // [xsp+Ch] [xbp-4h]

  if ( a2 > 4 )
  {
LABEL_2:
    v6 = 0;
    if ( !a3 || !a4 )
      return v6;
LABEL_87:
    *a3 = -1;
    *a4 = 0;
    return v6;
  }
  LODWORD(v10) = a1;
  v13 = raw_spin_lock_irqsave(&rmnet_mem_lock);
  if ( a5 >= 5 )
    goto LABEL_110;
  if ( a5 == 4 )
    goto LABEL_109;
  ++rmnet_mem_id_req[a5];
  if ( a2 == 4 )
    goto LABEL_109;
  v7 = a2;
  v5 = v13;
  ++rmnet_mem_order_requests[a2];
  v15 = rmnet_mem_cache_add(a2, 0);
  v6 = 0;
  v16 = (_QWORD **)((char *)&rmnet_mem_cache + 16 * a2);
  v17 = *v16;
  if ( *v16 == v16 )
    goto LABEL_23;
  v18 = v17 - 3;
  if ( v17 == &_ksymtab_rmnet_mem_get_pages_entry )
    goto LABEL_23;
  v19 = rmnet_mem_order_recycled[a2];
  ++rmnet_mem_id_recycled[a5];
  rmnet_mem_order_recycled[a2] = v19 + 1;
  --*((_DWORD *)&cache_pool_size + a2);
  v20 = (_QWORD *)v17[1];
  v6 = *(v17 - 3);
  if ( (_QWORD *)*v20 == v17 && (v21 = *v17, *(_QWORD **)(*v17 + 8LL) == v17) )
  {
    *(_QWORD *)(v21 + 8) = v20;
    *v20 = v21;
  }
  else
  {
    v15 = _list_del_entry_valid_or_report(v17);
  }
  *v17 = v17;
  v14 = (char *)(v17 - 2);
  v17[1] = v17;
  v22 = (_QWORD *)*(v17 - 1);
  if ( (_QWORD *)*v22 == v17 - 2 && (v23 = *(_QWORD *)v14, *(char **)(*(_QWORD *)v14 + 8LL) == v14) )
  {
    *(_QWORD *)(v23 + 8) = v22;
    *v22 = v23;
  }
  else
  {
    v15 = _list_del_entry_valid_or_report(v17 - 2);
  }
  *(v17 - 2) = v14;
  *(v17 - 1) = v14;
  if ( ((16LL * a2) | 8uLL) > 0x40 )
  {
LABEL_109:
    __break(1u);
LABEL_110:
    __break(0x5512u);
LABEL_111:
    v15 = _list_add_valid_or_report(v14);
    goto LABEL_21;
  }
  v24 = (char *)&rmnet_mem_pool + 16 * a2;
  v25 = *((char ***)v24 + 1);
  if ( v14 == v24 || v25 == (char **)v14 || *v25 != v24 )
    goto LABEL_111;
  *((_QWORD *)v24 + 1) = v14;
  *(v17 - 2) = v24;
  *(v17 - 1) = v25;
  *v25 = v14;
LABEL_21:
  v26 = *v18;
  if ( *(_DWORD *)(*v18 + 52LL) != 1 )
    __break(0x800u);
  _X8 = (unsigned int *)(v26 + 52);
  __asm { PRFM            #0x11, [X8] }
  do
    v62 = __ldxr(_X8);
  while ( __stxr(v62 + 1, _X8) );
LABEL_23:
  v69 = v10;
  v10 = v5;
  if ( !v6 && a2 - 1 <= 2 )
  {
    v27 = (char *)&rmnet_mem_pool;
    v28 = rmnet_mem_id_recycled;
    v29 = rmnet_mem_order_recycled;
    v30 = v7;
    do
    {
      v5 = 31;
      v31 = (16 * v30) | 8;
      v32 = &v27[16 * v30];
      while ( 1 )
      {
        v33 = *(char **)v32;
        v6 = 0;
        if ( *(char **)v32 == v32 )
          break;
        v34 = (__int64 *)(v33 - 8);
        if ( v33 == byte_8 )
          break;
        if ( *(_DWORD *)(*v34 + 52) == 1 )
        {
          v14 = (char *)(v28[a5] + 1);
          v28[a5] = (__int64)v14;
          if ( (v30 & 0x1FFFFFFFFFFFFFFCLL) != 0 )
            goto LABEL_109;
          ++v29[v30];
          v6 = *v34;
          _X8 = (unsigned int *)(*v34 + 52);
          __asm { PRFM            #0x11, [X8] }
          do
            v49 = __ldxr(_X8);
          while ( __stxr(v49 + 1, _X8) );
          v14 = *(char **)v32;
          if ( *(char **)v32 != v32 )
          {
            v38 = *((char ***)v14 + 1);
            if ( *v38 == v14 && (v39 = *(_QWORD *)v14, *(char **)(*(_QWORD *)v14 + 8LL) == v14) )
            {
              *(_QWORD *)(v39 + 8) = v38;
              *v38 = (char *)v39;
              if ( v31 > 0x40 )
                goto LABEL_109;
            }
            else
            {
              v15 = _list_del_entry_valid_or_report(*(_QWORD *)v32);
              if ( v31 > 0x40 )
                goto LABEL_109;
            }
            v40 = *((char **)v32 + 1);
            if ( v40 == v14 || *(char **)v40 != v32 )
            {
              v15 = _list_add_valid_or_report(v14);
            }
            else
            {
              *((_QWORD *)v32 + 1) = v14;
              *(_QWORD *)v14 = v32;
              *((_QWORD *)v14 + 1) = v40;
              *(_QWORD *)v40 = v14;
            }
          }
          v42 = v33 + 16;
          v41 = *((char **)v33 + 2);
          if ( v41 != v33 + 16 )
          {
            v43 = *((char ***)v33 + 3);
            if ( *v43 == v42 && *((char **)v41 + 1) == v42 )
            {
              *((_QWORD *)v41 + 1) = v43;
              *v43 = v41;
            }
            else
            {
              v15 = _list_del_entry_valid_or_report(v33 + 16);
            }
            *((_QWORD *)v33 + 2) = v33 + 16;
            *((_QWORD *)v33 + 3) = v42;
          }
          if ( a4 && v6 )
          {
            *a4 = v30;
            goto LABEL_69;
          }
          break;
        }
        v14 = *(char **)v32;
        if ( *(char **)v32 != v32 )
        {
          v35 = *((char ***)v14 + 1);
          if ( *v35 == v14 && (v36 = *(_QWORD *)v14, *(char **)(*(_QWORD *)v14 + 8LL) == v14) )
          {
            *(_QWORD *)(v36 + 8) = v35;
            *v35 = (char *)v36;
            if ( v31 > 0x40 )
              goto LABEL_109;
          }
          else
          {
            v15 = _list_del_entry_valid_or_report(*(_QWORD *)v32);
            if ( v31 > 0x40 )
              goto LABEL_109;
          }
          v37 = *((char **)v32 + 1);
          if ( v37 == v14 || *(char **)v37 != v32 )
          {
            v15 = _list_add_valid_or_report(v14);
          }
          else
          {
            *((_QWORD *)v32 + 1) = v14;
            *(_QWORD *)v14 = v32;
            *((_QWORD *)v14 + 1) = v37;
            *(_QWORD *)v37 = v14;
          }
        }
        v5 = (unsigned int)(v5 - 1);
        if ( !(_DWORD)v5 )
        {
          v6 = 0;
          break;
        }
      }
      if ( v6 )
        break;
    }
    while ( v30++ < 3 );
  }
LABEL_69:
  if ( *((_DWORD *)&static_pool_size + v7) < *((_DWORD *)&max_pool_size + v7) && pool_unbound_feature[v7] )
  {
    v50 = 0;
    v51 = v10;
    if ( v6 )
      goto LABEL_74;
  }
  else
  {
    v51 = v10;
    v15 = raw_spin_unlock_irqrestore(&rmnet_mem_lock, v10);
    v50 = 1;
    if ( v6 )
      goto LABEL_74;
  }
  v56 = rmnet_mem_order_gaveup[v7];
  ++rmnet_mem_id_gaveup[a5];
  rmnet_mem_order_gaveup[v7] = v56 + 1;
  if ( a2 <= 2 )
  {
    if ( v50 )
      v57 = v69 | 0x60000u;
    else
      v57 = 927776;
    v58 = _alloc_pages_noprof(v57, a2, 0, 0);
    v6 = v58;
    if ( v58 )
    {
      if ( (v50 & 1) != 0 )
      {
        if ( !a4 )
          goto LABEL_74;
      }
      else
      {
        rmnet_mem_add_page(v58, a2);
        _X8 = (unsigned int *)(v6 + 52);
        __asm { PRFM            #0x11, [X8] }
        do
          v65 = __ldxr(_X8);
        while ( __stxr(v65 + 1, _X8) );
        if ( !a4 )
        {
LABEL_74:
          if ( (v50 & 1) != 0 )
            goto LABEL_76;
          goto LABEL_75;
        }
      }
      *a4 = a2;
      goto LABEL_74;
    }
    ++qword_8E48;
    goto LABEL_74;
  }
  if ( (v50 & 1) != 0 )
    goto LABEL_2;
  if ( rmnet_mem_debug )
    ((void (__fastcall *)(__int64))rmnet_mem_check_all)(v15);
  v59 = _alloc_pages_noprof(927776, a2, 0, 0);
  v6 = v59;
  if ( v59 )
  {
    rmnet_mem_add_page(v59, a2);
    _X8 = (unsigned int *)(v6 + 52);
    __asm { PRFM            #0x11, [X8] }
    do
      v68 = __ldxr(_X8);
    while ( __stxr(v68 + 1, _X8) );
    if ( !a4 )
      goto LABEL_75;
    goto LABEL_118;
  }
  ++qword_8E48;
  if ( a4 )
LABEL_118:
    *a4 = a2;
LABEL_75:
  raw_spin_unlock_irqrestore(&rmnet_mem_lock, v51);
LABEL_76:
  if ( a3 )
    _ZF = a4 == nullptr;
  else
    _ZF = 1;
  v53 = !_ZF;
  if ( _ZF || !v6 )
  {
    if ( !v53 )
      return v6;
    goto LABEL_87;
  }
  v54 = *a4;
  if ( *a4 == a2 )
  {
    *a3 = 0;
  }
  else if ( v54 <= a2 )
  {
    if ( v54 < a2 )
      *a3 = -2;
  }
  else
  {
    *a3 = -3;
  }
  return v6;
}
