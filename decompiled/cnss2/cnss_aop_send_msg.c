__int64 __fastcall cnss_aop_send_msg(
        __int64 a1,
        char *s,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v10; // x6
  __int64 v11; // x7
  int v12; // w8
  unsigned __int64 StatusReg; // x22
  int v14; // w23
  int v15; // w8
  const char *v16; // x1
  const char *v17; // x1
  unsigned __int64 v18; // x22
  const char *v19; // x1
  unsigned int v20; // w20
  const char *v21; // x1
  __int64 v22; // x0
  __int64 v23; // x7
  const char *v24; // x1
  unsigned __int64 v25; // x8
  const char *v26; // x1
  __int16 v27; // w9
  const char *v28; // x8
  char v30; // [xsp+0h] [xbp-20h]
  char v31; // [xsp+0h] [xbp-20h]
  char v32; // [xsp+0h] [xbp-20h]
  _QWORD v33[3]; // [xsp+8h] [xbp-18h] BYREF

  v33[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_QWORD *)(a1 + 7640) )
    goto LABEL_11;
  v33[0] = 0;
  v12 = strlen(s) & 0xFFFFFFFC;
  StatusReg = _ReadStatusReg(SP_EL0);
  v14 = v12 + 4;
  v15 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
  if ( v14 >= 65 )
  {
    if ( v15 )
    {
      v16 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v16 = "soft_irq";
    }
    else
    {
      v16 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v16,
      "cnss_mbox_send_msg",
      3u,
      3u,
      "message length greater than max length\n",
      v10,
      v11,
      v30);
LABEL_11:
    if ( *(_QWORD *)(a1 + 7648) )
      goto LABEL_12;
LABEL_35:
    v20 = -19;
LABEL_36:
    v25 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v25 + 16) & 0xF0000) != 0 )
    {
      v26 = "irq";
    }
    else
    {
      v27 = *(_DWORD *)(v25 + 16);
      v28 = (const char *)(v25 + 2320);
      if ( (v27 & 0xFF00) != 0 )
        v26 = "soft_irq";
      else
        v26 = v28;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v26,
      "cnss_aop_send_msg",
      3u,
      3u,
      "Failed to send AOP msg: %d\n",
      v20,
      a8,
      v30);
    goto LABEL_42;
  }
  if ( v15 )
  {
    v17 = "irq";
  }
  else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v17 = "soft_irq";
  }
  else
  {
    v17 = (const char *)(StatusReg + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v17,
    "cnss_mbox_send_msg",
    7u,
    7u,
    "Sending AOP Mbox msg: %s\n",
    (__int64)s,
    v11,
    v30);
  v22 = *(_QWORD *)(a1 + 7640);
  LODWORD(v33[0]) = v14;
  v33[1] = s;
  if ( (mbox_send_message(v22, v33) & 0x80000000) == 0 )
  {
    v20 = 0;
    goto LABEL_42;
  }
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v24 = "irq";
  }
  else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v24 = "soft_irq";
  }
  else
  {
    v24 = (const char *)(StatusReg + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v24,
    "cnss_mbox_send_msg",
    3u,
    3u,
    "Failed to send AOP mbox msg: %s\n",
    (__int64)s,
    v23,
    v32);
  if ( !*(_QWORD *)(a1 + 7648) )
    goto LABEL_35;
LABEL_12:
  v18 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v18 + 16) & 0xF0000) != 0 )
  {
    v19 = "irq";
  }
  else if ( (*(_DWORD *)(v18 + 16) & 0xFF00) != 0 )
  {
    v19 = "soft_irq";
  }
  else
  {
    v19 = (const char *)(v18 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v19,
    "cnss_qmp_send_msg",
    7u,
    7u,
    "Sending AOP QMP msg: %s\n",
    (__int64)s,
    a8,
    v30);
  v20 = qmp_send(*(_QWORD *)(a1 + 7648), s, 64);
  if ( v20 )
  {
    if ( (*(_DWORD *)(v18 + 16) & 0xF0000) != 0 )
    {
      v21 = "irq";
    }
    else if ( (*(_DWORD *)(v18 + 16) & 0xFF00) != 0 )
    {
      v21 = "soft_irq";
    }
    else
    {
      v21 = (const char *)(v18 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v21,
      "cnss_qmp_send_msg",
      3u,
      3u,
      "Failed to send AOP QMP msg: %d[%s]\n",
      v20,
      (__int64)s,
      v31);
    goto LABEL_36;
  }
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return v20;
}
