__int64 __fastcall csr_send_ese_adjacent_ap_rep_ind(_QWORD *a1, unsigned __int8 *a2)
{
  __int64 result; // x0
  __int64 v5; // x19
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 session_by_bssid; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x4
  __int64 v24; // x8
  unsigned __int8 v25; // w1
  unsigned int v26; // w21
  _DWORD *v27; // x8
  __int64 v28; // x0
  const char *v29; // x2
  const char *v30; // x3
  unsigned __int8 v31[4]; // [xsp+Ch] [xbp-14h] BYREF
  int v32; // [xsp+10h] [xbp-10h] BYREF
  __int16 v33; // [xsp+14h] [xbp-Ch]
  __int64 v34; // [xsp+18h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31[0] = -1;
  v33 = 0;
  v32 = 0;
  result = _qdf_mem_malloc(0x180u, "csr_send_ese_adjacent_ap_rep_ind", 1631);
  if ( result )
  {
    v5 = result;
    *(_WORD *)(result + 102) = qdf_mc_timer_get_system_time() - *((_WORD *)a2 + 28);
    wlan_mlme_get_bssid_vdev_id(a1[2695], *a2, &v32);
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Bssid(%02x:%02x:%02x:**:**:%02x) Roaming Delay(%u ms)",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "csr_send_ese_adjacent_ap_rep_ind",
      (unsigned __int8)v32,
      BYTE1(v32),
      BYTE2(v32),
      HIBYTE(v33),
      *(unsigned __int16 *)(v5 + 102));
    session_by_bssid = pe_find_session_by_bssid((__int64)a1, (unsigned __int8 *)&v32, v31);
    if ( session_by_bssid )
    {
      *(_WORD *)(session_by_bssid + 7051) = *(_WORD *)(v5 + 102);
      v23 = *a2;
      if ( a1 )
      {
        if ( (unsigned int)v23 <= 5 )
        {
          v24 = a1[2153];
          if ( v24 )
          {
            if ( (*(_BYTE *)(v24 + 96LL * *a2 + 1) & 1) != 0 )
            {
              v25 = *a2;
              v26 = *a2;
              wlan_get_operation_chan_freq_vdev_id(a1[2695], v25);
              v27 = (_DWORD *)a1[2746];
              if ( v27 )
              {
                v28 = a1[2694];
                if ( *(v27 - 1) != 1469140685 )
                  __break(0x8228u);
                ((void (__fastcall *)(__int64, _QWORD, __int64, __int64, _QWORD))v27)(v28, v26, v5, 36, 0);
              }
              goto LABEL_14;
            }
          }
        }
      }
      v29 = "%s: Session ID: %d is not valid";
      v30 = "csr_roam_call_callback";
    }
    else
    {
      v23 = v31[0];
      v29 = "%s: session %d not found";
      v30 = "csr_send_ese_adjacent_ap_rep_ind";
    }
    qdf_trace_msg(0x34u, 2u, v29, v15, v16, v17, v18, v19, v20, v21, v22, v30, v23);
LABEL_14:
    result = _qdf_mem_free(v5);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
