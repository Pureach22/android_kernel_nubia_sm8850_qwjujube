__int64 __fastcall csr_get_vdev_dot11_mode(__int64 a1, unsigned __int8 a2, unsigned int a3)
{
  _QWORD *vdev_by_id_from_pdev; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  unsigned int *cmpt_obj; // x0
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w9
  unsigned __int64 v25; // x8
  bool v26; // cf
  bool v27; // zf
  bool v28; // vf
  unsigned int v29; // w21
  __int64 v30; // x0
  char v31; // w11
  char v32; // w9
  char v33; // w22
  char v34; // w23
  bool v35; // w20
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  int v44; // w8

  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(*(_QWORD *)(a1 + 21560), a2, 0x43u);
  if ( vdev_by_id_from_pdev )
  {
    v13 = (__int64)vdev_by_id_from_pdev;
    cmpt_obj = (unsigned int *)wlan_vdev_mlme_get_cmpt_obj(
                                 (__int64)vdev_by_id_from_pdev,
                                 v5,
                                 v6,
                                 v7,
                                 v8,
                                 v9,
                                 v10,
                                 v11,
                                 v12);
    if ( cmpt_obj )
    {
      v24 = a3 & 0xFFFFFFFE;
      LODWORD(v25) = (a3 & 0xFFFFFFFD) == 5;
      if ( (a3 & 0xFFFFFFFE) == 8 )
        LODWORD(v25) = 1;
      if ( v24 == 10 )
      {
        v28 = 0;
        v26 = 0;
        v27 = 1;
      }
      else
      {
        v28 = __OFSUB__(v24, 12);
        v26 = v24 >= 0xC;
        v27 = v24 == 12;
      }
      v29 = *cmpt_obj;
      v30 = v13;
      if ( v27 )
        v25 = 1;
      else
        v25 = (unsigned int)v25;
      v31 = v27;
      if ( v24 == 8 )
        v32 = 1;
      else
        v32 = v31;
      if ( a3 )
        v33 = v25;
      else
        v33 = 1;
      if ( a3 )
        v34 = v32;
      else
        v34 = 1;
      if ( (v28 << 28) & 0x40000000 | (v26 << 29) & 0x40000000 | (v27 << 30) & 0x40000000 )
        v35 = 1;
      else
        v35 = a3 == 0;
      wlan_objmgr_vdev_release_ref(v30, 0x43u, (unsigned int *)v25, v16, v17, v18, v19, v20, v21, v22, v23);
      if ( ((unsigned __int8)v33 & (v29 == 1)) != 0 )
        v44 = 5;
      else
        v44 = a3;
      if ( ((unsigned __int8)v34 & (v29 == 2)) != 0 )
        v44 = 8;
      if ( v35 && v29 == 3 )
        a3 = 10;
      else
        a3 = v44;
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: INI vdev_dot11_mode %d new dot11_mode %d",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "csr_get_vdev_dot11_mode",
        v29,
        a3);
    }
    else
    {
      wlan_objmgr_vdev_release_ref(v13, 0x43u, v15, v16, v17, v18, v19, v20, v21, v22, v23);
    }
  }
  return a3;
}
