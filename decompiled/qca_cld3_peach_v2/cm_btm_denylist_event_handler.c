__int64 __fastcall cm_btm_denylist_event_handler(__int64 a1, unsigned __int8 *a2)
{
  __int64 v4; // x1
  int pdev_id_from_vdev_id; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 pdev_by_id; // x0
  __int64 v15; // x20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int *v24; // x8
  unsigned int v25; // w22
  unsigned __int8 *v26; // x23
  int v27; // w8
  int v28; // w10
  int v29; // w9
  __int16 v30; // w8
  unsigned __int8 v31; // w8
  unsigned int v32; // w21
  int v33; // w9
  int v34; // w8
  __int64 result; // x0
  const char *v36; // x2
  _QWORD v37[2]; // [xsp+8h] [xbp-E8h] BYREF
  __int64 v38; // [xsp+18h] [xbp-D8h]
  __int64 v39; // [xsp+20h] [xbp-D0h]
  __int64 v40; // [xsp+28h] [xbp-C8h]
  __int64 v41; // [xsp+30h] [xbp-C0h]
  __int64 v42; // [xsp+38h] [xbp-B8h]
  __int64 v43; // [xsp+40h] [xbp-B0h]
  __int64 v44; // [xsp+48h] [xbp-A8h]
  _QWORD v45[5]; // [xsp+50h] [xbp-A0h] BYREF
  __int64 v46; // [xsp+78h] [xbp-78h]
  __int64 v47; // [xsp+80h] [xbp-70h] BYREF
  __int64 v48; // [xsp+88h] [xbp-68h]
  _QWORD v49[5]; // [xsp+90h] [xbp-60h] BYREF
  __int64 v50; // [xsp+B8h] [xbp-38h]
  __int64 v51; // [xsp+C0h] [xbp-30h]
  __int64 v52; // [xsp+C8h] [xbp-28h]
  __int64 v53; // [xsp+D0h] [xbp-20h]
  __int128 v54; // [xsp+D8h] [xbp-18h]
  __int64 v55; // [xsp+E8h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a2;
  v46 = 0;
  memset(v45, 0, sizeof(v45));
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37[1] = 0;
  v38 = 0;
  v37[0] = 0;
  pdev_id_from_vdev_id = wlan_get_pdev_id_from_vdev_id(a1, v4, 0x4Du);
  if ( pdev_id_from_vdev_id == -1 )
  {
    v36 = "%s: Invalid pdev id";
LABEL_16:
    qdf_trace_msg(0x68u, 2u, v36, v6, v7, v8, v9, v10, v11, v12, v13, "cm_btm_denylist_event_handler");
    result = 4;
    goto LABEL_17;
  }
  pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, pdev_id_from_vdev_id, 0x4Du);
  if ( !pdev_by_id )
  {
    v36 = "%s: Invalid pdev";
    goto LABEL_16;
  }
  v15 = pdev_by_id;
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: Received Denylist event from FW num entries %d",
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    "cm_btm_denylist_event_handler",
    *((unsigned int *)a2 + 1));
  v24 = (unsigned int *)*((unsigned int *)a2 + 1);
  if ( (_DWORD)v24 )
  {
    v25 = 0;
    v26 = a2 + 8;
    do
    {
      qdf_mem_set(v37, 0x78u, 0);
      v33 = *(_DWORD *)v26;
      WORD2(v38) = *((_WORD *)v26 + 2);
      LODWORD(v38) = v33;
      v40 = *((_QWORD *)v26 + 2);
      LODWORD(v41) = *((_DWORD *)v26 + 7);
      v34 = *((_DWORD *)v26 + 9);
      if ( !v34 )
        v34 = 2;
      HIDWORD(v41) = v34;
      LODWORD(v42) = *((_DWORD *)v26 + 8);
      v43 = *((_QWORD *)v26 + 2);
      if ( *((_DWORD *)v26 + 2) )
      {
        LOBYTE(v27) = 0;
        LODWORD(v39) = *((_DWORD *)v26 + 2);
      }
      else
      {
        if ( !*((_DWORD *)v26 + 6) )
          goto LABEL_7;
        LODWORD(v39) = 0;
        v27 = *((_DWORD *)v26 + 6);
      }
      v28 = v26[88];
      v29 = *((_DWORD *)v26 + 10);
      BYTE4(v39) = v27;
      v30 = *((_WORD *)v26 + 22);
      LODWORD(v44) = v29;
      WORD2(v44) = v30;
      qdf_mem_copy(v45, v26 + 48, (unsigned int)(4 * v28));
      v31 = v26[88];
      v32 = *a2;
      v54 = 0u;
      LOBYTE(v46) = v31;
      v52 = 0;
      v53 = 0;
      v50 = 0;
      v51 = 0;
      v48 = 0;
      memset(v49, 0, sizeof(v49));
      v47 = 0;
      qdf_mem_set(&v47, 0x68u, 0);
      LODWORD(v54) = 4;
      LODWORD(v47) = v38;
      WORD2(v47) = WORD2(v38);
      LODWORD(v51) = v39;
      BYTE4(v51) = BYTE4(v39);
      *(_QWORD *)((char *)&v54 + 4) = v41;
      v52 = v43;
      LODWORD(v53) = v42;
      WORD2(v48) = WORD2(v44);
      LODWORD(v48) = v44;
      qdf_mem_copy(v49, v45, 4 * (unsigned int)(unsigned __int8)v46);
      LOBYTE(v50) = v46;
      ((void (__fastcall *)(__int64, _QWORD, __int64 *))dlm_update_mlo_reject_ap_info)(v15, v32, &v47);
      dlm_add_bssid_to_reject_list(v15, &v47);
      v26 += 96;
LABEL_7:
      v24 = (unsigned int *)*((unsigned int *)a2 + 1);
      ++v25;
    }
    while ( v25 < (unsigned int)v24 );
  }
  wlan_objmgr_pdev_release_ref(v15, 0x4Du, v24, v16, v17, v18, v19, v20, v21, v22, v23);
  result = 0;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
