__int64 __fastcall tdls_set_link_status(__int64 a1, unsigned __int8 *a2, unsigned int a3, unsigned int a4)
{
  _QWORD *peer; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x1
  _QWORD *v18; // x20
  __int64 result; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 comp_private_obj; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 *v39; // x21
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x8
  __int64 v49; // x8
  __int64 v50; // x0
  __int64 v51; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  unsigned int v60; // w8
  __int64 v61; // x4
  __int64 v62; // x3
  const char *v63; // x2
  const char *v64; // x2
  __int64 v65; // x1
  __int64 v66; // x2
  __int64 (__fastcall *v67)(unsigned __int8 *, __int64, __int64, __int64, __int64, __int64); // x8
  __int64 v68; // x5
  __int64 v69; // [xsp+0h] [xbp-10h] BYREF
  __int64 v70; // [xsp+8h] [xbp-8h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v69 = 0;
  peer = tdls_find_peer(a1, a2);
  if ( !peer )
  {
    result = qdf_trace_msg(
               0,
               2u,
               "%s: peer is NULL, can't set link status %d, reason %d",
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               "tdls_set_link_status",
               a3,
               a4);
    goto LABEL_21;
  }
  v17 = *((unsigned int *)peer + 9);
  v18 = peer;
  *((_DWORD *)peer + 9) = a3;
  result = tdls_update_pmo_status(a1, v17, a3);
  if ( a3 >= 2 )
    *((_WORD *)v18 + 21) = 0;
  if ( *((_BYTE *)v18 + 489) == 1 && v18[85] )
  {
    *((_DWORD *)v18 + 169) = a4;
    if ( *(_QWORD *)a1 )
    {
      v28 = *(_QWORD *)(*(_QWORD *)a1 + 216LL);
      if ( v28 )
      {
        v29 = *(_QWORD *)(v28 + 80);
        if ( v29 )
        {
          comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v29, 0xAu);
          if ( comp_private_obj )
          {
            v39 = (__int64 *)comp_private_obj;
            tdls_determine_channel_opclass(comp_private_obj, a1, v18, &v69, (char *)&v69 + 4);
            v48 = *(_QWORD *)v18[2];
            if ( v48 )
            {
              v49 = *(_QWORD *)(v48 + 216);
              if ( v49 )
              {
                v50 = *(_QWORD *)(v49 + 80);
                if ( v50 )
                {
                  v51 = wlan_objmgr_psoc_get_comp_private_obj(v50, 0xAu);
                  if ( v51 )
                  {
                    v60 = *((_DWORD *)v18 + 9);
                    v61 = *((unsigned int *)v18 + 169);
                    if ( v60 < 4 )
                      goto LABEL_15;
                    if ( v60 != 4 )
                    {
                      if ( v60 == 5 )
                        v62 = 5;
                      else
                        v62 = 0;
                      goto LABEL_26;
                    }
                    if ( (*(_BYTE *)(v51 + 156) & 1) != 0 && *(_DWORD *)(v51 + 208) == 1 )
                      v62 = 4;
                    else
LABEL_15:
                      v62 = 2;
LABEL_26:
                    v66 = (unsigned int)v69;
                    v65 = HIDWORD(v69);
                    v67 = (__int64 (__fastcall *)(unsigned __int8 *, __int64, __int64, __int64, __int64, __int64))v18[85];
                    v68 = *v39;
                    if ( *((_DWORD *)v67 - 1) != 1218055519 )
                      __break(0x8228u);
                    result = v67(a2, v65, v66, v62, v61, v68);
                    goto LABEL_21;
                  }
LABEL_25:
                  qdf_trace_msg(
                    0,
                    2u,
                    "%s: can't get tdls object",
                    v52,
                    v53,
                    v54,
                    v55,
                    v56,
                    v57,
                    v58,
                    v59,
                    "tdls_get_wifi_hal_state",
                    v69);
                  v62 = 0;
                  v61 = 0;
                  goto LABEL_26;
                }
              }
              v64 = "%s: can't get psoc";
            }
            else
            {
              v64 = "%s: NULL vdev";
            }
            qdf_trace_msg(0, 2u, v64, v40, v41, v42, v43, v44, v45, v46, v47, "wlan_vdev_get_tdls_soc_obj", v69, v70);
            goto LABEL_25;
          }
LABEL_20:
          result = qdf_trace_msg(
                     0,
                     2u,
                     "%s: NULL psoc object",
                     v31,
                     v32,
                     v33,
                     v34,
                     v35,
                     v36,
                     v37,
                     v38,
                     "tdls_set_link_status",
                     v69);
          goto LABEL_21;
        }
      }
      v63 = "%s: can't get psoc";
    }
    else
    {
      v63 = "%s: NULL vdev";
    }
    qdf_trace_msg(0, 2u, v63, v20, v21, v22, v23, v24, v25, v26, v27, "wlan_vdev_get_tdls_soc_obj", v69, v70);
    goto LABEL_20;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
