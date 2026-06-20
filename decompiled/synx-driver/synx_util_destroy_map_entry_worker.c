__int64 __fastcall synx_util_destroy_map_entry_worker(__int64 a1)
{
  __int64 v2; // x19
  unsigned __int64 v3; // x21
  __int64 v4; // x22
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x4
  __int64 v9; // x5
  unsigned int object_status; // w23
  __int64 v11; // x1
  __int64 v12; // x2
  __int64 v13; // x3
  __int64 v14; // x4
  __int64 v15; // x5
  unsigned int v16; // w0
  unsigned int status; // w0
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 v20; // x4
  __int64 v21; // x5
  unsigned int v22; // w23
  __int64 v23; // x1
  __int64 v24; // x2
  __int64 v25; // x3
  __int64 v26; // x4
  __int64 v27; // x5
  __int64 v28; // x5
  __int64 v29; // x2
  __int64 v30; // x3
  __int64 v31; // x4
  __int64 v32; // x5
  __int64 v33; // x23
  unsigned __int64 v34; // x0
  int v35; // w0
  __int64 v36; // x2
  __int64 v37; // x3
  __int64 v38; // x4
  __int64 v39; // x5
  __int64 v40; // x1
  __int64 v41; // x2
  __int64 v42; // x3
  __int64 v43; // x4
  __int64 v44; // x5
  __int64 v45; // x1
  __int64 v46; // x2
  __int64 v47; // x3
  __int64 v48; // x4
  __int64 v49; // x5
  __int64 v50; // x1
  __int64 v51; // x2
  __int64 v52; // x3
  __int64 v53; // x4
  __int64 v54; // x5
  int v55; // w8
  __int64 v56; // x9
  __int64 v57; // x8
  __int64 result; // x0
  unsigned __int64 v65; // x10
  int v66; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v67; // [xsp+8h] [xbp-8h]

  v67 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1 - 24;
  v3 = *(_QWORD *)(a1 - 24);
  if ( v3 && v3 <= 0xFFFFFFFFFFFFF000LL )
  {
    v66 = 0;
    mutex_lock(v3 + 72);
    v4 = *(_QWORD *)(v3 + 352);
    --*(_DWORD *)(v3 + 348);
    object_status = synx_util_get_object_status(v3, v5, v6, v7, v8, v9);
    if ( (synx_debug & 0x10) != 0 )
      printk(&unk_278E0, "verb", "synx_util_cleanup_fence", 1119, object_status, v4);
    dma_fence_enable_sw_signaling(*(_QWORD *)(v3 + 64));
    if ( *(_DWORD *)(v3 + 348) || !v4 )
      goto LABEL_25;
    v16 = *(_DWORD *)(v3 + 344);
    if ( !v16 || object_status != 1 )
    {
      if ( object_status == 1 && (dma_fence_remove_callback(*(_QWORD *)(v3 + 64), v4 + 32) & 1) != 0 )
      {
        kfree(v4);
        *(_QWORD *)(v3 + 352) = 0;
        synx_util_put_object(v3, v23, v24, v25, v26, v27);
        if ( (synx_debug & 0x80) != 0 )
          printk(&unk_25714, &unk_25D36, "synx_util_cleanup_fence", 1178, *(_QWORD *)(v3 + 352), v28);
      }
      goto LABEL_25;
    }
    status = synx_global_get_status(v16, v11, v12, v13, v14, v15);
    if ( status < 2 )
    {
      v33 = raw_spin_lock_irqsave(**(_QWORD **)(v3 + 64));
      v34 = *(_QWORD *)(v3 + 64);
      if ( (*(_BYTE *)(v3 + 124) & 0x20) != 0 )
        v35 = _fence_group_state(v34, 1, v29, v30, v31, v32);
      else
        v35 = _fence_state(v34, 1, v29, v30, v31, v32);
      if ( v35 == 1 )
      {
        *(_QWORD *)(v4 + 16) = 0;
        synx_global_fetch_handle_details(*(_DWORD *)(v3 + 344), &v66, v36, v37, v38, v39);
        *(_DWORD *)v4 = v66;
        *(_QWORD *)(v3 + 352) = 0;
        synx_util_put_object(v3, v40, v41, v42, v43, v44);
        synx_global_get_ref(*(_DWORD *)(v3 + 344), v45, v46, v47, v48, v49);
      }
      raw_spin_unlock_irqrestore(**(_QWORD **)(v3 + 64), v33);
      goto LABEL_25;
    }
    v22 = status;
    if ( (synx_debug & 8) != 0 )
    {
      printk(&unk_2A4F2, &unk_2A972, "synx_util_cleanup_fence", 1144, *(_QWORD *)(v3 + 64), status);
      if ( (*(_BYTE *)(v3 + 124) & 0x20) == 0 )
        goto LABEL_12;
    }
    else if ( (*(_BYTE *)(v3 + 124) & 0x20) == 0 )
    {
LABEL_12:
      synx_native_signal_fence(v3, v22, v18, v19, v20, v21);
LABEL_25:
      mutex_unlock(v3 + 72);
      synx_util_put_object(v3, v50, v51, v52, v53, v54);
      goto LABEL_26;
    }
    synx_native_signal_merged_fence(v3);
    goto LABEL_25;
  }
LABEL_26:
  v55 = *(_DWORD *)(a1 - 8);
  if ( (v55 & 0x100000) != 0 )
  {
    if ( (synx_debug & 0x10) != 0 )
LABEL_32:
      printk(&unk_28064, "verb", "synx_util_destroy_map_entry_worker", 1202, *(unsigned int *)(a1 - 8), a1 - 24);
  }
  else
  {
    v56 = (unsigned __int16)v55 >> 6;
    v57 = 1LL << v55;
    _X9 = (unsigned __int64 *)(*(_QWORD *)(synx_dev + 152) + 22568LL + 8 * v56);
    __asm { PRFM            #0x11, [X9] }
    do
      v65 = __ldxr(_X9);
    while ( __stxr(v65 & ~v57, _X9) );
    if ( (synx_debug & 0x10) != 0 )
      goto LABEL_32;
  }
  result = kfree(v2);
  _ReadStatusReg(SP_EL0);
  return result;
}
