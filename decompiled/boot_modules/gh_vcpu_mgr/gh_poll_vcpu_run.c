__int64 __fastcall gh_poll_vcpu_run(__int64 a1)
{
  unsigned int v1; // w19
  unsigned int vm_name; // w0
  __int64 v3; // x28
  __int64 v4; // x8
  __int64 v5; // x20
  __int64 v6; // x21
  __int64 v7; // x0
  __int64 v8; // x24
  __int64 v9; // x0
  unsigned int v15; // w22
  _QWORD v17[2]; // [xsp+20h] [xbp-10h] BYREF

  v1 = a1;
  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v17[0]) = 0;
  vm_name = gh_rm_get_vm_name(a1, v17);
  if ( vm_name )
    goto LABEL_15;
  v3 = gh_vms + 40LL * LODWORD(v17[0]);
  if ( !v3 || *(_BYTE *)(v3 + 25) != 1 )
    goto LABEL_16;
  LODWORD(v17[0]) = 0;
  vm_name = gh_rm_get_vm_name(v1, v17);
  if ( vm_name )
  {
LABEL_15:
    printk(&unk_7AD3, (unsigned __int16)v1, vm_name);
  }
  else
  {
    v4 = gh_vms + 40LL * LODWORD(v17[0]);
    if ( v4 && *(_BYTE *)(v4 + 24) == 1 )
    {
      v5 = *(unsigned int *)(v4 + 4);
      if ( (v5 & 0x80000000) != 0 )
      {
        printk_deferred("Failed to get vcpu count for VM %d ret %d\n", (unsigned __int16)v1, v5);
        v15 = v5;
        goto LABEL_17;
      }
      if ( (_DWORD)v5 )
      {
        v6 = 0;
        _ReadStatusReg(SP_EL0);
        while ( 1 )
        {
          v7 = xa_load(v3 + 8, v6);
          if ( !v7 )
            break;
          v8 = v7;
          if ( *(_QWORD *)(v7 + 8) == -1 )
            break;
          do
          {
            ktime_get();
            v9 = *(_QWORD *)(v8 + 8);
            __asm { HVC             #0x6065 }
            v17[0] = 0;
            v15 = v9;
            ktime_get();
          }
          while ( v15 == -2 );
          if ( ++v6 == v5 )
            goto LABEL_17;
        }
      }
    }
  }
LABEL_16:
  v15 = -1;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return v15;
}
