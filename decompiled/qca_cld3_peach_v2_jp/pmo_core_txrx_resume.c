__int64 __fastcall pmo_core_txrx_resume(
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
  unsigned int ref; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w20
  __int64 comp_private_obj; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x21
  __int64 hif_handle; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w0
  unsigned int v40; // w20

  ref = wlan_objmgr_psoc_try_get_ref(a1, 0xAu, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( ref )
  {
    v19 = ref;
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: pmo cannot get the reference out of psoc",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "pmo_core_txrx_resume");
  }
  else
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
    if ( *(_BYTE *)(comp_private_obj + 946) == 1 )
    {
      v29 = comp_private_obj;
      hif_handle = pmo_core_psoc_get_hif_handle(a1);
      if ( hif_handle )
      {
        v39 = hif_enable_grp_irqs(hif_handle);
        if ( v39 != -95 && v39 )
        {
          v40 = v39;
          qdf_trace_msg(
            0x4Du,
            2u,
            "%s: Failed to enable grp irqs: %d",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            "pmo_core_txrx_resume",
            v39);
          v19 = qdf_status_from_os_return(v40);
        }
        else
        {
          v19 = 0;
          *(_BYTE *)(v29 + 946) = 0;
        }
      }
      else
      {
        qdf_trace_msg(0x4Du, 2u, "%s: Invalid hif ctx", v31, v32, v33, v34, v35, v36, v37, v38, "pmo_core_txrx_resume");
        v19 = 4;
      }
    }
    else
    {
      v19 = 0;
    }
    wlan_objmgr_psoc_release_ref(a1, 0xAu, v21, v22, v23, v24, v25, v26, v27, v28);
  }
  return v19;
}
