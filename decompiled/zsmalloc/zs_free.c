__int64 __fastcall zs_free(__int64 result, __int64 *a2)
{
  __int64 v3; // x20
  __int64 lock; // x0
  __int64 v5; // x1
  __int64 v6; // x23
  unsigned int *v7; // x21
  unsigned __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x22
  __int64 v11; // x0
  unsigned int v12; // w8
  int v13; // w9
  unsigned int v14; // w10
  unsigned __int64 v15; // x11
  unsigned int **v16; // x8
  unsigned int *v17; // x9
  __int64 v18; // x12
  __int64 v19; // x1
  unsigned int *v20; // x1
  __int64 v21; // x2
  __int64 v22; // t1

  if ( !a2 || (unsigned __int64)a2 > 0xFFFFFFFFFFFFF000LL )
    return result;
  v3 = result;
  lock = raw_read_lock(result + 2120);
  v6 = *a2;
  v7 = *(unsigned int **)((((unsigned __int64)*a2 >> 18) & 0x3FFFFFFFFFC0LL)
                        - ((__int64)memstart_addr >> 12 << 6)
                        - 0x13FFFFFD8LL);
  v8 = *v7;
  if ( (v8 & 0x3FC000) != 0x160000 )
  {
LABEL_29:
    __break(0x800u);
    return obj_free(lock, v5);
  }
  v9 = (v8 >> 5) & 0x1FF;
  if ( (unsigned int)v9 >= 0xFF )
  {
LABEL_28:
    __break(0x5512u);
    goto LABEL_29;
  }
  v10 = *(_QWORD *)(v3 + 8 * v9 + 8);
  raw_spin_lock(v10);
  raw_read_unlock(v3 + 2120);
  v11 = *(unsigned int *)(v10 + 200);
  --*(_QWORD *)(v10 + 320);
  lock = obj_free(v11, v6);
  v12 = v7[1];
  if ( v12 )
  {
    v13 = *(_DWORD *)(v10 + 204);
    if ( v12 == v13 )
      v14 = 11;
    else
      v14 = (int)(100 * v12) / v13 / 10 + 1;
  }
  else
  {
    v14 = 0;
  }
  v15 = ((unsigned __int64)*v7 >> 1) & 0xF;
  if ( v14 != (_DWORD)v15 )
  {
    v16 = *((unsigned int ***)v7 + 4);
    v17 = v7 + 6;
    if ( *v16 == v7 + 6 && (v18 = *(_QWORD *)v17, *(unsigned int **)(*(_QWORD *)v17 + 8LL) == v17) )
    {
      *(_QWORD *)(v18 + 8) = v16;
      *v16 = (unsigned int *)v18;
    }
    else
    {
      lock = _list_del_entry_valid_or_report(v7 + 6);
    }
    *((_QWORD *)v7 + 3) = v7 + 6;
    *((_QWORD *)v7 + 4) = v17;
    if ( (unsigned int)v15 < 0xE )
    {
      --*(_QWORD *)(v10 + 216 + 8 * v15);
      if ( v14 < 0xE )
      {
        ++*(_QWORD *)(v10 + 216 + 8LL * v14);
        if ( v14 != 13 )
        {
          v19 = v10 + 16LL * v14;
          v22 = *(_QWORD *)(v19 + 8);
          v20 = (unsigned int *)(v19 + 8);
          v21 = v22;
          if ( *(unsigned int **)(v22 + 8) != v20 || v17 == v20 || (unsigned int *)v21 == v17 )
          {
            _list_add_valid_or_report(v17);
          }
          else
          {
            *(_QWORD *)(v21 + 8) = v17;
            *((_QWORD *)v7 + 3) = v21;
            *((_QWORD *)v7 + 4) = v20;
            *(_QWORD *)v20 = v17;
          }
          *v7 = *v7 & 0xFFFFFFE1 | (2 * v14);
          goto LABEL_22;
        }
      }
    }
    goto LABEL_28;
  }
LABEL_22:
  if ( !v14 )
    ((void (__fastcall *)(__int64, __int64, unsigned int *))free_zspage)(v3, v10, v7);
  raw_spin_unlock(v10);
  return kmem_cache_free(*(_QWORD *)(v3 + 2048), a2);
}
