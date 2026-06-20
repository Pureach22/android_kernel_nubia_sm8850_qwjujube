__int64 __fastcall gh_rm_booster_probe(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x0
  __int64 v4; // x19
  unsigned int variable_u32_array; // w0
  unsigned int v6; // w0
  _QWORD *v7; // x9
  unsigned int v8; // w23
  int v9; // w0
  __int64 result; // x0
  __int64 v11; // x9
  __int64 v12; // x0
  unsigned __int64 hyp_res; // x0
  __int64 v14; // x8
  unsigned __int64 v15; // x9
  unsigned __int64 v16; // x20
  __int64 v17; // x0
  unsigned int v18; // w20
  const char *v19; // x1
  _QWORD v20[2]; // [xsp+0h] [xbp-10h] BYREF

  v20[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 760);
  v3 = _kmalloc_cache_noprof(gh_rm_register_notifier, 3520, 240);
  rm_status = v3;
  if ( !v3 )
  {
    result = 4294967284LL;
    goto LABEL_18;
  }
  v4 = a1 + 16;
  variable_u32_array = of_property_read_variable_u32_array(v2, "qcom,rm-vmid", v3 + 4, 1, 0);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v18 = variable_u32_array;
    v19 = "Failed to get RM vmid\n";
LABEL_22:
    dev_err(v4, v19);
    kfree(rm_status);
    result = v18;
    goto LABEL_18;
  }
  v6 = of_property_read_variable_u32_array(v2, "qcom,rm-affinity-default", rm_status + 8, 1, 0);
  if ( (v6 & 0x80000000) != 0 )
  {
    v18 = v6;
    v19 = "Failed to get RM affinity\n";
    goto LABEL_22;
  }
  v20[0] = *(int *)(rm_status + 8);
  smp_call_function_single();
  v7 = (_QWORD *)rm_status;
  *(_QWORD *)(rm_status + 16) = v20[0];
  v7[4] = v4;
  *(_QWORD *)(a1 + 168) = v7;
  v7[16] = 0xFFFFFFFE00000LL;
  v7[17] = v7 + 17;
  v7[18] = v7 + 17;
  v7[19] = gh_rm_booster_release_func;
  init_timer_key(v7 + 20, &delayed_work_timer_fn, 0x200000, 0, 0);
  v8 = target_cpu;
  if ( v8 >= (unsigned int)_sw_hweight64(_cpu_possible_mask) )
  {
    v9 = _sw_hweight64(_cpu_possible_mask) - 1;
    target_cpu = v9;
  }
  else
  {
    v9 = target_cpu;
  }
  v20[0] = v9;
  smp_call_function_single();
  v11 = rm_status;
  v12 = *(unsigned int *)(rm_status + 4);
  *(_QWORD *)(rm_status + 24) = v20[0];
  *(_DWORD *)v11 = 0;
  *(_QWORD *)(v11 + 232) = -1;
  LODWORD(v20[0]) = 0;
  hyp_res = gh_rm_vm_get_hyp_res(v12, v20);
  if ( hyp_res && hyp_res <= 0xFFFFFFFFFFFFF000LL )
  {
    v14 = LODWORD(v20[0]);
    if ( LODWORD(v20[0]) )
    {
      v15 = hyp_res;
      while ( *(_BYTE *)v15 != 4 )
      {
        --v14;
        v15 += 44LL;
        if ( !v14 )
          goto LABEL_14;
      }
      *(_QWORD *)(rm_status + 232) = *(_QWORD *)(v15 + 12);
    }
    else
    {
LABEL_14:
      v16 = hyp_res;
      dev_err(*(_QWORD *)(rm_status + 32), "No vCPU resource type found.\n");
      hyp_res = v16;
    }
    kfree(hyp_res);
  }
  else
  {
    dev_err(*(_QWORD *)(rm_status + 32), "Get hyp resources failed.\n");
  }
  v17 = rm_status;
  *(_QWORD *)(rm_status + 104) = gh_rm_boost_nb_handler;
  *(_DWORD *)(v17 + 120) = 0x7FFFFFFF;
  result = gh_rm_register_notifier();
  if ( (_DWORD)result )
  {
    v18 = result;
    v19 = "Failed to register RM notifier\n";
    goto LABEL_22;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
