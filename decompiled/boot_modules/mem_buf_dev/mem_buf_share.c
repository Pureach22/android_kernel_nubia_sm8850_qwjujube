__int64 __fastcall mem_buf_share(__int64 a1, unsigned int *a2)
{
  signed int v2; // w25
  int *v4; // x8
  __int64 v5; // x10
  int v6; // t1
  unsigned __int64 v7; // x21
  void *v8; // x20
  unsigned __int64 v9; // x28
  unsigned __int64 v10; // x23
  void *v11; // x22
  unsigned __int64 v12; // x24
  signed int v13; // w8
  __int64 v14; // x23
  __int64 v15; // x24
  unsigned int v16; // w0
  unsigned int v17; // w8
  unsigned int v18; // w21
  unsigned __int64 StatusReg; // x22
  __int64 v21; // x23

  v2 = *a2;
  if ( (int)*a2 < 1 )
  {
LABEL_5:
    if ( v2 + 1 < 0 )
      return 4294967284LL;
    v7 = 4LL * (unsigned int)(v2 + 1);
    v8 = (void *)_kmalloc_noprof(v7, 3264);
    v9 = v7;
    while ( 1 )
    {
      if ( !v8 )
        return 4294967284LL;
      if ( v2 + 1 < 0 || (v10 = 4LL * (unsigned int)(v2 + 1), (v11 = (void *)_kmalloc_noprof(v10, 3264)) == nullptr) )
      {
        kfree(v8);
        return 4294967284LL;
      }
      v12 = 4LL * v2;
      if ( v7 >= v12 )
      {
        memcpy(v8, *((const void **)a2 + 1), 4LL * v2);
        if ( v10 < v12 )
          goto LABEL_21;
        memcpy(v11, *((const void **)a2 + 2), 4LL * v2);
        if ( (v2 & 0x80000000) == 0 && v9 >= v12 && v9 - v12 >= 4 )
        {
          *((_DWORD *)v8 + v2) = current_vmid;
          if ( v10 >= v12 && v10 - v12 >= 4 )
          {
            *((_DWORD *)v11 + v2) = 7;
            v13 = *a2;
            v14 = *((_QWORD *)a2 + 1);
            v15 = *((_QWORD *)a2 + 2);
            *((_QWORD *)a2 + 1) = v8;
            *((_QWORD *)a2 + 2) = v11;
            *a2 = v13 + 1;
            v16 = mem_buf_lend_internal(a1, a2, 2);
            v17 = *a2;
            v18 = v16;
            *((_QWORD *)a2 + 1) = v14;
            *((_QWORD *)a2 + 2) = v15;
            *a2 = v17 - 1;
            kfree(v8);
            kfree(v11);
            return v18;
          }
        }
        __break(1u);
      }
      _fortify_panic(17, v7, 4LL * v2);
LABEL_21:
      _fortify_panic(17, v10, 4LL * v2);
      StatusReg = _ReadStatusReg(SP_EL0);
      v21 = *(_QWORD *)(StatusReg + 80);
      v7 = 4LL * (v2 + 1);
      *(_QWORD *)(StatusReg + 80) = &mem_buf_share__alloc_tag;
      if ( v2 + 1 < 0 )
      {
        v9 = 0;
        v8 = nullptr;
      }
      else
      {
        v8 = (void *)_kmalloc_noprof(4LL * (v2 + 1), 3264);
        v9 = 4LL * (v2 + 1);
      }
      *(_QWORD *)(StatusReg + 80) = v21;
    }
  }
  v4 = *((int **)a2 + 1);
  v5 = *a2;
  while ( 1 )
  {
    v6 = *v4++;
    if ( v6 == current_vmid )
      return mem_buf_lend_internal(a1, a2, 2);
    if ( !--v5 )
      goto LABEL_5;
  }
}
