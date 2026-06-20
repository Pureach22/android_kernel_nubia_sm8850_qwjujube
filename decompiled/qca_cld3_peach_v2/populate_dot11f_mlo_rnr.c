__int64 __fastcall populate_dot11f_mlo_rnr(__int64 a1, __int64 a2, __int64 a3, _WORD *a4)
{
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w8
  __int64 v18; // x23
  unsigned int v19; // w25
  char v20; // w24
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 session_by_vdev_id; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x27
  __int64 v39; // x1
  unsigned int v42; // w8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // [xsp+0h] [xbp-40h]
  unsigned __int16 v52; // [xsp+14h] [xbp-2Ch] BYREF
  int v53; // [xsp+18h] [xbp-28h] BYREF
  __int16 v54; // [xsp+1Ch] [xbp-24h]
  int v55; // [xsp+20h] [xbp-20h] BYREF
  __int16 v56; // [xsp+24h] [xbp-1Ch]
  _QWORD v57[3]; // [xsp+28h] [xbp-18h] BYREF

  v57[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v52 = 0;
  v57[0] = 0;
  v57[1] = 0;
  result = lim_get_mlo_vdev_list(a2, &v52, v57);
  v17 = v52;
  if ( v52 )
  {
    v18 = 0;
    v19 = 0;
    v20 = 0;
    while ( 1 )
    {
      if ( v18 == 2 )
        __break(0x5512u);
      result = v57[v18];
      if ( !result )
        goto LABEL_5;
      if ( result != *(_QWORD *)(a2 + 16)
        && *(_DWORD *)(result + 16) == 1
        && (wlan_vdev_mlme_is_mlo_vdev(result, v9, v10, v11, v12, v13, v14, v15, v16) & 1) != 0 )
      {
        session_by_vdev_id = pe_find_session_by_vdev_id(
                               a1,
                               *(_BYTE *)(v57[v18] + 168LL),
                               v21,
                               v22,
                               v23,
                               v24,
                               v25,
                               v26,
                               v27,
                               v28);
        if ( session_by_vdev_id )
        {
          if ( *(_BYTE *)(a1 + 14881) )
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: skip rnrie populate if cac running",
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              "populate_dot11f_mlo_rnr");
          }
          else
          {
            v38 = session_by_vdev_id;
            v56 = 0;
            v55 = 0;
            v54 = 0;
            v53 = 0;
            qdf_mem_copy(&v55, (const void *)(a2 + 13233), 6u);
            qdf_mem_copy(&v53, (const void *)(v38 + 30), 6u);
            if ( *(unsigned __int8 *)(a2 + 13226) << 8 == 4096 && v55 == v53 && v56 == v54 )
            {
              v42 = 0;
              v20 = 1;
              goto LABEL_28;
            }
            v56 = 0;
            v55 = 0;
            v54 = 0;
            v53 = 0;
            qdf_mem_copy(&v55, (const void *)(a2 + 13261), 6u);
            qdf_mem_copy(&v53, (const void *)(v38 + 30), 6u);
            if ( *(unsigned __int8 *)(a2 + 13254) << 8 == 4096 && v55 == v53 && v56 == v54 )
            {
              v42 = 1;
              v20 = 1;
LABEL_28:
              if ( v19 <= 1 )
              {
                populate_dot11f_rnr_tbtt_info_16(a1, v39, v38, a3 + 784LL * v19, a2 + 13224 + 28LL * v42);
                LODWORD(v51) = *(unsigned __int8 *)(a3 + 4);
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: mlo vdev id %d populate vdev id %d link id %d op class %d chan num %d in RNR IE",
                  v43,
                  v44,
                  v45,
                  v46,
                  v47,
                  v48,
                  v49,
                  v50,
                  "populate_dot11f_mlo_rnr",
                  *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 168LL),
                  *(unsigned __int8 *)(v57[v18] + 168LL),
                  *(_DWORD *)(a3 + 23) & 0xF,
                  *(unsigned __int8 *)(a3 + 3),
                  v51);
                v20 = 0;
                ++v19;
              }
              goto LABEL_4;
            }
            v42 = 2;
            if ( (v20 & 1) != 0 )
              goto LABEL_28;
          }
        }
        else
        {
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: vdev id %d pe session is not created",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "populate_dot11f_mlo_rnr",
            *(unsigned __int8 *)(v57[v18] + 168LL));
        }
      }
LABEL_4:
      result = lim_mlo_release_vdev_ref(v57[v18]);
      v17 = v52;
LABEL_5:
      if ( ++v18 >= (unsigned __int64)v17 )
        goto LABEL_31;
    }
  }
  LOWORD(v19) = 0;
LABEL_31:
  *a4 = v19;
  _ReadStatusReg(SP_EL0);
  return result;
}
