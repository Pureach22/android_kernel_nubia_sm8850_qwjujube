__int64 __fastcall mem_buf_cleanup_alloc_req(__int64 a1, unsigned int a2)
{
  char v3; // w8
  __int64 result; // x0
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x20
  __int64 v8; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v9; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_BYTE *)(a1 + 32);
  v9 = a2;
  if ( (v3 & 1) != 0 )
    goto LABEL_9;
  if ( *(_DWORD *)(a1 + 40) == a2 )
  {
    result = mem_buf_unassign_mem(*(_QWORD *)(a1 + 24), *(_QWORD *)(a1 + 72), *(unsigned int *)(a1 + 64), a2);
    if ( (result & 0x80000000) != 0 )
      goto LABEL_13;
    goto LABEL_9;
  }
  v8 = 0;
  result = _kmalloc_cache_noprof(kvfree, 3520, 8, a2);
  v5 = result;
  if ( result )
  {
    *(_DWORD *)result = 1;
    *(_WORD *)(result + 4) = 3;
    *(_BYTE *)(result + 6) = 7;
    if ( (unsigned int)mem_buf_map_mem_s2(0, &v9, result, &v8, 45) )
    {
      v6 = v5;
LABEL_12:
      result = kfree(v6);
      goto LABEL_13;
    }
    kvfree(v8);
    kfree(v5);
LABEL_9:
    mem_buf_rmt_free_mem(a1);
    if ( *(_DWORD *)(a1 + 8) == 1 )
      kfree(*(_QWORD *)(a1 + 16));
    kfree(*(_QWORD *)(a1 + 72));
    kfree(*(_QWORD *)(a1 + 80));
    v7 = *(unsigned int *)(a1 + 88);
    mutex_lock(&mem_buf_idr_mutex);
    idr_remove(&mem_buf_obj_idr, v7);
    mutex_unlock(&mem_buf_idr_mutex);
    v6 = a1;
    goto LABEL_12;
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
