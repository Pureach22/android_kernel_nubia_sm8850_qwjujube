unsigned __int64 __fastcall cnss_wlfw_fw_mem_file_save_ind_cb(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int *a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x25
  const char *v11; // x1
  const char *v12; // x1
  unsigned __int64 result; // x0
  __int64 v14; // x6
  __int64 v15; // x7
  __int64 v16; // x19
  unsigned int v17; // w9
  unsigned int v18; // w8
  unsigned int v19; // w10
  int v20; // w11
  __int64 v21; // x0
  const char *v22; // x1
  unsigned __int64 v23; // x22
  int *v24; // x27
  _DWORD *v25; // x26
  int v26; // w8
  int v27; // w10
  const char *v28; // x1
  unsigned __int64 v29; // x2
  __int64 v30; // x0
  unsigned int v31; // w1
  const char *v32; // x5
  __int64 v33; // x22
  char v34; // [xsp+0h] [xbp-20h]
  char v35; // [xsp+0h] [xbp-20h]

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( a3 && a4 )
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v11 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v11 = "soft_irq";
    }
    else
    {
      v11 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_long_context,
      v11,
      "cnss_wlfw_fw_mem_file_save_ind_cb",
      8u,
      8u,
      "QMI fw_mem_file_save: source: %d  mem_seg: %d type: %u len: %u\n",
      *a4,
      *((unsigned __int8 *)a4 + 8),
      a4[7]);
    result = _kmalloc_cache_noprof(memcpy, 3520, 872);
    v16 = result;
    if ( result )
    {
      while ( 1 )
      {
        v17 = a4[7];
        v18 = a4[3];
        v19 = a4[1];
        v20 = *((unsigned __int8 *)a4 + 8);
        *(_DWORD *)(v16 + 4) = v18;
        *(_DWORD *)(v16 + 8) = v17;
        *(_DWORD *)v16 = v19;
        if ( v20 )
        {
          if ( v18 > 0x10 )
          {
            v21 = cnss_ipc_log_context;
            if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
            {
              v22 = "irq";
            }
            else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              v22 = "soft_irq";
            }
            else
            {
              v22 = (const char *)(StatusReg + 2320);
            }
            v32 = "Invalid seg len indication\n";
            goto LABEL_56;
          }
          if ( v18 )
            break;
        }
LABEL_28:
        if ( !*((_BYTE *)a4 + 1264) )
          goto LABEL_35;
        result = strnlen((const char *)a4 + 1265, 0x11u);
        if ( result >= 0x12 )
        {
LABEL_59:
          _fortify_panic(2, 17, result + 1);
        }
        else
        {
          if ( result == 17 )
            v29 = 17;
          else
            v29 = result + 1;
          if ( v29 < 0x12 )
          {
            sized_strscpy(v16 + 848, (char *)a4 + 1265);
LABEL_35:
            v30 = a1 - 856;
            if ( *a4 == 1 )
            {
              if ( !*((_BYTE *)a4 + 1264) )
              {
                sized_strscpy(v16 + 848, "qdss_trace_wcss_etb");
                v30 = a1 - 856;
              }
              v31 = 20;
              return cnss_driver_event_post(v30, v31, 0, v16);
            }
            if ( *(_DWORD *)(v16 + 8) == 6 )
            {
              if ( !*((_BYTE *)a4 + 1264) )
              {
                v31 = 18;
                strcpy((char *)(v16 + 848), "qdss_trace_ddr");
                return cnss_driver_event_post(v30, v31, 0, v16);
              }
            }
            else if ( !*((_BYTE *)a4 + 1264) )
            {
              strcpy((char *)(v16 + 848), "fw_mem_dump");
            }
            v31 = 18;
            return cnss_driver_event_post(v30, v31, 0, v16);
          }
        }
        _fortify_panic(7, 17, v29);
        v33 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &cnss_wlfw_fw_mem_file_save_ind_cb__alloc_tag;
        result = _kmalloc_cache_noprof(memcpy, 3520, 872);
        v16 = result;
        *(_QWORD *)(StatusReg + 80) = v33;
        if ( !result )
          return result;
      }
      v23 = 0;
      v24 = (int *)(a4 + 7);
      v25 = (_DWORD *)(v16 + 24);
      while ( 1 )
      {
        if ( v23 == 52 )
        {
          __break(0x5512u);
          goto LABEL_59;
        }
        v26 = *(v24 - 1);
        v27 = *v24;
        v15 = *(_QWORD *)(v24 - 3);
        *((_QWORD *)v25 - 1) = v15;
        *v25 = v26;
        if ( *(_DWORD *)(v16 + 8) != v27 )
          break;
        v28 = "irq";
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            v28 = "soft_irq";
          else
            v28 = (const char *)(StatusReg + 2320);
        }
        result = cnss_debug_ipc_log_print(
                   cnss_ipc_log_long_context,
                   v28,
                   "cnss_wlfw_fw_mem_file_save_ind_cb",
                   8u,
                   8u,
                   "seg-%d: addr 0x%llx size 0x%x\n",
                   (unsigned int)v23++,
                   v15,
                   v26);
        v24 += 6;
        v25 += 4;
        if ( v23 >= a4[3] )
          goto LABEL_28;
      }
      v21 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v22 = "irq";
      }
      else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        v22 = "soft_irq";
      }
      else
      {
        v22 = (const char *)(StatusReg + 2320);
      }
      v32 = "FW Mem file save ind cannot have multiple mem types\n";
LABEL_56:
      cnss_debug_ipc_log_print(v21, v22, "cnss_wlfw_fw_mem_file_save_ind_cb", 3u, 3u, v32, v14, v15, v35);
      return kfree(v16);
    }
  }
  else
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v12 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v12 = "soft_irq";
    }
    else
    {
      v12 = (const char *)(StatusReg + 2320);
    }
    return cnss_debug_ipc_log_print(
             cnss_ipc_log_context,
             v12,
             "cnss_wlfw_fw_mem_file_save_ind_cb",
             3u,
             3u,
             "Spurious indication\n",
             a7,
             a8,
             v34);
  }
  return result;
}
