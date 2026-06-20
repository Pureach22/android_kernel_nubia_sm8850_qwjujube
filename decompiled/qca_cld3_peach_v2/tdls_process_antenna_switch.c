__int64 __fastcall tdls_process_antenna_switch(
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
  __int64 v9; // x21
  unsigned int vdev_objects; // w20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int *v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  int v29; // w9
  unsigned __int8 v30; // w2
  __int64 v31; // x8
  int v32; // w1
  __int64 v33; // x0
  unsigned int v34; // w0
  unsigned int channel; // w0
  bool is_24ghz_ch_freq; // w0
  __int64 v37; // x22
  __int64 v38; // x8
  int v39; // w26
  unsigned __int8 i; // w27
  __int64 v41; // x8
  unsigned __int8 *all_peer; // x0
  unsigned __int8 *v43; // x25
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  int v52; // w8
  __int64 v53; // x8
  _DWORD *v54; // x10
  __int64 v55; // x0
  int v57; // [xsp+Ch] [xbp-34h] BYREF
  __int64 v58; // [xsp+10h] [xbp-30h] BYREF
  __int64 v59; // [xsp+18h] [xbp-28h] BYREF
  _QWORD v60[2]; // [xsp+20h] [xbp-20h] BYREF
  __int64 v61; // [xsp+30h] [xbp-10h]
  __int64 v62; // [xsp+38h] [xbp-8h]

  v62 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v58 = 0;
  v59 = 0;
  v57 = 0;
  v60[1] = 0;
  v61 = 0;
  v60[0] = 0;
  if ( a1 )
  {
    v9 = *(_QWORD *)a1;
    if ( *(_QWORD *)a1 )
    {
      vdev_objects = tdls_get_vdev_objects(*(_QWORD *)a1, &v58, &v59);
      if ( vdev_objects )
      {
        qdf_trace_msg(
          0,
          2u,
          "%s: can't get vdev_obj & soc_obj",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "tdls_process_antenna_switch");
LABEL_42:
        wlan_objmgr_vdev_release_ref(v9, 0x11u, v20, v21, v22, v23, v24, v25, v26, v27, v28);
        _qdf_mem_free(a1);
        goto LABEL_43;
      }
      v29 = *(unsigned __int16 *)(v59 + 202);
      if ( !*(_WORD *)(v59 + 202) )
      {
LABEL_34:
        v53 = v59;
        v54 = *(_DWORD **)(v59 + 264);
        if ( v54 )
        {
          v55 = *(_QWORD *)(v59 + 272);
          v60[0] = v9;
          LODWORD(v61) = v29;
          if ( *(v54 - 1) != 1890320457 )
            __break(0x822Au);
          ((void (__fastcall *)(__int64, __int64, _QWORD *))v54)(v55, 10, v60);
          v53 = v59;
        }
        if ( *(_BYTE *)(v53 + 214) == 1 && (*(_BYTE *)(v53 + 215) & 1) != 0 )
          *(_WORD *)(v53 + 214) = 0;
        qdf_trace_msg(
          0,
          8u,
          "%s: tdls_nss_switch_in_progress: %d tdls_nss_teardown_complete: %d",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "tdls_process_antenna_switch");
        goto LABEL_42;
      }
      if ( *(_BYTE *)(v59 + 214) == 1 )
      {
        if ( (*(_BYTE *)(v59 + 215) & 1) == 0 )
        {
          qdf_trace_msg(
            0,
            2u,
            "%s: TDLS antenna switch is in progress",
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            "tdls_process_antenna_switch");
LABEL_32:
          v29 = -11;
          goto LABEL_34;
        }
      }
      else
      {
        v30 = *(_BYTE *)(v9 + 168);
        v31 = *(_QWORD *)(v9 + 216);
        v32 = *(_DWORD *)(v9 + 16);
        v57 = v30;
        if ( v31 )
          v33 = *(_QWORD *)(v31 + 80);
        else
          v33 = 0;
        v34 = policy_mgr_qdf_opmode_to_pm_con_mode(v33, v32, v30, v12, v13, v14, v15, v16, v17, v18, v19);
        channel = policy_mgr_get_channel(*(_QWORD *)v59, v34, &v57);
        is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(channel);
        v37 = v59;
        v38 = 184;
        if ( !is_24ghz_ch_freq )
          v38 = 185;
        if ( *(_BYTE *)(v59 + v38) == 1 )
        {
          qdf_trace_msg(
            0,
            8u,
            "%s: Supported NSS is 1x1, no need to teardown TDLS links",
            v12,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            "tdls_process_antenna_switch");
        }
        else
        {
          v39 = *(_DWORD *)(a1 + 8);
          if ( *(_WORD *)(v59 + 200) )
          {
            for ( i = 0; *(unsigned __int16 *)(v37 + 200) > (unsigned int)i; ++i )
            {
              v41 = v37 + 32 + 9LL * i;
              if ( *(_BYTE *)(v41 + 1) == 1 )
              {
                all_peer = (unsigned __int8 *)tdls_find_all_peer(v37, v41 + 3);
                if ( all_peer )
                {
                  if ( all_peer[673] != 1 )
                  {
                    v43 = all_peer;
                    qdf_trace_msg(
                      0,
                      8u,
                      "%s: Indicate TDLS teardown peer bssid %02x:%02x:%02x:**:**:%02x",
                      v12,
                      v13,
                      v14,
                      v15,
                      v16,
                      v17,
                      v18,
                      v19,
                      "tdls_teardown_links",
                      all_peer[24],
                      all_peer[25],
                      all_peer[26],
                      all_peer[29]);
                    if ( (unsigned int)tdls_indicate_teardown(*((_QWORD *)v43 + 2), v43, 26) )
                      goto LABEL_32;
                    ++*(_DWORD *)(v37 + 220);
                  }
                }
              }
            }
          }
          if ( *(int *)(v37 + 220) >= 1 )
          {
            *(_BYTE *)(v37 + 214) = 1;
            qdf_trace_msg(
              0,
              8u,
              "%s: TDLS peers to be torn down = %d",
              v12,
              v13,
              v14,
              v15,
              v16,
              v17,
              v18,
              v19,
              "tdls_teardown_links");
            v52 = v39 == 1 ? 1 : 2;
            *(_DWORD *)(v37 + 216) = v52;
            qdf_trace_msg(
              0,
              8u,
              "%s: TDLS teardown for antenna switch operation starts",
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51,
              "tdls_teardown_links");
            if ( v39 == 1 )
              goto LABEL_32;
          }
        }
      }
      v29 = 0;
      goto LABEL_34;
    }
    qdf_trace_msg(0, 2u, "%s: null vdev", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_process_antenna_switch");
    _qdf_mem_free(a1);
    vdev_objects = 4;
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: null req", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_process_antenna_switch");
    vdev_objects = 4;
  }
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return vdev_objects;
}
