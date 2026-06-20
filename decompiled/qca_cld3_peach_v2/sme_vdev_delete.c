__int64 __fastcall sme_vdev_delete(__int64 a1, __int64 a2)
{
  unsigned int v4; // w20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w22
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v32; // x0
  int v33; // w10
  int v34; // w9
  __int64 v35; // x21
  const void *v36; // x1
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int *v45; // x8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // [xsp+0h] [xbp-40h] BYREF
  __int64 v55; // [xsp+8h] [xbp-38h]
  __int64 (__fastcall *v56)(__int64, double, double, double, double, double, double, double, double); // [xsp+10h] [xbp-30h]
  __int64 v57; // [xsp+18h] [xbp-28h]
  __int64 v58; // [xsp+20h] [xbp-20h]
  __int64 v59; // [xsp+28h] [xbp-18h]
  __int64 v60; // [xsp+38h] [xbp-8h]

  v60 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned __int8 *)(a2 + 168);
  v58 = 0;
  v59 = 0;
  v56 = nullptr;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  qdf_trace(52, 0x31u, v4, 0);
  if ( (wlan_wifi_pos_pasn_peer_delete_all(*(_QWORD *)(a1 + 21624), v4) & 1) != 0 )
  {
    qdf_trace_msg(
      0x34u,
      4u,
      "%s: Resume vdev delete after pasn peers deletion",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "sme_vdev_delete",
      v54,
      v55,
      v56,
      v57,
      v58,
      v59);
    v13 = 0;
  }
  else
  {
    if ( !(unsigned int)qdf_mutex_acquire(a1 + 12848) )
    {
      csr_prepare_vdev_delete(a1, a2);
      qdf_mutex_release(a1 + 12848);
    }
    v22 = wlan_objmgr_vdev_obj_delete(a2, v14, v15, v16, v17, v18, v19, v20, v21);
    if ( v22 )
    {
      v13 = v22;
      qdf_trace_msg(
        0x34u,
        2u,
        "Failed to mark vdev as logical delete %d",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v22,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59);
    }
    else
    {
      v32 = _qdf_mem_malloc(0x18u, "sme_vdev_delete", 5414);
      if ( v32 )
      {
        v33 = *(unsigned __int16 *)(a2 + 84);
        v34 = *(_DWORD *)(a2 + 80);
        *(_QWORD *)(v32 + 16) = a2;
        v35 = v32;
        if ( v34 | v33 )
          v36 = (const void *)(a2 + 80);
        else
          v36 = (const void *)(a2 + 74);
        *(_BYTE *)(v32 + 6) = *(_BYTE *)(a2 + 168);
        qdf_mem_copy((void *)v32, v36, 6u);
        v55 = v35;
        v56 = mlme_vdev_self_peer_delete;
        v13 = scheduler_post_message_debug(
                0x34u,
                0x1Fu,
                73,
                (unsigned __int16 *)&v54,
                0x1538u,
                (__int64)"sme_vdev_delete");
        if ( v13 )
        {
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: Failed to post vdev selfpeer for vdev:%d",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "sme_vdev_delete",
            v4,
            v54);
          wlan_objmgr_vdev_release_ref(a2, 0xBu, v45, v46, v47, v48, v49, v50, v51, v52, v53);
          _qdf_mem_free(v35);
        }
      }
      else
      {
        v13 = 2;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return v13;
}
