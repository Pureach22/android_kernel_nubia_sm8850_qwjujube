__int64 __fastcall target_if_cm_roam_event(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 psoc_from_scn_hdl; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  __int64 v15; // x22
  __int64 v16; // x23
  __int64 v17; // x0
  __int64 v18; // x19
  unsigned int roam_event; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  const char *v28; // x2
  int v30; // w8
  __int64 ext_hdl; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 (__fastcall *v40)(_QWORD); // x8
  unsigned int v41; // w20

  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( psoc_from_scn_hdl )
  {
    v14 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
    if ( v14 )
    {
      v15 = *(_QWORD *)(v14 + 16);
      if ( v15 )
      {
        v16 = psoc_from_scn_hdl;
        v17 = _qdf_mem_malloc(0x40u, "target_if_cm_roam_event", 111);
        if ( !v17 )
          return 4294967284LL;
        v18 = v17;
        roam_event = wmi_extract_roam_event(v15, a2, a3, v17);
        if ( roam_event )
        {
          qdf_trace_msg(
            0x49u,
            2u,
            "%s: parsing of event failed, %d",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "target_if_cm_roam_event",
            roam_event);
        }
        else
        {
          v30 = *(_DWORD *)(v18 + 16);
          *(_QWORD *)(v18 + 8) = v16;
          if ( v30 == 5 || v30 == 7 && !*(_DWORD *)(v18 + 28) )
            *(_BYTE *)(v18 + 56) = 0;
          ext_hdl = wlan_psoc_mlme_get_ext_hdl(v16);
          if ( ext_hdl )
          {
            v40 = *(__int64 (__fastcall **)(_QWORD))(ext_hdl + 7328);
            if ( v40 )
            {
              if ( *((_DWORD *)v40 - 1) != -1251064106 )
                __break(0x8228u);
              v41 = v40(v18);
              goto LABEL_24;
            }
          }
          else
          {
            qdf_trace_msg(
              0x49u,
              2u,
              "%s: psoc legacy private object is NULL",
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              "target_if_cm_get_roam_rx_ops");
          }
          qdf_trace_msg(
            0x49u,
            2u,
            "%s: No valid roam rx ops",
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            "target_if_cm_roam_event");
        }
        v41 = 4;
LABEL_24:
        _qdf_mem_free(v18);
        return qdf_status_to_os_return(v41);
      }
    }
    v28 = "%s: wmi_handle is null";
  }
  else
  {
    v28 = "%s: psoc is null";
  }
  qdf_trace_msg(0x49u, 2u, v28, v6, v7, v8, v9, v10, v11, v12, v13, "target_if_cm_roam_event");
  return 4294967274LL;
}
