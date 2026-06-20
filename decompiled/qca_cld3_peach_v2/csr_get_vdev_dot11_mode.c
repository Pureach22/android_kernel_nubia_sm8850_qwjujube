__int64 __fastcall csr_get_vdev_dot11_mode(__int64 a1, char a2, unsigned int a3)
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
  unsigned int v25; // w21
  __int64 v26; // x0
  _BOOL4 v27; // w8
  _BOOL4 v28; // w10
  char v29; // w11
  unsigned int *v30; // x8
  char v31; // w23
  char v32; // w22
  char v33; // w24
  bool v34; // w20
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w8

  vdev_by_id_from_pdev = wlan_objmgr_get_vdev_by_id_from_pdev(*(_QWORD *)(a1 + 21632), a2, 0x43u);
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
      v25 = *cmpt_obj;
      v26 = v13;
      v27 = (a3 & 0xFFFFFFFD) == 5;
      v28 = (a3 & 0xFFFFFFFE) == 10;
      if ( (a3 & 0xFFFFFFFE) == 0xC )
        v28 = 1;
      if ( v24 == 8 )
      {
        v27 = 1;
        v29 = 1;
      }
      else
      {
        v29 = v28;
      }
      v30 = (unsigned int *)(v28 | (unsigned int)v27);
      if ( a3 )
        v31 = v29;
      else
        v31 = 1;
      if ( a3 )
        v32 = (char)v30;
      else
        v32 = 1;
      if ( a3 )
        v33 = v28;
      else
        v33 = 1;
      v34 = v24 == 12 || a3 == 0;
      wlan_objmgr_vdev_release_ref(v26, 0x43u, v30, v16, v17, v18, v19, v20, v21, v22, v23);
      if ( ((unsigned __int8)v32 & (v25 == 1)) != 0 )
        v43 = 5;
      else
        v43 = a3;
      if ( ((unsigned __int8)v31 & (v25 == 2)) != 0 )
        v43 = 8;
      if ( ((unsigned __int8)v33 & (v25 == 3)) != 0 )
        v43 = 10;
      if ( v34 && v25 == 4 )
        a3 = 12;
      else
        a3 = v43;
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: INI vdev_dot11_mode %d new dot11_mode %d",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "csr_get_vdev_dot11_mode",
        v25,
        a3);
    }
    else
    {
      wlan_objmgr_vdev_release_ref(v13, 0x43u, v15, v16, v17, v18, v19, v20, v21, v22, v23);
    }
  }
  return a3;
}
