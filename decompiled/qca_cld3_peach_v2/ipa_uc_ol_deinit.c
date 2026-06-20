__int64 __fastcall ipa_uc_ol_deinit(
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
  __int64 v10; // x19
  __int64 inited; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 comp_private_obj; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x20
  unsigned int v30; // w19
  __int64 v31; // x0

  if ( !g_ipa_config || (*(_BYTE *)g_ipa_config & 1) == 0 )
  {
    qdf_trace_msg(0x61u, 8u, "%s: ipa is disabled", a2, a3, a4, a5, a6, a7, a8, a9, "ipa_uc_ol_deinit");
    return 0;
  }
  v10 = *(_QWORD *)(a1 + 80);
  inited = ipa_init_deinit_lock();
  if ( (ipa_cb_is_ready(inited) & 1) == 0 )
  {
    v31 = qdf_trace_msg(0x61u, 8u, "%s: ipa is not ready", v12, v13, v14, v15, v16, v17, v18, v19, "ipa_uc_ol_deinit");
LABEL_13:
    v30 = 0;
    goto LABEL_14;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v10, 0x1Au);
  if ( comp_private_obj )
  {
    if ( (*(_BYTE *)(comp_private_obj + 7457) & 1) != 0 )
    {
      v29 = comp_private_obj;
      v30 = wlan_ipa_uc_ol_deinit(comp_private_obj, v21, v22, v23, v24, v25, v26, v27, v28);
      v31 = wlan_ipa_cleanup(v29);
      if ( !g_instances_added || (--g_instances_added, !g_instances_added) )
        v31 = ipa_disable_register_cb(v31);
      goto LABEL_14;
    }
    v31 = qdf_trace_msg(
            0x61u,
            8u,
            "%s: IPA is already deinit for hdl:%d",
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            "ipa_uc_ol_deinit",
            *(unsigned int *)(comp_private_obj + 7460));
    goto LABEL_13;
  }
  v31 = qdf_trace_msg(0x61u, 2u, "%s: IPA object is NULL", v21, v22, v23, v24, v25, v26, v27, v28, "ipa_uc_ol_deinit");
  v30 = 16;
LABEL_14:
  ipa_init_deinit_unlock(v31);
  return v30;
}
