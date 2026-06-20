void __fastcall hfi_kms_resource_vote_hfi_prop_handler(__int64 a1, int a2, __int64 a3, unsigned int a4, __int64 a5)
{
  __int64 v5; // x28
  int v6; // w27
  int v7; // w25
  int v8; // w19
  __int64 v9; // x26
  __int64 **v10; // x20
  int v11; // w8
  __int64 v12; // [xsp+0h] [xbp-90h]
  __int64 v13; // [xsp+8h] [xbp-88h]
  __int64 v14; // [xsp+10h] [xbp-80h]
  __int64 v15; // [xsp+18h] [xbp-78h]
  __int64 v16; // [xsp+20h] [xbp-70h]
  __int64 v17; // [xsp+28h] [xbp-68h]

  if ( !a3 || !a5 || a2 != 16777225 || a4 < 0x10 )
    return;
  v5 = a4 >> 4;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a5 - 168) + 136LL) + 56LL);
  v10 = (__int64 **)(a3 + 8);
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v12 = 0;
  do
  {
    v11 = *((_DWORD *)v10 - 2);
    if ( v11 <= 65554 )
    {
      switch ( v11 )
      {
        case 65552:
          v8 = 1;
          v12 = **v10;
          break;
        case 65553:
          v8 = 1;
          v13 = **v10;
          break;
        case 65554:
          msm_dss_enable_vreg(*(_QWORD *)(v9 + 24), *(unsigned int *)(v9 + 16), *(unsigned int *)*v10);
          break;
      }
    }
    else if ( v11 > 65556 )
    {
      if ( v11 == 65557 )
      {
        v16 = **v10;
      }
      else
      {
        if ( v11 != 65558 )
          goto LABEL_7;
        v17 = **v10;
      }
      v7 = 1;
    }
    else
    {
      v6 = 1;
      if ( v11 == 65555 )
        v14 = **v10;
      else
        v15 = **v10;
    }
LABEL_7:
    --v5;
    v10 += 2;
  }
  while ( v5 );
  if ( v8 && (unsigned int)sde_power_data_bus_set_quota(v9 + 16, 0, v12, v13) )
  {
    printk(&unk_23EE78, "hfi_kms_resource_vote_hfi_prop_handler");
    if ( v6 )
      goto LABEL_26;
  }
  else if ( v6 )
  {
LABEL_26:
    if ( (unsigned int)sde_power_data_bus_set_quota(v9 + 16, 1, v14, v15) )
      printk(&unk_23EE78, "hfi_kms_resource_vote_hfi_prop_handler");
  }
  if ( v7 )
  {
    if ( (unsigned int)sde_power_data_bus_set_quota(v9 + 16, 2, v16, v17) )
      printk(&unk_23EE78, "hfi_kms_resource_vote_hfi_prop_handler");
  }
}
