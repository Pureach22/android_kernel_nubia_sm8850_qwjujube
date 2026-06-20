unsigned __int64 __fastcall mpam_msc_slc_probe(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x0
  __int64 v4; // x20
  unsigned __int64 result; // x0
  __int64 (*v6)(void); // x8
  unsigned __int64 v7; // x0
  __int64 v8; // x1
  const char *v9; // x2
  __int64 v10; // x0
  unsigned __int64 v11; // x0
  __int64 v12; // x22
  unsigned int variable_u32_array; // w0
  unsigned int string; // w0
  unsigned int v15; // w0
  int v16; // w1
  __int64 resource_byname; // x0
  unsigned __int64 v18; // x0
  unsigned int v19; // w0
  __int64 v20; // x0
  unsigned int v21; // w21
  unsigned int v22; // w0
  unsigned int v23; // w8
  unsigned int started; // w0
  const char *v25; // x1
  __int64 v26; // [xsp+0h] [xbp-20h]
  __int64 v27; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v28[2]; // [xsp+10h] [xbp-10h] BYREF

  v1 = a1 + 16;
  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v3 = devm_kmalloc(a1 + 16, 92, 3520);
  if ( v3 )
  {
    v4 = v3;
    *(_DWORD *)(v3 + 88) = 1;
    result = get_qcom_scmi_device();
    *(_QWORD *)(v4 + 32) = result;
    if ( result < 0xFFFFFFFFFFFFF001LL )
    {
      v6 = *(__int64 (**)(void))(*(_QWORD *)(result + 928) + 24LL);
      if ( *((_DWORD *)v6 - 1) != -1171826031 )
        __break(0x8228u);
      v7 = v6();
      *(_QWORD *)(v4 + 40) = v7;
      if ( v7 >= 0xFFFFFFFFFFFFF001LL )
      {
        v8 = v7;
        v9 = "Error getting vendor protocol ops\n";
LABEL_7:
        v10 = v1;
LABEL_19:
        result = dev_err_probe(v10, v8, v9);
        goto LABEL_20;
      }
      v11 = devm_clk_get(v1, "qdss_clk");
      llcc_perfmon_clock = v11;
      if ( !v11 || v11 >= 0xFFFFFFFFFFFFF001LL )
      {
        printk(&unk_8300);
        llcc_perfmon_clock = 0;
      }
      v12 = *(_QWORD *)(a1 + 760);
      *(_BYTE *)(v4 + 13) = 0;
      *(_WORD *)(v4 + 14) = 2;
      *(_QWORD *)(v4 + 24) = &slc_msc_ops;
      *(_QWORD *)(v4 + 56) = v1;
      variable_u32_array = of_property_read_variable_u32_array(v12, "qcom,dev-index", (char *)&v27 + 4, 1, 0);
      if ( (variable_u32_array & 0x80000000) != 0 )
      {
        v8 = variable_u32_array;
        v9 = "qcom,dev-index Node failed!\n";
LABEL_18:
        v10 = v1;
        goto LABEL_19;
      }
      if ( HIDWORD(v27) >= 0x100 )
      {
        v9 = "dev-index wrong value failed!\n";
LABEL_14:
        v10 = v1;
        v8 = 4294967274LL;
        goto LABEL_19;
      }
      *(_BYTE *)(v4 + 12) = BYTE4(v27);
      string = of_property_read_string(v12, "qcom,msc-name", v4 + 4);
      if ( string )
      {
        v8 = string;
        v9 = "qcom,msc-name Node failed!\n";
        goto LABEL_18;
      }
      v15 = of_property_read_variable_u32_array(v12, "qcom,msc-id", v4, 1, 0);
      if ( (v15 & 0x80000000) != 0 )
      {
        v8 = v15;
        v9 = "qcom,msc-id Node failed!\n";
        goto LABEL_18;
      }
      *(_QWORD *)(a1 + 168) = v4;
      v28[0] = 0;
      if ( (unsigned int)mpam_msc_slc_get_params(v1, v28, &v27, 4, 4) )
      {
        v16 = 1;
        LODWORD(v27) = 0;
      }
      else if ( (_DWORD)v27 )
      {
        v16 = 2;
      }
      else
      {
        v16 = 1;
      }
      HIDWORD(v27) = v16;
      if ( (unsigned int)slc_mpam_start_stop(v1) )
      {
        v9 = "MAPM SCMI failure!\n";
        goto LABEL_14;
      }
      resource_byname = platform_get_resource_byname(a1, 512, "mon-base");
      v18 = devm_ioremap_resource(v1, resource_byname);
      v8 = v18;
      *(_QWORD *)(v4 + 64) = v18;
      if ( !v18 || v18 >= 0xFFFFFFFFFFFFF001LL )
      {
        v9 = "ioremap slc mpam_mon_base failed!\n";
        goto LABEL_7;
      }
      if ( *(_DWORD *)v4 != *(unsigned __int16 *)(v18 + 4) )
      {
        v9 = "IMEM Init failure!\n";
        goto LABEL_14;
      }
      v19 = attach_mpam_msc(v1, v4, 2);
      if ( v19 )
      {
        v8 = v19;
        v9 = "MPAM MSC attach failed!\n";
        goto LABEL_18;
      }
      v20 = devm_kmalloc(v1, 40, 3520);
      *(_QWORD *)(v4 + 16) = v20;
      if ( !v20 )
      {
        v21 = -12;
LABEL_40:
        detach_mpam_msc(v1, v4, 2);
        v9 = "MPAM SLC driver probe failed!\n";
        v10 = v1;
        v8 = v21;
        goto LABEL_19;
      }
      v26 = v20;
      *(_DWORD *)(v20 + 32) = v27;
      v22 = ((__int64 (__fastcall *)(__int64, __int64))slc_client_info_read)(v1, v12);
      if ( v22 )
      {
        v21 = v22;
        v25 = "Failed to detect SLC device\n";
      }
      else
      {
        v23 = *(_DWORD *)(v26 + 32);
        if ( !v23 )
        {
LABEL_45:
          dev_info(v1, "SLC MPAM Firmware version %d.%d.%d\n", HIWORD(v23), BYTE1(v23), (unsigned __int8)v23);
          result = 0;
          *(_QWORD *)(v26 + 20) = 0;
          *(_DWORD *)(v4 + 88) = 6;
          goto LABEL_20;
        }
        started = slc_mpam_start_stop(v1);
        if ( !started )
        {
          v23 = *(_DWORD *)(v26 + 32);
          goto LABEL_45;
        }
        v21 = started;
        v25 = "MON Memory init Failure!\n";
      }
      dev_err(v1, v25);
      goto LABEL_40;
    }
  }
  else
  {
    result = 4294967284LL;
  }
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
