__int64 __fastcall target_if_green_ap_ll_ps_event(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 pdev_from_scn_hdl; // x0
  __int64 v13; // x20
  __int64 comp_private_obj; // x0
  __int64 v15; // x22
  void *v16; // x0
  __int64 v17; // x19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 *v26; // x8
  const char *v27; // x2
  const char *v28; // x2
  unsigned int v29; // w0
  unsigned int v30; // w20
  int v32; // w8
  __int64 v33; // x4

  if ( target_if_get_psoc_from_scn_hdl(a1) )
  {
    pdev_from_scn_hdl = target_if_get_pdev_from_scn_hdl(a1);
    if ( pdev_from_scn_hdl )
    {
      v13 = pdev_from_scn_hdl;
      comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(pdev_from_scn_hdl, 0x16u);
      if ( comp_private_obj )
      {
        v15 = comp_private_obj;
        v16 = (void *)_qdf_mem_malloc(0x10u, "target_if_green_ap_ll_ps_event", 137);
        if ( v16 )
        {
          v17 = (__int64)v16;
          qdf_mem_set(v16, 0x10u, 0);
          v26 = *(__int64 **)(v13 + 1232);
          if ( v26 && *v26 )
          {
            if ( !(unsigned int)wmi_unified_extract_green_ap_ll_ps_param(*v26, a2, v17) )
            {
              if ( (*(_DWORD *)(v17 + 4) & 1) != 0 )
                v32 = *(_DWORD *)(v15 + 104);
              else
                LOWORD(v32) = 1;
              v33 = *(_QWORD *)(v17 + 8);
              *(_WORD *)v17 = v32;
              qdf_trace_msg(
                0x5Du,
                8u,
                "%s: Next TSF: %llu Dialog Token: %u bcn_mult: %u",
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                v24,
                v25,
                "target_if_green_ap_ll_ps_event",
                v33);
              if ( !(unsigned int)wlan_green_ap_send_ll_ps_event_params(v13, v17) )
              {
                v30 = 0;
                goto LABEL_15;
              }
              v27 = "%s: wlan_green_ap_send_ll_ps_event failed";
              v29 = 49;
LABEL_14:
              qdf_trace_msg(v29, 2u, v27, v18, v19, v20, v21, v22, v23, v24, v25, "target_if_green_ap_ll_ps_event");
              v30 = -22;
LABEL_15:
              _qdf_mem_free(v17);
              return v30;
            }
            v27 = "%s: unable to extract green ap ll ps event params";
          }
          else
          {
            v27 = "%s: null wmi_hdl";
          }
          v29 = 93;
          goto LABEL_14;
        }
        v28 = "%s: Unable to allocate memory";
      }
      else
      {
        v28 = "%s: green_ap_ctx not found";
      }
    }
    else
    {
      v28 = "%s: pdev is null";
    }
  }
  else
  {
    v28 = "%s: psoc is null";
  }
  qdf_trace_msg(0x5Du, 2u, v28, v4, v5, v6, v7, v8, v9, v10, v11, "target_if_green_ap_ll_ps_event");
  return 4294967284LL;
}
