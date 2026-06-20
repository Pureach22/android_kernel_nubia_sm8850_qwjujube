__int64 __fastcall sde_vm_release_mem(__int64 a1)
{
  __int64 v2; // x0
  __int64 v4; // x19
  unsigned int v5; // w0
  unsigned int v6; // w0
  __int64 v7; // x1
  char v8; // w8
  unsigned int v9; // w19
  void *v10; // x0

  v2 = *(unsigned int *)(a1 + 60);
  if ( (v2 & 0x80000000) != 0 )
    return 0;
  v4 = a1;
  v5 = gh_rm_mem_release(v2, 0);
  if ( v5 )
  {
    v9 = v5;
    v10 = &unk_21BBE8;
LABEL_9:
    printk(v10, "_sde_vm_release_mem");
    return v9;
  }
  v6 = gh_rm_mem_notify(*(unsigned int *)(v4 + 60), 2, 0, 0);
  if ( v6 )
  {
    v9 = v6;
    v10 = &unk_247F04;
    goto LABEL_9;
  }
  v8 = _drm_debug;
  *(_DWORD *)(v4 + 60) = -1;
  if ( (v8 & 4) != 0 )
    printk(&unk_21820B, v7);
  else
    printk(&unk_24E8FA, "_sde_vm_release_mem");
  return 0;
}
