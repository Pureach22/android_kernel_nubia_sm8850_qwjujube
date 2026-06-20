__int64 __fastcall _remove_heap_parcel(unsigned int *a1, unsigned int a2)
{
  char v2; // w8
  unsigned int v5; // w20
  char v6; // w8
  unsigned int **v7; // x8
  unsigned int *v8; // x0
  __int64 v9; // x9
  __int64 v10; // x8
  const char *v12; // x8
  bool v13; // zf
  void *v14; // x0
  const char *v15; // x2

  v2 = *((_BYTE *)a1 + 16);
  if ( (v2 & 1) == 0 )
  {
    v5 = 0;
    if ( (a1[4] & 2) == 0 )
      goto LABEL_3;
    goto LABEL_8;
  }
  if ( a2 >= 2 )
    goto LABEL_28;
  v5 = gh_rm_remove_heap_memory(*(unsigned int *)(rm_heap_manager + 4LL * a2 + 4), *a1);
  if ( (v5 & 0x80000000) == 0 )
  {
    v2 = a1[4] & 0xFE;
    *((_BYTE *)a1 + 16) = v2;
    if ( (v2 & 2) == 0 )
    {
LABEL_3:
      if ( (v2 & 4) == 0 )
        goto LABEL_12;
      goto LABEL_10;
    }
LABEL_8:
    v5 = ghd_rm_mem_reclaim(*a1, 0);
    if ( v5 )
    {
      v12 = (const char *)&unk_7074;
      v13 = a2 == 1;
      v14 = &unk_71A7;
LABEL_22:
      if ( v13 )
        v12 = "RM heap";
      if ( a2 )
        v15 = v12;
      else
        v15 = "Root heap";
      printk(v14, "__remove_heap_parcel", v15, v5);
      *((_BYTE *)a1 + 16) |= 8u;
      return v5;
    }
    v6 = a1[4] & 0xFD;
    *((_BYTE *)a1 + 16) = v6;
    if ( (v6 & 4) == 0 )
    {
LABEL_12:
      v7 = *((unsigned int ***)a1 + 5);
      v8 = a1 + 8;
      if ( *v7 == a1 + 8 && (v9 = *(_QWORD *)v8, *(unsigned int **)(*(_QWORD *)v8 + 8LL) == v8) )
      {
        *(_QWORD *)(v9 + 8) = v7;
        *v7 = (unsigned int *)v9;
      }
      else
      {
        _list_del_entry_valid_or_report();
      }
      *((_QWORD *)a1 + 4) = 0xDEAD000000000100LL;
      *((_QWORD *)a1 + 5) = 0xDEAD000000000122LL;
      if ( a2 <= 2 )
      {
        v10 = rm_heap_manager;
        --*(_DWORD *)(rm_heap_manager + 4LL * a2 + 12);
        if ( a2 != 2 )
        {
          *(_QWORD *)(v10 + 8LL * a2 + 24) -= *((_QWORD *)a1 + 1);
          kfree(a1);
          return v5;
        }
      }
LABEL_28:
      __break(0x5512u);
      JUMPOUT(0x6BDC);
    }
LABEL_10:
    v5 = mem_prot_pool_free(*((_QWORD *)a1 + 3), *((_QWORD *)a1 + 1), 4);
    if ( !v5 )
    {
      *((_BYTE *)a1 + 16) &= ~4u;
      goto LABEL_12;
    }
    v12 = (const char *)&unk_7074;
    v13 = a2 == 1;
    v14 = &unk_72AC;
    goto LABEL_22;
  }
  return v5;
}
