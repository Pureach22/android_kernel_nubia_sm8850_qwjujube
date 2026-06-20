__int64 __fastcall gh_rm_minidump_deregister_slot(unsigned __int16 a1)
{
  unsigned int v1; // w0
  __int64 result; // x0
  unsigned int v3; // w19
  __int64 v4; // [xsp+0h] [xbp-20h] BYREF
  __int64 v5; // [xsp+8h] [xbp-18h] BYREF
  int v6; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+18h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = a1;
  v4 = 0;
  v5 = 0;
  v1 = gunyah_rm_call(rm, 1442840642, &v6, 4, &v5, &v4);
  if ( v1 )
  {
    v3 = v1;
    printk(&unk_132B2, "gh_rm_minidump_deregister_slot");
    result = v3;
  }
  else if ( v4 )
  {
    kfree(v5);
    printk(&unk_1372E, "gh_rm_minidump_deregister_slot");
    result = 4294967274LL;
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
