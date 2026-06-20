__int64 __fastcall target_if_green_ap_egap_status_info_event(__int64 a1, __int64 a2)
{
  __int64 pdev_from_scn_hdl; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 *v12; // x8
  const char *v13; // x2
  __int64 result; // x0
  __int64 v15; // [xsp+8h] [xbp-18h] BYREF
  __int64 v16; // [xsp+10h] [xbp-10h]
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v16 = 0;
  pdev_from_scn_hdl = target_if_get_pdev_from_scn_hdl(a1);
  if ( pdev_from_scn_hdl )
  {
    v12 = *(__int64 **)(pdev_from_scn_hdl + 1240);
    if ( v12 && *v12 )
    {
      if ( !(unsigned int)wmi_extract_green_ap_egap_status_info(*v12, a2, (__int64)&v15) )
      {
        qdf_trace_msg(
          0x5Du,
          8u,
          "%s: mac_id: %d, status: %d, tx_mask: %x, rx_mask: %d",
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          "target_if_green_ap_egap_status_info_event",
          HIDWORD(v15),
          (unsigned int)v15,
          (unsigned int)v16,
          HIDWORD(v16));
        result = 0;
        goto LABEL_9;
      }
      v13 = "%s: unable to extract green ap egap status info";
    }
    else
    {
      v13 = "%s: null wmi_hdl";
    }
  }
  else
  {
    v13 = "%s: pdev is null";
  }
  qdf_trace_msg(0x5Du, 2u, v13, v4, v5, v6, v7, v8, v9, v10, v11, "target_if_green_ap_egap_status_info_event");
  result = 16;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
