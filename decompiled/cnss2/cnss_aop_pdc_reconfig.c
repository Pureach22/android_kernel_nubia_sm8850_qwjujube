__int64 __fastcall cnss_aop_pdc_reconfig(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v9; // x25
  const char *v11; // x1
  __int64 v12; // x7
  const char *v13; // x1
  unsigned __int64 v14; // x27
  unsigned int v15; // w20
  __int64 v16; // x8
  const char *v17; // x23
  __int64 v18; // x7
  const char *v19; // x1
  char v21; // [xsp+0h] [xbp-50h]
  char v22; // [xsp+0h] [xbp-50h]
  char v23; // [xsp+0h] [xbp-50h]
  char s[8]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v25; // [xsp+10h] [xbp-40h]
  __int64 v26; // [xsp+18h] [xbp-38h]
  __int64 v27; // [xsp+20h] [xbp-30h]
  __int64 v28; // [xsp+28h] [xbp-28h]
  __int64 v29; // [xsp+30h] [xbp-20h]
  __int64 v30; // [xsp+38h] [xbp-18h]
  __int64 v31; // [xsp+40h] [xbp-10h]
  __int64 v32; // [xsp+48h] [xbp-8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v9 = _ReadStatusReg(SP_EL0);
  v32 = *(_QWORD *)(StatusReg + 1808);
  if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
  {
    v11 = "irq";
  }
  else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
  {
    v11 = "soft_irq";
  }
  else
  {
    v11 = (const char *)(v9 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v11,
    "cnss_aop_pdc_reconfig",
    7u,
    7u,
    "PDC init table length: %d\n",
    *(unsigned int *)(a1 + 7696),
    a8,
    v21);
  if ( *(int *)(a1 + 7696) >= 1
    && *(_QWORD *)(a1 + 7672)
    && ((*(_DWORD *)(v9 + 16) & 0xF0000) == 0
      ? ((*(_DWORD *)(v9 + 16) & 0xFF00) != 0
       ? (v13 = "soft_irq")
       : (v13 = (const char *)(v9 + 2320)))
      : (v13 = "irq"),
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v13,
          "cnss_aop_pdc_reconfig",
          7u,
          7u,
          "Setting PDC defaults for device ID: %d\n",
          *(_QWORD *)(a1 + 528),
          v12,
          v22),
        *(_DWORD *)(a1 + 7696)) )
  {
    v14 = 0;
    v15 = 0;
    do
    {
      v16 = *(_QWORD *)(a1 + 7672);
      v30 = 0;
      v31 = 0;
      v28 = 0;
      v29 = 0;
      v26 = 0;
      v27 = 0;
      *(_QWORD *)s = 0;
      v25 = 0;
      v17 = *(const char **)(v16 + 8 * v14);
      if ( strlen(v17) < 0x41 )
      {
        snprintf(s, 0x40u, v17);
        v15 = cnss_aop_send_msg(a1, s);
        if ( (v15 & 0x80000000) != 0 )
          break;
      }
      else
      {
        v19 = "irq";
        if ( (*(_DWORD *)(v9 + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
            v19 = "soft_irq";
          else
            v19 = (const char *)(v9 + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v19,
          "cnss_aop_pdc_reconfig",
          3u,
          3u,
          "msg too long: %s\n",
          (__int64)v17,
          v18,
          v23);
      }
      ++v14;
    }
    while ( v14 < *(unsigned int *)(a1 + 7696) );
  }
  else
  {
    v15 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v15;
}
