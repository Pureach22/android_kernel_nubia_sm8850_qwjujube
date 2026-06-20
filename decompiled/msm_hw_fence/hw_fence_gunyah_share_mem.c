__int64 __fastcall hw_fence_gunyah_share_mem(
        __int64 a1,
        unsigned __int16 a2,
        unsigned __int16 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v6; // x30
  __int64 v10; // x0
  __int64 v11; // x20
  __int64 v12; // x8
  unsigned int v13; // w0
  __int64 v14; // x21
  __int64 v15; // x24
  __int64 v16; // x2
  __int64 v17; // x8
  __int64 v18; // x10
  int v19; // w0
  int v20; // w8
  unsigned int v21; // w19
  __int64 result; // x0
  __int64 v23; // x5
  __int64 v24; // [xsp+0h] [xbp-30h] BYREF
  __int64 v25; // [xsp+8h] [xbp-28h] BYREF
  _DWORD v26[4]; // [xsp+10h] [xbp-20h] BYREF
  _DWORD v27[2]; // [xsp+20h] [xbp-10h] BYREF
  __int64 v28; // [xsp+28h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27[0] = a2;
  v27[1] = 7;
  v10 = *(_QWORD *)(a1 + 320);
  v26[0] = a2;
  v26[1] = 6;
  v26[2] = a3;
  v26[3] = 6;
  v11 = v6;
  v12 = *(_QWORD *)(a1 + 328) - v10;
  v24 = (1LL << a3) | (1LL << a2);
  v25 = 1LL << a2;
  v13 = qcom_scm_assign_mem(v10, v12 + 1, &v25, v26, 2, a6);
  if ( !v13 )
  {
    v14 = _kmalloc_cache_noprof(usleep_range_state, 3520, 12);
    if ( v14 )
    {
      v15 = _kmalloc_cache_noprof(dma_fence_init, 3520, 22);
      if ( v15 )
      {
        v16 = *(unsigned int *)(a1 + 424);
        *(_DWORD *)v14 = 2;
        v17 = *(_QWORD *)(a1 + 320);
        v18 = *(_QWORD *)(a1 + 328);
        *(_BYTE *)(v14 + 6) = 6;
        *(_BYTE *)(v14 + 10) = 6;
        *(_DWORD *)v15 = 1;
        *(_QWORD *)(v15 + 6) = v17;
        *(_WORD *)(v14 + 4) = a2;
        *(_WORD *)(v14 + 8) = a3;
        *(_QWORD *)(v15 + 14) = v18 - v17 + 1;
        v19 = ghd_rm_mem_share(0, 0, v16, v14, v15, 0, a1 + 456);
        v20 = 0;
        if ( v19 )
        {
          printk(&unk_245ED, "hw_fence_gunyah_share_mem", 1114, v11, "hw_fence_gunyah_share_mem");
          qcom_scm_assign_mem(
            *(_QWORD *)(a1 + 320),
            *(_QWORD *)(a1 + 328) - *(_QWORD *)(a1 + 320) + 1LL,
            &v24,
            v27,
            1,
            v23);
          v20 = -517;
        }
        v21 = v20;
        kfree(v14);
        kfree(v15);
        goto LABEL_7;
      }
      kfree(v14);
    }
    result = 4294967284LL;
    goto LABEL_11;
  }
  v21 = v13;
  printk(&unk_26D8F, "hw_fence_gunyah_share_mem", 1083, v11, "hw_fence_gunyah_share_mem");
LABEL_7:
  result = v21;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
