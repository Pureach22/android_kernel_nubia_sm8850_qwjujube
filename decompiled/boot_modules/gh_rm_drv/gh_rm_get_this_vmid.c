__int64 __fastcall gh_rm_get_this_vmid(_WORD *a1)
{
  __int64 result; // x0
  unsigned int v4; // w0
  __int16 *v5; // x0
  unsigned int v6; // w19
  __int16 *v7; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v8[2]; // [xsp+10h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (unsigned __int16)gh_rm_get_this_vmid_cached_vmid == 0xFFFF )
  {
    v7 = nullptr;
    v8[0] = 0;
    v4 = gunyah_rm_call(rm, 1442840612, 0, 0, &v7, v8);
    if ( v4 )
    {
      v6 = v4;
      printk(&unk_126F2, "gh_rm_get_this_vmid");
      result = v6;
    }
    else if ( v8[0] )
    {
      if ( v8[0] == 4 )
      {
        v5 = v7;
        gh_rm_get_this_vmid_cached_vmid = *v7;
        *a1 = gh_rm_get_this_vmid_cached_vmid;
        kfree(v5);
        result = 0;
      }
      else
      {
        kfree(v7);
        result = 4294967222LL;
      }
    }
    else
    {
      result = 4294967222LL;
    }
  }
  else
  {
    result = 0;
    *a1 = gh_rm_get_this_vmid_cached_vmid;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
