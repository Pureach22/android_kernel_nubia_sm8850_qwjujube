__int64 __fastcall _dump_noc_regs_pakala(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x26
  int v6; // w20
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v8; // x21
  int v9; // w0
  __int64 v10; // x2
  __int64 v11; // x3
  unsigned int v12; // w21
  int v13; // w8
  __int64 v14; // x0
  __int64 v15; // x1
  __int64 v16; // x2
  __int64 v17; // x3
  __int64 v18; // x4
  __int64 v19; // x5
  __int64 v20; // x6
  __int64 v21; // x2
  __int64 v22; // x3
  __int64 v23; // x26
  unsigned __int64 v24; // x22
  int v25; // w0
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x8
  unsigned __int64 v29; // x8
  unsigned __int64 v30; // x8
  unsigned __int64 v31; // x8
  unsigned __int64 v32; // x8
  unsigned __int64 v33; // x8
  unsigned __int64 v34; // x8
  unsigned __int64 v35; // x8
  unsigned __int64 v36; // x8
  unsigned __int64 v37; // x8
  unsigned __int64 v38; // x8
  unsigned __int64 v39; // x8
  unsigned __int64 v40; // x8
  unsigned __int64 v41; // x8
  unsigned __int64 v42; // x8
  unsigned __int64 v43; // x8
  unsigned __int64 v44; // x8
  unsigned __int64 v45; // x8
  unsigned __int64 v46; // x8
  unsigned __int64 v47; // x8
  unsigned __int64 v48; // x8
  unsigned __int64 v49; // x8
  unsigned __int64 v50; // x8
  unsigned int v51; // w22
  unsigned __int64 v52; // x8
  unsigned __int64 v53; // x8

  if ( !msm_cvp_fw_low_power_mode )
    goto LABEL_13;
  v5 = *(_QWORD *)(a1 + 2208);
  if ( !*(_DWORD *)(v5 + 464) )
  {
    v8 = *(_QWORD *)(v5 + 264);
    if ( v8 < v8 + 24LL * *(unsigned int *)(v5 + 272) )
    {
      v6 = 0;
      do
      {
        if ( !strcmp(*(const char **)(v8 + 16), "cvp-core") )
        {
          v9 = _acquire_regulator((_QWORD *)v8, a1);
          v5 = *(_QWORD *)(a1 + 2208);
          v6 = v9;
        }
        v8 += 24LL;
      }
      while ( v8 < *(_QWORD *)(v5 + 264) + 24 * (unsigned __int64)*(unsigned int *)(v5 + 272) );
      goto LABEL_4;
    }
LABEL_13:
    v6 = 0;
    goto LABEL_14;
  }
  v6 = switch_core_gdsc_mode(a1, 0, a3, a4);
LABEL_4:
  if ( v6 && (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    printk(&unk_872CC, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
  }
LABEL_14:
  _read_register(a1, 0xF8068u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v27 = _ReadStatusReg(SP_EL0);
    printk(&unk_9378F, *(unsigned int *)(v27 + 1800), *(unsigned int *)(v27 + 1804), &unk_8E7CE);
  }
  v12 = _read_register(a1, 0xB0088u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v28 = _ReadStatusReg(SP_EL0);
    printk(&unk_92B86, *(unsigned int *)(v28 + 1800), *(unsigned int *)(v28 + 1804), &unk_8E7CE);
    if ( !v12 )
      goto LABEL_24;
  }
  else if ( !v12 )
  {
    goto LABEL_24;
  }
  if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
    printk(&unk_8FD4F, &unk_8DA84, v10, v11);
  _write_register(a1, 0xB0088u, 0);
LABEL_24:
  _read_register(a1, 0x13108u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v29 = _ReadStatusReg(SP_EL0);
    printk(&unk_8FDF9, *(unsigned int *)(v29 + 1800), *(unsigned int *)(v29 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0x13188u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v30 = _ReadStatusReg(SP_EL0);
    printk(&unk_8CDB3, *(unsigned int *)(v30 + 1800), *(unsigned int *)(v30 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0x13508u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v31 = _ReadStatusReg(SP_EL0);
    printk(&unk_8897B, *(unsigned int *)(v31 + 1800), *(unsigned int *)(v31 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0x13588u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v32 = _ReadStatusReg(SP_EL0);
    printk(&unk_868F5, *(unsigned int *)(v32 + 1800), *(unsigned int *)(v32 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0x17040u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v33 = _ReadStatusReg(SP_EL0);
    printk(&unk_8B960, *(unsigned int *)(v33 + 1800), *(unsigned int *)(v33 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0x17100u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v34 = _ReadStatusReg(SP_EL0);
    printk(&unk_92BC6, *(unsigned int *)(v34 + 1800), *(unsigned int *)(v34 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0x17104u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v35 = _ReadStatusReg(SP_EL0);
    printk(&unk_96B80, *(unsigned int *)(v35 + 1800), *(unsigned int *)(v35 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0x17108u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v36 = _ReadStatusReg(SP_EL0);
    printk(&unk_8360B, *(unsigned int *)(v36 + 1800), *(unsigned int *)(v36 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0x1710Cu);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v37 = _ReadStatusReg(SP_EL0);
    printk(&unk_92C0E, *(unsigned int *)(v37 + 1800), *(unsigned int *)(v37 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0x17110u);
  v13 = msm_cvp_debug_out;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v38 = _ReadStatusReg(SP_EL0);
    printk(&unk_8A4AD, *(unsigned int *)(v38 + 1800), *(unsigned int *)(v38 + 1804), &unk_8E7CE);
    v13 = msm_cvp_debug_out;
    if ( (msm_cvp_debug & 1) == 0 )
      goto LABEL_56;
  }
  else if ( (msm_cvp_debug & 1) == 0 )
  {
    goto LABEL_56;
  }
  if ( !v13 )
  {
    v39 = _ReadStatusReg(SP_EL0);
    printk(&unk_8E756, *(unsigned int *)(v39 + 1800), *(unsigned int *)(v39 + 1804), &unk_8E7CE);
  }
LABEL_56:
  _read_register(a1, 0x1A000u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v40 = _ReadStatusReg(SP_EL0);
    printk(&unk_87313, *(unsigned int *)(v40 + 1800), *(unsigned int *)(v40 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0x1A004u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v41 = _ReadStatusReg(SP_EL0);
    printk(&unk_87351, *(unsigned int *)(v41 + 1800), *(unsigned int *)(v41 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0x1A008u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v42 = _ReadStatusReg(SP_EL0);
    printk(&unk_9760C, *(unsigned int *)(v42 + 1800), *(unsigned int *)(v42 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0x1A010u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v43 = _ReadStatusReg(SP_EL0);
    printk(&unk_95624, *(unsigned int *)(v43 + 1800), *(unsigned int *)(v43 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0x1A018u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v44 = _ReadStatusReg(SP_EL0);
    printk(&unk_91EA2, *(unsigned int *)(v44 + 1800), *(unsigned int *)(v44 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0x1A020u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v45 = _ReadStatusReg(SP_EL0);
    printk(&unk_8FE30, *(unsigned int *)(v45 + 1800), *(unsigned int *)(v45 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0x1A024u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v46 = _ReadStatusReg(SP_EL0);
    printk(&unk_85528, *(unsigned int *)(v46 + 1800), *(unsigned int *)(v46 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0x1A028u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v47 = _ReadStatusReg(SP_EL0);
    printk(&unk_85568, *(unsigned int *)(v47 + 1800), *(unsigned int *)(v47 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0x1A02Cu);
  _print_reg_details_errlog1_high();
  _read_register(a1, 0x1A030u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v48 = _ReadStatusReg(SP_EL0);
    printk(&unk_8B9AA, *(unsigned int *)(v48 + 1800), *(unsigned int *)(v48 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0x1A034u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v49 = _ReadStatusReg(SP_EL0);
    printk(&unk_855A7, *(unsigned int *)(v49 + 1800), *(unsigned int *)(v49 + 1804), &unk_8E7CE);
  }
  v14 = _read_register(a1, 0x1A038u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v50 = _ReadStatusReg(SP_EL0);
    v51 = v14;
    printk(&unk_94ACA, *(unsigned int *)(v50 + 1800), *(unsigned int *)(v50 + 1804), &unk_8E7CE);
    v14 = v51;
  }
  _print_reg_details_errlog3_low_pakala(v14, v15, v16, v17, v18, v19, v20);
  _read_register(a1, 0x1A03Cu);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v52 = _ReadStatusReg(SP_EL0);
    printk(&unk_89AB0, *(unsigned int *)(v52 + 1800), *(unsigned int *)(v52 + 1804), &unk_8E7CE);
  }
  _write_register(a1, 0x1A018u, 1u);
  if ( msm_cvp_fw_low_power_mode )
  {
    v23 = *(_QWORD *)(a1 + 2208);
    if ( *(_DWORD *)(v23 + 464) )
    {
      v6 = switch_core_gdsc_mode(a1, 1, v21, v22);
    }
    else
    {
      v24 = *(_QWORD *)(v23 + 264);
      if ( v24 < v24 + 24LL * *(unsigned int *)(v23 + 272) )
      {
        do
        {
          if ( !strcmp(*(const char **)(v24 + 16), "cvp-core") )
          {
            v25 = _hand_off_regulator(v24);
            v23 = *(_QWORD *)(a1 + 2208);
            v6 = v25;
          }
          v24 += 24LL;
        }
        while ( v24 < *(_QWORD *)(v23 + 264) + 24 * (unsigned __int64)*(unsigned int *)(v23 + 272) );
      }
    }
    if ( v6 && (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v53 = _ReadStatusReg(SP_EL0);
      printk(&unk_95662, *(unsigned int *)(v53 + 1800), *(unsigned int *)(v53 + 1804), "warn");
    }
  }
  return _write_register(a1, 0xB0088u, v12);
}
