unsigned __int64 __fastcall icnss_get_smp2p_info(unsigned __int64 result, unsigned int a2)
{
  unsigned __int64 v2; // x8
  unsigned __int64 v3; // x25
  const char *v4; // x19
  unsigned __int64 v5; // x20
  unsigned __int64 v6; // x0
  __int64 v7; // x8
  int v8; // w22
  unsigned __int64 v9; // x0
  __int64 v10; // x8
  int v11; // w22
  unsigned __int64 v12; // x0
  __int64 v13; // x8
  int v14; // w22
  unsigned __int64 v15; // x0
  __int64 v16; // x8
  int v17; // w22
  __int64 v18; // x8

  v2 = result + 16LL * a2;
  if ( !*(_QWORD *)(v2 + 3048) )
  {
    if ( a2 > 2 )
    {
      __break(1u);
      return register_fw_error_notifications(result);
    }
    else
    {
      v3 = v2 + 3040;
      v4 = icnss_smp2p_str[a2];
      v5 = result;
      v6 = qcom_smem_state_get(*(_QWORD *)(result + 8) + 16LL, v4, v2 + 3044);
      v7 = *(_QWORD *)(v5 + 304);
      *(_QWORD *)(v3 + 8) = v6;
      if ( v7 != 25680 && v7 != 26448 && v7 != 30544 && *(_BYTE *)(v5 + 5968) != 1 )
        return ipc_log_string(icnss_ipc_log_context, "icnss2: smem state, Entry: %s", v4);
      if ( v6 && v6 < 0xFFFFFFFFFFFFF001LL )
        return ipc_log_string(icnss_ipc_log_context, "icnss2: smem state, Entry: %s", v4);
      v8 = v6;
      printk("%sicnss2: Failed to get smem state, ret: %d Entry: %s", byte_130B32, v6, v4);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2: Failed to get smem state, ret: %d Entry: %s",
        (const char *)&unk_12DBF3,
        v8,
        v4);
      msleep(500);
      v9 = qcom_smem_state_get(*(_QWORD *)(v5 + 8) + 16LL, v4, v3 + 4);
      v10 = *(_QWORD *)(v5 + 304);
      *(_QWORD *)(v3 + 8) = v9;
      if ( v10 != 25680 && v10 != 26448 && v10 != 30544 && *(_BYTE *)(v5 + 5968) != 1 )
        return ipc_log_string(icnss_ipc_log_context, "icnss2: smem state, Entry: %s", v4);
      if ( v9 && v9 < 0xFFFFFFFFFFFFF001LL )
        return ipc_log_string(icnss_ipc_log_context, "icnss2: smem state, Entry: %s", v4);
      v11 = v9;
      printk("%sicnss2: Failed to get smem state, ret: %d Entry: %s", byte_130B32, v9, v4);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2: Failed to get smem state, ret: %d Entry: %s",
        (const char *)&unk_12DBF3,
        v11,
        v4);
      msleep(500);
      v12 = qcom_smem_state_get(*(_QWORD *)(v5 + 8) + 16LL, v4, v3 + 4);
      v13 = *(_QWORD *)(v5 + 304);
      *(_QWORD *)(v3 + 8) = v12;
      if ( v13 != 25680 && v13 != 26448 && v13 != 30544 && *(_BYTE *)(v5 + 5968) != 1 )
        return ipc_log_string(icnss_ipc_log_context, "icnss2: smem state, Entry: %s", v4);
      if ( v12 && v12 < 0xFFFFFFFFFFFFF001LL )
        return ipc_log_string(icnss_ipc_log_context, "icnss2: smem state, Entry: %s", v4);
      v14 = v12;
      printk("%sicnss2: Failed to get smem state, ret: %d Entry: %s", byte_130B32, v12, v4);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2: Failed to get smem state, ret: %d Entry: %s",
        (const char *)&unk_12DBF3,
        v14,
        v4);
      msleep(500);
      v15 = qcom_smem_state_get(*(_QWORD *)(v5 + 8) + 16LL, v4, v3 + 4);
      v16 = *(_QWORD *)(v5 + 304);
      *(_QWORD *)(v3 + 8) = v15;
      if ( v16 != 25680 && v16 != 26448 && v16 != 30544 && *(_BYTE *)(v5 + 5968) != 1 )
        return ipc_log_string(icnss_ipc_log_context, "icnss2: smem state, Entry: %s", v4);
      if ( v15 && v15 < 0xFFFFFFFFFFFFF001LL )
        return ipc_log_string(icnss_ipc_log_context, "icnss2: smem state, Entry: %s", v4);
      v17 = v15;
      printk("%sicnss2: Failed to get smem state, ret: %d Entry: %s", byte_130B32, v15, v4);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2: Failed to get smem state, ret: %d Entry: %s",
        (const char *)&unk_12DBF3,
        v17,
        v4);
      msleep(500);
      result = qcom_smem_state_get(*(_QWORD *)(v5 + 8) + 16LL, v4, v3 + 4);
      v18 = *(_QWORD *)(v5 + 304);
      *(_QWORD *)(v3 + 8) = result;
      if ( v18 != 25680 && v18 != 26448 && v18 != 30544 && *(_BYTE *)(v5 + 5968) != 1 )
        return ipc_log_string(icnss_ipc_log_context, "icnss2: smem state, Entry: %s", v4);
      if ( result && result <= 0xFFFFFFFFFFFFF000LL )
        return ipc_log_string(icnss_ipc_log_context, "icnss2: smem state, Entry: %s", v4);
    }
  }
  return result;
}
