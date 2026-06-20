__int64 __fastcall tdls_process_evt(
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
  __int64 v9; // x19
  __int64 v10; // x20
  const char *v11; // x4
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int *v21; // x8

  if ( a1 && (v9 = *(_QWORD *)(a1 + 8)) != 0 )
  {
    v10 = *(_QWORD *)v9;
    if ( *(_QWORD *)v9 )
    {
      if ( *(unsigned __int16 *)(v9 + 16) > 3u )
        v11 = "Invalid TDLS event";
      else
        v11 = off_B2DE80[*(unsigned __int16 *)(v9 + 16)];
      qdf_trace_msg(0, 8u, "%s:  %s(%d)", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_process_evt", v11);
      v21 = (unsigned int *)*(unsigned __int16 *)(v9 + 16);
      if ( (unsigned int)((_DWORD)v21 - 1) < 2 )
      {
        tdls_process_should_teardown(v10, v9 + 8, v13, v14, v15, v16, v17, v18, v19, v20);
      }
      else if ( (_DWORD)v21 == 3 )
      {
        tdls_process_connection_tracker_notify(v10, v9 + 8, v13, v14, v15, v16, v17, v18, v19, v20);
      }
      else if ( !*(_WORD *)(v9 + 16) )
      {
        tdls_process_should_discover(v10, v9 + 8, v13, v14, v15, v16, v17, v18, v19, v20);
      }
      wlan_objmgr_vdev_release_ref(v10, 0x10u, v21, v13, v14, v15, v16, v17, v18, v19, v20);
      _qdf_mem_free(v9);
      return 0;
    }
    else
    {
      qdf_trace_msg(0, 2u, "%s: NULL vdev object", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_process_evt", a1);
      _qdf_mem_free(v9);
      return 29;
    }
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: msg is not valid: %pK", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_process_evt", a1);
    return 29;
  }
}
