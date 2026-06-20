__int64 __fastcall ipa3_cfg_ep_holb(unsigned int a1, _DWORD *a2)
{
  __int64 v2; // x18
  int v3; // w8
  _DWORD *v6; // x10
  unsigned int v7; // w9
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x8
  unsigned int v11; // w9
  unsigned int v12; // w9
  int v13; // w12
  unsigned int v14; // w11
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 result; // x0
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x8
  __int64 v33; // x0
  __int64 v34; // x0
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x8
  __int64 v40; // x0

  _ReadStatusReg(SP_EL0);
  v3 = ipa3_ctx;
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
    goto LABEL_34;
  if ( a1 < 0x24 )
  {
    if ( a2 )
    {
      v6 = (_DWORD *)(ipa3_ctx + 168 + 480LL * a1);
      if ( *v6 )
      {
        if ( *a2 <= *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 34176) + 40LL) && *((unsigned __int16 *)a2 + 6) < 2u )
        {
          v7 = v6[1];
          if ( v7 > 0x85 || (v7 & 1) != 0 )
          {
            v8 = ipa3_ctx + 168 + 480LL * a1;
            v9 = *((_QWORD *)a2 + 1);
            *(_QWORD *)(v8 + 336) = *(_QWORD *)a2;
            *(_QWORD *)(v8 + 344) = v9;
            if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
            {
              printk(&unk_3E7136, "ipa3_get_client_mapping");
              v26 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v27 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v27 )
                {
                  ipc_log_string(v27, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
                  v26 = ipa3_ctx;
                }
                v28 = *(_QWORD *)(v26 + 34160);
                if ( v28 )
                  ipc_log_string(v28, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
              }
              __break(0x800u);
              if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
              {
                printk(&unk_3E7136, "ipa3_get_client_mapping");
                v29 = ipa3_ctx;
                if ( ipa3_ctx )
                {
                  v30 = *(_QWORD *)(ipa3_ctx + 34152);
                  if ( v30 )
                  {
                    ipc_log_string(v30, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
                    v29 = ipa3_ctx;
                  }
                  v31 = *(_QWORD *)(v29 + 34160);
                  if ( v31 )
                    ipc_log_string(v31, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
                }
                __break(0x800u);
              }
            }
            ipa3_inc_client_enable_clks();
            if ( !*((_WORD *)a2 + 6) )
              goto LABEL_26;
            v10 = ipa3_ctx;
            v11 = *(_DWORD *)(ipa3_ctx + 32240);
            if ( v11 < 0x11 )
            {
              if ( v11 != 16 )
              {
LABEL_13:
                if ( v11 < 0x11 )
                  goto LABEL_25;
LABEL_23:
                if ( (unsigned int)ipa3_process_timer_cfg(
                                     1000 * *a2,
                                     (_BYTE *)(v10 + 480LL * a1 + 518),
                                     (unsigned __int8 *)(v10 + 480LL * a1 + 519)) )
                {
                  v38 = printk(&unk_3EFDA2, "ipa3_cfg_ep_holb");
                  v39 = ipa3_ctx;
                  if ( ipa3_ctx )
                  {
                    v40 = *(_QWORD *)(ipa3_ctx + 34152);
                    if ( v40 )
                    {
                      ipc_log_string(
                        v40,
                        "ipa %s:%d failed to process HOLB timer tmr=%u\n",
                        "ipa3_cfg_ep_holb",
                        9852,
                        *a2);
                      v39 = ipa3_ctx;
                    }
                    v38 = *(_QWORD *)(v39 + 34160);
                    if ( v38 )
                      v38 = ipc_log_string(
                              v38,
                              "ipa %s:%d failed to process HOLB timer tmr=%u\n",
                              "ipa3_cfg_ep_holb",
                              9852,
                              *a2);
                  }
                  ((void (__fastcall *)(__int64))ipa_assert)(v38);
                  result = 0xFFFFFFFFLL;
                  goto LABEL_40;
                }
                v10 = ipa3_ctx;
LABEL_25:
                ((void (__fastcall *)(__int64, _QWORD, __int64))ipahal_write_reg_n_fields)(
                  53,
                  a1,
                  v10 + 480LL * a1 + 504);
                *(_WORD *)(ipa3_ctx + 480LL * a1 + 516) = 1;
                ((void (__fastcall *)(__int64, _QWORD, _DWORD *))ipahal_write_reg_n_fields)(52, a1, a2);
                if ( *(_DWORD *)(ipa3_ctx + 32240) < 0xEu )
                {
LABEL_27:
                  if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
                  {
                    printk(&unk_3E7136, "ipa3_get_client_mapping");
                    v32 = ipa3_ctx;
                    if ( ipa3_ctx )
                    {
                      v33 = *(_QWORD *)(ipa3_ctx + 34152);
                      if ( v33 )
                      {
                        ipc_log_string(v33, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
                        v32 = ipa3_ctx;
                      }
                      v34 = *(_QWORD *)(v32 + 34160);
                      if ( v34 )
                        ipc_log_string(v34, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
                    }
                    __break(0x800u);
                    if ( *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
                    {
                      printk(&unk_3E7136, "ipa3_get_client_mapping");
                      v35 = ipa3_ctx;
                      if ( ipa3_ctx )
                      {
                        v36 = *(_QWORD *)(ipa3_ctx + 34152);
                        if ( v36 )
                        {
                          ipc_log_string(v36, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
                          v35 = ipa3_ctx;
                        }
                        v37 = *(_QWORD *)(v35 + 34160);
                        if ( v37 )
                          ipc_log_string(v37, "ipa %s:%d Bad pipe index!\n", "ipa3_get_client_mapping", 8584);
                      }
                      __break(0x800u);
                    }
                  }
                  ipa3_dec_client_disable_clks();
                  v17 = ipa3_ctx;
                  if ( ipa3_ctx )
                  {
                    v18 = *(_QWORD *)(ipa3_ctx + 34152);
                    if ( v18 )
                    {
                      ipc_log_string(
                        v18,
                        "ipa %s:%d cfg holb %u ep=%d tmr=%d\n",
                        "ipa3_cfg_ep_holb",
                        9873,
                        *((unsigned __int16 *)a2 + 6),
                        a1,
                        *a2);
                      v17 = ipa3_ctx;
                    }
                    result = *(_QWORD *)(v17 + 34160);
                    if ( !result )
                      goto LABEL_40;
                    ipc_log_string(
                      result,
                      "ipa %s:%d cfg holb %u ep=%d tmr=%d\n",
                      "ipa3_cfg_ep_holb",
                      9873,
                      *((unsigned __int16 *)a2 + 6),
                      a1,
                      *a2);
                  }
                  result = 0;
LABEL_40:
                  _ReadStatusReg(SP_EL0);
                  return result;
                }
LABEL_26:
                ((void (__fastcall *)(__int64, _QWORD, _DWORD *))ipahal_write_reg_n_fields)(52, a1, a2);
                goto LABEL_27;
              }
            }
            else
            {
              *(_WORD *)(ipa3_ctx + 480LL * a1 + 516) = 0;
              ((void (__fastcall *)(__int64, _QWORD, _DWORD *))ipahal_write_reg_n_fields)(52, a1, a2);
              v10 = ipa3_ctx;
              v11 = *(_DWORD *)(ipa3_ctx + 32240);
              if ( v11 != 16 )
                goto LABEL_13;
            }
            v12 = 1;
            v13 = 31;
            do
            {
              v14 = *a2 / v12;
              v12 <<= v13 != 31;
            }
            while ( v14 >= 0x20 && v13-- != 0 );
            v16 = v10 + 480LL * a1;
            *(_DWORD *)(v16 + 508) = v14;
            *(_DWORD *)(v16 + 512) = v12;
            v10 = ipa3_ctx;
            if ( *(_DWORD *)(ipa3_ctx + 32240) < 0x11u )
              goto LABEL_25;
            goto LABEL_23;
          }
          printk(&unk_3E71FF, "ipa3_cfg_ep_holb");
          v23 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v24 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v24 )
            {
              ipc_log_string(v24, "ipa %s:%d HOLB does not apply to IPA in EP %d\n", "ipa3_cfg_ep_holb", 9818, a1);
              v23 = ipa3_ctx;
            }
            v25 = *(_QWORD *)(v23 + 34160);
            if ( v25 )
            {
              ipc_log_string(v25, "ipa %s:%d HOLB does not apply to IPA in EP %d\n", "ipa3_cfg_ep_holb", 9818, a1);
              result = 4294967274LL;
              goto LABEL_40;
            }
          }
LABEL_39:
          result = 4294967274LL;
          goto LABEL_40;
        }
      }
    }
LABEL_34:
    printk(&unk_3F1C1D, "ipa3_cfg_ep_holb");
    v20 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v21 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v21 )
      {
        ipc_log_string(v21, "ipa %s:%d bad parm.\n", "ipa3_cfg_ep_holb", 9813);
        v20 = ipa3_ctx;
      }
      v22 = *(_QWORD *)(v20 + 34160);
      if ( v22 )
        ipc_log_string(v22, "ipa %s:%d bad parm.\n", "ipa3_cfg_ep_holb", 9813);
    }
    goto LABEL_39;
  }
  __break(0x5512u);
  *(_DWORD *)(v2 + 13908) = v3;
  return ipa3_force_cfg_ep_holb();
}
