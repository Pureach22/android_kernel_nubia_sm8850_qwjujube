__int64 __fastcall spss_attach(__int64 a1)
{
  _QWORD *v2; // x19
  int v3; // w21
  int v4; // w22
  int v5; // w23
  int v6; // w25
  unsigned int v7; // w24
  __int64 v8; // x8
  __int64 v9; // x21
  const char *v10; // x3
  unsigned int v11; // w0
  int v12; // w21
  int v13; // w0
  int v14; // w0
  __int64 result; // x0
  unsigned int v16; // w26
  __int64 v17; // x20
  const char *v18; // x3
  unsigned int v19; // w19
  __int64 v20; // x8
  char s[8]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v22; // [xsp+10h] [xbp-40h]
  __int64 v23; // [xsp+18h] [xbp-38h]
  __int64 v24; // [xsp+20h] [xbp-30h]
  __int64 v25; // [xsp+28h] [xbp-28h]
  __int64 v26; // [xsp+30h] [xbp-20h]
  __int64 v27; // [xsp+38h] [xbp-18h]
  __int64 v28; // [xsp+40h] [xbp-10h]
  __int64 v29; // [xsp+48h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(a1 + 40);
  v3 = *(_DWORD *)v2[51];
  v4 = *(_DWORD *)(v2[51] - 4LL);
  v5 = *(_DWORD *)(v2[51] - 8LL);
  v6 = *(_DWORD *)v2[47];
  v7 = *(_DWORD *)v2[50];
  if ( HIBYTE(v7) == 239 )
  {
    dev_err(*v2, "PBL error detected\n");
    v16 = v7;
LABEL_18:
    dev_err(*v2, "irq_status: 0x%08x, err_ready: 0x%08lx\n", v6, 1LL << *((_DWORD *)v2 + 106));
    dev_err(
      *v2,
      "PBL error status register: 0x%08x, spare0 register: 0x%08x, spare1 register: 0x%08x, spare2 register: 0x%08x\n",
      v7,
      v5,
      v4,
      v3);
    dev_err(*v2, "Failed to attach SPSS remote proc and shutdown\n");
    spss_stop(a1);
    result = v16;
    goto LABEL_15;
  }
  v8 = 1LL << *((_DWORD *)v2 + 106);
  if ( ((unsigned int)v8 & *(_DWORD *)v2[47]) != 0 && v3 == 1146441040 )
  {
    dev_err(*v2, "wdog bite is pending\n");
    v16 = 0;
    *(_DWORD *)v2[48] = 1LL << *((_DWORD *)v2 + 106);
    goto LABEL_18;
  }
  v9 = v2[18];
  if ( v9 )
  {
    v10 = (const char *)v2[17];
    v27 = 0;
    v28 = 0;
    v25 = 0;
    v26 = 0;
    v23 = 0;
    v24 = 0;
    *(_QWORD *)s = 0;
    v22 = 0;
    snprintf(s, 0x40u, "{class: image, res: load_state, name: %s, val: %s}", v10, "on");
    v11 = qmp_send(v9, s, 64);
    if ( v11 )
    {
      v20 = *v2;
      v19 = v11;
      dev_err(v20, "Failed to signal AOP about spss status [%d]\n", v11);
      spss_stop(a1);
      goto LABEL_24;
    }
    v8 = 1LL << *((_DWORD *)v2 + 106);
  }
  *(_DWORD *)v2[49] = ~((1LL << *((_DWORD *)v2 + 107)) | v8);
  v12 = wait_for_completion_timeout(v2 + 8, 1250);
  read_sp2cl_debug_registers(v2);
  v13 = spss_enable_regulator(v2, v2 + 5);
  if ( v13 )
    dev_err(*v2, "Failed to enable sensors regulator [%d]\n", v13);
  v14 = spss_disable_regulator(v2, v2 + 5);
  if ( v14 )
    dev_err(*v2, "Failed to disable sensors regulator [%d]\n", v14);
  if ( *(_BYTE *)(a1 + 1204) == 1 && !v12 )
  {
    dev_err(*v2, "%d ms timeout poked\n", 5000);
    dev_err(*v2, "%s attach timed out\n", *(const char **)(a1 + 24));
LABEL_21:
    v17 = v2[18];
    result = 4294967186LL;
    if ( !v17 )
      goto LABEL_15;
    v18 = (const char *)v2[17];
    v19 = -110;
    v27 = 0;
    v28 = 0;
    v25 = 0;
    v26 = 0;
    v23 = 0;
    v24 = 0;
    *(_QWORD *)s = 0;
    v22 = 0;
    snprintf(s, 0x40u, "{class: image, res: load_state, name: %s, val: %s}", v18, "off");
    qmp_send(v17, s, 64);
LABEL_24:
    result = v19;
    goto LABEL_15;
  }
  if ( !v12 )
  {
    dev_err(*v2, "recovery disabled (after timeout)\n");
    goto LABEL_21;
  }
  result = 0;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
