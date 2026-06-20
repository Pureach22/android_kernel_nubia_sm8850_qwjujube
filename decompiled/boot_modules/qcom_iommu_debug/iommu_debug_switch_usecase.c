__int64 __fastcall iommu_debug_switch_usecase(__int64 *a1, unsigned int a2)
{
  __int64 v4; // x0
  __int64 *v5; // x24
  __int64 v6; // x21
  __int64 next_child; // x0
  __int64 v8; // x1
  unsigned int v9; // w22
  __int64 v10; // x8
  __int64 v11; // x21
  unsigned int v12; // w23
  bool v13; // zf
  __int64 v14; // x0
  __int64 v15; // x23
  const char *v16; // x0
  char v17; // w8
  __int64 domain_for_dev; // x0
  __int64 result; // x0
  char *s1[2]; // [xsp+0h] [xbp-10h] BYREF

  s1[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = a1 + 4;
  v4 = a1[4];
  s1[0] = nullptr;
  if ( v4 )
  {
    of_platform_device_destroy(v4, 0);
    *v5 = 0;
    v5[1] = 0;
  }
  v6 = *(_QWORD *)(*a1 + 744);
  next_child = of_get_next_child(v6, 0);
  if ( !next_child )
    goto LABEL_26;
  v8 = next_child;
  v9 = 0;
  do
  {
    ++v9;
    v8 = of_get_next_child(v6, v8);
  }
  while ( v8 );
  if ( v9 <= a2 )
  {
LABEL_26:
    dev_err(*a1, "Invalid usecase nr requested: %u\n", a2);
    result = 0;
    goto LABEL_25;
  }
  v10 = *a1;
  *((_DWORD *)a1 + 26) = 0;
  v11 = of_get_next_child(*(_QWORD *)(v10 + 744), 0);
  if ( v11 && a2 )
  {
    v12 = a2 - 1;
    do
    {
      v11 = of_get_next_child(*(_QWORD *)(*a1 + 744), v11);
      if ( v11 )
        v13 = v12 == 0;
      else
        v13 = 1;
      --v12;
    }
    while ( !v13 );
  }
  v14 = of_platform_device_create(v11, 0, *a1);
  if ( !v14 )
  {
    dev_err(*a1, "Creating platform device failed\n");
    result = 0;
    goto LABEL_25;
  }
  v15 = v14;
  if ( (int)wait_for_completion_interruptible_timeout(a1 + 13, 125) < 1 )
  {
    dev_err(*a1, "Timed out waiting for usecase to register\n");
  }
  else
  {
    if ( (unsigned int)of_property_read_string(v11, "qcom,iommu-dma", s1) )
    {
      v16 = "default";
      s1[0] = "default";
    }
    else
    {
      v16 = s1[0];
    }
    v13 = strcmp(v16, "fastmap") == 0;
    *((_DWORD *)a1 + 12) = a2;
    v17 = v13;
    a1[4] = v15 + 16;
    *((_BYTE *)a1 + 52) = v17;
    domain_for_dev = iommu_get_domain_for_dev();
    a1[5] = domain_for_dev;
    if ( domain_for_dev )
    {
      result = *v5;
      goto LABEL_25;
    }
    dev_err(*a1, "Oops, usecase not associated with iommu\n");
  }
  result = a1[4];
  if ( result )
  {
    of_platform_device_destroy(result, 0);
    result = 0;
    *v5 = 0;
    v5[1] = 0;
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
