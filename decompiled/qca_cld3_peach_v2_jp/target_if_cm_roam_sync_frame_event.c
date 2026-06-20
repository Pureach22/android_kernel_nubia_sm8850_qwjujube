__int64 __fastcall target_if_cm_roam_sync_frame_event(__int64 a1, __int64 a2, unsigned int a3)
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
  __int64 v15; // x23
  __int64 v16; // x20
  __int64 v17; // x0
  __int64 v18; // x19
  unsigned int roam_sync_frame_event; // w0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  const char *v28; // x2
  __int64 ext_hdl; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int (__fastcall *v39)(__int64, __int64); // x8
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0

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
        v17 = _qdf_mem_malloc(0x48u, "target_if_cm_roam_sync_frame_event", 230);
        if ( !v17 )
          return 4294967284LL;
        v18 = v17;
        roam_sync_frame_event = wmi_extract_roam_sync_frame_event(v15, a2, a3, v17);
        if ( roam_sync_frame_event )
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
            "target_if_cm_roam_sync_frame_event",
            roam_sync_frame_event);
        }
        else
        {
          ext_hdl = wlan_psoc_mlme_get_ext_hdl(v16);
          if ( ext_hdl )
          {
            v39 = *(unsigned int (__fastcall **)(__int64, __int64))(ext_hdl + 7312);
            if ( v39 )
            {
              if ( *((_DWORD *)v39 - 1) != 2030840732 )
                __break(0x8228u);
              if ( !v39(v16, v18) )
              {
                _qdf_mem_free(v18);
                return 0;
              }
              goto LABEL_21;
            }
          }
          else
          {
            qdf_trace_msg(
              0x49u,
              2u,
              "%s: psoc legacy private object is NULL",
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              "target_if_cm_get_roam_rx_ops");
          }
          qdf_trace_msg(
            0x49u,
            2u,
            "%s: No valid roam rx ops",
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            "target_if_cm_roam_sync_frame_event");
        }
LABEL_21:
        v40 = *(_QWORD *)(v18 + 8);
        if ( v40 )
        {
          _qdf_mem_free(v40);
          *(_DWORD *)v18 = 0;
          *(_QWORD *)(v18 + 8) = 0;
        }
        v41 = *(_QWORD *)(v18 + 24);
        if ( v41 )
        {
          _qdf_mem_free(v41);
          *(_DWORD *)(v18 + 20) = 0;
          *(_QWORD *)(v18 + 24) = 0;
        }
        v42 = *(_QWORD *)(v18 + 40);
        if ( v42 )
        {
          _qdf_mem_free(v42);
          *(_DWORD *)(v18 + 36) = 0;
          *(_QWORD *)(v18 + 40) = 0;
        }
        v43 = *(_QWORD *)(v18 + 56);
        if ( v43 )
        {
          _qdf_mem_free(v43);
          *(_DWORD *)(v18 + 48) = 0;
          *(_QWORD *)(v18 + 56) = 0;
        }
        _qdf_mem_free(v18);
        return 4294967274LL;
      }
    }
    v28 = "%s: wmi_handle is null";
  }
  else
  {
    v28 = "%s: psoc is null";
  }
  qdf_trace_msg(0x49u, 2u, v28, v6, v7, v8, v9, v10, v11, v12, v13, "target_if_cm_roam_sync_frame_event");
  return 4294967274LL;
}
