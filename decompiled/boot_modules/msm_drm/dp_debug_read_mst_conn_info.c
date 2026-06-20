unsigned __int64 __fastcall dp_debug_read_mst_conn_info(
        __int64 a1,
        unsigned __int64 a2,
        unsigned __int64 a3,
        _QWORD *a4)
{
  __int64 v4; // x24
  unsigned __int64 v6; // x21
  __int64 v10; // x20
  __int64 v11; // x0
  unsigned int v12; // w25
  int v13; // w27
  __int64 v14; // x0
  __int64 ipc_log_context; // x0
  __int64 v16; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v18; // x9
  __int64 v19; // x0
  unsigned __int64 v20; // x9
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x8
  unsigned __int64 v29; // x9
  _QWORD v30[3]; // [xsp+8h] [xbp-18h] BYREF

  v30[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v30[0] = 0;
  v30[1] = 0;
  if ( !v4 )
  {
    ipc_log_context = get_ipc_log_context(a1);
    ipc_log_string(ipc_log_context, "[e][%-4d]invalid data\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_245274, "dp_debug_read_mst_conn_info");
    v6 = -19;
    goto LABEL_4;
  }
  if ( *a4 )
  {
    v6 = 0;
    goto LABEL_4;
  }
  v10 = _kmalloc_cache_noprof(kthread_park, 3520, 4096);
  if ( !v10 )
  {
    v6 = -12;
    goto LABEL_4;
  }
  drm_connector_list_iter_begin(***(_QWORD ***)(v4 + 144), v30);
  v11 = drm_connector_list_iter_next(v30);
  v12 = 0;
  if ( !v11 )
    goto LABEL_15;
  v13 = 4096;
  while ( 1 )
  {
    if ( !*(_QWORD *)(v11 + 2776) || *(_QWORD *)(*(_QWORD *)(v11 + 2760) + 16LL) != **(_QWORD **)(v4 + 144) )
      goto LABEL_8;
    v14 = scnprintf(
            v10 + v12,
            (unsigned int)v13,
            "conn name:%s, conn id:%d state:%d\n",
            *(const char **)(v11 + 96),
            *(_DWORD *)(v11 + 64),
            *(_DWORD *)(v11 + 192));
    if ( v13 <= (int)v14 )
      break;
    v12 += v14;
    v13 = 4096 - v12;
LABEL_8:
    v11 = drm_connector_list_iter_next(v30);
    if ( !v11 )
      goto LABEL_15;
  }
  v16 = get_ipc_log_context(v14);
  ipc_log_string(v16, "[e][%-4d]buffer overflow\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  printk(&unk_27296B, "dp_debug_check_buffer_overflow");
LABEL_15:
  drm_connector_list_iter_end(v30);
  if ( v12 >= a3 )
    v6 = a3;
  else
    v6 = v12;
  if ( v6 > 0x1000 )
  {
    _copy_overflow(4096, v6);
    goto LABEL_25;
  }
  _check_object_size(v10, v6, 1);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v18 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v18 = a2 & ((__int64)(a2 << 8) >> 8);
  v19 = v6;
  if ( 0x8000000000LL - v6 >= v18 )
  {
    v20 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v26 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v26 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v26);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v20);
    v19 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
    v27 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v29 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v29 - 4096);
    _WriteStatusReg(TTBR1_EL1, v29);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v27);
  }
  if ( v19 )
  {
LABEL_25:
    kfree(v10);
    v6 = -14;
  }
  else
  {
    *a4 += v6;
    kfree(v10);
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return v6;
}
