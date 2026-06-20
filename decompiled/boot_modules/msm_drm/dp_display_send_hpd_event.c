__int64 __fastcall dp_display_send_hpd_event(__int64 a1)
{
  __int64 *v1; // x21
  __int64 v2; // x0
  void *v3; // x0
  __int64 result; // x0
  int v6; // w8
  __int64 v7; // x0
  unsigned __int64 StatusReg; // x19
  __int64 v9; // x20
  const char *connector_status_name; // x0
  int v11; // w8
  int v12; // w3
  __int64 v13; // x0
  unsigned __int64 v14; // x21
  __int64 v15; // x8
  int v16; // w19
  __int64 v17; // x0
  const char *v18; // x20
  char *v19; // [xsp+0h] [xbp-B0h] BYREF
  char *v20; // [xsp+8h] [xbp-A8h]
  char *v21; // [xsp+10h] [xbp-A0h]
  _QWORD *v22; // [xsp+18h] [xbp-98h]
  __int64 v23; // [xsp+20h] [xbp-90h]
  _QWORD v24[4]; // [xsp+28h] [xbp-88h] BYREF
  char v25[8]; // [xsp+48h] [xbp-68h] BYREF
  __int64 v26; // [xsp+50h] [xbp-60h]
  _WORD v27[7]; // [xsp+58h] [xbp-58h] BYREF
  char v28[8]; // [xsp+68h] [xbp-48h] BYREF
  __int64 v29; // [xsp+70h] [xbp-40h]
  _WORD v30[7]; // [xsp+78h] [xbp-38h] BYREF
  char s[8]; // [xsp+88h] [xbp-28h] BYREF
  __int64 v32; // [xsp+90h] [xbp-20h]
  _WORD v33[7]; // [xsp+98h] [xbp-18h] BYREF
  __int64 v34; // [xsp+A8h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(__int64 **)(a1 + 1184);
  v32 = 0;
  memset(v33, 0, sizeof(v33));
  *(_QWORD *)s = 0;
  v29 = 0;
  memset(v30, 0, sizeof(v30));
  *(_QWORD *)v28 = 0;
  v26 = 0;
  memset(v27, 0, sizeof(v27));
  *(_QWORD *)v25 = 0;
  v23 = 0;
  memset(v24, 0, 30);
  v21 = nullptr;
  v22 = nullptr;
  v19 = nullptr;
  v20 = nullptr;
  if ( !v1 )
  {
    if ( !g_dp_display || (v2 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v2 = 0;
    ipc_log_string(v2, "[e][%-4d]connector not set\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    v3 = &unk_21C722;
LABEL_6:
    printk(v3, "dp_display_send_hpd_event");
    result = 0;
    goto LABEL_40;
  }
  if ( *(_BYTE *)(a1 + 1200) )
    v6 = 1;
  else
    v6 = 2;
  *((_DWORD *)v1 + 48) = v6;
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 192) + 13LL) == 1 )
  {
    if ( !g_dp_display || (v7 = *(_QWORD *)(g_dp_display + 56)) == 0 )
      v7 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(v7, "[i][%-4d]skipping uevent\n", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
    {
      printk(&unk_245415, *(unsigned int *)(StatusReg + 1800));
      result = 0;
      goto LABEL_40;
    }
    v3 = &unk_2487BD;
    goto LABEL_6;
  }
  v9 = *v1;
  snprintf(s, 0x1Eu, "name=%s", (const char *)v1[12]);
  connector_status_name = (const char *)drm_get_connector_status_name(*((unsigned int *)v1 + 48));
  snprintf(v28, 0x1Eu, "status=%s", connector_status_name);
  v11 = *(_DWORD *)(*(_QWORD *)(a1 + 168) + 20LL);
  if ( v11 )
  {
    if ( v11 == 64 )
    {
      v12 = 30;
    }
    else if ( v11 == 32 )
    {
      v12 = 24;
    }
    else
    {
      v12 = 0;
    }
  }
  else
  {
    v12 = 18;
  }
  snprintf(v25, 0x1Eu, "bpp=%d", v12);
  snprintf((char *)v24, 0x1Eu, "pattern=%d", *(_DWORD *)(*(_QWORD *)(a1 + 168) + 16LL));
  if ( !g_dp_display || (v13 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v13 = 0;
  v14 = _ReadStatusReg(SP_EL0);
  ipc_log_string(v13, "[i][%-4d][%s]:[%s] [%s] [%s]\n", *(_DWORD *)(v14 + 1800), s, v28, v25, (const char *)v24);
  if ( (_drm_debug & 4) != 0 )
    printk(&unk_261660, *(unsigned int *)(v14 + 1800));
  else
    printk(&unk_211678, "dp_display_send_hpd_event");
  v20 = v28;
  v21 = v25;
  v22 = v24;
  v23 = 0;
  v15 = *(_QWORD *)(v9 + 64);
  v19 = s;
  v16 = kobject_uevent_env(*(_QWORD *)(v15 + 8), 2, &v19);
  if ( !g_dp_display || (v17 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v17 = 0;
  if ( v16 )
    v18 = "failure";
  else
    v18 = "success";
  ipc_log_string(v17, "[i][%-4d]uevent %s: %d\n", *(_DWORD *)(v14 + 1800), v18, v16);
  if ( (_drm_debug & 4) != 0 )
    printk(&unk_267F59, *(unsigned int *)(v14 + 1800));
  else
    printk(&unk_259E3A, "dp_display_send_hpd_event");
  result = 1;
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}
