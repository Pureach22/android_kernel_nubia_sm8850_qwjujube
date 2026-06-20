__int64 __fastcall pmo_core_configure_dynamic_wake_events(__int64 a1)
{
  unsigned int v2; // w20
  __int64 result; // x0
  __int64 v4; // x21
  char pno_match; // w22
  char v6; // w25
  _QWORD *v7; // x2
  int v8; // w26
  __int64 comp_private_obj; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 (__fastcall *v18)(_QWORD); // x8
  _QWORD v19[2]; // [xsp+8h] [xbp-28h] BYREF
  _QWORD v20[3]; // [xsp+18h] [xbp-18h] BYREF

  v2 = 0;
  v20[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20[0] = 0;
  v20[1] = 0;
  v19[0] = 0;
  v19[1] = 0;
  do
  {
    qdf_mem_set(v20, 0x10u, 0);
    qdf_mem_set(v19, 0x10u, 0);
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v2, 10);
    if ( !result )
      goto LABEL_3;
    v4 = result;
    if ( (ucfg_scan_get_pno_in_progress(result) & 1) != 0 )
    {
      pno_match = ucfg_scan_get_pno_match(v4);
      v6 = pno_match ^ 1;
      if ( (pno_match & 1) != 0 )
        v7 = v20;
      else
        v7 = v19;
      pmo_set_wow_event_bitmap(28, 4, v7);
    }
    else
    {
      pno_match = 0;
      v6 = 0;
    }
    v8 = *(_DWORD *)(v4 + 16);
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
    v18 = (__int64 (__fastcall *)(_QWORD))*(unsigned int *)(comp_private_obj + 60);
    if ( (_DWORD)v18 == 1 )
    {
      v18 = (__int64 (__fastcall *)(_QWORD))(v8 & 0xFFFFFFFD);
      if ( !(_DWORD)v18 )
      {
        v18 = *(__int64 (__fastcall **)(_QWORD))(comp_private_obj + 1016);
        if ( v18 )
        {
          if ( *((_DWORD *)v18 - 1) != 2116364946 )
            __break(0x8228u);
          if ( (v18(v2) & 1) != 0 )
          {
            pmo_set_wow_event_bitmap(33, 4, v20);
LABEL_19:
            pmo_tgt_enable_wow_wakeup_event(v4, v20);
            goto LABEL_20;
          }
        }
      }
    }
    if ( (pno_match & 1) != 0 )
      goto LABEL_19;
LABEL_20:
    if ( (v6 & 1) != 0 )
      pmo_tgt_disable_wow_wakeup_event(v4, v19);
    result = wlan_objmgr_vdev_release_ref(v4, 0xAu, (unsigned int *)v18, v10, v11, v12, v13, v14, v15, v16, v17);
LABEL_3:
    ++v2;
  }
  while ( v2 != 6 );
  _ReadStatusReg(SP_EL0);
  return result;
}
