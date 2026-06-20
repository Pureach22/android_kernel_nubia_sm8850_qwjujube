__int64 __fastcall lim_process_bcn_tpe_and_set_tpc(__int64 a1, __int64 a2)
{
  __int64 v4; // x2
  __int64 v5; // x1
  __int64 concurrent_session; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x21
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x8
  __int64 v34; // x21
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 cmpt_obj; // x0
  __int64 v44; // x22
  void (__fastcall *v45)(__int64, __int64, __int64); // x8
  __int64 v46; // x0
  __int64 v47; // x1
  __int64 (__fastcall *v48)(__int64, __int64, __int64); // x8
  __int64 v49; // x0
  __int64 v50; // x1
  const char *v51; // x2
  _BYTE v52[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v53; // [xsp+8h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned int *)(a2 + 7036);
  v5 = *(unsigned __int8 *)(a2 + 10);
  v52[0] = 0;
  concurrent_session = lim_get_concurrent_session(a1, v5, v4);
  if ( concurrent_session )
  {
    v15 = concurrent_session;
    if ( (lim_is_power_change_required_for_sta(a1, a2, concurrent_session) & 1) != 0 )
      lim_update_tx_power(a1, v15, a2, 0);
  }
  result = wlan_reg_is_ext_tpc_supported(*(_QWORD *)(a1 + 21624), v7, v8, v9, v10, v11, v12, v13, v14);
  if ( (result & 1) != 0 && (*(_BYTE *)(a2 + 10070) & 1) == 0 )
  {
    result = wlan_reg_get_tx_ops(*(_QWORD *)(a1 + 21624), v17, v18, v19, v20, v21, v22, v23, v24);
    if ( result )
    {
      v33 = *(_QWORD *)(a2 + 112);
      if ( v33 )
      {
        v34 = result;
        lim_process_tpe_ie_from_beacon(a1, a2, v33 + 4548, v52);
        cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a2 + 16), v35, v36, v37, v38, v39, v40, v41, v42);
        if ( cmpt_obj )
        {
          v44 = cmpt_obj;
          if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a2 + 284)) && *(_BYTE *)(a2 + 10069) == 3 )
          {
            lim_calculate_tpc(a1, a2, 1);
            v45 = *(void (__fastcall **)(__int64, __int64, __int64))(v34 + 144);
            if ( v45 )
            {
              v46 = *(_QWORD *)(a1 + 21624);
              v47 = *(unsigned __int8 *)(a2 + 10);
              if ( *((_DWORD *)v45 - 1) != 1094041931 )
                __break(0x8228u);
              v45(v46, v47, v44 + 544);
            }
          }
          result = lim_calculate_tpc(a1, a2, 0);
          v48 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v34 + 144);
          if ( v48 )
          {
            v49 = *(_QWORD *)(a1 + 21624);
            v50 = *(unsigned __int8 *)(a2 + 10);
            if ( *((_DWORD *)v48 - 1) != 1094041931 )
              __break(0x8228u);
            result = v48(v49, v50, v44 + 544);
          }
          goto LABEL_22;
        }
        v51 = "%s: vdev component object is NULL";
      }
      else
      {
        v51 = "%s: bss descriptor is NULL";
      }
      result = qdf_trace_msg(0x35u, 2u, v51, v25, v26, v27, v28, v29, v30, v31, v32, "lim_process_bcn_tpe_and_set_tpc");
    }
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}
