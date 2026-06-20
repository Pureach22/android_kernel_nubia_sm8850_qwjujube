__int64 __fastcall mlme_update_tgt_mlo_caps_in_cfg(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x8
  unsigned int v10; // w19
  __int64 psoc_ext_obj_fl; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x9
  int v22; // w8

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2800)) != 0 )
  {
    v10 = *(unsigned __int16 *)(v9 + 428);
    psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
    if ( psoc_ext_obj_fl )
    {
      v21 = *(_QWORD *)(a1 + 2800);
      if ( v21 )
      {
        LOBYTE(v22) = v10;
        if ( !(_BYTE)v10 )
          v22 = *(_DWORD *)(v21 + 428);
        *(_BYTE *)(psoc_ext_obj_fl + 3592) = v22;
        qdf_trace_msg(
          0x1Fu,
          8u,
          "%s: mlo_support_link_num user input %d intersected value :%d",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "wlan_mlme_set_sta_mlo_conn_max_num",
          (unsigned __int8)v10,
          (unsigned __int8)v22);
      }
      else
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: target psoc info is NULL",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "wlan_mlme_set_sta_mlo_conn_max_num");
      }
    }
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Max ML link supported: %u(ML-STA)  %u(ML-SAP)",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "mlme_update_tgt_mlo_caps_in_cfg",
      v10,
      0);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: target psoc info is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "mlme_update_tgt_mlo_caps_in_cfg");
    return 16;
  }
}
