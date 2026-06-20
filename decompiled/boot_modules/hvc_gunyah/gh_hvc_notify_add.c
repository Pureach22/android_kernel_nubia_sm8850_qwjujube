__int64 __fastcall gh_hvc_notify_add(__int64 a1, unsigned int a2)
{
  unsigned int vmid; // w0
  __int64 result; // x0
  unsigned int v5; // w20
  unsigned __int16 v6; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  vmid = ghd_rm_get_vmid(a2, &v6);
  if ( vmid )
  {
    v5 = vmid;
    printk(&unk_9626, "gh_hvc_notify_add", a2, vmid);
    result = v5;
  }
  else
  {
    result = gh_rm_console_open(v6);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
