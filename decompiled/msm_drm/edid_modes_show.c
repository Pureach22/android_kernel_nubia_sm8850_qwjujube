__int64 __fastcall edid_modes_show(int a1, int a2, char *s)
{
  unsigned __int16 *v3; // x8
  __int64 v4; // x0
  unsigned __int64 v5; // x19
  unsigned __int16 v8; // w19
  unsigned __int16 v9; // w19
  __int64 ipc_log_context; // x0
  __int64 v11; // x8
  unsigned __int64 StatusReg; // x21

  v3 = *(unsigned __int16 **)(edid_ctl + 48);
  if ( *v3 && v3[1] )
  {
    v8 = snprintf(s, 0x20u, "%dx%d %d %d\n", *v3, v3[1], v3[2], *((unsigned __int8 *)v3 + 6));
    v9 = snprintf(&s[v8], 0x1000u, "%s", *(const char **)(edid_ctl + 32)) + v8;
    ipc_log_context = get_ipc_log_context();
    v11 = edid_ctl;
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(
      ipc_log_context,
      "[i][%-4d]: selected_edid_mode: %dx%d %d %d\n",
      *(_DWORD *)(StatusReg + 1800),
      **(unsigned __int16 **)(v11 + 48),
      *(unsigned __int16 *)(*(_QWORD *)(v11 + 48) + 2LL),
      *(unsigned __int16 *)(*(_QWORD *)(v11 + 48) + 4LL),
      *(unsigned __int8 *)(*(_QWORD *)(v11 + 48) + 6LL));
    if ( (_drm_debug & 4) != 0 )
      printk(&unk_21CD76, *(unsigned int *)(StatusReg + 1800));
    else
      printk(&unk_248B36, "edid_modes_show");
    return v9;
  }
  else
  {
    v4 = get_ipc_log_context();
    v5 = _ReadStatusReg(SP_EL0);
    ipc_log_string(v4, "[i][%-4d]: edid mode not been initialized\n", *(_DWORD *)(v5 + 1800));
    if ( (_drm_debug & 4) != 0 )
      printk(&unk_256808, *(unsigned int *)(v5 + 1800));
    else
      printk(&unk_22A536, "edid_modes_show");
    return 0;
  }
}
