__int64 __fastcall cnss_genl_send_msg(__int64 a1, unsigned __int8 a2, const char *a3, unsigned int a4)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v5; // x27
  unsigned int v6; // w26
  const char *v8; // x1
  unsigned int v9; // w22
  const char *v10; // x21
  unsigned int v11; // w9
  int v12; // w19
  bool v13; // cc
  unsigned int v14; // w24
  int v15; // w9
  __int64 v16; // x7
  const char *v17; // x1
  size_t v18; // x0
  unsigned __int64 v19; // x2
  size_t v20; // x0
  __int64 v21; // x0
  _DWORD *v22; // x28
  const char *v23; // x24
  unsigned int v24; // w21
  __int64 v25; // x0
  __int64 v26; // x7
  __int64 v27; // x26
  unsigned int v28; // w0
  __int64 v29; // x3
  __int64 v30; // x0
  unsigned int v31; // w25
  const char *v32; // x1
  const char *v33; // x1
  const char *v34; // x1
  char v36; // [xsp+0h] [xbp-70h]
  char v37; // [xsp+0h] [xbp-70h]
  char v38; // [xsp+0h] [xbp-70h]
  unsigned int v39; // [xsp+24h] [xbp-4Ch]
  int v41; // [xsp+30h] [xbp-40h]
  unsigned int v42; // [xsp+34h] [xbp-3Ch]
  int v43; // [xsp+40h] [xbp-30h]
  unsigned int v45; // [xsp+4Ch] [xbp-24h] BYREF
  char string[8]; // [xsp+50h] [xbp-20h] BYREF
  __int64 v47; // [xsp+58h] [xbp-18h]
  char v48; // [xsp+60h] [xbp-10h]
  __int64 v49; // [xsp+68h] [xbp-8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v5 = _ReadStatusReg(SP_EL0);
  v6 = a4;
  v49 = *(_QWORD *)(StatusReg + 1808);
  if ( (*(_DWORD *)(v5 + 16) & 0xF0000) != 0 )
  {
    v8 = "irq";
  }
  else if ( (*(_DWORD *)(v5 + 16) & 0xFF00) != 0 )
  {
    v8 = "soft_irq";
  }
  else
  {
    v8 = (const char *)(v5 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_long_context,
    v8,
    "cnss_genl_send_msg",
    8u,
    8u,
    "type: %u, total_size: %x\n",
    a2,
    a4,
    v36);
  if ( !v6 )
  {
LABEL_58:
    v31 = 0;
    goto LABEL_65;
  }
  v9 = 0;
  v10 = "cnss_genl_send_data";
  v11 = v6;
  v41 = 0;
  while ( 2 )
  {
    v39 = v11;
    v12 = 1;
    v13 = v11 > 0x3C00;
    if ( v11 >= 0x3C00 )
      v14 = 15360;
    else
      v14 = v11;
    v15 = v41;
    v42 = v14;
    if ( !v13 )
      v15 = 1;
    v41 = v15;
    v43 = (((_WORD)v14 + 7) & 0x7FFC) + 63;
    do
    {
      v48 = 0;
      v17 = "irq";
      *(_QWORD *)string = 0;
      v47 = 0;
      if ( (*(_DWORD *)(v5 + 16) & 0xF0000) == 0 )
      {
        if ( (*(_DWORD *)(v5 + 16) & 0xFF00) != 0 )
          v17 = "soft_irq";
        else
          v17 = (const char *)(v5 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_long_context,
        v17,
        v10,
        8u,
        8u,
        "type: %u, file_name %s, total_size: %x, seg_id %u, end %u, data_len %u\n",
        a2,
        (__int64)a3,
        v6);
      if ( a3 )
      {
        v18 = strnlen(a3, 0x11u);
        if ( v18 == -1 )
          goto LABEL_68;
        if ( v18 == 17 )
          v19 = 17;
        else
          v19 = v18 + 1;
        if ( v19 >= 0x12 )
          goto LABEL_69;
        sized_strscpy(string, a3);
      }
      else
      {
        strcpy(string, "default");
      }
      v20 = strnlen(string, 0x11u);
      if ( v20 >= 0x12 )
        goto LABEL_67;
      if ( v20 == 17 )
      {
LABEL_66:
        v20 = _fortify_panic(4, 17, v20 + 1);
LABEL_67:
        v18 = _fortify_panic(2, 17, v20 + 1);
LABEL_68:
        _fortify_panic(2, -1, v18 + 1);
LABEL_69:
        _fortify_panic(7, 17, v19);
      }
      v21 = _alloc_skb((((v43 + (((_BYTE)v20 + 8) & 0x3C)) & 0x1FFFC) + 19) & 0x3FFFC, 3264, 0, 0xFFFFFFFFLL);
      if ( !v21 )
      {
        v31 = -12;
        goto LABEL_51;
      }
      v22 = (_DWORD *)v21;
      v23 = v10;
      v24 = v6;
      v25 = genlmsg_put(v21, 0, 0, &cnss_genl_family, 0, 1);
      if ( !v25 )
      {
        v31 = -12;
        goto LABEL_46;
      }
      v27 = v25;
      LOBYTE(v45) = a2;
      v28 = nla_put(v22, 1, 1, &v45);
      if ( (v28 & 0x80000000) != 0 )
        goto LABEL_43;
      v20 = strnlen(string, 0x11u);
      if ( v20 >= 0x12 )
        goto LABEL_67;
      if ( v20 == 17 )
        goto LABEL_66;
      v28 = nla_put(v22, 2, (unsigned int)(v20 + 1), string);
      if ( (v28 & 0x80000000) != 0 )
        goto LABEL_43;
      v45 = v24;
      v28 = nla_put(v22, 3, 4, &v45);
      if ( (v28 & 0x80000000) != 0
        || (v45 = v9, v28 = nla_put(v22, 4, 4, &v45), (v28 & 0x80000000) != 0)
        || (LOBYTE(v45) = v41, v28 = nla_put(v22, 5, 1, &v45), (v28 & 0x80000000) != 0)
        || (v45 = v42, v28 = nla_put(v22, 6, 4, &v45), (v28 & 0x80000000) != 0)
        || (v28 = nla_put(v22, 7, v42, a1), (v28 & 0x80000000) != 0) )
      {
LABEL_43:
        v31 = v28;
LABEL_46:
        v32 = "irq";
        v6 = v24;
        if ( (*(_DWORD *)(v5 + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(v5 + 16) & 0xFF00) != 0 )
            v32 = "soft_irq";
          else
            v32 = (const char *)(v5 + 2320);
        }
        v10 = v23;
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v32,
          v23,
          3u,
          3u,
          "Fail to generate genl msg: %d\n",
          v31,
          v26,
          v38);
        sk_skb_reason_drop(0, v22, 2);
        v14 = v42;
        goto LABEL_51;
      }
      *(_DWORD *)(v27 - 20) = v22[54] + v22[52] - (v27 - 20);
      if ( byte_1388 )
      {
        v29 = (unsigned int)dword_13FC;
        v30 = wait_for_completion_killable;
        v22[14] = dword_13FC;
        v6 = v24;
        v10 = v23;
        v14 = v42;
        v31 = netlink_broadcast_filtered(v30, v22, 0, v29, 3264, 0, 0);
        if ( (v31 & 0x80000000) == 0 )
          goto LABEL_57;
      }
      else
      {
        __break(0x800u);
        v6 = v24;
        v10 = v23;
        v14 = v42;
        v31 = -22;
      }
LABEL_51:
      v33 = "irq";
      if ( (*(_DWORD *)(v5 + 16) & 0xF0000) == 0 )
      {
        if ( (*(_DWORD *)(v5 + 16) & 0xFF00) != 0 )
          v33 = "soft_irq";
        else
          v33 = (const char *)(v5 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v33,
        "cnss_genl_send_msg",
        3u,
        3u,
        "Fail to send genl seg_id %d: %d, try %d\n",
        v9,
        v31,
        v12);
      msleep(200);
      ++v12;
    }
    while ( v12 != 11 );
    if ( (v31 & 0x80000000) == 0 )
    {
LABEL_57:
      ++v9;
      v11 = v39 - v14;
      a1 += v14;
      if ( v39 == v14 )
        goto LABEL_58;
      continue;
    }
    break;
  }
  if ( (*(_DWORD *)(v5 + 16) & 0xF0000) != 0 )
  {
    v34 = "irq";
  }
  else if ( (*(_DWORD *)(v5 + 16) & 0xFF00) != 0 )
  {
    v34 = "soft_irq";
  }
  else
  {
    v34 = (const char *)(v5 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v34,
    "cnss_genl_send_msg",
    3u,
    3u,
    "fail to send genl msg, ret %d\n",
    v31,
    v16,
    v37);
LABEL_65:
  _ReadStatusReg(SP_EL0);
  return v31;
}
