__int64 __fastcall cvp_read_platform_resources_from_drv_data(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 *v4; // x22
  char v6; // w10
  __int64 v7; // x23
  __int64 v8; // x20
  int v9; // w8
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x23
  __int64 v13; // x20
  int v14; // w8
  __int64 v15; // x23
  __int64 v16; // x20
  int v17; // w8
  __int64 v18; // x23
  __int64 v19; // x20
  int v20; // w8
  __int64 v21; // x23
  __int64 v22; // x20
  int v23; // w8
  int v24; // w9
  int v25; // w8
  int v26; // w8
  __int64 v27; // x9
  __int64 v28; // x23
  __int64 v29; // x20
  int v30; // w8
  __int64 v31; // x23
  __int64 v32; // x20
  bool v33; // w8
  __int64 v34; // x23
  __int64 v35; // x20
  int v36; // w8
  __int64 v37; // x23
  __int64 v38; // x20
  int v39; // w8
  __int64 v40; // x23
  __int64 v41; // x20
  int v42; // w8
  __int64 v43; // x23
  __int64 v44; // x20
  bool v45; // w8
  __int64 v46; // x23
  __int64 v47; // x20
  int v48; // w8
  __int64 v49; // x23
  __int64 v50; // x20
  int v51; // w8
  __int64 v52; // x8

  if ( a1 && (v4 = *(__int64 **)(a1 + 264)) != nullptr )
  {
    v6 = BYTE1(msm_cvp_debug);
    *(_DWORD *)(a1 + 760) = *((_DWORD *)v4 + 3);
    *(_QWORD *)(a1 + 968) = "evass";
    if ( (v6 & 1) != 0 && !msm_cvp_debug_out )
      printk(&unk_8CC70, "core", "evass", a4);
    v7 = *((unsigned int *)v4 + 2);
    if ( (int)v7 < 1 )
    {
LABEL_10:
      v9 = 0;
    }
    else
    {
      v8 = *v4;
      while ( strcmp((const char *)v8, "qcom,dsp-enabled") )
      {
        --v7;
        v8 += 132;
        if ( !v7 )
          goto LABEL_10;
      }
      v9 = *(_DWORD *)(v8 + 128);
    }
    *(_BYTE *)(a1 + 938) = v9 != 0;
    v12 = *((unsigned int *)v4 + 2);
    if ( (int)v12 < 1 )
    {
LABEL_19:
      v14 = 0;
    }
    else
    {
      v13 = *v4;
      while ( strcmp((const char *)v13, "qcom,max-ssr-allowed") )
      {
        --v12;
        v13 += 132;
        if ( !v12 )
          goto LABEL_19;
      }
      v14 = *(_DWORD *)(v13 + 128);
    }
    *(_DWORD *)(a1 + 856) = v14;
    v15 = *((unsigned int *)v4 + 2);
    if ( (int)v15 < 1 )
    {
LABEL_25:
      v17 = 0;
    }
    else
    {
      v16 = *v4;
      while ( strcmp((const char *)v16, "qcom,sw-power-collapse") )
      {
        --v15;
        v16 += 132;
        if ( !v15 )
          goto LABEL_25;
      }
      v17 = *(_DWORD *)(v16 + 128);
    }
    *(_BYTE *)(a1 + 937) = v17 != 0;
    v18 = *((unsigned int *)v4 + 2);
    if ( (int)v18 < 1 )
    {
LABEL_31:
      v20 = 0;
    }
    else
    {
      v19 = *v4;
      while ( strcmp((const char *)v19, "qcom,debug-timeout") )
      {
        --v18;
        v19 += 132;
        if ( !v18 )
          goto LABEL_31;
      }
      v20 = *(_DWORD *)(v19 + 128);
    }
    *(_BYTE *)(a1 + 984) = v20 != 0;
    v21 = *((unsigned int *)v4 + 2);
    if ( (int)v21 < 1 )
    {
LABEL_37:
      v23 = 0;
    }
    else
    {
      v22 = *v4;
      while ( strcmp((const char *)v22, "qcom,pm-qos-latency-us") )
      {
        --v21;
        v22 += 132;
        if ( !v21 )
          goto LABEL_37;
      }
      v23 = *(_DWORD *)(v22 + 128);
    }
    *(_DWORD *)(a1 + 996) = v23;
    v24 = platform_get_resource;
    *(_DWORD *)(a1 + 992) = 0;
    if ( !v24 )
    {
      v25 = iommu_get_domain_for_dev;
      *(_DWORD *)(a1 + 992) = 1;
      if ( v25 )
      {
        v26 = 0;
        v27 = 1000;
      }
      else
      {
        v27 = 1004;
        *(_DWORD *)(a1 + 1000) = 0;
        *(_DWORD *)(a1 + 992) = 2;
        v26 = 1;
      }
      *(_DWORD *)(a1 + v27) = v26;
    }
    v28 = *((unsigned int *)v4 + 2);
    if ( (int)v28 < 1 )
    {
LABEL_48:
      v30 = 0;
    }
    else
    {
      v29 = *v4;
      while ( strcmp((const char *)v29, "qcom,max-secure-instances") )
      {
        --v28;
        v29 += 132;
        if ( !v28 )
          goto LABEL_48;
      }
      v30 = *(_DWORD *)(v29 + 128);
    }
    *(_DWORD *)(a1 + 1020) = v30;
    v31 = *((unsigned int *)v4 + 2);
    if ( (int)v31 < 1 )
    {
LABEL_54:
      v33 = 0;
    }
    else
    {
      v32 = *v4;
      while ( strcmp((const char *)v32, "qcom,enable-thermal-mitigation") )
      {
        --v31;
        v32 += 132;
        if ( !v31 )
          goto LABEL_54;
      }
      v33 = *(_DWORD *)(v32 + 128) != 0;
    }
    *(_BYTE *)(a1 + 960) = v33;
    v34 = *((unsigned int *)v4 + 2);
    if ( (int)v34 < 1 )
    {
LABEL_60:
      v36 = 0;
    }
    else
    {
      v35 = *v4;
      while ( strcmp((const char *)v35, "qcom,power-collapse-delay") )
      {
        --v34;
        v35 += 132;
        if ( !v34 )
          goto LABEL_60;
      }
      v36 = *(_DWORD *)(v35 + 128);
    }
    *(_DWORD *)(a1 + 1040) = v36;
    v37 = *((unsigned int *)v4 + 2);
    if ( (int)v37 < 1 )
    {
LABEL_66:
      v39 = 0;
    }
    else
    {
      v38 = *v4;
      while ( strcmp((const char *)v38, "qcom,hw-resp-timeout") )
      {
        --v37;
        v38 += 132;
        if ( !v37 )
          goto LABEL_66;
      }
      v39 = *(_DWORD *)(v38 + 128);
    }
    *(_DWORD *)(a1 + 1024) = v39;
    v40 = *((unsigned int *)v4 + 2);
    if ( (int)v40 < 1 )
    {
LABEL_72:
      v42 = 0;
    }
    else
    {
      v41 = *v4;
      while ( strcmp((const char *)v41, "qcom,dsp-resp-timeout") )
      {
        --v40;
        v41 += 132;
        if ( !v40 )
          goto LABEL_72;
      }
      v42 = *(_DWORD *)(v41 + 128);
    }
    *(_DWORD *)(a1 + 1028) = v42;
    v43 = *((unsigned int *)v4 + 2);
    if ( (int)v43 < 1 )
    {
LABEL_78:
      v45 = 0;
    }
    else
    {
      v44 = *v4;
      while ( strcmp((const char *)v44, "qcom,domain-attr-non-fatal-faults") )
      {
        --v43;
        v44 += 132;
        if ( !v43 )
          goto LABEL_78;
      }
      v45 = *(_DWORD *)(v44 + 128) != 0;
    }
    *(_BYTE *)(a1 + 1044) = v45;
    v46 = *((unsigned int *)v4 + 2);
    if ( (int)v46 < 1 )
    {
LABEL_84:
      v48 = 0;
    }
    else
    {
      v47 = *v4;
      while ( strcmp((const char *)v47, "qcom,qos_noc_urgency_low_a_bitmask") )
      {
        --v46;
        v47 += 132;
        if ( !v46 )
          goto LABEL_84;
      }
      v48 = *(_DWORD *)(v47 + 128);
    }
    *(_DWORD *)(a1 + 1032) = v48;
    v49 = *((unsigned int *)v4 + 2);
    if ( (int)v49 < 1 )
    {
LABEL_90:
      v51 = 0;
    }
    else
    {
      v50 = *v4;
      while ( strcmp((const char *)v50, "qcom,qos_noc_urgency_low_b_bitmask") )
      {
        --v49;
        v50 += 132;
        if ( !v49 )
          goto LABEL_90;
      }
      v51 = *(_DWORD *)(v50 + 128);
    }
    *(_DWORD *)(a1 + 1036) = v51;
    *(_DWORD *)(a1 + 1056) = *((_DWORD *)v4 + 4);
    v52 = v4[3];
    *(_BYTE *)(a1 + 1045) = 0;
    *(_QWORD *)(a1 + 1064) = v52;
    return 0;
  }
  else
  {
    result = 4294967294LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_93674, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 4294967294LL;
    }
  }
  return result;
}
