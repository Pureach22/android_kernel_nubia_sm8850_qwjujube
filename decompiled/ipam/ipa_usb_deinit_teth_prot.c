__int64 __fastcall ipa_usb_deinit_teth_prot(unsigned int a1)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v3; // x19
  __int64 v4; // x8
  __int64 v5; // x22
  __int64 v6; // x0
  const char *v7; // x8
  const char *v8; // x4
  __int64 v9; // x0
  const char *v10; // x8
  const char *v11; // x4
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  const char *v15; // x8
  const char *v16; // x5
  __int64 v17; // x0
  const char *v18; // x5
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 ipc_logbuf; // x0
  __int64 v22; // x0
  unsigned int v23; // w19
  __int64 v24; // x20
  __int64 v25; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  const char *v31; // x19
  __int64 v32; // x0
  __int64 v33; // x0
  const char *v34; // x19
  __int64 v35; // x0
  const char *v36; // x8
  const char *v37; // x5
  __int64 v38; // x0
  const char *v39; // x19
  __int64 v40; // x0
  __int64 v41; // x0
  const char *v42; // x19
  __int64 v43; // x0
  __int64 v44; // x0

  mutex_lock(ipa3_usb_ctx + 544);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_usb %s:%d entry\n", "ipa_usb_deinit_teth_prot", 2205);
  }
  if ( a1 >= 6 )
  {
    printk(&unk_3AB53C, "ipa_usb_deinit_teth_prot");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_usb %s:%d bad parameters\n", "ipa_usb_deinit_teth_prot", 2207);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v22 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v22, "ipa_usb %s:%d bad parameters\n", "ipa_usb_deinit_teth_prot", 2207);
      v23 = -22;
      goto LABEL_63;
    }
    goto LABEL_97;
  }
  if ( a1 == 4 )
    v3 = 1;
  else
    v3 = 2 * (unsigned int)(a1 == 5);
  if ( (ipa3_usb_check_legal_op(5, v3) & 1) != 0 )
  {
    v4 = ipa3_usb_ctx;
    v5 = ipa3_usb_ctx + 72LL * a1;
    if ( (int)a1 > 3 )
    {
      if ( a1 == 4 )
      {
        if ( !*(_DWORD *)(v5 + 56) )
        {
          *(_QWORD *)(v5 + 64) = 0;
          *(_DWORD *)(v5 + 56) = 2;
          if ( ipa3_get_ipc_logbuf() )
          {
            v12 = ipa3_get_ipc_logbuf();
            ipc_log_string(v12, "ipa_usb %s:%d deinitialized %s\n", "ipa_usb_deinit_teth_prot", 2292, "dpl");
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v13 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v13, "ipa_usb %s:%d deinitialized %s\n", "ipa_usb_deinit_teth_prot", 2292, "dpl");
          }
          goto LABEL_56;
        }
        v39 = ipa3_usb_teth_prot_to_string(4u);
        printk(&unk_3B9A6A, "ipa_usb_deinit_teth_prot");
        if ( ipa3_get_ipc_logbuf() )
        {
          v40 = ipa3_get_ipc_logbuf();
          ipc_log_string(v40, "ipa_usb %s:%d %s is not initialized\n", "ipa_usb_deinit_teth_prot", 2285, v39);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v41 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v41, "ipa_usb %s:%d %s is not initialized\n", "ipa_usb_deinit_teth_prot", 2285, v39);
          goto LABEL_92;
        }
      }
      else
      {
        if ( !*(_DWORD *)(v5 + 56) )
        {
          *(_QWORD *)(v5 + 64) = 0;
          *(_DWORD *)(v4 + 72LL * a1 + 56) = 2;
          if ( ipa3_get_ipc_logbuf() )
          {
            v19 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v19,
              "ipa_usb %s:%d deinitialized %s (%s)\n",
              "ipa_usb_deinit_teth_prot",
              2279,
              "teth_bridge_cv2x",
              "rmnet_cv2x");
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v20 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v20,
              "ipa_usb %s:%d deinitialized %s (%s)\n",
              "ipa_usb_deinit_teth_prot",
              2279,
              "teth_bridge_cv2x",
              "rmnet_cv2x");
          }
          goto LABEL_56;
        }
        v42 = ipa3_usb_teth_prot_to_string(5u);
        printk(&unk_3FF964, "ipa_usb_deinit_teth_prot");
        if ( ipa3_get_ipc_logbuf() )
        {
          v43 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v43,
            "ipa_usb %s:%d %s (%s) is not initialized\n",
            "ipa_usb_deinit_teth_prot",
            2268,
            v42,
            "rmnet_cv2x");
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v44 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v44,
            "ipa_usb %s:%d %s (%s) is not initialized\n",
            "ipa_usb_deinit_teth_prot",
            2268,
            v42,
            "rmnet_cv2x");
        }
      }
    }
    else if ( a1 >= 2 )
    {
      if ( !*(_DWORD *)(v5 + 56) )
      {
        *(_QWORD *)(v5 + 64) = 0;
        *(_DWORD *)(v5 + 56) = 2;
        --*(_DWORD *)(v4 + 432);
        if ( ipa3_get_ipc_logbuf() )
        {
          v14 = ipa3_get_ipc_logbuf();
          v15 = "unsupported";
          if ( a1 == 3 )
            v15 = "mbim";
          if ( a1 == 2 )
            v16 = "rmnet";
          else
            v16 = v15;
          ipc_log_string(
            v14,
            "ipa_usb %s:%d deinitialized %s (%s)\n",
            "ipa_usb_deinit_teth_prot",
            2261,
            "teth_bridge",
            v16);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v17 = ipa3_get_ipc_logbuf_low();
          if ( a1 == 2 )
            v18 = "rmnet";
          else
            v18 = "mbim";
          ipc_log_string(
            v17,
            "ipa_usb %s:%d deinitialized %s (%s)\n",
            "ipa_usb_deinit_teth_prot",
            2261,
            "teth_bridge",
            v18);
        }
LABEL_55:
        if ( *(_DWORD *)(ipa3_usb_ctx + 432) )
        {
LABEL_60:
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v25 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v25, "ipa_usb %s:%d exit\n", "ipa_usb_deinit_teth_prot", 2310);
          }
          v23 = 0;
          goto LABEL_63;
        }
LABEL_56:
        if ( (ipa3_usb_set_state(0, 0, v3) & 1) == 0 )
        {
          printk(&unk_3E8086, "ipa_usb_deinit_teth_prot");
          if ( ipa3_get_ipc_logbuf() )
          {
            v29 = ipa3_get_ipc_logbuf();
            ipc_log_string(v29, "ipa_usb %s:%d failed to change state to invalid\n", "ipa_usb_deinit_teth_prot", 2305);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v30 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v30, "ipa_usb %s:%d failed to change state to invalid\n", "ipa_usb_deinit_teth_prot", 2305);
          }
        }
        v24 = ipa3_usb_ctx + (v3 << 8);
        if ( !(unsigned int)((__int64 (__fastcall *)(_QWORD))ipa_pm_deregister)(*(unsigned int *)(v24 + 632)) )
        {
          *(_QWORD *)(v24 + 608) = 0;
          *(_QWORD *)(v24 + 616) = 0;
          *(_QWORD *)(v24 + 592) = 0;
          *(_QWORD *)(v24 + 600) = 0;
        }
        *(_QWORD *)(ipa3_usb_ctx + (v3 << 8) + 640) = 0;
        goto LABEL_60;
      }
      v34 = ipa3_usb_teth_prot_to_string(a1);
      printk(&unk_3FF964, "ipa_usb_deinit_teth_prot");
      if ( ipa3_get_ipc_logbuf() )
      {
        v35 = ipa3_get_ipc_logbuf();
        if ( a1 == 3 )
          v36 = "mbim";
        else
          v36 = "unsupported";
        if ( a1 == 2 )
          v37 = "rmnet";
        else
          v37 = v36;
        ipc_log_string(v35, "ipa_usb %s:%d %s (%s) is not initialized\n", "ipa_usb_deinit_teth_prot", 2251, v34, v37);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v38 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v38,
          "ipa_usb %s:%d %s (%s) is not initialized\n",
          "ipa_usb_deinit_teth_prot",
          2251,
          v34,
          off_1E5298[a1 - 2]);
      }
    }
    else
    {
      if ( !*(_DWORD *)(v5 + 56) )
      {
        if ( !a1 )
        {
          rndis_ipa_cleanup(*(_QWORD *)(v5 + 40));
          v4 = ipa3_usb_ctx;
        }
        *(_QWORD *)(v5 + 64) = 0;
        *(_DWORD *)(v5 + 56) = 2;
        --*(_DWORD *)(v4 + 432);
        if ( ipa3_get_ipc_logbuf() )
        {
          v6 = ipa3_get_ipc_logbuf();
          v7 = "unsupported";
          if ( a1 == 1 )
            v7 = "ecm_ipa";
          if ( a1 )
            v8 = v7;
          else
            v8 = "rndis_ipa";
          ipc_log_string(v6, "ipa_usb %s:%d deinitialized %s\n", "ipa_usb_deinit_teth_prot", 2243, v8);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v9 = ipa3_get_ipc_logbuf_low();
          v10 = "unsupported";
          if ( a1 == 1 )
            v10 = "ecm_ipa";
          if ( a1 )
            v11 = v10;
          else
            v11 = "rndis_ipa";
          ipc_log_string(v9, "ipa_usb %s:%d deinitialized %s\n", "ipa_usb_deinit_teth_prot", 2243, v11);
        }
        goto LABEL_55;
      }
      v31 = ipa3_usb_teth_prot_to_string(a1);
      printk(&unk_3B9A6A, "ipa_usb_deinit_teth_prot");
      if ( ipa3_get_ipc_logbuf() )
      {
        v32 = ipa3_get_ipc_logbuf();
        ipc_log_string(v32, "ipa_usb %s:%d %s is not initialized\n", "ipa_usb_deinit_teth_prot", 2229, v31);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v33 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v33, "ipa_usb %s:%d %s is not initialized\n", "ipa_usb_deinit_teth_prot", 2229, v31);
LABEL_92:
        v23 = -22;
        goto LABEL_63;
      }
    }
LABEL_97:
    v23 = -22;
    goto LABEL_63;
  }
  printk(&unk_3A5362, "ipa_usb_deinit_teth_prot");
  if ( ipa3_get_ipc_logbuf() )
  {
    v27 = ipa3_get_ipc_logbuf();
    ipc_log_string(v27, "ipa_usb %s:%d Illegal operation\n", "ipa_usb_deinit_teth_prot", 2215);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v28 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v28, "ipa_usb %s:%d Illegal operation\n", "ipa_usb_deinit_teth_prot", 2215);
  }
  v23 = -1;
LABEL_63:
  mutex_unlock(ipa3_usb_ctx + 544);
  return v23;
}
