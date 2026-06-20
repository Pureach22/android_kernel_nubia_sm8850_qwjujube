unsigned __int64 __fastcall gh_rm_heap_memlend_prealloc(unsigned __int64 result)
{
  unsigned __int64 v1; // x23
  __int64 v2; // x8
  const char *v3; // x22
  char v4; // w9
  char v5; // w24
  __int64 v6; // x19
  unsigned int v7; // w0
  unsigned __int64 v8; // x20
  const char *v9; // x2
  unsigned __int64 v10; // x8
  int v11; // w8
  __int16 v12; // w19
  int v13; // w28
  __int64 v14; // x2
  __int64 v15; // x3
  bool v16; // cf
  int v17; // w26
  unsigned __int64 v18; // x23
  _QWORD *v19; // x21
  unsigned int v20; // w0
  __int64 v21; // x0
  __int64 v22; // x20
  __int64 v23; // x26
  unsigned int v24; // w0
  __int64 v25; // x9
  __int64 v26; // x1
  char v27; // w8
  int v28; // w9
  __int64 v29; // x10
  __int64 v30; // x8
  _QWORD *v31; // x1
  _QWORD *v32; // x2
  __int64 v33; // x10
  __int64 v34; // x2
  __int64 v35; // x3
  const char *v36; // x2
  unsigned __int64 v37; // [xsp+18h] [xbp-28h]
  unsigned __int64 v38; // [xsp+20h] [xbp-20h]
  __int64 v39; // [xsp+28h] [xbp-18h] BYREF
  _QWORD v40[2]; // [xsp+30h] [xbp-10h] BYREF

  v40[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( rm_heap_manager_enabled == 1 )
  {
    v1 = result >> 12;
    v2 = 0;
    v3 = (const char *)&unk_7074;
    _ReadStatusReg(SP_EL0);
    v37 = result >> 12;
    v4 = 1;
    do
    {
      v5 = v4;
      if ( (v4 & 1) != 0 )
        v6 = 20;
      else
        v6 = 12;
      if ( rm_heap_manager_enabled == 1 )
      {
        v39 = 0;
        v40[0] = 0;
        v7 = gh_rm_heap_query(*(unsigned int *)(rm_heap_manager + 4 * v2 + 4), 2, v40, &v39);
        if ( (v7 & 0x80000000) == 0 )
        {
          result = v40[0];
          v8 = *(_QWORD *)v40[0] - *(_QWORD *)(v40[0] + 8LL);
          if ( v39 )
            result = kfree(v40[0]);
          goto LABEL_17;
        }
        if ( (v5 & 1) != 0 )
          v9 = "Root heap";
        else
          v9 = v3;
        result = printk(&unk_7136, "gh_get_rm_heap_free", v9, v7);
      }
      v8 = 0;
LABEL_17:
      v10 = v6 * v1 - v8;
      if ( v6 * v1 <= v8 )
        goto LABEL_4;
      v38 = v10 + 0x3FFFFF;
      v11 = (unsigned __int16)((v10 + 0x3FFFFF) >> 22);
      if ( !v11 )
        goto LABEL_4;
      v12 = 0;
      v13 = -v11;
      do
      {
        while ( 1 )
        {
          v17 = *(_DWORD *)rm_heap_manager;
          v40[0] = 0;
          LODWORD(v39) = 0;
          result = _kmalloc_cache_noprof(gh_rm_add_heap_memory, 3520, 48);
          v18 = result;
          if ( !result )
            goto LABEL_26;
          v19 = (_QWORD *)(result + 32);
          *(_QWORD *)(result + 32) = result + 32;
          *(_QWORD *)(result + 40) = result + 32;
          v20 = mem_prot_pool_alloc(0x400000, v40, 4);
          if ( v20 )
          {
            printk(&unk_6FA7, "gh_rm_heap_add_chunk", "Root heap", v20);
            goto LABEL_25;
          }
          *(_BYTE *)(v18 + 16) |= 4u;
          v21 = _kmalloc_cache_noprof(mem_alloc_profiling_key, 3520, 8);
          v22 = v21;
          if ( !v21 )
            goto LABEL_23;
          *(_WORD *)(v21 + 4) = v17;
          *(_DWORD *)v21 = 1;
          *(_BYTE *)(v21 + 6) = 7;
          v23 = _kmalloc_cache_noprof(ghd_rm_mem_lend, 3520, 22);
          if ( !v23 )
            goto LABEL_22;
          *(_QWORD *)(v23 + 6) = v40[0];
          *(_DWORD *)v23 = 1;
          *(_QWORD *)(v23 + 14) = 0x400000;
          v24 = ghd_rm_mem_lend(0, 0, 0, v22, v23, 0, &v39);
          if ( v24 )
          {
            printk(&unk_70B6, "gh_rm_heap_add_chunk", "Root heap", v24);
LABEL_21:
            kfree(v23);
LABEL_22:
            kfree(v22);
LABEL_23:
            if ( (unsigned int)mem_prot_pool_free(v40[0], 0x400000, 4) )
              printk(&unk_7165, "gh_rm_heap_add_chunk", v14, v15);
            goto LABEL_25;
          }
          v25 = rm_heap_manager;
          v26 = (unsigned int)v39;
          *(_BYTE *)(v18 + 16) |= 2u;
          if ( (gh_rm_add_heap_memory(*(unsigned int *)(v25 + 4), v26) & 0x80000000) == 0 )
            break;
          printk(&unk_70DF, "gh_rm_heap_add_chunk", 0x400000, "Root heap");
          if ( !(unsigned int)ghd_rm_mem_reclaim((unsigned int)v39, 0) )
            goto LABEL_21;
          printk(&unk_6FD4, "gh_rm_heap_add_chunk", v34, v35);
          kfree(v23);
          kfree(v22);
LABEL_25:
          result = kfree(v18);
LABEL_26:
          ++v12;
          v16 = __CFADD__(v13++, 1);
          if ( v16 )
            goto LABEL_3;
        }
        v27 = *(_BYTE *)(v18 + 16);
        v28 = v39;
        *(_QWORD *)(v18 + 8) = 0x400000;
        v29 = v40[0];
        *(_DWORD *)v18 = v28;
        *(_BYTE *)(v18 + 16) = v27 | 1;
        *(_QWORD *)(v18 + 24) = v29;
        mutex_lock(&rm_heap_lock);
        v30 = rm_heap_manager;
        v31 = (_QWORD *)(rm_heap_manager + 40);
        v32 = *(_QWORD **)(rm_heap_manager + 40);
        if ( v32[1] != rm_heap_manager + 40 || v19 == v31 || v32 == v19 )
        {
          _list_add_valid_or_report(v18 + 32);
          v30 = rm_heap_manager;
        }
        else
        {
          v32[1] = v19;
          *(_QWORD *)(v18 + 32) = v32;
          *(_QWORD *)(v18 + 40) = v31;
          *v31 = v19;
        }
        v33 = *(_QWORD *)(v30 + 24) + 0x400000LL;
        ++*(_DWORD *)(v30 + 12);
        *(_QWORD *)(v30 + 24) = v33;
        mutex_unlock(&rm_heap_lock);
        kfree(v22);
        result = kfree(v23);
        v16 = __CFADD__(v13++, 1);
      }
      while ( !v16 );
LABEL_3:
      v1 = v37;
      if ( v12 )
      {
        if ( (v5 & 1) != 0 )
          v36 = "Root heap";
        else
          v36 = v3;
        result = printk(&unk_726D, "gh_rm_heap_memlend_prealloc", v36, v38 & 0xFFFFFFFFFFC00000LL);
      }
LABEL_4:
      v4 = 0;
      v3 = "RM heap";
      v2 = 1;
    }
    while ( (v5 & 1) != 0 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
