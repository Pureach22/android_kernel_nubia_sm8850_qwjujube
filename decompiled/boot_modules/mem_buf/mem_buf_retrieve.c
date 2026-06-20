__int64 __fastcall mem_buf_retrieve(unsigned int *a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v4; // w8
  __int64 result; // x0
  __int64 v7; // x19
  unsigned int *v8; // x0
  unsigned int *v9; // x20
  int v10; // w22
  __int64 v11; // x9
  __int64 v12; // x4
  _BYTE *v13; // x10
  __int64 v14; // x11
  unsigned int v15; // w21
  _BYTE *v16; // x10
  __int64 v17; // x0
  __int64 v18; // x23
  unsigned __int64 sgl_buf_size; // x22
  __int64 v20; // x0
  __int64 v21; // x3
  __int64 v22; // x25
  _DWORD *v23; // x0
  __int64 v24; // x0
  __int64 v25; // x1
  _DWORD *v26; // x8
  __int64 v27; // x10
  _DWORD *v28; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v29[2]; // [xsp+10h] [xbp-10h] BYREF

  v29[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a1[7];
  v28 = nullptr;
  if ( (v4 & 0xFFF7FFFC) == 0 && a1[1] && *((_QWORD *)a1 + 1) && *((_QWORD *)a1 + 2) )
  {
    v7 = _kmalloc_cache_noprof(_cpu_online_mask, 3520, 360, a4);
    if ( !v7 )
    {
      result = -12;
      goto LABEL_3;
    }
    v8 = (unsigned int *)mem_buf_vmid_perm_list_to_gh_acl(*((_QWORD *)a1 + 1), *((_QWORD *)a1 + 2), a1[1]);
    v9 = v8;
    if ( (unsigned __int64)v8 >= 0xFFFFFFFFFFFFF001LL )
    {
      v10 = (int)v8;
LABEL_41:
      kfree(v7);
      result = v10;
      goto LABEL_3;
    }
    v11 = *v8;
    v12 = *a1;
    if ( (_DWORD)v11 )
    {
      v13 = (char *)v8 + 6;
      v14 = *v8;
      do
      {
        if ( (_DWORD)v12 == *((unsigned __int16 *)v13 - 1) && *v13 )
        {
          v15 = 2;
          goto LABEL_17;
        }
        --v14;
        v13 += 4;
      }
      while ( v14 );
      v15 = 1;
LABEL_17:
      v16 = (char *)v8 + 6;
      while ( (_DWORD)v12 != *((unsigned __int16 *)v16 - 1) || !*v16 )
      {
        --v11;
        v16 += 4;
        if ( !v11 )
          goto LABEL_23;
      }
      v17 = 2;
    }
    else
    {
      v15 = 1;
LABEL_23:
      v17 = 1;
    }
    v29[0] = 0;
    if ( (unsigned int)mem_buf_map_mem_s2(v17, a1 + 6, v9, v29, v12) )
    {
      v18 = 0;
      sgl_buf_size = 0;
    }
    else
    {
      sgl_buf_size = mem_buf_get_sgl_buf_size(v29[0]);
      if ( (unsigned int)mem_buf_unmap_mem_s2(a1[6]) )
        printk(&unk_9D43, a1[6]);
      v18 = v29[0];
      v28 = (_DWORD *)v29[0];
    }
    v20 = ((__int64 (*)(void))memory_block_size_bytes)();
    memory_block_size_bytes(v20);
    kvfree(v18);
    v22 = 0;
    v28 = nullptr;
    if ( sgl_buf_size >> 27 && dmabuf_mem_pool )
    {
      v10 = prepare_altmap(v7, (__int64 *)&v28, sgl_buf_size, v21);
      if ( v10 )
      {
LABEL_40:
        kfree(v9);
        goto LABEL_41;
      }
      v22 = *(_QWORD *)(v7 + 176) << 12;
    }
    v10 = mem_buf_map_mem_s2(v15, a1 + 6, v9, &v28, *a1);
    if ( v10 )
    {
      v23 = v28;
      if ( !v28 )
      {
LABEL_36:
        v24 = *(_QWORD *)(v7 + 336);
        if ( v24 )
          mem_buf_free(v24);
        v25 = *(_QWORD *)(v7 + 344);
        if ( v25 )
          gen_pool_free_owner(dmabuf_mem_pool, v25, *(_QWORD *)(v7 + 352), 0);
        goto LABEL_40;
      }
    }
    else
    {
      v26 = v28;
      if ( *v28 == 1 )
      {
        v27 = *(_QWORD *)(v7 + 336);
        *(_DWORD *)(v7 + 280) = 4;
        *(_DWORD *)(v7 + 312) = 1;
        if ( !v27 )
          v22 = *(_QWORD *)((char *)v26 + 6);
        *(_QWORD *)(v7 + 320) = v22;
        *(_QWORD *)(v7 + 328) = *(_QWORD *)((char *)v26 + 6) + *(_QWORD *)((char *)v26 + 14) - 1LL;
        printk(&unk_9A9C, 4294967274LL);
      }
      else
      {
        printk(&unk_9E5E, "mem_buf_retrieve");
      }
      mem_buf_unmap_mem_s2(a1[6]);
      v10 = -22;
      v23 = v28;
      if ( !v28 )
        goto LABEL_36;
    }
    kvfree(v23);
    goto LABEL_36;
  }
  result = -22;
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
