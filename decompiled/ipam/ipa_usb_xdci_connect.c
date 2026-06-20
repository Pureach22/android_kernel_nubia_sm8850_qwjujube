__int64 __fastcall ipa_usb_xdci_connect(__int64 a1, __int64 a2, unsigned int *a3, unsigned int *a4, int *a5)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v11; // x24
  __int64 v12; // x0
  const char *v13; // x4
  long double v14; // q0
  __int64 v15; // x0
  const char *v16; // x4
  int r_rev_version; // w19
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x19
  __int64 ipc_logbuf; // x0
  __int64 v23; // x0
  unsigned int v24; // w24
  unsigned int v25; // w0
  unsigned int v26; // w0
  __int64 v27; // x25
  int v28; // w24
  unsigned int v29; // w28
  unsigned int v30; // w23
  int v31; // w22
  int v32; // w20
  char v33; // w19
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x27
  __int64 v39; // x9
  unsigned int v40; // w0
  unsigned int v41; // w0
  unsigned int v42; // w0
  unsigned int v43; // w0
  unsigned int v44; // w0
  __int64 v45; // x0
  __int64 v46; // x0
  unsigned int *v47; // x19
  __int64 v48; // x23
  __int64 v49; // x0
  __int64 v50; // x0
  long double v51; // q0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x0
  long double v64; // q0
  __int64 v65; // x0
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x0
  __int64 v72; // x0
  __int64 v73; // x0
  __int64 v74; // x0
  __int64 v75; // x0
  __int64 v76; // x0
  __int64 v77; // x0
  long double v78; // q0
  __int64 v79; // x0
  int v80; // w8
  __int64 v81; // x2
  int v82; // w8
  __int64 v83; // x2
  __int64 v85; // x0
  __int64 v86; // x0
  __int64 v87; // x0
  __int64 v88; // x0
  __int64 v89; // x0
  __int64 v90; // x0
  __int64 v91; // x0
  __int64 v92; // x0
  unsigned int *v93; // [xsp+8h] [xbp-48h]
  char v94; // [xsp+14h] [xbp-3Ch]
  unsigned int *v95; // [xsp+20h] [xbp-30h]
  __int64 v96; // [xsp+28h] [xbp-28h]
  unsigned int v97; // [xsp+34h] [xbp-1Ch]
  __int64 v98; // [xsp+38h] [xbp-18h]
  int v99; // [xsp+40h] [xbp-10h]

  _ReadStatusReg(SP_EL0);
  mutex_lock(ipa3_usb_ctx + 544);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_usb %s:%d entry\n", "ipa_usb_xdci_connect", 1928);
  }
  if ( !a4 || !a2 || !a5 || (v11 = (unsigned int)a5[2], (_DWORD)v11 != 4) && (!a1 || !a3) )
  {
    printk(&unk_3AB53C, "ipa_usb_xdci_connect");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_usb %s:%d bad parameters\n", "ipa_usb_xdci_connect", 1933);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v23 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v23, "ipa_usb %s:%d bad parameters\n", "ipa_usb_xdci_connect", 1933);
    }
    v24 = -22;
    goto LABEL_154;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v12 = ipa3_get_ipc_logbuf();
    if ( (unsigned int)v11 > 5 )
      v13 = "unsupported";
    else
      v13 = off_1E5248[v11];
    ipc_log_string(v12, "ipa_usb %s:%d Start new_teth=%s\n", "ipa3_usb_is_teth_switch_valid", 706, v13);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v15 = ipa3_get_ipc_logbuf_low();
    if ( (unsigned int)v11 > 5 )
      v16 = "unsupported";
    else
      v16 = off_1E5248[v11];
    v14 = ipc_log_string(v15, "ipa_usb %s:%d Start new_teth=%s\n", "ipa3_usb_is_teth_switch_valid", 706, v16);
  }
  if ( (_DWORD)v11 == 4 || (unsigned int)ipa_get_hw_type() != 17 )
    goto LABEL_40;
  r_rev_version = ipa3_get_r_rev_version();
  if ( ipa3_get_ipc_logbuf() )
  {
    v18 = ipa3_get_ipc_logbuf();
    ipc_log_string(v18, "ipa_usb %s:%d ipa_r_rev=%u\n", "ipa3_usb_is_teth_switch_valid", 715, r_rev_version);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v19 = ipa3_get_ipc_logbuf_low();
    v14 = ipc_log_string(v19, "ipa_usb %s:%d ipa_r_rev=%u\n", "ipa3_usb_is_teth_switch_valid", 715, r_rev_version);
  }
  if ( r_rev_version != 13 && r_rev_version != 10 )
  {
LABEL_40:
    if ( a5[2] != 4 )
    {
      v25 = ipa3_usb_request_xdci_channel(v14);
      if ( v25 )
      {
        v24 = v25;
        printk(&unk_3C27CA, "ipa_usb_xdci_connect");
        if ( ipa3_get_ipc_logbuf() )
        {
          v67 = ipa3_get_ipc_logbuf();
          ipc_log_string(v67, "ipa_usb %s:%d failed to allocate UL channel\n", "ipa_usb_xdci_connect", 1947);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v68 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v68, "ipa_usb %s:%d failed to allocate UL channel\n", "ipa_usb_xdci_connect", 1947);
        }
        goto LABEL_154;
      }
    }
    v26 = ipa3_usb_request_xdci_channel(v14);
    if ( v26 )
    {
      v24 = v26;
      printk(&unk_3F9C0C, "ipa_usb_xdci_connect");
      if ( ipa3_get_ipc_logbuf() )
      {
        v50 = ipa3_get_ipc_logbuf();
        ipc_log_string(v50, "ipa_usb %s:%d failed to allocate DL/DPL channel\n", "ipa_usb_xdci_connect", 1955);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v52 = ipa3_get_ipc_logbuf_low();
        v51 = ipc_log_string(v52, "ipa_usb %s:%d failed to allocate DL/DPL channel\n", "ipa_usb_xdci_connect", 1955);
      }
      goto LABEL_149;
    }
    v27 = (unsigned int)a5[2];
    v96 = a1;
    if ( (_DWORD)v27 == 4 )
    {
      v97 = 0;
      v28 = 0;
      v94 = 0;
    }
    else
    {
      v28 = *((unsigned __int8 *)a5 + 6);
      v97 = *a3;
      v94 = *((_BYTE *)a5 + 7);
    }
    v95 = a4;
    v29 = *a4;
    v30 = a5[6];
    v31 = *a5;
    v32 = *((unsigned __int8 *)a5 + 4);
    v33 = *((_BYTE *)a5 + 5);
    v98 = *(_QWORD *)(a5 + 3);
    v99 = a5[5];
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v34 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v34, "ipa_usb %s:%d entry\n", "ipa3_usb_xdci_connect_internal", 1632);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v35 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v35, "ipa_usb %s:%d ul xferrscidx = %d\n", "ipa3_usb_check_connect_params", 1352, v28);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v36 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v36, "ipa_usb %s:%d dl xferrscidx = %d\n", "ipa3_usb_check_connect_params", 1353, v32);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v37 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v37,
        "ipa_usb %s:%d max_supported_bandwidth_mbps = %d\n",
        "ipa3_usb_check_connect_params",
        1355,
        v30);
    }
    if ( (unsigned int)(v31 - 1025) < 0xFFFFFC3F
      || (char)v32 < 0
      || (_DWORD)v27 != 4 && ((unsigned int)v27 > 5 || (v28 & 0x80) != 0) )
    {
      printk(&unk_3FCC4E, "ipa3_usb_check_connect_params");
      if ( ipa3_get_ipc_logbuf() )
      {
        v46 = ipa3_get_ipc_logbuf();
        ipc_log_string(v46, "ipa_usb %s:%d Invalid params\n", "ipa3_usb_check_connect_params", 1364);
      }
      v47 = v95;
      a1 = v96;
      v48 = a2;
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v49 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v49, "ipa_usb %s:%d Invalid params\n", "ipa3_usb_check_connect_params", 1364);
      }
    }
    else
    {
      if ( *(_DWORD *)(ipa3_usb_ctx + 72LL * (unsigned int)v27 + 56) != 2 )
      {
        v93 = a3;
        if ( (_DWORD)v27 == 4 )
          v38 = 1;
        else
          v38 = 2 * (unsigned int)((_DWORD)v27 == 5);
        if ( (ipa3_usb_check_legal_op(2, v38) & 1) != 0 )
        {
          v39 = ipa3_usb_ctx + (v38 << 8);
          *(_DWORD *)(v39 + 828) = v29;
          if ( (_DWORD)v27 != 4 )
            *(_DWORD *)(v39 + 824) = v97;
          *(_QWORD *)(v39 + 832) = v98;
          *(_DWORD *)(v39 + 840) = v99;
          v40 = ipa3_set_usb_max_packet_size(v31);
          if ( v40 )
          {
            v24 = v40;
            printk(&unk_3E265B, "ipa3_usb_xdci_connect_internal");
            if ( ipa3_get_ipc_logbuf() )
            {
              v55 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v55,
                "ipa_usb %s:%d failed setting xDCI EE scratch field\n",
                "ipa3_usb_xdci_connect_internal",
                1656);
            }
            v47 = v95;
            a1 = v96;
            a3 = v93;
            v48 = a2;
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v56 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v56,
                "ipa_usb %s:%d failed setting xDCI EE scratch field\n",
                "ipa3_usb_xdci_connect_internal",
                1656);
            }
          }
          else if ( (_DWORD)v27 != 4
                 && (v41 = ((__int64 (__fastcall *)(_QWORD, _QWORD))ipa_pm_set_throughput)(
                             *(unsigned int *)(ipa3_usb_ctx + (v38 << 8) + 632),
                             v30)) != 0 )
          {
            v24 = v41;
            printk(&unk_3BCB74, "ipa3_usb_xdci_connect_internal");
            if ( ipa3_get_ipc_logbuf() )
            {
              v70 = ipa3_get_ipc_logbuf();
              ipc_log_string(v70, "ipa_usb %s:%d failed to set pm throughput\n", "ipa3_usb_xdci_connect_internal", 1665);
            }
            v47 = v95;
            a1 = v96;
            a3 = v93;
            v48 = a2;
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v71 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v71, "ipa_usb %s:%d failed to set pm throughput\n", "ipa3_usb_xdci_connect_internal", 1665);
            }
          }
          else
          {
            v42 = ipa_pm_activate_sync(*(_DWORD *)(ipa3_usb_ctx + (v38 << 8) + 632));
            if ( v42 )
            {
              v24 = v42;
              printk(&unk_3A5497, "ipa3_usb_xdci_connect_internal");
              if ( ipa3_get_ipc_logbuf() )
              {
                v57 = ipa3_get_ipc_logbuf();
                ipc_log_string(v57, "ipa_usb %s:%d failed to activate pm\n", "ipa3_usb_xdci_connect_internal", 1673);
              }
              v47 = v95;
              a1 = v96;
              a3 = v93;
              v48 = a2;
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v58 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(v58, "ipa_usb %s:%d failed to activate pm\n", "ipa3_usb_xdci_connect_internal", 1673);
              }
            }
            else
            {
              if ( (_DWORD)v27 != 4 && (v43 = ipa3_xdci_start(v97, v28, v94 & 1)) != 0 )
              {
                v24 = v43;
                printk(&unk_3DFB95, "ipa3_usb_xdci_connect_internal");
                v47 = v95;
                a1 = v96;
                v48 = a2;
                if ( ipa3_get_ipc_logbuf() )
                {
                  v72 = ipa3_get_ipc_logbuf();
                  ipc_log_string(
                    v72,
                    "ipa_usb %s:%d failed to connect UL channel\n",
                    "ipa3_usb_xdci_connect_internal",
                    1694);
                }
                if ( ipa3_get_ipc_logbuf_low() )
                {
                  v73 = ipa3_get_ipc_logbuf_low();
                  ipc_log_string(
                    v73,
                    "ipa_usb %s:%d failed to connect UL channel\n",
                    "ipa3_usb_xdci_connect_internal",
                    1694);
                }
              }
              else
              {
                v44 = ipa3_xdci_start(v29, v32, v33);
                if ( v44 )
                {
                  v24 = v44;
                  printk(&unk_3F9CBA, "ipa3_usb_xdci_connect_internal");
                  if ( ipa3_get_ipc_logbuf() )
                  {
                    v59 = ipa3_get_ipc_logbuf();
                    ipc_log_string(
                      v59,
                      "ipa_usb %s:%d failed to connect DL/DPL channel\n",
                      "ipa3_usb_xdci_connect_internal",
                      1704);
                  }
                  v47 = v95;
                  a1 = v96;
                  v48 = a2;
                  if ( ipa3_get_ipc_logbuf_low() )
                  {
                    v60 = ipa3_get_ipc_logbuf_low();
                    ipc_log_string(
                      v60,
                      "ipa_usb %s:%d failed to connect DL/DPL channel\n",
                      "ipa3_usb_xdci_connect_internal",
                      1704);
                  }
                }
                else
                {
                  v24 = ipa3_usb_connect_teth_prot((unsigned int)v27);
                  if ( v24 )
                  {
                    printk(&unk_3B3849, "ipa3_usb_xdci_connect_internal");
                    if ( ipa3_get_ipc_logbuf() )
                    {
                      v61 = ipa3_get_ipc_logbuf();
                      ipc_log_string(
                        v61,
                        "ipa_usb %s:%d failed to connect teth protocol\n",
                        "ipa3_usb_xdci_connect_internal",
                        1711);
                    }
                    if ( ipa3_get_ipc_logbuf_low() )
                    {
                      v62 = ipa3_get_ipc_logbuf_low();
                      ipc_log_string(
                        v62,
                        "ipa_usb %s:%d failed to connect teth protocol\n",
                        "ipa3_usb_xdci_connect_internal",
                        1711);
                    }
                  }
                  else
                  {
                    if ( (ipa3_usb_set_state(2, 0, v38) & 1) != 0 )
                    {
                      if ( ipa3_get_ipc_logbuf_low() )
                      {
                        v45 = ipa3_get_ipc_logbuf_low();
                        ipc_log_string(v45, "ipa_usb %s:%d exit\n", "ipa3_usb_xdci_connect_internal", 1721);
                      }
                      goto LABEL_117;
                    }
                    printk(&unk_3E5069, "ipa3_usb_xdci_connect_internal");
                    if ( ipa3_get_ipc_logbuf() )
                    {
                      v63 = ipa3_get_ipc_logbuf();
                      ipc_log_string(
                        v63,
                        "ipa_usb %s:%d failed to change state to connected\n",
                        "ipa3_usb_xdci_connect_internal",
                        1717);
                    }
                    if ( ipa3_get_ipc_logbuf_low() )
                    {
                      v65 = ipa3_get_ipc_logbuf_low();
                      v64 = ipc_log_string(
                              v65,
                              "ipa_usb %s:%d failed to change state to connected\n",
                              "ipa3_usb_xdci_connect_internal",
                              1717);
                    }
                    ((void (__fastcall *)(_QWORD, long double))ipa3_usb_disconnect_teth_prot)((unsigned int)v27, v64);
                  }
                  ipa3_xdci_disconnect(v29, 0, 0xFFFFFFFF);
                  ipa3_reset_gsi_channel((_QWORD *)v29);
                  ((void (__fastcall *)(_QWORD))ipa3_reset_gsi_event_ring)(v29);
                  v47 = v95;
                  a1 = v96;
                  v48 = a2;
                }
                if ( (_DWORD)v27 != 4 )
                {
                  ipa3_xdci_disconnect(v97, 0, 0xFFFFFFFF);
                  ipa3_reset_gsi_channel((_QWORD *)v97);
                  ((void (__fastcall *)(_QWORD))ipa3_reset_gsi_event_ring)(v97);
                }
              }
              ((void (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)(*(unsigned int *)(ipa3_usb_ctx + (v38 << 8) + 632));
              a3 = v93;
              if ( !v24 )
              {
LABEL_117:
                if ( ipa3_get_ipc_logbuf_low() )
                {
                  v66 = ipa3_get_ipc_logbuf_low();
                  ipc_log_string(v66, "ipa_usb %s:%d exit\n", "ipa_usb_xdci_connect", 1984);
                }
                v24 = 0;
LABEL_154:
                mutex_unlock(ipa3_usb_ctx + 544);
                _ReadStatusReg(SP_EL0);
                return v24;
              }
            }
          }
        }
        else
        {
          printk(&unk_3A5362, "ipa3_usb_xdci_connect_internal");
          a3 = v93;
          if ( ipa3_get_ipc_logbuf() )
          {
            v53 = ipa3_get_ipc_logbuf();
            ipc_log_string(v53, "ipa_usb %s:%d Illegal operation\n", "ipa3_usb_xdci_connect_internal", 1641);
          }
          v47 = v95;
          a1 = v96;
          v48 = a2;
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v54 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v54, "ipa_usb %s:%d Illegal operation\n", "ipa3_usb_xdci_connect_internal", 1641);
          }
          v24 = -1;
        }
        goto LABEL_141;
      }
      v47 = v95;
      a1 = v96;
      v48 = a2;
      printk(&unk_3B9A6A, "ipa3_usb_check_connect_params");
      if ( ipa3_get_ipc_logbuf() )
      {
        v69 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v69,
          "ipa_usb %s:%d %s is not initialized\n",
          "ipa3_usb_check_connect_params",
          1372,
          off_1E5248[v27]);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v74 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v74,
          "ipa_usb %s:%d %s is not initialized\n",
          "ipa3_usb_check_connect_params",
          1372,
          off_1E5248[v27]);
      }
    }
    printk(&unk_3AB53C, "ipa3_usb_xdci_connect_internal");
    if ( ipa3_get_ipc_logbuf() )
    {
      v75 = ipa3_get_ipc_logbuf();
      ipc_log_string(v75, "ipa_usb %s:%d bad parameters\n", "ipa3_usb_xdci_connect_internal", 1634);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v76 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v76, "ipa_usb %s:%d bad parameters\n", "ipa3_usb_xdci_connect_internal", 1634);
    }
    v24 = -22;
LABEL_141:
    printk(&unk_3F3DBB, "ipa_usb_xdci_connect");
    if ( ipa3_get_ipc_logbuf() )
    {
      v77 = ipa3_get_ipc_logbuf();
      ipc_log_string(v77, "ipa_usb %s:%d failed to connect\n", "ipa_usb_xdci_connect", 1980);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v79 = ipa3_get_ipc_logbuf_low();
      v78 = ipc_log_string(v79, "ipa_usb %s:%d failed to connect\n", "ipa_usb_xdci_connect", 1980);
    }
    v80 = *(_DWORD *)(v48 + 4);
    if ( v80 == 4 )
      v81 = 1;
    else
      v81 = 2 * (unsigned int)(v80 == 5);
    ipa3_usb_release_xdci_channel(*v47, 1, v81, v78);
LABEL_149:
    if ( a5[2] != 4 )
    {
      v82 = *(_DWORD *)(a1 + 4);
      if ( v82 == 4 )
        v83 = 1;
      else
        v83 = 2 * (unsigned int)(v82 == 5);
      ipa3_usb_release_xdci_channel(*a3, 0, v83, v51);
    }
    goto LABEL_154;
  }
  v20 = ipa3_usb_ctx;
  if ( !ipa3_usb_ctx )
  {
    printk(&unk_3B6A0E, "ipa3_usb_is_teth_switch_valid");
    if ( ipa3_get_ipc_logbuf() )
    {
      v85 = ipa3_get_ipc_logbuf();
      ipc_log_string(v85, "ipa_usb %s:%d Invalid context", "ipa3_usb_is_teth_switch_valid", 722);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v86 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v86, "ipa_usb %s:%d Invalid context", "ipa3_usb_is_teth_switch_valid", 722);
    }
    goto LABEL_167;
  }
  if ( (unsigned int)v11 >= 6 )
  {
    printk(&unk_3B37D0, "ipa3_usb_is_teth_switch_valid");
    if ( ipa3_get_ipc_logbuf() )
    {
      v87 = ipa3_get_ipc_logbuf();
      ipc_log_string(v87, "ipa_usb %s:%d Invalid new_teth %d\n", "ipa3_usb_is_teth_switch_valid", 727, v11);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v88 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v88, "ipa_usb %s:%d Invalid new_teth %d\n", "ipa3_usb_is_teth_switch_valid", 727, v11);
    }
    goto LABEL_167;
  }
  if ( (*(_BYTE *)(ipa3_usb_ctx + 1392) & 1) == 0 )
  {
    *(_DWORD *)(ipa3_usb_ctx + 1396) = v11;
    *(_BYTE *)(v20 + 1392) = 1;
    goto LABEL_40;
  }
  v21 = *(unsigned int *)(ipa3_usb_ctx + 1396);
  if ( (unsigned int)v21 >= 6 )
  {
    __break(0x5512u);
  }
  else if ( v11 + 6 * (unsigned __int64)(unsigned int)v21 <= 0x23 )
  {
    if ( teth_type_switch_tbl_ipa45[6 * (unsigned int)v21 + v11] == 1 )
    {
      *(_DWORD *)(ipa3_usb_ctx + 1396) = v11;
      goto LABEL_40;
    }
    if ( ipa3_get_ipc_logbuf() )
    {
      v89 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v89,
        "ipa_usb %s:%d Invalid teth switch %s -> %s\n",
        "ipa3_usb_is_teth_switch_valid",
        745,
        off_1E5248[v21],
        off_1E5248[v11]);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v90 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v90,
        "ipa_usb %s:%d Invalid teth switch %s -> %s\n",
        "ipa3_usb_is_teth_switch_valid",
        745,
        off_1E5248[v21],
        off_1E5248[v11]);
    }
LABEL_167:
    printk(&unk_3F3D69, "ipa_usb_xdci_connect");
    if ( ipa3_get_ipc_logbuf() )
    {
      v91 = ipa3_get_ipc_logbuf();
      ipc_log_string(v91, "ipa_usb %s:%d Invalid teth type switch\n", "ipa_usb_xdci_connect", 1939);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v92 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v92, "ipa_usb %s:%d Invalid teth type switch\n", "ipa_usb_xdci_connect", 1939);
    }
    v24 = -14;
    goto LABEL_154;
  }
  __break(1u);
  return ipa3_usb_request_xdci_channel(v14);
}
