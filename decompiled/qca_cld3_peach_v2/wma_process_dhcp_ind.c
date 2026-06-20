void __fastcall wma_process_dhcp_ind(__int64 *a1, unsigned __int16 *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2
  const char *v13; // x4
  int v14; // w10
  __int64 v15; // x0
  bool v16; // zf
  int v17; // w10
  int v18; // w8
  _DWORD v19[6]; // [xsp+1Ch] [xbp-24h] BYREF
  unsigned __int8 v20[4]; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+38h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  v19[0] = 0;
  if ( !(unsigned int)_wma_validate_handle(a1, "wma_process_dhcp_ind") )
  {
    if ( !a2 )
    {
      v12 = "%s: DHCP indication is NULL";
      goto LABEL_6;
    }
    if ( (unsigned int)wma_find_vdev_id_by_addr((__int64)a1, (__int64)a2 + 5, v20) )
    {
      v12 = "%s: Failed to find vdev id for DHCP indication";
LABEL_6:
      qdf_trace_msg(0x36u, 2u, v12, v4, v5, v6, v7, v8, v9, v10, v11, "wma_process_dhcp_ind");
      goto LABEL_14;
    }
    if ( *a2 == 4276 )
      v13 = "WMA_DHCP_START_IND";
    else
      v13 = "WMA_DHCP_STOP_IND";
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: WMA --> WMI_PEER_SET_PARAM triggered by DHCP, msgType=%s, device_mode=%d, macAddr=%02x:%02x:%02x:**:**:%02x",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "wma_process_dhcp_ind",
      v13,
      *((unsigned __int8 *)a2 + 4),
      *((unsigned __int8 *)a2 + 11),
      *((unsigned __int8 *)a2 + 12),
      *((unsigned __int8 *)a2 + 13),
      *((unsigned __int8 *)a2 + 16));
    v14 = *(_DWORD *)((char *)a2 + 11);
    v15 = *a1;
    v16 = *a2 == 4276;
    v19[1] = v20[0];
    v19[2] = v14;
    v17 = *(unsigned __int16 *)((char *)a2 + 15);
    v18 = v16;
    v19[4] = 9;
    v19[5] = v18;
    v19[3] = v17;
    wmi_unified_process_dhcp_ind(v15, v19);
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
}
