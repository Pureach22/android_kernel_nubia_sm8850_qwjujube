__int64 __fastcall tdls_get_all_peers_from_list(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x8
  __int64 v11; // x21
  __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 comp_private_obj; // x0
  __int64 v31; // x22
  double v32; // d0
  int v33; // w0
  int v34; // w20
  __int64 v35; // x21
  int v36; // w0
  __int64 v37; // x21
  __int64 v38; // x24
  __int64 v39; // x25
  int v40; // w26
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x3
  __int64 v50; // x4
  __int64 v51; // x5
  __int64 v52; // x6
  char *v53; // x7
  char *v54; // x9
  int v55; // w0
  __int64 v56; // x8
  __int64 v57; // x8
  __int64 v58; // x0
  __int64 v59; // x0
  _DWORD *v60; // x8
  __int64 v61; // x0
  const char *v62; // x2
  __int64 result; // x0
  __int64 v64; // [xsp+8h] [xbp-38h]
  int v65; // [xsp+10h] [xbp-30h]
  _QWORD *v66; // [xsp+18h] [xbp-28h] BYREF
  _QWORD v67[2]; // [xsp+20h] [xbp-20h] BYREF
  __int64 v68; // [xsp+30h] [xbp-10h]
  __int64 v69; // [xsp+38h] [xbp-8h]

  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)a1;
  v67[1] = 0;
  v68 = 0;
  v67[0] = 0;
  if ( !v10 )
    goto LABEL_35;
  v66 = nullptr;
  qdf_trace_msg(0, 4u, "%s: Enter ", a2, a3, a4, a5, a6, a7, a8, a9, "__tdls_get_all_peers_from_list");
  v11 = *(_QWORD *)(a1 + 8);
  v12 = *(int *)(a1 + 16);
  if ( (unsigned int)wlan_vdev_is_up() )
  {
    v22 = scnprintf(v11, v12, "\nSTA is not associated\n");
    goto LABEL_24;
  }
  if ( !*(_QWORD *)a1 )
  {
    qdf_trace_msg(0, 2u, "%s: NULL vdev", v13, v14, v15, v16, v17, v18, v19, v20, "wlan_vdev_get_tdls_vdev_obj");
    goto LABEL_23;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(*(_QWORD *)a1, 0xAu);
  if ( !comp_private_obj )
  {
LABEL_23:
    v22 = scnprintf(v11, v12, "TDLS not enabled\n");
    goto LABEL_24;
  }
  v31 = comp_private_obj;
  v32 = scnprintf(v11, v12, "\n%-18s%-3s%-4s%-3s%-5s\n", "MAC", "Id", "cap", "up", "RSSI");
  v65 = v12;
  v34 = v12 - v33;
  v35 = v11 + v33;
  scnprintf(v35, v34, "---------------------------------\n", v32);
  v37 = v35 + v36;
  v38 = 0;
  v39 = v31 + 8;
  v40 = v34 - v36;
  do
  {
    if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(v39 + 24 * v38), &v66) )
    {
      do
      {
        if ( v40 < 33 )
          break;
        if ( v66 == (_QWORD *)-24LL )
        {
          v51 = 0;
          v49 = 0;
          v50 = 0;
          v52 = 0;
        }
        else
        {
          v49 = *((unsigned __int8 *)v66 + 24);
          v50 = *((unsigned __int8 *)v66 + 25);
          v51 = *((unsigned __int8 *)v66 + 26);
          v52 = *((unsigned __int8 *)v66 + 29);
        }
        v53 = *((_DWORD *)v66 + 8) == 1 ? "Y" : "N";
        v54 = (*((_DWORD *)v66 + 9) & 0xFFFFFFFE) == 4 ? "Y" : "N";
        LODWORD(v64) = *((char *)v66 + 31);
        scnprintf(v37, (unsigned int)v40, "%02x:%02x:%02x:**:**:%02x%4s%3s%5d\n", v49, v50, v51, v52, v53, v54, v64);
        v37 += v55;
        v40 -= v55;
      }
      while ( !(unsigned int)qdf_list_peek_next((_QWORD *)(v39 + 24 * v38), v66, &v66) );
    }
    ++v38;
  }
  while ( v38 != 16 );
  qdf_trace_msg(0, 4u, "%s: Exit ", v41, v42, v43, v44, v45, v46, v47, v48, "__tdls_get_all_peers_from_list");
  v21 = v65 - v40;
LABEL_24:
  v56 = *(_QWORD *)a1;
  LODWORD(v68) = v21;
  v67[0] = v56;
  if ( !v56 )
  {
    v62 = "%s: NULL vdev";
    goto LABEL_34;
  }
  v57 = *(_QWORD *)(v56 + 216);
  if ( !v57 || (v58 = *(_QWORD *)(v57 + 80)) == 0 )
  {
    v62 = "%s: can't get psoc";
LABEL_34:
    qdf_trace_msg(0, 2u, v62, v22, v23, v24, v25, v26, v27, v28, v29, "wlan_vdev_get_tdls_soc_obj");
    goto LABEL_35;
  }
  v59 = wlan_objmgr_psoc_get_comp_private_obj(v58, 0xAu);
  if ( v59 )
  {
    v60 = *(_DWORD **)(v59 + 264);
    if ( v60 )
    {
      v61 = *(_QWORD *)(v59 + 272);
      if ( *(v60 - 1) != 1890320457 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, __int64, _QWORD *))v60)(v61, 9, v67);
    }
  }
LABEL_35:
  result = _qdf_mem_free(a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
