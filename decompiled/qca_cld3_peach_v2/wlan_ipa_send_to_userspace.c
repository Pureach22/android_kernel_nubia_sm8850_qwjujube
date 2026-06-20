__int64 __fastcall wlan_ipa_send_to_userspace(char a1)
{
  int v2; // w19
  __int16 v3; // w26
  unsigned int v4; // w25
  _QWORD *v5; // x9
  unsigned __int64 StatusReg; // x28
  _QWORD *v7; // x24
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  const char *v16; // x23
  signed int v17; // w23
  _DWORD *v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // w8
  __int64 v28; // x25
  _WORD *v29; // x0
  __int64 v30; // x19
  int v31; // w0
  int v32; // w23
  __int64 v33; // x23
  signed int v34; // w21
  _DWORD *v35; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int v44; // w8
  __int64 v45; // x20
  _WORD *v46; // x0
  __int64 v47; // x20
  _QWORD *v49[2]; // [xsp+0h] [xbp-10h] BYREF

  v49[1] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v49[0] = nullptr;
  if ( !g_ipa_log_msg )
  {
    v4 = 0;
    goto LABEL_53;
  }
  v2 = 0;
  v3 = 0;
  v4 = 0;
  v5 = &unk_92E000;
  StatusReg = _ReadStatusReg(SP_EL0);
  do
  {
    v7 = v5;
    if ( qdf_list_empty(&qword_92D850) || dword_92E0AC != 1 && (a1 & 1) == 0 )
      break;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(&dword_92D868);
    }
    else
    {
      raw_spin_lock_bh(&dword_92D868);
      qword_92D870 |= 1uLL;
    }
    qdf_list_remove_front(&qword_92D850, v49);
    if ( (qword_92D870 & 1) != 0 )
    {
      qword_92D870 &= ~1uLL;
      raw_spin_unlock_bh(&dword_92D868);
      v16 = (const char *)v49[0];
      if ( v49[0] )
      {
LABEL_14:
        if ( strlen(v16 + 16) + v2 - 2029 > 0xFFFFFFFFFFFFF7FELL )
          goto LABEL_27;
        v17 = (v2 + 23) & 0xFFFFFFFC;
        v18 = (_DWORD *)_netdev_alloc_skb(0, (unsigned int)v17, 2080);
        if ( !v18 )
          goto LABEL_23;
        v27 = v18[29];
        v28 = (__int64)v18;
        ++wlan_ipa_nl_broadcast_nlmsg_seq;
        if ( v27 )
        {
          if ( v17 > 0 )
          {
LABEL_22:
            consume_skb(v28);
LABEL_23:
            v30 = jiffies;
            if ( wlan_ipa_send_to_userspace___last_ticks_16 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x61u,
                2u,
                "%s: nl broadcast failure",
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                v25,
                v26,
                "wlan_ipa_send_to_userspace");
              wlan_ipa_send_to_userspace___last_ticks_16 = v30;
            }
            v4 = 16;
            word_92E098 += v3;
LABEL_26:
            qdf_mem_set(&unk_92D878, 0x800u, 0);
            v16 = (const char *)v49[0];
            v3 = 0;
            v2 = 0;
LABEL_27:
            scnprintf((char *)&g_ipa_logging_ctx + v2 + 64, 2048 - v2, "%s", v16 + 16);
            v32 = v31;
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
              || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(&dword_92D868);
            }
            else
            {
              raw_spin_lock_bh(&dword_92D868);
              qword_92D870 |= 1uLL;
            }
            v2 += v32;
            ++v3;
            qdf_list_insert_back(&g_ipa_logging_ctx, v49[0]);
            if ( (qword_92D870 & 1) != 0 )
            {
              qword_92D870 &= ~1uLL;
              raw_spin_unlock_bh(&dword_92D868);
            }
            else
            {
              raw_spin_unlock(&dword_92D868);
            }
            v5 = v7;
            continue;
          }
        }
        else if ( v18[53] - v18[52] < v17 )
        {
          goto LABEL_22;
        }
        v29 = (_WORD *)_nlmsg_put(v18, 0);
        if ( !v29 )
          goto LABEL_22;
        v29[8] = 0;
        v29[9] = v2;
        qdf_mem_copy(v29 + 10, &unk_92D878, (unsigned int)v2);
        nl_srv_bcast(v28, 7u, 30);
        v4 = 0;
        goto LABEL_26;
      }
    }
    else
    {
      raw_spin_unlock(&dword_92D868);
      v16 = (const char *)v49[0];
      if ( v49[0] )
        goto LABEL_14;
    }
    v33 = jiffies;
    if ( v7[27] - jiffies + 125LL < 0 )
    {
      qdf_trace_msg(
        0x61u,
        2u,
        "%s: log msg freed already",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "wlan_ipa_send_to_userspace");
      v5 = v7;
      v7[27] = v33;
    }
    else
    {
      v5 = v7;
    }
  }
  while ( g_ipa_log_msg );
  if ( v2 < 1 )
    goto LABEL_53;
  v34 = (v2 + 23) & 0xFFFFFFFC;
  v35 = (_DWORD *)_netdev_alloc_skb(0, (unsigned int)v34, 2080);
  if ( !v35 )
    goto LABEL_50;
  v44 = v35[29];
  v45 = (__int64)v35;
  ++wlan_ipa_nl_broadcast_nlmsg_seq;
  if ( !v44 )
  {
    if ( v35[53] - v35[52] < v34 )
      goto LABEL_49;
    goto LABEL_47;
  }
  if ( v34 <= 0 )
  {
LABEL_47:
    v46 = (_WORD *)_nlmsg_put(v35, 0);
    if ( !v46 )
      goto LABEL_49;
    v46[8] = 0;
    v46[9] = v2;
    qdf_mem_copy(v46 + 10, &unk_92D878, (unsigned int)v2);
    nl_srv_bcast(v45, 7u, 30);
    v4 = 0;
    goto LABEL_53;
  }
LABEL_49:
  consume_skb(v45);
LABEL_50:
  v47 = jiffies;
  if ( wlan_ipa_send_to_userspace___last_ticks_19 - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x61u,
      2u,
      "%s: nl broadcast failure",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "wlan_ipa_send_to_userspace");
    wlan_ipa_send_to_userspace___last_ticks_19 = v47;
  }
  v4 = 16;
  word_92E098 += v3;
LABEL_53:
  _ReadStatusReg(SP_EL0);
  return v4;
}
