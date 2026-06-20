__int64 __fastcall icnss_update_cpr_info(__int64 a1)
{
  const char *v1; // x3
  unsigned int v3; // w6
  unsigned int v4; // w0
  unsigned int v5; // w20
  __int64 result; // x0
  __int64 v7; // x0
  int v8; // w0
  unsigned int v9; // w19
  _QWORD v10[2]; // [xsp+8h] [xbp-58h] BYREF
  char s[8]; // [xsp+18h] [xbp-48h] BYREF
  __int64 v12; // [xsp+20h] [xbp-40h]
  __int64 v13; // [xsp+28h] [xbp-38h]
  __int64 v14; // [xsp+30h] [xbp-30h]
  __int64 v15; // [xsp+38h] [xbp-28h]
  __int64 v16; // [xsp+40h] [xbp-20h]
  __int64 v17; // [xsp+48h] [xbp-18h]
  __int64 v18; // [xsp+50h] [xbp-10h]
  __int64 v19; // [xsp+58h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(const char **)(a1 + 288);
  if ( !v1 || !*(_QWORD *)(a1 + 5744) && (*(_BYTE *)(a1 + 5760) & 1) == 0 )
  {
    ipc_log_string(icnss_ipc_log_context, "Mbox channel / QMP / OL CPR Vreg not configured\n");
    goto LABEL_14;
  }
  v3 = *(_DWORD *)(a1 + 296);
  if ( !v3 )
  {
    printk("%sVoltage %dmV is not valid\n", byte_130B32, 0);
    ipc_log_string(
      icnss_ipc_log_context,
      "%sVoltage %dmV is not valid\n",
      (const char *)&unk_12DBF3,
      *(_DWORD *)(a1 + 296));
    result = 4294967274LL;
    goto LABEL_15;
  }
  if ( *(_QWORD *)(a1 + 304) != 25680 )
  {
    if ( v3 <= 0x384 )
      v3 = 900;
    *(_DWORD *)(a1 + 296) = v3;
  }
  v10[0] = 64;
  *(_QWORD *)s = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  snprintf(s, 0x40u, "{class: wlan_pdc, res: %s.%s, %s: %d}", v1, "v", "upval", v3);
  if ( *(_BYTE *)(a1 + 5760) != 1 )
  {
    ipc_log_string(icnss_ipc_log_context, "Sending AOP Mbox msg: %s\n", s);
    v7 = *(_QWORD *)(a1 + 5744);
    v10[1] = s;
    v8 = mbox_send_message(v7, v10);
    if ( v8 < 0 )
    {
      v9 = v8;
      printk("%sFailed to send AOP mbox msg: %s,ret: %d\n", byte_130B32, s, v8);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sFailed to send AOP mbox msg: %s,ret: %d\n",
        (const char *)&unk_12DBF3,
        s,
        v9);
      result = v9;
      goto LABEL_15;
    }
    goto LABEL_14;
  }
  ipc_log_string(icnss_ipc_log_context, "Sending AOP QMP msg: %s\n", s);
  v4 = qmp_send(*(_QWORD *)(a1 + 5752), s, 64);
  if ( (v4 & 0x80000000) == 0 )
  {
LABEL_14:
    result = 0;
    goto LABEL_15;
  }
  v5 = v4;
  printk("%sFailed to send AOP QMP msg: %s\n", byte_130B32, s);
  ipc_log_string(icnss_ipc_log_context, "%sFailed to send AOP QMP msg: %s\n", (const char *)&unk_12DBF3, s);
  result = v5;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
