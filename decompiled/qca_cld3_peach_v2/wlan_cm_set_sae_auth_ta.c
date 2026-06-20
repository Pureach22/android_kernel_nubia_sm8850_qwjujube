__int64 __fastcall wlan_cm_set_sae_auth_ta(__int64 a1, char a2, __int64 a3)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x19
  __int64 ext_hdl; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w20
  unsigned int *v32; // x8
  __int64 v34; // [xsp+0h] [xbp-10h] BYREF
  __int64 v35; // [xsp+8h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v34) = a3;
  WORD2(v34) = WORD2(a3);
  if ( a1 && (vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(a1, a2, 0x4Du)) != nullptr )
  {
    v12 = (__int64)vdev_by_id_from_pdev;
    ext_hdl = wlan_vdev_mlme_get_ext_hdl((__int64)vdev_by_id_from_pdev, v4, v5, v6, v7, v8, v9, v10, v11);
    if ( ext_hdl )
    {
      v22 = ext_hdl;
      qdf_mem_copy((void *)(ext_hdl + 265), &v34, 6u);
      v31 = 0;
      v32 = (_DWORD *)(&off_0 + 1);
      *(_BYTE *)(v22 + 271) = 1;
    }
    else
    {
      qdf_trace_msg(
        0x1Fu,
        2u,
        "%s: vdev legacy private object is NULL",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wlan_cm_set_sae_auth_ta",
        v34,
        v35);
      v31 = 4;
    }
    wlan_objmgr_vdev_release_ref(v12, 0x4Du, v32, v23, v24, v25, v26, v27, v28, v29, v30);
  }
  else
  {
    v31 = 4;
  }
  _ReadStatusReg(SP_EL0);
  return v31;
}
