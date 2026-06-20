__int64 __fastcall sde_vm_reclaim_mem(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v3; // w0
  __int64 v4; // x1
  unsigned int v5; // w19

  v1 = *(_QWORD *)(a1 + 6384);
  if ( (*(_DWORD *)(v1 + 60) & 0x80000000) != 0 )
    return 0;
  v3 = ghd_rm_mem_reclaim();
  if ( v3 )
  {
    v5 = v3;
    printk(&unk_23067A, "_sde_vm_reclaim_mem");
    return v5;
  }
  else
  {
    if ( (_drm_debug & 4) != 0 )
      printk(&unk_22CDB7, v4);
    else
      printk(&unk_226084, "_sde_vm_reclaim_mem");
    *(_DWORD *)(v1 + 60) = -1;
    return 0;
  }
}
