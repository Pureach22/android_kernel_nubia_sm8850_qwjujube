__int64 __fastcall cvp_iris_hfi_initialize(unsigned __int64 *a1, __int64 a2, __int64 a3)
{
  unsigned __int64 v6; // x20
  __int64 v7; // x0
  __int64 v8; // x0
  unsigned int (__fastcall *v9)(unsigned __int64, __int64); // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 result; // x0
  unsigned __int64 v13; // x8
  void *v14; // x0
  unsigned __int64 v15; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v17; // x0
  __int64 v18; // x0

  if ( a1 && a2 && a3 )
  {
    v6 = _kmalloc_cache_noprof(_kmalloc_large_noprof, 3520, 2704);
    if ( !v6 )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_8A6CA, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      }
      goto LABEL_36;
    }
    v7 = _kmalloc_large_noprof(24576, 3264);
    *(_QWORD *)(v6 + 2432) = v7;
    if ( v7 )
    {
      v8 = _kmalloc_large_noprof(12288, 3520);
      *(_QWORD *)(v6 + 2440) = v8;
      if ( v8 )
      {
        v9 = *(unsigned int (__fastcall **)(unsigned __int64, __int64))((char *)off_199B8[0] + (unsigned __int64)&unk_8);
        if ( *((_DWORD *)v9 - 1) != -869659424 )
          __break(0x8228u);
        if ( !v9(v6, a2) )
        {
          *(_DWORD *)(v6 + 2696) = 0x7FFFFFFF;
          *(_QWORD *)(v6 + 2208) = a2;
          *(_QWORD *)(v6 + 128) = a3;
          *(_QWORD *)(v6 + 2512) = &hal_ops;
          v10 = alloc_workqueue(&unk_8A701, 393226, 1, "msm_cvp_workerq_iris");
          *(_QWORD *)(v6 + 2176) = v10;
          if ( v10 )
          {
            v11 = alloc_workqueue(&unk_8A701, 393226, 1, "pm_workerq_iris");
            *(_QWORD *)(v6 + 2184) = v11;
            if ( v11 )
            {
              _mutex_init(v6 + 80, "&hdevice->lock", &_add_device___key);
              *(_QWORD *)v6 = v6;
              *(_QWORD *)(v6 + 8) = v6;
              *a1 = v6;
              if ( v6 < 0xFFFFFFFFFFFFF001LL )
              {
                a1[1] = (unsigned __int64)iris_hfi_core_init;
                a1[2] = (unsigned __int64)iris_hfi_core_release;
                a1[3] = (unsigned __int64)iris_hfi_core_trigger_ssr;
                a1[4] = (unsigned __int64)iris_hfi_session_init;
                a1[5] = (unsigned __int64)iris_hfi_session_end;
                a1[6] = (unsigned __int64)iris_hfi_session_start;
                a1[7] = (unsigned __int64)iris_hfi_session_stop;
                a1[8] = (unsigned __int64)iris_hfi_session_abort;
                a1[9] = (unsigned __int64)iris_hfi_session_set_buffers;
                a1[10] = (unsigned __int64)iris_hfi_session_release_buffers;
                a1[11] = (unsigned __int64)iris_hfi_session_send;
                a1[12] = (unsigned __int64)iris_hfi_session_flush;
                a1[13] = (unsigned __int64)iris_hfi_scale_clocks;
                a1[14] = (unsigned __int64)iris_hfi_vote_buses;
                a1[15] = (unsigned __int64)iris_hfi_get_fw_info;
                a1[16] = (unsigned __int64)iris_hfi_session_clean;
                a1[17] = (unsigned __int64)iris_hfi_get_core_capabilities;
                a1[18] = (unsigned __int64)iris_hfi_suspend;
                a1[19] = (unsigned __int64)iris_hfi_resume;
                a1[20] = (unsigned __int64)iris_hfi_flush_debug_queue;
                a1[21] = (unsigned __int64)iris_hfi_noc_error_info;
                a1[22] = (unsigned __int64)iris_hfi_validate_session;
                a1[23] = (unsigned __int64)iris_pm_qos_aggregate;
                a1[24] = (unsigned __int64)iris_debug_hook;
                return 0;
              }
              goto LABEL_37;
            }
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              v14 = &unk_962E6;
              v15 = _ReadStatusReg(SP_EL0);
              goto LABEL_42;
            }
          }
          else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          {
            v14 = &unk_95822;
            v15 = _ReadStatusReg(SP_EL0);
            goto LABEL_42;
          }
        }
LABEL_31:
        v17 = *(_QWORD *)(v6 + 2184);
        if ( !v17 )
        {
LABEL_33:
          v18 = *(_QWORD *)(v6 + 2176);
          if ( v18 )
            destroy_workqueue(v18);
          kfree(*(_QWORD *)(v6 + 2432));
          kfree(*(_QWORD *)(v6 + 2440));
          kfree(v6);
LABEL_36:
          v6 = 0;
          *a1 = 0;
LABEL_37:
          if ( v6 )
            return (unsigned int)v6;
          else
            return 4294967274LL;
        }
LABEL_32:
        destroy_workqueue(v17);
        goto LABEL_33;
      }
      if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
        goto LABEL_31;
      v14 = &unk_8BBCF;
      v15 = _ReadStatusReg(SP_EL0);
    }
    else
    {
      if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
        goto LABEL_31;
      v14 = &unk_8762E;
      v15 = _ReadStatusReg(SP_EL0);
    }
LABEL_42:
    printk(v14, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
    v17 = *(_QWORD *)(v6 + 2184);
    if ( !v17 )
      goto LABEL_33;
    goto LABEL_32;
  }
  result = 4294967274LL;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v13 = _ReadStatusReg(SP_EL0);
    printk(&unk_8C490, *(unsigned int *)(v13 + 1800), *(unsigned int *)(v13 + 1804), &unk_8E7CE);
    return 4294967274LL;
  }
  return result;
}
