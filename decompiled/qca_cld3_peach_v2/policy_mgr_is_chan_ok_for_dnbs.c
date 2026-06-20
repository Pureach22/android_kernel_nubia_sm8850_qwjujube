__int64 __fastcall policy_mgr_is_chan_ok_for_dnbs(
        __int64 a1,
        unsigned int a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int mode_specific_conn_info; // w22
  unsigned int v15; // w22
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x23
  __int64 result; // x0
  const char *v31; // x2
  __int64 v32; // x4
  unsigned __int8 *v33; // x8
  unsigned int *v34; // x22
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x1
  unsigned int *v44; // x8
  int v45; // [xsp+8h] [xbp-28h] BYREF
  unsigned __int8 v46; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v47; // [xsp+10h] [xbp-20h] BYREF
  __int64 v48; // [xsp+18h] [xbp-18h] BYREF
  int v49; // [xsp+20h] [xbp-10h] BYREF
  __int64 v50; // [xsp+28h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v49 = 0;
  v47 = 0;
  v48 = 0;
  v46 = 0;
  v45 = 0;
  if ( a3 )
  {
    mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(
                                a1,
                                (unsigned __int64)&v47,
                                (unsigned __int64)&v45,
                                1u);
    v15 = policy_mgr_get_mode_specific_conn_info(
            a1,
            (unsigned __int64)&v47 + 4 * mode_specific_conn_info,
            (unsigned __int64)&v45 + mode_specific_conn_info,
            6u)
        + mode_specific_conn_info;
    if ( v15 > 4
      || (v15 += policy_mgr_get_mode_specific_conn_info(
                   a1,
                   (unsigned __int64)&v47 + 4 * v15,
                   (unsigned __int64)&v45 + v15,
                   3u)) != 0 )
    {
      if ( !a2 )
      {
        v31 = "%s: channel is 0, cc count %d";
        v32 = v15;
LABEL_26:
        qdf_trace_msg(0x4Fu, 2u, v31, v16, v17, v18, v19, v20, v21, v22, v23, "policy_mgr_is_chan_ok_for_dnbs", v32);
        result = 4;
        goto LABEL_35;
      }
      if ( v15 > 5 )
        goto LABEL_34;
      v24 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
              a1,
              (unsigned __int8)v45,
              24);
      if ( v24 )
      {
        if ( (*(_BYTE *)(v24 + 49) & 2) != 0 )
        {
          v29 = v24;
          v34 = (unsigned int *)&v47;
          goto LABEL_28;
        }
        *a3 = 1;
        wlan_objmgr_vdev_release_ref(
          v24,
          0x18u,
          (unsigned int *)((char *)&off_0 + 1),
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23);
        if ( v15 == 1 )
          goto LABEL_34;
        v25 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                a1,
                BYTE1(v45),
                24);
        if ( v25 )
        {
          if ( (*(_BYTE *)(v25 + 49) & 2) != 0 )
          {
            v29 = v25;
            v34 = (unsigned int *)&v47 + 1;
            goto LABEL_28;
          }
          *a3 = 1;
          wlan_objmgr_vdev_release_ref(
            v25,
            0x18u,
            (unsigned int *)((char *)&off_0 + 1),
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23);
          if ( v15 == 2 )
            goto LABEL_34;
          v26 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                  a1,
                  BYTE2(v45),
                  24);
          if ( v26 )
          {
            if ( (*(_BYTE *)(v26 + 49) & 2) != 0 )
            {
              v29 = v26;
              v34 = (unsigned int *)&v48;
              goto LABEL_28;
            }
            *a3 = 1;
            wlan_objmgr_vdev_release_ref(
              v26,
              0x18u,
              (unsigned int *)((char *)&off_0 + 1),
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23);
            if ( v15 == 3 )
              goto LABEL_34;
            v27 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                    a1,
                    HIBYTE(v45),
                    24);
            if ( v27 )
            {
              if ( (*(_BYTE *)(v27 + 49) & 2) != 0 )
              {
                v29 = v27;
                v34 = (unsigned int *)&v48 + 1;
                goto LABEL_28;
              }
              *a3 = 1;
              wlan_objmgr_vdev_release_ref(
                v27,
                0x18u,
                (unsigned int *)((char *)&off_0 + 1),
                v16,
                v17,
                v18,
                v19,
                v20,
                v21,
                v22,
                v23);
              if ( v15 != 4 )
              {
                v28 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                        a1,
                        v46,
                        24);
                if ( v28 )
                {
                  v29 = v28;
                  if ( (*(_BYTE *)(v28 + 49) & 2) == 0 )
                  {
                    *a3 = 1;
                    wlan_objmgr_vdev_release_ref(
                      v28,
                      0x18u,
                      (unsigned int *)((char *)&off_0 + 1),
                      v16,
                      v17,
                      v18,
                      v19,
                      v20,
                      v21,
                      v22,
                      v23);
                    goto LABEL_34;
                  }
                  v34 = (unsigned int *)&v49;
LABEL_28:
                  qdf_trace_msg(
                    0x4Fu,
                    8u,
                    "%s: Restrict offchannel is set",
                    v16,
                    v17,
                    v18,
                    v19,
                    v20,
                    v21,
                    v22,
                    v23,
                    "policy_mgr_is_dnsc_set");
                  v43 = *v34;
                  if ( (_DWORD)v43 == a2
                    || (policy_mgr_2_freq_always_on_same_mac(a1, v43, a2) & 1) == 0
                    && (policy_mgr_is_hw_dbs_capable(a1) & 1) != 0 )
                  {
                    v44 = (_DWORD *)(&off_0 + 1);
                    *a3 = 1;
                  }
                  else
                  {
                    *a3 = 0;
                  }
                  wlan_objmgr_vdev_release_ref(v29, 0x18u, v44, v35, v36, v37, v38, v39, v40, v41, v42);
                  goto LABEL_34;
                }
                v33 = &v46;
                goto LABEL_25;
              }
LABEL_34:
              result = 0;
              goto LABEL_35;
            }
            v33 = (unsigned __int8 *)&v45 + 3;
          }
          else
          {
            v33 = (unsigned __int8 *)&v45 + 2;
          }
        }
        else
        {
          v33 = (unsigned __int8 *)&v45 + 1;
        }
      }
      else
      {
        v33 = (unsigned __int8 *)&v45;
      }
LABEL_25:
      v32 = *v33;
      v31 = "%s: vdev for vdev_id:%d is NULL";
      goto LABEL_26;
    }
    result = 0;
    *a3 = 1;
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid parameter",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "policy_mgr_is_chan_ok_for_dnbs");
    result = 4;
  }
LABEL_35:
  _ReadStatusReg(SP_EL0);
  return result;
}
