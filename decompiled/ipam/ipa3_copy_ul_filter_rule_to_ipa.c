__int64 __fastcall ipa3_copy_ul_filter_rule_to_ipa(__int64 a1)
{
  __int64 v2; // x21
  _BYTE *v3; // x20
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x23
  __int64 v10; // x24
  __int64 v11; // x8
  __int64 v12; // x1
  __int64 v13; // x0
  __int64 v14; // x0
  unsigned __int64 v15; // x23
  __int64 v16; // x24
  __int64 v17; // x0
  __int64 v18; // x1
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x23
  __int64 v22; // x24
  unsigned int v23; // w3
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x20
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x21
  __int64 v30; // x9
  int v31; // w10
  unsigned __int64 v32; // x9
  __int64 v33; // x13
  unsigned __int64 v34; // x12
  unsigned __int64 v35; // x23
  __int64 v36; // x19
  unsigned int v37; // w3
  unsigned int v38; // w19
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  __int64 v55; // x0
  void *v56; // x0

  v2 = a1 + 27696;
  v3 = (_BYTE *)(a1 + 13600);
  mutex_lock(rmnet_ipa3_ctx + 1136);
  if ( v3[264] == 1 )
  {
    if ( !*(_BYTE *)v2 )
    {
      *(_DWORD *)(rmnet_ipa3_ctx + 1036) = *(_DWORD *)(a1 + 13868);
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(
          ipc_logbuf,
          "ipa-wan %s:%d Received (%d) install_flt_req_ex_list\n",
          "ipa3_copy_ul_filter_rule_to_ipa",
          887,
          *(_DWORD *)(rmnet_ipa3_ctx + 1036));
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          ipc_logbuf_low,
          "ipa-wan %s:%d Received (%d) install_flt_req_ex_list\n",
          "ipa3_copy_ul_filter_rule_to_ipa",
          887,
          *(unsigned int *)(rmnet_ipa3_ctx + 1036));
      }
      goto LABEL_13;
    }
LABEL_71:
    *(_DWORD *)(rmnet_ipa3_ctx + 1036) = 0;
    if ( *(_BYTE *)v2 == 1 )
    {
      printk(&unk_3BC2EE, "ipa3_copy_ul_filter_rule_to_ipa");
      if ( ipa3_get_ipc_logbuf() )
      {
        v40 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v40,
          "ipa-wan %s:%d both ex and ex2 flt rules are set to valid\n",
          "ipa3_copy_ul_filter_rule_to_ipa",
          898);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v41 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v41,
          "ipa-wan %s:%d both ex and ex2 flt rules are set to valid\n",
          "ipa3_copy_ul_filter_rule_to_ipa",
          898);
      }
    }
    else
    {
      printk(&unk_3DC657, "ipa3_copy_ul_filter_rule_to_ipa");
      if ( ipa3_get_ipc_logbuf() )
      {
        v50 = ipa3_get_ipc_logbuf();
        ipc_log_string(v50, "ipa-wan %s:%d got no UL rules from modem\n", "ipa3_copy_ul_filter_rule_to_ipa", 900);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v51 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v51, "ipa-wan %s:%d got no UL rules from modem\n", "ipa3_copy_ul_filter_rule_to_ipa", 900);
      }
    }
    v29 = rmnet_ipa3_ctx;
    v38 = -22;
    goto LABEL_70;
  }
  if ( v3[264] || *(_BYTE *)v2 != 1 )
    goto LABEL_71;
  *(_DWORD *)(rmnet_ipa3_ctx + 1036) = *(_DWORD *)(v2 + 4);
  if ( ipa3_get_ipc_logbuf() )
  {
    v6 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v6,
      "ipa-wan %s:%d Received (%d) install_flt_req_ex2_list\n",
      "ipa3_copy_ul_filter_rule_to_ipa",
      893,
      *(_DWORD *)(rmnet_ipa3_ctx + 1036));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v7 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v7,
      "ipa-wan %s:%d Received (%d) install_flt_req_ex2_list\n",
      "ipa3_copy_ul_filter_rule_to_ipa",
      893,
      *(unsigned int *)(rmnet_ipa3_ctx + 1036));
  }
LABEL_13:
  LODWORD(v8) = *(_DWORD *)(rmnet_ipa3_ctx + 1036);
  if ( (int)v8 < 1 )
  {
LABEL_22:
    if ( *v3 )
    {
      if ( *(_DWORD *)(a1 + 13604) > (unsigned int)v8 )
      {
        printk(&unk_3C518D, "ipa3_copy_ul_filter_rule_to_ipa");
        if ( ipa3_get_ipc_logbuf() )
        {
          v46 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v46,
            "ipa-wan %s:%d Number of xlat indices is not valid: %d\n",
            "ipa3_copy_ul_filter_rule_to_ipa",
            930,
            *(_DWORD *)(a1 + 13604));
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v47 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v47,
            "ipa-wan %s:%d Number of xlat indices is not valid: %d\n",
            "ipa3_copy_ul_filter_rule_to_ipa",
            930,
            *(unsigned int *)(a1 + 13604));
        }
        goto LABEL_105;
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v13 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v13,
          "ipa-wan %s:%d Receive %d XLAT indices: ",
          "ipa3_copy_ul_filter_rule_to_ipa",
          934,
          *(_DWORD *)(a1 + 13604));
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v14 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v14,
          "ipa-wan %s:%d Receive %d XLAT indices: ",
          "ipa3_copy_ul_filter_rule_to_ipa",
          934,
          *(_DWORD *)(a1 + 13604));
      }
      if ( *(_DWORD *)(a1 + 13604) )
      {
        v15 = 0;
        v16 = a1 + 13608;
        do
        {
          if ( ipa3_get_ipc_logbuf() )
          {
            v17 = ipa3_get_ipc_logbuf();
            if ( v15 > 0x3F )
              goto LABEL_106;
            ipc_log_string(v17, "ipa-wan %s:%d %d ", "ipa3_copy_ul_filter_rule_to_ipa", 936, *(_DWORD *)(v16 + 4 * v15));
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v17 = ipa3_get_ipc_logbuf_low();
            if ( v15 > 0x3F )
              goto LABEL_106;
            ipc_log_string(v17, "ipa-wan %s:%d %d ", "ipa3_copy_ul_filter_rule_to_ipa", 936, *(_DWORD *)(v16 + 4 * v15));
          }
          ++v15;
        }
        while ( v15 < *(unsigned int *)(a1 + 13604) );
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v19 = ipa3_get_ipc_logbuf();
        ipc_log_string(v19, "ipa-wan %s:%d \n", "ipa3_copy_ul_filter_rule_to_ipa", 937);
      }
      v17 = ipa3_get_ipc_logbuf_low();
      if ( v17 )
      {
        v20 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v20, "ipa-wan %s:%d \n", "ipa3_copy_ul_filter_rule_to_ipa", 937);
      }
      if ( *(_DWORD *)(a1 + 13604) )
      {
        v21 = 0;
        v22 = a1 + 13608;
        while ( v21 != 64 )
        {
          v23 = *(_DWORD *)(v22 + 4 * v21);
          if ( v23 >= *(_DWORD *)(rmnet_ipa3_ctx + 1036) )
          {
            printk(&unk_3D0AE8, "ipa3_copy_ul_filter_rule_to_ipa");
            if ( ipa3_get_ipc_logbuf() )
            {
              v52 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v52,
                "ipa-wan %s:%d Xlat rule idx is wrong: %d\n",
                "ipa3_copy_ul_filter_rule_to_ipa",
                943,
                *(_DWORD *)(v22 + 4 * v21));
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v53 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v53,
                "ipa-wan %s:%d Xlat rule idx is wrong: %d\n",
                "ipa3_copy_ul_filter_rule_to_ipa",
                943,
                *(unsigned int *)(v22 + 4 * v21));
            }
            goto LABEL_105;
          }
          if ( v23 > 0x22 )
            goto LABEL_106;
          *(_BYTE *)(ipa3_qmi_ctx + 216LL * v23 + 204) = 1;
          if ( ipa3_get_ipc_logbuf() )
          {
            v24 = ipa3_get_ipc_logbuf();
            ipc_log_string(
              v24,
              "ipa-wan %s:%d Rule %d is xlat rule\n",
              "ipa3_copy_ul_filter_rule_to_ipa",
              950,
              *(_DWORD *)(v22 + 4 * v21));
          }
          v17 = ipa3_get_ipc_logbuf_low();
          if ( v17 )
          {
            v25 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(
              v25,
              "ipa-wan %s:%d Rule %d is xlat rule\n",
              "ipa3_copy_ul_filter_rule_to_ipa",
              950,
              *(_DWORD *)(v22 + 4 * v21));
          }
          if ( ++v21 >= (unsigned __int64)*(unsigned int *)(a1 + 13604) )
            goto LABEL_51;
        }
        goto LABEL_106;
      }
    }
LABEL_51:
    v26 = a1 + 41528;
    if ( *(_BYTE *)(a1 + 41528) )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v27 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v27,
          "ipa-wan %s:%d Receive ul_firewall_indices_list_len = (%d)",
          "ipa3_copy_ul_filter_rule_to_ipa",
          957,
          *(_DWORD *)(a1 + 41532));
      }
      v17 = ipa3_get_ipc_logbuf_low();
      if ( v17 )
      {
        v28 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v28,
          "ipa-wan %s:%d Receive ul_firewall_indices_list_len = (%d)",
          "ipa3_copy_ul_filter_rule_to_ipa",
          957,
          *(_DWORD *)(a1 + 41532));
      }
      v29 = rmnet_ipa3_ctx;
      if ( *(_DWORD *)(a1 + 41532) > *(_DWORD *)(rmnet_ipa3_ctx + 1036) )
      {
        printk(&unk_3B60A4, "ipa3_copy_ul_filter_rule_to_ipa");
        if ( ipa3_get_ipc_logbuf() )
        {
          v48 = ipa3_get_ipc_logbuf();
          ipc_log_string(
            v48,
            "ipa-wan %s:%d UL rule indices are not valid: (%d/%d)\n",
            "ipa3_copy_ul_filter_rule_to_ipa",
            963,
            *(_DWORD *)(a1 + 13604),
            *(_DWORD *)(rmnet_ipa3_ctx + 1036));
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v49 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v49,
            "ipa-wan %s:%d UL rule indices are not valid: (%d/%d)\n",
            "ipa3_copy_ul_filter_rule_to_ipa",
            963,
            *(_DWORD *)(a1 + 13604),
            *(_DWORD *)(rmnet_ipa3_ctx + 1036));
        }
        goto LABEL_105;
      }
      v30 = ipa3_qmi_ctx + 28672;
      *(_BYTE *)(ipa3_qmi_ctx + 29916) = 1;
      v31 = *(_DWORD *)(a1 + 41532);
      *(_DWORD *)(v30 + 1248) = v31;
      if ( v31 )
      {
        v32 = 0;
        while ( v32 != 64 )
        {
          v33 = 4 * v32++;
          *(_DWORD *)(ipa3_qmi_ctx + v33 + 29924) = *(_DWORD *)(a1 + 41536 + v33);
          v34 = *(unsigned int *)(a1 + 41532);
          if ( v32 >= v34 )
          {
            if ( !(_DWORD)v34 )
              goto LABEL_69;
            v35 = 0;
            v36 = a1 + 41536;
            while ( v35 != 64 )
            {
              v37 = *(_DWORD *)(v36 + 4 * v35);
              if ( v37 >= *(_DWORD *)(v29 + 1036) )
              {
                printk(&unk_3B3373, "ipa3_copy_ul_filter_rule_to_ipa");
                if ( ipa3_get_ipc_logbuf() )
                {
                  v54 = ipa3_get_ipc_logbuf();
                  ipc_log_string(
                    v54,
                    "ipa-wan %s:%d UL rule idx is wrong: %d\n",
                    "ipa3_copy_ul_filter_rule_to_ipa",
                    980,
                    *(_DWORD *)(v36 + 4 * v35));
                }
                if ( ipa3_get_ipc_logbuf_low() )
                {
                  v55 = ipa3_get_ipc_logbuf_low();
                  ipc_log_string(
                    v55,
                    "ipa-wan %s:%d UL rule idx is wrong: %d\n",
                    "ipa3_copy_ul_filter_rule_to_ipa",
                    980,
                    *(unsigned int *)(v36 + 4 * v35));
                }
                goto LABEL_105;
              }
              if ( v37 > 0x22 )
                goto LABEL_106;
              ++v35;
              *(_BYTE *)(ipa3_qmi_ctx + 216LL * v37 + 213) = 1;
              if ( v35 >= *(unsigned int *)(v26 + 4) )
                goto LABEL_69;
            }
            break;
          }
        }
LABEL_106:
        __break(0x5512u);
        return ipa3_copy_qmi_flt_rule_ex(v17, v18);
      }
    }
    else
    {
      v29 = rmnet_ipa3_ctx;
    }
LABEL_69:
    v38 = 0;
    goto LABEL_70;
  }
  v9 = 0;
  v10 = 0;
  while ( v10 != 35 )
  {
    if ( v3[264] == 1 )
    {
      v11 = ipa3_qmi_ctx;
      v12 = a1 + 13872 + v9;
    }
    else
    {
      if ( *(_BYTE *)v2 != 1 )
        goto LABEL_17;
      v11 = ipa3_qmi_ctx;
      v12 = a1 + 27704 + v9;
    }
    ipa3_copy_qmi_flt_rule_ex(v11 + v9, v12);
LABEL_17:
    ++v10;
    v9 += 216;
    v8 = *(int *)(rmnet_ipa3_ctx + 1036);
    if ( v10 >= v8 )
      goto LABEL_22;
  }
  printk(&unk_3AAC38, "ipa3_copy_ul_filter_rule_to_ipa");
  if ( ipa3_get_ipc_logbuf() )
  {
    v42 = ipa3_get_ipc_logbuf();
    ipc_log_string(v42, "ipa-wan %s:%d Reaching (%d) max cache ", "ipa3_copy_ul_filter_rule_to_ipa", 911, 35);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v43 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v43, "ipa-wan %s:%d Reaching (%d) max cache ", "ipa3_copy_ul_filter_rule_to_ipa", 911, 35);
  }
  printk(&unk_3B09F2, "ipa3_copy_ul_filter_rule_to_ipa");
  if ( ipa3_get_ipc_logbuf() )
  {
    v44 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v44,
      "ipa-wan %s:%d  however total (%d)\n",
      "ipa3_copy_ul_filter_rule_to_ipa",
      913,
      *(_DWORD *)(rmnet_ipa3_ctx + 1036));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v45 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v45,
      "ipa-wan %s:%d  however total (%d)\n",
      "ipa3_copy_ul_filter_rule_to_ipa",
      913,
      *(unsigned int *)(rmnet_ipa3_ctx + 1036));
  }
LABEL_105:
  v29 = rmnet_ipa3_ctx;
  v56 = (void *)ipa3_qmi_ctx;
  *(_DWORD *)(rmnet_ipa3_ctx + 1036) = 0;
  memset(v56, 0, 0x1D88u);
  v38 = -22;
LABEL_70:
  mutex_unlock(v29 + 1136);
  return v38;
}
