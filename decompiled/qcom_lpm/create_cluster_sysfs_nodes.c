__int64 __fastcall create_cluster_sysfs_nodes(_QWORD *a1)
{
  __int64 v1; // x24
  __int64 v3; // x0
  unsigned __int64 v4; // x20
  __int64 v5; // x0
  __int64 v6; // x22
  __int64 v7; // x0
  __int64 v8; // x23
  __int64 v9; // x0
  _QWORD *v10; // x0
  __int64 v11; // x9
  _QWORD *v12; // x8
  __int64 result; // x0
  __int64 v14; // [xsp+8h] [xbp-18h] BYREF
  __int16 v15; // [xsp+10h] [xbp-10h]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( qcom_lpm_kobj )
  {
    v1 = a1[20];
    v15 = 0;
    v14 = 0;
    v3 = kobject_create_and_add(*(_QWORD *)(v1 + 1288));
    a1[25] = v3;
    if ( !v3 )
    {
LABEL_16:
      result = 4294967284LL;
      goto LABEL_17;
    }
    if ( *(_DWORD *)(v1 + 1456) )
    {
      v4 = 0;
      while ( 1 )
      {
        v5 = devm_kmalloc(*a1, 72, 3520);
        if ( !v5 )
          break;
        v6 = v5;
        *(_DWORD *)(v5 + 16) = v4;
        *(_QWORD *)v5 = a1;
        scnprintf(&v14, 4096, "D%u", v4);
        v7 = kobject_create_and_add(&v14);
        *(_QWORD *)(v6 + 8) = v7;
        if ( !v7 )
          break;
        v8 = *a1;
        v9 = devm_kmalloc(*a1, 40, 3520);
        *(_QWORD *)(v6 + 56) = v9;
        if ( !v9 )
          goto LABEL_14;
        v10 = (_QWORD *)devm_kmalloc(v8, 16, 3520);
        *(_QWORD *)(v6 + 64) = v10;
        if ( !v10 )
          goto LABEL_14;
        v11 = *(_QWORD *)(v6 + 56);
        *(_QWORD *)(v6 + 24) = "disable";
        *(_WORD *)(v6 + 32) = 420;
        *(_QWORD *)(v6 + 40) = cluster_idle_get;
        *(_QWORD *)(v6 + 48) = cluster_idle_set;
        *v10 = v6 + 24;
        v10[1] = 0;
        *(_QWORD *)(v11 + 24) = v10;
        if ( (unsigned int)sysfs_create_group(*(_QWORD *)(v6 + 8), *(_QWORD *)(v6 + 56)) )
        {
LABEL_14:
          kobject_put(*(_QWORD *)(v6 + 8));
          break;
        }
        if ( v4 == 4 )
          __break(0x5512u);
        v12 = &a1[v4++];
        v12[21] = v6;
        if ( v4 >= *(unsigned int *)(v1 + 1456) )
          goto LABEL_12;
      }
      kobject_put(a1[25]);
      goto LABEL_16;
    }
LABEL_12:
    result = 0;
  }
  else
  {
    result = 4294966779LL;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
