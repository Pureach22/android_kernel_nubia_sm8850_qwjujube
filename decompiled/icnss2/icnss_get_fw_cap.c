__int64 __fastcall icnss_get_fw_cap(__int64 a1, int a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x20
  const char *v7; // x3

  v2 = *(_QWORD *)(a1 + 152);
  if ( v2 && (v3 = *(_QWORD *)(v2 + 6272)) != 0 )
  {
    if ( a2 )
    {
      printk("%sicnss2: Invalid FW Capability: 0x%x\n", byte_130B32, a2);
      ipc_log_string(icnss_ipc_log_context, "%sicnss2: Invalid FW Capability: 0x%x\n", (const char *)&unk_12DBF3, a2);
      LOBYTE(v6) = 0;
      v7 = "not supported";
    }
    else
    {
      v5 = v3 & 0x10;
      v6 = v5 >> 4;
      if ( v5 )
        v7 = "supported";
      else
        v7 = "not supported";
    }
    ipc_log_string(icnss_ipc_log_context, "icnss2: FW Capability 0x%x is %s\n", a2, v7);
  }
  else
  {
    LOBYTE(v6) = 0;
  }
  return v6 & 1;
}
