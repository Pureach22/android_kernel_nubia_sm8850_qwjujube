__int64 adsp_load_fw()
{
  __int64 v0; // x20
  __int64 v1; // x0
  __int64 *v2; // x21
  __int64 property; // x0
  __int64 v4; // x0
  __int64 v5; // x19
  int v6; // w0
  int v7; // w0
  __int64 result; // x0
  const char *v9; // x1
  _QWORD v10[2]; // [xsp+0h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = adsp_private;
  v10[0] = 0;
  if ( !adsp_private )
  {
    dev_err(16, "%s: Platform device null\n", "adsp_load_fw");
    goto LABEL_24;
  }
  v1 = *(_QWORD *)(adsp_private + 760);
  if ( !v1 )
  {
    v9 = "%s: Device tree information missing\n";
LABEL_23:
    dev_err(v0 + 16, v9, "adsp_load_fw");
    goto LABEL_24;
  }
  v2 = *(__int64 **)(adsp_private + 168);
  if ( !v2 )
  {
    v9 = " %s: Private data get failed\n";
    goto LABEL_23;
  }
  if ( (of_property_read_variable_u32_array(v1, "qcom,adsp-state") & 0x80000000) != 0 )
  {
    dev_err(v0 + 16, "%s: ADSP state = %x\n", "adsp_load_fw", HIDWORD(v10[0]));
    if ( (v2[4] & 1) == 0 )
    {
      v9 = "%s: failed to read adsp state\n";
      goto LABEL_23;
    }
    *((_BYTE *)v2 + 32) = 0;
    HIDWORD(v10[0]) = 0;
  }
  else if ( (v2[4] & 1) != 0 )
  {
    *((_BYTE *)v2 + 32) = 0;
  }
  property = of_find_property(*(_QWORD *)(v0 + 760), "qcom,proc-img-to-load", v10);
  if ( !property )
    goto LABEL_12;
  v4 = rproc_get_by_phandle(bswap32(**(_DWORD **)(property + 16)));
  *v2 = v4;
  if ( !v4 )
  {
LABEL_24:
    result = dev_err(v0 + 16, "%s: Q6 image loading failed\n", "adsp_load_fw");
    goto LABEL_25;
  }
  v5 = v4;
  v6 = strcmp(*(const char **)(v4 + 24), "modem");
  if ( !(v6 | HIDWORD(v10[0])) )
  {
    v7 = rproc_boot(v5);
    if ( (unsigned __int64)*v2 > 0xFFFFFFFFFFFFF000LL || v7 )
    {
LABEL_22:
      v9 = "%s: pil get failed,\n";
      goto LABEL_23;
    }
  }
LABEL_12:
  result = spf_core_is_apm_ready(10000);
  HIDWORD(v10[0]) = result & 1;
  if ( (result & 1) == 0 )
  {
    if ( v2[3] )
    {
      dev_info(v0 + 16, "%s: Load ADSP with fw name %s\n", "adsp_load_fw");
      if ( (unsigned int)rproc_set_firmware(*v2, v2[3]) )
      {
        v9 = "%s: rproc set firmware failed,\n";
        goto LABEL_23;
      }
    }
    else
    {
      dev_info(v0 + 16, "%s: Load default ADSP\n", "adsp_load_fw");
    }
    result = rproc_boot(*v2);
    if ( (_DWORD)result )
      goto LABEL_22;
  }
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
