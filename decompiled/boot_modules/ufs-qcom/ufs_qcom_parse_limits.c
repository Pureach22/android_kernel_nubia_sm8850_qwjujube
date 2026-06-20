__int64 __fastcall ufs_qcom_parse_limits(__int64 a1)
{
  _QWORD *v2; // x8
  unsigned int v3; // w10
  __int64 v4; // x21
  _BOOL4 v5; // w8
  unsigned int v6; // w9
  int *v7; // x20
  char v8; // w0
  unsigned int v9; // w9
  int v10; // w8
  __int64 result; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x23
  unsigned __int64 v15; // x0
  unsigned __int64 v16; // x21
  unsigned __int64 v17; // x0
  _BYTE *v18; // x22
  int v19; // w3
  __int64 v20; // x8
  __int64 v21; // x0
  int v22; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v23; // [xsp+10h] [xbp-10h]
  __int64 v24; // [xsp+18h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(a1 + 16);
  v3 = *(unsigned __int8 *)(a1 + 174);
  v22 = 0;
  v4 = *(_QWORD *)(v2[8] + 744LL);
  if ( v3 >= 4 )
  {
    v6 = ((unsigned int)readl((unsigned int *)(*v2 + 208LL)) >> 4) & 7;
    v5 = *(unsigned __int8 *)(a1 + 174) > 4u;
  }
  else
  {
    v5 = 0;
    v6 = 3;
  }
  *(_DWORD *)(a1 + 316) = v6;
  v7 = (int *)(a1 + 344);
  *(_DWORD *)(a1 + 312) = v6;
  *(_QWORD *)(a1 + 304) = 0x400000004LL;
  *(_QWORD *)(a1 + 320) = 0x200000002LL;
  *(_QWORD *)(a1 + 328) = 0x200000002LL;
  *(_QWORD *)(a1 + 336) = 0x100000001LL;
  *(_QWORD *)(a1 + 344) = 0x100000002LL;
  *(_DWORD *)(a1 + 352) = 2;
  if ( v5 )
  {
    v8 = readl((unsigned int *)(**(_QWORD **)(a1 + 16) + 10316LL));
    v9 = *(unsigned __int8 *)(a1 + 174);
    if ( v9 == 5 && (v8 & 0xC0) != 0 )
    {
      v10 = 1;
LABEL_11:
      *v7 = v10;
      *(_DWORD *)(a1 + 348) = 2;
      goto LABEL_12;
    }
    if ( v9 >= 6 && (v8 & 0xC0) != 0 )
    {
      v10 = 2;
      goto LABEL_11;
    }
  }
LABEL_12:
  if ( v4 )
  {
    of_property_read_variable_u32_array(v4, "limit-tx-hs-gear", a1 + 316, 1, 0);
    of_property_read_variable_u32_array(v4, "limit-rx-hs-gear", a1 + 312, 1, 0);
    of_property_read_variable_u32_array(v4, "limit-tx-pwm-gear", a1 + 308, 1, 0);
    of_property_read_variable_u32_array(v4, "limit-rx-pwm-gear", a1 + 304, 1, 0);
    of_property_read_variable_u32_array(v4, "limit-rate", a1 + 344, 1, 0);
    of_property_read_variable_u32_array(v4, "limit-phy-submode", a1 + 348, 1, 0);
    of_property_read_variable_u32_array(v4, "ufs-dev-types", &v22, 1, 0);
    result = of_find_property(v4, "limit-rate-ufs3", 0);
    if ( result || v22 )
    {
      v12 = *(_QWORD *)(a1 + 16);
      v23 = 0;
      v13 = *(_QWORD *)(v12 + 64);
      v14 = *(_QWORD *)(v13 + 744);
      v15 = nvmem_cell_get(v13, "ufs_dev");
      if ( v15 < 0xFFFFFFFFFFFFF001LL )
      {
        v16 = v15;
        v17 = nvmem_cell_read();
        if ( v17 < 0xFFFFFFFFFFFFF001LL )
        {
          v18 = (_BYTE *)v17;
          if ( of_find_property(v14, "qcom,ufs-dev-revert", 0) )
            v19 = *v18 == 0;
          else
            v19 = (unsigned __int8)*v18;
          v20 = *(_QWORD *)(a1 + 16);
          *(_DWORD *)(a1 + 348) = v19;
          v21 = *(_QWORD *)(v20 + 64);
          if ( v19 )
          {
            dev_info(v21, "(%s) UFS device is 3.x, phy_submode = %d\n", "ufs_qcom_read_nvmem_cell", v19);
            if ( of_find_property(v14, "limit-rate-ufs3", 0) )
              *v7 = 1;
          }
          else
          {
            dev_info(v21, "(%s) UFS device is 2.x, phy_submode = %d\n", "ufs_qcom_read_nvmem_cell", 0);
          }
          kfree(v18);
        }
        else
        {
          dev_err(
            *(_QWORD *)(*(_QWORD *)(a1 + 16) + 64LL),
            "(%s) Failed to read from nvmem\n",
            "ufs_qcom_read_nvmem_cell");
        }
        result = nvmem_cell_put(v16);
      }
      else
      {
        result = dev_err(
                   *(_QWORD *)(*(_QWORD *)(a1 + 16) + 64LL),
                   "(%s) Failed to get nvmem cell\n",
                   "ufs_qcom_read_nvmem_cell");
      }
    }
  }
  else
  {
    result = dev_info(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 64LL), "%s: device_node NULL\n", "ufs_qcom_parse_limits");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
