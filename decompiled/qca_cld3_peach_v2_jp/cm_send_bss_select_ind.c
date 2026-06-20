__int64 __fastcall cm_send_bss_select_ind(__int64 *a1, unsigned int *a2)
{
  unsigned int v4; // w6
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // x20
  char v16; // w8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned __int8 v26; // [xsp+8h] [xbp-78h]

  _ReadStatusReg(SP_EL0);
  v26 = *(_BYTE *)(*a1 + 104);
  v4 = mlme_cm_bss_select_ind();
  if ( v4 )
  {
    if ( v4 != 11 )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev %d cm_id 0x%x: mlme candidate select indication failed %d",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "cm_send_bss_select_ind",
        v26,
        *a2);
      v13 = _qdf_mem_malloc(0xA0u, "cm_send_bss_select_ind", 2375);
      v4 = 16;
      if ( v13 )
      {
        v14 = *a2;
        *(_DWORD *)(v13 + 52) = 16;
        v15 = v13;
        *(_DWORD *)(v13 + 4) = v14;
        v16 = *(_BYTE *)(*a1 + 104);
        *(_DWORD *)(v13 + 56) = 3;
        *(_BYTE *)v13 = v16;
        cm_fill_bss_info_in_connect_rsp_by_cm_id(a1, v14, v13);
        wlan_sm_dispatch(a1[9], 0xBu, 0xA0u, v15, v17, v18, v19, v20, v21, v22, v23, v24);
        _qdf_mem_free(v15);
        v4 = 0;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return v4;
}
