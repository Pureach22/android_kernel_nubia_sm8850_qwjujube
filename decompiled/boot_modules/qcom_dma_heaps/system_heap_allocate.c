__int64 __fastcall system_heap_allocate(__int64 a1, __int64 a2, int a3)
{
  __int64 v6; // x21
  int v7; // w0
  int v8; // w22
  unsigned __int64 v9; // x0
  __int64 name; // x0
  __int64 v11; // x8
  unsigned __int64 v12; // x0
  __int64 result; // x0
  unsigned __int64 v14; // x19
  _QWORD v15[3]; // [xsp+0h] [xbp-50h] BYREF
  __int64 v16; // [xsp+18h] [xbp-38h]
  __int64 v17; // [xsp+20h] [xbp-30h]
  __int64 v18; // [xsp+28h] [xbp-28h]
  __int64 v19; // [xsp+30h] [xbp-20h]
  __int64 v20; // [xsp+38h] [xbp-18h]
  __int64 v21; // [xsp+40h] [xbp-10h]
  __int64 v22; // [xsp+48h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v15[2] = 0;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  v15[0] = "qcom_dma_heaps";
  v15[1] = &_this_module;
  v6 = _kmalloc_cache_noprof(of_get_next_available_child, 3520, 176);
  if ( !v6 )
  {
    result = -12;
    goto LABEL_11;
  }
  v7 = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))system_qcom_sg_buffer_alloc)(a1, v6, a2, 0);
  if ( v7 )
  {
    v8 = v7;
    kfree(v6);
  }
  else
  {
    v9 = mem_buf_vmperm_alloc(v6 + 80, qcom_sg_release, v6 + 168);
    v8 = v9;
    *(_QWORD *)(v6 + 120) = v9;
    if ( v9 <= 0xFFFFFFFFFFFFF000LL )
    {
      name = dma_heap_get_name(a1);
      v11 = *(_QWORD *)(v6 + 72);
      v15[0] = name;
      LODWORD(v17) = a3;
      v16 = v11;
      v19 = v6;
      v12 = mem_buf_dma_buf_export(v15, qcom_sg_buf_ops);
      if ( v12 <= 0xFFFFFFFFFFFFF000LL )
      {
        v14 = v12;
        qcom_store_dma_buf_fops(*(_QWORD *)(v12 + 8));
        result = v14;
        goto LABEL_11;
      }
      v8 = v12;
      mem_buf_vmperm_free(*(_QWORD *)(v6 + 120));
    }
    deferred_free(v6 + 128, system_heap_deferred_free, (unsigned __int64)(*(_QWORD *)(v6 + 72) + 4095LL) >> 12);
  }
  result = v8;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
