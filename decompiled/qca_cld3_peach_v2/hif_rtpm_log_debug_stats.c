__int64 __fastcall hif_rtpm_log_debug_stats(__int64 a1, unsigned int a2)
{
  unsigned int v4; // w22
  __int64 v5; // x4
  __int64 v6; // x4
  __int64 v7; // x8
  __int64 i; // x21
  __int64 v9; // x27
  __int64 v10; // x21
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 *j; // x23
  __int64 v15; // x9
  __int64 v16; // x9
  unsigned int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v4 = *(_DWORD *)(gp_hif_rtpm_ctx + 188);
  __isb(0xFu);
  _ReadStatusReg(CNTVCT_EL0);
  hif_rtpm_print(a2, &v18, a1, "%30s: %llu\n", "Current timestamp");
  if ( v4 >= 6 )
  {
LABEL_25:
    __break(0x5512u);
    __break(1u);
  }
  hif_rtpm_print(a2, &v18, a1, "%30s: %s\n", "Runtime PM state");
  hif_rtpm_print(a2, &v18, a1, "%30s: %llu\n", "Last Busy timestamp");
  hif_rtpm_print(a2, &v18, a1, "%30s: %llu\n", "Last resume request timestamp");
  hif_rtpm_print(a2, &v18, a1, "%30s: %llu\n", "Last resume request by");
  hif_rtpm_print(a2, &v18, a1, "%30s: %ps\n", "Last Busy Marker");
  hif_rtpm_print(a2, &v18, a1, "Rx busy marker counts:\n", v5);
  hif_rtpm_print(a2, &v18, a1, "%30s: %u %llu\n", "HIF_RTPM_DP");
  hif_rtpm_print(a2, &v18, a1, "%30s: %u %llu\n", "HIF_RTPM_CE");
  hif_rtpm_print(a2, &v18, a1, "%30s: %u\n", "last_busy_id");
  if ( v4 == 5 )
    hif_rtpm_print(a2, &v18, a1, "%30s: %llx us\n", "Suspended Since");
  hif_rtpm_print(a2, &v18, a1, "%30s: %u\n", "resume_count");
  hif_rtpm_print(a2, &v18, a1, "%30s: %u\n", "suspend_count");
  hif_rtpm_print(a2, &v18, a1, "%30s: %u\n", "suspend_err_count");
  hif_rtpm_print(a2, &v18, a1, "%30s: %d\n", "PM Usage count");
  hif_rtpm_print(a2, &v18, a1, "get  put  get-timestamp put-timestamp :DBGID_NAME\n", v6);
  v7 = gp_hif_rtpm_ctx;
  for ( i = 0; i != 12; ++i )
  {
    v9 = *(_QWORD *)(v7 + 8 * i + 56);
    if ( v9 )
    {
      hif_rtpm_print(a2, &v18, a1, "%-10d ", *(_DWORD *)(v9 + 12));
      hif_rtpm_print(a2, &v18, a1, "%-10d ", *(_DWORD *)(v9 + 16));
      hif_rtpm_print(a2, &v18, a1, "0x%-10llx ", *(_QWORD *)(v9 + 24));
      hif_rtpm_print(a2, &v18, a1, "0x%-10llx ", *(_QWORD *)(v9 + 32));
      if ( i == 11 )
        goto LABEL_25;
      hif_rtpm_print(a2, &v18, a1, ":%-2d %-30s\n", i, hif_rtpm_id_to_string_strings[i]);
      v7 = gp_hif_rtpm_ctx;
    }
  }
  hif_rtpm_print(a2, &v18, a1, "\n");
  v10 = gp_hif_rtpm_ctx;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v10 + 152);
  }
  else
  {
    raw_spin_lock_bh(v10 + 152);
    *(_QWORD *)(v10 + 160) |= 1uLL;
  }
  v12 = gp_hif_rtpm_ctx;
  if ( *(_QWORD *)(gp_hif_rtpm_ctx + 168) == gp_hif_rtpm_ctx + 168 )
  {
    v16 = *(_QWORD *)(gp_hif_rtpm_ctx + 160);
    if ( (v16 & 1) != 0 )
    {
      *(_QWORD *)(gp_hif_rtpm_ctx + 160) = v16 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v12 + 152);
    }
    else
    {
      raw_spin_unlock(gp_hif_rtpm_ctx + 152);
    }
  }
  else
  {
    hif_rtpm_print(a2, &v18, a1, "%30s: ", "Active Wakeup_Sources");
    v13 = gp_hif_rtpm_ctx;
    for ( j = *(__int64 **)(gp_hif_rtpm_ctx + 168); j != (__int64 *)(gp_hif_rtpm_ctx + 168); j = (__int64 *)*j )
    {
      hif_rtpm_print(a2, &v18, a1, "%s", (const char *)j[3]);
      hif_rtpm_print(a2, &v18, a1, " ");
      v13 = gp_hif_rtpm_ctx;
    }
    v15 = *(_QWORD *)(v13 + 160);
    if ( (v15 & 1) != 0 )
    {
      *(_QWORD *)(v13 + 160) = v15 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v13 + 152);
    }
    else
    {
      raw_spin_unlock(v13 + 152);
    }
    hif_rtpm_print(a2, &v18, a1, "\n");
  }
  _ReadStatusReg(SP_EL0);
  return v18;
}
