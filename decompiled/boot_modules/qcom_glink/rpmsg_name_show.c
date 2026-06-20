__int64 __fastcall rpmsg_name_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v5; // x0
  const char *v6; // x2
  __int64 result; // x0
  _QWORD v8[2]; // [xsp+0h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 744);
  v8[0] = 0;
  if ( (of_property_read_string(v5, "label", v8) & 0x80000000) != 0 )
  {
    v6 = **(const char ***)(a1 + 744);
    v8[0] = v6;
  }
  else
  {
    v6 = (const char *)v8[0];
  }
  LODWORD(result) = sysfs_emit(a3, "%s\n", v6);
  _ReadStatusReg(SP_EL0);
  return (int)result;
}
