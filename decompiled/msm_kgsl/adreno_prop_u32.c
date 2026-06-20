__int64 __fastcall adreno_prop_u32(__int64 a1, int *a2)
{
  int v3; // w8
  int partinfo_vulkan_id; // w8
  __int64 gpu_model_node; // x0
  __int64 v7; // x8
  const char *v8; // x1
  __int64 result; // x0
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a2;
  v10 = 0;
  if ( v3 <= 41 )
  {
    if ( v3 <= 25 )
    {
      if ( v3 == 23 )
      {
        partinfo_vulkan_id = *(_DWORD *)(a1 + 20652);
        goto LABEL_31;
      }
      if ( v3 == 24 )
      {
        if ( **(_DWORD **)(a1 + 14264) <= 0x1F3u )
          partinfo_vulkan_id = 32;
        else
          partinfo_vulkan_id = 48;
        goto LABEL_31;
      }
      goto LABEL_32;
    }
    switch ( v3 )
    {
      case 26:
        v7 = *(_QWORD *)(a1 + 11168);
        v8 = "qcom,min-access-length";
        break;
      case 27:
        v7 = *(_QWORD *)(a1 + 11168);
        v8 = "qcom,ubwc-mode";
        break;
      case 37:
        partinfo_vulkan_id = *(_DWORD *)(a1 + 13176);
LABEL_31:
        v10 = partinfo_vulkan_id;
        goto LABEL_32;
      default:
        goto LABEL_32;
    }
    of_property_read_variable_u32_array(*(_QWORD *)(v7 + 760), v8, &v10, 1, 0);
    goto LABEL_32;
  }
  if ( v3 <= 44 )
  {
    if ( v3 == 42 )
    {
      partinfo_vulkan_id = adreno_get_vk_device_id_device_id;
      if ( !adreno_get_vk_device_id_device_id )
      {
        gpu_model_node = adreno_get_gpu_model_node(*(_QWORD *)(a1 + 11168));
        if ( !gpu_model_node )
          gpu_model_node = *(_QWORD *)(*(_QWORD *)(a1 + 11168) + 760LL);
        if ( (of_property_read_variable_u32_array(
                gpu_model_node,
                "qcom,vk-device-id",
                &adreno_get_vk_device_id_device_id,
                1,
                0)
            & 0x80000000) != 0 )
        {
          partinfo_vulkan_id = socinfo_get_partinfo_vulkan_id(1);
          if ( !partinfo_vulkan_id )
            partinfo_vulkan_id = *(_DWORD *)(a1 + 14248);
          adreno_get_vk_device_id_device_id = partinfo_vulkan_id;
        }
        else
        {
          partinfo_vulkan_id = adreno_get_vk_device_id_device_id;
        }
      }
      goto LABEL_31;
    }
    if ( v3 == 43 )
    {
      partinfo_vulkan_id = *(unsigned __int8 *)(a1 + 20440);
      goto LABEL_31;
    }
  }
  else
  {
    switch ( v3 )
    {
      case '-':
        partinfo_vulkan_id = *(unsigned __int8 *)(a1 + 24026);
        goto LABEL_31;
      case '.':
        partinfo_vulkan_id = *(unsigned __int8 *)(a1 + 24025);
        goto LABEL_31;
      case '0':
        partinfo_vulkan_id = (*(_DWORD *)(*(_QWORD *)(a1 + 14264) + 32LL) >> 18) & 1;
        goto LABEL_31;
    }
  }
LABEL_32:
  result = copy_prop(a2, &v10, 4);
  _ReadStatusReg(SP_EL0);
  return result;
}
