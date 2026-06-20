__int64 __fastcall enable_source_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v6; // w0
  __int64 v7; // x0
  int v8; // w0
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10[0] = 0;
  v6 = kstrtoull(a3, 10, v10);
  if ( v6 )
  {
    a4 = v6;
  }
  else
  {
    v7 = a1 - 56;
    if ( v10[0] )
    {
      v8 = coresight_enable_sysfs(v7);
      if ( v8 )
        a4 = v8;
    }
    else
    {
      coresight_disable_sysfs(v7);
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
