__int64 __fastcall cnss_remove_sysfs(_QWORD *a1)
{
  __int64 result; // x0
  _QWORD v3[4]; // [xsp+8h] [xbp-38h] BYREF
  char v4[5]; // [xsp+28h] [xbp-18h] BYREF
  __int64 v5; // [xsp+2Dh] [xbp-13h]
  __int16 v6; // [xsp+35h] [xbp-Bh]
  __int64 v7; // [xsp+38h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  strcpy(v4, "cnss");
  v6 = 0;
  memset((char *)&v3[1] + 6, 0, 18);
  strcpy((char *)v3, "shutdown_wlan");
  sysfs_remove_link(kernel_kobj, v3);
  sysfs_remove_link(kernel_kobj, v4);
  result = devres_release(*a1 + 16LL, devm_cnss_group_remove, devm_cnss_group_match, &cnss_attr_group);
  if ( (_DWORD)result )
    __break(0x800u);
  _ReadStatusReg(SP_EL0);
  return result;
}
