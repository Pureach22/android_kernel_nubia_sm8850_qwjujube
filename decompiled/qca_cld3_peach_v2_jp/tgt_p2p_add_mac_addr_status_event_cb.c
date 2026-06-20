__int64 __fastcall tgt_p2p_add_mac_addr_status_event_cb(
        __int64 a1,
        _DWORD *a2,
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
  __int64 v12; // x19
  __int64 v13; // x0
  __int64 v14; // x19
  int v15; // w9
  __int64 result; // x0
  unsigned int v17; // w20
  const char *v18; // x2
  __int64 v19; // [xsp+8h] [xbp-38h] BYREF
  __int64 v20; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v21)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+18h] [xbp-28h]
  __int64 v22; // [xsp+20h] [xbp-20h]
  __int64 v23; // [xsp+28h] [xbp-18h]
  __int64 v24; // [xsp+30h] [xbp-10h]
  __int64 v25; // [xsp+38h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v24 = 0;
  v21 = nullptr;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  if ( !a1 )
  {
    v18 = "%s: random_mac:psoc context passed is NULL";
LABEL_10:
    qdf_trace_msg(0x4Eu, 2u, v18, a3, a4, a5, a6, a7, a8, a9, a10, "tgt_p2p_add_mac_addr_status_event_cb");
    result = 4;
    goto LABEL_11;
  }
  if ( !a2 )
  {
    v18 = "%s: random_mac:invalid event_info";
    goto LABEL_10;
  }
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 5u);
  if ( !comp_private_obj )
  {
    v18 = "%s: random_mac:p2p soc object is NULL";
    goto LABEL_10;
  }
  v12 = comp_private_obj;
  v13 = _qdf_mem_malloc(0x10u, "tgt_p2p_add_mac_addr_status_event_cb", 197);
  if ( v13 )
  {
    *(_QWORD *)v13 = v12;
    v14 = v13;
    *(_DWORD *)(v13 + 8) = *a2;
    v15 = a2[1];
    LOWORD(v19) = 5;
    *(_DWORD *)(v13 + 12) = v15;
    v20 = v13;
    v21 = p2p_process_evt;
    result = scheduler_post_message_debug(
               0x4Eu,
               0x4Eu,
               73,
               (unsigned __int16 *)&v19,
               0xD1u,
               (__int64)"tgt_p2p_add_mac_addr_status_event_cb");
    if ( (_DWORD)result )
    {
      v17 = result;
      _qdf_mem_free(v14);
      result = v17;
    }
  }
  else
  {
    result = 2;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
