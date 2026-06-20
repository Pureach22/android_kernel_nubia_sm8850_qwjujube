__int64 __fastcall msm_ext_disp_probe(__int64 a1)
{
  __int64 v1; // x22
  __int64 v3; // x0
  __int64 v4; // x19
  unsigned __int64 v5; // x0
  unsigned int v6; // w20
  unsigned int v7; // w0
  __int64 v8; // x8
  unsigned __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x8
  void *v12; // x0

  if ( !a1 )
  {
    v12 = &unk_717B;
LABEL_20:
    printk(v12, "msm_ext_disp_probe");
    return (unsigned int)-19;
  }
  v1 = *(_QWORD *)(a1 + 760);
  if ( !v1 )
  {
    v12 = &unk_7041;
    goto LABEL_20;
  }
  v3 = devm_kmalloc(a1 + 16, 144, 3520);
  if ( v3 )
  {
    v4 = v3;
    *(_QWORD *)(a1 + 168) = v3;
    *(_QWORD *)(v3 + 16) = a1;
    v5 = devm_extcon_dev_allocate(a1 + 16, &msm_ext_disp_supported_cable);
    v6 = v5;
    *(_QWORD *)(v4 + 48) = v5;
    if ( v5 <= 0xFFFFFFFFFFFFF000LL )
    {
      v7 = devm_extcon_dev_register(*(_QWORD *)(v4 + 16) + 16LL, v5);
      if ( v7 )
        goto LABEL_22;
      v8 = *(_QWORD *)(v4 + 16);
      if ( !v8 )
      {
        printk(&unk_7161, "msm_ext_disp_extcon_register");
        v6 = -22;
        goto LABEL_11;
      }
      v9 = devm_extcon_dev_allocate(v8 + 16, &msm_ext_disp_supported_cable);
      *(_QWORD *)(v4 + 56) = v9;
      if ( v9 > 0xFFFFFFFFFFFFF000LL )
      {
        v6 = v9;
        goto LABEL_11;
      }
      v7 = devm_extcon_dev_register(*(_QWORD *)(v4 + 16) + 16LL, v9);
      if ( v7 )
      {
LABEL_22:
        v6 = v7;
        printk(&unk_72AB, "msm_ext_disp_extcon_register");
        goto LABEL_11;
      }
      v6 = of_platform_populate(v1, 0, 0, a1 + 16);
      if ( !v6 )
      {
        _mutex_init(v4 + 88, "&ext_disp->lock", &msm_ext_disp_probe___key);
        *(_QWORD *)(v4 + 72) = v4 + 72;
        *(_QWORD *)(v4 + 80) = v4 + 72;
        *(_DWORD *)(v4 + 24) = -1;
        *(_BYTE *)(v4 + 136) = 0;
        return v6;
      }
      printk(&unk_708F, "msm_ext_disp_probe");
    }
LABEL_11:
    v10 = *(_QWORD *)(v4 + 16);
    if ( v10 )
    {
      devm_extcon_dev_unregister(v10 + 16, *(_QWORD *)(v4 + 48));
      v11 = *(_QWORD *)(v4 + 16);
      if ( v11 )
      {
LABEL_13:
        devm_extcon_dev_unregister(v11 + 16, *(_QWORD *)(v4 + 56));
LABEL_14:
        devm_kfree(*(_QWORD *)(v4 + 16) + 16LL, v4);
        return v6;
      }
    }
    else
    {
      printk(&unk_7309, "msm_ext_disp_extcon_unregister");
      v11 = *(_QWORD *)(v4 + 16);
      if ( v11 )
        goto LABEL_13;
    }
    printk(&unk_7309, "msm_ext_disp_extcon_unregister");
    goto LABEL_14;
  }
  return (unsigned int)-12;
}
