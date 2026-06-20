__int64 __fastcall wlan_mlme_update_sr_data(
        __int64 a1,
        int *a2,
        int a3,
        int a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 comp_private_obj; // x0
  char v19; // w24
  __int64 v20; // x0
  int v21; // w8
  const char *v22; // x2
  int v23; // w9
  unsigned int v25; // w8
  int v26; // w8
  const char *v27; // x2
  __int64 v28; // x0
  int v29; // w8
  int v30; // w9
  int v33; // w8
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  const char *v43; // x19
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 result; // x0

  if ( !a1 )
  {
    v22 = "%s: vdev is NULL";
LABEL_9:
    qdf_trace_msg(0x68u, 2u, v22, a6, a7, a8, a9, a10, a11, a12, a13, "wlan_vdev_mlme_get_cmpt_obj");
    v19 = 0;
    goto LABEL_10;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 0);
  if ( !comp_private_obj )
  {
    v22 = "%s:  MLME component object is NULL";
    goto LABEL_9;
  }
  v19 = *(_BYTE *)(comp_private_obj + 182);
  if ( (v19 & 2) != 0 )
  {
    if ( (*(_BYTE *)(comp_private_obj + 182) & 8) == 0 )
    {
      v26 = *a2;
      goto LABEL_46;
    }
    goto LABEL_30;
  }
  if ( (*(_BYTE *)(comp_private_obj + 182) & 4) != 0 )
  {
    v20 = wlan_objmgr_vdev_get_comp_private_obj(a1, 0);
    if ( v20 )
    {
      v21 = (char)(*(_BYTE *)(v20 + 183) - 82);
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s:  MLME component object is NULL",
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        "wlan_vdev_mlme_get_cmpt_obj");
      v21 = -82;
    }
    goto LABEL_11;
  }
LABEL_10:
  v21 = -62;
LABEL_11:
  if ( a4 <= -82 )
    v23 = -82;
  else
    v23 = a4;
  if ( v21 >= a4 && a4 != 0 )
    v21 = v23;
  if ( v21 >= -62 )
    a4 = -62;
  else
    a4 = v21;
  if ( (a5 & 1) != 0 )
    v25 = 0x80000000;
  else
    v25 = 0;
  v26 = *a2 | v25;
  *a2 = v26;
  if ( (v19 & 8) != 0 )
  {
    if ( !a1 )
    {
      v27 = "%s: vdev is NULL";
      goto LABEL_33;
    }
LABEL_30:
    v28 = wlan_objmgr_vdev_get_comp_private_obj(a1, 0);
    if ( v28 )
    {
      v29 = *(unsigned __int8 *)(v28 + 184) - 82;
      v30 = *(unsigned __int8 *)(v28 + 185) - 82;
LABEL_34:
      if ( v30 > a3 || v29 < a3 || a3 == 0 )
        a3 = v29;
      if ( (a5 & 1) != 0 )
        v33 = 0x40000000;
      else
        v33 = 0;
      v26 = *a2 | v33;
      goto LABEL_46;
    }
    v27 = "%s:  MLME component object is NULL";
LABEL_33:
    qdf_trace_msg(0x68u, 2u, v27, a6, a7, a8, a9, a10, a11, a12, a13, "wlan_vdev_mlme_get_cmpt_obj");
    v30 = -82;
    v29 = -82;
    goto LABEL_34;
  }
LABEL_46:
  *a2 = (unsigned __int8)a4 | v26 & 0xFFFF0000 | ((unsigned __int8)a3 << 8) | 0x20000000;
  if ( a1 )
  {
    v34 = wlan_objmgr_vdev_get_comp_private_obj(a1, 0);
    if ( v34 )
      *(_DWORD *)(v34 + 208) = a4;
    else
      qdf_trace_msg(
        0x68u,
        2u,
        "%s:  MLME component object is NULL",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "wlan_vdev_mlme_get_cmpt_obj");
    result = wlan_objmgr_vdev_get_comp_private_obj(a1, 0);
    if ( result )
    {
      *(_DWORD *)(result + 212) = a3;
      return result;
    }
    v43 = "%s:  MLME component object is NULL";
  }
  else
  {
    v43 = "%s: vdev is NULL";
    qdf_trace_msg(0x68u, 2u, "%s: vdev is NULL", a6, a7, a8, a9, a10, a11, a12, a13, "wlan_vdev_mlme_get_cmpt_obj");
  }
  return qdf_trace_msg(0x68u, 2u, v43, v44, v45, v46, v47, v48, v49, v50, v51, "wlan_vdev_mlme_get_cmpt_obj");
}
