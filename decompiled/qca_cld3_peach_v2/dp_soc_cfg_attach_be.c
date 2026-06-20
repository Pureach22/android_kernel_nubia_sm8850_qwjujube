__int64 __fastcall dp_soc_cfg_attach_be(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  __int64 v4; // x10

  v1 = *(_QWORD *)(a1 + 40);
  dp_soc_cfg_attach();
  result = wlan_cfg_set_rx_rel_ring_id(v1, 3);
  *(_QWORD *)(*(_QWORD *)(a1 + 40) + 776LL) = &g_tcl_wbm_map_array;
  v4 = *(_QWORD *)(a1 + 40);
  *(_BYTE *)(a1 + 20121) = 1;
  *(_BYTE *)(a1 + 7202) = 0;
  *(_BYTE *)(v4 + 812) = 1;
  return result;
}
