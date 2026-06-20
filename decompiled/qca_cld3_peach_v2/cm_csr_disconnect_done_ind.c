__int64 __fastcall cm_csr_disconnect_done_ind(
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
  unsigned int v10; // w19
  _QWORD *context; // x0
  __int64 v12; // x21
  __int64 psoc_ext_obj_fl; // x0
  __int64 v14; // x22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  v10 = *(unsigned __int8 *)(a1 + 168);
  context = _cds_get_context(52, (__int64)"cm_csr_disconnect_done_ind", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    return 4;
  v12 = (__int64)context;
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(context[2703]);
  if ( !psoc_ext_obj_fl )
    return 4;
  v14 = psoc_ext_obj_fl;
  v15 = ((double (__fastcall *)(_QWORD))cm_csr_set_idle)(v10);
  if ( cm_is_vdev_roaming(a1, v15, v16, v17, v18, v19, v20, v21, v22) )
    sme_qos_update_hand_off(v10, 0);
  *(_DWORD *)(*(_QWORD *)(v12 + 8) + 5964LL) = csr_translate_to_wni_cfg_dot11_mode(v12, *(unsigned int *)(v12 + 17204));
  if ( *(_BYTE *)(v14 + 2808) == 1 )
  {
    wlan_cm_set_force_20mhz_in_24ghz(a1, 1);
    sme_set_vdev_ies_per_band(v12, v10, *(_DWORD *)(a1 + 16));
  }
  return 0;
}
