__int64 __fastcall msm_common_snd_init(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  __int64 v5; // x20
  __int64 result; // x0
  _DWORD *v7; // x22
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x9
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x9
  __int64 v13; // x9
  __int64 v14; // x11
  __int64 v15; // x8
  __int64 v16; // x8
  __int64 v17; // x9
  int v18; // w8
  __int64 v19; // x0
  int v20; // w0
  __int64 v21; // x8
  bool v22; // zf
  __int64 v23; // x0
  int v24; // w0
  __int64 v25; // x8
  __int64 v26; // x0
  int v27; // w0
  __int64 v28; // x8
  __int64 v29; // x0
  int v30; // w0
  __int64 v31; // x8
  __int64 v32; // x0
  int v33; // w0
  __int64 v34; // x8
  __int64 v35; // x0
  int v36; // w0
  __int64 v37; // x8
  __int64 v38; // x0
  int v39; // w0
  __int64 v40; // x8
  __int64 v41; // x1
  __int64 v42; // x0
  int v43; // w2
  unsigned int v44; // w0
  __int64 v45; // x0
  char v46; // w15
  unsigned __int64 v47; // x9
  __int64 v48; // x10
  int v49; // w13
  bool v50; // cf
  unsigned __int64 v51; // x15
  unsigned __int64 v52; // x15
  int v53; // w16
  char *v54; // x22
  unsigned __int64 v55; // x8
  _DWORD *v56; // x22
  unsigned int v57; // t1
  unsigned __int64 v58; // x19
  __int64 cpu_device; // x0
  unsigned int v60; // w0
  unsigned int v61; // w19
  __int64 v62; // x0
  unsigned int v63; // w0
  unsigned __int64 StatusReg; // x19
  __int64 v65; // x20
  __int64 v66; // x0
  unsigned int v67; // w0
  __int64 v68; // [xsp+8h] [xbp-78h] BYREF
  __int64 v69; // [xsp+10h] [xbp-70h]
  __int64 v70; // [xsp+18h] [xbp-68h]
  int v71; // [xsp+20h] [xbp-60h]
  __int64 v72; // [xsp+28h] [xbp-58h] BYREF
  __int64 v73; // [xsp+30h] [xbp-50h]
  __int64 v74; // [xsp+38h] [xbp-48h]
  __int64 v75; // [xsp+40h] [xbp-40h]
  __int64 v76; // [xsp+48h] [xbp-38h]
  __int64 v77; // [xsp+50h] [xbp-30h]
  __int64 v78; // [xsp+58h] [xbp-28h]
  __int64 v79; // [xsp+60h] [xbp-20h]
  __int64 v80; // [xsp+68h] [xbp-18h]
  __int64 v81; // [xsp+70h] [xbp-10h]
  __int64 v82; // [xsp+78h] [xbp-8h]

  v82 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v71 = 0;
  v69 = 0;
  v70 = 0;
  v68 = 0;
  v4 = _kmalloc_cache_noprof(digital_cdc_rsc_mgr_hw_vote_disable, 3520, 712);
  v5 = v4;
  if ( v4 )
  {
    _mutex_init(v4 + 216, "&common_pdata->lock[count]", &msm_common_snd_init___key);
    *(_DWORD *)(v5 + 556) = 0;
    _mutex_init(v5 + 264, "&common_pdata->lock[count]", &msm_common_snd_init___key);
    *(_DWORD *)(v5 + 560) = 0;
    _mutex_init(v5 + 312, "&common_pdata->lock[count]", &msm_common_snd_init___key);
    *(_DWORD *)(v5 + 564) = 0;
    _mutex_init(v5 + 360, "&common_pdata->lock[count]", &msm_common_snd_init___key);
    *(_DWORD *)(v5 + 568) = 0;
    _mutex_init(v5 + 408, "&common_pdata->lock[count]", &msm_common_snd_init___key);
    *(_DWORD *)(v5 + 572) = 0;
    _mutex_init(v5 + 456, "&common_pdata->lock[count]", &msm_common_snd_init___key);
    *(_DWORD *)(v5 + 576) = 0;
    _mutex_init(v5 + 504, "&common_pdata->lock[count]", &msm_common_snd_init___key);
    *(_DWORD *)(v5 + 580) = 0;
    v7 = (_DWORD *)(v5 + 552);
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,tdm-max-slots", v5 + 552, 1, 0) & 0x80000000) != 0 )
      dev_info(a1 + 16, "%s: No DT match for tdm max slots\n", "msm_common_snd_init");
    if ( (unsigned int)(*v7 - 9) <= 0xFFFFFFF7 )
    {
      *v7 = 8;
      dev_info(a1 + 16, "%s: Using default tdm max slot: %d\n", "msm_common_snd_init", 8);
    }
    v8 = devm_clk_get(a1 + 16, "lpass_audio_hw_vote");
    if ( v8 <= 0xFFFFFFFFFFFFF000LL )
      v9 = v8;
    else
      v9 = 0;
    v10 = *(_QWORD *)(a1 + 760);
    *(_QWORD *)(v5 + 616) = v9;
    if ( (of_property_read_variable_u32_array(v10, "qcom,mi2s-tdm-is-hw-vote-needed", &v68, 7, 0) & 0x80000000) == 0 )
    {
      v11 = v68;
      v12 = v69;
      *(_QWORD *)(v5 + 640) = v70;
      *(_QWORD *)(v5 + 624) = v11;
      LODWORD(v11) = v71;
      *(_QWORD *)(v5 + 632) = v12;
      *(_DWORD *)(v5 + 648) = v11;
    }
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,tdm-clk-attribute", &v68, 7, 0) & 0x80000000) != 0 )
    {
      dev_info(a1 + 16, "%s: No DT match for tdm clk attribute, set to default\n", "msm_common_snd_init");
      *(_QWORD *)(v5 + 652) = 0x100000001LL;
      *(_QWORD *)(v5 + 668) = 0x100000001LL;
      *(_QWORD *)(v5 + 660) = 0x100000001LL;
      *(_DWORD *)(v5 + 676) = 1;
    }
    else
    {
      v13 = v68;
      v14 = v69;
      *(_DWORD *)(v5 + 676) = v71;
      v15 = v70;
      *(_QWORD *)(v5 + 652) = v13;
      *(_QWORD *)(v5 + 660) = v14;
      *(_QWORD *)(v5 + 668) = v15;
    }
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,mi2s-clk-attribute", &v68, 7, 0) & 0x80000000) != 0 )
    {
      dev_info(a1 + 16, "%s: No DT match for mi2s clk attribute, set to default\n", "msm_common_snd_init");
      *(_QWORD *)(v5 + 680) = 0x100000001LL;
      *(_QWORD *)(v5 + 688) = 0x100000001LL;
      *(_QWORD *)(v5 + 696) = 0x100000001LL;
      v18 = 1;
    }
    else
    {
      v16 = v68;
      v17 = v69;
      *(_QWORD *)(v5 + 696) = v70;
      *(_QWORD *)(v5 + 680) = v16;
      v18 = v71;
      *(_QWORD *)(v5 + 688) = v17;
    }
    v19 = *(_QWORD *)(a1 + 760);
    *(_DWORD *)(v5 + 704) = v18;
    v80 = 0;
    v81 = 0;
    v78 = 0;
    v79 = 0;
    v76 = 0;
    v77 = 0;
    v74 = 0;
    v75 = 0;
    v72 = 0;
    v73 = 0;
    v20 = _of_parse_phandle_with_args(v19, "qcom,pri-mi2s-gpios", 0, 0, 0, &v72);
    v21 = v72;
    v22 = v20 == 0;
    v23 = *(_QWORD *)(a1 + 760);
    if ( !v22 )
      v21 = 0;
    v80 = 0;
    v81 = 0;
    *(_QWORD *)(v5 + 160) = v21;
    v78 = 0;
    v79 = 0;
    v76 = 0;
    v77 = 0;
    v74 = 0;
    v75 = 0;
    v72 = 0;
    v73 = 0;
    v24 = _of_parse_phandle_with_args(v23, "qcom,sec-mi2s-gpios", 0, 0, 0, &v72);
    v25 = v72;
    v22 = v24 == 0;
    v26 = *(_QWORD *)(a1 + 760);
    if ( !v22 )
      v25 = 0;
    v80 = 0;
    v81 = 0;
    *(_QWORD *)(v5 + 168) = v25;
    v78 = 0;
    v79 = 0;
    v76 = 0;
    v77 = 0;
    v74 = 0;
    v75 = 0;
    v72 = 0;
    v73 = 0;
    v27 = _of_parse_phandle_with_args(v26, "qcom,tert-mi2s-gpios", 0, 0, 0, &v72);
    v28 = v72;
    v22 = v27 == 0;
    v29 = *(_QWORD *)(a1 + 760);
    if ( !v22 )
      v28 = 0;
    v80 = 0;
    v81 = 0;
    *(_QWORD *)(v5 + 176) = v28;
    v78 = 0;
    v79 = 0;
    v76 = 0;
    v77 = 0;
    v74 = 0;
    v75 = 0;
    v72 = 0;
    v73 = 0;
    v30 = _of_parse_phandle_with_args(v29, "qcom,quat-mi2s-gpios", 0, 0, 0, &v72);
    v31 = v72;
    v22 = v30 == 0;
    v32 = *(_QWORD *)(a1 + 760);
    if ( !v22 )
      v31 = 0;
    v80 = 0;
    v81 = 0;
    *(_QWORD *)(v5 + 184) = v31;
    v78 = 0;
    v79 = 0;
    v76 = 0;
    v77 = 0;
    v74 = 0;
    v75 = 0;
    v72 = 0;
    v73 = 0;
    v33 = _of_parse_phandle_with_args(v32, "qcom,quin-mi2s-gpios", 0, 0, 0, &v72);
    v34 = v72;
    v22 = v33 == 0;
    v35 = *(_QWORD *)(a1 + 760);
    if ( !v22 )
      v34 = 0;
    v80 = 0;
    v81 = 0;
    *(_QWORD *)(v5 + 192) = v34;
    v78 = 0;
    v79 = 0;
    v76 = 0;
    v77 = 0;
    v74 = 0;
    v75 = 0;
    v72 = 0;
    v73 = 0;
    v36 = _of_parse_phandle_with_args(v35, "qcom,sen-mi2s-gpios", 0, 0, 0, &v72);
    v37 = v72;
    v22 = v36 == 0;
    v38 = *(_QWORD *)(a1 + 760);
    if ( !v22 )
      v37 = 0;
    v80 = 0;
    v81 = 0;
    *(_QWORD *)(v5 + 200) = v37;
    v78 = 0;
    v79 = 0;
    v76 = 0;
    v77 = 0;
    v74 = 0;
    v75 = 0;
    v72 = 0;
    v73 = 0;
    v39 = _of_parse_phandle_with_args(v38, "qcom,sep-mi2s-gpios", 0, 0, 0, &v72);
    v40 = v72;
    v41 = *(int *)(a2 + 360);
    if ( v39 )
      v40 = 0;
    *(_QWORD *)(v5 + 208) = v40;
    v42 = devm_kmalloc(a1 + 16, v41, 3520);
    v43 = *(_DWORD *)(a2 + 360);
    *(_QWORD *)v5 = v42;
    dev_info(a1 + 16, "num_links %d \n", v43);
    *(_DWORD *)(v5 + 152) = *(_DWORD *)(a2 + 360);
    _mutex_init(v5 + 104, "&common_pdata->aud_dev_lock", &msm_common_snd_init___key_37);
    strcpy((char *)&v72, "aud_dev");
    LOWORD(v73) = 0;
    if ( (kobject_init_and_add(v5 + 8, &aud_dev_ktype, kernel_kobj, &v72) & 0x80000000) != 0 )
    {
      printk(&unk_131E2, "aud_dev_sysfs_init", &v72);
    }
    else if ( (sysfs_create_file_ns(v5 + 8, &device_state_attr, 0) & 0x80000000) != 0 )
    {
      printk(&unk_13A33, "aud_dev_sysfs_init", &v72);
      kobject_put(v5 + 8);
    }
    msm_common_set_pdata(a2, v5);
    v44 = _sw_hweight64(_cpu_possible_mask);
    v45 = _kmalloc_noprof(80LL * v44, 3520);
    while ( 2 )
    {
      msm_audio_req = v45;
      if ( v45 )
      {
        v46 = 0;
        v47 = 0;
        v48 = _cpu_possible_mask;
        v49 = -1;
        do
        {
          v51 = v48 & (-1LL << v46);
          if ( !v51 )
            break;
          v52 = __clz(__rbit64(v51));
          v53 = cpu_topology[12 * (unsigned int)v52 + 2];
          if ( v53 != v49 )
          {
            if ( v47 > 3 )
              goto LABEL_56;
            cluster_first_cpu[v47++] = v52;
            v49 = v53;
          }
          v50 = v52 >= 0x1F;
          v46 = v52 + 1;
        }
        while ( !v50 );
        if ( cluster_first_cpu[0] > 0x1Fu )
        {
LABEL_56:
          __break(0x5512u);
          StatusReg = _ReadStatusReg(SP_EL0);
          v65 = *(_QWORD *)(StatusReg + 80);
          v66 = _cpu_possible_mask;
          *(_QWORD *)(StatusReg + 80) = &msm_audio_add_qos_request__alloc_tag;
          v67 = _sw_hweight64(v66);
          v45 = _kmalloc_noprof(80LL * v67, 3520);
          *(_QWORD *)(StatusReg + 80) = v65;
          continue;
        }
        v54 = (char *)&cpu_topology[12 * cluster_first_cpu[0]];
        v57 = *((_DWORD *)v54 + 6);
        v56 = v54 + 24;
        v55 = v57;
        if ( !v57 )
          break;
        v58 = __clz(__rbit64(v55));
        cpu_device = get_cpu_device((unsigned int)v58);
        v60 = dev_pm_qos_add_request(cpu_device, msm_audio_req + 80LL * (unsigned int)v58, 1, 2000000000);
        if ( (v60 & 0x80000000) != 0 )
        {
          printk(&unk_125D7, "msm_audio_add_qos_request", v60);
          if ( v58 >= 0x1F )
            break;
        }
        else
        {
          cpu_vote_mask |= 1 << v58;
          if ( v58 >= 0x1F )
            break;
        }
        if ( ((unsigned int)(-2LL << v58) & *v56) != 0 )
        {
          v61 = __clz(__rbit64((unsigned int)(-2LL << v58) & *v56));
          v62 = get_cpu_device(v61);
          v63 = dev_pm_qos_add_request(v62, msm_audio_req + 80LL * v61, 1, 2000000000);
          if ( (v63 & 0x80000000) != 0 )
            printk(&unk_125D7, "msm_audio_add_qos_request", v63);
          else
            cpu_vote_mask |= 1 << v61;
        }
      }
      break;
    }
    _mutex_init(&vote_against_sleep_lock, "&vote_against_sleep_lock", &msm_common_snd_init___key_39);
    result = 0;
  }
  else
  {
    result = 4294967284LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
