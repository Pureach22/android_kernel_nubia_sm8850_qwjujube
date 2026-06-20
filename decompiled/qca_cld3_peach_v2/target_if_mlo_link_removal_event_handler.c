__int64 __fastcall target_if_mlo_link_removal_event_handler(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 psoc_from_scn_hdl; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x23
  __int64 v21; // x8
  __int64 v22; // x22
  __int64 v23; // x21
  unsigned int v24; // w0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w20
  const char *v34; // x2
  const char *v35; // x2
  __int64 result; // x0
  unsigned int mlo_link_removal_tbtt_update; // w0
  __int64 (__fastcall *v38)(__int64, __int64 *); // x8
  __int64 v39; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v40[4]; // [xsp+10h] [xbp-20h] BYREF

  v40[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39 = 0;
  memset(v40, 0, 24);
  if ( a1 && a2 )
  {
    psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
    if ( psoc_from_scn_hdl )
    {
      v20 = *(_QWORD *)(psoc_from_scn_hdl + 2136);
      if ( v20 )
      {
        if ( *(_QWORD *)(v20 + 1248) )
        {
          v21 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
          if ( v21 )
          {
            v22 = *(_QWORD *)(v21 + 16);
            if ( v22 )
            {
              v23 = psoc_from_scn_hdl;
              v24 = wmi_extract_mlo_link_removal_evt_fixed_param(*(_QWORD *)(v21 + 16), a2, &v39);
              if ( v24 )
              {
                v33 = v24;
                v34 = "%s: Unable to extract fixed param, ret = %d";
              }
              else
              {
                mlo_link_removal_tbtt_update = wmi_extract_mlo_link_removal_tbtt_update(v22, a2, v40);
                if ( !mlo_link_removal_tbtt_update )
                {
                  v38 = *(__int64 (__fastcall **)(__int64, __int64 *))(v20 + 1248);
                  if ( *((_DWORD *)v38 - 1) != 484739362 )
                    __break(0x8228u);
                  v33 = v38(v23, &v39);
                  goto LABEL_21;
                }
                v33 = mlo_link_removal_tbtt_update;
                v34 = "%s: Unable to extract TBTT update TLV, ret = %d";
              }
              qdf_trace_msg(
                0x49u,
                2u,
                v34,
                v25,
                v26,
                v27,
                v28,
                v29,
                v30,
                v31,
                v32,
                "target_if_mlo_link_removal_event_handler",
                v33);
LABEL_21:
              result = qdf_status_to_os_return(v33);
              goto LABEL_17;
            }
          }
          v35 = "%s: wmi_handle is null";
          goto LABEL_15;
        }
      }
      else
      {
        qdf_trace_msg(
          0x49u,
          2u,
          "%s: rx_ops is NULL",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "target_if_mlo_get_rx_ops");
      }
      v35 = "%s: callback not registered";
    }
    else
    {
      v35 = "%s: null psoc";
    }
LABEL_15:
    qdf_trace_msg(0x49u, 2u, v35, v12, v13, v14, v15, v16, v17, v18, v19, "target_if_mlo_link_removal_event_handler");
    goto LABEL_16;
  }
  qdf_trace_msg(
    0x49u,
    2u,
    "%s: scn: 0x%pK, data: 0x%pK",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "target_if_mlo_link_removal_event_handler",
    a1,
    a2);
LABEL_16:
  result = 4294967274LL;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
