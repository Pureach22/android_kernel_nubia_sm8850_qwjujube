__int64 __fastcall msm_vidc_pool_alloc(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  __int64 v3; // x8
  unsigned int *v4; // x19
  unsigned int *v5; // x20
  unsigned int **v6; // x8
  unsigned int *v7; // x9
  __int64 v8; // x10
  unsigned int **v9; // x1
  __int64 v12; // x0
  __int64 v13; // x4
  unsigned int *v14; // x2
  __int64 *v15; // x1
  __int64 v16; // x9

  if ( a2 >= 7 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_80408, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_pool_alloc");
    return 0;
  }
  v3 = a1 + 48LL * a2;
  v4 = *(unsigned int **)(v3 + 2184);
  v5 = (unsigned int *)(v3 + 2168);
  if ( v4 == (unsigned int *)(v3 + 2184) )
  {
    v12 = vzalloc_noprof(*v5 + 32LL);
    if ( !v12 )
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
        printk(&unk_92E2A, "err ", a1 + 340, "msm_vidc_pool_alloc", v13);
      return 0;
    }
    *(_QWORD *)v12 = v12;
    v14 = v5 + 8;
    *(_QWORD *)(v12 + 8) = v12;
    v15 = *((__int64 **)v5 + 5);
    *(_BYTE *)(v12 + 20) = 1;
    *(_DWORD *)(v12 + 16) = a2;
    *(_QWORD *)(v12 + 24) = v12 + 32;
    if ( (unsigned int *)v12 == v5 + 8 || v15 == (__int64 *)v12 || (unsigned int *)*v15 != v14 )
    {
      _list_add_valid_or_report(v12);
      v12 = v16;
    }
    else
    {
      *((_QWORD *)v5 + 5) = v12;
      *(_QWORD *)v12 = v14;
      *(_QWORD *)(v12 + 8) = v15;
      *v15 = v12;
    }
    return *(_QWORD *)(v12 + 24);
  }
  else
  {
    v6 = *((unsigned int ***)v4 + 1);
    v7 = v5 + 8;
    if ( *v6 == v4 && (v8 = *(_QWORD *)v4, *(unsigned int **)(*(_QWORD *)v4 + 8LL) == v4) )
    {
      *(_QWORD *)(v8 + 8) = v6;
      *v6 = (unsigned int *)v8;
    }
    else
    {
      _list_del_entry_valid_or_report(v4);
    }
    v9 = *((unsigned int ***)v5 + 5);
    if ( v4 == v7 || v9 == (unsigned int **)v4 || *v9 != v7 )
    {
      _list_add_valid_or_report(v4);
    }
    else
    {
      *((_QWORD *)v5 + 5) = v4;
      *(_QWORD *)v4 = v7;
      *((_QWORD *)v4 + 1) = v9;
      *v9 = v4;
    }
    memset(*((void **)v4 + 3), 0, *v5);
    result = *((_QWORD *)v4 + 3);
    *((_BYTE *)v4 + 20) = 1;
  }
  return result;
}
