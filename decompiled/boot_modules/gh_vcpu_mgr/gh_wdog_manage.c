__int64 __fastcall gh_wdog_manage(unsigned int a1, __int64 a2, __int64 a3)
{
  char v5; // w20
  __int64 v6; // x2
  unsigned int vm_name; // w0
  __int64 v8; // x8
  unsigned int v9; // w20
  _WORD v11[2]; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (init_done & 1) != 0 )
  {
    v5 = a3;
    v11[0] = 0;
    if ( ((unsigned int)ghd_rm_get_vmid(2, v11) || v11[0] != (unsigned __int16)a1)
      && ((unsigned int)ghd_rm_get_vmid(4, v11) || v11[0] != (unsigned __int16)a1) )
    {
      printk(&unk_7DC2, (unsigned __int16)a1, v6);
      v9 = -22;
    }
    else
    {
      mutex_lock(&gh_vm_mutex);
      v12 = 0;
      vm_name = gh_rm_get_vm_name(a1, &v12);
      if ( vm_name )
      {
        printk(&unk_7AD3, (unsigned __int16)a1, vm_name);
        v9 = -19;
      }
      else
      {
        v8 = gh_vms + 40LL * v12;
        if ( v8 )
        {
          if ( (v5 & 1) != 0 )
          {
            v9 = 0;
            *(_QWORD *)(v8 + 32) = a2;
          }
          else
          {
            v9 = 0;
            *(_QWORD *)(v8 + 32) = -1;
          }
        }
        else
        {
          v9 = -19;
        }
      }
      mutex_unlock(&gh_vm_mutex);
    }
  }
  else
  {
    printk(&unk_7C16, "gh_wdog_manage", a3);
    v9 = -6;
  }
  _ReadStatusReg(SP_EL0);
  return v9;
}
