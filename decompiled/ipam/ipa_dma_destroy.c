__int64 __fastcall ipa_dma_destroy(__int64 a1)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x4
  __int64 v13; // x5
  __int64 v14; // x6
  __int64 v15; // x7
  __int64 ipc_logbuf; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // x1
  __int64 v21; // x2
  __int64 v22; // x3
  __int64 v23; // x4
  __int64 v24; // x5
  __int64 v25; // x6
  __int64 v26; // x7
  __int64 v27; // x0
  __int64 v28; // x1
  __int64 v29; // x2
  __int64 v30; // x3
  __int64 v31; // x4
  __int64 v32; // x5
  __int64 v33; // x6
  __int64 v34; // x7
  __int64 v35; // x0
  __int64 v36; // x1
  __int64 v37; // x2
  __int64 v38; // x3
  __int64 v39; // x4
  __int64 v40; // x5
  __int64 v41; // x6
  __int64 v42; // x7
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 result; // x0
  __int64 v49; // x0
  __int64 v50; // x0
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
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x0
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
  __int64 v78; // x0
  __int64 v79; // x0
  __int64 v80; // x0
  __int64 v81; // x0
  __int64 v82; // x0

  ipc_logbuf_low = ipa3_get_ipc_logbuf_low(a1);
  if ( ipc_logbuf_low )
  {
    v2 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
    ipc_log_string(v2, "ipa_dma %s:%d ENTRY\n", "ipa_dma_destroy", 1019);
  }
  if ( ipa_dma_init_refcnt_ctrl )
  {
    v3 = mutex_lock(ipa_dma_init_refcnt_ctrl + 8);
    if ( *(_DWORD *)ipa_dma_init_refcnt_ctrl < 2u )
    {
      if ( *(_DWORD *)ipa_dma_init_refcnt_ctrl && ipa3_dma_ctx )
      {
        v8 = ipa3_dma_work_pending(v3);
        if ( (v8 & 1) != 0 )
        {
          *(_BYTE *)(ipa3_dma_ctx + 4) = 1;
          ipc_logbuf = ipa3_get_ipc_logbuf(v8);
          if ( ipc_logbuf )
          {
            v17 = ipa3_get_ipc_logbuf(ipc_logbuf);
            ipc_logbuf = ipc_log_string(
                           v17,
                           "ipa_dma %s:%d There are pending memcpy, wait for completion\n",
                           "ipa_dma_destroy",
                           1041);
          }
          v18 = ipa3_get_ipc_logbuf_low(ipc_logbuf);
          if ( v18 )
          {
            v19 = ipa3_get_ipc_logbuf_low(v18);
            ipc_log_string(
              v19,
              "ipa_dma %s:%d There are pending memcpy, wait for completion\n",
              "ipa_dma_destroy",
              1041);
          }
          wait_for_completion(ipa3_dma_ctx + 128);
        }
        if ( *(_DWORD *)ipa3_dma_ctx )
        {
          v58 = printk(&unk_3B1FE2, "ipa_dma_destroy");
          v59 = ipa3_get_ipc_logbuf(v58);
          if ( v59 )
          {
            v60 = ipa3_get_ipc_logbuf(v59);
            v59 = ipc_log_string(v60, "ipa_dma %s:%d IPADMA still enabled\n", "ipa_dma_destroy", 1046);
          }
          v61 = ipa3_get_ipc_logbuf_low(v59);
          if ( v61 )
          {
            v62 = ipa3_get_ipc_logbuf_low(v61);
            ipc_log_string(v62, "ipa_dma %s:%d IPADMA still enabled\n", "ipa_dma_destroy", 1046);
          }
        }
        else
        {
          if ( (unsigned int)ipa_teardown_sys_pipe(
                               *(unsigned int *)(ipa3_dma_ctx + 172),
                               v9,
                               v10,
                               v11,
                               v12,
                               v13,
                               v14,
                               v15) )
          {
            v63 = printk(&unk_3A33A4, "ipa_dma_destroy");
            v64 = ipa3_get_ipc_logbuf(v63);
            if ( v64 )
            {
              v65 = ipa3_get_ipc_logbuf(v64);
              v64 = ipc_log_string(v65, "ipa_dma %s:%d teardown IPADMA ASYNC CONS failed\n", "ipa_dma_destroy", 1052);
            }
            v66 = ipa3_get_ipc_logbuf_low(v64);
            if ( v66 )
            {
              v67 = ipa3_get_ipc_logbuf_low(v66);
              ipc_log_string(v67, "ipa_dma %s:%d teardown IPADMA ASYNC CONS failed\n", "ipa_dma_destroy", 1052);
            }
          }
          v27 = *(unsigned int *)(ipa3_dma_ctx + 168);
          *(_DWORD *)(ipa3_dma_ctx + 172) = 0;
          if ( (unsigned int)ipa_teardown_sys_pipe(v27, v20, v21, v22, v23, v24, v25, v26) )
          {
            v68 = printk(&unk_3EC20F, "ipa_dma_destroy");
            v69 = ipa3_get_ipc_logbuf(v68);
            if ( v69 )
            {
              v70 = ipa3_get_ipc_logbuf(v69);
              v69 = ipc_log_string(v70, "ipa_dma %s:%d teardown IPADMA SYNC CONS failed\n", "ipa_dma_destroy", 1056);
            }
            v71 = ipa3_get_ipc_logbuf_low(v69);
            if ( v71 )
            {
              v72 = ipa3_get_ipc_logbuf_low(v71);
              ipc_log_string(v72, "ipa_dma %s:%d teardown IPADMA SYNC CONS failed\n", "ipa_dma_destroy", 1056);
            }
          }
          v35 = *(unsigned int *)(ipa3_dma_ctx + 164);
          *(_DWORD *)(ipa3_dma_ctx + 168) = 0;
          if ( (unsigned int)ipa_teardown_sys_pipe(v35, v28, v29, v30, v31, v32, v33, v34) )
          {
            v73 = printk(&unk_3A9A65, "ipa_dma_destroy");
            v74 = ipa3_get_ipc_logbuf(v73);
            if ( v74 )
            {
              v75 = ipa3_get_ipc_logbuf(v74);
              v74 = ipc_log_string(v75, "ipa_dma %s:%d teardown IPADMA ASYNC PROD failed\n", "ipa_dma_destroy", 1060);
            }
            v76 = ipa3_get_ipc_logbuf_low(v74);
            if ( v76 )
            {
              v77 = ipa3_get_ipc_logbuf_low(v76);
              ipc_log_string(v77, "ipa_dma %s:%d teardown IPADMA ASYNC PROD failed\n", "ipa_dma_destroy", 1060);
            }
          }
          v43 = *(unsigned int *)(ipa3_dma_ctx + 160);
          *(_DWORD *)(ipa3_dma_ctx + 164) = 0;
          if ( (unsigned int)ipa_teardown_sys_pipe(v43, v36, v37, v38, v39, v40, v41, v42) )
          {
            v78 = printk(&unk_3BDC81, "ipa_dma_destroy");
            v79 = ipa3_get_ipc_logbuf(v78);
            if ( v79 )
            {
              v80 = ipa3_get_ipc_logbuf(v79);
              v79 = ipc_log_string(v80, "ipa_dma %s:%d teardown IPADMA SYNC PROD failed\n", "ipa_dma_destroy", 1064);
            }
            v81 = ipa3_get_ipc_logbuf_low(v79);
            if ( v81 )
            {
              v82 = ipa3_get_ipc_logbuf_low(v81);
              ipc_log_string(v82, "ipa_dma %s:%d teardown IPADMA SYNC PROD failed\n", "ipa_dma_destroy", 1064);
            }
          }
          v44 = dent_0;
          *(_DWORD *)(ipa3_dma_ctx + 160) = 0;
          debugfs_remove(v44);
          kmem_cache_destroy(*(_QWORD *)(ipa3_dma_ctx + 8));
          dma_free_attrs(
            *(_QWORD *)(ipa3_ctx + 34216),
            32,
            *(_QWORD *)(ipa3_dma_ctx + 200),
            *(_QWORD *)(ipa3_dma_ctx + 208),
            0);
          v45 = kfree(ipa3_dma_ctx);
          ipa3_dma_ctx = 0;
          *(_DWORD *)ipa_dma_init_refcnt_ctrl = 0;
          v46 = ipa3_get_ipc_logbuf_low(v45);
          if ( v46 )
          {
            v47 = ipa3_get_ipc_logbuf_low(v46);
            ipc_log_string(v47, "ipa_dma %s:%d EXIT\n", "ipa_dma_destroy", 1076);
          }
        }
      }
      else
      {
        v53 = printk(&unk_3E0C85, "ipa_dma_destroy");
        v54 = ipa3_get_ipc_logbuf(v53);
        if ( v54 )
        {
          v55 = ipa3_get_ipc_logbuf(v54);
          v54 = ipc_log_string(
                  v55,
                  "ipa_dma %s:%d IPADMA isn't initialized ctx=%pK\n",
                  "ipa_dma_destroy",
                  1035,
                  (const void *)ipa3_dma_ctx);
        }
        v56 = ipa3_get_ipc_logbuf_low(v54);
        if ( v56 )
        {
          v57 = ipa3_get_ipc_logbuf_low(v56);
          ipc_log_string(
            v57,
            "ipa_dma %s:%d IPADMA isn't initialized ctx=%pK\n",
            "ipa_dma_destroy",
            1035,
            (const void *)ipa3_dma_ctx);
        }
      }
    }
    else
    {
      v4 = ipa3_get_ipc_logbuf(v3);
      if ( v4 )
      {
        v5 = ipa3_get_ipc_logbuf(v4);
        v4 = ipc_log_string(
               v5,
               "ipa_dma %s:%d Multiple initialization done. refcnt=%d\n",
               "ipa_dma_destroy",
               1029,
               *(_DWORD *)ipa_dma_init_refcnt_ctrl);
      }
      v6 = ipa3_get_ipc_logbuf_low(v4);
      if ( v6 )
      {
        v7 = ipa3_get_ipc_logbuf_low(v6);
        ipc_log_string(
          v7,
          "ipa_dma %s:%d Multiple initialization done. refcnt=%d\n",
          "ipa_dma_destroy",
          1029,
          *(_DWORD *)ipa_dma_init_refcnt_ctrl);
      }
      --*(_DWORD *)ipa_dma_init_refcnt_ctrl;
    }
    return mutex_unlock(ipa_dma_init_refcnt_ctrl + 8);
  }
  else
  {
    v49 = printk(&unk_3C3AEA, "ipa_dma_destroy");
    v50 = ipa3_get_ipc_logbuf(v49);
    if ( v50 )
    {
      v51 = ipa3_get_ipc_logbuf(v50);
      v50 = ipc_log_string(v51, "ipa_dma %s:%d Setup isn't done\n", "ipa_dma_destroy", 1022);
    }
    result = ipa3_get_ipc_logbuf_low(v50);
    if ( result )
    {
      v52 = ipa3_get_ipc_logbuf_low(result);
      return ipc_log_string(v52, "ipa_dma %s:%d Setup isn't done\n", "ipa_dma_destroy", 1022);
    }
  }
  return result;
}
