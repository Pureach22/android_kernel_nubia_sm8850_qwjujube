__int64 __fastcall wlan_hdd_set_mon_chan(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x28
  int v10; // w8
  __int64 v11; // x21
  __int64 v12; // x20
  __int64 result; // x0
  unsigned int v15; // w22
  __int64 v16; // x20
  unsigned int v17; // w5
  unsigned int v18; // w4
  __int64 v19; // x22
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  unsigned int v53; // w0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x27
  int v72; // w8
  unsigned int v73; // w1
  __int16 v74; // w9
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  __int64 v83; // x27
  __int64 v84; // x27
  __int64 v85; // x0
  int is_up_active_state; // w0
  unsigned __int16 *v87; // x8
  __int64 v88; // x27
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  unsigned int v97; // w19
  __int64 v98; // x20
  unsigned int v99; // w21
  _QWORD v100[3]; // [xsp+8h] [xbp-18h] BYREF

  v9 = a1 + 49152;
  v100[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(unsigned __int8 *)(a1 + 52194);
  v11 = *(_QWORD *)(a1 + 24);
  v100[0] = 0;
  v100[1] = 0;
  if ( v10 == 1 )
  {
    v12 = jiffies;
    if ( wlan_hdd_set_mon_chan___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: monitor mode vdev up in progress",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "wlan_hdd_set_mon_chan");
      wlan_hdd_set_mon_chan___last_ticks = v12;
    }
    result = 4294967280LL;
    goto LABEL_48;
  }
  if ( a1 )
  {
    v15 = 4;
    if ( (*(_QWORD *)(a1 + 1640) & 1) != 0 )
    {
      v16 = a1 + 52832;
      if ( a1 != -52832 )
      {
        while ( 1 )
        {
          v17 = *(_DWORD *)(v16 + 80);
          if ( !v17 )
          {
            result = *(_QWORD *)(v16 + 32);
            if ( result )
            {
              if ( !(unsigned int)wlan_vdev_is_up_active_state(result) )
              {
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: Del vdev %d",
                  v89,
                  v90,
                  v91,
                  v92,
                  v93,
                  v94,
                  v95,
                  v96,
                  "wlan_hdd_set_mon_chan",
                  *(unsigned __int8 *)(v16 + 8));
                wlan_hdd_delete_mon_link(a1, v16);
              }
              result = 0;
            }
            goto LABEL_48;
          }
          v18 = *(unsigned __int8 *)(v16 + 8);
          if ( v18 == 255 )
            break;
          if ( v18 >= 6 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: bad vdev Id:%u (via %s)",
              a2,
              a3,
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              "__wlan_hdd_validate_vdev_id");
LABEL_16:
            qdf_trace_msg(0x33u, 8u, "%s: Create mon vdev", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_hdd_set_mon_chan");
            result = hdd_vdev_create(v16, v20, v21, v22, v23, v24, v25, v26, v27);
            if ( (_DWORD)result )
              goto LABEL_48;
            wlan_hdd_init_mon_link(v11, v16);
            v17 = *(_DWORD *)(v16 + 80);
            goto LABEL_18;
          }
          v85 = *(_QWORD *)(v16 + 32);
          if ( v85 )
          {
            is_up_active_state = wlan_vdev_is_up_active_state(v85);
            v17 = *(_DWORD *)(v16 + 80);
            if ( !is_up_active_state )
            {
              v87 = *(unsigned __int16 **)(*(_QWORD *)(v16 + 32) + 40LL);
              if ( v17 == *v87 && *((_DWORD *)v87 + 6) == *(_DWORD *)(v16 + 84) )
              {
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: vdev %u freq %d bw %d already set",
                  a2,
                  a3,
                  a4,
                  a5,
                  a6,
                  a7,
                  a8,
                  a9,
                  "wlan_hdd_set_mon_chan",
                  *(unsigned __int8 *)(v16 + 8));
                goto LABEL_41;
              }
            }
          }
LABEL_18:
          v28 = hdd_validate_channel_and_bandwidth(a1, v17, 0, *(_DWORD *)(v16 + 84), a2, a3, a4, a5, a6, a7, a8, a9);
          if ( v28 )
          {
            v97 = v28;
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Invalid CH %d and BW %d combo",
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              "wlan_hdd_set_mon_chan",
              *(unsigned int *)(v16 + 80),
              *(unsigned int *)(v16 + 80));
            result = v97;
            goto LABEL_48;
          }
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Set vdev %u monitor mode frequency %d",
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            "wlan_hdd_set_mon_chan",
            *(unsigned __int8 *)(v16 + 8),
            *(unsigned int *)(v16 + 80));
          if ( (unsigned int)wlan_hdd_change_hw_mode_for_given_chnl(
                               a1,
                               *(_DWORD *)(v16 + 80),
                               1u,
                               v37,
                               v38,
                               v39,
                               v40,
                               v41,
                               v42,
                               v43,
                               v44) )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Failed to change hw mode",
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              "wlan_hdd_set_mon_chan");
            result = 4294967274LL;
            goto LABEL_48;
          }
          if ( (unsigned int)ucfg_scan_get_pdev_status(*(_QWORD *)(v11 + 8), v45, v46, v47, v48, v49, v50, v51, v52) )
            wlan_abort_scan(
              *(_QWORD *)(v11 + 8),
              *(unsigned __int8 *)(*(_QWORD *)(v11 + 8) + 40LL),
              0xFFFFFFFF,
              0xFFFFFFFF,
              1);
          v53 = qdf_event_reset(a1 + 1664);
          if ( v53 )
          {
            v98 = jiffies;
            if ( wlan_hdd_set_mon_chan___last_ticks_201 - jiffies + 125 < 0 )
            {
              v99 = v53;
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: failed to reinit monitor vdev up event",
                v54,
                v55,
                v56,
                v57,
                v58,
                v59,
                v60,
                v61,
                "wlan_hdd_set_mon_chan");
              v53 = v99;
              wlan_hdd_set_mon_chan___last_ticks_201 = v98;
            }
            goto LABEL_47;
          }
          *(_BYTE *)(v9 + 3042) = 1;
          qdf_mem_set(v100, 0x10u, 0);
          v62 = _qdf_mem_malloc(0x40u, "wlan_hdd_set_mon_chan", 11346);
          if ( !v62 )
          {
            *(_BYTE *)(v9 + 3042) = 0;
            result = 4294967284LL;
            goto LABEL_48;
          }
          v71 = v62;
          *(_BYTE *)v62 = *(_BYTE *)(v16 + 8);
          *(_DWORD *)(v62 + 4) = *(_DWORD *)(v16 + 80);
          v72 = *(_DWORD *)(v16 + 84);
          *(_DWORD *)(v62 + 12) = v72;
          v73 = *(_DWORD *)(v16 + 80);
          LODWORD(v100[0]) = v72;
          hdd_select_cbmode(a1, v73, 0, v100, v63, v64, v65, v66, v67, v68, v69, v70);
          v74 = *(_WORD *)((char *)v100 + 5);
          *(_BYTE *)(v71 + 8) = BYTE4(v100[0]);
          *(_WORD *)(v71 + 16) = v74;
          sme_fill_channel_change_request(*(_QWORD *)(v11 + 16), v71, *(unsigned int *)(v16 + 92));
          v15 = sme_send_channel_change_req(*(_QWORD *)(v11 + 16), v71);
          _qdf_mem_free(v71);
          if ( v15 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Status: %d Failed to set sme_roam Channel for monitor mode",
              v75,
              v76,
              v77,
              v78,
              v79,
              v80,
              v81,
              v82,
              "wlan_hdd_set_mon_chan",
              v15);
            *(_BYTE *)(v9 + 3042) = 0;
            goto LABEL_46;
          }
          v15 = qdf_wait_for_event_completion(a1 + 1664, 0x2EE0u);
          if ( v15 )
          {
            v83 = jiffies;
            if ( wlan_hdd_set_mon_chan___last_ticks_204 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: monitor vdev up event time out vdev id: %d",
                a2,
                a3,
                a4,
                a5,
                a6,
                a7,
                a8,
                a9,
                "wlan_hdd_set_mon_chan",
                *(unsigned __int8 *)(v16 + 8));
              wlan_hdd_set_mon_chan___last_ticks_204 = v83;
            }
            if ( *(_BYTE *)(a1 + 1701) == 1 )
            {
              v84 = jiffies;
              if ( wlan_hdd_set_mon_chan___last_ticks_206 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: mon vdev up event forcefully set",
                  a2,
                  a3,
                  a4,
                  a5,
                  a6,
                  a7,
                  a8,
                  a9,
                  "wlan_hdd_set_mon_chan");
                wlan_hdd_set_mon_chan___last_ticks_206 = v84;
              }
            }
            else if ( v15 == 15 )
            {
              qdf_trace_msg(
                0x33u,
                2u,
                "%s: monitor mode vdev up timed out",
                a2,
                a3,
                a4,
                a5,
                a6,
                a7,
                a8,
                a9,
                "wlan_hdd_set_mon_chan");
            }
            else
            {
              v88 = jiffies;
              if ( wlan_hdd_set_mon_chan___last_ticks_209 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: Failed mon vdev up(status-%d)",
                  a2,
                  a3,
                  a4,
                  a5,
                  a6,
                  a7,
                  a8,
                  a9,
                  "wlan_hdd_set_mon_chan",
                  v15);
                wlan_hdd_set_mon_chan___last_ticks_209 = v88;
              }
            }
            *(_BYTE *)(v9 + 3042) = 0;
          }
LABEL_41:
          if ( a1 )
          {
            if ( (unsigned __int8)~(-910593773 * ((unsigned int)(v16 - *(_DWORD *)v16 - 52832) >> 4)) )
              goto LABEL_46;
            v16 = v9 + 3680;
            if ( (*(_QWORD *)(a1 + 1640) & 1) == 0 )
              goto LABEL_46;
          }
          if ( !v16 )
            goto LABEL_46;
        }
        v19 = jiffies;
        if ( _wlan_hdd_validate_vdev_id___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: adapter is not up (via %s)",
            a2,
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            "__wlan_hdd_validate_vdev_id",
            "wlan_hdd_set_mon_chan");
          _wlan_hdd_validate_vdev_id___last_ticks = v19;
        }
        goto LABEL_16;
      }
    }
  }
  else
  {
    v15 = 4;
  }
LABEL_46:
  v53 = v15;
LABEL_47:
  result = qdf_status_to_os_return(v53);
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
