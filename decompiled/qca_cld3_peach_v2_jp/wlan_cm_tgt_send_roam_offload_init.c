__int64 __fastcall wlan_cm_tgt_send_roam_offload_init(__int64 a1, __int64 a2, char a3)
{
  unsigned __int8 v4; // w19
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int *v15; // x8
  unsigned int v16; // w21
  __int64 v17; // x8
  __int64 v18; // x20
  __int64 v19; // x0
  __int64 ext_hdl; // x0
  __int64 v21; // x22
  unsigned int v22; // w24
  const char *v23; // x2
  _DWORD *v25; // x8
  _BYTE v26[4]; // [xsp+8h] [xbp-18h] BYREF
  int v27; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v28[2]; // [xsp+10h] [xbp-10h] BYREF

  v4 = a2;
  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28[0] = 0;
  v27 = 0;
  v26[0] = 0;
  v6 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( v6 )
  {
    v15 = (unsigned int *)*(unsigned int *)(v6 + 16);
    if ( (_DWORD)v15 )
    {
      v16 = 4;
LABEL_18:
      wlan_objmgr_vdev_release_ref(v6, 2u, v15, v7, v8, v9, v10, v11, v12, v13, v14);
      goto LABEL_19;
    }
    v17 = *(_QWORD *)(v6 + 152);
    if ( v17 )
    {
      v18 = v6;
      v19 = *(_QWORD *)(v17 + 80);
      if ( v19 )
      {
        ext_hdl = wlan_psoc_mlme_get_ext_hdl(v19);
        if ( ext_hdl )
        {
          v21 = ext_hdl;
          if ( *(_QWORD *)(ext_hdl + 7136) )
          {
            LOBYTE(v28[0]) = v4;
            if ( (a3 & 1) == 0 )
            {
              v22 = 0;
LABEL_27:
              qdf_trace_msg(
                0x68u,
                8u,
                "%s: vdev_id:%d, is_init:%d, flag:%d",
                v7,
                v8,
                v9,
                v10,
                v11,
                v12,
                v13,
                v14,
                "wlan_cm_tgt_send_roam_offload_init",
                v4,
                a3 & 1,
                v22);
              v25 = *(_DWORD **)(v21 + 7136);
              if ( *(v25 - 1) != 1043004913 )
                __break(0x8228u);
              v16 = ((__int64 (__fastcall *)(__int64, _QWORD *))v25)(v18, v28);
              if ( v16 )
                qdf_trace_msg(
                  0x68u,
                  2u,
                  "%s: CM_RSO: vdev%d fail to send rso init",
                  v7,
                  v8,
                  v9,
                  v10,
                  v11,
                  v12,
                  v13,
                  v14,
                  "wlan_cm_tgt_send_roam_offload_init",
                  v4);
              goto LABEL_17;
            }
            HIDWORD(v28[0]) = 6;
            wlan_mlme_get_4way_hs_offload(a1, &v27);
            if ( v27 )
            {
              if ( (v27 & 1) == 0 )
              {
                v22 = 6;
                goto LABEL_25;
              }
              v22 = 46;
            }
            else
            {
              v22 = 38;
            }
            HIDWORD(v28[0]) = v22;
LABEL_25:
            wlan_mlme_get_bmiss_skip_full_scan_value(a1, v26);
            if ( v26[0] == 1 )
            {
              v22 |= 0x10u;
              HIDWORD(v28[0]) = v22;
            }
            goto LABEL_27;
          }
LABEL_16:
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: CM_RSO: vdev%d send_roam_offload_init_req is NULL",
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            "wlan_cm_tgt_send_roam_offload_init",
            v4);
          v16 = 4;
LABEL_17:
          v6 = v18;
          goto LABEL_18;
        }
        v23 = "%s: psoc legacy private object is NULL";
LABEL_15:
        qdf_trace_msg(0x1Fu, 2u, v23, v7, v8, v9, v10, v11, v12, v13, v14, "wlan_cm_roam_get_tx_ops_from_vdev");
        goto LABEL_16;
      }
    }
    else
    {
      v18 = v6;
    }
    v23 = "%s: psoc object is NULL";
    goto LABEL_15;
  }
  v16 = 4;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return v16;
}
