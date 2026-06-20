__int64 __fastcall gh_populate_all_res_info(unsigned int a1, char a2, __int64 a3)
{
  __int64 v5; // x2
  unsigned int vm_name; // w0
  __int64 v7; // x8
  __int64 result; // x0
  _WORD v9[2]; // [xsp+0h] [xbp-10h] BYREF
  unsigned int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (init_done & 1) != 0 )
  {
    v9[0] = 0;
    if ( ((unsigned int)ghd_rm_get_vmid(2, v9) || v9[0] != (unsigned __int16)a1)
      && ((unsigned int)ghd_rm_get_vmid(4, v9) || v9[0] != (unsigned __int16)a1) )
    {
      result = printk(&unk_7C57, (unsigned __int16)a1, v5);
    }
    else
    {
      mutex_lock(&gh_vm_mutex);
      v10 = 0;
      vm_name = gh_rm_get_vm_name(a1, &v10);
      if ( vm_name )
      {
        printk(&unk_7AD3, (unsigned __int16)a1, vm_name);
      }
      else
      {
        v7 = gh_vms + 40LL * v10;
        if ( v7 )
        {
          if ( (a2 & 1) != 0 )
          {
            if ( (*(_BYTE *)(v7 + 24) & 1) == 0 )
              *(_WORD *)(v7 + 24) = 257;
          }
          else if ( *(_BYTE *)(v7 + 24) )
          {
            *(_DWORD *)(v7 + 4) = 0;
            *(_WORD *)v7 = -1;
            *(_WORD *)(v7 + 24) = 0;
          }
        }
      }
      result = mutex_unlock(&gh_vm_mutex);
    }
  }
  else
  {
    result = printk(&unk_7C16, "gh_populate_all_res_info", a3);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
