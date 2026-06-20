__int64 __fastcall dp_mst_display_hpd(__int64 a1, char a2)
{
  __int64 v3; // x8
  __int64 v4; // x8
  const char *v5; // x9
  __int64 v6; // x10
  __int64 *v7; // x10
  __int64 v8; // x9
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x20
  int v13; // w7
  __int64 result; // x0
  char v15[8]; // [xsp+0h] [xbp-50h] BYREF
  _QWORD *v16; // [xsp+8h] [xbp-48h]
  __int64 v17; // [xsp+10h] [xbp-40h]
  _QWORD v18[2]; // [xsp+18h] [xbp-38h] BYREF
  _BYTE v19[14]; // [xsp+28h] [xbp-28h] BYREF
  char v20[16]; // [xsp+38h] [xbp-18h] BYREF
  __int64 v21; // [xsp+48h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 40);
  if ( (a2 & 1) != 0 )
  {
    v4 = **(_QWORD **)(v3 + 4120);
    strcpy(v20, "HOTPLUG=1");
    v5 = "status=connected";
    v6 = *(_QWORD *)"status=connected";
    *(_QWORD *)&v19[1] = 0;
    *(_QWORD *)&v19[6] = 0;
    v19[0] = 0;
  }
  else
  {
    v7 = *(__int64 **)(v3 + 4120);
    *(_BYTE *)(v3 + 4236) = 0;
    v4 = *v7;
    *(_QWORD *)&v19[4] = 0;
    strcpy(v19, "ted");
    v5 = "status=disconnected";
    v6 = *(_QWORD *)"status=disconnected";
    strcpy(v20, "HOTPLUG=1");
    *(_WORD *)&v19[12] = 0;
  }
  v8 = *((_QWORD *)v5 + 1);
  v9 = *(_QWORD *)(v4 + 64);
  v18[0] = v6;
  v18[1] = v8;
  v16 = v18;
  v17 = 0;
  v10 = *(_QWORD *)(v9 + 8);
  *(_QWORD *)v15 = v20;
  kobject_uevent_env(v10, 2, v15);
  ipc_log_context = get_ipc_log_context();
  StatusReg = _ReadStatusReg(SP_EL0);
  ipc_log_string(
    ipc_log_context,
    "[i][%-4d]%s finished. hpd_status:%d\n",
    *(_DWORD *)(StatusReg + 1800),
    "dp_mst_hpd_event_notify",
    a2 & 1);
  if ( (_drm_debug & 4) != 0 )
    printk(&unk_23B446, *(unsigned int *)(StatusReg + 1800));
  else
    printk(&unk_26FAB3, "dp_mst_hpd_event_notify");
  result = sde_evtlog_log(
             sde_dbg_base_evtlog,
             "dp_mst_hpd_event_notify",
             2085,
             8,
             8738,
             a2 & 1,
             -1059143953,
             v13,
             v15[0]);
  _ReadStatusReg(SP_EL0);
  return result;
}
