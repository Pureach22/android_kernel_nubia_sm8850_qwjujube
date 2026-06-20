__int64 __fastcall wlfw_qdss_trace_save_ind_cb(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  __int64 v8; // x19
  int v9; // w8
  int v10; // w9
  unsigned int v11; // w2
  int v12; // w10
  size_t v13; // x0
  unsigned __int64 v14; // x22
  int *v15; // x25
  int *v16; // x26
  int v17; // w4
  int v18; // w9
  __int64 v19; // x3
  unsigned __int64 v20; // x2
  __int64 v21; // x0
  unsigned int v22; // w1
  unsigned __int64 StatusReg; // x22
  __int64 v24; // x23

  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Received QMI WLFW QDSS trace save indication\n");
  if ( !a3 )
  {
    printk("%sicnss2_qmi: Spurious indication\n", byte_130B32);
    return ipc_log_string(icnss_ipc_log_context, "%sicnss2_qmi: Spurious indication\n", (const char *)&unk_12DBF3);
  }
  ipc_log_string(
    icnss_ipc_log_context,
    "icnss2_qmi: QDSS_trace_save info: source %u, total_size %u, file_name_valid %u, file_name %s\n",
    *(_DWORD *)a4,
    *(_DWORD *)(a4 + 4),
    *(unsigned __int8 *)(a4 + 1264),
    (const char *)(a4 + 1265));
  result = _kmalloc_cache_noprof(kfree, 3520, 552);
  v8 = result;
  if ( result )
  {
    while ( 1 )
    {
      v9 = *(_DWORD *)(a4 + 28);
      v10 = *(_DWORD *)(a4 + 4);
      v11 = *(_DWORD *)(a4 + 12);
      v12 = *(unsigned __int8 *)(a4 + 8);
      *(_DWORD *)(v8 + 4) = v11;
      *(_DWORD *)(v8 + 8) = v9;
      *(_DWORD *)v8 = v10;
      if ( v12 )
      {
        if ( v11 >= 0x21 )
        {
          printk("%sicnss2_qmi: Invalid seg len %u\n", byte_130B32, v11);
          ipc_log_string(
            icnss_ipc_log_context,
            "%sicnss2_qmi: Invalid seg len %u\n",
            (const char *)&unk_12DBF3,
            *(_DWORD *)(a4 + 12));
          return kfree(v8);
        }
        v13 = ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: QDSS_trace_save seg len %u\n", v11);
        if ( *(_DWORD *)(a4 + 12) )
          break;
      }
LABEL_10:
      if ( !*(_BYTE *)(a4 + 1264) )
        goto LABEL_17;
      v13 = strnlen((const char *)(a4 + 1265), 0x11u);
      if ( v13 >= 0x12 )
        goto LABEL_31;
      if ( v13 == 17 )
        v20 = 17;
      else
        v20 = v13 + 1;
      if ( v20 < 0x12 )
      {
        sized_strscpy(v8 + 528, a4 + 1265);
LABEL_17:
        v21 = a1 - 624;
        if ( *(_DWORD *)a4 == 1 )
        {
          if ( !*(_BYTE *)(a4 + 1264) )
          {
            sized_strscpy(v8 + 528, "qdss_trace_wcss_etb");
            v21 = a1 - 624;
          }
          v22 = 16;
        }
        else
        {
          if ( !*(_BYTE *)(a4 + 1264) )
            strcpy((char *)(v8 + 528), "qdss_trace_ddr");
          v22 = 11;
        }
        return icnss_driver_event_post(v21, v22, 0, v8);
      }
LABEL_32:
      _fortify_panic(7, 17, v20);
      StatusReg = _ReadStatusReg(SP_EL0);
      v24 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &wlfw_qdss_trace_save_ind_cb__alloc_tag;
      result = _kmalloc_cache_noprof(kfree, 3520, 552);
      v8 = result;
      *(_QWORD *)(StatusReg + 80) = v24;
      if ( !result )
        return result;
    }
    v14 = 0;
    v15 = (int *)(v8 + 24);
    v16 = (int *)(a4 + 28);
    while ( v14 != 32 )
    {
      v17 = *(v16 - 1);
      v18 = *v16;
      v19 = *(_QWORD *)(v16 - 3);
      *((_QWORD *)v15 - 1) = v19;
      *v15 = v17;
      if ( *(_DWORD *)(v8 + 8) != v18 )
      {
        printk("%sicnss2_qmi: FW Mem file save ind cannot have multiple mem types\n", byte_130B32);
        ipc_log_string(
          icnss_ipc_log_context,
          "%sicnss2_qmi: FW Mem file save ind cannot have multiple mem types\n",
          (const char *)&unk_12DBF3);
        return kfree(v8);
      }
      v13 = ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: seg-%d: addr 0x%llx size 0x%x\n", v14++, v19, v17);
      v15 += 4;
      v16 += 6;
      if ( v14 >= *(unsigned int *)(a4 + 12) )
        goto LABEL_10;
    }
    __break(0x5512u);
LABEL_31:
    _fortify_panic(2, 17, v13 + 1);
    goto LABEL_32;
  }
  return result;
}
