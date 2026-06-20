__int64 __fastcall wma_roam_scan_stats_event_handler(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x21
  __int64 result; // x0
  int roam_scan_stats_res_evt; // w0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x8
  __int64 v30; // x19
  unsigned int v31; // w20
  const char *v32; // x2
  unsigned int v33; // w0
  _DWORD *v34; // x8
  __int64 v35; // x0

  _ReadStatusReg(SP_EL0);
  if ( !(unsigned int)_wma_validate_handle(
                        a1,
                        (__int64)"wma_roam_scan_stats_event_handler",
                        a2,
                        a3,
                        a4,
                        a5,
                        a6,
                        a7,
                        a8,
                        a9) )
  {
    v18 = *(_QWORD *)a1;
    if ( !(unsigned int)_wmi_validate_handle(
                          *(_QWORD *)a1,
                          (__int64)"wma_roam_scan_stats_event_handler",
                          v10,
                          v11,
                          v12,
                          v13,
                          v14,
                          v15,
                          v16,
                          v17) )
    {
      roam_scan_stats_res_evt = wmi_extract_roam_scan_stats_res_evt(v18);
      if ( *(_WORD *)(a1 + 162) )
      {
        v29 = *(_QWORD *)(a1 + 520);
        if ( v29 )
        {
          v30 = *(_QWORD *)(v29 + 440);
          *(_QWORD *)(v29 + 440) = 0;
          if ( v30 )
          {
            if ( roam_scan_stats_res_evt || (v34 = *(_DWORD **)(v30 + 8)) == nullptr || *(_DWORD *)v30 )
            {
              qdf_trace_msg(
                0x31u,
                2u,
                "%s: roam_scan_stats buffer not available",
                v21,
                v22,
                v23,
                v24,
                v25,
                v26,
                v27,
                v28,
                "wma_roam_scan_stats_event_handler");
              v31 = -22;
            }
            else
            {
              v35 = *(_QWORD *)(v30 + 16);
              if ( *(v34 - 1) != 1252071588 )
                __break(0x8228u);
              ((void (__fastcall *)(__int64, _QWORD))v34)(v35, 0);
              v31 = 0;
            }
            _qdf_mem_free(v30);
            goto LABEL_16;
          }
          v32 = "%s: No pending request vdev_id: %d";
        }
        else
        {
          v32 = "%s: Interface not available for vdev_id: %d";
        }
        v33 = 49;
      }
      else
      {
        v32 = "%s: Received invalid vdev_id: %d";
        v33 = 54;
      }
      qdf_trace_msg(v33, 2u, v32, v21, v22, v23, v24, v25, v26, v27, v28, "wma_roam_scan_stats_event_handler");
      v31 = -22;
LABEL_16:
      _qdf_mem_free(0);
      result = v31;
      goto LABEL_4;
    }
  }
  result = 4294967274LL;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
