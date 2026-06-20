__int64 __fastcall cm_roam_beacon_loss_disconnect_event(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int *v14; // x8
  __int64 result; // x0
  __int64 v16; // x20
  __int64 v17; // x1
  __int64 v18; // x2
  __int64 v19; // x3
  __int64 v20; // x4
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int *v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  int v39; // [xsp+8h] [xbp-158h] BYREF
  __int16 v40; // [xsp+Ch] [xbp-154h]
  _BYTE s[331]; // [xsp+15h] [xbp-14Bh] BYREF

  *(_QWORD *)&s[323] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39 = a2;
  v40 = WORD2(a2);
  memset(s, 0, 0x143u);
  v5 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a3, 77);
  if ( v5 )
  {
    v14 = (unsigned int *)*(unsigned int *)(v5 + 16);
    if ( (_DWORD)v14 )
    {
      wlan_objmgr_vdev_release_ref(v5, 0x4Du, v14, v6, v7, v8, v9, v10, v11, v12, v13);
    }
    else
    {
      v16 = v5;
      qdf_mem_set(s, 0x143u, 0);
      *(_WORD *)&s[6] = (unsigned __int8)a3;
      *(_QWORD *)&s[8] = qdf_get_time_of_the_day_us();
      v21 = ktime_get(*(_QWORD *)&s[8], v17, v18, v19, v20);
      *(_QWORD *)&s[16] = 0;
      *(_QWORD *)&s[24] = v21 / 1000;
      qdf_mem_copy(s, &v39, 6u);
      *(_WORD *)&s[40] = 12;
      s[32] = 1;
      *(_DWORD *)&s[52] = mlme_get_hb_ap_rssi(v16, v22, v23, v24, v25, v26, v27, v28, v29);
      wlan_objmgr_vdev_release_ref(v16, 0x4Du, v30, v31, v32, v33, v34, v35, v36, v37, v38);
      s[38] = 0;
      host_diag_event_report_payload(3355, 323, s);
    }
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Vdev[%d] is null",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "cm_roam_beacon_loss_disconnect_event",
      (unsigned __int8)a3);
    result = 16;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
