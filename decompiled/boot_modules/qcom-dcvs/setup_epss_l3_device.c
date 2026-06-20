__int64 __fastcall setup_epss_l3_device(__int64 a1, __int64 a2, char a3)
{
  unsigned int matched; // w0
  unsigned int v7; // w0
  __int64 v8; // x23
  int variable_u32_array; // w8
  __int64 result; // x0
  __int64 v11; // x0
  __int64 v12; // x21
  int v13; // w24
  __int64 v14; // x0
  int v15; // w0
  unsigned int v16; // w21
  unsigned int v17; // w19
  unsigned int v18; // w21
  int v19; // [xsp+4h] [xbp-6Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-68h] BYREF
  __int64 v21; // [xsp+10h] [xbp-60h]
  __int64 v22; // [xsp+18h] [xbp-58h]
  __int64 v23; // [xsp+20h] [xbp-50h]
  __int64 v24; // [xsp+28h] [xbp-48h]
  __int64 v25; // [xsp+30h] [xbp-40h]
  __int64 v26; // [xsp+38h] [xbp-38h]
  __int64 v27; // [xsp+40h] [xbp-30h]
  __int64 v28; // [xsp+48h] [xbp-28h]
  __int64 v29; // [xsp+50h] [xbp-20h]
  __int64 v30; // [xsp+58h] [xbp-18h]
  __int64 v31; // [xsp+60h] [xbp-10h]
  __int64 v32; // [xsp+68h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  mutex_lock(&epss_lock);
  if ( !epss_data )
  {
    v30 = 0;
    v31 = 0;
    v28 = 0;
    v29 = 0;
    v26 = 0;
    v27 = 0;
    v24 = 0;
    v25 = 0;
    v22 = 0;
    v23 = 0;
    v20 = 0;
    v21 = 0;
    epss_data = devm_kmalloc(a1, 24, 3520);
    if ( epss_data )
    {
      matched = of_property_match_string(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 744LL), "reg-names", "l3-base");
      if ( (matched & 0x80000000) != 0 )
      {
        dev_err(a1, "%s: Unable to find l3-base: %d\n", "init_epss_data", matched);
        v17 = -22;
      }
      else
      {
        v7 = of_address_to_resource(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 744LL), matched, &v20);
        if ( (v7 & 0x80000000) == 0 )
        {
          *(_QWORD *)epss_data = devm_ioremap(*(_QWORD *)(a1 + 96));
          if ( *(_QWORD *)epss_data )
            goto LABEL_6;
          dev_err(a1, "Unable to map l3-base!\n");
          goto LABEL_28;
        }
        v17 = v7;
        dev_err(a1, "Unable to get resource from address: %d\n", v7);
      }
LABEL_29:
      mutex_unlock(&epss_lock);
      result = v17;
      goto LABEL_30;
    }
LABEL_28:
    v17 = -12;
    goto LABEL_29;
  }
LABEL_6:
  mutex_unlock(&epss_lock);
  v8 = epss_data;
  if ( (a3 & 1) != 0 )
  {
    variable_u32_array = of_property_read_variable_u32_array(
                           *(_QWORD *)(a1 + 744),
                           "qcom,shared-offset",
                           epss_data + 8,
                           1,
                           0);
    result = variable_u32_array & (unsigned int)(variable_u32_array >> 31);
    if ( variable_u32_array < 0 )
    {
      v16 = variable_u32_array & (variable_u32_array >> 31);
      dev_err(a1, "Error reading shared offset: %d\n", result);
      result = v16;
    }
    *(_QWORD *)(a2 + 128) = commit_epss_l3_shared;
    if ( (result & 0x80000000) != 0 )
      goto LABEL_30;
LABEL_21:
    result = 0;
    *(_QWORD *)(a2 + 120) = epss_data;
    goto LABEL_30;
  }
  v11 = *(_QWORD *)(a1 + 744);
  v19 = 0;
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  if ( (unsigned int)_of_parse_phandle_with_args(v11, "qcom,percpu-offsets", 0, 0, 0, &v20) || (v12 = v20) == 0 )
    v12 = *(_QWORD *)(a1 + 744);
  if ( of_find_property(v12, "qcom,percpu-offsets", &v19) )
  {
    v19 >>= 2;
    v13 = v19;
    if ( v13 == (unsigned int)_sw_hweight64(_cpu_possible_mask) )
    {
      v14 = devm_kmalloc(a1, 4LL * v19, 3520);
      *(_QWORD *)(v8 + 16) = v14;
      if ( v14 )
      {
        v15 = of_property_read_variable_u32_array(v12, "qcom,percpu-offsets", v14, v19, 0);
        if ( v15 < 0 )
        {
          v18 = v15;
          dev_err(a1, "Error reading percpu offsets from DT: %d\n", v15);
          result = v18;
        }
        else
        {
          result = 0;
        }
      }
      else
      {
        result = 4294967284LL;
      }
    }
    else
    {
      dev_err(a1, "Invalid percpu offsets table len=%d\n", v19);
      result = 4294967274LL;
    }
  }
  else
  {
    dev_err(a1, "Unable to find percpu offsets prop!\n");
    result = 4294967274LL;
  }
  *(_QWORD *)(a2 + 128) = commit_epss_l3_percpu;
  if ( (result & 0x80000000) == 0 )
    goto LABEL_21;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
