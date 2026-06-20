__int64 __fastcall icnss_aop_pdc_reconfig(__int64 a1)
{
  __int64 v2; // x2
  __int64 v3; // x21
  __int64 v4; // x8
  const char *v5; // x26
  unsigned int v6; // w0
  __int64 result; // x0
  __int64 v8; // x0
  int v9; // w0
  unsigned int v10; // w27
  unsigned int v11; // [xsp+4h] [xbp-1Ch]
  __int64 v12; // [xsp+8h] [xbp-18h] BYREF
  const char *v13; // [xsp+10h] [xbp-10h]
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(int *)(a1 + 5776) >= 1 )
  {
    if ( *(_QWORD *)(a1 + 5768) )
    {
      v2 = *(_QWORD *)(a1 + 304);
      v12 = 0;
      v13 = nullptr;
      ipc_log_string(icnss_ipc_log_context, "Setting PDC defaults for device ID: (0x%lx)\n", v2);
      if ( *(_DWORD *)(a1 + 5776) )
      {
        v3 = 0;
        while ( 1 )
        {
          v4 = *(_QWORD *)(a1 + 5768);
          v5 = *(const char **)(v4 + 8 * v3);
          if ( *(_BYTE *)(a1 + 5760) != 1 )
            break;
          ipc_log_string(icnss_ipc_log_context, "Sending AOP QMP msg: %s\n", *(const char **)(v4 + 8 * v3));
          v6 = qmp_send(*(_QWORD *)(a1 + 5752), v5, 64);
          if ( (v6 & 0x80000000) == 0 )
            goto LABEL_9;
          v11 = v6;
          printk("%sFailed to send AOP QMP msg: %s\n", byte_130B32, v5);
          ipc_log_string(icnss_ipc_log_context, "%sFailed to send AOP QMP msg: %s\n", (const char *)&unk_12DBF3, v5);
          result = v11;
LABEL_10:
          if ( ++v3 >= (unsigned __int64)*(unsigned int *)(a1 + 5776) )
            goto LABEL_14;
        }
        ipc_log_string(icnss_ipc_log_context, "Sending AOP Mbox msg: %s\n", *(const char **)(v4 + 8 * v3));
        v8 = *(_QWORD *)(a1 + 5744);
        LODWORD(v12) = 64;
        v13 = v5;
        v9 = mbox_send_message(v8, &v12);
        if ( v9 < 0 )
        {
          v10 = v9;
          printk("%sFailed to send AOP mbox msg: %s,ret: %d\n", byte_130B32, v5, v9);
          ipc_log_string(
            icnss_ipc_log_context,
            "%sFailed to send AOP mbox msg: %s,ret: %d\n",
            (const char *)&unk_12DBF3,
            v5,
            v10);
          result = v10;
          goto LABEL_10;
        }
LABEL_9:
        result = 0;
        goto LABEL_10;
      }
    }
  }
  result = 0;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
