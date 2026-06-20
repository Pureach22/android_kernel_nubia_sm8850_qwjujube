__int64 gh_rm_setup_feature_scm_assign()
{
  unsigned int this_vmid; // w19
  __int64 v1; // x19
  __int64 v2; // x20
  unsigned __int64 v3; // x8
  int v4; // w0
  int v6; // [xsp+Ch] [xbp-14h] BYREF
  _WORD v7[2]; // [xsp+10h] [xbp-10h] BYREF
  int v8; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  v7[0] = 0;
  v6 = 0;
  this_vmid = gh_rm_get_this_vmid(v7);
  if ( this_vmid )
    goto LABEL_15;
  if ( v7[0] == 3 )
  {
    v1 = _alloc_pages_noprof(3264, 0, 0, 0);
    if ( v1 )
    {
      v2 = _kmalloc_cache_noprof(trace_event_buffer_reserve, 3520, 42);
      if ( v2 )
      {
        if ( !(unsigned int)gh_rm_vm_alloc_vmid(2u, &v8) )
        {
          v3 = memstart_addr;
          *(_BYTE *)(v2 + 6) = 6;
          *(_WORD *)(v2 + 4) = v8;
          *(_DWORD *)v2 = 1;
          *(_DWORD *)(v2 + 12) = 1;
          *(_QWORD *)(v2 + 26) = 4096;
          *(_QWORD *)(v2 + 18) = ((v1 - -64LL * (v3 >> 12)) << 6) + 0x5000000000LL;
          v4 = ghd_rm_mem_lend(0, 0, 0, (unsigned int *)v2, (unsigned int *)(v2 + 12), nullptr, &v6);
          gh_feature_use_scm_assign = v4 != 0;
          if ( v4 || !(unsigned int)ghd_rm_mem_reclaim(v6, 0) )
            _free_pages(v1, 0);
          gh_rm_vm_dealloc_vmid(v8);
          kfree(v2);
          goto LABEL_11;
        }
        kfree(v2);
      }
      _free_pages(v1, 0);
    }
    this_vmid = -12;
LABEL_15:
    gh_feature_use_scm_assign = 1;
    printk(&unk_133EF, "gh_rm_setup_feature_scm_assign");
    goto LABEL_16;
  }
  gh_feature_use_scm_assign = 0;
LABEL_11:
  printk(&unk_122C1, "gh_rm_setup_feature_scm_assign");
  this_vmid = 0;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return this_vmid;
}
