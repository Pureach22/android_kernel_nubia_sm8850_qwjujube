__int64 __fastcall tdls_set_link_mode(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x0
  char is_mlo_vdev; // w8
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  __int64 v21; // x8
  __int64 v22; // x20
  int v23; // w8
  int is_ml_links_in_mcc_allowed; // w21
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x8
  __int64 v34; // x1
  __int64 v35; // x8
  __int64 v36; // x1
  _BYTE v37[4]; // [xsp+4h] [xbp-2Ch] BYREF
  __int64 v38; // [xsp+8h] [xbp-28h] BYREF
  __int64 v39; // [xsp+10h] [xbp-20h]
  __int64 v40; // [xsp+18h] [xbp-18h]
  int v41; // [xsp+20h] [xbp-10h] BYREF
  char v42; // [xsp+24h] [xbp-Ch]
  __int64 v43; // [xsp+28h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)a1;
  v39 = 0;
  v40 = 0;
  v38 = 0;
  v37[0] = 0;
  v42 = 0;
  v41 = 0;
  is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v10, a2, a3, a4, a5, a6, a7, a8, a9);
  result = 0;
  if ( (is_mlo_vdev & 1) != 0 )
  {
    v21 = *(_QWORD *)(*(_QWORD *)a1 + 216LL);
    if ( !v21 || (v22 = *(_QWORD *)(v21 + 80)) == 0 )
    {
      qdf_trace_msg(0, 2u, "%s: psoc is NULL", v12, v13, v14, v15, v16, v17, v18, v19, "tdls_set_link_mode");
      result = 29;
      goto LABEL_19;
    }
    v23 = a1[66];
    if ( v23 != 10 )
    {
      if ( v23 == 15 )
      {
        qdf_mem_set(&v38, 0x18u, 0);
        v33 = *(_QWORD *)a1;
        BYTE4(v38) = 1;
        v34 = *(unsigned __int8 *)(v33 + 168);
        LODWORD(v33) = 1 << *(_BYTE *)(v33 + 93);
        BYTE5(v38) = v34;
        LODWORD(v38) = v33;
        v39 = 0x400000005LL;
        LODWORD(result) = ml_nlink_conn_change_notify(v22, v34, 17, &v38);
LABEL_15:
        if ( (_DWORD)result == 24 )
          result = 0;
        else
          result = (unsigned int)result;
        goto LABEL_19;
      }
      if ( v23 != 14 )
      {
        result = 0;
        goto LABEL_19;
      }
    }
    is_ml_links_in_mcc_allowed = policy_mgr_is_ml_links_in_mcc_allowed(v22, *(_QWORD *)a1, (__int64)&v41, v37);
    if ( (policy_mgr_is_hw_dbs_capable(v22) & 1) != 0 && !is_ml_links_in_mcc_allowed )
    {
      qdf_trace_msg(
        0,
        2u,
        "%s: ML STA Links in MCC, so don't send the TDLS frames",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "tdls_set_link_mode");
      result = 16;
      goto LABEL_19;
    }
    qdf_mem_set(&v38, 0x18u, 0);
    v35 = *(_QWORD *)a1;
    BYTE4(v38) = 1;
    v36 = *(unsigned __int8 *)(v35 + 168);
    LODWORD(v35) = 1 << *(_BYTE *)(v35 + 93);
    BYTE5(v38) = v36;
    LODWORD(v38) = v35;
    v39 = 0x400000001LL;
    LODWORD(result) = ml_nlink_conn_change_notify(v22, v36, 17, &v38);
    if ( (_DWORD)result == 24 || !(_DWORD)result )
      a1[58] = 1;
    goto LABEL_15;
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
