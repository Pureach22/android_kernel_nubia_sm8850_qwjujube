__int64 __fastcall cm_send_bss_select_ind(__int64 *a1, unsigned int *a2)
{
  __int64 v4; // x10
  char v5; // w9
  unsigned int v6; // w6
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x0
  __int64 v16; // x1
  __int64 v17; // x20
  char v18; // w8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  _QWORD v28[38]; // [xsp+0h] [xbp-130h] BYREF

  v28[37] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v28, 0, 0x128u);
  v4 = *((_QWORD *)a2 + 127);
  v5 = *(_BYTE *)(*a1 + 168);
  HIDWORD(v28[0]) = *a2;
  v28[7] = v4;
  LOBYTE(v28[0]) = v5;
  v6 = mlme_cm_bss_select_ind();
  if ( v6 )
  {
    if ( v6 != 11 )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev %d cm_id 0x%x: mlme candidate select indication failed %d",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "cm_send_bss_select_ind",
        LOBYTE(v28[0]),
        *a2);
      v15 = _qdf_mem_malloc(0x150u, "cm_send_bss_select_ind", 2375);
      v6 = 16;
      if ( v15 )
      {
        v16 = *a2;
        *(_DWORD *)(v15 + 52) = 16;
        v17 = v15;
        *(_DWORD *)(v15 + 4) = v16;
        v18 = *(_BYTE *)(*a1 + 168);
        *(_DWORD *)(v15 + 56) = 3;
        *(_BYTE *)v15 = v18;
        cm_fill_bss_info_in_connect_rsp_by_cm_id(a1, v16, v15);
        wlan_sm_dispatch(a1[9], 0xBu, 0x150u, v17, v19, v20, v21, v22, v23, v24, v25, v26);
        _qdf_mem_free(v17);
        v6 = 0;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return v6;
}
