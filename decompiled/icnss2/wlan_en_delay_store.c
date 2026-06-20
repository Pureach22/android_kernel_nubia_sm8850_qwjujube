__int64 __fastcall wlan_en_delay_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x20
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v7 = 0;
  if ( *(_QWORD *)(v5 + 304) != 43981 )
  {
    if ( sscanf(s, "%du", &v7) == 1 )
    {
      ipc_log_string(icnss_ipc_log_context, "icnss2: WLAN_EN delay: %dms", v7);
      *(_DWORD *)(v5 + 5784) = v7;
    }
    else
    {
      printk("%sicnss2: Failed to read wlan_en_delay", byte_130B32);
      ipc_log_string(icnss_ipc_log_context, "%sicnss2: Failed to read wlan_en_delay", (const char *)&unk_12DBF3);
      a4 = -22;
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
