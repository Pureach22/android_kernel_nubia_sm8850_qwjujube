__int64 __fastcall fwol_process_event(
        unsigned __int16 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 *v18; // x19
  int v19; // w8
  __int64 v20; // x0
  void (__fastcall *v21)(__int64, char *); // x8
  __int64 v22; // x0
  char *v23; // x1
  unsigned int v24; // w20
  __int64 comp_private_obj; // x0
  __int64 v26; // x0
  const char *v27; // x2
  const char *v28; // x3
  const char *v30; // x3

  qdf_trace_msg(0x66u, 8u, "%s: msg type %d", a2, a3, a4, a5, a6, a7, a8, a9, "fwol_process_event", *a1);
  v18 = *((__int64 **)a1 + 1);
  if ( v18 )
  {
    v19 = *a1;
    *((_QWORD *)a1 + 1) = 0;
    if ( v19 == 2 )
    {
      if ( *v18 )
      {
        comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*v18, 0x1Du);
        if ( comp_private_obj )
        {
          v21 = *(void (__fastcall **)(__int64, char *))(comp_private_obj + 1336);
          if ( v21 )
          {
            v22 = *(_QWORD *)(comp_private_obj + 1344);
            v23 = (char *)v18 + 12;
            if ( *((_DWORD *)v21 - 1) != -1630470721 )
              __break(0x8228u);
LABEL_16:
            v21(v22, v23);
            v24 = 0;
            v26 = *v18;
            if ( !*v18 )
              goto LABEL_27;
            goto LABEL_26;
          }
          v30 = "fwol_process_get_thermal_stats_resp";
          goto LABEL_31;
        }
        v27 = "%s: Failed to get FWOL Obj";
      }
      else
      {
        v27 = "%s: psoc is NULL";
      }
      v28 = "fwol_process_get_thermal_stats_resp";
    }
    else
    {
      if ( v19 != 1 )
        goto LABEL_25;
      if ( *v18 )
      {
        v20 = wlan_objmgr_psoc_get_comp_private_obj(*v18, 0x1Du);
        if ( v20 )
        {
          v21 = *(void (__fastcall **)(__int64, char *))(v20 + 1320);
          if ( v21 )
          {
            v22 = *(_QWORD *)(v20 + 1328);
            v23 = (char *)v18 + 12;
            if ( *((_DWORD *)v21 - 1) != -691055213 )
              __break(0x8228u);
            goto LABEL_16;
          }
          v30 = "fwol_process_get_elna_bypass_resp";
LABEL_31:
          qdf_trace_msg(0x66u, 2u, "%s: NULL pointer for callback", v10, v11, v12, v13, v14, v15, v16, v17, v30);
          v24 = 23;
          v26 = *v18;
          if ( !*v18 )
            goto LABEL_27;
          goto LABEL_26;
        }
        v27 = "%s: Failed to get FWOL Obj";
      }
      else
      {
        v27 = "%s: psoc is NULL";
      }
      v28 = "fwol_process_get_elna_bypass_resp";
    }
    qdf_trace_msg(0x66u, 2u, v27, v10, v11, v12, v13, v14, v15, v16, v17, v28);
LABEL_25:
    v24 = 4;
    v26 = *v18;
    if ( !*v18 )
    {
LABEL_27:
      _qdf_mem_free((__int64)v18);
      return v24;
    }
LABEL_26:
    wlan_objmgr_psoc_release_ref(v26, 0x47u, v10, v11, v12, v13, v14, v15, v16, v17);
    goto LABEL_27;
  }
  qdf_trace_msg(0x66u, 2u, "%s: Invalid message body", v10, v11, v12, v13, v14, v15, v16, v17, "fwol_process_event");
  return 4;
}
