__int64 __fastcall nan_discovery_scheduled_handler(
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
  __int64 v9; // x19
  int v10; // w4
  unsigned __int16 *v11; // x20
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w19
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v39; // x0
  __int64 v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 (__fastcall *v49)(__int64, __int64); // x8
  __int64 v50; // x0
  __int64 v51; // x1
  __int64 comp_private_obj; // x0
  const char *v54; // x2
  const char *v55; // x3
  __int64 v56; // x0

  if ( !a1 || (v9 = *((_QWORD *)a1 + 1)) == 0 )
  {
    qdf_trace_msg(
      0x53u,
      1u,
      "%s: msg or bodyptr is null",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "nan_discovery_scheduled_handler");
    return 29;
  }
  v10 = *a1;
  if ( !*a1 )
  {
    v11 = a1;
    if ( *(_QWORD *)v9 )
    {
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)v9, 0xFu);
      if ( comp_private_obj )
      {
        v49 = *(__int64 (__fastcall **)(__int64, __int64))(comp_private_obj + 240);
        if ( v49 )
        {
          v50 = v9;
          v51 = 0;
          goto LABEL_35;
        }
        v54 = "%s: NAN Discovery tx op is NULL";
LABEL_28:
        v55 = "nan_discovery_generic_req";
LABEL_46:
        qdf_trace_msg(0x53u, 2u, v54, v41, v42, v43, v44, v45, v46, v47, v48, v55);
        v29 = 29;
        goto LABEL_47;
      }
    }
    else
    {
      qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a2, a3, a4, a5, a6, a7, a8, a9, "nan_get_psoc_priv_obj");
    }
    v54 = "%s: psoc_nan_obj is null";
    goto LABEL_28;
  }
  if ( v10 == 2 )
  {
    v11 = a1;
    if ( *(_QWORD *)v9 )
    {
      v39 = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)v9, 0xFu);
      if ( v39 )
      {
        if ( *(_DWORD *)(v39 + 272) )
        {
          if ( *(_QWORD *)v9 )
          {
            v40 = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)v9, 0xFu);
            if ( v40 )
            {
              v49 = *(__int64 (__fastcall **)(__int64, __int64))(v40 + 240);
              if ( v49 )
              {
                v50 = v9;
                v51 = 2;
LABEL_35:
                if ( *((_DWORD *)v49 - 1) != -297509796 )
                  __break(0x8228u);
                v29 = v49(v50, v51);
                goto LABEL_47;
              }
              v54 = "%s: NAN Discovery tx op is NULL";
LABEL_45:
              v55 = "nan_discovery_disable_req";
              goto LABEL_46;
            }
          }
          else
          {
            qdf_trace_msg(
              0x53u,
              2u,
              "%s: psoc is null",
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              "nan_get_psoc_priv_obj");
          }
          v54 = "%s: psoc_nan_obj is null";
          goto LABEL_45;
        }
LABEL_25:
        v29 = 0;
        goto LABEL_47;
      }
    }
    else
    {
      qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a2, a3, a4, a5, a6, a7, a8, a9, "nan_get_psoc_priv_obj");
    }
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: nan psoc priv object is NULL",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "nan_get_discovery_state");
    goto LABEL_25;
  }
  if ( v10 != 1 )
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: Unsupported request type: %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "nan_discovery_scheduled_handler");
    _qdf_mem_free(*((_QWORD *)a1 + 1));
    return 16;
  }
  v11 = a1;
  if ( !*(_QWORD *)v9 )
  {
    qdf_trace_msg(0x53u, 2u, "%s: psoc is null", a2, a3, a4, a5, a6, a7, a8, a9, "nan_get_psoc_priv_obj");
    goto LABEL_30;
  }
  v12 = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)v9, 0xFu);
  if ( !v12 )
  {
LABEL_30:
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: nan psoc priv object is NULL",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "nan_get_discovery_state");
LABEL_31:
    if ( *(_QWORD *)v9 )
    {
      v56 = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)v9, 0xFu);
      if ( v56 )
      {
        *(_DWORD *)(v56 + 276) = *(_DWORD *)(v9 + 8);
        v49 = *(__int64 (__fastcall **)(__int64, __int64))(v56 + 240);
        *(_DWORD *)(v56 + 280) = *(_DWORD *)(v9 + 12);
        if ( v49 )
        {
          v50 = v9;
          v51 = 1;
          goto LABEL_35;
        }
        v54 = "%s: NAN Discovery tx op is NULL";
        goto LABEL_40;
      }
    }
    else
    {
      qdf_trace_msg(0x53u, 2u, "%s: psoc is null", v13, v14, v15, v16, v17, v18, v19, v20, "nan_get_psoc_priv_obj");
    }
    v54 = "%s: psoc_nan_obj is null";
LABEL_40:
    v55 = "nan_discovery_enable_req";
    goto LABEL_46;
  }
  if ( *(_DWORD *)(v12 + 272) != 3 )
    goto LABEL_31;
  policy_mgr_check_n_start_opportunistic_timer(*(_QWORD *)v9);
  v29 = nan_set_discovery_state(*(_QWORD *)v9, 0, v21, v22, v23, v24, v25, v26, v27, v28);
LABEL_47:
  nan_discovery_flush_callback(v11, v30, v31, v32, v33, v34, v35, v36, v37);
  return v29;
}
