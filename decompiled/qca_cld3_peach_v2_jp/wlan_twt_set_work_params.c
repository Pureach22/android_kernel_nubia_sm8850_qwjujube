__int64 __fastcall wlan_twt_set_work_params(__int64 a1, int *a2, unsigned __int8 a3, char a4, int a5)
{
  __int64 comp_private_obj; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int16 v18; // w8
  int v19; // w9
  int v20; // w11

  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0x2Cu);
  if ( !comp_private_obj )
    return qdf_trace_msg(
             0x96u,
             2u,
             "%s: twt vdev private obj is null",
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             "wlan_twt_set_work_params");
  v18 = *((_WORD *)a2 + 2);
  v19 = *a2;
  *(_DWORD *)(comp_private_obj + 16) = a5;
  *(_WORD *)(comp_private_obj + 12) = v18;
  v20 = *(unsigned __int8 *)(comp_private_obj + 13);
  *(_DWORD *)(comp_private_obj + 4) = a3;
  *(_DWORD *)(comp_private_obj + 8) = v19;
  *(_BYTE *)(comp_private_obj + 14) = a4 & 1;
  return qdf_trace_msg(
           0x96u,
           8u,
           "%s: TWT terminate: dialog_id:%d is_ps_disabled:%d next_action:%d peer mac_addr  %02x:%02x:%02x:**:**:%02x",
           v10,
           v11,
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           "wlan_twt_set_work_params",
           BYTE1(v19),
           BYTE2(v19),
           v20);
}
