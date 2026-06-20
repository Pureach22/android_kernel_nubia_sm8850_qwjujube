unsigned __int64 __fastcall android_rvh_gh_before_vcpu_release(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v5; // x20
  __int64 v6; // x2
  unsigned __int64 result; // x0
  __int64 v8; // x8
  unsigned __int64 v9; // x22
  unsigned __int64 v10; // x19
  unsigned int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(int *)(a3 + 188);
  LOWORD(v11) = 0;
  if ( ((unsigned int)ghd_rm_get_vmid(2, &v11) || (unsigned __int16)v11 != (unsigned __int16)a2)
    && ((unsigned int)ghd_rm_get_vmid(4, &v11) || (unsigned __int16)v11 != (unsigned __int16)a2) )
  {
    result = printk(&unk_7C57, (unsigned __int16)a2, v6);
  }
  else
  {
    LOWORD(v11) = 0;
    if ( !(unsigned int)ghd_rm_get_vmid(2, &v11) && (unsigned __int16)v11 == (unsigned __int16)a2
      || (result = ghd_rm_get_vmid(4, &v11), !(_DWORD)result) && (unsigned __int16)v11 == (unsigned __int16)a2 )
    {
      v11 = 0;
      result = gh_rm_get_vm_name(a2, &v11);
      if ( (_DWORD)result )
      {
        result = printk(&unk_7AD3, (unsigned __int16)a2, (unsigned int)result);
      }
      else
      {
        v8 = gh_vms + 40LL * v11;
        if ( v8 )
        {
          if ( *(_BYTE *)(v8 + 25) == 1 )
          {
            result = xa_load(v8 + 8, v5);
            if ( result )
            {
              if ( !**(_BYTE **)(a3 + 72) )
              {
                v9 = result;
                result = gunyah_vm_get(*(_QWORD *)(a3 + 64));
                if ( (_DWORD)result )
                {
                  *(_QWORD *)(v9 + 72) = a3;
                  result = kthread_create_on_node(
                             gh_vcpu_kthread,
                             v9,
                             0xFFFFFFFFLL,
                             "vm%d_vcpu%d_kthread",
                             (unsigned __int16)a2,
                             v5);
                  v10 = result;
                  if ( result <= 0xFFFFFFFFFFFFF000LL )
                    result = wake_up_process(result);
                  *(_QWORD *)(v9 + 64) = v10;
                }
              }
            }
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
