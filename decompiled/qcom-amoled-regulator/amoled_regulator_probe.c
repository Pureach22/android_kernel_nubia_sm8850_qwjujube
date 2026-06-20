__int64 __fastcall amoled_regulator_probe(_QWORD *a1)
{
  _QWORD *v1; // x21
  __int64 v3; // x0
  _QWORD *v4; // x19
  __int64 v5; // x0
  __int64 regmap; // x0
  __int64 v7; // x8
  __int64 v8; // x20
  __int64 next_available_child; // x0
  __int64 v10; // x21
  _DWORD *v11; // x26
  char v12; // w8
  unsigned int *address; // x0
  unsigned int v14; // w25
  unsigned int v15; // w0
  char v16; // w8
  char v17; // w9
  __int64 property; // x0
  int v19; // w8
  unsigned __int64 v20; // x0
  int v21; // w0
  int v22; // w0
  int v23; // w9
  int v24; // w8
  int v25; // w10
  int v26; // w8
  int v27; // w9
  int v28; // w25
  unsigned int v29; // w0
  unsigned int v30; // w0
  unsigned int v31; // w0
  unsigned int updated; // w0
  unsigned int v33; // w24
  int v34; // w8
  unsigned int v35; // w0
  __int64 v36; // x0
  unsigned int v37; // w0
  unsigned int v38; // w20
  unsigned int v39; // w8
  unsigned int v40; // w8
  unsigned int v41; // w8
  unsigned int v42; // w0
  unsigned int v43; // w0
  __int64 v44; // x21
  unsigned int *v45; // x23
  unsigned int v46; // w22
  unsigned int v47; // w26
  unsigned int v48; // w8
  __int64 v49; // x0
  unsigned __int16 v50; // w20
  unsigned int v51; // w0
  __int64 v52; // x0
  unsigned int v53; // w8
  unsigned __int16 v54; // w26
  unsigned int v55; // w0
  unsigned int v56; // w0
  __int16 v58; // [xsp+Ch] [xbp-24h] BYREF
  char v59; // [xsp+Eh] [xbp-22h]
  __int64 v60; // [xsp+10h] [xbp-20h] BYREF
  __int64 v61; // [xsp+18h] [xbp-18h]
  __int64 v62; // [xsp+20h] [xbp-10h]
  __int64 v63; // [xsp+28h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1[95] )
  {
    printk(&unk_78F4, "amoled_regulator_probe");
    v33 = -19;
    goto LABEL_86;
  }
  v1 = a1 + 2;
  v3 = devm_kmalloc(a1 + 2, 1136, 3520);
  if ( !v3 )
  {
    v33 = -12;
    goto LABEL_86;
  }
  v4 = (_QWORD *)v3;
  v5 = a1[14];
  *v4 = v1;
  regmap = dev_get_regmap(v5, 0);
  v4[1] = regmap;
  if ( !regmap )
  {
    dev_err(v1, "Failed to get the regmap handle\n");
    v33 = -22;
    goto LABEL_86;
  }
  v7 = *v4;
  a1[21] = v4;
  v59 = 0;
  v8 = *(_QWORD *)(v7 + 744);
  v58 = 0;
  next_available_child = of_get_next_available_child(v8, 0);
  if ( !next_available_child )
  {
LABEL_29:
    v29 = amoled_regulator_register(v4, 0);
    if ( (v29 & 0x80000000) == 0 )
    {
      v30 = amoled_regulator_register(v4, 1);
      if ( (v30 & 0x80000000) != 0 )
      {
        v33 = v30;
        dev_err(*v4, "Failed to register AB regulator rc=%d\n", v30);
        goto LABEL_43;
      }
      v31 = amoled_regulator_register(v4, 2);
      if ( (v31 & 0x80000000) != 0 )
      {
        v33 = v31;
        dev_err(*v4, "Failed to register IBB regulator rc=%d\n", v31);
        goto LABEL_43;
      }
      if ( *((_BYTE *)v4 + 1064) == 4 && *((_BYTE *)v4 + 1068) == 1 )
      {
        updated = regmap_update_bits_base(v4[1], (unsigned __int16)(*((_DWORD *)v4 + 282) + 112), 7, 1, 0, 0, 0);
        v33 = 0;
        if ( (updated & 0x80000000) != 0 )
        {
          v33 = updated;
          printk(&unk_7BA4, "amoled_masked_write");
LABEL_43:
          dev_err(*v4, "Failed to initialize HW rc=%d\n", v33);
        }
      }
      else
      {
        v33 = 0;
      }
      if ( *((_BYTE *)v4 + 1064) != 4 || *((unsigned __int8 *)v4 + 1065) < 2u )
        goto LABEL_86;
      v34 = *((_DWORD *)v4 + 268);
      if ( v34 != 1 )
      {
        if ( v34 != 2 )
        {
          v42 = regmap_update_bits_base(v4[1], (unsigned __int16)(*((_DWORD *)v4 + 282) + 182), 128, 0, 0, 0, 0);
          v33 = 0;
          if ( (v42 & 0x80000000) == 0 )
            goto LABEL_86;
          v33 = v42;
          printk(&unk_7BA4, "amoled_masked_write");
          dev_err(*v4, "failed to disable spur FSM!\n");
          goto LABEL_85;
        }
        v35 = regmap_update_bits_base(v4[1], (unsigned __int16)(*((_DWORD *)v4 + 282) + 182), 64, 64, 0, 0, 0);
        if ( (v35 & 0x80000000) != 0 )
        {
          v33 = v35;
          printk(&unk_7BA4, "amoled_masked_write");
          dev_err(*v4, "failed to enable spur SQM mode!\n");
          goto LABEL_85;
        }
        if ( (unsigned int)(*((_DWORD *)v4 + 269) - 101) <= 0x26AA )
        {
          v36 = v4[139];
          LOWORD(v60) = *((_DWORD *)v4 + 269);
          v37 = nvmem_cell_write(v36, &v60, 2);
          if ( (v37 & 0x80000000) != 0 )
          {
            v33 = v37;
            if ( v37 != -517 )
              dev_err(*v4, "failed to enable spur SQM timer\n");
            goto LABEL_85;
          }
        }
      }
      v38 = *((unsigned __int8 *)v4 + 1104);
      LOWORD(v60) = 0;
      if ( (v38 & 1) == 0 )
      {
        v39 = *((_DWORD *)v4 + 270);
        v38 = true;
        if ( v39 - 249 > 0xF6 || v39 < *((_DWORD *)v4 + 273) )
        {
          v40 = *((_DWORD *)v4 + 271);
          if ( v40 - 249 > 0xF6 || v40 < *((_DWORD *)v4 + 274) )
          {
            v41 = *((_DWORD *)v4 + 272);
            if ( v41 - 249 > 0xF6 || v41 < *((_DWORD *)v4 + 275) )
              v38 = false;
          }
        }
        *((_BYTE *)v4 + 1104) = v38;
      }
      v43 = regmap_update_bits_base(v4[1], (unsigned __int16)(*((_DWORD *)v4 + 282) + 183), 1, v38, 0, 0, 0);
      if ( (v43 & 0x80000000) == 0 )
      {
        v44 = 0;
        v45 = (unsigned int *)v4 + 273;
        if ( *((_BYTE *)v4 + 1104) )
          v46 = 496;
        else
          v46 = 248;
        do
        {
          v47 = *(unsigned __int16 *)v45;
          v48 = *((unsigned __int16 *)v45 - 6);
          if ( v48 < v47 || v48 > v46 )
          {
            dev_err(*v4, "ibb spur freq band%d threshold invalid!\n", v44 + 1);
            v47 = v46;
            v48 = v46;
            *(v45 - 3) = v46;
            *v45 = v46;
          }
          v49 = v4[1];
          v50 = *((_DWORD *)v4 + 282) + ((2 * v44) | 0xB8);
          LOWORD(v60) = ((_BYTE)v4[138] & v48) + (v48 >> *((_BYTE *)v4 + 1104));
          v51 = regmap_bulk_write(v49, v50, &v60, 1);
          if ( (v51 & 0x80000000) != 0 )
          {
            v33 = v51;
            printk(&unk_7CEB, "amoled_write");
            dev_err(*v4, "failed to write IBB_SPUR_FREQ_HIGH register!\n");
            goto LABEL_84;
          }
          v52 = v4[1];
          v53 = v47 >> *((_BYTE *)v4 + 1104);
          v54 = *((_DWORD *)v4 + 282) + ((2 * v44) | 0xB9);
          LOWORD(v60) = v53;
          v55 = regmap_bulk_write(v52, v54, &v60, 1);
          if ( (v55 & 0x80000000) != 0 )
          {
            v33 = v55;
            printk(&unk_7CEB, "amoled_write");
            dev_err(*v4, "failed to write IBB_SPUR_FREQ_LOW register!\n");
            goto LABEL_84;
          }
          ++v44;
          ++v45;
        }
        while ( v44 != 3 );
        v56 = regmap_update_bits_base(v4[1], (unsigned __int16)(*((_DWORD *)v4 + 282) + 182), 128, 128, 0, 0, 0);
        v33 = 0;
        if ( (v56 & 0x80000000) != 0 )
        {
          v33 = v56;
          printk(&unk_7BA4, "amoled_masked_write");
          dev_err(*v4, "failed to enable spur FSM!\n");
          goto LABEL_85;
        }
        goto LABEL_86;
      }
      v33 = v43;
      printk(&unk_7BA4, "amoled_masked_write");
      dev_err(*v4, "failed to write IBB_SPUR_CTL register!\n");
LABEL_84:
      dev_err(*v4, "failed to set spur thresholds!\n");
LABEL_85:
      dev_err(*v4, "Failed to init ibb spur settings rc=%d\n", v33);
      goto LABEL_86;
    }
    v33 = v29;
    dev_err(*v4, "Failed to register OLEDB regulator rc=%d\n", v29);
    goto LABEL_43;
  }
  v10 = next_available_child;
  v11 = v4 + 134;
  while ( 1 )
  {
    address = (unsigned int *)_of_get_address(v10, 0, 0xFFFFFFFFLL, 0, 0);
    if ( !address )
    {
      printk(&unk_7956, "amoled_parse_dt");
      goto LABEL_79;
    }
    v14 = bswap32(*address);
    v15 = regmap_bulk_read(v4[1], (unsigned __int16)(v14 + 3), &v58, 3);
    if ( (v15 & 0x80000000) != 0 )
    {
      v33 = v15;
      printk(&unk_7C4B, "amoled_read");
      printk(&unk_797E, "amoled_parse_dt");
      goto LABEL_80;
    }
    if ( HIBYTE(v58) != 32 )
      break;
    v16 = v59;
    v17 = v58;
    *((_DWORD *)v4 + 282) = v14;
    *((_BYTE *)v4 + 1064) = v16;
    *((_BYTE *)v4 + 1065) = v17;
    v4[131] = v10;
    *((_BYTE *)v4 + 1066) = of_find_property(v10, "qcom,swire-control", 0) != 0;
    *((_BYTE *)v4 + 1067) = of_find_property(v10, "qcom,aod-pd-control", 0) != 0;
    property = of_find_property(v10, "qcom,ibb-single-phase", 0);
    v19 = *((unsigned __int8 *)v4 + 1064);
    *((_BYTE *)v4 + 1068) = property != 0;
    if ( v19 != 4 || *((unsigned __int8 *)v4 + 1065) < 2u )
      goto LABEL_7;
    v61 = 0;
    v62 = 0;
    v60 = 0;
    if ( (of_property_read_variable_u32_array(v10, "qcom,ibb-spur-mitigation-level", v4 + 134, 1, 0) & 0x80000000) != 0 )
      goto LABEL_26;
    if ( *v11 )
    {
      if ( *v11 == 2 )
      {
        of_property_read_variable_u32_array(v10, "qcom,ibb-spur-sqm-timer-ms", (char *)v4 + 1076, 1, 0);
        v20 = devm_nvmem_cell_get(*v4, "ibb_spur_sqm_timer");
        v4[139] = v20;
        if ( v20 >= 0xFFFFFFFFFFFFF001LL )
        {
          if ( (_DWORD)v20 != -517 )
          {
            v28 = v20;
            dev_err(*v4, "Failed to get nvmem-cells, rc=%d\n", v20);
            if ( (v28 & 0x80000000) == 0 )
              goto LABEL_7;
          }
          goto LABEL_26;
        }
      }
      *((_BYTE *)v4 + 1104) = of_find_property(v10, "qcom,ibb-spur-2khz-step-size", 0) != 0;
      v21 = of_property_count_elems_of_size(v10, "qcom,ibb-spur-freq-thresholds", 4);
      if ( v21 != 6 )
      {
        dev_err(*v4, "invalid ibb spur freq threshold array size = %d\n", v21);
        *((_DWORD *)v4 + 268) = 0;
LABEL_26:
        printk(&unk_7B73, "amoled_parse_dt");
        goto LABEL_7;
      }
      v22 = of_property_read_variable_u32_array(v10, "qcom,ibb-spur-freq-thresholds", &v60, 6, 0);
      if ( v22 < 0 )
      {
        dev_err(*v4, "failed to read thresholds = %d\n", v22);
        goto LABEL_26;
      }
      v23 = HIDWORD(v60);
      *((_DWORD *)v4 + 273) = v60;
      v24 = v61;
      v25 = HIDWORD(v61);
      *((_DWORD *)v4 + 270) = v23;
      *((_DWORD *)v4 + 274) = v24;
      v26 = v62;
      v27 = HIDWORD(v62);
      *((_DWORD *)v4 + 271) = v25;
      *((_DWORD *)v4 + 275) = v26;
      *((_DWORD *)v4 + 272) = v27;
    }
LABEL_7:
    v10 = of_get_next_available_child(v8, v10);
    if ( !v10 )
      goto LABEL_29;
  }
  if ( HIBYTE(v58) == 36 )
  {
    v12 = v59;
    *((_DWORD *)v4 + 281) = v14;
    *((_BYTE *)v4 + 712) = v12;
    v4[87] = v10;
    *((_BYTE *)v4 + 713) = of_find_property(v10, "qcom,swire-control", 0) != 0;
    *((_BYTE *)v4 + 714) = of_find_property(v10, "qcom,aod-pd-control", 0) != 0;
    goto LABEL_7;
  }
  if ( HIBYTE(v58) == 44 )
  {
    *((_DWORD *)v4 + 280) = v14;
    v4[43] = v10;
    *((_BYTE *)v4 + 360) = of_find_property(v10, "qcom,swire-control", 0) != 0;
    goto LABEL_7;
  }
  printk(&unk_7A2E, "amoled_parse_dt");
LABEL_79:
  v33 = -22;
LABEL_80:
  dev_err(*v4, "Failed to parse DT params rc=%d\n", v33);
LABEL_86:
  _ReadStatusReg(SP_EL0);
  return v33;
}
