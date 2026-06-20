__int64 __fastcall ipa3_wan_ioctl(__int64 a1, int a2, __int64 a3)
{
  __int64 ipc_logbuf; // x0
  long double v6; // q0
  __int64 ipc_logbuf_low; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  unsigned __int64 v12; // x19
  int v13; // w21
  __int64 v14; // x0
  long double v15; // q0
  __int64 v16; // x0
  unsigned __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 result; // x0
  __int64 v23; // x0
  unsigned __int64 v24; // x0
  int v25; // w0
  int v26; // w20
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  unsigned __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  long double v33; // q0
  __int64 v34; // x0
  const char *v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  long double v38; // q0
  __int64 v39; // x0
  char *v40; // x0
  __int64 v41; // x0
  unsigned __int64 v42; // x1
  __int64 v43; // x2
  long double v44; // q0
  __int64 v45; // x0
  unsigned __int64 v46; // x0
  long double v47; // q0
  __int64 v48; // x0
  unsigned __int64 v49; // x0
  int v50; // w0
  long double v51; // q0
  __int64 v52; // x0
  __int64 *v53; // x0
  __int64 v54; // x0
  __int64 v55; // x0
  long double v56; // q0
  __int64 v57; // x0
  char *v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  long double v61; // q0
  __int64 v62; // x0
  unsigned __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x0
  long double v66; // q0
  __int64 v67; // x0
  __int64 *v68; // x0
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x0
  long double v72; // q0
  __int64 v73; // x0
  unsigned int *v74; // x0
  __int64 v75; // x0
  long double v76; // q0
  __int64 v77; // x0
  unsigned __int64 v78; // x0
  __int64 v79; // x0
  __int64 v80; // x0
  __int64 v81; // x0
  long double v82; // q0
  __int64 v83; // x0
  _DWORD *v84; // x0
  __int64 v85; // x0
  __int64 v86; // x0
  long double v87; // q0
  __int64 v88; // x0
  unsigned int *v89; // x0
  int per_client_stats; // w0
  long double v91; // q0
  __int64 v92; // x0
  unsigned int *v93; // x0
  __int64 v94; // x0
  __int64 v95; // x0
  __int64 v96; // x0
  long double v97; // q0
  __int64 v98; // x0
  char *v99; // x0
  __int64 v100; // x0
  __int64 v101; // x0
  long double v102; // q0
  __int64 v103; // x0
  char *v104; // x0
  __int64 v105; // x0
  __int64 v106; // x0
  long double v107; // q0
  __int64 v108; // x0
  unsigned __int64 v109; // x0
  __int64 v110; // x0
  long double v111; // q0
  __int64 v112; // x0
  unsigned __int64 v113; // x0
  __int64 v114; // x0
  __int64 v115; // x0
  __int64 v116; // x0
  __int64 v117; // x0
  __int64 v118; // x0
  __int64 v119; // x0
  __int64 v120; // x0
  __int64 v121; // x0
  __int64 v122; // x0
  __int64 v123; // x0
  __int64 v124; // x0
  __int64 v125; // x0
  __int64 v126; // x0
  __int64 v127; // x0
  __int64 v128; // x0
  __int64 v129; // x0
  __int64 v130; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa-wan %s:%d device %s got ioctl events :>>>\n", "ipa3_wan_ioctl", 79, "wwan_ioctl");
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v6 = ipc_log_string(
           ipc_logbuf_low,
           "ipa-wan %s:%d device %s got ioctl events :>>>\n",
           "ipa3_wan_ioctl",
           79,
           "wwan_ioctl");
  }
  if ( ipa3_process_ioctl == 1 )
  {
    if ( (unsigned int)(a2 + 1073190641) <= 1 )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v8 = ipa3_get_ipc_logbuf();
        ipc_log_string(v8, "ipa-wan %s:%d Modem is in SSR\n", "ipa3_wan_ioctl", 87);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v9 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v9, "ipa-wan %s:%d Modem is in SSR\n", "ipa3_wan_ioctl", 87);
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v10 = ipa3_get_ipc_logbuf();
        ipc_log_string(v10, "ipa-wan %s:%d Still allow IOCTL for exceptions (%d)\n", "ipa3_wan_ioctl", 89, a2);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v11 = ipa3_get_ipc_logbuf_low();
        v6 = ipc_log_string(v11, "ipa-wan %s:%d Still allow IOCTL for exceptions (%d)\n", "ipa3_wan_ioctl", 89, a2);
      }
      goto LABEL_15;
    }
    if ( (unsigned int)__ratelimit(&ipa3_wan_ioctl__rs, "ipa3_wan_ioctl") )
    {
      printk(&unk_3A7FD7, "ipa3_wan_ioctl");
      if ( !ipa3_get_ipc_logbuf() )
        goto LABEL_29;
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
LABEL_29:
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v21 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v21, "ipa-wan %s:%d Modem is in SSR, ignoring ioctl (%d)\n", "ipa3_wan_ioctl", 92, a2);
      }
      return -11;
    }
    v20 = ipa3_get_ipc_logbuf();
    ipc_log_string(v20, "ipa-wan %s:%d Modem is in SSR, ignoring ioctl (%d)\n", "ipa3_wan_ioctl", 92, a2);
    goto LABEL_29;
  }
LABEL_15:
  v12 = 0;
  v13 = -25;
  switch ( a2 )
  {
    case -1073190655:
      if ( ipa3_get_ipc_logbuf() )
      {
        v14 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v14,
          "ipa-wan %s:%d device %s got WAN_IOC_ADD_FLT_RULE_INDEX :>>>\n",
          "ipa3_wan_ioctl",
          192,
          "wwan_ioctl");
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v16 = ipa3_get_ipc_logbuf_low();
        v15 = ipc_log_string(
                v16,
                "ipa-wan %s:%d device %s got WAN_IOC_ADD_FLT_RULE_INDEX :>>>\n",
                "ipa3_wan_ioctl",
                192,
                "wwan_ioctl");
      }
      v17 = vmemdup_user(a3, 1908, v15);
      v12 = v17;
      if ( v17 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_174;
      if ( !(unsigned int)((__int64 (__fastcall *)(unsigned __int64))ipa3_qmi_filter_notify_send)(v17) )
      {
        v41 = a3;
        v42 = v12;
        v43 = 1908;
        goto LABEL_196;
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v18 = ipa3_get_ipc_logbuf();
        ipc_log_string(v18, "ipa-wan %s:%d IPACM->Q6 rule index fail\n", "ipa3_wan_ioctl", 202);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v19 = ipa3_get_ipc_logbuf_low();
        v6 = ipc_log_string(v19, "ipa-wan %s:%d IPACM->Q6 rule index fail\n", "ipa3_wan_ioctl", 202);
        goto LABEL_184;
      }
      goto LABEL_234;
    case -1073190654:
      if ( ipa3_get_ipc_logbuf() )
      {
        v71 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v71,
          "ipa-wan %s:%d device %s got WAN_IOC_VOTE_FOR_BW_MBPS :>>>\n",
          "ipa3_wan_ioctl",
          214,
          "wwan_ioctl");
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v73 = ipa3_get_ipc_logbuf_low();
        v72 = ipc_log_string(
                v73,
                "ipa-wan %s:%d device %s got WAN_IOC_VOTE_FOR_BW_MBPS :>>>\n",
                "ipa3_wan_ioctl",
                214,
                "wwan_ioctl");
      }
      v74 = (unsigned int *)vmemdup_user(a3, 4, v72);
      v12 = (unsigned __int64)v74;
      if ( (unsigned __int64)v74 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_174;
      if ( !(unsigned int)ipa3_vote_for_bus_bw(v74) )
      {
        v41 = a3;
        v42 = v12;
        v43 = 4;
        goto LABEL_196;
      }
      printk(&unk_3ED595, "ipa3_wan_ioctl");
      if ( ipa3_get_ipc_logbuf() )
      {
        v125 = ipa3_get_ipc_logbuf();
        ipc_log_string(v125, "ipa-wan %s:%d Failed to vote for bus BW\n", "ipa3_wan_ioctl", 223);
      }
      if ( !ipa3_get_ipc_logbuf_low() )
        goto LABEL_234;
      v126 = ipa3_get_ipc_logbuf_low();
      v6 = ipc_log_string(v126, "ipa-wan %s:%d Failed to vote for bus BW\n", "ipa3_wan_ioctl", 223);
      goto LABEL_184;
    case -1073190653:
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v52 = ipa3_get_ipc_logbuf_low();
        v51 = ipc_log_string(v52, "ipa-wan %s:%d got WAN_IOCTL_POLL_TETHERING_STATS :>>>\n", "ipa3_wan_ioctl", 234);
      }
      v53 = (__int64 *)vmemdup_user(a3, 16, v51);
      v12 = (unsigned __int64)v53;
      if ( (unsigned __int64)v53 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_174;
      if ( !(unsigned int)rmnet_ipa3_poll_tethering_stats(v53) )
      {
        v41 = a3;
        v42 = v12;
        v43 = 16;
        goto LABEL_196;
      }
      if ( !(unsigned int)__ratelimit(&ipa3_wan_ioctl__rs_28, "ipa3_wan_ioctl") )
      {
        if ( !ipa3_get_ipc_logbuf() )
          goto LABEL_80;
        goto LABEL_79;
      }
      printk(&unk_3B0C3A, "ipa3_wan_ioctl");
      if ( ipa3_get_ipc_logbuf() )
      {
LABEL_79:
        v54 = ipa3_get_ipc_logbuf();
        ipc_log_string(v54, "ipa-wan %s:%d WAN_IOCTL_POLL_TETHERING_STATS failed\n", "ipa3_wan_ioctl", 244);
      }
LABEL_80:
      if ( !ipa3_get_ipc_logbuf_low() )
        goto LABEL_234;
      v55 = ipa3_get_ipc_logbuf_low();
      v6 = ipc_log_string(v55, "ipa-wan %s:%d WAN_IOCTL_POLL_TETHERING_STATS failed\n", "ipa3_wan_ioctl", 244);
LABEL_184:
      v13 = -14;
LABEL_199:
      if ( v12 <= 0xFFFFFFFFFFFFF000LL )
LABEL_200:
        kvfree(v12, v6);
      result = v13;
      break;
    case -1073190652:
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v48 = ipa3_get_ipc_logbuf_low();
        v47 = ipc_log_string(
                v48,
                "ipa-wan %s:%d device %s got WAN_IOCTL_SET_DATA_QUOTA :>>>\n",
                "ipa3_wan_ioctl",
                256,
                "wwan_ioctl");
      }
      v49 = vmemdup_user(a3, 32, v47);
      v12 = v49;
      if ( v49 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_174;
      v50 = rmnet_ipa3_set_data_quota(v49);
      if ( !v50 )
      {
        v41 = a3;
        v42 = v12;
        v43 = 32;
        goto LABEL_196;
      }
      v26 = v50;
      printk(&unk_3BC6CA, "ipa3_wan_ioctl");
      if ( ipa3_get_ipc_logbuf() )
      {
        v123 = ipa3_get_ipc_logbuf();
        ipc_log_string(v123, "ipa-wan %s:%d WAN_IOC_SET_DATA_QUOTA failed\n", "ipa3_wan_ioctl", 267);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v124 = ipa3_get_ipc_logbuf_low();
        v6 = ipc_log_string(v124, "ipa-wan %s:%d WAN_IOC_SET_DATA_QUOTA failed\n", "ipa3_wan_ioctl", 267);
      }
      goto LABEL_219;
    case -1073190651:
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v62 = ipa3_get_ipc_logbuf_low();
        v61 = ipc_log_string(v62, "ipa-wan %s:%d got WAN_IOC_SET_TETHER_CLIENT_PIPE :>>>\n", "ipa3_wan_ioctl", 313);
      }
      v63 = vmemdup_user(a3, 176, v61);
      v12 = v63;
      if ( v63 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_174;
      if ( !(unsigned int)((__int64 (__fastcall *)(unsigned __int64))rmnet_ipa3_set_tether_client_pipe)(v63) )
        goto LABEL_168;
      printk(&unk_3C54FF, "ipa3_wan_ioctl");
      if ( ipa3_get_ipc_logbuf() )
      {
        v64 = ipa3_get_ipc_logbuf();
        ipc_log_string(v64, "ipa-wan %s:%d WAN_IOC_SET_TETHER_CLIENT_PIPE failed\n", "ipa3_wan_ioctl", 323);
      }
      if ( !ipa3_get_ipc_logbuf_low() )
        goto LABEL_234;
      v65 = ipa3_get_ipc_logbuf_low();
      v6 = ipc_log_string(v65, "ipa-wan %s:%d WAN_IOC_SET_TETHER_CLIENT_PIPE failed\n", "ipa3_wan_ioctl", 323);
      goto LABEL_184;
    case -1073190650:
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v39 = ipa3_get_ipc_logbuf_low();
        v38 = ipc_log_string(v39, "ipa-wan %s:%d got WAN_IOC_QUERY_TETHER_STATS :>>>\n", "ipa3_wan_ioctl", 330);
      }
      v40 = (char *)vmemdup_user(a3, 104, v38);
      v12 = (unsigned __int64)v40;
      if ( (unsigned __int64)v40 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_174;
      if ( !(unsigned int)rmnet_ipa3_query_tethering_stats(v40) )
      {
        v41 = a3;
        v42 = v12;
        v43 = 104;
        goto LABEL_196;
      }
      printk(&unk_3B0C71, "ipa3_wan_ioctl");
      if ( ipa3_get_ipc_logbuf() )
      {
        v119 = ipa3_get_ipc_logbuf();
        ipc_log_string(v119, "ipa-wan %s:%d WAN_IOC_QUERY_TETHER_STATS failed\n", "ipa3_wan_ioctl", 341);
      }
      if ( !ipa3_get_ipc_logbuf_low() )
        goto LABEL_234;
      v120 = ipa3_get_ipc_logbuf_low();
      v6 = ipc_log_string(v120, "ipa-wan %s:%d WAN_IOC_QUERY_TETHER_STATS failed\n", "ipa3_wan_ioctl", 341);
      goto LABEL_184;
    case -1073190649:
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v57 = ipa3_get_ipc_logbuf_low();
        v56 = ipc_log_string(
                v57,
                "ipa-wan %s:%d device %s got WAN_IOC_RESET_TETHER_STATS :>>>\n",
                "ipa3_wan_ioctl",
                377,
                "wwan_ioctl");
      }
      v58 = (char *)vmemdup_user(a3, 17, v56);
      v12 = (unsigned __int64)v58;
      if ( (unsigned __int64)v58 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_174;
      if ( !(unsigned int)rmnet_ipa3_reset_tethering_stats(v58) )
        goto LABEL_168;
      printk(&unk_3D98BE, "ipa3_wan_ioctl");
      if ( ipa3_get_ipc_logbuf() )
      {
        v59 = ipa3_get_ipc_logbuf();
        ipc_log_string(v59, "ipa-wan %s:%d WAN_IOC_RESET_TETHER_STATS failed\n", "ipa3_wan_ioctl", 388);
      }
      if ( !ipa3_get_ipc_logbuf_low() )
        goto LABEL_234;
      v60 = ipa3_get_ipc_logbuf_low();
      v6 = ipc_log_string(v60, "ipa-wan %s:%d WAN_IOC_RESET_TETHER_STATS failed\n", "ipa3_wan_ioctl", 388);
      goto LABEL_184;
    case -1073190648:
      goto LABEL_200;
    case -1073190647:
      if ( ipa3_get_ipc_logbuf() )
      {
        v96 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v96,
          "ipa-wan %s:%d device %s got WAN_IOC_ADD_FLT_RULE_EX :>>>\n",
          "ipa3_wan_ioctl",
          100,
          "wwan_ioctl");
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v98 = ipa3_get_ipc_logbuf_low();
        v97 = ipc_log_string(
                v98,
                "ipa-wan %s:%d device %s got WAN_IOC_ADD_FLT_RULE_EX :>>>\n",
                "ipa3_wan_ioctl",
                100,
                "wwan_ioctl");
      }
      v99 = (char *)vmemdup_user(a3, 42296, v97);
      v12 = (unsigned __int64)v99;
      if ( (unsigned __int64)v99 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_174;
      if ( !(unsigned int)ipa3_qmi_filter_request_ex_send(v99) )
      {
        v41 = a3;
        v42 = v12;
        v43 = 42296;
        goto LABEL_196;
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v100 = ipa3_get_ipc_logbuf();
        ipc_log_string(v100, "ipa-wan %s:%d IPACM->Q6 add filter rule failed\n", "ipa3_wan_ioctl", 110);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v101 = ipa3_get_ipc_logbuf_low();
        v6 = ipc_log_string(v101, "ipa-wan %s:%d IPACM->Q6 add filter rule failed\n", "ipa3_wan_ioctl", 110);
        goto LABEL_184;
      }
      goto LABEL_234;
    case -1073190646:
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v45 = ipa3_get_ipc_logbuf_low();
        v44 = ipc_log_string(v45, "ipa-wan %s:%d got WAN_IOC_QUERY_TETHER_STATS_ALL :>>>\n", "ipa3_wan_ioctl", 353);
      }
      v46 = vmemdup_user(a3, 40, v44);
      v12 = v46;
      if ( v46 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_174;
      if ( !(unsigned int)rmnet_ipa3_query_tethering_stats_all(v46) )
        goto LABEL_67;
      printk(&unk_3B0C71, "ipa3_wan_ioctl");
      if ( ipa3_get_ipc_logbuf() )
      {
        v121 = ipa3_get_ipc_logbuf();
        ipc_log_string(v121, "ipa-wan %s:%d WAN_IOC_QUERY_TETHER_STATS failed\n", "ipa3_wan_ioctl", 364);
      }
      if ( !ipa3_get_ipc_logbuf_low() )
        goto LABEL_234;
      v122 = ipa3_get_ipc_logbuf_low();
      v6 = ipc_log_string(v122, "ipa-wan %s:%d WAN_IOC_QUERY_TETHER_STATS failed\n", "ipa3_wan_ioctl", 364);
      goto LABEL_184;
    case -1073190645:
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v34 = ipa3_get_ipc_logbuf_low();
        v33 = ipc_log_string(
                v34,
                "ipa-wan %s:%d device %s got WAN_IOC_NOTIFY_WAN_STATE :>>>\n",
                "ipa3_wan_ioctl",
                396,
                "wwan_ioctl");
      }
      v35 = (const char *)vmemdup_user(a3, 17, v33);
      v12 = (unsigned __int64)v35;
      if ( (unsigned __int64)v35 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_174;
      if ( !(unsigned int)ipa3_wwan_set_modem_state(v35) )
        goto LABEL_168;
      printk(&unk_3D0E5B, "ipa3_wan_ioctl");
      if ( ipa3_get_ipc_logbuf() )
      {
        v36 = ipa3_get_ipc_logbuf();
        ipc_log_string(v36, "ipa-wan %s:%d WAN_IOC_NOTIFY_WAN_STATE failed\n", "ipa3_wan_ioctl", 407);
      }
      if ( !ipa3_get_ipc_logbuf_low() )
        goto LABEL_234;
      v37 = ipa3_get_ipc_logbuf_low();
      v6 = ipc_log_string(v37, "ipa-wan %s:%d WAN_IOC_NOTIFY_WAN_STATE failed\n", "ipa3_wan_ioctl", 407);
      goto LABEL_184;
    case -1073190644:
      if ( ipa3_get_ipc_logbuf() )
      {
        v81 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v81,
          "ipa-wan %s:%d device %s got WAN_IOC_UL_ADD_FLT_RULE :>>>\n",
          "ipa3_wan_ioctl",
          168,
          "wwan_ioctl");
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v83 = ipa3_get_ipc_logbuf_low();
        v82 = ipc_log_string(
                v83,
                "ipa-wan %s:%d device %s got WAN_IOC_UL_ADD_FLT_RULE :>>>\n",
                "ipa3_wan_ioctl",
                168,
                "wwan_ioctl");
      }
      v84 = (_DWORD *)vmemdup_user(a3, 12044, v82);
      v12 = (unsigned __int64)v84;
      if ( (unsigned __int64)v84 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_174;
      if ( !(unsigned int)ipa3_qmi_ul_filter_request_send(v84) )
      {
        v41 = a3;
        v42 = v12;
        v43 = 12044;
        goto LABEL_196;
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v85 = ipa3_get_ipc_logbuf();
        ipc_log_string(v85, "ipa-wan %s:%d IPACM->Q6 add ul filter rule failed\n", "ipa3_wan_ioctl", 180);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v86 = ipa3_get_ipc_logbuf_low();
        v6 = ipc_log_string(v86, "ipa-wan %s:%d IPACM->Q6 add ul filter rule failed\n", "ipa3_wan_ioctl", 180);
        goto LABEL_184;
      }
      goto LABEL_234;
    case -1073190643:
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v103 = ipa3_get_ipc_logbuf_low();
        v102 = ipc_log_string(v103, "ipa-wan %s:%d got WAN_IOC_ENABLE_PER_CLIENT_STATS :>>>\n", "ipa3_wan_ioctl", 419);
      }
      v104 = (char *)vmemdup_user(a3, 1, v102);
      v12 = (unsigned __int64)v104;
      if ( (unsigned __int64)v104 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_174;
      if ( !(unsigned int)rmnet_ipa3_enable_per_client_stats(v104) )
        goto LABEL_168;
      printk(&unk_3E7AC5, "ipa3_wan_ioctl");
      if ( ipa3_get_ipc_logbuf() )
      {
        v105 = ipa3_get_ipc_logbuf();
        ipc_log_string(v105, "ipa-wan %s:%d WAN_IOC_ENABLE_PER_CLIENT_STATS failed\n", "ipa3_wan_ioctl", 429);
      }
      if ( !ipa3_get_ipc_logbuf_low() )
        goto LABEL_234;
      v106 = ipa3_get_ipc_logbuf_low();
      v6 = ipc_log_string(v106, "ipa-wan %s:%d WAN_IOC_ENABLE_PER_CLIENT_STATS failed\n", "ipa3_wan_ioctl", 429);
      goto LABEL_184;
    case -1073190642:
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v88 = ipa3_get_ipc_logbuf_low();
        v87 = ipc_log_string(v88, "ipa-wan %s:%d got WAN_IOC_QUERY_PER_CLIENT_STATS :>>>\n", "ipa3_wan_ioctl", 435);
      }
      v89 = (unsigned int *)vmemdup_user(a3, 648, v87);
      v12 = (unsigned __int64)v89;
      if ( (unsigned __int64)v89 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_174;
      if ( *(_DWORD *)(ipa3_ctx + 32240) < 0x11u )
        per_client_stats = rmnet_ipa3_query_per_client_stats(v89);
      else
        per_client_stats = rmnet_ipa3_query_per_client_stats_v2(v89);
      v13 = per_client_stats;
      if ( !per_client_stats )
      {
        v41 = a3;
        v42 = v12;
        v43 = 648;
        goto LABEL_196;
      }
      printk(&unk_3D0E8C, "ipa3_wan_ioctl");
      if ( ipa3_get_ipc_logbuf() )
      {
        v127 = ipa3_get_ipc_logbuf();
        ipc_log_string(v127, "ipa-wan %s:%d WAN_IOC_QUERY_PER_CLIENT_STATS failed\n", "ipa3_wan_ioctl", 450);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v128 = ipa3_get_ipc_logbuf_low();
        v6 = ipc_log_string(v128, "ipa-wan %s:%d WAN_IOC_QUERY_PER_CLIENT_STATS failed\n", "ipa3_wan_ioctl", 450);
      }
      goto LABEL_199;
    case -1073190641:
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v92 = ipa3_get_ipc_logbuf_low();
        v91 = ipc_log_string(v92, "ipa-wan %s:%d got WAN_IOC_SET_LAN_CLIENT_INFO :>>>\n", "ipa3_wan_ioctl", 461);
      }
      v93 = (unsigned int *)vmemdup_user(a3, 24, v91);
      v12 = (unsigned __int64)v93;
      if ( (unsigned __int64)v93 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_174;
      if ( !(unsigned int)rmnet_ipa3_set_lan_client_info(v93) )
        goto LABEL_168;
      printk(&unk_3DCAE6, "ipa3_wan_ioctl");
      if ( ipa3_get_ipc_logbuf() )
      {
        v94 = ipa3_get_ipc_logbuf();
        ipc_log_string(v94, "ipa-wan %s:%d WAN_IOC_SET_LAN_CLIENT_INFO failed\n", "ipa3_wan_ioctl", 471);
      }
      if ( !ipa3_get_ipc_logbuf_low() )
        goto LABEL_234;
      v95 = ipa3_get_ipc_logbuf_low();
      v6 = ipc_log_string(v95, "ipa-wan %s:%d WAN_IOC_SET_LAN_CLIENT_INFO failed\n", "ipa3_wan_ioctl", 471);
      goto LABEL_184;
    case -1073190640:
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v108 = ipa3_get_ipc_logbuf_low();
        v107 = ipc_log_string(v108, "ipa-wan %s:%d got WAN_IOC_CLEAR_LAN_CLIENT_INFO :>>>\n", "ipa3_wan_ioctl", 478);
      }
      v109 = vmemdup_user(a3, 24, v107);
      v12 = v109;
      if ( v109 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_174;
      if ( !(unsigned int)((__int64 (__fastcall *)(unsigned __int64))rmnet_ipa3_clear_lan_client_info)(v109) )
        goto LABEL_168;
      printk(&unk_3F95EC, "ipa3_wan_ioctl");
      if ( ipa3_get_ipc_logbuf() )
      {
        v129 = ipa3_get_ipc_logbuf();
        ipc_log_string(v129, "ipa-wan %s:%d WAN_IOC_CLEAR_LAN_CLIENT_INFO failed\n", "ipa3_wan_ioctl", 488);
      }
      if ( !ipa3_get_ipc_logbuf_low() )
        goto LABEL_234;
      v130 = ipa3_get_ipc_logbuf_low();
      v6 = ipc_log_string(v130, "ipa-wan %s:%d WAN_IOC_CLEAR_LAN_CLIENT_INFO failed\n", "ipa3_wan_ioctl", 488);
      goto LABEL_184;
    case -1073190639:
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v67 = ipa3_get_ipc_logbuf_low();
        v66 = ipc_log_string(v67, "ipa-wan %s:%d got WAN_IOC_SEND_LAN_CLIENT_MSG :>>>\n", "ipa3_wan_ioctl", 496);
      }
      v68 = (__int64 *)vmemdup_user(a3, 44, v66);
      v12 = (unsigned __int64)v68;
      if ( (unsigned __int64)v68 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_174;
      if ( !(unsigned int)rmnet_ipa3_send_lan_client_msg(v68) )
      {
LABEL_168:
        v13 = 0;
        goto LABEL_199;
      }
      printk(&unk_3BC72B, "ipa3_wan_ioctl");
      if ( ipa3_get_ipc_logbuf() )
      {
        v69 = ipa3_get_ipc_logbuf();
        ipc_log_string(v69, "ipa-wan %s:%d IOC_SEND_LAN_CLIENT_MSG failed\n", "ipa3_wan_ioctl", 507);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v70 = ipa3_get_ipc_logbuf_low();
        v6 = ipc_log_string(v70, "ipa-wan %s:%d IOC_SEND_LAN_CLIENT_MSG failed\n", "ipa3_wan_ioctl", 507);
        goto LABEL_184;
      }
      goto LABEL_234;
    case -1073190638:
      if ( ipa3_get_ipc_logbuf() )
      {
        v110 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v110,
          "ipa-wan %s:%d device %s got WAN_IOC_ADD_OFFLOAD_CONNECTION :>>>\n",
          "ipa3_wan_ioctl",
          122,
          "wwan_ioctl");
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v112 = ipa3_get_ipc_logbuf_low();
        v111 = ipc_log_string(
                 v112,
                 "ipa-wan %s:%d device %s got WAN_IOC_ADD_OFFLOAD_CONNECTION :>>>\n",
                 "ipa3_wan_ioctl",
                 122,
                 "wwan_ioctl");
      }
      v113 = vmemdup_user(a3, 14124, v111);
      v12 = v113;
      if ( v113 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_174;
      if ( !(unsigned int)ipa3_qmi_add_offload_request_send(v113) )
      {
        v41 = a3;
        v42 = v12;
        v43 = 14124;
        goto LABEL_196;
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v115 = ipa3_get_ipc_logbuf();
        ipc_log_string(v115, "ipa-wan %s:%d IPACM->Q6 add offload connection failed\n", "ipa3_wan_ioctl", 133);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v116 = ipa3_get_ipc_logbuf_low();
        v6 = ipc_log_string(v116, "ipa-wan %s:%d IPACM->Q6 add offload connection failed\n", "ipa3_wan_ioctl", 133);
        goto LABEL_184;
      }
      goto LABEL_234;
    case -1073190637:
      if ( ipa3_get_ipc_logbuf() )
      {
        v75 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v75,
          "ipa-wan %s:%d device %s got WAN_IOC_RMV_OFFLOAD_CONNECTION :>>>\n",
          "ipa3_wan_ioctl",
          145,
          "wwan_ioctl");
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v77 = ipa3_get_ipc_logbuf_low();
        v76 = ipc_log_string(
                v77,
                "ipa-wan %s:%d device %s got WAN_IOC_RMV_OFFLOAD_CONNECTION :>>>\n",
                "ipa3_wan_ioctl",
                145,
                "wwan_ioctl");
      }
      v78 = vmemdup_user(a3, 524, v76);
      v12 = v78;
      if ( v78 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_174;
      if ( !(unsigned int)ipa3_qmi_rmv_offload_request_send(v78) )
      {
        v41 = a3;
        v42 = v12;
        v43 = 524;
        goto LABEL_196;
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v79 = ipa3_get_ipc_logbuf();
        ipc_log_string(v79, "ipa-wan %s:%d IPACM->Q6 add offload connection failed\n", "ipa3_wan_ioctl", 156);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v80 = ipa3_get_ipc_logbuf_low();
        v6 = ipc_log_string(v80, "ipa-wan %s:%d IPACM->Q6 add offload connection failed\n", "ipa3_wan_ioctl", 156);
        goto LABEL_184;
      }
LABEL_234:
      v13 = -14;
      goto LABEL_199;
    case -1073190636:
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v29 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v29, "ipa-wan %s:%d got WAN_IOC_GET_WAN_MTU :>>>\n", "ipa3_wan_ioctl", 522);
      }
      v30 = memdup_user(a3, 40);
      v12 = v30;
      if ( v30 >= 0xFFFFFFFFFFFFF001LL )
        goto LABEL_174;
      if ( !(unsigned int)rmnet_ipa3_get_wan_mtu(v30) )
        goto LABEL_67;
      printk(&unk_3ED662, "ipa3_wan_ioctl");
      if ( ipa3_get_ipc_logbuf() )
      {
        v31 = ipa3_get_ipc_logbuf();
        ipc_log_string(v31, "ipa-wan %s:%d WAN_IOC_GET_WAN_MTU failed\n", "ipa3_wan_ioctl", 532);
      }
      if ( !ipa3_get_ipc_logbuf_low() )
        goto LABEL_234;
      v32 = ipa3_get_ipc_logbuf_low();
      v6 = ipc_log_string(v32, "ipa-wan %s:%d WAN_IOC_GET_WAN_MTU failed\n", "ipa3_wan_ioctl", 532);
      goto LABEL_184;
    default:
      if ( a2 == -1073649386 )
      {
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v114 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v114, "ipa-wan %s:%d got WAN_IOC_NOTIFY_NAT_MOVE_RES :>>>\n", "ipa3_wan_ioctl", 513);
        }
        if ( (unsigned int)rmnet_ipa3_notify_nat_move_res(a3 != 0) )
        {
          printk(&unk_3F9622, "ipa3_wan_ioctl");
          if ( ipa3_get_ipc_logbuf() )
          {
            v117 = ipa3_get_ipc_logbuf();
            ipc_log_string(v117, "ipa-wan %s:%d WAN_IOC_NOTIFY_NAT_MOVE_RES failed\n", "ipa3_wan_ioctl", 515);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v118 = ipa3_get_ipc_logbuf_low();
            v6 = ipc_log_string(v118, "ipa-wan %s:%d WAN_IOC_NOTIFY_NAT_MOVE_RES failed\n", "ipa3_wan_ioctl", 515);
          }
          v12 = 0;
          v13 = -14;
        }
        else
        {
          v13 = 0;
          v12 = 0;
        }
        goto LABEL_200;
      }
      if ( a2 != -1071093483 )
        goto LABEL_200;
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v23 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v23,
          "ipa-wan %s:%d device %s got WAN_IOC_SET_DATA_QUOTA_WARNING :>>>\n",
          "ipa3_wan_ioctl",
          283,
          "wwan_ioctl");
      }
      v24 = memdup_user(a3, 40);
      v12 = v24;
      if ( v24 >= 0xFFFFFFFFFFFFF001LL )
      {
LABEL_174:
        v13 = v12;
      }
      else
      {
        v25 = rmnet_ipa3_set_data_quota_warning(v24);
        if ( v25 )
        {
          v26 = v25;
          printk(&unk_3C54D0, "ipa3_wan_ioctl");
          if ( ipa3_get_ipc_logbuf() )
          {
            v27 = ipa3_get_ipc_logbuf();
            ipc_log_string(v27, "ipa-wan %s:%d SET_DATA_QUOTA_WARNING failed\n", "ipa3_wan_ioctl", 298);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v28 = ipa3_get_ipc_logbuf_low();
            v6 = ipc_log_string(v28, "ipa-wan %s:%d SET_DATA_QUOTA_WARNING failed\n", "ipa3_wan_ioctl", 298);
          }
LABEL_219:
          if ( v26 == -19 )
            v13 = -19;
          else
            v13 = -14;
        }
        else
        {
LABEL_67:
          v41 = a3;
          v42 = v12;
          v43 = 40;
LABEL_196:
          if ( inline_copy_to_user_1(v41, v42, v43) )
            v13 = -14;
          else
            v13 = 0;
        }
      }
      goto LABEL_199;
  }
  return result;
}
