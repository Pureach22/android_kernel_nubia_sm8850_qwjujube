__int64 __fastcall target_if_mgmt_srng_reap_event_handler(__int64 a1)
{
  __int64 psoc_from_scn_hdl; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x8
  __int64 v12; // x21
  __int64 pdev_from_scn_hdl; // x0
  __int64 v14; // x20
  const char *v15; // x2
  unsigned int v16; // w0
  __int64 result; // x0
  __int64 v18; // [xsp+0h] [xbp-10h] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v15 = "%s: psoc is NULL";
LABEL_9:
    v16 = 165;
    goto LABEL_10;
  }
  v11 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( v11 )
  {
    v12 = *(_QWORD *)(v11 + 16);
    if ( v12 )
    {
      pdev_from_scn_hdl = target_if_get_pdev_from_scn_hdl(a1);
      if ( pdev_from_scn_hdl )
      {
        v14 = pdev_from_scn_hdl;
        if ( !(unsigned int)wmi_unified_extract_mgmt_srng_reap_event(v12) )
        {
          tgt_wlan_mgmt_rx_srng_reap_event(v14, &v18);
          result = 0;
          goto LABEL_11;
        }
        v15 = "%s: Extract mgmt rx srng reap event failed";
      }
      else
      {
        v15 = "%s: pdev is NULL";
      }
      goto LABEL_9;
    }
  }
  v15 = "%s: Invalid WMI handle";
  v16 = 73;
LABEL_10:
  qdf_trace_msg(v16, 2u, v15, v3, v4, v5, v6, v7, v8, v9, v10, "target_if_mgmt_srng_reap_event_handler", v18, v19);
  result = 4294967274LL;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
