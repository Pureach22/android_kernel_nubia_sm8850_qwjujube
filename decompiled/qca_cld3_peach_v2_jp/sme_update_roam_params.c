__int64 __fastcall sme_update_roam_params(
        __int64 a1,
        unsigned int a2,
        unsigned __int8 *a3,
        unsigned __int8 *a4,
        int a5)
{
  __int64 psoc_ext_obj_fl; // x0
  __int64 v11; // x25
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  __int64 rso_user_config_fl; // x0
  unsigned int *v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned __int8 *v32; // x24
  int v33; // w9
  size_t v34; // x2
  size_t v35; // x2
  size_t v36; // x2
  size_t v37; // x2
  size_t v38; // x2
  size_t v39; // x2
  size_t v40; // x2
  size_t v41; // x2
  unsigned int v42; // w19
  int v43; // w8
  __int64 v44; // x8
  __int64 v45; // x9
  __int64 v46; // x12
  int v47; // w10
  unsigned __int64 v48; // x11

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(*(_QWORD *)(a1 + 21552));
  if ( !psoc_ext_obj_fl )
    return 16;
  v11 = psoc_ext_obj_fl;
  v12 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          *(_QWORD *)(a1 + 21552),
          a2,
          11);
  if ( !v12 )
    return 16;
  v21 = v12;
  rso_user_config_fl = wlan_cm_get_rso_user_config_fl(
                         v12,
                         (__int64)"sme_update_roam_params",
                         0x414u,
                         v13,
                         v14,
                         v15,
                         v16,
                         v17,
                         v18,
                         v19,
                         v20);
  if ( !rso_user_config_fl )
  {
    v42 = 16;
LABEL_30:
    wlan_objmgr_vdev_release_ref(v21, 0xBu, v23, v24, v25, v26, v27, v28, v29, v30, v31);
    return v42;
  }
  if ( a5 > 26 )
  {
    if ( a5 == 27 )
    {
      qdf_mem_set((void *)(v11 + 2365), 0x60u, 0);
      v43 = *a3;
      *(_BYTE *)(v11 + 2364) = v43;
      if ( v43 )
      {
        v44 = 2365;
        v45 = 2461;
        while ( 1 )
        {
          v46 = v11 + v44;
          v47 = *(_DWORD *)&a3[v44 - 2364];
          *(_WORD *)(v46 + 4) = *(_WORD *)&a3[v44 - 2360];
          *(_DWORD *)v46 = v47;
          if ( v44 == 2461 )
            goto LABEL_16;
          v48 = v45 - 2460;
          v44 += 6;
          *(_BYTE *)(v11 + v45) = a3[v45 - 2364];
          ++v45;
          if ( v48 >= *(unsigned __int8 *)(v11 + 2364) )
            goto LABEL_27;
        }
      }
    }
    else if ( a5 == 28 )
    {
      *(_DWORD *)(v11 + 2480) = *((_DWORD *)a3 + 29);
    }
    goto LABEL_27;
  }
  if ( a5 == 25 )
  {
    *(_DWORD *)(*(_QWORD *)(a1 + 8) + 1668LL) = *((_DWORD *)a3 + 32);
    *(_DWORD *)(*(_QWORD *)(a1 + 8) + 1680LL) = *((_DWORD *)a3 + 33);
    *(_DWORD *)(*(_QWORD *)(a1 + 8) + 1672LL) = a3[136];
    *(_DWORD *)(*(_QWORD *)(a1 + 8) + 1684LL) = a3[137];
    *(_DWORD *)(*(_QWORD *)(a1 + 8) + 1676LL) = *((_DWORD *)a3 + 35);
    *(_DWORD *)(v11 + 2484) = *((_DWORD *)a3 + 30);
    *(_DWORD *)(v11 + 2488) = *((_DWORD *)a3 + 31);
    *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1561LL) = 1;
LABEL_27:
    if ( !(unsigned int)qdf_mutex_acquire(a1 + 12776) )
    {
      wlan_roam_update_cfg(*(_QWORD *)(a1 + 21552), a2, a5);
      qdf_mutex_release(a1 + 12776);
    }
    v42 = 0;
    goto LABEL_30;
  }
  if ( a5 != 26 )
    goto LABEL_27;
  v32 = (unsigned __int8 *)rso_user_config_fl;
  qdf_mem_set((void *)(rso_user_config_fl + 1), 0x108u, 0);
  v33 = *a4;
  *v32 = v33;
  if ( !v33 )
    goto LABEL_27;
  v34 = a4[1];
  v32[1] = v34;
  qdf_mem_copy(v32 + 2, a4 + 2, v34);
  if ( *v32 <= 1u )
    goto LABEL_27;
  v35 = a4[34];
  v32[34] = v35;
  qdf_mem_copy(v32 + 35, a4 + 35, v35);
  if ( *v32 < 3u )
    goto LABEL_27;
  v36 = a4[67];
  v32[67] = v36;
  qdf_mem_copy(v32 + 68, a4 + 68, v36);
  if ( *v32 < 4u )
    goto LABEL_27;
  v37 = a4[100];
  v32[100] = v37;
  qdf_mem_copy(v32 + 101, a4 + 101, v37);
  if ( *v32 < 5u )
    goto LABEL_27;
  v38 = a4[133];
  v32[133] = v38;
  qdf_mem_copy(v32 + 134, a4 + 134, v38);
  if ( *v32 < 6u )
    goto LABEL_27;
  v39 = a4[166];
  v32[166] = v39;
  qdf_mem_copy(v32 + 167, a4 + 167, v39);
  if ( *v32 < 7u )
    goto LABEL_27;
  v40 = a4[199];
  v32[199] = v40;
  qdf_mem_copy(v32 + 200, a4 + 200, v40);
  if ( *v32 < 8u )
    goto LABEL_27;
  v41 = a4[232];
  v32[232] = v41;
  qdf_mem_copy(v32 + 233, a4 + 233, v41);
  if ( *v32 <= 8u )
    goto LABEL_27;
LABEL_16:
  __break(0x5512u);
  return 16;
}
