__int64 __fastcall ll_lt_sap_switch_bearer_on_p2p_go_complete(__int64 result, unsigned __int8 a2, int a3)
{
  __int64 v4; // x19
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _DWORD v13[2]; // [xsp+0h] [xbp-30h] BYREF
  __int64 v14; // [xsp+8h] [xbp-28h]
  __int64 (__fastcall *v15)(); // [xsp+10h] [xbp-20h]
  int v16; // [xsp+18h] [xbp-18h]
  int v17; // [xsp+1Ch] [xbp-14h]
  __int64 v18; // [xsp+20h] [xbp-10h]
  __int64 v19; // [xsp+28h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 == 3 )
  {
    v4 = result;
    result = wlan_policy_mgr_get_ll_lt_sap_vdev_id(result);
    if ( (_BYTE)result != 0xFF )
    {
      v17 = 0;
      v13[0] = a2;
      v13[1] = ll_lt_sap_bearer_switch_get_id(v4);
      v14 = 0x300000001LL;
      v15 = p2p_go_complete_bearer_switch_requester_cb;
      v16 = 0;
      v18 = 0;
      result = bs_sm_deliver_event(v4, 0, 0x28u, (__int64)v13);
      if ( (_DWORD)result )
        result = qdf_trace_msg(
                   0xA1u,
                   2u,
                   "%s: vdev %d beaer_switch failed for req_type %d source %d status %d",
                   v5,
                   v6,
                   v7,
                   v8,
                   v9,
                   v10,
                   v11,
                   v12,
                   "ll_lt_sap_switch_bearer",
                   LOBYTE(v13[0]),
                   (unsigned int)v14,
                   HIDWORD(v14),
                   (unsigned int)result);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
