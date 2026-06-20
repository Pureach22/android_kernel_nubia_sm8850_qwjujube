__int64 __fastcall cnss_minidump_remove_region(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x6
  unsigned __int64 v12; // x21
  const char *v13; // x1
  unsigned __int64 StatusReg; // x8
  const char *v15; // x1
  __int64 v16; // x7
  unsigned int v17; // w19
  const char *v18; // x1
  __int16 v19; // w9
  const char *v20; // x8
  char v22; // [xsp+0h] [xbp-50h]
  char v23; // [xsp+0h] [xbp-50h]
  __int64 v24; // [xsp+10h] [xbp-40h] BYREF
  _QWORD s[2]; // [xsp+18h] [xbp-38h] BYREF
  __int64 v26; // [xsp+28h] [xbp-28h]
  __int64 v27; // [xsp+30h] [xbp-20h]
  __int64 v28; // [xsp+38h] [xbp-18h]
  __int64 v29; // [xsp+40h] [xbp-10h]
  __int64 v30; // [xsp+48h] [xbp-8h]

  v8 = a2;
  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = a5;
  s[0] = 0;
  s[1] = 0;
  v26 = 0;
  if ( a2 >= 3 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else
    {
      v19 = *(_DWORD *)(StatusReg + 16);
      v20 = (const char *)(StatusReg + 2320);
      if ( (v19 & 0xFF00) != 0 )
        v15 = "soft_irq";
      else
        v15 = v20;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v15,
      "cnss_minidump_remove_region",
      3u,
      3u,
      "Unknown dump type ID: %d\n",
      v8,
      a8,
      v22);
    v17 = -22;
  }
  else
  {
    snprintf((char *)s, 0xDu, off_5ADD8[a2], a3);
    v27 = a4;
    v28 = a5;
    v29 = a6;
    v12 = _ReadStatusReg(SP_EL0);
    LODWORD(v26) = 225;
    if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
    {
      v13 = "irq";
    }
    else if ( (*(_DWORD *)(v12 + 16) & 0xFF00) != 0 )
    {
      v13 = "soft_irq";
    }
    else
    {
      v13 = (const char *)(v12 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_long_context,
      v13,
      "cnss_minidump_remove_region",
      7u,
      7u,
      "Remove mini dump region: %s, va: %pK, pa: %pa, size: 0x%zx\n",
      (__int64)s,
      a4,
      (char)&v24);
    v17 = msm_minidump_remove_region(s);
    if ( v17 )
    {
      if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
      {
        v18 = "irq";
      }
      else if ( (*(_DWORD *)(v12 + 16) & 0xFF00) != 0 )
      {
        v18 = "soft_irq";
      }
      else
      {
        v18 = (const char *)(v12 + 2320);
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v18,
        "cnss_minidump_remove_region",
        3u,
        3u,
        "Failed to remove mini dump region, err = %d\n",
        v17,
        v16,
        v23);
    }
  }
  _ReadStatusReg(SP_EL0);
  return v17;
}
