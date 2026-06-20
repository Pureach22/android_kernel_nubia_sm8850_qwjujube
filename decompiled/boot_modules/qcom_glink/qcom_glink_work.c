__int64 __fastcall qcom_glink_work(_QWORD *a1)
{
  __int64 v2; // x9
  _QWORD *v3; // x20
  _QWORD *v4; // x27
  const char *v5; // x25
  _QWORD *v6; // x26
  __int64 v7; // x0
  _QWORD *v8; // x8
  __int64 v9; // x10
  __int64 v10; // x3
  __int64 v11; // x4
  __int64 v12; // x5
  unsigned int v13; // w1
  __int64 v14; // x28
  unsigned __int64 v15; // x23
  __int64 v16; // x22
  __int64 v17; // x0
  __int64 v18; // x24
  unsigned __int64 v19; // x0
  int v20; // w23
  __int64 v21; // x22
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x23
  __int64 v26; // x4
  __int64 v27; // x23
  __int64 v28; // x22
  __int64 v29; // x8
  const char *v30; // x23
  size_t v31; // x0
  unsigned __int64 v32; // x2
  unsigned __int64 v33; // x0
  __int64 v34; // x0
  int v35; // w3
  __int64 v36; // x0
  __int64 v37; // x23
  __int64 v38; // x8
  _QWORD *v39; // x21
  const char *v40; // x26
  __int64 v41; // x25
  __int64 v42; // x0
  __int64 v43; // x22
  __int64 v45; // x25
  __int64 next; // x0
  int v47; // w3
  __int64 v48; // x8
  int v49; // w3
  __int64 v50; // x8
  __int64 v51; // x0
  const char *v52; // x1
  const char *v53; // x2
  __int64 v54; // x22
  int v55; // w0
  int v56; // w4
  __int64 v57; // x8
  _QWORD *v58; // x22
  unsigned __int64 v59; // x2
  int v60; // w28
  _QWORD *v61; // x21
  const char *v62; // x26
  unsigned __int64 v63; // x0
  __int64 v64; // x8
  __int64 v65; // x1
  __int64 v66; // x25
  __int64 v67; // x0
  __int64 next_available_child; // x0
  __int64 v69; // x23
  __int64 v70; // x8
  __int64 v71; // x8
  __int64 v72; // x8
  __int64 v73; // x8
  __int64 v74; // x1
  int v80; // w8
  unsigned int v83; // w8
  int v85; // w8
  int v88; // w8
  __int64 result; // x0
  __int64 v90; // x0
  __int64 v91; // [xsp+18h] [xbp-38h] BYREF
  char *s1[4]; // [xsp+20h] [xbp-30h] BYREF
  __int64 v93; // [xsp+40h] [xbp-10h]
  __int64 v94; // [xsp+48h] [xbp-8h]

  v94 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = raw_spin_lock_irqsave(a1 + 4);
  v4 = a1 + 5;
  v3 = (_QWORD *)a1[5];
  if ( v3 == a1 + 5 )
  {
LABEL_133:
    result = raw_spin_unlock_irqrestore(a1 + 4, v2);
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v5 = "[%s]: vers:%d features:%d\n";
  v6 = a1 - 12;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v8 = (_QWORD *)v3[1];
    if ( (_QWORD *)*v8 == v3 && (v9 = *v3, *(_QWORD **)(*v3 + 8LL) == v3) )
    {
      *(_QWORD *)(v9 + 8) = v8;
      *v8 = v9;
    }
    else
    {
      _list_del_entry_valid_or_report(v3);
    }
    *v3 = 0xDEAD000000000100LL;
    v3[1] = 0xDEAD000000000122LL;
    raw_spin_unlock_irqrestore(a1 + 4, v2);
    v13 = *((unsigned __int16 *)v3 + 8);
    v14 = *((unsigned __int16 *)v3 + 9);
    v15 = *((unsigned int *)v3 + 5);
    if ( v13 <= 2 )
      break;
    switch ( v13 )
    {
      case 3u:
        v93 = 0;
        memset(s1, 0, sizeof(s1));
        v27 = raw_spin_lock_irqsave((char *)a1 + 60);
        v28 = idr_find(a1 + 11, v14);
        raw_spin_unlock_irqrestore((char *)a1 + 60, v27);
        if ( v28 )
        {
          v29 = *(_QWORD *)(v28 + 112);
          if ( v29 )
            ipc_log_string(
              *(_QWORD *)(v29 + 256),
              "%s[%d:%d] %s: \n",
              *(const char **)(v28 + 128),
              *(_DWORD *)(v28 + 136),
              *(_DWORD *)(v28 + 140),
              "qcom_glink_rx_close");
          if ( *(_QWORD *)(v28 + 104) )
          {
            v30 = *(const char **)(v28 + 128);
            v31 = strnlen(v30, 0x20u);
            if ( v31 == -1 )
              goto LABEL_134;
            if ( v31 == 32 )
              v32 = 32;
            else
              v32 = v31 + 1;
            if ( v32 >= 0x29 )
              goto LABEL_135;
            v33 = sized_strscpy(s1, v30);
            if ( v33 <= 0x1F )
              memset((char *)s1 + v33 + 1, 0, 31 - v33);
            v34 = *v6;
            v93 = -1;
            rpmsg_unregister_device(v34, s1);
          }
          *(_QWORD *)(v28 + 104) = 0;
          v35 = *(_DWORD *)(v28 + 140);
          v36 = a1[20];
          v91 = 11;
          WORD1(v91) = v35;
          ipc_log_string(v36, "[%s]: rcid:%d\n", "qcom_glink_send_close_ack", v35);
          qcom_glink_tx(v6, &v91, 8, 0, 0, 1);
          v37 = raw_spin_lock_irqsave((char *)a1 + 60);
          idr_remove(a1 + 11, *(unsigned int *)(v28 + 140));
          *(_DWORD *)(v28 + 140) = 0;
          raw_spin_unlock_irqrestore((char *)a1 + 60, v37);
          _X0 = (unsigned int *)(v28 + 120);
          __asm { PRFM            #0x11, [X0] }
          do
            v80 = __ldxr(_X0);
          while ( __stlxr(v80 - 1, _X0) );
          if ( v80 != 1 )
          {
LABEL_3:
            if ( v80 <= 0 )
LABEL_127:
              refcount_warn_saturate(_X0, 3);
            break;
          }
          goto LABEL_130;
        }
        _warn_printk("close request on unknown channel\n");
        __break(0x800u);
        break;
      case 7u:
        if ( v6 )
        {
          v39 = v6;
          v40 = v5;
          v41 = raw_spin_lock_irqsave((char *)a1 + 60);
          v42 = idr_find(a1 + 11, v14);
          if ( v42 )
          {
            v43 = v42;
            _X24 = (unsigned int *)(v42 + 120);
            __asm { PRFM            #0x11, [X24] }
            do
              v83 = __ldxr(_X24);
            while ( __stxr(v83 + 1, _X24) );
            if ( v83 )
            {
              if ( (((v83 + 1) | v83) & 0x80000000) != 0 )
              {
                v74 = 1;
                goto LABEL_122;
              }
            }
            else
            {
              v74 = 2;
LABEL_122:
              refcount_warn_saturate(v42 + 120, v74);
            }
            raw_spin_unlock_irqrestore((char *)a1 + 60, v41);
            v45 = raw_spin_lock_irqsave(v43 + 144);
            for ( LODWORD(v91) = 0; ; LODWORD(v91) = v91 + 1 )
            {
              next = idr_get_next(v43 + 152, &v91);
              if ( !next )
                break;
              if ( (_DWORD)v15 && *(_QWORD *)(next + 16) >= v15 && (*(_BYTE *)(next + 24) & 1) != 0 )
              {
                raw_spin_unlock_irqrestore(v43 + 144, v45);
                v47 = *(_DWORD *)(v43 + 136);
                v48 = *(_QWORD *)(v43 + 112);
                s1[0] = (char *)0x100000008LL;
                WORD1(s1[0]) = v47;
                if ( v48 )
                  ipc_log_string(
                    *(_QWORD *)(v48 + 256),
                    "%s[%d:%d] %s: \n",
                    *(const char **)(v43 + 128),
                    v47,
                    *(_DWORD *)(v43 + 140),
                    "qcom_glink_send_intent_req_ack");
                qcom_glink_tx(v39, s1, 8, 0, 0, 1);
                v5 = v40;
                __asm { PRFM            #0x11, [X24] }
                do
                  v88 = __ldxr(_X24);
                while ( __stlxr(v88 - 1, _X24) );
                v6 = v39;
                if ( v88 == 1 )
                {
LABEL_61:
                  __dmb(9u);
                  qcom_glink_channel_release(_X24);
                  goto LABEL_4;
                }
                if ( v88 <= 0 )
                  goto LABEL_126;
                goto LABEL_4;
              }
            }
            raw_spin_unlock_irqrestore(v43 + 144, v45);
            v5 = v40;
            v6 = v39;
            if ( (qcom_glink_queue_rx_intent_alloc(v43, v15, 0, 1) & 0x80000000) != 0 )
            {
              v49 = *(_DWORD *)(v43 + 136);
              v50 = *(_QWORD *)(v43 + 112);
              s1[0] = (_BYTE *)&unk_8;
              WORD1(s1[0]) = v49;
              if ( v50 )
                ipc_log_string(
                  *(_QWORD *)(v50 + 256),
                  "%s[%d:%d] %s: \n",
                  *(const char **)(v43 + 128),
                  v49,
                  *(_DWORD *)(v43 + 140),
                  "qcom_glink_send_intent_req_ack");
              qcom_glink_tx(v39, s1, 8, 0, 0, 1);
            }
            __asm { PRFM            #0x11, [X24] }
            do
              v85 = __ldxr(_X24);
            while ( __stlxr(v85 - 1, _X24) );
            if ( v85 == 1 )
              goto LABEL_61;
            if ( v85 <= 0 )
            {
LABEL_126:
              _X0 = _X24;
              goto LABEL_127;
            }
            break;
          }
          raw_spin_unlock_irqrestore((char *)a1 + 60, v41);
          v5 = v40;
          v6 = v39;
        }
        printk(&unk_C67B, "qcom_glink_handle_intent_req", (unsigned int)v14, v10, v11, v12);
        break;
      case 0xBu:
        _wake_up(a1 + 16, 3, 0, 0);
        v21 = raw_spin_lock_irqsave((char *)a1 + 60);
        v22 = idr_find(a1 + 8, v14);
        if ( v22 )
        {
          v23 = *(_QWORD *)(v22 + 112);
          v24 = v22;
          if ( v23 )
            ipc_log_string(
              *(_QWORD *)(v23 + 256),
              "%s[%d:%d] %s: \n",
              *(const char **)(v22 + 128),
              *(_DWORD *)(v22 + 136),
              *(_DWORD *)(v22 + 140),
              "qcom_glink_rx_close_ack");
          idr_remove(a1 + 8, *(unsigned int *)(v24 + 136));
          *(_DWORD *)(v24 + 136) = 0;
          raw_spin_unlock_irqrestore((char *)a1 + 60, v21);
          _X0 = (unsigned int *)(v24 + 120);
          *(_DWORD *)(v24 + 280) = 0;
          *(_BYTE *)(v24 + 424) = 0;
          __asm { PRFM            #0x11, [X0] }
          do
            v80 = __ldxr(_X0);
          while ( __stlxr(v80 - 1, _X0) );
          if ( v80 != 1 )
            goto LABEL_3;
LABEL_130:
          __dmb(9u);
          qcom_glink_channel_release(_X0);
          break;
        }
        _warn_printk("close ack on unknown channel\n");
        __break(0x800u);
        raw_spin_unlock_irqrestore((char *)a1 + 60, v21);
        break;
      default:
LABEL_42:
        _warn_printk("Unknown defer object %d\n", v13);
        __break(0x800u);
        break;
    }
LABEL_4:
    kfree(v3);
    v7 = raw_spin_lock_irqsave(a1 + 4);
    v3 = (_QWORD *)*v4;
    v2 = v7;
    if ( (_QWORD *)*v4 == v4 )
      goto LABEL_133;
  }
  if ( !*((_WORD *)v3 + 8) )
  {
    ipc_log_string(a1[20], v5, "qcom_glink_receive_version", *((unsigned __int16 *)v3 + 9), (unsigned int)v15);
    if ( (_DWORD)v14 )
    {
      if ( (_DWORD)v14 == 1 )
      {
        v26 = a1[14] & v15;
        a1[14] = v26;
      }
      else
      {
        v26 = a1[14];
      }
      v51 = a1[20];
      v52 = v5;
      v53 = "qcom_glink_send_version_ack";
      s1[0] = (char *)65537;
      goto LABEL_73;
    }
    goto LABEL_4;
  }
  if ( v13 == 1 )
  {
    ipc_log_string(a1[20], v5, "qcom_glink_receive_version_ack", *((unsigned __int16 *)v3 + 9), (unsigned int)v15);
    if ( (_DWORD)v14 )
    {
      if ( (_DWORD)v14 != 1 )
      {
        v26 = a1[14];
LABEL_72:
        v51 = a1[20];
        v52 = v5;
        s1[0] = (char *)0x10000;
        v53 = "qcom_glink_send_version";
LABEL_73:
        HIDWORD(s1[0]) = v26;
        ipc_log_string(v51, v52, v53, 1);
        qcom_glink_tx(v6, s1, 8, 0, 0, 1);
        goto LABEL_4;
      }
      v38 = a1[14];
      if ( v38 != v15 )
      {
        LODWORD(v26) = v38 & v15;
        a1[14] = v38 & v15;
        goto LABEL_72;
      }
    }
    goto LABEL_4;
  }
  if ( v13 != 2 )
    goto LABEL_42;
  v16 = raw_spin_lock_irqsave((char *)a1 + 60);
  LODWORD(v91) = 0;
  v17 = idr_get_next(a1 + 11, &v91);
  if ( !v17 )
  {
LABEL_16:
    raw_spin_unlock_irqrestore((char *)a1 + 60, v16);
    v19 = qcom_glink_alloc_channel(v6, v3 + 3);
    if ( v19 <= 0xFFFFFFFFFFFFF000LL )
    {
      v18 = v19;
      v20 = 1;
      goto LABEL_75;
    }
    goto LABEL_4;
  }
  v18 = v17;
  while ( strcmp(*(const char **)(v18 + 128), (const char *)v3 + 24) )
  {
    LODWORD(v91) = v91 + 1;
    v18 = idr_get_next(a1 + 11, &v91);
    if ( !v18 )
      goto LABEL_16;
  }
  raw_spin_unlock_irqrestore((char *)a1 + 60, v16);
  v20 = 0;
LABEL_75:
  v54 = raw_spin_lock_irqsave((char *)a1 + 60);
  v55 = idr_alloc(a1 + 11, v18, (unsigned int)v14, (unsigned int)(v14 + 1), 2080);
  if ( v55 < 0 )
  {
    dev_err(*v6, "Unable to insert channel into rcid list\n");
    goto LABEL_98;
  }
  *(_DWORD *)(v18 + 140) = v55;
  raw_spin_unlock_irqrestore((char *)a1 + 60, v54);
  complete_all(v18 + 312);
  v56 = *(_DWORD *)(v18 + 140);
  v57 = *(_QWORD *)(v18 + 112);
  s1[0] = (_BYTE *)&unk_4;
  WORD1(s1[0]) = v56;
  if ( v57 )
    ipc_log_string(
      *(_QWORD *)(v57 + 256),
      "%s[%d:%d] %s: \n",
      *(const char **)(v18 + 128),
      *(_DWORD *)(v18 + 136),
      v56,
      "qcom_glink_send_open_ack");
  qcom_glink_tx(v6, s1, 8, 0, 0, 1);
  if ( !v20 )
    goto LABEL_103;
  v58 = (_QWORD *)_kmalloc_cache_noprof(_stack_chk_fail, 3520, 992);
  if ( !v58 )
    goto LABEL_95;
  v58[121] = v18;
  v31 = strnlen((const char *)v3 + 24, 0x20u);
  if ( v31 == -1 )
  {
LABEL_134:
    _fortify_panic(2, -1, v31 + 1);
LABEL_135:
    _fortify_panic(7, 40, v32);
  }
  if ( v31 == 32 )
    v59 = 32;
  else
    v59 = v31 + 1;
  if ( v59 < 0x51 )
  {
    v60 = v20;
    v61 = v6;
    v62 = v5;
    v63 = sized_strscpy(v58 + 114, v3 + 3);
    if ( v63 <= 0x1F )
      memset((char *)v58 + v63 + 913, 0, 31 - v63);
    v58[120] = -1;
    v64 = *v61;
    v65 = 0;
    v58[123] = &glink_device_ops;
    v66 = *(_QWORD *)(v64 + 744);
    s1[0] = nullptr;
    v67 = v66;
    while ( 1 )
    {
      next_available_child = of_get_next_available_child(v67, v65);
      v69 = next_available_child;
      if ( !next_available_child
        || !(unsigned int)of_property_read_string(next_available_child, "qcom,glink-channels", s1)
        && !strcmp(s1[0], (const char *)v3 + 24) )
      {
        break;
      }
      v67 = v66;
      v65 = v69;
    }
    v70 = *v61;
    v58[93] = v69;
    v58[12] = v70;
    v58[101] = qcom_glink_rpdev_release;
    v5 = v62;
    if ( of_find_property(v69, "qcom,cb-irq", 0) )
      *(_BYTE *)(v18 + 432) = 1;
    v6 = v61;
    v20 = v60;
    if ( !(unsigned int)rpmsg_register_device(v58) )
    {
      *(_QWORD *)(v18 + 104) = v58;
LABEL_103:
      v73 = *(_QWORD *)(v18 + 112);
      if ( v73 )
        ipc_log_string(
          *(_QWORD *)(v73 + 256),
          "%s[%d:%d] %s: \n",
          *(const char **)(v18 + 128),
          *(_DWORD *)(v18 + 136),
          *(_DWORD *)(v18 + 140),
          "qcom_glink_rx_open");
      goto LABEL_4;
    }
LABEL_95:
    v71 = *(_QWORD *)(v18 + 112);
    if ( v71 )
      ipc_log_string(
        *(_QWORD *)(v71 + 256),
        "%s[%d:%d] %s: rcid_remove\n",
        *(const char **)(v18 + 128),
        *(_DWORD *)(v18 + 136),
        *(_DWORD *)(v18 + 140),
        "qcom_glink_rx_open");
    v54 = raw_spin_lock_irqsave((char *)a1 + 60);
    idr_remove(a1 + 11, *(unsigned int *)(v18 + 140));
    *(_DWORD *)(v18 + 140) = 0;
LABEL_98:
    raw_spin_unlock_irqrestore((char *)a1 + 60, v54);
    v72 = *(_QWORD *)(v18 + 112);
    if ( v72 )
      ipc_log_string(
        *(_QWORD *)(v72 + 256),
        "%s[%d:%d] %s: free_channel\n",
        *(const char **)(v18 + 128),
        *(_DWORD *)(v18 + 136),
        *(_DWORD *)(v18 + 140),
        "qcom_glink_rx_open");
    if ( !v20 )
      goto LABEL_4;
    _X0 = (unsigned int *)(v18 + 120);
    __asm { PRFM            #0x11, [X0] }
    do
      v80 = __ldxr(_X0);
    while ( __stlxr(v80 - 1, _X0) );
    if ( v80 != 1 )
      goto LABEL_3;
    goto LABEL_130;
  }
  v90 = _fortify_panic(7, 80, v59);
  return qcom_glink_native_start(v90);
}
