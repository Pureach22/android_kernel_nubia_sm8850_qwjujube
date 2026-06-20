__int64 __fastcall cnss_get_fw_files_for_target(int a1, void *dest, unsigned int a3, unsigned int a4)
{
  unsigned __int64 StatusReg; // x8
  const char *v8; // x1
  __int16 v9; // w9
  const char *v10; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !dest )
    return 4294967277LL;
  if ( (a4 | 0x10000) == 0x5030000 )
  {
    memcpy(dest, "qwlan30.bin", 0x8Cu);
  }
  else
  {
    memcpy(dest, "qwlan.bin", 0x8Cu);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v8 = "irq";
    }
    else
    {
      v9 = *(_DWORD *)(StatusReg + 16);
      v10 = (const char *)(StatusReg + 2320);
      if ( (v9 & 0xFF00) != 0 )
        v8 = "soft_irq";
      else
        v8 = v10;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v8,
      "cnss_get_fw_files_for_target",
      3u,
      3u,
      "Unknown target version, type: 0x%X, version: 0x%X",
      a3,
      a4,
      vars0);
  }
  return 0;
}
