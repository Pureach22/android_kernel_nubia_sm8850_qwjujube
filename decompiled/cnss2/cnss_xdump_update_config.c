__int64 __fastcall cnss_xdump_update_config(_BYTE *a1)
{
  char v1; // w8
  unsigned int v2; // w10
  __int64 v3; // x6
  unsigned int v4; // w10
  __int64 v5; // x7
  unsigned __int64 StatusReg; // x10
  const char *v7; // x1
  __int16 v8; // w11
  const char *v9; // x10

  v1 = a1[7952];
  if ( (v1 & 2) != 0 && (~(unsigned __int8)a1[7954] & 3) == 0 && (v2 = (unsigned __int8)a1[7953], (v2 & 1) != 0) )
  {
    v3 = (v2 >> 1) & 1;
    a1[7955] = (v2 & 2) != 0;
    if ( (v1 & 4) == 0 )
      goto LABEL_9;
  }
  else
  {
    v3 = 0;
    a1[7955] = 0;
    if ( (v1 & 4) == 0 )
      goto LABEL_9;
  }
  if ( (~(unsigned __int8)a1[7954] & 5) == 0 )
  {
    v4 = (unsigned __int8)a1[7953];
    if ( (v4 & 1) != 0 )
    {
      v5 = (v4 >> 2) & 1;
      goto LABEL_10;
    }
  }
LABEL_9:
  v5 = 0;
LABEL_10:
  a1[7956] = v5;
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v7 = "irq";
  }
  else
  {
    v8 = *(_DWORD *)(StatusReg + 16);
    v9 = (const char *)(StatusReg + 2320);
    if ( (v8 & 0xFF00) != 0 )
      v7 = "soft_irq";
    else
      v7 = v9;
  }
  return cnss_debug_ipc_log_print(
           cnss_ipc_log_context,
           v7,
           "cnss_xdump_update_config",
           6u,
           6u,
           "XDUMP(%d - %d): wl_cap(%d: %d - %d) bt_cap(%d: %d - %d) user_cap(%d: %d - %d)\n",
           v3,
           v5,
           a1[7953] & 1);
}
