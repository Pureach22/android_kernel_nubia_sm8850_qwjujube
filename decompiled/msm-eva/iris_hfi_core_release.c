__int64 __fastcall iris_hfi_core_release(__int64 a1)
{
  __int64 v2; // x1
  __int64 v3; // x2
  __int64 v4; // x3
  __int64 v5; // x8
  __int64 v6; // x0
  unsigned int v7; // w9
  __int64 v8; // x10
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3
  unsigned int v12; // w20
  int v13; // w9
  int v14; // w0
  int v15; // w8
  __int64 v16; // x0
  __int64 v17; // x2
  __int64 v18; // x3
  unsigned __int64 *v19; // x9
  unsigned __int64 v20; // x10
  unsigned __int64 **v21; // x8
  unsigned __int64 *v22; // x11
  unsigned __int64 v24; // x8
  unsigned __int64 v25; // x8
  unsigned __int64 v26; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v28; // x8
  unsigned __int64 v29; // x8

  if ( !a1 )
  {
    v12 = -19;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_8A7C9, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    }
    return v12;
  }
  mutex_lock(a1 + 80);
  if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
  {
    v24 = _ReadStatusReg(SP_EL0);
    printk(&unk_942EE, *(unsigned int *)(v24 + 1800), *(unsigned int *)(v24 + 1804), "warn");
    if ( !*(_DWORD *)(a1 + 2696) )
      goto LABEL_18;
  }
  else if ( !*(_DWORD *)(a1 + 2696) )
  {
LABEL_18:
    _resume(a1, v2, v3, v4);
    *(_DWORD *)(a1 + 2408) = 1;
    v12 = qcom_scm_set_remote_state(0, 26);
    if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_82354, "core", 0, v12);
      if ( !v12 )
        goto LABEL_26;
    }
    else if ( !v12 )
    {
      goto LABEL_26;
    }
    v13 = msm_cvp_debug_out;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v25 = _ReadStatusReg(SP_EL0);
      printk(&unk_86A4F, *(unsigned int *)(v25 + 1800), *(unsigned int *)(v25 + 1804), &unk_8E7CE);
      v13 = msm_cvp_debug_out;
      if ( (msm_cvp_debug & 2) == 0 )
        goto LABEL_26;
    }
    else if ( (msm_cvp_debug & 2) == 0 )
    {
      goto LABEL_26;
    }
    if ( !v13 )
    {
      v26 = _ReadStatusReg(SP_EL0);
      printk(&unk_90A16, *(unsigned int *)(v26 + 1800), *(unsigned int *)(v26 + 1804), "warn");
    }
LABEL_26:
    if ( (msm_cvp_dsp_disable & 1) == 0 )
    {
      if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
        printk(&unk_82E65, "dsp", "__dsp_shutdown", v11);
      v14 = cvp_dsp_shutdown();
      v15 = msm_cvp_debug_out;
      if ( v14 && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v28 = _ReadStatusReg(SP_EL0);
        printk(&unk_8E9E7, *(unsigned int *)(v28 + 1800), *(unsigned int *)(v28 + 1804), &unk_8E7CE);
        v15 = msm_cvp_debug_out;
        if ( (msm_cvp_debug & 0x800) != 0 )
        {
LABEL_34:
          if ( !v15 )
            printk(&unk_8B1FB, "dsp", "__dsp_shutdown", v11);
        }
      }
      else if ( (msm_cvp_debug & 0x800) != 0 )
      {
        goto LABEL_34;
      }
    }
    _disable_subcaches(a1, v9, v10, v11);
    v16 = _read_register(a1, 0xA0060u);
    msm_cvp_unmap_ipcc_regs(v16);
    _unload_fw(a1);
    _hwfence_regs_unmap(a1);
    if ( msm_cvp_mmrm_enabled == 1 )
    {
      v12 = msm_cvp_mmrm_deregister(a1);
      if ( v12 )
      {
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        {
          v29 = _ReadStatusReg(SP_EL0);
          printk(&unk_95900, *(unsigned int *)(v29 + 1800), *(unsigned int *)(v29 + 1804), &unk_8E7CE);
        }
      }
    }
    v19 = *(unsigned __int64 **)a1;
    if ( *(_QWORD *)a1 != a1 )
    {
      v20 = 0xDEAD000000000100LL;
      do
      {
        v22 = (unsigned __int64 *)*v19;
        v21 = (unsigned __int64 **)v19[1];
        if ( *v21 == v19 && (unsigned __int64 *)v22[1] == v19 )
        {
          v22[1] = (unsigned __int64)v21;
          *v21 = v22;
        }
        else
        {
          _list_del_entry_valid_or_report(v19);
        }
        v19[4] = 0;
        *v19 = v20;
        v19[1] = v20 + 34;
        v19 = v22;
      }
      while ( v22 != (unsigned __int64 *)a1 );
    }
    if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
      printk(&unk_8438D, "core", v17, v18);
    mutex_unlock(a1 + 80);
    return v12;
  }
  v5 = *(_QWORD *)(a1 + 2208);
  v6 = *(_QWORD *)(v5 + 400);
  if ( !v6 )
    goto LABEL_18;
  v7 = *(_DWORD *)(v5 + 384);
  if ( !v7 )
  {
LABEL_17:
    kfree(v6);
    *(_QWORD *)(*(_QWORD *)(a1 + 2208) + 400LL) = 0;
    goto LABEL_18;
  }
  if ( ((*(_QWORD *)((char *)&_cpu_possible_mask + (((unsigned __int64)*(unsigned int *)(v5 + 392) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v5 + 392))
      & 1) != 0
    && *(_QWORD *)(v6 + 72) )
  {
    v6 = ((__int64 (*)(void))dev_pm_qos_remove_request)();
    v5 = *(_QWORD *)(a1 + 2208);
    v7 = *(_DWORD *)(v5 + 384);
  }
  if ( v7 < 2 )
    goto LABEL_16;
  if ( ((*(_QWORD *)((char *)&_cpu_possible_mask + (((unsigned __int64)*(unsigned int *)(v5 + 396) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v5 + 396))
      & 1) != 0 )
  {
    v8 = *(_QWORD *)(v5 + 400);
    v6 = v8 + 80;
    if ( v8 != -80 )
    {
      if ( *(_QWORD *)(v8 + 152) )
      {
        v6 = dev_pm_qos_remove_request(v6);
        v5 = *(_QWORD *)(a1 + 2208);
        v7 = *(_DWORD *)(v5 + 384);
      }
    }
  }
  if ( v7 <= 2 )
  {
LABEL_16:
    v6 = *(_QWORD *)(v5 + 400);
    goto LABEL_17;
  }
  __break(0x5512u);
  return iris_hfi_core_trigger_ssr(v6);
}
