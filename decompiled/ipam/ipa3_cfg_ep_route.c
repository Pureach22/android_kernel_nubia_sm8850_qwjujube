__int64 __fastcall ipa3_cfg_ep_route(unsigned int a1, _DWORD *a2)
{
  __int64 v3; // x8
  unsigned int v4; // w21
  _DWORD *v5; // x11
  unsigned int v6; // w11
  __int64 v7; // x0
  __int64 result; // x0
  __int64 v9; // x0
  _DWORD *v10; // x22
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  _DWORD *v18; // x22
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  int v33; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v34; // [xsp+28h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = ipa3_ctx;
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
  {
    if ( a1 <= 0x23 )
    {
      v4 = a1;
LABEL_27:
      printk(&unk_3E4584, "ipa3_cfg_ep_route");
      v12 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v13 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v13 )
        {
          ipc_log_string(
            v13,
            "ipa %s:%d bad parm, clnt_hdl = %d , ep_valid = %d\n",
            "ipa3_cfg_ep_route",
            9721,
            a1,
            *(_DWORD *)(ipa3_ctx + 480LL * v4 + 168));
          v12 = ipa3_ctx;
        }
        v14 = *(_QWORD *)(v12 + 34160);
        if ( v14 )
        {
          ipc_log_string(
            v14,
            "ipa %s:%d bad parm, clnt_hdl = %d , ep_valid = %d\n",
            "ipa3_cfg_ep_route",
            9721,
            a1,
            *(_DWORD *)(v12 + 480LL * v4 + 168));
          result = 4294967274LL;
          goto LABEL_24;
        }
      }
LABEL_37:
      result = 4294967274LL;
      goto LABEL_24;
    }
LABEL_67:
    __break(0x5512u);
  }
  if ( a1 >= 0x24 )
    goto LABEL_67;
  v4 = a1;
  v5 = (_DWORD *)(ipa3_ctx + 168 + 480LL * a1);
  if ( !a2 || !*v5 )
    goto LABEL_27;
  v6 = v5[1];
  if ( v6 <= 0x85 && (v6 & 1) != 0 )
  {
    printk(&unk_3EA35D, "ipa3_cfg_ep_route");
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        ipc_log_string(v16, "ipa %s:%d ROUTE does not apply to IPA out EP %d\n", "ipa3_cfg_ep_route", 9727, a1);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
        ipc_log_string(v17, "ipa %s:%d ROUTE does not apply to IPA out EP %d\n", "ipa3_cfg_ep_route", 9727, a1);
    }
    goto LABEL_37;
  }
  if ( *(_DWORD *)(ipa3_ctx + 168 + 480LL * a1 + 232) != 3 )
  {
    if ( *a2 )
    {
      v18 = a2;
      printk(&unk_3C7CEA, "ipa3_cfg_ep_route");
      v3 = ipa3_ctx;
      if ( !ipa3_ctx )
      {
LABEL_19:
        *(_DWORD *)(v3 + 480LL * a1 + 528) = *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 64LL);
        if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0xDu )
        {
          if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
          {
            printk(&unk_3E7136, "ipa3_get_client_mapping");
            v21 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v22 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v22 )
              {
                ipc_log_string(v22, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
                v21 = ipa3_ctx;
              }
              v23 = *(_QWORD *)(v21 + 34160);
              if ( v23 )
                ipc_log_string(v23, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
            }
            __break(0x800u);
            if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
            {
              printk(&unk_3E7136, "ipa3_get_client_mapping");
              v24 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v25 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v25 )
                {
                  ipc_log_string(v25, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
                  v24 = ipa3_ctx;
                }
                v26 = *(_QWORD *)(v24 + 34160);
                if ( v26 )
                  ipc_log_string(v26, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
              }
              __break(0x800u);
            }
          }
          ipa3_inc_client_enable_clks();
          v33 = *(_DWORD *)(ipa3_ctx + 480LL * a1 + 528);
          ((void (__fastcall *)(__int64, _QWORD, int *))ipahal_write_reg_n_fields)(45, a1, &v33);
          if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
          {
            printk(&unk_3E7136, "ipa3_get_client_mapping");
            v27 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v28 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v28 )
              {
                ipc_log_string(v28, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
                v27 = ipa3_ctx;
              }
              v29 = *(_QWORD *)(v27 + 34160);
              if ( v29 )
                ipc_log_string(v29, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
            }
            __break(0x800u);
            if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
            {
              printk(&unk_3E7136, "ipa3_get_client_mapping");
              v30 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v31 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v31 )
                {
                  ipc_log_string(v31, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
                  v30 = ipa3_ctx;
                }
                v32 = *(_QWORD *)(v30 + 34160);
                if ( v32 )
                  ipc_log_string(v32, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
              }
              __break(0x800u);
            }
          }
          ipa3_dec_client_disable_clks();
        }
        goto LABEL_23;
      }
      v19 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v19 )
      {
        ipc_log_string(v19, "ipa %s:%d client specified non-zero RT TBL hdl - ignore it\n", "ipa3_cfg_ep_route", 9742);
        v3 = ipa3_ctx;
      }
      a2 = v18;
      v20 = *(_QWORD *)(v3 + 34160);
      if ( v20 )
      {
        ipc_log_string(v20, "ipa %s:%d client specified non-zero RT TBL hdl - ignore it\n", "ipa3_cfg_ep_route", 9742);
        v3 = ipa3_ctx;
        a2 = v18;
      }
    }
    if ( v3 )
    {
      v9 = *(_QWORD *)(v3 + 34152);
      if ( v9 )
      {
        v10 = a2;
        ipc_log_string(v9, "ipa %s:%d pipe=%d, rt_tbl_hdl=%d\n", "ipa3_cfg_ep_route", 9746, a1, *a2);
        v3 = ipa3_ctx;
        a2 = v10;
      }
      v11 = *(_QWORD *)(v3 + 34160);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d pipe=%d, rt_tbl_hdl=%d\n", "ipa3_cfg_ep_route", 9746, a1, *a2);
        v3 = ipa3_ctx;
      }
    }
    goto LABEL_19;
  }
  if ( !ipa3_ctx )
  {
LABEL_23:
    result = 0;
    goto LABEL_24;
  }
  v7 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v7 )
  {
    ipc_log_string(v7, "ipa %s:%d DMA enabled for ep %d, dst pipe is part of DMA\n", "ipa3_cfg_ep_route", 9737, a1);
    v3 = ipa3_ctx;
  }
  result = *(_QWORD *)(v3 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d DMA enabled for ep %d, dst pipe is part of DMA\n", "ipa3_cfg_ep_route", 9737, a1);
    goto LABEL_23;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
