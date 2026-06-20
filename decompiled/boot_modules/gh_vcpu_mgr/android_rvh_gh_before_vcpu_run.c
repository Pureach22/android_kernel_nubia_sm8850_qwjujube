void __fastcall android_rvh_gh_before_vcpu_run(__int64 a1, unsigned int a2, unsigned int a3)
{
  unsigned __int16 v3; // w20
  unsigned int vm_name; // w0
  __int64 v6; // x20
  __int64 v7; // x0
  __int64 v8; // x19
  unsigned __int64 StatusReg; // x8
  _QWORD v15[2]; // [xsp+0h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned __int16)a2 <= 0x3Fu )
  {
    v3 = a2;
    LODWORD(v15[0]) = 0;
    vm_name = gh_rm_get_vm_name(a2, v15);
    if ( vm_name )
    {
      printk(&unk_7AD3, v3, vm_name);
    }
    else
    {
      v6 = gh_vms + 40LL * LODWORD(v15[0]);
      if ( v6 )
      {
        if ( *(_BYTE *)(v6 + 25) == 1 )
        {
          v7 = xa_load(v6 + 8, a3);
          if ( v7 )
          {
            v8 = v7;
            _pm_stay_awake(*(_QWORD *)(v7 + 56));
            StatusReg = _ReadStatusReg(SP_EL0);
            ++*(_DWORD *)(StatusReg + 16);
            if ( *(_BYTE *)(v8 + 20) == 1 )
            {
              __asm { HVC             #0x6063 }
              v15[0] = 0;
              *(_BYTE *)(v8 + 20) = 0;
            }
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
}
