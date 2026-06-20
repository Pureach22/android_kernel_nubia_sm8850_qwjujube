__int64 __fastcall gh_unpopulate_vm_vcpu_info(unsigned int a1, unsigned int a2, __int64 a3)
{
  __int64 v5; // x2
  unsigned int vm_name; // w0
  __int64 v7; // x21
  _QWORD *v8; // x20
  __int64 v9; // x8
  __int64 result; // x0
  _WORD v11[2]; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (init_done & 1) != 0 )
  {
    v11[0] = 0;
    if ( ((unsigned int)ghd_rm_get_vmid(2, v11) || v11[0] != (unsigned __int16)a1)
      && ((unsigned int)ghd_rm_get_vmid(4, v11) || v11[0] != (unsigned __int16)a1) )
    {
      printk(&unk_7A89, (unsigned __int16)a1, v5);
    }
    else
    {
      mutex_lock(&gh_vm_mutex);
      v12 = 0;
      vm_name = gh_rm_get_vm_name(a1, &v12);
      if ( vm_name )
      {
        printk(&unk_7AD3, (unsigned __int16)a1, vm_name);
      }
      else
      {
        v7 = gh_vms + 40LL * v12;
        if ( v7 && *(_BYTE *)(v7 + 24) == 1 )
        {
          v8 = (_QWORD *)xa_load(v7 + 8, a2);
          wakeup_source_unregister(v8[7]);
          if ( v8[8] )
          {
            v9 = v8[9];
            if ( v9 )
            {
              **(_BYTE **)(v9 + 72) = 1;
              complete_all(v8[9] + 96LL);
            }
          }
          kfree(v8);
          xa_erase(v7 + 8, a2);
          --*(_DWORD *)(v7 + 4);
        }
      }
      mutex_unlock(&gh_vm_mutex);
    }
    result = 0;
  }
  else
  {
    printk(&unk_7C16, "gh_unpopulate_vm_vcpu_info", a3);
    result = 4294967290LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
