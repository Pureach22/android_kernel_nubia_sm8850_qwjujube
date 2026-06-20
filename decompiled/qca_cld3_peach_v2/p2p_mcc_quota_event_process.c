__int64 __fastcall p2p_mcc_quota_event_process(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 comp_private_obj; // x0
  __int64 v13; // x21
  __int64 result; // x0
  _DWORD *v15; // x8
  const char *v16; // x2
  __int64 v17; // [xsp+0h] [xbp-20h] BYREF
  __int64 v18; // [xsp+8h] [xbp-18h]
  __int64 v19; // [xsp+10h] [xbp-10h]
  __int64 v20; // [xsp+18h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v19 = 0;
  v17 = 0;
  if ( !a2 )
  {
    v16 = "%s: invalid mcc quota event information";
LABEL_13:
    qdf_trace_msg(0x4Eu, 2u, v16, a3, a4, a5, a6, a7, a8, a9, a10, "p2p_mcc_quota_event_process", v17, v18, v19, v20);
    result = 4;
    goto LABEL_14;
  }
  if ( !a1 )
  {
    v16 = "%s: psoc context passed is NULL";
    goto LABEL_13;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 5u);
  if ( !comp_private_obj )
  {
    v16 = "%s: p2p soc object is NULL";
    goto LABEL_13;
  }
  v13 = comp_private_obj;
  if ( !*(_QWORD *)(comp_private_obj + 280) )
  {
    v16 = "%s: mcc_quota_ev_os_if_cb is NULL";
    goto LABEL_13;
  }
  qdf_mem_set(&v17, 0x18u, 0);
  v18 = a2;
  v19 = v13;
  wlan_objmgr_iterate_obj_list(a1, 2, wlan_indicate_quota_vdev_handler, (__int64)&v17, 1, 0xFu);
  result = 0;
  if ( (v17 & 1) == 0 )
  {
    v15 = *(_DWORD **)(v13 + 280);
    if ( *(v15 - 1) != -1994039160 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))v15)(a1, 0, a2);
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
