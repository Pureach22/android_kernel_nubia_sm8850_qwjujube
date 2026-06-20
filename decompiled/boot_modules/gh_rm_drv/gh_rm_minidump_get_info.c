__int64 gh_rm_minidump_get_info()
{
  unsigned int v0; // w0
  unsigned int v1; // w19
  __int64 v3; // [xsp+0h] [xbp-20h] BYREF
  unsigned __int16 *v4; // [xsp+8h] [xbp-18h] BYREF
  int v5; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+18h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  if ( rm )
  {
    v3 = 0;
    v4 = nullptr;
    v0 = gunyah_rm_call(rm, 1442840640, &v5, 4, &v4, &v3);
    if ( v0 )
    {
      v1 = v0;
      printk(&unk_132B2, "gh_rm_minidump_get_info");
    }
    else if ( v3 == 4 )
    {
      v1 = *v4;
      kfree(v4);
    }
    else
    {
      printk(&unk_1372E, "gh_rm_minidump_get_info");
      if ( v3 )
        kfree(v4);
      v1 = -22;
    }
  }
  else
  {
    v1 = -517;
  }
  _ReadStatusReg(SP_EL0);
  return v1;
}
