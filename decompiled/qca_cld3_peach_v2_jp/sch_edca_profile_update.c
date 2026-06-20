__int64 __fastcall sch_edca_profile_update(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v4; // x19
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  char v15; // w20
  int v16; // w1
  int v17; // [xsp+0h] [xbp-10h] BYREF
  char v18; // [xsp+4h] [xbp-Ch]
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a2 + 88) == 1 )
  {
    v4 = result;
    sch_qos_update_local();
    sch_qos_update_broadcast(v4, a2, a3);
    lim_send_conc_params_update(v6, v7, v8, v9, v10, v11, v12, v13);
    result = policy_mgr_is_vdev_ll_lt_sap(*(_QWORD *)(v4 + 21552), *(unsigned __int8 *)(a2 + 10));
    if ( (result & 1) != 0 )
    {
      v14 = *(_QWORD *)(v4 + 8);
      v15 = *(_BYTE *)(a2 + 10);
      v18 = 0;
      v16 = *(_DWORD *)(v14 + 1028);
      v17 = 0;
      wlan_mlme_set_edca_pifs_param((__int64)&v17, v16);
      result = lim_send_edca_pifs_param(v4, &v17, v15);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
