__int64 __fastcall msm_vidc_get_sw_fence(__int64 a1, __int64 a2, int a3, int a4, unsigned int a5)
{
  __int64 v10; // x0
  __int64 v11; // x4
  __int64 v12; // x19
  __int64 v13; // x8
  __int64 v14; // x25
  __int64 v15; // x8
  __int64 fence; // x0
  __int64 *v17; // x8
  __int64 v18; // x3
  __int64 v19; // x8
  __int64 v20; // x22
  __int64 *v21; // x1

  v10 = vzalloc_noprof(280);
  v12 = v10;
  if ( !v10 )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_92E2A, "err ", a1 + 340, "msm_vidc_get_sw_fence", v11);
    return 0;
  }
  v13 = *(_QWORD *)(a2 + 136);
  v14 = v13 + 1;
  if ( (unsigned __int64)(v13 + 1) <= 0x7FFFFFFE )
    v15 = v13 + 1;
  else
    v15 = 0;
  *(_QWORD *)(a2 + 136) = v15;
  if ( a5 == -1 )
  {
    v18 = *(_QWORD *)(a2 + 128);
    *(_DWORD *)(v10 + 248) = 0;
    dma_fence_init(v10 + 184, &msm_vidc_dma_fence_ops, v10 + 248, v18, v14);
    fence = 0;
    v17 = (__int64 *)(v12 + 224);
    goto LABEL_9;
  }
  fence = sync_file_get_fence(a5);
  if ( !fence )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_86B5F, "err ", a1 + 340, "msm_vidc_get_sw_fence", a5);
    vfree(v12);
    return 0;
  }
  v17 = (__int64 *)(fence + 40);
LABEL_9:
  v19 = *v17;
  *(_QWORD *)(v12 + 264) = fence;
  *(_QWORD *)(v12 + 272) = a2;
  *(_DWORD *)(v12 + 148) = a4;
  *(_DWORD *)(v12 + 152) = a5;
  *(_QWORD *)(v12 + 160) = v19;
  *(_QWORD *)(v12 + 168) = v14;
  v20 = a2 + 144;
  *(_DWORD *)(v12 + 144) = a3;
  *(_QWORD *)(v12 + 256) = 0;
  *(_QWORD *)(v12 + 176) = 0;
  snprintf(
    (char *)(v12 + 16),
    0x80u,
    "%s%sfence: %s: %s: fd %3d id %10llu mid %5llu f.no %5llu",
    (const char *)&unk_84D69,
    (const char *)&unk_84D69,
    (const char *)a2,
    "sw",
    a5,
    v19,
    v19 & 0x7FFFFFFF,
    v14);
  *(_QWORD *)v12 = v12;
  *(_QWORD *)(v12 + 8) = v12;
  v21 = *(__int64 **)(a2 + 152);
  if ( v12 == a2 + 144 || v21 == (__int64 *)v12 || *v21 != v20 )
  {
    _list_add_valid_or_report(v12);
  }
  else
  {
    *(_QWORD *)(a2 + 152) = v12;
    *(_QWORD *)v12 = v20;
    *(_QWORD *)(v12 + 8) = v21;
    *v21 = v12;
  }
  return v12;
}
