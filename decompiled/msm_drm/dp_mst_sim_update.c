__int64 __fastcall dp_mst_sim_update(__int64 a1, unsigned int a2, __int64 a3)
{
  unsigned int v3; // w22
  size_t v4; // x21
  int v7; // w8
  int v8; // w23
  __int64 v9; // x8
  unsigned __int8 *v10; // x11
  unsigned __int8 *v11; // x10
  unsigned __int64 v12; // x22
  __int64 v13; // x24
  __int64 v14; // x0
  __int64 v15; // x24
  __int64 v16; // x25
  __int64 v17; // x28
  __int64 v18; // x9
  _QWORD *v19; // x8
  __int64 v20; // x9
  __int64 v21; // x11
  __int64 v22; // x12
  void *v23; // x0
  void *v24; // x22
  size_t v25; // x2
  unsigned __int64 StatusReg; // x22
  __int64 v27; // x24
  __int64 v28; // x0
  unsigned __int64 v29; // x20
  __int64 v30; // x21
  __int64 v31; // x0
  __int64 v32; // x1

  v3 = -22;
  if ( a1 )
  {
    LODWORD(v4) = a2;
    if ( a2 <= 0xE )
    {
      if ( a3 )
      {
        mutex_lock(a1 + 688);
        v7 = *(_DWORD *)(a1 + 32);
        v8 = 0;
        if ( (_DWORD)v4 && v7 == (_DWORD)v4 )
        {
          v9 = 0;
          v8 = 0;
          v10 = (unsigned __int8 *)(a3 + 2);
          v11 = (unsigned __int8 *)(*(_QWORD *)(a1 + 24) + 2LL);
          do
          {
            if ( v10[1] != v11[1]
              || *(v10 - 2) != *(v11 - 2)
              || v10[2] != v11[2]
              || *v10 != *v11
              || *(v10 - 1) != *(v11 - 1) )
            {
              v8 |= 1 << v9;
            }
            ++v9;
            v11 += 48;
            v10 += 48;
          }
          while ( (unsigned int)v4 != v9 );
          v7 = 1;
        }
        if ( v7 )
        {
          v12 = 0;
          v13 = 32;
          do
          {
            kfree(*(_QWORD *)(*(_QWORD *)(a1 + 24) + v13));
            ++v12;
            v13 += 48;
          }
          while ( v12 < *(unsigned int *)(a1 + 32) );
        }
        kfree(*(_QWORD *)(a1 + 24));
        *(_QWORD *)(a1 + 24) = 0;
        *(_DWORD *)(a1 + 32) = 0;
        if ( (_DWORD)v4 )
        {
          v14 = _kmalloc_noprof((unsigned int)(48 * v4), 3520);
          *(_QWORD *)(a1 + 24) = v14;
          if ( v14 )
          {
LABEL_20:
            v15 = 0;
            v16 = (unsigned int)v4;
            *(_DWORD *)(a1 + 32) = v4;
            _ReadStatusReg(SP_EL0);
            while ( 1 )
            {
              v17 = a3 + v15;
              v18 = *(_QWORD *)(a3 + v15 + 8);
              v19 = (_QWORD *)(*(_QWORD *)(a1 + 24) + v15);
              *v19 = *(_QWORD *)(a3 + v15);
              v19[1] = v18;
              v20 = *(_QWORD *)(a3 + v15 + 40);
              v21 = *(_QWORD *)(a3 + v15 + 16);
              v22 = *(_QWORD *)(a3 + v15 + 24);
              v19[4] = *(_QWORD *)(a3 + v15 + 32);
              v19[5] = v20;
              v19[2] = v21;
              v19[3] = v22;
              if ( *(_DWORD *)(a3 + v15 + 40) )
              {
                if ( !*(_QWORD *)(v17 + 32) )
                {
                  v3 = -22;
                  if ( *(_DWORD *)(a1 + 32) )
                    goto LABEL_32;
                  goto LABEL_34;
                }
                v4 = *(unsigned int *)(v17 + 40);
                v23 = (void *)_kmalloc_noprof(v4, 3520);
                v24 = v23;
                if ( !v23 )
                  break;
                v25 = *(unsigned int *)(v17 + 40);
                if ( v4 < v25 )
                {
                  _fortify_panic(17, v4, v25);
                  StatusReg = _ReadStatusReg(SP_EL0);
                  v27 = *(_QWORD *)(StatusReg + 80);
                  *(_QWORD *)(StatusReg + 80) = &dp_mst_sim_update__alloc_tag;
                  v28 = _kmalloc_noprof((unsigned int)(48 * v4), 3520);
                  *(_QWORD *)(StatusReg + 80) = v27;
                  *(_QWORD *)(a1 + 24) = v28;
                  if ( v28 )
                    goto LABEL_20;
                  break;
                }
                memcpy(v23, *(const void **)(v17 + 32), v25);
                *(_QWORD *)(*(_QWORD *)(a1 + 24) + v15 + 32) = v24;
              }
              --v16;
              v15 += 48;
              if ( !v16 )
                goto LABEL_27;
            }
          }
          v3 = -12;
          if ( *(_DWORD *)(a1 + 32) )
          {
LABEL_32:
            v29 = 0;
            v30 = 32;
            do
            {
              kfree(*(_QWORD *)(*(_QWORD *)(a1 + 24) + v30));
              ++v29;
              v30 += 48;
            }
            while ( v29 < *(unsigned int *)(a1 + 32) );
          }
LABEL_34:
          kfree(*(_QWORD *)(a1 + 24));
          *(_QWORD *)(a1 + 24) = 0;
          *(_DWORD *)(a1 + 32) = 0;
        }
        else
        {
LABEL_27:
          v3 = 0;
        }
        mutex_unlock(a1 + 688);
        if ( v8 )
        {
          v31 = _kmalloc_cache_noprof(_drm_debug, 3520, 48);
          if ( v31 )
          {
            *(_DWORD *)(v31 + 40) = v8;
            *(_QWORD *)v31 = 0xFFFFFFFE00000LL;
            *(_QWORD *)(v31 + 8) = v31 + 8;
            *(_QWORD *)(v31 + 16) = v31 + 8;
            v32 = *(_QWORD *)(a1 + 768);
            *(_QWORD *)(v31 + 24) = dp_mst_sim_up_req_work;
            *(_QWORD *)(v31 + 32) = a1;
            queue_work_on(32, v32, v31);
          }
        }
      }
    }
  }
  return v3;
}
