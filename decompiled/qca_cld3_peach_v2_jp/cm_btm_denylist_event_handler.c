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
  unsigned int v25; // w21
  unsigned __int8 *v26; // x22
  int v27; // w8
  int v28; // w9
  int v29; // w8
  __int64 result; // x0
  const char *v31; // x2
  _QWORD v32[2]; // [xsp+8h] [xbp-78h] BYREF
  __int64 v33; // [xsp+18h] [xbp-68h]
  __int64 v34; // [xsp+20h] [xbp-60h]
  __int64 v35; // [xsp+28h] [xbp-58h]
  __int64 v36; // [xsp+30h] [xbp-50h]
  __int64 v37; // [xsp+38h] [xbp-48h]
  __int64 v38; // [xsp+40h] [xbp-40h]
  __int64 v39; // [xsp+48h] [xbp-38h] BYREF
  __int64 v40; // [xsp+50h] [xbp-30h]
  __int64 v41; // [xsp+58h] [xbp-28h]
  __int64 v42; // [xsp+60h] [xbp-20h]
  __int128 v43; // [xsp+68h] [xbp-18h]
  __int64 v44; // [xsp+78h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a2;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v32[0] = 0;
  v32[1] = 0;
  pdev_id_from_vdev_id = wlan_get_pdev_id_from_vdev_id(a1, v4, 0x4Du);
  if ( pdev_id_from_vdev_id == -1 )
  {
    v31 = "%s: Invalid pdev id";
LABEL_16:
    qdf_trace_msg(0x68u, 2u, v31, v6, v7, v8, v9, v10, v11, v12, v13, "cm_btm_denylist_event_handler");
    result = 4;
    goto LABEL_17;
  }
  pdev_by_id = wlan_objmgr_get_pdev_by_id(a1, pdev_id_from_vdev_id, 0x4Du);
  if ( !pdev_by_id )
  {
    v31 = "%s: Invalid pdev";
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
      qdf_mem_set(v32, 0x40u, 0);
      v28 = *(_DWORD *)v26;
      WORD2(v33) = *((_WORD *)v26 + 2);
      LODWORD(v33) = v28;
      v35 = *((_QWORD *)v26 + 2);
      LODWORD(v36) = *((_DWORD *)v26 + 7);
      v29 = *((_DWORD *)v26 + 9);
      if ( !v29 )
        v29 = 2;
      HIDWORD(v36) = v29;
      LODWORD(v37) = *((_DWORD *)v26 + 8);
      v38 = *((_QWORD *)v26 + 2);
      if ( *((_DWORD *)v26 + 2) )
      {
        LOBYTE(v27) = 0;
        LODWORD(v34) = *((_DWORD *)v26 + 2);
      }
      else
      {
        if ( !*((_DWORD *)v26 + 6) )
          goto LABEL_7;
        LODWORD(v34) = 0;
        v27 = *((_DWORD *)v26 + 6);
      }
      BYTE4(v34) = v27;
      v43 = 0u;
      v41 = 0;
      v42 = 0;
      v39 = 0;
      v40 = 0;
      qdf_mem_set(&v39, 0x30u, 0);
      LODWORD(v43) = 4;
      LODWORD(v39) = v33;
      WORD2(v39) = WORD2(v33);
      LODWORD(v40) = v34;
      BYTE4(v40) = BYTE4(v34);
      *(_QWORD *)((char *)&v43 + 4) = v36;
      v41 = v38;
      LODWORD(v42) = v37;
      dlm_add_bssid_to_reject_list(v15, &v39);
      v26 += 40;
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
