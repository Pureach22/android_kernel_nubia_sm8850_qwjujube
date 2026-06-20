__int64 __fastcall cm_send_connect_start_fail(__int64 *a1, unsigned int *a2, int a3)
{
  __int64 v6; // x0
  __int64 v7; // x19
  __int64 v8; // x1
  char v9; // w8
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  unsigned int v18; // w20

  v6 = _qdf_mem_malloc(0x150u, "cm_send_connect_start_fail", 337);
  if ( v6 )
  {
    v7 = v6;
    wlan_connectivity_connecting_event(*a1, a2 + 2);
    v8 = *a2;
    *(_DWORD *)(v7 + 52) = 16;
    *(_DWORD *)(v7 + 4) = v8;
    v9 = *(_BYTE *)(*a1 + 168);
    *(_DWORD *)(v7 + 56) = a3;
    *(_BYTE *)v7 = v9;
    cm_fill_bss_info_in_connect_rsp_by_cm_id(a1, v8, v7);
    v18 = wlan_sm_dispatch(a1[9], 0xCu, 0x150u, v7, v10, v11, v12, v13, v14, v15, v16, v17);
    _qdf_mem_free(v7);
  }
  else
  {
    return 2;
  }
  return v18;
}
