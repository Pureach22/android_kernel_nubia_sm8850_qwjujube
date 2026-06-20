__int64 __fastcall tdls_set_peer_link_status(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x22
  __int64 v15; // x24
  const char *v16; // x5
  const char *v17; // x6
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 result; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x8
  __int64 v36; // x0
  __int64 comp_private_obj; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 *v46; // x21
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 v55; // x8
  __int64 v56; // x8
  __int64 v57; // x0
  __int64 v58; // x0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int v67; // w8
  __int64 v68; // x4
  __int64 v69; // x3
  const char *v70; // x2
  const char *v71; // x2
  __int64 v72; // x1
  __int64 v73; // x2
  __int64 (__fastcall *v74)(__int64, __int64, __int64, __int64, __int64, __int64); // x8
  __int64 v75; // x5
  _QWORD v76[2]; // [xsp+20h] [xbp-10h] BYREF

  v76[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(_QWORD *)(a1 + 16);
  v15 = *(unsigned int *)(a1 + 36);
  *(_DWORD *)(a1 + 36) = a2;
  v76[0] = 0;
  if ( a2 > 5 )
  {
    v16 = "UNKNOWN";
    if ( (unsigned int)v15 > 5 )
      goto LABEL_3;
  }
  else
  {
    v16 = off_B2DF08[a2];
    if ( (unsigned int)v15 > 5 )
    {
LABEL_3:
      v17 = "UNKNOWN";
      goto LABEL_6;
    }
  }
  v17 = off_B2DF08[v15];
LABEL_6:
  qdf_trace_msg(
    0,
    8u,
    "%s: vdev:%d new state: %s old state:%s reason %d peer:%02x:%02x:%02x:**:**:%02x",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "tdls_set_peer_link_status",
    *(unsigned __int8 *)(*(_QWORD *)v14 + 168LL),
    v16,
    v17,
    a3,
    *(unsigned __int8 *)(a1 + 24),
    *(unsigned __int8 *)(a1 + 25),
    *(unsigned __int8 *)(a1 + 26),
    *(unsigned __int8 *)(a1 + 29));
  result = tdls_update_pmo_status(v14, v15, a2, v18, v19, v20, v21, v22, v23, v24, v25);
  if ( a2 >= 2 )
    *(_WORD *)(a1 + 42) = 0;
  if ( *(_BYTE *)(a1 + 489) == 1 && *(_QWORD *)(a1 + 680) )
  {
    *(_DWORD *)(a1 + 676) = a3;
    if ( *(_QWORD *)v14 )
    {
      v35 = *(_QWORD *)(*(_QWORD *)v14 + 216LL);
      if ( v35 )
      {
        v36 = *(_QWORD *)(v35 + 80);
        if ( v36 )
        {
          comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v36, 0xAu);
          if ( comp_private_obj )
          {
            v46 = (__int64 *)comp_private_obj;
            tdls_determine_channel_opclass(
              comp_private_obj,
              v14,
              a1,
              (unsigned int *)v76,
              (_DWORD *)v76 + 1,
              v38,
              v39,
              v40,
              v41,
              v42,
              v43,
              v44,
              v45);
            v55 = **(_QWORD **)(a1 + 16);
            if ( v55 )
            {
              v56 = *(_QWORD *)(v55 + 216);
              if ( v56 )
              {
                v57 = *(_QWORD *)(v56 + 80);
                if ( v57 )
                {
                  v58 = wlan_objmgr_psoc_get_comp_private_obj(v57, 0xAu);
                  if ( v58 )
                  {
                    v67 = *(_DWORD *)(a1 + 36);
                    v68 = *(unsigned int *)(a1 + 676);
                    if ( v67 < 4 )
                      goto LABEL_19;
                    if ( v67 != 4 )
                    {
                      if ( v67 == 5 )
                        v69 = 5;
                      else
                        v69 = 0;
                      goto LABEL_29;
                    }
                    if ( (*(_BYTE *)(v58 + 156) & 1) != 0 && *(_DWORD *)(v58 + 208) == 1 )
                      v69 = 4;
                    else
LABEL_19:
                      v69 = 2;
LABEL_29:
                    v73 = LODWORD(v76[0]);
                    v72 = HIDWORD(v76[0]);
                    v74 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64))(a1 + 680);
                    v75 = *v46;
                    if ( *((_DWORD *)v74 - 1) != 1218055519 )
                      __break(0x8228u);
                    result = v74(a1 + 24, v72, v73, v69, v68, v75);
                    goto LABEL_24;
                  }
LABEL_28:
                  qdf_trace_msg(
                    0,
                    2u,
                    "%s: can't get tdls object",
                    v59,
                    v60,
                    v61,
                    v62,
                    v63,
                    v64,
                    v65,
                    v66,
                    "tdls_get_wifi_hal_state");
                  v69 = 0;
                  v68 = 0;
                  goto LABEL_29;
                }
              }
              v71 = "%s: can't get psoc";
            }
            else
            {
              v71 = "%s: NULL vdev";
            }
            qdf_trace_msg(0, 2u, v71, v47, v48, v49, v50, v51, v52, v53, v54, "wlan_vdev_get_tdls_soc_obj");
            goto LABEL_28;
          }
LABEL_23:
          result = qdf_trace_msg(
                     0,
                     2u,
                     "%s: NULL psoc object",
                     v38,
                     v39,
                     v40,
                     v41,
                     v42,
                     v43,
                     v44,
                     v45,
                     "tdls_set_peer_link_status");
          goto LABEL_24;
        }
      }
      v70 = "%s: can't get psoc";
    }
    else
    {
      v70 = "%s: NULL vdev";
    }
    qdf_trace_msg(0, 2u, v70, v27, v28, v29, v30, v31, v32, v33, v34, "wlan_vdev_get_tdls_soc_obj");
    goto LABEL_23;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
