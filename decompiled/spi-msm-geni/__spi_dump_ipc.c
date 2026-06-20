void __fastcall _spi_dump_ipc(__int64 a1, const char *a2, __int64 a3, int a4, int a5, int a6)
{
  _QWORD v11[20]; // [xsp+8h] [xbp-148h] BYREF
  _QWORD v12[21]; // [xsp+A8h] [xbp-A8h] BYREF

  v12[20] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v12, 0, 160);
  memset(v11, 0, sizeof(v11));
  hex_dump_to_buffer(a3, a6, 32, 1, v12, 160, 0);
  scnprintf(v11, 160, "%s[%d-%d of %d]: %s", a2, a5 + 1, a6 + a5, a4, (const char *)v12);
  ipc_log_string(*(_QWORD *)(a1 + 480), "%s : %s\n", "__spi_dump_ipc", (const char *)v11);
  if ( *(_QWORD *)(a1 + 200) )
    spi_trace_log();
  _ReadStatusReg(SP_EL0);
}
