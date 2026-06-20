__int64 __fastcall hdd_set_nss_params(__int64 *a1, unsigned __int8 a2, unsigned __int8 a3)
{
  __int64 v6; // x23
  __int64 v7; // x24
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x22
  _QWORD *vdev_by_id_from_pdev; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int *v26; // x8
  __int64 v27; // x2
  __int64 result; // x0
  __int64 v29; // x23
  __int64 v30; // x0
  unsigned int v31; // w8
  __int64 v32; // x0
  __int64 cmpt_obj; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x4
  unsigned int *v43; // x8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  _QWORD v52[2]; // [xsp+0h] [xbp-40h] BYREF
  __int64 v53; // [xsp+10h] [xbp-30h]
  __int64 v54; // [xsp+18h] [xbp-28h]
  __int64 v55; // [xsp+20h] [xbp-20h]
  __int64 v56; // [xsp+28h] [xbp-18h]
  __int64 v57; // [xsp+30h] [xbp-10h]
  __int64 v58; // [xsp+38h] [xbp-8h]

  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *a1;
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v7 = *(_QWORD *)(v6 + 24);
  v52[1] = 0;
  v53 = 0;
  v52[0] = 0;
  qdf_mem_set(v52, 0x38u, 0);
  v16 = *(_QWORD *)(v7 + 16);
  if ( v16 )
  {
    vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(*(_QWORD *)(v7 + 8), *((_BYTE *)a1 + 8), 5u);
    if ( vdev_by_id_from_pdev )
    {
      v26 = (unsigned int *)(*(_DWORD *)(v6 + 40) | 2u);
      if ( (_DWORD)v26 == 3
        || ((v29 = (__int64)vdev_by_id_from_pdev,
             (v30 = wlan_vdev_mlme_get_cmpt_obj((__int64)vdev_by_id_from_pdev, v18, v19, v20, v21, v22, v23, v24, v25)) == 0)
          ? (v31 = 0)
          : (v31 = *(unsigned __int8 *)(v30 + 23)),
            (vdev_by_id_from_pdev = (_QWORD *)v29, v31 >= a2)
         && ((v32 = wlan_vdev_mlme_get_cmpt_obj(v29, v18, v19, v20, v21, v22, v23, v24, v25)) == 0
           ? (v26 = nullptr)
           : (v26 = (unsigned int *)*(unsigned __int8 *)(v32 + 23)),
             vdev_by_id_from_pdev = (_QWORD *)v29,
             (unsigned int)v26 >= a3)) )
      {
        wlan_objmgr_vdev_release_ref((__int64)vdev_by_id_from_pdev, 5u, v26, v18, v19, v20, v21, v22, v23, v24, v25);
        v27 = *((unsigned __int8 *)a1 + 8);
        LODWORD(v54) = a3;
        HIDWORD(v54) = a3;
        LODWORD(v53) = a2;
        HIDWORD(v53) = a2;
        result = 16 * (unsigned int)((unsigned int)sme_nss_chains_update(v16, v52, v27) != 0);
      }
      else
      {
        cmpt_obj = wlan_vdev_mlme_get_cmpt_obj((__int64)vdev_by_id_from_pdev, v18, v19, v20, v21, v22, v23, v24, v25);
        if ( cmpt_obj )
          v42 = *(unsigned __int8 *)(cmpt_obj + 23);
        else
          v42 = 0;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Given tx nss/rx nss is greater than intersected nss = %d",
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          "hdd_set_nss_params",
          v42);
        wlan_objmgr_vdev_release_ref(v29, 5u, v43, v44, v45, v46, v47, v48, v49, v50, v51);
        result = 16;
      }
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: vdev is NULL %d",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "hdd_set_nss_params",
        *((unsigned __int8 *)a1 + 8));
      result = 4;
    }
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: NULL MAC handle", v8, v9, v10, v11, v12, v13, v14, v15, "hdd_set_nss_params");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
