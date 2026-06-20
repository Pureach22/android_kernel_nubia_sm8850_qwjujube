__int64 __fastcall qcedev_check_and_map_buffer(_QWORD *a1, unsigned int a2, __int64 a3, __int64 a4, _QWORD *a5)
{
  _DWORD *v8; // x24
  unsigned __int64 v9; // x25
  unsigned int v10; // w27
  _QWORD *v11; // x23
  _QWORD *v12; // x8
  unsigned __int64 v13; // x22
  __int64 v14; // x26
  __int64 v15; // x22
  __int64 v16; // x2
  __int64 v17; // x3
  unsigned __int64 v18; // x0
  __int64 v19; // x2
  __int64 v20; // x3
  unsigned __int64 v21; // x26
  int v22; // w9
  void *v23; // x0
  __int64 v24; // x28
  unsigned __int64 v25; // x0
  __int64 v26; // x2
  __int64 v27; // x3
  unsigned __int64 v28; // x0
  __int64 v29; // x2
  unsigned __int64 v30; // x3
  __int64 v31; // x8
  __int64 v32; // x9
  void *v33; // x0
  int v34; // w27
  unsigned __int64 v35; // x27
  void *v36; // x0
  __int64 *v37; // x1
  unsigned int v45; // w9
  unsigned int v48; // w9
  unsigned int v49; // [xsp+Ch] [xbp-4h]

  if ( (unsigned int)a3 >= (unsigned int)a4 || (a2 & 0x80000000) != 0 || !a1 || !a5 )
  {
    v33 = &unk_1258B;
    goto LABEL_33;
  }
  if ( !*a1 || (v8 = *(_DWORD **)(*a1 + 336LL)) == nullptr )
  {
    v33 = &unk_11B6A;
LABEL_33:
    printk(v33, "qcedev_check_and_map_buffer", a3, a4);
    LODWORD(v9) = -22;
    return (unsigned int)v9;
  }
  if ( *v8 )
  {
    LODWORD(v9) = -1;
    return (unsigned int)v9;
  }
  v10 = a4;
  v49 = a3;
  v11 = a1 + 25;
  mutex_lock(a1 + 27);
  v12 = a1 + 25;
  do
  {
    v12 = (_QWORD *)*v12;
    if ( v12 == v11 )
    {
      mutex_unlock(a1 + 27);
      v15 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 88);
      if ( !v15 )
      {
        printk(&unk_12AD5, "qcedev_check_and_map_buffer", v16, v17);
        LODWORD(v9) = -12;
        goto LABEL_64;
      }
      if ( *v8 )
      {
        printk(&unk_1233D, "qcedev_map_buffer", v16, v17);
        LODWORD(v9) = -1;
      }
      else
      {
        v18 = dma_buf_get(a2);
        LODWORD(v9) = -22;
        if ( v18 )
        {
          v21 = v18;
          if ( v18 <= 0xFFFFFFFFFFFFF000LL )
          {
            if ( *(_QWORD *)(*a1 + 320LL) != *a1 + 320LL )
            {
              v22 = (mem_buf_dma_buf_exclusive_owner(v18) & 1) == 0;
              v23 = &unk_12BA9;
              v24 = *a1 + 320LL;
              do
              {
                v24 = *(_QWORD *)v24;
                if ( v24 == *a1 + 320LL )
                  goto LABEL_37;
              }
              while ( *(unsigned __int8 *)(v24 + 36) != v22 );
              if ( !v24 )
              {
                v23 = &unk_12BA9;
                goto LABEL_37;
              }
              v25 = dma_buf_attach(v21, *(_QWORD *)(v24 + 40));
              v9 = v25;
              if ( v25 && v25 < 0xFFFFFFFFFFFFF001LL )
              {
                *(_QWORD *)(v25 + 72) |= 0x20000uLL;
                v28 = dma_buf_map_attachment_unlocked(v25, 0);
                if ( v28 && v28 < 0xFFFFFFFFFFFFF001LL )
                {
                  if ( *(_QWORD *)v28 )
                  {
                    v31 = *(_QWORD *)(*(_QWORD *)v28 + 16LL);
                    *(_QWORD *)(v15 + 56) = v31;
                    v30 = *(unsigned int *)(*(_QWORD *)v28 + 24LL);
                    *(_QWORD *)(v15 + 64) = v30;
                    if ( (unsigned int)v30 >= v10 )
                    {
                      *(_QWORD *)(v15 + 16) = *(_QWORD *)(v24 + 40);
                      v32 = *(_QWORD *)(v24 + 48);
                      *(_QWORD *)(v15 + 40) = v9;
                      *(_QWORD *)(v15 + 48) = v21;
                      *(_DWORD *)(v15 + 72) = a2;
                      *(_QWORD *)(v15 + 24) = v32;
                      *(_QWORD *)(v15 + 32) = v28;
LABEL_52:
                      *a5 = v31;
                      _X8 = (unsigned int *)(v15 + 80);
                      __asm { PRFM            #0x11, [X8] }
                      do
                        v48 = __ldxr(_X8);
                      while ( __stxr(v48 + 1, _X8) );
                      v14 = v49;
                      if ( v30 <= v49 )
                      {
                        printk(&unk_11C6F, "qcedev_check_and_map_buffer", v49, v30);
                        qcedev_unmap_buffer(a1, v8, v15);
                        goto LABEL_61;
                      }
                      mutex_lock(a1 + 27);
                      v37 = (__int64 *)a1[26];
                      if ( (_QWORD *)v15 == v11 || v37 == (__int64 *)v15 || (_QWORD *)*v37 != v11 )
                      {
                        _list_add_valid_or_report(v15, v37, a1 + 25);
                      }
                      else
                      {
                        a1[26] = v15;
                        *(_QWORD *)v15 = v11;
                        *(_QWORD *)(v15 + 8) = v37;
                        *v37 = v15;
                      }
                      mutex_unlock(a1 + 27);
                      goto LABEL_59;
                    }
                    v35 = v28;
                    v36 = &unk_11D82;
                  }
                  else
                  {
                    v35 = v28;
                    v36 = &unk_11B8C;
                  }
                  printk(v36, "ion_map_buffer", v29, v30);
                  dma_buf_unmap_attachment_unlocked(v9, v35, 0);
                  v34 = -12;
                }
                else
                {
                  if ( v28 )
                    v34 = v28;
                  else
                    v34 = -12;
                  printk(&unk_12360, "ion_map_buffer", v29, v30);
                }
                dma_buf_detach(v21, v9);
                LODWORD(v9) = v34;
              }
              else
              {
                printk(&unk_125E6, "ion_map_buffer", v26, v27);
                if ( !v9 )
                {
                  LODWORD(v9) = -12;
                  goto LABEL_38;
                }
              }
              dma_buf_put(v21);
              if ( (_DWORD)v9 )
                goto LABEL_39;
              v31 = *(_QWORD *)(v15 + 56);
              v30 = *(_QWORD *)(v15 + 64);
              goto LABEL_52;
            }
            v23 = &unk_12D06;
LABEL_37:
            printk(v23, "ion_map_buffer", v19, v20);
            LODWORD(v9) = -5;
LABEL_38:
            dma_buf_put(v21);
          }
        }
      }
LABEL_39:
      printk(&unk_12755, "qcedev_map_buffer", v19, v20);
      printk(&unk_1228E, "qcedev_check_and_map_buffer", a2, (unsigned int)v9);
      goto LABEL_64;
    }
  }
  while ( *((_DWORD *)v12 + 18) != a2 );
  *a5 = v12[7];
  v13 = v12[8];
  _X8 = (unsigned int *)(v12 + 10);
  __asm { PRFM            #0x11, [X8] }
  do
    v45 = __ldxr(_X8);
  while ( __stxr(v45 + 1, _X8) );
  mutex_unlock(a1 + 27);
  v14 = v49;
  if ( v13 > v49 )
  {
LABEL_59:
    LODWORD(v9) = 0;
    *a5 += v14;
  }
  else
  {
    printk(&unk_11C6F, "qcedev_check_and_map_buffer", v49, v13);
    v15 = 0;
LABEL_61:
    LODWORD(v9) = -34;
LABEL_64:
    kfree(v15);
  }
  return (unsigned int)v9;
}
