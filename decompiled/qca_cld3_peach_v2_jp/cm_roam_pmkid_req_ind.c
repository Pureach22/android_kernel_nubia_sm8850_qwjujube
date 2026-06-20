__int64 __fastcall cm_roam_pmkid_req_ind(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x21
  __int64 v14; // x19
  unsigned int *v15; // x8
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x20
  unsigned __int8 *v25; // x22
  int v26; // w0
  __int64 v28; // x5
  __int64 v29; // x6
  __int64 v30; // x7
  int v31; // w8

  v4 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 1);
  if ( v4 )
  {
    v13 = *(unsigned int *)(a3 + 16);
    v14 = v4;
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: Num entries %d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "cm_roam_pmkid_req_ind",
      (unsigned int)v13);
    if ( (_DWORD)v13 )
    {
      v24 = 0;
      v25 = (unsigned __int8 *)(a3 + 20);
      while ( 1 )
      {
        v26 = mlme_cm_osif_pmksa_candidate_notify(v14, (__int64)v25, 1, 0);
        if ( v26 )
          break;
        ++v24;
        v25 += 6;
        if ( v13 == v24 )
        {
          LODWORD(v13) = 0;
          goto LABEL_12;
        }
      }
      LODWORD(v13) = v26;
      if ( v25 )
      {
        v28 = *v25;
        v29 = v25[1];
        v30 = v25[2];
        v31 = v25[5];
      }
      else
      {
        v30 = 0;
        v28 = 0;
        v29 = 0;
        v31 = 0;
      }
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: Number %d Notify failed for %02x:%02x:%02x:**:**:%02x",
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        "cm_roam_pmkid_req_ind",
        (unsigned int)v24,
        v28,
        v29,
        v30,
        v31);
    }
LABEL_12:
    wlan_objmgr_vdev_release_ref(v14, 1u, v15, v16, v17, v18, v19, v20, v21, v22, v23);
    return (unsigned int)v13;
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: vdev object is NULL", v5, v6, v7, v8, v9, v10, v11, v12, "cm_roam_pmkid_req_ind");
    return 29;
  }
}
