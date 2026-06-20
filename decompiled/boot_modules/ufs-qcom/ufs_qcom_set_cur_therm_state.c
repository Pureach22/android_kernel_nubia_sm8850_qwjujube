__int64 __fastcall ufs_qcom_set_cur_therm_state(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x19
  __int64 v3; // x23
  __int64 v5; // x24
  __int64 unlock; // x0
  __int64 v7; // x25
  __int64 v8; // x26
  unsigned int *v9; // x8
  unsigned __int64 v10; // x20
  unsigned int v11; // w22
  __int64 lock; // x0
  __int64 updated; // x0
  int v14; // w22
  __int64 v15; // x0
  __int64 v16; // x21
  const char *v17; // x2
  int v18; // w3
  int v19; // w4
  int v20; // w5
  int v21; // w6
  __int64 v22; // x0
  __int64 v23; // x21

  v2 = *(_QWORD **)(*(_QWORD *)(a1 + 944) + 152LL);
  if ( v2 )
  {
    v3 = v2[23];
    if ( *(_QWORD *)(v3 + 488) == a2 )
      return 0;
    if ( (unsigned __int64)(a2 - 1) < 2 )
    {
      dev_warn();
      *(_DWORD *)(v3 + 708) = 1;
      v5 = v2[23];
      if ( (*(_BYTE *)(v5 + 632) & 1) == 0 )
      {
        cancel_delayed_work_sync(v5 + 528);
        if ( *(_QWORD *)(v5 + 728) && *(_BYTE *)(v5 + 3139) == 1 )
          walt_unset_enforce_high_irq_cpus(v5 + 728);
        unlock = sched_set_boost(4294967292LL);
        if ( *(_BYTE *)(v5 + 524) == 1 )
        {
          *(_DWORD *)(v5 + 520) = 0;
          if ( *(int *)(v5 + 648) >= 1 )
          {
            v7 = 0;
            v8 = 0;
            while ( 1 )
            {
              v9 = (unsigned int *)(*(_QWORD *)(v5 + 640) + v7);
              v10 = *v9;
              v11 = v9[2];
              lock = cpus_read_lock(unlock);
              if ( ((*(_QWORD *)((char *)&_cpu_online_mask + ((v10 >> 3) & 0x1FFFFFF8)) >> v10) & 1) == 0 )
                break;
              if ( (unsigned int)v10 >= 0x20 )
              {
                __break(0x5512u);
                goto LABEL_32;
              }
              updated = freq_qos_update_request((char *)&qos_min_req + _per_cpu_offset[v10], v11);
              v14 = updated;
              unlock = cpus_read_unlock(updated);
              if ( (v14 & 0x80000000) == 0 )
                goto LABEL_17;
              unlock = dev_err(v2[8], "fail set cpufreq-fmin_def %d\n", v14);
LABEL_18:
              ++v8;
              v7 += 32;
              if ( v8 >= *(int *)(v5 + 648) )
                goto LABEL_19;
            }
            unlock = cpus_read_unlock(lock);
LABEL_17:
            *(_BYTE *)(v5 + 524) = 0;
            goto LABEL_18;
          }
        }
      }
LABEL_19:
      if ( *(_BYTE *)(v3 + 3137) == 1 )
        ((void (__fastcall *)(_QWORD *, _QWORD))ufs_qcom_toggle_pri_affinity)(v2, 0);
      ufshcd_auto_hibern8_update(v2, byte_3E8);
      v15 = _scsi_iterate_devices(v2[7], 0);
      if ( v15 )
      {
        v16 = v15;
        do
        {
          pm_runtime_set_autosuspend_delay(v16 + 464, 100);
          v16 = _scsi_iterate_devices(v2[7], v16);
        }
        while ( v16 );
      }
      goto LABEL_29;
    }
    if ( !a2 )
    {
      dev_warn();
      *(_DWORD *)(v3 + 708) = 0;
      ufshcd_auto_hibern8_update(v2, &print_fmt_ufs_qcom_pwr_change_notify[12], v17, v18, v19, v20, v21);
      v22 = _scsi_iterate_devices(v2[7], 0);
      if ( v22 )
      {
        v23 = v22;
        do
        {
          pm_runtime_set_autosuspend_delay(v23 + 464, 50);
          v23 = _scsi_iterate_devices(v2[7], v23);
        }
        while ( v23 );
      }
LABEL_29:
      *(_QWORD *)(v3 + 488) = a2;
      return 0;
    }
    ((void (*)(void))dev_err)();
    return 4294967274LL;
  }
  else
  {
LABEL_32:
    __break(0x800u);
    return ufs_qcom_print_hw_debug_reg_all();
  }
}
