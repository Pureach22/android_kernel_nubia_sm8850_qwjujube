__int64 __fastcall pmo_register_wow_wakeup_events(
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
  int v10; // w21
  unsigned int v11; // w20
  __int64 comp_private_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  __int64 (__fastcall *v22)(_QWORD); // x22
  char v23; // w8
  __int64 result; // x0
  _QWORD v25[3]; // [xsp+8h] [xbp-18h] BYREF

  v25[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_DWORD *)(a1 + 16);
  v11 = *(unsigned __int8 *)(a1 + 168);
  v25[0] = 0;
  v25[1] = 0;
  qdf_trace_msg(
    0x4Du,
    8u,
    "%s: vdev_opmode %d vdev_id %d",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "pmo_register_wow_wakeup_events",
    (unsigned int)v10,
    v11);
  wlan_objmgr_vdev_get_comp_private_obj(a1, 4u);
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(*(_QWORD *)(a1 + 216) + 80LL), 4u);
  if ( v10 <= 2 )
  {
    if ( v10 )
    {
      if ( v10 == 1 )
        goto LABEL_16;
      if ( v10 != 2 )
        goto LABEL_19;
    }
    v21 = comp_private_obj;
    pmo_set_wow_event_bitmap(22, 4, v25);
    comp_private_obj = v21;
    if ( *(_DWORD *)(v21 + 60) == 1 )
    {
      raw_spin_lock(v21 + 1040);
      v22 = *(__int64 (__fastcall **)(_QWORD))(v21 + 1016);
      raw_spin_unlock(v21 + 1040);
      comp_private_obj = v21;
      if ( v22 )
      {
        if ( *((_DWORD *)v22 - 1) != 2116364946 )
          __break(0x8236u);
        v23 = v22(v11);
        comp_private_obj = v21;
        if ( (v23 & 1) != 0 )
        {
          pmo_set_wow_event_bitmap(33, 4, v25);
          comp_private_obj = v21;
        }
      }
    }
LABEL_15:
    pmo_set_sta_wow_bitmask(comp_private_obj, v25, 4);
    goto LABEL_17;
  }
  if ( (unsigned int)(v10 - 5) < 4 )
    goto LABEL_15;
  if ( v10 == 3 )
  {
LABEL_16:
    pmo_set_sap_wow_bitmask(v25, 4);
    goto LABEL_17;
  }
  if ( v10 != 11 )
  {
LABEL_19:
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: Skipping wake event configuration for vdev_opmode %d",
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               "pmo_register_wow_wakeup_events",
               (unsigned int)v10);
    goto LABEL_18;
  }
  pmo_set_ndp_wow_bitmask(v25, 4);
LABEL_17:
  result = pmo_tgt_enable_wow_wakeup_event(a1, v25);
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
