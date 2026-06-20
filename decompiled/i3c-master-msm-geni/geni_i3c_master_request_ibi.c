__int64 __fastcall geni_i3c_master_request_ibi(__int64 a1, int *a2)
{
  __int64 v2; // x23
  __int64 v5; // x0
  __int64 v6; // x24
  __int64 v7; // x25
  int v8; // w27
  __int64 v9; // x22
  unsigned __int64 v10; // x19
  unsigned __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x8
  unsigned __int64 v14; // x20
  unsigned int v15; // w20
  const char *v16; // x2
  int v17; // w2
  __int64 v19; // x3
  __int64 v20; // x0
  __int64 v21; // x2
  __int64 v22; // x0
  __int64 v23; // x1
  __int64 v24; // x2
  __int64 v25; // x3
  __int64 v26; // x0
  __int64 v27; // x3
  __int64 v28; // x0
  __int64 v29; // x2
  __int64 v30; // x0
  __int64 v31; // x3
  __int64 v32; // x0
  __int64 v33; // x21
  __int64 v34; // x0

  v2 = *(_QWORD *)(a1 + 16);
  v5 = mutex_lock(v2 + 2552);
  v7 = *(_QWORD *)(a1 + 16);
  v6 = *(_QWORD *)(a1 + 24);
  v8 = *a2;
  v9 = *(_QWORD *)(v7 + 2424);
  if ( v9 )
  {
    if ( *(_DWORD *)(v7 + 2432) )
    {
      v10 = sched_clock(v5);
      ipc_log_string(v9, "%s:start at %llu nsec(%llu usec)\n", "geni_i3c_request_ibi", v10, v10 / 0x3E8);
    }
    else
    {
      v10 = 0;
    }
  }
  else
  {
    v10 = -22;
  }
  if ( *(_BYTE *)(v7 + 21208) == 1 )
  {
    if ( (*(_BYTE *)(v7 + 21209) & 1) == 0 )
      qcom_geni_i3c_ibi_conf(v7 - 112);
    v11 = i3c_generic_ibi_alloc_pool(a1, a2);
    *(_QWORD *)(v6 + 8) = v11;
    if ( v11 >= 0xFFFFFFFFFFFFF001LL )
    {
      ipc_log_string(*(_QWORD *)(v7 + 2416), "Error creating a generic IBI pool %ld\n", v11);
      v20 = *(_QWORD *)(v7 - 104);
      v21 = *(_QWORD *)(v6 + 8);
      if ( v20 )
        dev_err(v20, "Error creating a generic IBI pool %ld\n", v21);
      else
        printk(&unk_1339B, *(_QWORD *)(v6 + 8), v21, v19);
      if ( *(_QWORD *)(v7 - 104) )
        i3c_trace_log();
      v15 = *(_DWORD *)(v6 + 8);
    }
    else
    {
      v12 = raw_spin_lock_irqsave(v7 + 21240);
      v13 = *(unsigned int *)(v7 + 21224);
      if ( (_DWORD)v13 )
      {
        v14 = 0;
        while ( *(_QWORD *)(*(_QWORD *)(v7 + 21232) + 8 * v14) )
        {
          if ( v13 == ++v14 )
          {
            v14 = *(unsigned int *)(v7 + 21224);
            goto LABEL_18;
          }
        }
        *(_WORD *)(v6 + 2) = v14;
        *(_QWORD *)(*(_QWORD *)(v7 + 21232) + 8 * v14) = a1;
      }
      else
      {
        v14 = 0;
      }
LABEL_18:
      raw_spin_unlock_irqrestore(v7 + 21240, v12);
      if ( v14 < *(unsigned int *)(v7 + 21224) )
      {
        *(_DWORD *)(v7 + 21328) = 0;
        *(_DWORD *)(v7 + 21248) = 0;
        writel_relaxed(
          ((v8 & 0x3F) << 13) | (32 * *(unsigned __int8 *)(a1 + 43)) | 0x1000,
          (unsigned int *)(*(_QWORD *)(v7 + 21216) + 4096LL));
        if ( !(unsigned int)wait_for_completion_timeout(v7 + 21248, &print_fmt_i3c_log_info[2], v16) )
        {
          v22 = *(_QWORD *)(v7 + 2416);
          *(_DWORD *)(v7 + 21328) = -110;
          ipc_log_string(v22, "timeout while adding slave IBI\n");
          v26 = *(_QWORD *)(v7 - 104);
          if ( v26 )
            dev_err(v26, "timeout while adding slave IBI\n");
          else
            printk(&unk_1373F, v23, v24, v25);
          if ( *(_QWORD *)(v7 - 104) )
            i3c_trace_log();
        }
        v17 = *(_DWORD *)(v7 + 21328);
        if ( !v17 )
        {
          v15 = 0;
          goto LABEL_22;
        }
        ipc_log_string(*(_QWORD *)(v7 + 2416), "error while adding slave IBI 0x%x\n", v17);
        v28 = *(_QWORD *)(v7 - 104);
        v29 = *(unsigned int *)(v7 + 21328);
        if ( v28 )
          dev_err(v28, "error while adding slave IBI 0x%x\n", v29);
        else
          printk(&unk_12F84, (unsigned int)v29, v29, v27);
        if ( *(_QWORD *)(v7 - 104) )
          i3c_trace_log();
      }
      ipc_log_string(*(_QWORD *)(v7 + 2416), "ibi.num_slots ran out %ld: %d\n", v14, *(_DWORD *)(v7 + 21224));
      v30 = *(_QWORD *)(v7 - 104);
      v31 = *(unsigned int *)(v7 + 21224);
      if ( v30 )
        dev_err(v30, "ibi.num_slots ran out %ld: %d\n", v14, v31);
      else
        printk(&unk_14FBF, v14, (unsigned int)v31, v31);
      if ( *(_QWORD *)(v7 - 104) )
        i3c_trace_log();
      v32 = i3c_generic_ibi_free_pool(*(_QWORD *)(v6 + 8));
      *(_QWORD *)(v6 + 8) = 0;
      v33 = *(_QWORD *)(v7 + 2424);
      if ( v33 )
      {
        v15 = -28;
        if ( v10 && *(_DWORD *)(v7 + 2432) )
        {
          v34 = sched_clock(v32);
          ipc_log_string(v33, "%s:took %llu nsec(%llu usec)\n", "geni_i3c_request_ibi", v34 - v10, (v34 - v10) / 0x3E8);
        }
      }
      else
      {
        v15 = -28;
      }
    }
  }
  else
  {
    v15 = -1;
  }
LABEL_22:
  mutex_unlock(v2 + 2552);
  return v15;
}
