__int64 __fastcall synx_util_init_handle(unsigned __int64 a1, unsigned __int64 a2, int *a3, unsigned __int64 a4)
{
  __int64 result; // x0
  unsigned __int64 v9; // x20
  unsigned __int64 v10; // x0
  __int64 v11; // x4
  __int64 v12; // x5
  unsigned __int64 v13; // x19
  int v14; // w10
  __int64 v15; // x4
  __int64 v16; // x5
  int v17; // w11
  unsigned __int64 v18; // x8
  unsigned __int64 *v19; // x9
  unsigned __int64 v20; // x10
  unsigned __int64 v21; // x23
  __int64 v22; // x12
  unsigned __int64 v23; // x11
  unsigned int v24; // w22

  result = 4294967274LL;
  if ( a1
    && a1 <= 0xFFFFFFFFFFFFF000LL
    && a2
    && a2 <= 0xFFFFFFFFFFFFF000LL
    && a3
    && (unsigned __int64)a3 <= 0xFFFFFFFFFFFFF000LL
    && a4
    && a4 <= 0xFFFFFFFFFFFFF000LL )
  {
    v9 = a1;
    v10 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 2336, 88);
    v13 = v10;
    if ( v10 && v10 < 0xFFFFFFFFFFFFF001LL )
    {
      *(_QWORD *)(v10 + 16) = a4;
      v14 = *a3;
      *(_QWORD *)v10 = v9;
      *(_QWORD *)(v10 + 8) = a2;
      *(_DWORD *)(v10 + 24) = 1;
      *(_DWORD *)(v10 + 28) = v14;
      *(_DWORD *)(v10 + 32) = 1;
      raw_spin_lock_bh(v9 + 264920);
      v17 = *a3;
      v18 = v9;
      v19 = (unsigned __int64 *)(v9 + 8LL * ((unsigned int)(1640531527 * *a3) >> 24) + 262872);
      v20 = *v19;
      if ( !*v19 || (v21 = v20 - 72, v20 == 72) )
      {
LABEL_16:
        *(_QWORD *)(v13 + 72) = v20;
        v23 = v13 + 72;
        if ( v20 )
          *(_QWORD *)(v20 + 8) = v23;
        v24 = 0;
        *v19 = v23;
        *(_QWORD *)(v13 + 80) = v19;
      }
      else
      {
        while ( *(_DWORD *)(v21 + 28) != v17 )
        {
          v22 = *(_QWORD *)(v21 + 72);
          if ( v22 )
          {
            v21 = v22 - 72;
            if ( v22 != 72 )
              continue;
          }
          goto LABEL_16;
        }
        if ( *(_QWORD *)(v21 + 8) == a2 )
        {
          kref_get_0((unsigned int *)(v21 + 24));
          v24 = 0;
          ++*(_DWORD *)(v21 + 32);
        }
        else
        {
          if ( (synx_debug & 1) != 0 )
            printk(&unk_2AF73, &unk_29207, "synx_util_init_handle", 618, v15, v16);
          v24 = -22;
        }
        kfree(v13);
        v18 = v9;
      }
      raw_spin_unlock_bh(v18 + 264920);
      return v24;
    }
    else
    {
      if ( (synx_debug & 1) != 0 )
        printk(&unk_29102, &unk_29207, "synx_util_init_handle", 600, v11, v12);
      return 4294967284LL;
    }
  }
  return result;
}
