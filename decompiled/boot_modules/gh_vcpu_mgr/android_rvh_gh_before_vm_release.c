__int64 __fastcall android_rvh_gh_before_vm_release(__int64 a1, unsigned int a2)
{
  __int64 v3; // x2
  __int64 result; // x0
  __int64 v5; // x8
  unsigned int v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LOWORD(v6) = 0;
  if ( ((unsigned int)ghd_rm_get_vmid(2, &v6) || (unsigned __int16)v6 != (unsigned __int16)a2)
    && ((unsigned int)ghd_rm_get_vmid(4, &v6) || (unsigned __int16)v6 != (unsigned __int16)a2) )
  {
    result = printk(&unk_7C57, (unsigned __int16)a2, v3);
  }
  else
  {
    LOWORD(v6) = 0;
    if ( !(unsigned int)ghd_rm_get_vmid(2, &v6) && (unsigned __int16)v6 == (unsigned __int16)a2
      || (result = ghd_rm_get_vmid(4, &v6), !(_DWORD)result) && (unsigned __int16)v6 == (unsigned __int16)a2 )
    {
      v6 = 0;
      result = gh_rm_get_vm_name(a2, &v6);
      if ( (_DWORD)result )
      {
        result = printk(&unk_7AD3, (unsigned __int16)a2, (unsigned int)result);
      }
      else
      {
        v5 = gh_vms + 40LL * v6;
        if ( v5 && *(_BYTE *)(v5 + 25) == 1 )
          result = ghd_rm_vm_stop(a2, 0, 0);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
