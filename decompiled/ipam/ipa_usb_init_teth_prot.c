__int64 __fastcall ipa_usb_init_teth_prot(unsigned int a1, int *a2, __int64 a3, __int64 a4)
{
  long double v8; // q0
  __int64 ipc_logbuf_low; // x0
  bool v10; // cf
  __int64 v11; // x19
  __int64 v12; // x27
  __int64 v13; // x24
  const char *v14; // x8
  __int64 v15; // x0
  unsigned int v16; // w0
  int v17; // w8
  unsigned int v18; // w1
  unsigned int v19; // w0
  __int64 v20; // x8
  __int64 v21; // x10
  __int64 v22; // x9
  __int64 v23; // x9
  _QWORD *v24; // x24
  __int64 v25; // t1
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 ipc_logbuf; // x0
  __int64 v29; // x0
  unsigned int inited; // w21
  __int64 v31; // x8
  __int64 v32; // x24
  int v33; // w9
  int v34; // w9
  unsigned int v35; // w0
  __int64 v36; // x0
  const char *v37; // x8
  const char *v38; // x4
  __int64 v39; // x0
  const char *v40; // x8
  const char *v41; // x4
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x8
  __int64 v45; // x8
  __int64 v46; // x8
  unsigned int v47; // w0
  __int64 v48; // x19
  __int64 v49; // x0
  const char *v50; // x8
  const char *v51; // x4
  __int64 v52; // x0
  const char *v53; // x8
  const char *v54; // x4
  __int64 v55; // x3
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x9
  __int64 v63; // x0
  const char *v64; // x8
  const char *v65; // x5
  __int64 v66; // x0
  const char *v67; // x5
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x0
  long double v71; // q0
  __int64 v72; // x0
  __int64 v73; // x0
  __int64 v74; // x0
  __int64 v75; // x20
  const char *v76; // x0
  __int64 v77; // x20
  const char *v78; // x0
  __int64 v79; // x0
  __int64 v80; // x0
  __int64 v81; // x0
  __int64 v83; // x0
  __int64 v84; // x0
  __int64 v85; // x0
  __int64 v86; // x0

  mutex_lock(ipa3_usb_ctx + 544);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v8 = ipc_log_string(ipc_logbuf_low, "ipa_usb %s:%d entry\n", "ipa_usb_init_teth_prot", 773);
  }
  if ( a1 > 5 || (!a2 ? (v10 = a1 >= 2) : (v10 = 1), !v10 || !a3 || !a4) )
  {
    printk(&unk_3AB53C, "ipa_usb_init_teth_prot");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_usb %s:%d bad parameters\n", "ipa_usb_init_teth_prot", 778);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v29 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v29, "ipa_usb %s:%d bad parameters\n", "ipa_usb_init_teth_prot", 778);
      goto LABEL_45;
    }
LABEL_146:
    inited = -22;
    goto LABEL_154;
  }
  if ( a1 == 4 )
    v11 = 1;
  else
    v11 = 2 * (unsigned int)(a1 == 5);
  if ( (ipa3_usb_check_legal_op(0, (unsigned int)v11, v8) & 1) == 0 )
  {
    printk(&unk_3A5362, "ipa_usb_init_teth_prot");
    if ( ipa3_get_ipc_logbuf() )
    {
      v60 = ipa3_get_ipc_logbuf();
      ipc_log_string(v60, "ipa_usb %s:%d Illegal operation\n", "ipa_usb_init_teth_prot", 786);
    }
    if ( !ipa3_get_ipc_logbuf_low() )
      goto LABEL_114;
    v61 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v61, "ipa_usb %s:%d Illegal operation\n", "ipa_usb_init_teth_prot", 786);
    goto LABEL_113;
  }
  v12 = ipa3_usb_ctx;
  v13 = ipa3_usb_ctx + 592 + (v11 << 8);
  if ( a1 != 4 && a1 != 5 && *(int *)(ipa3_usb_ctx + 432) > 0 )
  {
    v25 = *(_QWORD *)(v13 + 48);
    v24 = (_QWORD *)(v13 + 48);
    v23 = v25;
    if ( v25 )
    {
      v20 = ipa3_usb_ctx;
      if ( v23 != a3 )
      {
LABEL_36:
        printk(&unk_3EDA6B, "ipa_usb_init_teth_prot");
        if ( ipa3_get_ipc_logbuf() )
        {
          v26 = ipa3_get_ipc_logbuf();
          ipc_log_string(v26, "ipa_usb %s:%d Got different notify_cb\n", "ipa_usb_init_teth_prot", 805);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v27 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v27, "ipa_usb %s:%d Got different notify_cb\n", "ipa_usb_init_teth_prot", 805);
LABEL_45:
          inited = -22;
          goto LABEL_154;
        }
        goto LABEL_146;
      }
      goto LABEL_48;
    }
    v20 = ipa3_usb_ctx;
    goto LABEL_47;
  }
  v14 = "USB";
  if ( a1 == 5 )
    v14 = "USB2";
  v15 = ipa3_usb_ctx + 592 + (v11 << 8);
  *(_QWORD *)(v13 + 16) = v13;
  *(_QWORD *)(v13 + 24) = 0;
  if ( a1 == 4 )
    v14 = "USB DPL";
  *(_QWORD *)v13 = v14;
  *(_QWORD *)(v13 + 8) = ipa3_usb_pm_cb;
  v16 = ipa_pm_register(v15, (unsigned int *)(v13 + 40));
  if ( v16 )
  {
    inited = v16;
    printk(&unk_3FF9C0, "ipa3_usb_register_pm");
    if ( ipa3_get_ipc_logbuf() )
    {
      v68 = ipa3_get_ipc_logbuf();
      ipc_log_string(v68, "ipa_usb %s:%d fail to register with PM %d\n", "ipa3_usb_register_pm", 661, inited);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v69 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v69, "ipa_usb %s:%d fail to register with PM %d\n", "ipa3_usb_register_pm", 661, inited);
    }
  }
  else
  {
    if ( a1 == 5 )
      v17 = 21;
    else
      v17 = 19;
    if ( a1 == 4 )
      v18 = 27;
    else
      v18 = v17;
    v19 = ipa_pm_associate_ipa_cons_to_client(*(_DWORD *)(v13 + 40), v18);
    if ( !v19 )
    {
      v20 = ipa3_usb_ctx;
      v21 = ipa3_usb_ctx + (v11 << 8);
      v22 = *(_QWORD *)(v21 + 640);
      if ( v22 )
      {
        if ( a1 == 4 )
        {
          printk(&unk_3F0ACC, "ipa_usb_init_teth_prot");
          if ( ipa3_get_ipc_logbuf() )
          {
            v79 = ipa3_get_ipc_logbuf();
            ipc_log_string(v79, "ipa_usb %s:%d Already has dpl_notify_cb\n", "ipa_usb_init_teth_prot", 810);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v80 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v80, "ipa_usb %s:%d Already has dpl_notify_cb\n", "ipa_usb_init_teth_prot", 810);
            goto LABEL_45;
          }
          goto LABEL_146;
        }
        if ( v22 != a3 )
          goto LABEL_36;
        goto LABEL_48;
      }
      v24 = (_QWORD *)(v21 + 640);
LABEL_47:
      *v24 = a3;
LABEL_48:
      if ( (int)a1 <= 3 )
      {
        if ( a1 < 2 )
        {
          v31 = v20 + 72LL * a1;
          if ( *(_DWORD *)(v31 + 56) == 2 )
          {
            *(_QWORD *)(v31 + 64) = a4;
            v32 = v12 + 72LL * a1;
            *(_QWORD *)v32 = ipa3_usb_device_ready_notify_cb;
            v33 = *a2;
            *(_WORD *)(v32 + 28) = *((_WORD *)a2 + 2);
            *(_DWORD *)(v32 + 24) = v33;
            v34 = *(int *)((char *)a2 + 6);
            *(_WORD *)(v32 + 34) = *((_WORD *)a2 + 5);
            *(_DWORD *)(v32 + 30) = v34;
            if ( a1 || (v35 = rndis_ipa_init(v32)) == 0 )
            {
              *(_DWORD *)(v32 + 56) = 0;
              ++*(_DWORD *)(ipa3_usb_ctx + 432);
              if ( ipa3_get_ipc_logbuf() )
              {
                v36 = ipa3_get_ipc_logbuf();
                v37 = "unsupported";
                if ( a1 == 1 )
                  v37 = "ecm_ipa";
                if ( a1 )
                  v38 = v37;
                else
                  v38 = "rndis_ipa";
                ipc_log_string(v36, "ipa_usb %s:%d initialized %s\n", "ipa_usb_init_teth_prot", 872, v38);
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v39 = ipa3_get_ipc_logbuf_low();
                v40 = "unsupported";
                if ( a1 == 1 )
                  v40 = "ecm_ipa";
                if ( a1 )
                  v41 = v40;
                else
                  v41 = "rndis_ipa";
                ipc_log_string(v39, "ipa_usb %s:%d initialized %s\n", "ipa_usb_init_teth_prot", 872, v41);
              }
LABEL_150:
              if ( (ipa3_usb_set_state(1, 0, (unsigned int)v11) & 1) == 0 )
              {
                printk(&unk_3B9A33, "ipa_usb_init_teth_prot");
                if ( ipa3_get_ipc_logbuf() )
                {
                  v83 = ipa3_get_ipc_logbuf();
                  ipc_log_string(
                    v83,
                    "ipa_usb %s:%d failed to change state to initialized\n",
                    "ipa_usb_init_teth_prot",
                    943);
                }
                if ( ipa3_get_ipc_logbuf_low() )
                {
                  v84 = ipa3_get_ipc_logbuf_low();
                  ipc_log_string(
                    v84,
                    "ipa_usb %s:%d failed to change state to initialized\n",
                    "ipa_usb_init_teth_prot",
                    943);
                }
              }
              if ( ipa3_get_ipc_logbuf_low() )
              {
                v81 = ipa3_get_ipc_logbuf_low();
                ipc_log_string(v81, "ipa_usb %s:%d exit\n", "ipa_usb_init_teth_prot", 945);
              }
              inited = 0;
              goto LABEL_154;
            }
            inited = v35;
            printk(&unk_3F0AF7, "ipa_usb_init_teth_prot");
            if ( ipa3_get_ipc_logbuf() )
            {
              v85 = ipa3_get_ipc_logbuf();
              ipc_log_string(v85, "ipa_usb %s:%d Failed to initialize %s\n", "ipa_usb_init_teth_prot", 844, "rndis_ipa");
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v86 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(v86, "ipa_usb %s:%d Failed to initialize %s\n", "ipa_usb_init_teth_prot", 844, "rndis_ipa");
            }
LABEL_75:
            v45 = ipa3_usb_ctx;
            if ( *(_DWORD *)(ipa3_usb_ctx + 432) )
              goto LABEL_154;
LABEL_80:
            v48 = v45 + (v11 << 8);
            if ( !(unsigned int)((__int64 (__fastcall *)(_QWORD))ipa_pm_deregister)(*(unsigned int *)(v48 + 632)) )
            {
              *(_QWORD *)(v48 + 608) = 0;
              *(_QWORD *)(v48 + 616) = 0;
              *(_QWORD *)(v48 + 592) = 0;
              *(_QWORD *)(v48 + 600) = 0;
            }
            goto LABEL_154;
          }
          if ( ipa3_get_ipc_logbuf() )
          {
            v49 = ipa3_get_ipc_logbuf();
            v50 = "unsupported";
            if ( a1 == 1 )
              v50 = "ecm_ipa";
            if ( a1 )
              v51 = v50;
            else
              v51 = "rndis_ipa";
            ipc_log_string(v49, "ipa_usb %s:%d %s already initialized\n", "ipa_usb_init_teth_prot", 822, v51);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v52 = ipa3_get_ipc_logbuf_low();
            v53 = "unsupported";
            if ( a1 == 1 )
              v53 = "ecm_ipa";
            if ( a1 )
              v54 = v53;
            else
              v54 = "rndis_ipa";
            v55 = 822;
            goto LABEL_108;
          }
LABEL_114:
          inited = -1;
          goto LABEL_154;
        }
        v44 = v20 + 72LL * a1;
        if ( *(_DWORD *)(v44 + 56) == 2 )
        {
          *(_QWORD *)(v44 + 64) = a4;
          inited = ipa3_usb_init_teth_bridge(a1);
          if ( !inited )
          {
            v62 = ipa3_usb_ctx;
            *(_DWORD *)(ipa3_usb_ctx + 72LL * a1 + 56) = 0;
            ++*(_DWORD *)(v62 + 432);
            if ( ipa3_get_ipc_logbuf() )
            {
              v63 = ipa3_get_ipc_logbuf();
              v64 = "unsupported";
              if ( a1 == 3 )
                v64 = "mbim";
              if ( a1 == 2 )
                v65 = "rmnet";
              else
                v65 = v64;
              ipc_log_string(
                v63,
                "ipa_usb %s:%d initialized %s %s\n",
                "ipa_usb_init_teth_prot",
                894,
                "teth_bridge",
                v65);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v66 = ipa3_get_ipc_logbuf_low();
              if ( a1 == 2 )
                v67 = "rmnet";
              else
                v67 = "mbim";
              ipc_log_string(
                v66,
                "ipa_usb %s:%d initialized %s %s\n",
                "ipa_usb_init_teth_prot",
                894,
                "teth_bridge",
                v67);
            }
            ipa3_register_client_callback(
              (__int64)ipa_usb_set_lock_unlock,
              (__int64)ipa3_usb_get_teth_port_state,
              0x12u);
            goto LABEL_150;
          }
          goto LABEL_75;
        }
        if ( ipa3_get_ipc_logbuf() )
        {
          v56 = ipa3_get_ipc_logbuf();
          ipc_log_string(v56, "ipa_usb %s:%d %s already initialized\n", "ipa_usb_init_teth_prot", 879, "teth_bridge");
        }
        if ( !ipa3_get_ipc_logbuf_low() )
          goto LABEL_114;
        v52 = ipa3_get_ipc_logbuf_low();
        v54 = "teth_bridge";
        v55 = 879;
LABEL_108:
        ipc_log_string(v52, "ipa_usb %s:%d %s already initialized\n", "ipa_usb_init_teth_prot", v55, v54);
        inited = -1;
        goto LABEL_154;
      }
      if ( a1 != 4 )
      {
        v46 = v20 + 72LL * a1;
        if ( *(_DWORD *)(v46 + 56) == 2 )
        {
          *(_QWORD *)(v46 + 64) = a4;
          v47 = ipa3_usb_init_teth_bridge(5);
          v45 = ipa3_usb_ctx;
          if ( !v47 )
          {
            *(_DWORD *)(ipa3_usb_ctx + 72LL * a1 + 56) = 0;
            if ( ipa3_get_ipc_logbuf() )
            {
              v75 = ipa3_get_ipc_logbuf();
              v76 = (const char *)ipa3_usb_teth_prot_to_string(5);
              ipc_log_string(v75, "ipa_usb %s:%d initialized %s %s\n", "ipa_usb_init_teth_prot", 922, v76, "rmnet_cv2x");
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v77 = ipa3_get_ipc_logbuf_low();
              v78 = (const char *)ipa3_usb_teth_prot_to_string(5);
              ipc_log_string(v77, "ipa_usb %s:%d initialized %s %s\n", "ipa_usb_init_teth_prot", 922, v78, "rmnet_cv2x");
            }
            goto LABEL_150;
          }
          inited = v47;
          goto LABEL_80;
        }
        if ( ipa3_get_ipc_logbuf() )
        {
          v59 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v59,
            "ipa_usb %s:%d %s already initialized\n",
            "ipa_usb_init_teth_prot",
            908,
            "teth_bridge_cv2x");
        }
        if ( !ipa3_get_ipc_logbuf_low() )
          goto LABEL_114;
        v52 = ipa3_get_ipc_logbuf_low();
        v54 = "teth_bridge_cv2x";
        v55 = 908;
        goto LABEL_108;
      }
      if ( *(_DWORD *)(v20 + 344) == 2 )
      {
        *(_QWORD *)(v20 + 352) = a4;
        *(_DWORD *)(v20 + 72LL * a1 + 56) = 0;
        if ( ipa3_get_ipc_logbuf() )
        {
          v42 = ipa3_get_ipc_logbuf();
          ipc_log_string(v42, "ipa_usb %s:%d initialized DPL\n", "ipa_usb_init_teth_prot", 934);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v43 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v43, "ipa_usb %s:%d initialized DPL\n", "ipa_usb_init_teth_prot", 934);
        }
        goto LABEL_150;
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v57 = ipa3_get_ipc_logbuf();
        ipc_log_string(v57, "ipa_usb %s:%d DPL already initialized\n", "ipa_usb_init_teth_prot", 927);
      }
      if ( !ipa3_get_ipc_logbuf_low() )
        goto LABEL_114;
      v58 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v58, "ipa_usb %s:%d DPL already initialized\n", "ipa_usb_init_teth_prot", 927);
LABEL_113:
      inited = -1;
      goto LABEL_154;
    }
    inited = v19;
    printk(&unk_3C885C, "ipa3_usb_register_pm");
    if ( ipa3_get_ipc_logbuf() )
    {
      v70 = ipa3_get_ipc_logbuf();
      ipc_log_string(v70, "ipa_usb %s:%d fail to associate cons with PM %d\n", "ipa3_usb_register_pm", 672, inited);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v72 = ipa3_get_ipc_logbuf_low();
      v71 = ipc_log_string(
              v72,
              "ipa_usb %s:%d fail to associate cons with PM %d\n",
              "ipa3_usb_register_pm",
              672,
              inited);
    }
    ((void (__fastcall *)(_QWORD, long double))ipa_pm_deregister)(*(unsigned int *)(v13 + 40), v71);
  }
  *(_QWORD *)(v13 + 16) = 0;
  *(_QWORD *)(v13 + 24) = 0;
  *(_QWORD *)v13 = 0;
  *(_QWORD *)(v13 + 8) = 0;
  printk(&unk_3CE40A, "ipa_usb_init_teth_prot");
  if ( ipa3_get_ipc_logbuf() )
  {
    v73 = ipa3_get_ipc_logbuf();
    ipc_log_string(v73, "ipa_usb %s:%d Failed registering IPA PM\n", "ipa_usb_init_teth_prot", 795);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v74 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v74, "ipa_usb %s:%d Failed registering IPA PM\n", "ipa_usb_init_teth_prot", 795);
  }
LABEL_154:
  mutex_unlock(ipa3_usb_ctx + 544);
  return inited;
}
