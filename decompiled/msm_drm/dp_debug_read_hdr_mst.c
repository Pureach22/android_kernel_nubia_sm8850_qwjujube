__int64 __fastcall dp_debug_read_hdr_mst(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x21
  __int64 v8; // x0
  __int64 v9; // x23
  __int64 result; // x0
  unsigned __int64 v11; // x21
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 ipc_log_context; // x0
  unsigned int v15; // w0
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x22
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v19; // x10
  unsigned __int64 v20; // x9
  __int64 v21; // x0
  unsigned __int64 v22; // x9
  unsigned __int64 v28; // x8
  unsigned __int64 v29; // x8
  unsigned __int64 v31; // x10
  _QWORD v32[3]; // [xsp+8h] [xbp-18h] BYREF

  v32[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v32[0] = 0;
  v32[1] = 0;
  if ( v4 )
  {
    drm_connector_list_iter_begin(***(_QWORD ***)(v4 + 144), v32);
    do
    {
      v8 = drm_connector_list_iter_next(v32);
      if ( !v8 )
      {
        v13 = drm_connector_list_iter_end(v32);
        ipc_log_context = get_ipc_log_context(v13);
        ipc_log_string(
          ipc_log_context,
          "[e][%-4d]connector %u not in mst list\n",
          *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
          *(_DWORD *)(v4 + 16));
        printk(&unk_26BA2F, "dp_debug_read_hdr_mst");
        result = -22;
        goto LABEL_24;
      }
    }
    while ( *(_DWORD *)(v8 + 64) != *(_DWORD *)(v4 + 16) );
    v9 = v8;
    drm_connector_list_iter_end(v32);
    if ( *a4 )
    {
      result = 0;
      goto LABEL_24;
    }
    v11 = _kmalloc_cache_noprof(kthread_park, 3520, 4096);
    if ( v11 < 0x11 )
    {
      result = -12;
      goto LABEL_24;
    }
    v15 = ((__int64 (__fastcall *)(__int64, unsigned __int64))dp_debug_print_hdr_params_to_buf)(v9, v11);
    if ( v15 == -75 )
    {
      kfree(v11);
      result = 4294967221LL;
    }
    else
    {
      v16 = v15;
      if ( v15 >= a3 )
        v16 = a3;
      v17 = v16;
      if ( v16 > 0x1000 )
      {
        _copy_overflow(4096, v16);
      }
      else
      {
        _check_object_size(v11, v16, 1);
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v19 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v19 = a2 & ((__int64)(a2 << 8) >> 8);
        v20 = v17;
        v21 = v17;
        if ( 0x8000000000LL - v17 >= v19 )
        {
          v22 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v28 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v28 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v28);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v22);
          v21 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
          v20 = v17;
          v29 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v31 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v31 - 4096);
          _WriteStatusReg(TTBR1_EL1, v31);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v29);
        }
        if ( !v21 )
        {
          *a4 += v20;
          kfree(v11);
          result = v17;
          goto LABEL_24;
        }
      }
      kfree(v11);
      result = -14;
    }
  }
  else
  {
    v12 = get_ipc_log_context(a1);
    ipc_log_string(v12, "[e][%-4d]invalid data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_245274, "dp_debug_read_hdr_mst");
    result = -19;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
