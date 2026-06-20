__int64 __fastcall wcd_mbhc_init(__int64 a1, __int64 a2, _QWORD *a3, __int64 a4, __int64 a5, char a6)
{
  __int64 v12; // x25
  __int64 v13; // x8
  unsigned int variable_u32_array; // w8
  __int64 v15; // x0
  char v16; // w24
  int v17; // w0
  int v18; // w8
  int v19; // w9
  int v20; // w9
  int v21; // w8
  int v22; // w10
  unsigned int v23; // w21
  __int64 result; // x0
  unsigned int v25; // w0
  unsigned int v26; // w0
  __int64 v27; // x1
  __int64 v28; // x8
  __int64 (__fastcall *v29)(__int64, __int64, __int64); // x8
  unsigned int v30; // w0
  int v31; // w2
  _QWORD *v32; // x8
  __int64 (__fastcall *v33)(__int64, __int64, __int64 (__fastcall *)(), const char *, __int64); // x8
  __int64 v34; // x1
  unsigned int v35; // w0
  __int64 (__fastcall *v36)(__int64, __int64, __int64 (__fastcall *)(), const char *, __int64); // x8
  __int64 v37; // x1
  unsigned int v38; // w0
  __int64 (__fastcall *v39)(__int64, __int64, __int64 (__fastcall *)(), const char *, __int64); // x8
  __int64 v40; // x1
  unsigned int v41; // w0
  __int64 (__fastcall *v42)(__int64, __int64, __int64, const char *, __int64); // x8
  __int64 v43; // x1
  __int64 v44; // x2
  unsigned int v45; // w0
  _DWORD *v46; // x8
  __int64 v47; // x1
  __int64 (__fastcall *v48)(__int64, __int64, __int64, const char *, __int64); // x8
  __int64 v49; // x1
  __int64 v50; // x2
  unsigned int v51; // w0
  _DWORD *v52; // x8
  __int64 v53; // x1
  __int64 (__fastcall *v54)(__int64, __int64, __int64 (__fastcall *)(), const char *, __int64); // x8
  __int64 v55; // x1
  unsigned int v56; // w0
  __int64 (__fastcall *v57)(__int64, __int64, __int64 (__fastcall *)(), const char *, __int64); // x8
  __int64 v58; // x1
  unsigned int v59; // w0
  unsigned __int64 v60; // x0
  void (__fastcall *v61)(__int64, __int64, __int64); // x8
  __int64 v62; // x1
  const char *v63; // x3
  unsigned int v64; // w19
  unsigned int v65; // w0
  unsigned int v66; // w19
  void (__fastcall *v67)(__int64, __int64, __int64); // x8
  __int64 v68; // x1
  void (__fastcall *v69)(__int64, __int64, __int64); // x8
  __int64 v70; // x1
  void (__fastcall *v71)(__int64, __int64, __int64); // x8
  __int64 v72; // x1
  void (__fastcall *v73)(__int64, __int64, __int64); // x8
  __int64 v74; // x1
  void (__fastcall *v75)(__int64, __int64, __int64); // x8
  __int64 v76; // x1
  void (__fastcall *v77)(__int64, __int64, __int64); // x8
  __int64 v78; // x1
  _DWORD *v79; // x8
  void *v80; // x8
  unsigned int v81; // w19
  unsigned int v82; // w19
  unsigned __int64 v89; // x10
  unsigned __int64 v92; // x10
  __int64 v93; // [xsp+0h] [xbp-20h] BYREF
  __int64 v94; // [xsp+8h] [xbp-18h] BYREF
  int v95; // [xsp+10h] [xbp-10h]
  __int64 v96; // [xsp+18h] [xbp-8h]

  v96 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD *)(a2 + 32);
  v93 = 0;
  v94 = 0;
  v13 = *(_QWORD *)(v12 + 72);
  v95 = 0;
  variable_u32_array = of_property_read_variable_u32_array(
                         *(_QWORD *)(v13 + 744),
                         "qcom,msm-mbhc-hphl-swh",
                         (char *)&v93 + 4,
                         1,
                         0);
  v15 = *(_QWORD *)(v12 + 72);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v63 = "qcom,msm-mbhc-hphl-swh";
LABEL_73:
    v64 = variable_u32_array;
    dev_err(v15, "%s: missing %s in dt node\n", "wcd_mbhc_init", v63);
    result = v64;
    goto LABEL_111;
  }
  variable_u32_array = of_property_read_variable_u32_array(*(_QWORD *)(v15 + 744), "qcom,msm-mbhc-gnd-swh", &v93, 1, 0);
  v15 = *(_QWORD *)(v12 + 72);
  if ( (variable_u32_array & 0x80000000) != 0 )
  {
    v63 = "qcom,msm-mbhc-gnd-swh";
    goto LABEL_73;
  }
  v16 = a6 & 1;
  of_property_read_variable_u32_array(*(_QWORD *)(v15 + 744), "qcom,msm-mbhc-hs-mic-max-threshold-mv", a1 + 168, 1, 0);
  of_property_read_variable_u32_array(
    *(_QWORD *)(*(_QWORD *)(v12 + 72) + 744LL),
    "qcom,msm-mbhc-hs-mic-min-threshold-mv",
    a1 + 172,
    1,
    0);
  v17 = of_property_read_variable_u32_array(
          *(_QWORD *)(*(_QWORD *)(v12 + 72) + 744LL),
          "qcom,msm-mbhc-moist-cfg",
          &v94,
          3,
          0);
  v18 = HIDWORD(v94);
  v19 = v95;
  *(_BYTE *)(a1 + 162) = 0;
  *(_WORD *)(a1 + 160) = 0;
  if ( v17 < 0 )
  {
    v18 = 3;
    v19 = 1;
  }
  *(_QWORD *)(a1 + 216) = a2;
  *(_DWORD *)(a1 + 188) = v18;
  *(_DWORD *)(a1 + 192) = v19;
  v20 = v93;
  v22 = HIDWORD(v93);
  v21 = v94;
  *(_QWORD *)(a1 + 792) = a4;
  *(_BYTE *)(a1 + 384) = v16;
  if ( v17 < 0 )
    v21 = 1;
  *(_BYTE *)(a1 + 207) = 0;
  *(_QWORD *)(a1 + 120) = a3;
  *(_BYTE *)(a1 + 163) = v22 != 0;
  *(_BYTE *)(a1 + 164) = v20 != 0;
  *(_DWORD *)(a1 + 180) = 4;
  *(_DWORD *)(a1 + 184) = v21;
  *(_WORD *)(a1 + 208) = 0;
  *(_BYTE *)(a1 + 210) = 0;
  *(_BYTE *)(a1 + 213) = 0;
  *(_DWORD *)(a1 + 388) = 0;
  *(_QWORD *)(a1 + 856) = a5;
  *(_QWORD *)(a1 + 196) = 0x6400000064LL;
  if ( !a4 )
  {
    printk(&unk_E27C, "wcd_mbhc_init");
    result = 4294967274LL;
    goto LABEL_111;
  }
  if ( !a5 )
  {
    dev_err(*(_QWORD *)(a2 + 24), "%s: mbhc registers are not defined\n", "wcd_mbhc_init");
    goto LABEL_20;
  }
  if ( !a3 || !a3[13] || !a3[14] || !a3[15] || !a3[17] || !a3[18] || !a3[20] || !a3[24] )
  {
    dev_err(*(_QWORD *)(a2 + 24), "%s: required mbhc callbacks are not defined\n", "wcd_mbhc_init");
LABEL_20:
    result = 4294967274LL;
    goto LABEL_111;
  }
  if ( *(_QWORD *)(a1 + 440) )
  {
    v23 = v17 & (v17 >> 31);
    goto LABEL_25;
  }
  v25 = snd_soc_card_jack_new(*(_QWORD *)(a2 + 32), "Headset Jack", 15, a1 + 392);
  if ( v25 )
  {
    v80 = &unk_DDCE;
LABEL_115:
    v82 = v25;
    printk(v80, "wcd_mbhc_init");
    result = v82;
    goto LABEL_111;
  }
  v26 = snd_soc_card_jack_new(*(_QWORD *)(a2 + 32), "Button Jack", 32256, a1 + 568);
  if ( v26 )
  {
    v81 = v26;
    printk(&unk_E306, v27);
    result = v81;
    goto LABEL_111;
  }
  v25 = snd_jack_set_key(*(_QWORD *)(a1 + 616), 0x4000);
  if ( v25 )
  {
    v80 = &unk_DC2B;
    goto LABEL_115;
  }
  *(_QWORD *)(a1 + 224) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 232) = a1 + 232;
  *(_QWORD *)(a1 + 240) = a1 + 232;
  *(_QWORD *)(a1 + 248) = wcd_mbhc_fw_read;
  init_timer_key(a1 + 256, &delayed_work_timer_fn, 0x200000, 0, 0);
  *(_QWORD *)a1 = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 8) = a1 + 8;
  *(_QWORD *)(a1 + 16) = a1 + 8;
  *(_QWORD *)(a1 + 24) = wcd_btn_lpress_fn;
  init_timer_key(a1 + 32, &delayed_work_timer_fn, 0x200000, 0, 0);
  v23 = 0;
LABEL_25:
  *(_DWORD *)(a1 + 864) = 0;
  _init_swait_queue_head(a1 + 872, "&x->wait", &init_completion___key);
  v28 = *(_QWORD *)(a1 + 120);
  *(_QWORD *)(a1 + 832) = wcd_event_notify;
  v29 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v28 + 96);
  if ( v29 )
  {
    if ( *((_DWORD *)v29 - 1) != -321073799 )
      __break(0x8228u);
    v30 = v29(a1, a1 + 832, 1);
    if ( v30 )
    {
      v66 = v30;
      printk(&unk_DFD4, "wcd_mbhc_init");
      result = v66;
      goto LABEL_111;
    }
    v23 = 0;
  }
  _init_waitqueue_head(a1 + 136, "&mbhc->wait_btn_press", &wcd_mbhc_init___key_28);
  _mutex_init(a1 + 744, "&mbhc->codec_resource_lock", &wcd_mbhc_init___key_30);
  v31 = *(_DWORD *)(a1 + 900);
  if ( v31 )
  {
    if ( v31 != 1 )
    {
      printk(&unk_DDEF, "wcd_mbhc_init");
      v32 = *(_QWORD **)(a1 + 920);
      if ( v32 )
        goto LABEL_34;
LABEL_86:
      printk(&unk_E0A1, "wcd_mbhc_init");
      goto LABEL_106;
    }
    wcd_mbhc_adc_init(a1);
  }
  v32 = *(_QWORD **)(a1 + 920);
  if ( !v32 )
    goto LABEL_86;
LABEL_34:
  if ( !*v32 || !v32[1] || !v32[2] || !v32[4] )
    goto LABEL_86;
  v33 = *(__int64 (__fastcall **)(__int64, __int64, __int64 (__fastcall *)(), const char *, __int64))(*(_QWORD *)(a1 + 120) + 104LL);
  v34 = **(unsigned int **)(a1 + 792);
  if ( *((_DWORD *)v33 - 1) != -917514073 )
    __break(0x8228u);
  v35 = v33(a2, v34, wcd_mbhc_mech_plug_detect_irq, "mbhc sw intr", a1);
  if ( !v35 )
  {
    v36 = *(__int64 (__fastcall **)(__int64, __int64, __int64 (__fastcall *)(), const char *, __int64))(*(_QWORD *)(a1 + 120) + 104LL);
    v37 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 4LL);
    if ( *((_DWORD *)v36 - 1) != -917514073 )
      __break(0x8228u);
    v38 = v36(a2, v37, wcd_mbhc_btn_press_handler, "Button Press detect", a1);
    if ( v38 )
    {
      v23 = v38;
      printk(&unk_E0FC, "wcd_mbhc_init");
LABEL_103:
      v77 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 120) + 120LL);
      v78 = **(unsigned int **)(a1 + 792);
      if ( *((_DWORD *)v77 - 1) != -1123681200 )
        __break(0x8228u);
      v77(a2, v78, a1);
      goto LABEL_106;
    }
    v39 = *(__int64 (__fastcall **)(__int64, __int64, __int64 (__fastcall *)(), const char *, __int64))(*(_QWORD *)(a1 + 120) + 104LL);
    v40 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 8LL);
    if ( *((_DWORD *)v39 - 1) != -917514073 )
      __break(0x8228u);
    v41 = v39(a2, v40, wcd_mbhc_release_handler, "Button Release detect", a1);
    if ( v41 )
    {
      v23 = v41;
      printk(&unk_E0FC, "wcd_mbhc_init");
LABEL_100:
      v75 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 120) + 120LL);
      v76 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 4LL);
      if ( *((_DWORD *)v75 - 1) != -1123681200 )
        __break(0x8228u);
      v75(a2, v76, a1);
      goto LABEL_103;
    }
    v42 = *(__int64 (__fastcall **)(__int64, __int64, __int64, const char *, __int64))(*(_QWORD *)(a1 + 120) + 104LL);
    v43 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 12LL);
    v44 = **(_QWORD **)(a1 + 920);
    if ( *((_DWORD *)v42 - 1) != -917514073 )
      __break(0x8228u);
    v45 = v42(a2, v43, v44, "Elect Insert", a1);
    if ( v45 )
    {
      v23 = v45;
      printk(&unk_E0FC, "wcd_mbhc_init");
LABEL_97:
      v73 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 120) + 120LL);
      v74 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 8LL);
      if ( *((_DWORD *)v73 - 1) != -1123681200 )
        __break(0x8228u);
      v73(a2, v74, a1);
      goto LABEL_100;
    }
    v46 = *(_DWORD **)(*(_QWORD *)(a1 + 120) + 112LL);
    v47 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 12LL);
    if ( *(v46 - 1) != 542830841 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD))v46)(a2, v47, 0);
    _X8 = (unsigned __int64 *)(a1 + 904);
    __asm { PRFM            #0x11, [X8] }
    do
      v89 = __ldxr(_X8);
    while ( __stxr(v89 & 0xFFFFFFFFFFFFFFFELL, _X8) );
    v48 = *(__int64 (__fastcall **)(__int64, __int64, __int64, const char *, __int64))(*(_QWORD *)(a1 + 120) + 104LL);
    v49 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 16LL);
    v50 = *(_QWORD *)(*(_QWORD *)(a1 + 920) + 8LL);
    if ( *((_DWORD *)v48 - 1) != -917514073 )
      __break(0x8228u);
    v51 = v48(a2, v49, v50, "Elect Remove", a1);
    if ( v51 )
    {
      v23 = v51;
      printk(&unk_E0FC, "wcd_mbhc_init");
LABEL_94:
      v71 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 120) + 120LL);
      v72 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 12LL);
      if ( *((_DWORD *)v71 - 1) != -1123681200 )
        __break(0x8228u);
      v71(a2, v72, a1);
      goto LABEL_97;
    }
    v52 = *(_DWORD **)(*(_QWORD *)(a1 + 120) + 112LL);
    v53 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 16LL);
    if ( *(v52 - 1) != 542830841 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD))v52)(a2, v53, 0);
    _X8 = (unsigned __int64 *)(a1 + 904);
    __asm { PRFM            #0x11, [X8] }
    do
      v92 = __ldxr(_X8);
    while ( __stxr(v92 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
    v54 = *(__int64 (__fastcall **)(__int64, __int64, __int64 (__fastcall *)(), const char *, __int64))(*(_QWORD *)(a1 + 120) + 104LL);
    v55 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 20LL);
    if ( *((_DWORD *)v54 - 1) != -917514073 )
      __break(0x8228u);
    v56 = v54(a2, v55, wcd_mbhc_hphl_ocp_irq, "HPH_L OCP detect", a1);
    if ( v56 )
    {
      v23 = v56;
      printk(&unk_E0FC, "wcd_mbhc_init");
LABEL_91:
      v69 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 120) + 120LL);
      v70 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 16LL);
      if ( *((_DWORD *)v69 - 1) != -1123681200 )
        __break(0x8228u);
      v69(a2, v70, a1);
      goto LABEL_94;
    }
    v57 = *(__int64 (__fastcall **)(__int64, __int64, __int64 (__fastcall *)(), const char *, __int64))(*(_QWORD *)(a1 + 120) + 104LL);
    v58 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 24LL);
    if ( *((_DWORD *)v57 - 1) != -917514073 )
      __break(0x8228u);
    v59 = v57(a2, v58, wcd_mbhc_hphr_ocp_irq, "HPH_R OCP detect", a1);
    if ( v59 )
    {
      v23 = v59;
      printk(&unk_E0FC, "wcd_mbhc_init");
LABEL_88:
      v67 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 120) + 120LL);
      v68 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 20LL);
      if ( *((_DWORD *)v67 - 1) != -1123681200 )
        __break(0x8228u);
      v67(a2, v68, a1);
      goto LABEL_91;
    }
    if ( !*(_QWORD *)(a1 + 968) )
    {
      v60 = devm_extcon_dev_allocate(*(_QWORD *)(a2 + 24), &mbhc_ext_dev_supported_table);
      *(_QWORD *)(a1 + 968) = v60;
      if ( v60 > 0xFFFFFFFFFFFFF000LL )
      {
        v23 = 0;
LABEL_68:
        v61 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a1 + 120) + 120LL);
        v62 = *(unsigned int *)(*(_QWORD *)(a1 + 792) + 24LL);
        if ( *((_DWORD *)v61 - 1) != -1123681200 )
          __break(0x8228u);
        v61(a2, v62, a1);
        goto LABEL_88;
      }
      v65 = devm_extcon_dev_register(*(_QWORD *)(a2 + 24), v60);
      if ( v65 )
      {
        v23 = v65;
        printk(&unk_E3AC, "wcd_mbhc_init");
        goto LABEL_68;
      }
    }
    result = 0;
    *(_BYTE *)(a1 + 896) = 0;
    goto LABEL_111;
  }
  v23 = v35;
  printk(&unk_E21E, "wcd_mbhc_init");
LABEL_106:
  v79 = *(_DWORD **)(*(_QWORD *)(a1 + 120) + 96LL);
  if ( v79 )
  {
    if ( *(v79 - 1) != -321073799 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD))v79)(a1, a1 + 832, 0);
  }
  result = v23;
LABEL_111:
  _ReadStatusReg(SP_EL0);
  return result;
}
