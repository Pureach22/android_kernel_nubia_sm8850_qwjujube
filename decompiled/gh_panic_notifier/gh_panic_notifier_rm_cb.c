__int64 __fastcall gh_panic_notifier_rm_cb(__int64 a1, __int64 a2, unsigned __int16 *a3)
{
  __int64 v4; // x0
  unsigned int v7; // w20
  _BYTE *recovery_vm_from_vmid; // x0
  _WORD v9[2]; // [xsp+0h] [xbp-10h] BYREF
  unsigned __int16 v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 == 1443889153 )
  {
    v4 = *(unsigned int *)(a1 - 60);
    v10 = 0;
    v9[0] = 0;
    if ( !(unsigned int)ghd_rm_get_vmid(v4, &v10)
      && !(unsigned int)ghd_rm_get_vmid(1, v9)
      && (unsigned int)a3[1] - 4 <= 2 )
    {
      v7 = *a3;
      dev_err(*(_QWORD *)(a1 - 184), "VM: %d Crashed!\n", v7);
      recovery_vm_from_vmid = (_BYTE *)get_recovery_vm_from_vmid(v7);
      if ( recovery_vm_from_vmid )
      {
        if ( (*recovery_vm_from_vmid & 1) == 0 )
        {
          if ( v10 == v7 )
            atomic_notifier_chain_unregister(&panic_notifier_list, a1 + 24);
          panic("Resetting the SoC");
        }
      }
      else
      {
        dev_err(*(_QWORD *)(a1 - 184), "Failed to get recovery vm for VM:%d!\n", v7);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}
