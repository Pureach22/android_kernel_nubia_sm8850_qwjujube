__int64 __fastcall ipa3_usb_connect_teth_prot(unsigned int a1)
{
  __int64 v3; // x19
  __int64 ipc_logbuf; // x0
  const char *v5; // x4
  __int64 v6; // x23
  long double v7; // q0
  __int64 ipc_logbuf_low; // x0
  const char *v9; // x4
  __int64 v10; // x8
  __int64 v11; // x19
  _DWORD *v12; // x24
  unsigned int v13; // w25
  __int64 v14; // x0
  const char *v15; // x4
  __int64 v16; // x0
  __int64 result; // x0
  __int64 v18; // x0
  int v19; // w10
  int v20; // w8
  int v21; // w9
  unsigned int v22; // w20
  unsigned int v23; // w0
  __int64 v24; // x0
  const char *v25; // x4
  const char *v26; // x5
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x4
  __int64 v32; // x0
  __int64 v33; // x1
  unsigned int v34; // w0
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x9
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  const char *v43; // x4
  __int64 v44; // x0
  const char *v45; // x4
  const char *v46; // x5
  __int64 v47; // x0
  __int64 v48; // x0
  unsigned int v49; // w20
  __int64 v50; // x0
  const char *v51; // x4
  __int64 v52; // x0
  const char *v53; // x1
  const char *v54; // x2
  __int64 v55; // x3
  const char *v56; // x4
  __int64 v57; // x0
  _DWORD v58[2]; // [xsp+8h] [xbp-18h] BYREF
  int v59; // [xsp+10h] [xbp-10h]
  int v60; // [xsp+14h] [xbp-Ch]
  __int64 v61; // [xsp+18h] [xbp-8h]

  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 >= 7 )
    __break(0x5512u);
  v3 = ipa3_usb_ctx;
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    if ( a1 == 6 )
      v5 = "unsupported";
    else
      v5 = off_1E5248[a1];
    ipc_log_string(ipc_logbuf, "ipa_usb %s:%d connecting protocol = %s\n", "ipa3_usb_connect_teth_prot", 1415, v5);
  }
  v6 = v3 + 72LL * a1;
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    if ( a1 == 6 )
      v9 = "unsupported";
    else
      v9 = off_1E5248[a1];
    v7 = ipc_log_string(
           ipc_logbuf_low,
           "ipa_usb %s:%d connecting protocol = %s\n",
           "ipa3_usb_connect_teth_prot",
           1415,
           v9);
  }
  v10 = ipa3_usb_ctx;
  if ( a1 == 4 )
    v11 = 1;
  else
    v11 = 2 * (unsigned int)(a1 == 5);
  v12 = (_DWORD *)(ipa3_usb_ctx + (v11 << 8) + 592);
  if ( (int)a1 <= 1 )
  {
    if ( a1 )
    {
      if ( *(_DWORD *)(v6 + 56) == 1 )
      {
        if ( ipa3_get_ipc_logbuf() )
        {
          v16 = ipa3_get_ipc_logbuf();
          ipc_log_string(v16, "ipa_usb %s:%d %s is already connected\n", "ipa3_usb_connect_teth_prot", 1453, "ecm_ipa");
        }
        result = ipa3_get_ipc_logbuf_low();
        if ( !result )
          goto LABEL_73;
        v18 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v18, "ipa_usb %s:%d %s is already connected\n", "ipa3_usb_connect_teth_prot", 1453, "ecm_ipa");
      }
      else
      {
        *(_QWORD *)(ipa3_usb_ctx + (v11 << 8) + 648) = *(_QWORD *)(v6 + 64);
        *(_DWORD *)(v6 + 56) = 1;
        if ( ipa3_get_ipc_logbuf() )
        {
          v37 = ipa3_get_ipc_logbuf();
          ipc_log_string(v37, "ipa_usb %s:%d %s is connected\n", "ipa3_usb_connect_teth_prot", 1470, "ecm_ipa");
        }
        result = ipa3_get_ipc_logbuf_low();
        if ( !result )
          goto LABEL_73;
        v38 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v38, "ipa_usb %s:%d %s is connected\n", "ipa3_usb_connect_teth_prot", 1470, "ecm_ipa");
      }
    }
    else if ( *(_DWORD *)(v6 + 56) == 1 )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v27 = ipa3_get_ipc_logbuf();
        ipc_log_string(v27, "ipa_usb %s:%d %s is already connected\n", "ipa3_usb_connect_teth_prot", 1426, "rndis_ipa");
      }
      result = ipa3_get_ipc_logbuf_low();
      if ( !result )
        goto LABEL_73;
      v28 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v28, "ipa_usb %s:%d %s is already connected\n", "ipa3_usb_connect_teth_prot", 1426, "rndis_ipa");
    }
    else
    {
      v31 = *(unsigned int *)(ipa3_usb_ctx + (v11 << 8) + 840);
      v32 = *(unsigned int *)(ipa3_usb_ctx + (v11 << 8) + 824);
      v33 = *(unsigned int *)(ipa3_usb_ctx + (v11 << 8) + 828);
      *(_QWORD *)(ipa3_usb_ctx + (v11 << 8) + 648) = *(_QWORD *)(v6 + 64);
      v34 = rndis_ipa_pipe_connect_notify(
              v32,
              v33,
              (unsigned int)v12[60],
              (unsigned int)v12[61],
              v31,
              *(_QWORD *)(v6 + 40),
              v7);
      if ( v34 )
      {
        v49 = v34;
        printk(&unk_3D13FD, "ipa3_usb_connect_teth_prot");
        if ( ipa3_get_ipc_logbuf() )
        {
          v57 = ipa3_get_ipc_logbuf();
          ipc_log_string(v57, "ipa_usb %s:%d failed to connect %s\n", "ipa3_usb_connect_teth_prot", 1440, "rndis_ipa");
        }
        if ( !ipa3_get_ipc_logbuf_low() )
          goto LABEL_100;
        v52 = ipa3_get_ipc_logbuf_low();
        v53 = "ipa_usb %s:%d failed to connect %s\n";
        v54 = "ipa3_usb_connect_teth_prot";
        v56 = "rndis_ipa";
        v55 = 1440;
        goto LABEL_99;
      }
      *(_DWORD *)(v6 + 56) = 1;
      if ( ipa3_get_ipc_logbuf() )
      {
        v35 = ipa3_get_ipc_logbuf();
        ipc_log_string(v35, "ipa_usb %s:%d %s is connected\n", "ipa3_usb_connect_teth_prot", 1447, "rndis_ipa");
      }
      result = ipa3_get_ipc_logbuf_low();
      if ( !result )
        goto LABEL_73;
      v36 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v36, "ipa_usb %s:%d %s is connected\n", "ipa3_usb_connect_teth_prot", 1447, "rndis_ipa");
    }
LABEL_72:
    result = 0;
    goto LABEL_73;
  }
  v13 = a1 - 2;
  if ( a1 - 2 < 2 )
    goto LABEL_19;
  if ( a1 == 4 )
  {
    if ( *(_DWORD *)(ipa3_usb_ctx + 344) == 1 )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v29 = ipa3_get_ipc_logbuf();
        ipc_log_string(v29, "ipa_usb %s:%d %s is already connected\n", "ipa3_usb_connect_teth_prot", 1517, "dpl");
      }
      result = ipa3_get_ipc_logbuf_low();
      if ( !result )
        goto LABEL_73;
      v30 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v30, "ipa_usb %s:%d %s is already connected\n", "ipa3_usb_connect_teth_prot", 1517, "dpl");
    }
    else
    {
      v39 = *(_QWORD *)(ipa3_usb_ctx + 72LL * a1 + 64);
      *(_DWORD *)(ipa3_usb_ctx + 344) = 1;
      *(_QWORD *)(v10 + (v11 << 8) + 648) = v39;
      ipa3_usb_notify_do(1u, 0);
      if ( ipa3_get_ipc_logbuf() )
      {
        v40 = ipa3_get_ipc_logbuf();
        ipc_log_string(v40, "ipa_usb %s:%d %s is connected\n", "ipa3_usb_connect_teth_prot", 1527, "dpl");
      }
      result = ipa3_get_ipc_logbuf_low();
      if ( !result )
        goto LABEL_73;
      v41 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v41, "ipa_usb %s:%d %s is connected\n", "ipa3_usb_connect_teth_prot", 1527, "dpl");
    }
    goto LABEL_72;
  }
  if ( a1 != 5 )
  {
    printk(&unk_3BF7DA, "ipa3_usb_connect_teth_prot");
    if ( ipa3_get_ipc_logbuf() )
    {
      v47 = ipa3_get_ipc_logbuf();
      ipc_log_string(v47, "ipa_usb %s:%d Invalid tethering protocol\n", "ipa3_usb_connect_teth_prot", 1530);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v48 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v48, "ipa_usb %s:%d Invalid tethering protocol\n", "ipa3_usb_connect_teth_prot", 1530);
    }
    result = 4294967282LL;
    goto LABEL_73;
  }
LABEL_19:
  if ( *(_DWORD *)(v6 + 56) != 1 )
  {
    result = ipa3_usb_init_teth_bridge(a1);
    if ( (_DWORD)result )
      goto LABEL_73;
    *(_QWORD *)(ipa3_usb_ctx + (v11 << 8) + 648) = *(_QWORD *)(v6 + 64);
    v58[0] = v12[59];
    v19 = v12[58];
    if ( a1 == 5 )
      v20 = 20;
    else
      v20 = 18;
    if ( a1 == 5 )
      v21 = 2;
    else
      v21 = 1;
    v22 = a1 - 2;
    v60 = v20;
    if ( !v22 )
      v21 = 0;
    v58[1] = v19;
    v59 = v21;
    v23 = ipa3_teth_bridge_connect((__int64)v58);
    if ( !v23 )
    {
      *(_DWORD *)(ipa3_usb_ctx + 72LL * a1 + 56) = 1;
      ipa3_usb_notify_do(v11, 0);
      if ( ipa3_get_ipc_logbuf() )
      {
        v24 = ipa3_get_ipc_logbuf();
        if ( v22 > 3 )
        {
          v26 = "rmnet_cv2x";
          v25 = "unsupported";
        }
        else
        {
          v25 = off_1E5278[v22];
          v26 = off_1E5298[v22];
        }
        ipc_log_string(v24, "ipa_usb %s:%d %s (%s) is connected\n", "ipa3_usb_connect_teth_prot", 1511, v25, v26);
      }
      result = ipa3_get_ipc_logbuf_low();
      if ( result )
      {
        v44 = ipa3_get_ipc_logbuf_low();
        if ( v22 > 3 )
        {
          v46 = "rmnet_cv2x";
          v45 = "unsupported";
        }
        else
        {
          v45 = off_1E5278[v22];
          v46 = off_1E5298[v22];
        }
        ipc_log_string(v44, "ipa_usb %s:%d %s (%s) is connected\n", "ipa3_usb_connect_teth_prot", 1511, v45, v46);
        goto LABEL_72;
      }
      goto LABEL_73;
    }
    v49 = v23;
    printk(&unk_3A54BE, "ipa3_usb_connect_teth_bridge");
    if ( ipa3_get_ipc_logbuf() )
    {
      v50 = ipa3_get_ipc_logbuf();
      if ( v59 )
        v51 = "mbim";
      else
        v51 = "rmnet";
      ipc_log_string(
        v50,
        "ipa_usb %s:%d failed to connect teth_bridge (%s)\n",
        "ipa3_usb_connect_teth_bridge",
        1388,
        v51);
    }
    if ( !ipa3_get_ipc_logbuf_low() )
    {
LABEL_100:
      result = v49;
      *(_QWORD *)(ipa3_usb_ctx + (v11 << 8) + 648) = 0;
      goto LABEL_73;
    }
    v52 = ipa3_get_ipc_logbuf_low();
    v53 = "ipa_usb %s:%d failed to connect teth_bridge (%s)\n";
    v54 = "ipa3_usb_connect_teth_bridge";
    v55 = 1388;
    if ( v59 )
      v56 = "mbim";
    else
      v56 = "rmnet";
LABEL_99:
    ipc_log_string(v52, v53, v54, v55, v56);
    goto LABEL_100;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v14 = ipa3_get_ipc_logbuf();
    if ( v13 > 3 )
      v15 = "unsupported";
    else
      v15 = off_1E5278[v13];
    ipc_log_string(v14, "ipa_usb %s:%d %s is already connected\n", "ipa3_usb_connect_teth_prot", 1478, v15);
  }
  result = ipa3_get_ipc_logbuf_low();
  if ( result )
  {
    v42 = ipa3_get_ipc_logbuf_low();
    if ( v13 > 3 )
      v43 = "unsupported";
    else
      v43 = off_1E5278[v13];
    ipc_log_string(v42, "ipa_usb %s:%d %s is already connected\n", "ipa3_usb_connect_teth_prot", 1478, v43);
    goto LABEL_72;
  }
LABEL_73:
  _ReadStatusReg(SP_EL0);
  return result;
}
