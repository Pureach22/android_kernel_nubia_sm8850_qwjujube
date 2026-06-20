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
  int v9; // w8
  __int64 v10; // x20
  __int64 v11; // x20
  __int64 result; // x0
  __int64 v14; // x21
  unsigned int v15; // w22
  unsigned int v16; // w5
  unsigned int v17; // w4
  __int64 v18; // x22
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int v52; // w0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  __int64 v61; // x0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x27
  int v71; // w8
  unsigned int v72; // w1
  __int16 v73; // w9
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // x27
  __int64 v83; // x27
  __int64 v84; // x0
  int is_up_active_state; // w0
  unsigned __int16 *v86; // x8
  __int64 v87; // x27
  __int64 v88; // x8
  __int64 v89; // x9
  __int64 v90; // x10
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  unsigned int v99; // w19
  __int64 v100; // x20
  unsigned int v101; // w21
  __int64 v102; // [xsp+0h] [xbp-20h] BYREF
  __int64 v103; // [xsp+8h] [xbp-18h]
  __int64 v104; // [xsp+10h] [xbp-10h]
  __int64 v105; // [xsp+18h] [xbp-8h]

  v105 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(unsigned __int8 *)(a1 + 52194);
  v10 = *(_QWORD *)(a1 + 24);
  v103 = 0;
  v104 = 0;
  v102 = 0;
  if ( v9 == 1 )
  {
    v11 = jiffies;
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
        "wlan_hdd_set_mon_chan",
        v102,
        v103,
        v104,
        v105);
      wlan_hdd_set_mon_chan___last_ticks = v11;
    }
    result = 4294967280LL;
    goto LABEL_54;
  }
  if ( a1 )
  {
    if ( (*(_QWORD *)(a1 + 1640) & 1) != 0 && (v14 = a1 + 52840, a1 != -52840)
      || (*(_QWORD *)(a1 + 1640) & 2) != 0 && (v14 = a1 + 58928, a1 != -58928)
      || (v15 = 4, (*(_QWORD *)(a1 + 1640) & 4) != 0) && (v14 = a1 + 65016, a1 != -65016) )
    {
      v15 = 4;
      while ( 1 )
      {
        v16 = *(_DWORD *)(v14 + 80);
        if ( !v16 )
        {
          result = *(_QWORD *)(v14 + 32);
          if ( result )
          {
            if ( !(unsigned int)wlan_vdev_is_up_active_state(result) )
            {
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Del vdev %d",
                v91,
                v92,
                v93,
                v94,
                v95,
                v96,
                v97,
                v98,
                "wlan_hdd_set_mon_chan",
                *(unsigned __int8 *)(v14 + 8));
              wlan_hdd_delete_mon_link(a1, v14);
            }
            result = 0;
          }
          goto LABEL_54;
        }
        v17 = *(unsigned __int8 *)(v14 + 8);
        if ( v17 == 255 )
          break;
        if ( v17 >= 6 )
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
LABEL_20:
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Create mon vdev",
            a2,
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            "wlan_hdd_set_mon_chan",
            v102,
            v103,
            v104,
            v105);
          result = hdd_vdev_create(v14, v19, v20, v21, v22, v23, v24, v25, v26);
          if ( (_DWORD)result )
            goto LABEL_54;
          wlan_hdd_init_mon_link(v10, v14);
          v16 = *(_DWORD *)(v14 + 80);
          goto LABEL_22;
        }
        v84 = *(_QWORD *)(v14 + 32);
        if ( v84 )
        {
          is_up_active_state = wlan_vdev_is_up_active_state(v84);
          v16 = *(_DWORD *)(v14 + 80);
          if ( !is_up_active_state )
          {
            v86 = *(unsigned __int16 **)(*(_QWORD *)(v14 + 32) + 40LL);
            if ( v16 == *v86 && *((_DWORD *)v86 + 6) == *(_DWORD *)(v14 + 84) )
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
                *(unsigned __int8 *)(v14 + 8));
              goto LABEL_45;
            }
          }
        }
LABEL_22:
        v27 = hdd_validate_channel_and_bandwidth(a1, v16, 0, *(_DWORD *)(v14 + 84), a2, a3, a4, a5, a6, a7, a8, a9);
        if ( v27 )
        {
          v99 = v27;
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Invalid CH %d and BW %d combo",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "wlan_hdd_set_mon_chan",
            *(unsigned int *)(v14 + 80),
            *(unsigned int *)(v14 + 80));
          result = v99;
          goto LABEL_54;
        }
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Set vdev %u monitor mode frequency %d",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "wlan_hdd_set_mon_chan",
          *(unsigned __int8 *)(v14 + 8),
          *(unsigned int *)(v14 + 80));
        if ( (unsigned int)wlan_hdd_change_hw_mode_for_given_chnl(
                             a1,
                             *(_DWORD *)(v14 + 80),
                             1u,
                             v36,
                             v37,
                             v38,
                             v39,
                             v40,
                             v41,
                             v42,
                             v43) )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to change hw mode",
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            "wlan_hdd_set_mon_chan");
          result = 4294967274LL;
          goto LABEL_54;
        }
        if ( (unsigned int)ucfg_scan_get_pdev_status(*(_QWORD *)(v10 + 8), v44, v45, v46, v47, v48, v49, v50, v51) )
          wlan_abort_scan(
            *(_QWORD *)(v10 + 8),
            *(unsigned __int8 *)(*(_QWORD *)(v10 + 8) + 40LL),
            0xFFFFFFFF,
            0xFFFFFFFF,
            1);
        v52 = qdf_event_reset(a1 + 1664);
        if ( v52 )
        {
          v100 = jiffies;
          if ( wlan_hdd_set_mon_chan___last_ticks_214 - jiffies + 125 < 0 )
          {
            v101 = v52;
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: failed to reinit monitor vdev up event",
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              "wlan_hdd_set_mon_chan");
            v52 = v101;
            wlan_hdd_set_mon_chan___last_ticks_214 = v100;
          }
          goto LABEL_53;
        }
        *(_BYTE *)(a1 + 52194) = 1;
        qdf_mem_set(&v102, 0x18u, 0);
        v61 = _qdf_mem_malloc(0x40u, "wlan_hdd_set_mon_chan", 11346);
        if ( !v61 )
        {
          *(_BYTE *)(a1 + 52194) = 0;
          result = 4294967284LL;
          goto LABEL_54;
        }
        v70 = v61;
        *(_BYTE *)v61 = *(_BYTE *)(v14 + 8);
        *(_DWORD *)(v61 + 4) = *(_DWORD *)(v14 + 80);
        v71 = *(_DWORD *)(v14 + 84);
        *(_DWORD *)(v61 + 12) = v71;
        v72 = *(_DWORD *)(v14 + 80);
        LODWORD(v102) = v71;
        hdd_select_cbmode(a1, v72, 0, &v102, v62, v63, v64, v65, v66, v67, v68, v69);
        v73 = *(_WORD *)((char *)&v102 + 5);
        *(_BYTE *)(v70 + 8) = BYTE4(v102);
        *(_WORD *)(v70 + 16) = v73;
        sme_fill_channel_change_request(*(_QWORD *)(v10 + 16), v70, *(unsigned int *)(v14 + 92));
        v15 = sme_send_channel_change_req(*(_QWORD *)(v10 + 16), v70);
        _qdf_mem_free(v70);
        if ( v15 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Status: %d Failed to set sme_roam Channel for monitor mode",
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            v81,
            "wlan_hdd_set_mon_chan",
            v15);
          *(_BYTE *)(a1 + 52194) = 0;
          goto LABEL_52;
        }
        v15 = qdf_wait_for_event_completion(a1 + 1664, 0x2EE0u);
        if ( v15 )
        {
          v82 = jiffies;
          if ( wlan_hdd_set_mon_chan___last_ticks_217 - jiffies + 125 < 0 )
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
              *(unsigned __int8 *)(v14 + 8));
            wlan_hdd_set_mon_chan___last_ticks_217 = v82;
          }
          if ( *(_BYTE *)(a1 + 1701) == 1 )
          {
            v83 = jiffies;
            if ( wlan_hdd_set_mon_chan___last_ticks_219 - jiffies + 125 < 0 )
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
              wlan_hdd_set_mon_chan___last_ticks_219 = v83;
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
            v87 = jiffies;
            if ( wlan_hdd_set_mon_chan___last_ticks_222 - jiffies + 125 < 0 )
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
              wlan_hdd_set_mon_chan___last_ticks_222 = v87;
            }
          }
          *(_BYTE *)(a1 + 52194) = 0;
        }
LABEL_45:
        if ( a1 )
        {
          if ( (unsigned __int8)(73 * ((unsigned int)(v14 - *(_DWORD *)v14 - 52840) >> 3) + 1) > 2u )
            goto LABEL_52;
          v88 = (unsigned __int8)(73 * ((unsigned int)(v14 - *(_DWORD *)v14 - 52840) >> 3) + 1);
          v14 = 0;
          v89 = a1 + 52840 + 6088LL * (unsigned int)v88;
          do
          {
            if ( v14 )
              break;
            v90 = *(_QWORD *)(a1 + 1640) >> v88++;
            v14 = (v90 << 63 >> 63) & v89;
            v89 += 6088;
          }
          while ( v88 != 3 );
        }
        if ( !v14 )
          goto LABEL_52;
      }
      v18 = jiffies;
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
        _wlan_hdd_validate_vdev_id___last_ticks = v18;
      }
      goto LABEL_20;
    }
  }
  else
  {
    v15 = 4;
  }
LABEL_52:
  v52 = v15;
LABEL_53:
  result = qdf_status_to_os_return(v52);
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return result;
}
