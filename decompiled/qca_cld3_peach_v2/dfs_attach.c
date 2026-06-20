__int64 __fastcall dfs_attach(__int64 a1)
{
  unsigned int v2; // w20

  dfs_nol_attach();
  *(_QWORD *)(a1 + 208) = dfs_testtimer_task;
  *(_QWORD *)(a1 + 216) = a1;
  init_timer_key(a1 + 168, _os_timer_shim_16, 0, 0, 0);
  v2 = wlan_mlme_get_sap_dfs_puncture(**(_QWORD **)(a1 + 14944)) & 1;
  dfs_set_nol_subchannel_marking(a1, v2);
  *(_BYTE *)(a1 + 15001) = v2;
  return 0;
}
