__int64 __fastcall prepare_altmap(__int64 a1, __int64 *a2, __int64 a3, __int64 a4)
{
  __int64 v7; // x22
  __int64 v8; // x0
  unsigned __int64 v9; // x26
  __int64 v10; // x25
  __int64 v11; // x0
  unsigned __int64 v12; // x24
  int v13; // w0
  __int64 v14; // x8
  __int64 v15; // x1
  __int64 v16; // x2
  __int64 v17; // x3
  unsigned __int64 v18; // x0
  unsigned __int64 v19; // x2
  __int64 result; // x0
  int v21; // w8
  __int64 v22; // [xsp+0h] [xbp-60h] BYREF
  __int64 v23; // [xsp+8h] [xbp-58h]
  int *v24; // [xsp+10h] [xbp-50h]
  int *v25; // [xsp+18h] [xbp-48h]
  __int64 v26; // [xsp+20h] [xbp-40h]
  __int64 v27; // [xsp+28h] [xbp-38h]
  __int64 v28; // [xsp+30h] [xbp-30h]
  __int64 v29; // [xsp+38h] [xbp-28h]
  __int64 v30; // [xsp+40h] [xbp-20h]
  __int64 v31; // [xsp+48h] [xbp-18h]
  int v32; // [xsp+50h] [xbp-10h] BYREF
  int v33; // [xsp+54h] [xbp-Ch] BYREF
  __int64 v34; // [xsp+58h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = _kmalloc_cache_noprof(mem_buf_vmid_perm_list_to_gh_acl, 3520, 22, a4);
  if ( !v7 )
    goto LABEL_7;
  v8 = memory_block_size_bytes();
  v9 = memory_block_size_bytes() * ((a3 + v8 - 2097153) / (unsigned __int64)(v8 - 0x200000));
  v10 = (v9 >> 6) & 0x3FFFFFFFFFFFFC0LL;
  v11 = gen_pool_alloc_algo_owner(
          dmabuf_mem_pool,
          v10 + a3,
          *(_QWORD *)(dmabuf_mem_pool + 32LL),
          *(_QWORD *)(dmabuf_mem_pool + 40LL),
          0);
  if ( !v11 )
  {
    printk(&unk_9970, v10 + a3);
    kfree(v7);
LABEL_7:
    result = 4294967284LL;
    goto LABEL_10;
  }
  v12 = v11;
  *(_QWORD *)(v7 + 14) = v10;
  *(_QWORD *)(v7 + 6) = v11;
  *(_DWORD *)v7 = 1;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = nullptr;
  v26 = 0;
  v23 = 0;
  v24 = nullptr;
  v32 = 7;
  v13 = mem_buf_current_vmid();
  v14 = *(_QWORD *)(v7 + 14);
  v33 = v13;
  LODWORD(v23) = 1;
  v22 = v14;
  v24 = &v33;
  v25 = &v32;
  LODWORD(v26) = 1;
  v27 = v7;
  LODWORD(v28) = 2;
  v29 = 0;
  LODWORD(v30) = 2;
  v31 = 0;
  v18 = mem_buf_alloc((__int64)&v22, v15, v16, v17);
  v19 = v18;
  if ( v18 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_9A22, "prepare_memmap_membuf");
    goto LABEL_9;
  }
  if ( !v18 )
  {
LABEL_9:
    kfree(v7);
    result = 4294967274LL;
    goto LABEL_10;
  }
  result = 0;
  *(_QWORD *)(a1 + 216) = 0;
  *(_QWORD *)(a1 + 176) = v12 >> 12;
  v21 = *(_DWORD *)(a1 + 284);
  *(_QWORD *)(a1 + 200) = v9 >> 18;
  *(_QWORD *)(a1 + 336) = v19;
  *(_QWORD *)(a1 + 344) = v12;
  *(_DWORD *)(a1 + 284) = v21 | 1;
  *(_QWORD *)(v7 + 6) = v12 + v10;
  *(_QWORD *)(a1 + 352) = v10 + a3;
  *(_QWORD *)(v7 + 14) = a3;
  *(_DWORD *)v7 = 1;
  *a2 = v7;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
