__int64 __fastcall wlan_green_ap_get_capab(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 green_ap_tx_ops; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 (__fastcall *v20)(_QWORD); // x8

  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x16u);
  if ( comp_private_obj )
  {
    green_ap_tx_ops = wlan_psoc_get_green_ap_tx_ops(comp_private_obj, v3, v4, v5, v6, v7, v8, v9, v10);
    if ( green_ap_tx_ops )
    {
      v20 = *(__int64 (__fastcall **)(_QWORD))(green_ap_tx_ops + 40);
      if ( v20 )
      {
        if ( *((_DWORD *)v20 - 1) != -2099273483 )
          __break(0x8228u);
        return v20(a1);
      }
      else
      {
        return 0;
      }
    }
    else
    {
      qdf_trace_msg(
        0x5Du,
        2u,
        "%s: green ap tx ops obtained are NULL",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "wlan_green_ap_get_capab");
      return 14;
    }
  }
  else
  {
    qdf_trace_msg(
      0x5Du,
      2u,
      "%s: green ap context obtained is NULL",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_green_ap_get_capab");
    return 16;
  }
}
