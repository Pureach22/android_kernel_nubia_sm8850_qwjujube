__int64 __fastcall lim_pre_vdev_start(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  int v15; // w8
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  bool is_10_mhz_enabled; // w0
  __int64 v26; // x8
  char v27; // w9
  unsigned int v28; // w21
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 cmpt_obj; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x22

  result = lim_set_session_channel_params(a1, a3);
  if ( !(_DWORD)result )
  {
    if ( *(_DWORD *)(a3 + 88) == 2 )
      wlan_cdp_set_peer_freq(
        *(_QWORD *)(a1 + 21624),
        a3 + 24,
        *(unsigned int *)(a3 + 284),
        *(unsigned __int8 *)(*(_QWORD *)(a3 + 16) + 168LL));
    *(_BYTE *)(a2 + 139) = *(_BYTE *)(a3 + 7032);
    v15 = *(unsigned __int8 *)(a2 + 179);
    *(_WORD *)(a2 + 20) = *(_WORD *)(a3 + 7158);
    if ( v15 == 1 )
    {
      v16 = *(_QWORD *)(a2 + 520);
      *(_BYTE *)(a2 + 240) = *(_BYTE *)(a3 + 7020) != 0;
      wlan_util_vdev_mgr_set_cac_timeout_for_vdev(v16, *(_DWORD *)(a3 + 10048));
    }
    *(_BYTE *)(a2 + 8) = *(_BYTE *)(a3 + 251);
    *(_DWORD *)(a2 + 12) = *(unsigned __int8 *)(a3 + 250);
    *(_DWORD *)(a2 + 320) = *(unsigned __int16 *)(a3 + 8656);
    *(_BYTE *)(a2 + 64) = *(_BYTE *)(a3 + 155) != 0;
    *(_BYTE *)(a2 + 59) = *(_BYTE *)(a3 + 7170) != 0;
    *(_BYTE *)(*(_QWORD *)(a2 + 536) + 24006LL) = *(_BYTE *)(a3 + 7273);
    *(_BYTE *)(a2 + 413) = cds_is_5_mhz_enabled(v7, v8, v9, v10, v11, v12, v13, v14);
    is_10_mhz_enabled = cds_is_10_mhz_enabled(v17, v18, v19, v20, v21, v22, v23, v24);
    v26 = *(_QWORD *)(a2 + 520);
    *(_BYTE *)(a2 + 412) = is_10_mhz_enabled;
    v27 = *(_BYTE *)(a3 + 8635);
    *(_BYTE *)(a2 + 418) = v27;
    *(_BYTE *)(a2 + 419) = v27;
    v28 = *(unsigned __int8 *)(a3 + 36);
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v26, v29, v30, v31, v32, v33, v34, v35, v36);
    if ( cmpt_obj )
    {
      if ( v28 > 0x20 )
      {
        LOBYTE(v28) = 0;
      }
      else
      {
        v46 = cmpt_obj;
        qdf_mem_copy((void *)(cmpt_obj + 145), (const void *)(a3 + 37), v28);
        cmpt_obj = v46;
      }
      *(_BYTE *)(cmpt_obj + 178) = v28;
    }
    return lim_set_ch_phy_mode(
             *(_QWORD *)(a2 + 520),
             *(unsigned __int8 *)(a3 + 154),
             v38,
             v39,
             v40,
             v41,
             v42,
             v43,
             v44,
             v45);
  }
  return result;
}
