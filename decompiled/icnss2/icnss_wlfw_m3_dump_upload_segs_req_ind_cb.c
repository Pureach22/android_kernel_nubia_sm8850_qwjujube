__int64 __fastcall icnss_wlfw_m3_dump_upload_segs_req_ind_cb(__int64 a1, __int64 a2, __int64 a3, _DWORD *a4)
{
  char *v4; // x25
  __int64 result; // x0
  unsigned __int64 v9; // x2
  _DWORD *v10; // x21
  int v11; // w9
  __int64 v12; // x26
  unsigned __int64 v13; // x22
  unsigned __int64 v14; // x27
  const char *v15; // x28
  unsigned __int64 v16; // x4
  unsigned __int64 v17; // x24
  char *v18; // x20
  const char *v19; // x23
  size_t v20; // x0
  unsigned __int64 StatusReg; // x22
  __int64 v22; // x23
  __int64 (__fastcall *v23)(_QWORD); // x0
  __int64 v24; // [xsp+8h] [xbp-8h]

  v4 = "eq %d\n";
  ipc_log_string(icnss_ipc_log_context, "icnss2_qmi: Received QMI WLFW M3 dump upload sigments indication\n");
  if ( a3 )
  {
    result = ipc_log_string(
               icnss_ipc_log_context,
               "icnss2_qmi: M3 Dump upload info: pdev_id: %d no_of_segments: %d\n",
               *a4,
               a4[1]);
    if ( a4[1] <= 0xAu )
    {
      v24 = a1;
      result = _kmalloc_cache_noprof(wait_for_completion, 3520, 488);
      v10 = (_DWORD *)result;
      if ( result )
      {
        while ( 1 )
        {
          v11 = a4[1];
          *v10 = *a4;
          v10[1] = v11;
          if ( !v11 )
            return icnss_driver_event_post(a1 - 624, 0xDu, 0, (__int64)v10);
          v12 = 0;
          v13 = 0;
          v14 = *(_QWORD *)(a1 + 1168) + *(unsigned int *)(a1 + 1192);
          while ( v12 != 120 )
          {
            v15 = (const char *)&a4[v12];
            v16 = *(_QWORD *)&a4[v12 + 6];
            v17 = (unsigned int)a4[v12 + 4];
            if ( v16 > *(unsigned int *)(a1 + 1192) || v17 >= v14 || v17 < *(_QWORD *)(a1 + 1168) || v16 + v17 > v14 )
            {
              ipc_log_string(
                *((_QWORD *)v4 + 54),
                "icnss2_qmi: Received out of range Segment %d Addr: 0x%llx Size: 0x%llx, Name: %s, type: %d\n",
                v13 + 1,
                (unsigned int)a4[v12 + 4],
                v16,
                v15 + 32,
                *((_DWORD *)v15 + 2));
              return kfree(v10);
            }
            if ( (unsigned __int64)(v12 * 4 - 473) < 0xFFFFFFFFFFFFFE17LL
              || (*(_QWORD *)&v10[v12 + 4] = v17, (unsigned __int64)(v12 * 4 - 464) < 0xFFFFFFFFFFFFFE18LL) )
            {
              __break(1u);
              break;
            }
            v18 = v4;
            v4 = (char *)&v10[v12];
            *(_QWORD *)&v10[v12 + 6] = v16;
            v19 = (const char *)&a4[v12];
            v10[v12 + 2] = *((_DWORD *)v15 + 2);
            v20 = strnlen((const char *)&a4[v12 + 8], 0x11u);
            if ( v20 >= 0x12 )
              goto LABEL_26;
            if ( v20 == 17 )
              v9 = 17;
            else
              v9 = v20 + 1;
            if ( v9 >= 0x12 )
              goto LABEL_25;
            sized_strscpy(v4 + 32, v19 + 32);
            ++v13;
            v4 = v18;
            ipc_log_string(
              *((_QWORD *)v18 + 54),
              "icnss2_qmi: Received Segment %d Addr: 0x%llx Size: 0x%llx, Name: %s, type: %d\n",
              v13,
              v17,
              *((_QWORD *)v15 + 3),
              v19 + 32,
              *((_DWORD *)v15 + 2));
            a1 = v24;
            v12 += 12;
            if ( v13 >= (unsigned int)a4[1] )
              return icnss_driver_event_post(a1 - 624, 0xDu, 0, (__int64)v10);
          }
          __break(0x5512u);
LABEL_25:
          v20 = _fortify_panic(7, 17, v9);
LABEL_26:
          _fortify_panic(2, 17, v20 + 1);
          StatusReg = _ReadStatusReg(SP_EL0);
          v22 = *(_QWORD *)(StatusReg + 80);
          v23 = wait_for_completion;
          *(_QWORD *)(StatusReg + 80) = &icnss_wlfw_m3_dump_upload_segs_req_ind_cb__alloc_tag;
          result = _kmalloc_cache_noprof(v23, 3520, 488);
          a1 = v24;
          v10 = (_DWORD *)result;
          *(_QWORD *)(StatusReg + 80) = v22;
          if ( !result )
            return result;
        }
      }
    }
  }
  else
  {
    printk("%sicnss2_qmi: Spurious indication\n", byte_130B32);
    return ipc_log_string(icnss_ipc_log_context, "%sicnss2_qmi: Spurious indication\n", (const char *)&unk_12DBF3);
  }
  return result;
}
