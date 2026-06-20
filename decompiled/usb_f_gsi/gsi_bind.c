__int64 __fastcall gsi_bind(__int64 a1, __int64 a2)
{
  int v2; // w8
  _QWORD *v3; // x20
  __int64 result; // x0
  int v7; // w3
  _BYTE *v8; // x23
  _BYTE *v9; // x22
  _BYTE *v10; // x21
  unsigned int v11; // w26
  __int64 v12; // x28
  char *v13; // x24
  unsigned __int64 v14; // x25
  char v15; // w27
  unsigned __int8 v16; // w8
  _UNKNOWN **v17; // x12
  _UNKNOWN **v18; // x14
  _UNKNOWN **v19; // x15
  _BYTE *v20; // x11
  _BYTE *v21; // x13
  _BYTE *v22; // x1
  _BYTE *v23; // x16
  _BYTE *v24; // x17
  _BYTE *v25; // x3
  _BYTE *v26; // x0
  int v27; // w5
  __int64 v28; // x9
  __int64 v29; // x10
  __int64 v30; // x27
  __int64 v31; // x4
  __int64 v32; // x8
  int v33; // w2
  unsigned int v34; // w23
  unsigned __int64 v35; // x0
  __int16 v36; // w9
  __int64 v37; // x0
  int v38; // w11
  char v39; // w8
  char v40; // w9
  char v41; // w10
  unsigned int v42; // w0
  __int64 v43; // x0
  _QWORD *v44; // x27
  __int64 v45; // x0
  _QWORD *v46; // x27
  _BYTE *v47; // x1
  _QWORD *v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x1
  __int64 v52; // x8
  int v53; // w9
  __int64 v54; // x8
  char v55; // w8
  char v56; // w8
  char v57; // w8
  _QWORD *v58; // x1
  _QWORD *v59; // x8
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 (__fastcall *v62)(__int64, __int64); // x8
  __int64 v63; // x0
  unsigned __int64 StatusReg; // x20
  __int64 v65; // x21
  __int64 v66; // [xsp+10h] [xbp-D0h]
  char v67; // [xsp+1Ch] [xbp-C4h]
  unsigned __int64 v68; // [xsp+20h] [xbp-C0h]
  __int64 v69; // [xsp+28h] [xbp-B8h]
  unsigned int v70; // [xsp+34h] [xbp-ACh]
  _UNKNOWN **v71; // [xsp+38h] [xbp-A8h]
  _UNKNOWN **v72; // [xsp+40h] [xbp-A0h]
  _UNKNOWN **v73; // [xsp+48h] [xbp-98h]
  __int64 v74; // [xsp+50h] [xbp-90h]
  __int64 v75; // [xsp+58h] [xbp-88h]
  _BYTE *v76; // [xsp+60h] [xbp-80h]
  _BYTE *v77; // [xsp+68h] [xbp-78h]
  _BYTE *v78; // [xsp+70h] [xbp-70h]
  _BYTE *v79; // [xsp+78h] [xbp-68h]
  _BYTE *v80; // [xsp+80h] [xbp-60h]
  _BYTE *v81; // [xsp+88h] [xbp-58h]
  __int64 v82; // [xsp+90h] [xbp-50h]
  _BYTE *v83; // [xsp+98h] [xbp-48h]
  unsigned __int64 v84; // [xsp+A0h] [xbp-40h]
  _BYTE *v85; // [xsp+A8h] [xbp-38h]
  _BYTE *v86; // [xsp+B0h] [xbp-30h]
  _BYTE *v87; // [xsp+B8h] [xbp-28h]
  unsigned __int64 v88; // [xsp+C0h] [xbp-20h]
  _BYTE *v89; // [xsp+C8h] [xbp-18h]
  _BYTE *v90; // [xsp+D0h] [xbp-10h]

  v2 = *(_DWORD *)(a2 + 224);
  v3 = *(_QWORD **)(a1 + 48);
  if ( v2 == 4 || v2 == 2 )
  {
    *(_DWORD *)(a2 + 228) = -19;
  }
  else
  {
    result = usb_interface_id(a1, a2);
    *(_DWORD *)(a2 + 228) = result;
    if ( (result & 0x80000000) != 0 )
      return result;
  }
  result = usb_interface_id(a1, a2);
  *(_DWORD *)(a2 + 232) = result;
  if ( (result & 0x80000000) == 0 )
  {
    v7 = *(_DWORD *)(a2 + 224);
    if ( v7 > 1 )
    {
      if ( v7 == 2 )
      {
        v67 = 0;
        v90 = &rmnet_gsi_interface_desc;
        v84 = 0;
        v85 = nullptr;
        v86 = &rmnet_gsi_fs_in_desc;
        v87 = &rmnet_gsi_fs_out_desc;
        v82 = 0;
        v83 = &rmnet_gsi_fs_notify_desc;
        v76 = &rmnet_gsi_hs_in_desc;
        v78 = &rmnet_gsi_hs_out_desc;
        v79 = &rmnet_gsi_hs_notify_desc;
        v77 = &rmnet_gsi_ss_in_desc;
        v8 = nullptr;
        v80 = &rmnet_gsi_ss_out_desc;
        v81 = &rmnet_gsi_ss_notify_desc;
        v71 = &rmnet_gsi_fs_function;
        v72 = &rmnet_gsi_hs_function;
        v9 = nullptr;
        *(_QWORD *)(a2 + 552) = 0x600000004000LL;
        v68 = 0;
        v10 = nullptr;
        v70 = 8;
        v11 = 0;
        v75 = 50;
        v12 = 0;
        v69 = 31744;
        v15 = 1;
        v66 = 14;
        v13 = &rmnet_gsi_string_defs;
        v88 = 0;
        v89 = nullptr;
        v14 = 32;
        v73 = &rmnet_gsi_ss_function;
        v74 = 31744;
        goto LABEL_54;
      }
      if ( v7 != 3 )
      {
        if ( v7 == 4 )
        {
          v66 = 0;
          v90 = &qdss_gsi_data_intf_desc;
          v86 = &qdss_gsi_fs_data_desc;
          v69 = 0;
          v76 = &qdss_gsi_hs_data_desc;
          v77 = &qdss_gsi_ss_data_desc;
          v80 = nullptr;
          v81 = nullptr;
          v8 = nullptr;
          v67 = 1;
          v71 = &qdss_gsi_fs_data_only_desc;
          v72 = &qdss_gsi_hs_data_only_desc;
          v79 = nullptr;
          v9 = nullptr;
          v70 = 8;
          v10 = nullptr;
          v73 = &qdss_gsi_ss_data_only_desc;
          v74 = 0x4000;
          v11 = 0;
          v78 = nullptr;
          v12 = 0;
          v13 = &qdss_gsi_string_defs;
          v83 = nullptr;
          v84 = 0;
          v14 = 32;
          v87 = nullptr;
          v15 = 1;
          v85 = nullptr;
          v68 = 0;
          v88 = 0;
          v89 = nullptr;
          v82 = 0;
          v75 = 15;
          goto LABEL_54;
        }
LABEL_32:
        if ( a2 )
        {
          ipc_log_string(*(_QWORD *)(a2 + 1344), "%s: Invalid prot id %d", "gsi_bind", v7);
          printk(&unk_1181B, "gsi_bind");
        }
        return 4294967274LL;
      }
      v87 = &mbim_gsi_fs_out_desc;
      *(_QWORD *)(a2 + 552) = 0x600000004000LL;
      v85 = &mbim_gsi_data_nop_intf;
      v86 = &mbim_gsi_fs_in_desc;
      v31 = 0;
      word_961 = 2048;
      v13 = &mbim_gsi_string_defs;
      v88 = 8;
      v17 = &mbim_gsi_ss_function;
      v18 = &mbim_gsi_hs_function;
      v19 = &mbim_gsi_fs_function;
      v20 = &mbim_gsi_ss_notify_desc;
      v21 = &mbim_gsi_ss_out_desc;
      v22 = &mbim_gsi_ss_in_desc;
      v23 = &mbim_gsi_hs_notify_desc;
      v24 = &mbim_gsi_hs_out_desc;
      v25 = &mbim_gsi_hs_in_desc;
      v26 = &mbim_gsi_fs_notify_desc;
      v8 = &mbim_gsi_union_desc;
      v9 = &mbim_gsi_iad_desc;
      v90 = &mbim_gsi_data_intf;
      v27 = 8;
      v10 = &mbim_gsi_control_intf;
      v11 = -1;
      v14 = 48;
      v28 = 15;
      v29 = 0x4000;
      v12 = 1;
      v84 = 9;
      if ( a2 )
      {
        v33 = *(unsigned __int8 *)(a1 + 40);
        v30 = 0;
        v89 = nullptr;
        v32 = 0x4000;
        if ( (unsigned int)(v33 - 5) >= 0xFFFFFFFD )
        {
          ipc_log_string(*(_QWORD *)(a2 + 1344), "MBIM in configuration %d", v33);
          v31 = 0;
          v30 = 0;
          v86 = &mbim_gsi_fs_in_desc;
          v87 = &mbim_gsi_fs_out_desc;
          v85 = &mbim_gsi_data_nop_intf;
          v90 = &mbim_gsi_data_intf;
          v17 = &mbim_gsi_ss_function;
          v88 = 8;
          v89 = nullptr;
          v18 = &mbim_gsi_hs_function;
          v19 = &mbim_gsi_fs_function;
          v20 = &mbim_gsi_ss_notify_desc;
          v21 = &mbim_gsi_ss_out_desc;
          v22 = &mbim_gsi_ss_in_desc;
          v23 = &mbim_gsi_hs_notify_desc;
          v24 = &mbim_gsi_hs_out_desc;
          v25 = &mbim_gsi_hs_in_desc;
          v26 = &mbim_gsi_fs_notify_desc;
          v14 = 48;
          v28 = 15;
          v29 = 0x4000;
          v84 = 9;
          v12 = 1;
          v32 = 0x4000;
LABEL_51:
          v27 = 8;
        }
      }
      else
      {
        v30 = 0;
        v89 = nullptr;
        v32 = 0x4000;
      }
LABEL_52:
      v83 = v26;
      v69 = v32;
      v70 = v27;
      v82 = v31;
      v74 = v29;
      v75 = v28;
      v76 = v25;
      v77 = v22;
      v78 = v24;
      v79 = v23;
      v71 = v19;
      v72 = v18;
      v80 = v21;
      v73 = v17;
      v81 = v20;
      v42 = usb_string_id(v3);
      if ( (v42 & 0x80000000) != 0 )
        goto LABEL_115;
      v68 = v30;
      v15 = 0;
      v67 = 0;
      *v13 = v42;
      v66 = 14;
      v10[8] = v42;
LABEL_54:
      v42 = usb_string_id(v3);
      if ( (v42 & 0x80000000) == 0 )
      {
        if ( v14 == 16 * v12 )
          goto LABEL_129;
        v13[16 * v12] = v42;
        v90[8] = v42;
        if ( v9 && (v11 & 0x80000000) == 0 )
        {
          v42 = usb_string_id(v3);
          if ( (v42 & 0x80000000) != 0 )
            goto LABEL_115;
          if ( v14 <= 16 * (unsigned __int64)v11 )
            goto LABEL_129;
          v13[16 * v11] = v42;
          if ( v88 < 7 )
            goto LABEL_129;
          v9[7] = v42;
        }
        if ( !v89 )
          goto LABEL_66;
        v42 = usb_string_id(v3);
        if ( (v42 & 0x80000000) == 0 )
        {
          v13[16 * v82] = v42;
          if ( v68 < 3 )
            goto LABEL_129;
          v89[3] = v42;
LABEL_66:
          if ( v10 )
          {
            if ( (v15 & 1) != 0 )
              goto LABEL_129;
            v10[2] = *(_DWORD *)(a2 + 228);
          }
          if ( v9 )
          {
            if ( v88 < 2 )
              goto LABEL_129;
            v9[2] = *(_DWORD *)(a2 + 228);
          }
          if ( v8 )
          {
            if ( (v15 & 1) != 0 )
              goto LABEL_129;
            v8[3] = *(_DWORD *)(a2 + 228);
            v8[4] = *(_DWORD *)(a2 + 232);
          }
          v8 = v86;
          v9 = v87;
          v90[2] = *(_DWORD *)(a2 + 232);
          if ( v85 )
          {
            if ( v84 < 2 )
              goto LABEL_129;
            v85[2] = *(_DWORD *)(a2 + 232);
          }
          v43 = usb_ep_autoconfig(*v3, v86);
          if ( !v43 )
            goto LABEL_104;
          *(_QWORD *)(a2 + 304) = v43;
          v44 = (_QWORD *)v43;
          msm_ep_set_mode(v43, 2);
          *v44 = v3;
          if ( v87 )
          {
            v45 = usb_ep_autoconfig(*v3, v87);
            if ( !v45 )
              goto LABEL_104;
            *(_QWORD *)(a2 + 312) = v45;
            v46 = (_QWORD *)v45;
            msm_ep_set_mode(v45, 2);
            *v46 = v3;
          }
          v47 = v83;
          if ( !v83 )
            goto LABEL_90;
          v48 = (_QWORD *)usb_ep_autoconfig(*v3, v83);
          if ( v48 )
          {
            *(_QWORD *)(a2 + 1208) = v48;
            *v48 = v3;
            v49 = usb_ep_alloc_request();
            *(_QWORD *)(a2 + 1216) = v49;
            if ( v49 )
            {
              v50 = _kmalloc_noprof(v70, 3264);
              while ( 1 )
              {
                **(_QWORD **)(a2 + 1216) = v50;
                v51 = *(_QWORD *)(a2 + 1216);
                if ( !*(_QWORD *)v51 )
                  goto LABEL_102;
                *(_DWORD *)(v51 + 8) = v70;
                *(_QWORD *)(*(_QWORD *)(a2 + 1216) + 56LL) = a2;
                *(_QWORD *)(*(_QWORD *)(a2 + 1216) + 48LL) = gsi_ctrl_notify_resp_complete;
                v52 = **(_QWORD **)(a2 + 1216);
                *(_BYTE *)v52 = -95;
                v53 = *(_DWORD *)(a2 + 228);
                if ( v53 == -19 )
                  v53 = *(_DWORD *)(a2 + 232);
                v47 = v83;
                *(_WORD *)(v52 + 4) = v53;
                *(_WORD *)(v52 + 6) = 0;
LABEL_90:
                v54 = *(_QWORD *)(a2 + 312);
                *(_QWORD *)(a2 + 336) = v75;
                *(_QWORD *)(a2 + 344) = v74;
                if ( v54 )
                {
                  *(_QWORD *)(a2 + 424) = v66;
                  *(_QWORD *)(a2 + 432) = v69;
                }
                *(_DWORD *)(a2 + 824) = 0;
                *(_WORD *)(a2 + 820) = 32639;
                v55 = v8[2];
                v76[2] = v55;
                v77[2] = v55;
                if ( v9 )
                {
                  if ( (v67 & 1) != 0 )
                    goto LABEL_129;
                  v56 = v9[2];
                  v78[2] = v56;
                  v80[2] = v56;
                }
                if ( !v47 )
                  goto LABEL_98;
                if ( (v67 & 1) == 0 )
                {
                  v57 = v47[2];
                  v79[2] = v57;
                  v81[2] = v57;
LABEL_98:
                  if ( (unsigned int)usb_assign_descriptors(a2, v71, v72, v73, v73) )
                  {
                    v58 = *(_QWORD **)(a2 + 1216);
                    if ( !v58 )
                      break;
                    if ( *v58 )
                    {
                      kfree(*v58);
                      v51 = *(_QWORD *)(a2 + 1216);
LABEL_102:
                      if ( !v51 )
                        break;
                    }
                    usb_ep_free_request(*(_QWORD *)(a2 + 1208));
                    break;
                  }
                  if ( (unsigned int)wait_for_completion_timeout(&wait_for_ipa_ready, 1250) )
                  {
                    *(_QWORD *)(a2 + 1048) = &ipa_ops;
                    v62 = (__int64 (__fastcall *)(__int64, __int64))ipa_ops;
                    v63 = *(unsigned int *)(a2 + 224);
                    *(_QWORD *)(a2 + 512) = ipa_usb_notify_cb;
                    if ( *((_DWORD *)v62 - 1) != 465559982 )
                      __break(0x8228u);
                    result = v62(v63, a2 + 520);
                    if ( (_DWORD)result )
                    {
                      v34 = result;
                      if ( a2 )
                      {
                        ipc_log_string(
                          *(_QWORD *)(a2 + 1344),
                          "%s: failed to init teth prot(%d) with err:%d",
                          "gsi_bind",
                          *(_DWORD *)(a2 + 224),
                          result);
                        printk(&unk_10054, "gsi_bind");
                      }
                      goto LABEL_116;
                    }
                    *(_DWORD *)(a2 + 688) = 1;
                    return result;
                  }
                  if ( a2 )
                  {
                    ipc_log_string(*(_QWORD *)(a2 + 1344), "%s: ipa ready timeout", "gsi_bind");
                    printk(&unk_11A63, "gsi_bind");
                  }
                  v34 = -110;
LABEL_116:
                  rndis_deregister(*(_QWORD *)(a2 + 264));
                  return v34;
                }
LABEL_129:
                __break(1u);
                StatusReg = _ReadStatusReg(SP_EL0);
                v65 = *(_QWORD *)(StatusReg + 80);
                *(_QWORD *)(StatusReg + 80) = &gsi_update_function_bind_params__alloc_tag;
                v50 = _kmalloc_noprof(v70, 3264);
                *(_QWORD *)(StatusReg + 80) = v65;
              }
            }
          }
LABEL_104:
          v59 = *(_QWORD **)(a2 + 1208);
          if ( v59 )
            *v59 = 0;
          v60 = *(_QWORD *)(a2 + 312);
          if ( v60 && *(_QWORD *)(v60 + 24) )
          {
            msm_ep_set_mode(v60, 0);
            **(_QWORD **)(a2 + 312) = 0;
          }
          v61 = *(_QWORD *)(a2 + 304);
          if ( v61 && *(_QWORD *)(v61 + 24) )
          {
            msm_ep_set_mode(v61, 0);
            **(_QWORD **)(a2 + 304) = 0;
          }
          if ( a2 )
          {
            ipc_log_string(
              *(_QWORD *)(a2 + 1344),
              "%s: bind failed for %s",
              "gsi_update_function_bind_params",
              *(const char **)a2);
            printk(&unk_1130F, "gsi_update_function_bind_params");
          }
          v34 = -12;
          goto LABEL_116;
        }
      }
LABEL_115:
      v34 = v42;
      goto LABEL_116;
    }
    if ( v7 )
    {
      if ( v7 != 1 )
        goto LABEL_32;
      *(_QWORD *)(a2 + 552) = 0x80000000800LL;
      get_random_bytes(a2 + 526, 6);
      *(_BYTE *)(a2 + 526) = *(_BYTE *)(a2 + 526) & 0xFC | 2;
      get_random_bytes(a2 + 520, 6);
      v16 = *(_BYTE *)(a2 + 520) & 0xFC | 2;
      *(_BYTE *)(a2 + 520) = v16;
      if ( a2 )
      {
        ipc_log_string(
          *(_QWORD *)(a2 + 1344),
          "setting host_ethaddr=%pM, device_ethaddr = %pM",
          (const void *)(a2 + 520),
          (const void *)(a2 + 526));
        v16 = *(_BYTE *)(a2 + 520);
      }
      scnprintf(
        a2 + 240,
        14,
        "%02X%02X%02X%02X%02X%02X",
        v16,
        *(unsigned __int8 *)(a2 + 521),
        *(unsigned __int8 *)(a2 + 522),
        *(unsigned __int8 *)(a2 + 523),
        *(unsigned __int8 *)(a2 + 524),
        *(unsigned __int8 *)(a2 + 525));
      v13 = &ecm_gsi_string_defs;
      v86 = &ecm_gsi_fs_in_desc;
      v87 = &ecm_gsi_fs_out_desc;
      v85 = &ecm_gsi_data_nop_intf;
      v11 = 0;
      v89 = &ecm_gsi_desc;
      v90 = &ecm_gsi_data_intf;
      v9 = nullptr;
      v17 = &ecm_gsi_ss_function;
      v18 = &ecm_gsi_hs_function;
      v19 = &ecm_gsi_fs_function;
      v20 = &ecm_gsi_ss_notify_desc;
      v21 = &ecm_gsi_ss_out_desc;
      v22 = &ecm_gsi_ss_in_desc;
      v23 = &ecm_gsi_hs_notify_desc;
      v24 = &ecm_gsi_hs_out_desc;
      v25 = &ecm_gsi_hs_in_desc;
      v26 = &ecm_gsi_fs_notify_desc;
      v8 = &ecm_gsi_union_desc;
      qword_548 = a2 + 240;
      v10 = &ecm_gsi_control_intf;
      v27 = 16;
      v14 = 64;
      v28 = 15;
      v29 = 2048;
      v84 = 9;
      v30 = 13;
      v31 = 1;
      v12 = 2;
      v32 = 2048;
      v88 = 0;
      goto LABEL_52;
    }
    v34 = result;
    *(_QWORD *)(a2 + 552) = 0x600000004000LL;
    v35 = rndis_register(gsi_rndis_response_available, a2);
    if ( v35 > 0xFFFFFFFFFFFFF000LL )
      return v34;
    *(_QWORD *)(a2 + 264) = v35;
    rndis_set_param_medium();
    get_random_bytes(a2 + 526, 6);
    *(_BYTE *)(a2 + 526) = *(_BYTE *)(a2 + 526) & 0xFC | 2;
    get_random_bytes(a2 + 520, 6);
    *(_BYTE *)(a2 + 520) = *(_BYTE *)(a2 + 520) & 0xFC | 2;
    if ( a2 )
      ipc_log_string(
        *(_QWORD *)(a2 + 1344),
        "setting host_ethaddr=%pM, device_ethaddr = %pM",
        (const void *)(a2 + 520),
        (const void *)(a2 + 526));
    v36 = *(_WORD *)(a2 + 524);
    *(_DWORD *)(a2 + 240) = *(_DWORD *)(a2 + 520);
    v37 = *(_QWORD *)(a2 + 264);
    *(_WORD *)(a2 + 244) = v36;
    rndis_set_host_mac(v37, a2 + 240);
    if ( *(_QWORD *)(a2 + 256) && *(_DWORD *)(a2 + 236) && (unsigned int)rndis_set_param_vendor(*(_QWORD *)(a2 + 264)) )
      goto LABEL_116;
    v38 = *(_DWORD *)(a2 + 280);
    v39 = -32;
    v40 = 1;
    v41 = 3;
    if ( v38 > 4 )
    {
      if ( v38 <= 6 )
      {
        v39 = -17;
        if ( v38 != 5 )
          v41 = 4;
        v40 = 4;
      }
      else
      {
        switch ( v38 )
        {
          case 7:
            v39 = -17;
            v40 = 4;
            v41 = 5;
            break;
          case 8:
            v39 = -17;
            v40 = 4;
            v41 = 6;
            break;
          case 9:
            v39 = -17;
            v40 = 4;
            v41 = 7;
            break;
        }
      }
      goto LABEL_50;
    }
    if ( v38 > 2 )
    {
      if ( v38 != 3 )
      {
        v39 = -17;
        v40 = 4;
        v41 = 2;
LABEL_50:
        v9 = &rndis_gsi_iad_descriptor;
        v10 = &rndis_gsi_control_intf;
        byte_626 = v39;
        byte_615 = v39;
        v87 = &rndis_gsi_fs_out_desc;
        v86 = &rndis_gsi_fs_in_desc;
        v31 = 0;
        v30 = 0;
        v84 = 0;
        v85 = nullptr;
        v88 = 8;
        v89 = nullptr;
        v13 = &rndis_gsi_string_defs;
        v17 = &gsi_eth_ss_function;
        v18 = &gsi_eth_hs_function;
        v19 = &gsi_eth_fs_function;
        v20 = &rndis_gsi_ss_notify_desc;
        v21 = &rndis_gsi_ss_out_desc;
        v22 = &rndis_gsi_ss_in_desc;
        v23 = &rndis_gsi_hs_notify_desc;
        v24 = &rndis_gsi_hs_out_desc;
        byte_627 = v40;
        v25 = &rndis_gsi_hs_in_desc;
        byte_628 = v41;
        v26 = &rndis_gsi_fs_notify_desc;
        byte_616 = v40;
        v8 = &rndis_gsi_union_desc;
        byte_617 = v41;
        v11 = 2;
        v90 = &rndis_gsi_data_intf;
        v14 = 64;
        v32 = 24576;
        v28 = 50;
        v29 = 0x4000;
        v12 = 1;
        goto LABEL_51;
      }
    }
    else
    {
      if ( v38 )
      {
        if ( v38 == 2 )
        {
          v39 = -17;
          v41 = 1;
        }
        goto LABEL_50;
      }
      *(_DWORD *)(a2 + 280) = 3;
    }
    v39 = -17;
    v40 = 4;
    v41 = 1;
    goto LABEL_50;
  }
  return result;
}
