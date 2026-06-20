__int64 __fastcall mem_buf_alloc(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  _QWORD *v6; // x0
  __int64 v7; // x8
  __int64 v8; // x2
  _QWORD *v9; // x19
  unsigned __int64 v10; // x20
  unsigned __int64 v11; // x0
  __int64 v12; // x9
  int v13; // w10
  int v14; // w8
  _QWORD *v15; // x21
  _QWORD *v16; // x22
  int v17; // w0
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 7;
  if ( (mem_buf_capability & 2) != 0 )
  {
    if ( !a1
      || !*(_QWORD *)a1
      || *(_DWORD *)(a1 + 8) != 1
      || !*(_QWORD *)(a1 + 16)
      || !*(_QWORD *)(a1 + 24)
      || (unsigned int)(*(_DWORD *)(a1 + 48) - 1) > 1
      || (unsigned int)(*(_DWORD *)(a1 + 64) - 1) > 1 )
    {
      result = -22;
      goto LABEL_14;
    }
    v6 = (_QWORD *)_kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 96, a4);
    if ( !v6 )
    {
      result = -12;
      goto LABEL_14;
    }
    v7 = *(_QWORD *)(a1 + 16);
    v8 = *(unsigned int *)(a1 + 8);
    v9 = v6;
    *v6 = *(_QWORD *)a1;
    v10 = mem_buf_vmid_perm_list_to_gh_acl(v7, &v18, v8);
    v11 = (unsigned __int64)v9;
    v9[1] = v10;
    if ( v10 >= 0xFFFFFFFFFFFFF001LL )
    {
LABEL_39:
      kfree(v11);
      result = (int)v10;
      goto LABEL_14;
    }
    v12 = a1;
    if ( *(_QWORD *)(a1 + 40) )
    {
      v10 = dup_gh_sgl_desc(*(_QWORD *)(a1 + 40));
      v12 = a1;
      v11 = (unsigned __int64)v9;
      v9[2] = v10;
      if ( v10 >= 0xFFFFFFFFFFFFF001LL )
      {
LABEL_38:
        kfree(*(_QWORD *)(v11 + 8));
        v11 = (unsigned __int64)v9;
        goto LABEL_39;
      }
    }
    v13 = *(_DWORD *)(v12 + 48);
    v14 = *(_DWORD *)(v12 + 64);
    *(_DWORD *)(v11 + 28) = *(_DWORD *)(v12 + 32);
    *(_DWORD *)(v11 + 32) = v13;
    *(_DWORD *)(v11 + 48) = v14;
    if ( v13 == 1 )
    {
      v10 = kstrdup(*(_QWORD *)(v12 + 56), 3264);
      v11 = (unsigned __int64)v9;
      v9[5] = v10;
      v15 = v9 + 5;
      if ( v10 <= 0xFFFFFFFFFFFFF000LL )
      {
        v14 = *(_DWORD *)(a1 + 64);
        v12 = a1;
LABEL_22:
        if ( v14 == 1 )
        {
          v10 = kstrdup(*(_QWORD *)(v12 + 72), 3264);
          v11 = (unsigned __int64)v9;
          v9[7] = v10;
          v16 = v9 + 7;
          if ( v10 < 0xFFFFFFFFFFFFF001LL )
            goto LABEL_27;
        }
        else
        {
          if ( v14 == 2 )
          {
            *(_QWORD *)(v11 + 56) = 0;
            v16 = (_QWORD *)(v11 + 56);
LABEL_27:
            v10 = v11;
            trace_mem_buf_alloc_info(
              *(_QWORD *)v11,
              *(unsigned int *)(v11 + 32),
              *(unsigned int *)(v11 + 48),
              *(_QWORD *)(v11 + 8));
            LODWORD(v10) = mem_buf_request_mem(v10);
            if ( !(_DWORD)v10 )
            {
              v17 = mem_buf_map_mem_s2(*((unsigned int *)v9 + 7), v9 + 3, v9[1], v9 + 2, 3);
              if ( !v17 )
              {
                mutex_lock(&mem_buf_list_lock);
                _list_add(v9 + 9, off_428);
                mutex_unlock(&mem_buf_list_lock);
                result = (__int64)v9;
                goto LABEL_14;
              }
              LODWORD(v10) = v17;
              mem_buf_relinquish_mem(v9);
            }
            if ( *((_DWORD *)v9 + 12) == 1 )
              kfree(*v16);
            v11 = (unsigned __int64)v9;
            goto LABEL_34;
          }
          LODWORD(v10) = -22;
          *(_QWORD *)(v11 + 56) = -22;
        }
LABEL_34:
        if ( *(_DWORD *)(v11 + 32) == 1 )
        {
          kfree(*v15);
          v11 = (unsigned __int64)v9;
        }
      }
    }
    else
    {
      if ( v13 == 2 )
      {
        *(_QWORD *)(v11 + 40) = 0;
        v15 = (_QWORD *)(v11 + 40);
        goto LABEL_22;
      }
      LODWORD(v10) = -22;
      *(_QWORD *)(v11 + 40) = -22;
    }
    if ( *(_QWORD *)(v11 + 16) )
    {
      kvfree(*(_QWORD *)(v11 + 16));
      v11 = (unsigned __int64)v9;
    }
    goto LABEL_38;
  }
  result = -95;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
