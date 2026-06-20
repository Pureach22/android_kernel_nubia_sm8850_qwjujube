// Alternative name is 'init_module'
__int64 __fastcall gh_vcpu_mgr_init(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v4; // w0
  __int64 v5; // x1
  __int64 v6; // x2
  unsigned int v7; // w0
  unsigned int v8; // w0
  unsigned int v9; // w0
  __int64 v10; // x8
  unsigned int v12; // w20
  void *v13; // x0

  gh_vms = _kmalloc_cache_noprof(_tracepoint_android_rvh_gh_after_vcpu_run, 3520, &print_fmt_gh_hcall_vcpu_run[64], a4);
  if ( !gh_vms )
    return 4294967284LL;
  v4 = gh_rm_set_wdog_manage_cb(gh_wdog_manage);
  if ( v4 )
  {
    v12 = v4;
    v13 = &unk_7D8B;
  }
  else
  {
    v7 = gh_rm_set_vcpu_affinity_cb(gh_populate_vm_vcpu_info);
    if ( v7 )
    {
      v12 = v7;
      v13 = &unk_7B89;
    }
    else
    {
      v8 = gh_rm_reset_vcpu_affinity_cb(gh_unpopulate_vm_vcpu_info);
      if ( v8 )
      {
        v12 = v8;
        v13 = &unk_7B18;
      }
      else
      {
        v9 = gh_rm_all_res_populated_cb(gh_populate_all_res_info);
        if ( !v9 )
        {
          v10 = gh_vms;
          *(_WORD *)gh_vms = -1;
          *(_QWORD *)(v10 + 4) = 0;
          *(_QWORD *)(v10 + 12) = 0;
          *(_QWORD *)(v10 + 18) = 0;
          *(_WORD *)(v10 + 40) = -1;
          *(_QWORD *)(v10 + 44) = 0;
          *(_QWORD *)(v10 + 52) = 0;
          *(_QWORD *)(v10 + 58) = 0;
          *(_WORD *)(v10 + 80) = -1;
          *(_QWORD *)(v10 + 84) = 0;
          *(_QWORD *)(v10 + 92) = 0;
          *(_QWORD *)(v10 + 98) = 0;
          *(_WORD *)(v10 + 120) = -1;
          *(_QWORD *)(v10 + 124) = 0;
          *(_QWORD *)(v10 + 132) = 0;
          *(_QWORD *)(v10 + 138) = 0;
          *(_WORD *)(v10 + 160) = -1;
          *(_QWORD *)(v10 + 164) = 0;
          *(_QWORD *)(v10 + 178) = 0;
          *(_QWORD *)(v10 + 172) = 0;
          android_rvh_probe_register(&_tracepoint_android_rvh_gh_before_vcpu_run, android_rvh_gh_before_vcpu_run, 0);
          android_rvh_probe_register(&_tracepoint_android_rvh_gh_after_vcpu_run, android_rvh_gh_after_vcpu_run, 0);
          android_rvh_probe_register(&_tracepoint_android_rvh_gh_vcpu_release, android_rvh_gh_before_vcpu_release, 0);
          android_rvh_probe_register(&_tracepoint_android_rvh_gh_vm_release, android_rvh_gh_before_vm_release, 0);
          init_done = 1;
          return 0;
        }
        v12 = v9;
        v13 = &unk_7CF4;
      }
    }
  }
  printk(v13, v5, v6);
  kfree(gh_vms);
  return v12;
}
