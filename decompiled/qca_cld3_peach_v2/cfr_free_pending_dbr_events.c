__int64 __fastcall cfr_free_pending_dbr_events(
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
  __int64 comp_private_obj; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int *v28; // x8
  __int64 v29; // x20
  unsigned int v30; // w21
  __int64 v31; // x22

  if ( (unsigned int)wlan_objmgr_pdev_try_get_ref(a1, 0x30u, a2, a3, a4, a5, a6, a7, a8, a9) )
    return qdf_trace_msg(
             0x6Au,
             2u,
             "%s: Failed to get pdev reference",
             v10,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             "cfr_free_pending_dbr_events");
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x1Eu);
  if ( comp_private_obj )
  {
    v28 = (unsigned int *)*(unsigned int *)(comp_private_obj + 80);
    v29 = comp_private_obj;
    if ( (_DWORD)v28 )
    {
      v30 = 0;
      do
      {
        v31 = *(_QWORD *)(*(_QWORD *)(v29 + 72) + 8LL * (int)v30);
        if ( v31
          && *(_BYTE *)v31 == 1
          && (*(_BYTE *)(v31 + 1) & 1) == 0
          && *(_QWORD *)(v31 + 216) < *(_QWORD *)(v29 + 1424) )
        {
          target_if_dbr_buf_release(a1, 1u, *(_QWORD *)(v31 + 24), v30, 0);
          ++*(_QWORD *)(v29 + 1392);
          *(_WORD *)v31 = 0;
          *(_QWORD *)(v31 + 8) = 0;
          *(_QWORD *)(v31 + 16) = 0;
          *(_QWORD *)(v31 + 24) = 0;
          *(_QWORD *)(v31 + 32) = 0;
          *(_QWORD *)(v31 + 208) = 0;
          *(_QWORD *)(v31 + 216) = 0;
          qdf_mem_set((void *)(v31 + 40), 0xA0u, 0);
          v28 = (unsigned int *)*(unsigned int *)(v29 + 80);
        }
        ++v30;
      }
      while ( v30 < (unsigned int)v28 );
    }
  }
  else
  {
    qdf_trace_msg(
      0x6Au,
      2u,
      "%s: pdev object for CFR is null",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "cfr_free_pending_dbr_events");
  }
  return wlan_objmgr_pdev_release_ref(a1, 0x30u, v28, v20, v21, v22, v23, v24, v25, v26, v27);
}
