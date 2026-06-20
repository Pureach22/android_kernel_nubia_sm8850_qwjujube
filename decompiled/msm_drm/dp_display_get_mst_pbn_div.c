unsigned __int64 __fastcall dp_display_get_mst_pbn_div(__int64 a1)
{
  __int64 v2; // x0

  if ( a1 )
    return *(_DWORD *)(*(_QWORD *)(a1 - 1000) + 128LL)
         * (unsigned int)drm_dp_bw_code_to_link_rate(*(unsigned int *)(*(_QWORD *)(a1 - 1000) + 132LL))
         / 0xD2F0uLL;
  if ( !g_dp_display || (v2 = *(_QWORD *)(g_dp_display + 56)) == 0 )
    v2 = 0;
  ipc_log_string(v2, "[e][%-4d]invalid params\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
  printk(&unk_24B695, "dp_display_get_mst_pbn_div");
  return 0;
}
