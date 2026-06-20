__int64 __fastcall syna_sysfs_debug_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  __int64 v6; // x20
  __int64 v8; // x0
  __int64 v9; // x2
  __int64 v10; // x2
  __int64 v11; // x0
  unsigned int v12; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 24);
  v12 = 0;
  v6 = *(_QWORD *)(v5 + 152);
  if ( (unsigned int)kstrtouint(a3, 10, &v12) )
    goto LABEL_2;
  if ( v12 )
  {
    if ( v12 != 1 || *(_QWORD *)(v6 + 928) )
    {
      printk(unk_32624, "syna_sysfs_debug_store", v12);
LABEL_2:
      a4 = -22;
      goto LABEL_3;
    }
    v8 = kobject_create_and_add("utility", *(_QWORD *)(v6 + 920));
    *(_QWORD *)(v6 + 928) = v8;
    if ( v8 )
    {
      if ( (sysfs_create_group(v8, &attr_debug_group) & 0x80000000) != 0 )
      {
        printk(unk_337A6, "syna_sysfs_debug_store", v10);
        kobject_put(*(_QWORD *)(v6 + 928));
        a4 = -20;
      }
    }
    else
    {
      printk(unk_330B8, "syna_sysfs_debug_store", v9);
      a4 = -20;
    }
  }
  else
  {
    v11 = *(_QWORD *)(v6 + 928);
    if ( v11 )
    {
      sysfs_remove_group(v11, &attr_debug_group);
      kobject_put(*(_QWORD *)(v6 + 928));
      *(_QWORD *)(v6 + 928) = 0;
    }
  }
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return a4;
}
