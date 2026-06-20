__int64 __fastcall ipa3_wwan_probe(__int64 a1, __int64 a2)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 result; // x0
  __int64 v6; // x0
  __int64 property; // x0
  const char *v8; // x1
  bool v9; // zf
  char v10; // w8
  const char *v11; // x1
  bool v12; // zf
  char v13; // w8
  const char *v14; // x1
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned int inited; // w0
  __int64 v18; // x8
  _QWORD *v19; // x10
  _QWORD *v20; // x9
  int v21; // w0
  unsigned int v22; // w19
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  unsigned int v26; // w20
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x19
  void *v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x8
  __int64 v38; // x8
  __int64 v39; // x0
  __int64 v40; // x8
  unsigned int v41; // w0
  __int64 *v42; // x9
  unsigned int v43; // w0
  __int64 v44; // x0
  __int64 v45; // x0
  unsigned int v46; // w0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x8
  __int64 v50; // x8
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  long double v61; // q0
  __int64 v62; // x0
  __int64 v63; // x0
  const char *v64[3]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v65; // [xsp+20h] [xbp-10h]
  __int64 v66; // [xsp+28h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  printk(&unk_3AAE37, a2);
  if ( (ipa_is_ready() & 1) != 0 )
    goto LABEL_9;
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa-wan %s:%d IPA driver not ready, registering callback\n", "ipa3_wwan_probe", 3661);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      ipc_logbuf_low,
      "ipa-wan %s:%d IPA driver not ready, registering callback\n",
      "ipa3_wwan_probe",
      3661);
  }
  result = ipa_register_ipa_ready_cb((__int64)ipa3_ready_cb, a1);
  if ( (_DWORD)result )
  {
    if ( (_DWORD)result != -17 )
    {
      v22 = result;
      printk(&unk_3D3D28, "ipa3_wwan_probe");
      if ( ipa3_get_ipc_logbuf() )
      {
        v23 = ipa3_get_ipc_logbuf();
        ipc_log_string(v23, "ipa-wan %s:%d IPA CB reg failed - %d\n", "ipa3_wwan_probe", 3670, v22);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v24 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v24, "ipa-wan %s:%d IPA CB reg failed - %d\n", "ipa3_wwan_probe", 3670, v22);
        result = v22;
        goto LABEL_7;
      }
      goto LABEL_48;
    }
LABEL_9:
    ipa_get_ep_mapping(35);
    v6 = *(_QWORD *)(a1 + 760);
    dword_2018C4 = 256;
    property = of_find_property(v6, "qcom,rmnet-ipa-ssr", 0);
    if ( property )
      v8 = "True";
    else
      v8 = "False";
    ipa3_rmnet_res = property != 0;
    printk(&unk_3E2031, v8);
    v9 = of_find_property(*(_QWORD *)(a1 + 760), "qcom,ipa-advertise-sg-support", 0) == 0;
    v10 = !v9;
    if ( v9 )
      v11 = "False";
    else
      v11 = "True";
    byte_2018C1 = v10;
    printk(&unk_3B638B, v11);
    v12 = of_find_property(*(_QWORD *)(a1 + 760), "qcom,ipa-napi-enable", 0) == 0;
    v13 = !v12;
    if ( v12 )
      v14 = "False";
    else
      v14 = "True";
    byte_2018C2 = v13;
    printk(&unk_3ADE61, v14);
    if ( (of_property_read_variable_u32_array(*(_QWORD *)(a1 + 760), "qcom,wan-rx-desc-size", &dword_2018C4, 1, 0)
        & 0x80000000) != 0 )
    {
      printk(&unk_3E785A, (unsigned int)dword_2018C4);
    }
    else
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v15 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v15,
          "ipa-wan %s:%d : found ipa_drv_res->wan-rx-desc-size = %u\n",
          "get_ipa_rmnet_dts_configuration",
          3565,
          dword_2018C4);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v16 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v16,
          "ipa-wan %s:%d : found ipa_drv_res->wan-rx-desc-size = %u\n",
          "get_ipa_rmnet_dts_configuration",
          3565,
          dword_2018C4);
      }
    }
    ipa3_rmnet_ctx = ipa3_rmnet_res;
    *(_BYTE *)(rmnet_ipa3_ctx + 1992) = ipa3_is_apq();
    inited = ipa3_init_q6_smem();
    if ( !inited )
    {
      v18 = rmnet_ipa3_ctx;
      *(_QWORD *)(rmnet_ipa3_ctx + 8) = 0;
      *(_QWORD *)(v18 + 16) = 0;
      v19 = (_QWORD *)(v18 + 556);
      *(_QWORD *)(v18 + 1036) = 0;
      *(_QWORD *)(v18 + 1042) = 0;
      *(_QWORD *)(v18 + 588) = 0;
      *(_QWORD *)(v18 + 596) = 0;
      *(_QWORD *)(v18 + 604) = 0;
      *(_QWORD *)(v18 + 612) = 0;
      *(_QWORD *)(v18 + 620) = 0;
      *(_QWORD *)(v18 + 628) = 0;
      *(_QWORD *)(v18 + 636) = 0;
      *(_QWORD *)(v18 + 644) = 0;
      *(_QWORD *)(v18 + 668) = 0;
      *(_QWORD *)(v18 + 676) = 0;
      *(_QWORD *)(v18 + 652) = 0;
      *(_QWORD *)(v18 + 660) = 0;
      *(_QWORD *)(v18 + 700) = 0;
      *(_QWORD *)(v18 + 708) = 0;
      *(_QWORD *)(v18 + 684) = 0;
      *(_QWORD *)(v18 + 692) = 0;
      *(_QWORD *)(v18 + 716) = 0;
      *(_QWORD *)(v18 + 724) = 0;
      *(_QWORD *)(v18 + 732) = 0;
      *(_QWORD *)(v18 + 740) = 0;
      *(_QWORD *)(v18 + 748) = 0;
      *(_QWORD *)(v18 + 756) = 0;
      *(_QWORD *)(v18 + 764) = 0;
      *(_QWORD *)(v18 + 772) = 0;
      *(_QWORD *)(v18 + 780) = 0;
      *(_QWORD *)(v18 + 788) = 0;
      *(_QWORD *)(v18 + 796) = 0;
      *(_QWORD *)(v18 + 804) = 0;
      *(_QWORD *)(v18 + 828) = 0;
      *(_QWORD *)(v18 + 836) = 0;
      *(_QWORD *)(v18 + 812) = 0;
      *(_QWORD *)(v18 + 820) = 0;
      *(_QWORD *)(v18 + 860) = 0;
      *(_QWORD *)(v18 + 868) = 0;
      *(_QWORD *)(v18 + 844) = 0;
      *(_QWORD *)(v18 + 852) = 0;
      *(_QWORD *)(v18 + 892) = 0;
      *(_QWORD *)(v18 + 900) = 0;
      *(_QWORD *)(v18 + 876) = 0;
      *(_QWORD *)(v18 + 884) = 0;
      *(_QWORD *)(v18 + 924) = 0;
      *(_QWORD *)(v18 + 932) = 0;
      *(_QWORD *)(v18 + 908) = 0;
      *(_QWORD *)(v18 + 916) = 0;
      *(_QWORD *)(v18 + 24) = 0;
      *(_QWORD *)(v18 + 32) = 0;
      *(_QWORD *)(v18 + 40) = 0;
      *(_QWORD *)(v18 + 48) = 0;
      *(_QWORD *)(v18 + 56) = 0;
      *(_QWORD *)(v18 + 64) = 0;
      *(_QWORD *)(v18 + 72) = 0;
      *(_QWORD *)(v18 + 80) = 0;
      *(_QWORD *)(v18 + 88) = 0;
      *(_QWORD *)(v18 + 96) = 0;
      *(_QWORD *)(v18 + 104) = 0;
      *(_QWORD *)(v18 + 112) = 0;
      *(_QWORD *)(v18 + 120) = 0;
      *(_QWORD *)(v18 + 128) = 0;
      *(_QWORD *)(v18 + 136) = 0;
      *(_QWORD *)(v18 + 144) = 0;
      *(_QWORD *)(v18 + 152) = 0;
      *(_QWORD *)(v18 + 160) = 0;
      *(_QWORD *)(v18 + 168) = 0;
      *(_QWORD *)(v18 + 176) = 0;
      *(_QWORD *)(v18 + 184) = 0;
      *(_QWORD *)(v18 + 192) = 0;
      *(_QWORD *)(v18 + 200) = 0;
      *(_QWORD *)(v18 + 208) = 0;
      *(_QWORD *)(v18 + 216) = 0;
      *(_QWORD *)(v18 + 224) = 0;
      *(_QWORD *)(v18 + 232) = 0;
      *(_QWORD *)(v18 + 240) = 0;
      *(_QWORD *)(v18 + 248) = 0;
      *(_QWORD *)(v18 + 256) = 0;
      *(_QWORD *)(v18 + 504) = 0;
      *(_QWORD *)(v18 + 512) = 0;
      *(_QWORD *)(v18 + 488) = 0;
      *(_QWORD *)(v18 + 496) = 0;
      *(_QWORD *)(v18 + 472) = 0;
      *(_QWORD *)(v18 + 480) = 0;
      *(_QWORD *)(v18 + 456) = 0;
      *(_QWORD *)(v18 + 464) = 0;
      *(_QWORD *)(v18 + 440) = 0;
      *(_QWORD *)(v18 + 448) = 0;
      *(_QWORD *)(v18 + 424) = 0;
      *(_QWORD *)(v18 + 432) = 0;
      *(_QWORD *)(v18 + 408) = 0;
      *(_QWORD *)(v18 + 416) = 0;
      *(_QWORD *)(v18 + 392) = 0;
      *(_QWORD *)(v18 + 400) = 0;
      *(_QWORD *)(v18 + 376) = 0;
      *(_QWORD *)(v18 + 384) = 0;
      *(_QWORD *)(v18 + 360) = 0;
      *(_QWORD *)(v18 + 368) = 0;
      *(_QWORD *)(v18 + 344) = 0;
      *(_QWORD *)(v18 + 352) = 0;
      *(_QWORD *)(v18 + 328) = 0;
      *(_QWORD *)(v18 + 336) = 0;
      *(_QWORD *)(v18 + 312) = 0;
      *(_QWORD *)(v18 + 320) = 0;
      *(_QWORD *)(v18 + 296) = 0;
      *(_QWORD *)(v18 + 304) = 0;
      *(_QWORD *)(v18 + 280) = 0;
      *(_QWORD *)(v18 + 288) = 0;
      *(_QWORD *)(v18 + 264) = 0;
      *(_QWORD *)(v18 + 272) = 0;
      *(_BYTE *)(v18 + 1993) = 0;
      *(_DWORD *)(v18 + 2056) = 0;
      *(_BYTE *)(v18 + 2060) = 0;
      *(_QWORD *)(v18 + 956) = 0;
      *(_QWORD *)(v18 + 964) = 0;
      *(_QWORD *)(v18 + 940) = 0;
      *(_QWORD *)(v18 + 948) = 0;
      v20 = (_QWORD *)(v18 + 972);
      v18 += 1004;
      *v19 = 0;
      v19[1] = 0;
      v19[2] = 0;
      v19[3] = 0;
      v20[2] = 0;
      v20[3] = 0;
      *v20 = 0;
      v20[1] = 0;
      *(_QWORD *)(v18 + 16) = 0;
      *(_QWORD *)(v18 + 24) = 0;
      *(_QWORD *)v18 = 0;
      *(_QWORD *)(v18 + 8) = 0;
      if ( (unsigned int)ipa3_ctx_get_type(1) == 1 || (unsigned int)ipa3_ctx_get_type(1) == 2 )
      {
        v21 = 3;
      }
      else if ( (ipa3_ctx_get_flag(2) & 1) != 0 )
      {
        v21 = 6;
      }
      else
      {
        v21 = 2;
      }
      v25 = ipa3_qmi_service_init(v21);
      if ( *(_DWORD *)(rmnet_ipa3_ctx + 1056) )
      {
        ipa3_wan_ioctl_enable_qmi_messages(v25);
      }
      else
      {
        v26 = ipa3_wan_ioctl_init(v25);
        if ( v26 )
        {
LABEL_42:
          ipa3_qmi_service_exit();
          result = v26;
          *(_DWORD *)(rmnet_ipa3_ctx + 1056) = 0;
          goto LABEL_7;
        }
      }
      v29 = alloc_netdev_mqs(680, "rmnet_ipa%d", 0);
      if ( !v29 )
      {
        printk(&unk_3DF468, "ipa3_wwan_probe");
        if ( ipa3_get_ipc_logbuf() )
        {
          v30 = ipa3_get_ipc_logbuf();
          ipc_log_string(v30, "ipa-wan %s:%d no memory for netdev\n", "ipa3_wwan_probe", 3736);
        }
        v31 = ipa3_get_ipc_logbuf_low();
        if ( v31 )
        {
          v32 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v32, "ipa-wan %s:%d no memory for netdev\n", "ipa3_wwan_probe", 3736);
        }
        v26 = -12;
        ipa3_wan_ioctl_deinit(v31);
        goto LABEL_42;
      }
      v33 = v29;
      v34 = (void *)(v29 + 2688);
      *(_QWORD *)rmnet_ipa3_ctx = v34;
      memset(v34, 0, 0x2A8u);
      if ( ipa3_get_ipc_logbuf() )
      {
        v35 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v35,
          "ipa-wan %s:%d wwan_ptr (private) = %pK",
          "ipa3_wwan_probe",
          3743,
          *(const void **)rmnet_ipa3_ctx);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v36 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v36,
          "ipa-wan %s:%d wwan_ptr (private) = %pK",
          "ipa3_wwan_probe",
          3743,
          *(const void **)rmnet_ipa3_ctx);
      }
      v37 = rmnet_ipa3_ctx;
      **(_QWORD **)rmnet_ipa3_ctx = v33;
      *(_DWORD *)(*(_QWORD *)v37 + 192LL) = 0;
      *(_DWORD *)(*(_QWORD *)v37 + 200LL) = 0;
      v38 = *(_QWORD *)v37;
      *(_DWORD *)(v38 + 208) = 0;
      v39 = _init_swait_queue_head(v38 + 216, "&x->wait", &init_completion___key_5);
      v40 = rmnet_ipa3_ctx;
      if ( !*(_DWORD *)(rmnet_ipa3_ctx + 1056) )
      {
        v41 = ipa3_q6_register_pm(v39);
        if ( v41 )
        {
          v26 = v41;
          printk(&unk_3D95CA, "ipa3_wwan_probe");
          if ( ipa3_get_ipc_logbuf() )
          {
            v58 = ipa3_get_ipc_logbuf();
            ipc_log_string(v58, "ipa-wan %s:%d ipa3_q6_register_pm failed, ret: %d\n", "ipa3_wwan_probe", 3755, v26);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v59 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v59, "ipa-wan %s:%d ipa3_q6_register_pm failed, ret: %d\n", "ipa3_wwan_probe", 3755, v26);
          }
LABEL_110:
          v63 = free_netdev(v33);
          *(_QWORD *)rmnet_ipa3_ctx = 0;
          ipa3_wan_ioctl_deinit(v63);
          goto LABEL_42;
        }
        v40 = rmnet_ipa3_ctx;
      }
      v42 = nullptr;
      v65 = 0;
      if ( v40 )
      {
        v42 = *(__int64 **)v40;
        if ( *(_QWORD *)v40 )
          v42 = (__int64 *)*v42;
      }
      v64[0] = (const char *)(v42 + 37);
      v64[1] = (const char *)ipa_pm_wwan_pm_cb;
      v64[2] = (const char *)v33;
      LODWORD(v65) = 1;
      v43 = ipa_pm_register((__int64)v64, (unsigned int *)(v40 + 1184));
      if ( v43 )
      {
        v26 = v43;
        printk(&unk_3F393B, "ipa3_wwan_register_netdev_pm_client");
        if ( ipa3_get_ipc_logbuf() )
        {
          v53 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v53,
            "ipa-wan %s:%d failed to create IPA PM client %d\n",
            "ipa3_wwan_register_netdev_pm_client",
            3624,
            v26);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v54 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v54,
            "ipa-wan %s:%d failed to create IPA PM client %d\n",
            "ipa3_wwan_register_netdev_pm_client",
            3624,
            v26);
        }
        printk(&unk_3B6355, "ipa3_wwan_probe");
        if ( ipa3_get_ipc_logbuf() )
        {
          v55 = ipa3_get_ipc_logbuf();
          ipc_log_string(v55, "ipa-wan %s:%d fail to create/register pm resources\n", "ipa3_wwan_probe", 3762);
        }
        v56 = ipa3_get_ipc_logbuf_low();
        if ( v56 )
        {
          v57 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v57, "ipa-wan %s:%d fail to create/register pm resources\n", "ipa3_wwan_probe", 3762);
        }
      }
      else
      {
        printk(&unk_3E7A62, "ipa3_wwan_register_netdev_pm_client");
        if ( ipa3_get_ipc_logbuf() )
        {
          v44 = ipa3_get_ipc_logbuf();
          ipc_log_string(v44, "ipa-wan %s:%d %s register done\n", "ipa3_wwan_register_netdev_pm_client", 3628, v64[0]);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v45 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v45, "ipa-wan %s:%d %s register done\n", "ipa3_wwan_register_netdev_pm_client", 3628, v64[0]);
        }
        if ( byte_2018C1 == 1 )
          *(_QWORD *)(v33 + 496) |= 1uLL;
        if ( (ipa3_is_ulso_supported() & 1) != 0 )
        {
          *(_QWORD *)(v33 + 496) |= 0x2001D0000uLL;
          *(_DWORD *)(v33 + 44) = 64000;
        }
        if ( byte_2018C2 == 1 )
          netif_napi_add_weight(v33, *(_QWORD *)rmnet_ipa3_ctx + 248LL, ipa3_rmnet_poll, 64);
        v46 = register_netdev(v33);
        if ( !v46 )
        {
          if ( ipa3_get_ipc_logbuf() )
          {
            v47 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v47,
              "ipa-wan %s:%d IPA-WWAN devices (%s) initialization ok :>>>>\n",
              "ipa3_wwan_probe",
              3791,
              (const char *)(v33 + 296));
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v48 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v48,
              "ipa-wan %s:%d IPA-WWAN devices (%s) initialization ok :>>>>\n",
              "ipa3_wwan_probe",
              3791,
              (const char *)(v33 + 296));
          }
          if ( (int)ipa3_ctx_get_type(0) >= 17 )
            *(_QWORD *)(v33 + 496) |= 0x80010000000012uLL;
          v49 = rmnet_ipa3_ctx;
          *(_DWORD *)(rmnet_ipa3_ctx + 1052) = 1;
          if ( !*(_DWORD *)(v49 + 1056) && (unsigned int)ipa3_ctx_get_type(0) != 14 )
            ipa3_proxy_clk_unvote();
          v50 = rmnet_ipa3_ctx;
          *(_DWORD *)(rmnet_ipa3_ctx + 1056) = 0;
          *(_DWORD *)(v50 + 1988) = 0;
          ipa3_update_ssr_state(0);
          qword_2018D8 = 0;
          qword_2018E0 = 0;
          ingress_pipe_status = 0;
          qword_2018D0 = 0;
          egress_pipe_status = 0;
          qword_2018F0 = 0;
          qword_2018F8 = 0;
          printk(&unk_3F93D8, "ipa3_wwan_probe");
          if ( ipa3_get_ipc_logbuf() )
          {
            v51 = ipa3_get_ipc_logbuf();
            ipc_log_string(v51, "ipa-wan %s:%d rmnet_ipa completed initialization\n", "ipa3_wwan_probe", 3828);
          }
          result = ipa3_get_ipc_logbuf_low();
          if ( result )
          {
            v52 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v52, "ipa-wan %s:%d rmnet_ipa completed initialization\n", "ipa3_wwan_probe", 3828);
            result = 0;
          }
          goto LABEL_7;
        }
        v26 = v46;
        printk(&unk_3ADE29, "ipa3_wwan_probe");
        if ( ipa3_get_ipc_logbuf() )
        {
          v60 = ipa3_get_ipc_logbuf();
          ipc_log_string(v60, "ipa-wan %s:%d unable to register ipa_netdev %d rc=%d\n", "ipa3_wwan_probe", 3787, 0, v26);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v62 = ipa3_get_ipc_logbuf_low();
          v61 = ipc_log_string(
                  v62,
                  "ipa-wan %s:%d unable to register ipa_netdev %d rc=%d\n",
                  "ipa3_wwan_probe",
                  3787,
                  0,
                  v26);
        }
        v56 = ipa3_wwan_deregister_netdev_pm_client(v61);
      }
      if ( !*(_DWORD *)(rmnet_ipa3_ctx + 1056) )
        ipa3_q6_deregister_pm(v56);
      goto LABEL_110;
    }
    v22 = inited;
    printk(&unk_3E2007, "ipa3_wwan_probe");
    if ( ipa3_get_ipc_logbuf() )
    {
      v27 = ipa3_get_ipc_logbuf();
      ipc_log_string(v27, "ipa-wan %s:%d ipa3_init_q6_smem failed\n", "ipa3_wwan_probe", 3685);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v28 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v28, "ipa-wan %s:%d ipa3_init_q6_smem failed\n", "ipa3_wwan_probe", 3685);
      result = v22;
      goto LABEL_7;
    }
LABEL_48:
    result = v22;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
