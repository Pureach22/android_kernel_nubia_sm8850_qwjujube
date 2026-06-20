__int64 __fastcall msm_audio_ion_probe(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x0
  __int64 v4; // x19
  bool v5; // w9
  __int64 v6; // x0
  __int64 property; // x0
  __int64 v8; // x0
  unsigned int variable_u32_array; // w0
  int v10; // w0
  __int64 result; // x0
  char v12; // w8
  unsigned int v13; // w0
  unsigned __int64 v14; // x0
  unsigned __int64 v15; // x0
  unsigned int v16; // w19
  unsigned int v17; // w20
  unsigned int v18; // w19
  __int64 v19; // [xsp+0h] [xbp-60h] BYREF
  __int64 v20; // [xsp+8h] [xbp-58h] BYREF
  __int64 v21; // [xsp+10h] [xbp-50h]
  __int64 v22; // [xsp+18h] [xbp-48h]
  __int64 v23; // [xsp+20h] [xbp-40h]
  __int64 v24; // [xsp+28h] [xbp-38h]
  __int64 v25; // [xsp+30h] [xbp-30h]
  __int64 v26; // [xsp+38h] [xbp-28h]
  __int64 v27; // [xsp+40h] [xbp-20h]
  __int64 v28; // [xsp+48h] [xbp-18h]
  __int64 v29; // [xsp+50h] [xbp-10h]
  __int64 v30; // [xsp+58h] [xbp-8h]

  v1 = a1 + 16;
  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v20 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v21 = 0;
  dev_err(a1 + 16, "%s: msm_audio_ion_probe\n", "msm_audio_ion_probe");
  if ( !*(_QWORD *)(a1 + 760) )
  {
    dev_err(v1, "%s: device tree is not found\n", "msm_audio_ion_probe");
    result = 0;
    goto LABEL_18;
  }
  v3 = devm_kmalloc(v1, 272, 3520);
  if ( v3 )
  {
    v4 = v3;
    v5 = of_find_property(*(_QWORD *)(a1 + 760), "qcom,non-hyp-assign", 0) != 0;
    v6 = *(_QWORD *)(a1 + 760);
    *(_BYTE *)(v4 + 100) = v5;
    property = of_find_property(v6, "qcom,smmu-enabled", 0);
    *(_BYTE *)v4 = property != 0;
    if ( property )
    {
      v8 = *(_QWORD *)(a1 + 760);
      *(_QWORD *)(v4 + 104) = "msm_audio_ion";
      variable_u32_array = of_property_read_variable_u32_array(v8, "qcom,smmu-version", v4 + 96, 1, 0);
      if ( (variable_u32_array & 0x80000000) != 0 )
      {
        v18 = variable_u32_array;
        dev_err(v1, "%s: qcom,smmu_version missing in DT node\n", "msm_audio_ion_probe");
        result = v18;
        goto LABEL_18;
      }
      if ( (unsigned int)of_property_read_u64(*(_QWORD *)(a1 + 760), "qcom,smmu-sid-mask", &v19) )
      {
        dev_err(v1, "%s: qcom,smmu-sid-mask missing in DT node, using default\n", "msm_audio_ion_probe");
        v19 = -1;
      }
      v10 = _of_parse_phandle_with_args(*(_QWORD *)(a1 + 760), "iommus", "#iommu-cells", 0xFFFFFFFFLL, 0, &v20);
      if ( v10 )
      {
        dev_err(v1, "%s: could not get smmu SID, ret = %d\n", "msm_audio_ion_probe", v10);
        *(_QWORD *)(v4 + 88) = 0;
LABEL_12:
        *(_QWORD *)(v4 + 8) = v1;
        v12 = msm_audio_ion_fd_list_init;
        *(_QWORD *)(a1 + 168) = v4;
        if ( (v12 & 1) == 0 )
        {
          qword_7690 = (__int64)&qword_7690;
          qword_7698 = (__int64)&qword_7690;
          ((void (*)(void))_mutex_init)();
          msm_audio_ion_fd_list_init = 1;
        }
        *(_QWORD *)(v4 + 24) = v4 + 24;
        *(_QWORD *)(v4 + 32) = v4 + 24;
        _mutex_init(v4 + 40, "&(msm_audio_ion_data->list_mutex)", &msm_audio_ion_probe___key_25);
        v13 = alloc_chrdev_region(v4 + 112, 0, 1, *(_QWORD *)(v4 + 104));
        if ( (v13 & 0x80000000) != 0 )
        {
          v16 = v13;
          printk(&unk_7BEE, "msm_audio_ion_reg_chrdev");
          v17 = v16;
        }
        else
        {
          v14 = class_create(*(_QWORD *)(v4 + 104));
          *(_QWORD *)(v4 + 120) = v14;
          if ( v14 >= 0xFFFFFFFFFFFFF001LL )
          {
            v17 = v14;
            printk(&unk_7A11, "msm_audio_ion_reg_chrdev");
          }
          else
          {
            v15 = device_create();
            *(_QWORD *)(v4 + 128) = v15;
            if ( v15 >= 0xFFFFFFFFFFFFF001LL )
            {
              v17 = v15;
              printk(&unk_7DC9, "msm_audio_ion_reg_chrdev");
            }
            else
            {
              cdev_init(v4 + 136, &msm_audio_ion_fops);
              result = cdev_add(v4 + 136, *(unsigned int *)(v4 + 112), 1);
              if ( !(_DWORD)result )
                goto LABEL_18;
              v17 = result;
              printk(&unk_794B, "msm_audio_ion_reg_chrdev");
              device_destroy(*(_QWORD *)(v4 + 120), *(unsigned int *)(v4 + 112));
            }
            class_destroy(*(_QWORD *)(v4 + 120));
          }
          unregister_chrdev_region(0, 1);
        }
        printk(&unk_7B54, "msm_audio_ion_probe");
        result = v17;
        goto LABEL_18;
      }
      *(_QWORD *)(v4 + 88) = (unsigned __int64)((unsigned int)v19 & HIDWORD(v21)) << 32;
    }
    else
    {
      *(_QWORD *)(v4 + 104) = "msm_audio_ion_cma";
    }
    *(_BYTE *)(v4 + 16) |= 1u;
    goto LABEL_12;
  }
  result = 4294967284LL;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
