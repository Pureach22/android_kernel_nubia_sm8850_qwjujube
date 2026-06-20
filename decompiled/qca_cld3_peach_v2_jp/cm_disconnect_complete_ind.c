__int64 __fastcall cm_disconnect_complete_ind(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x8
  unsigned int v21; // w19
  __int64 v22; // x21
  unsigned int v23; // w22
  unsigned __int64 StatusReg; // x8
  int v25; // w9
  unsigned int v26; // w9
  __int64 v27; // x8
  __int64 v28; // x0
  __int64 psoc_ext_obj_fl; // x0
  __int64 v30; // x24
  char *v31; // x26
  unsigned int v32; // w8
  __int64 result; // x0
  __int64 v34; // x5
  const char *v35; // x2
  unsigned int v36; // w9
  unsigned __int64 v37; // x9
  _QWORD v38[4]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v39; // [xsp+28h] [xbp-18h] BYREF
  char v40; // [xsp+30h] [xbp-10h] BYREF
  __int64 v41; // [xsp+38h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    cm_csr_disconnect_done_ind();
    v20 = *(_QWORD *)(a1 + 152);
    v21 = *(unsigned __int8 *)(a1 + 104);
    if ( v20 )
    {
      v22 = *(_QWORD *)(v20 + 80);
      if ( v22 )
      {
        v23 = *(_DWORD *)(a1 + 16);
        BYTE5(v38[0]) = *(_BYTE *)(a1 + 104);
        LODWORD(v38[0]) = 1900555;
        BYTE4(v38[0]) = v23;
        *(_QWORD *)((char *)v38 + 6) = qdf_get_time_of_the_day_us();
        __isb(0xFu);
        StatusReg = _ReadStatusReg(CNTVCT_EL0);
        v25 = *a2;
        *(_QWORD *)((char *)&v38[1] + 6) = StatusReg;
        *(_DWORD *)((char *)&v38[2] + 6) = v25;
        v26 = a2[2];
        WORD1(v38[3]) = a2[3];
        LOBYTE(StatusReg) = *((_BYTE *)a2 + 16);
        BYTE4(v38[3]) = v26;
        LOWORD(v26) = *(_WORD *)((char *)a2 + 17);
        BYTE5(v38[3]) = StatusReg;
        LOBYTE(StatusReg) = *((_BYTE *)a2 + 21);
        HIWORD(v38[3]) = v26;
        LOBYTE(v39) = StatusReg;
        wlan_cp_stats_cstats_write_to_buff(0, v38, 33);
        v27 = *(_QWORD *)(a1 + 152);
        if ( !v27 )
          goto LABEL_23;
        v28 = *(_QWORD *)(v27 + 80);
        if ( !v28 )
          goto LABEL_23;
        v40 = 0;
        v39 = 0;
        memset(v38, 0, sizeof(v38));
        psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(v28);
        if ( !psoc_ext_obj_fl )
          goto LABEL_23;
        v30 = psoc_ext_obj_fl;
        v31 = (char *)&v39 + 7;
        qdf_mem_set(v38, 0x29u, 0);
        qdf_mem_copy(v38, (const void *)(v30 + 3346), 0x29u);
        v32 = a2[3];
        BYTE2(v39) = *(_BYTE *)(v30 + 3329);
        LOBYTE(v38[0]) = 1;
        if ( v32 == 14 )
        {
          LOBYTE(v32) = 2;
LABEL_22:
          *v31 = v32;
          host_diag_event_report_payload(2739, 41, v38);
LABEL_23:
          wlan_tdls_notify_sta_disconnect(v21, 0, 0, a1);
          policy_mgr_decr_session_set_pcl(v22, v23, v21);
          result = 0;
          goto LABEL_24;
        }
        v36 = a2[2];
        if ( v36 == 7 )
        {
          LOBYTE(v37) = 4;
        }
        else
        {
          if ( v36 != 6 )
          {
            LOBYTE(v32) = 1;
            goto LABEL_22;
          }
          if ( v32 > 6 )
            LOBYTE(v37) = 3;
          else
            v37 = 0x4030304040303uLL >> (8 * (unsigned __int8)v32);
        }
        v31 = &v40;
        HIBYTE(v39) = v37;
        goto LABEL_22;
      }
      v34 = *a2;
      v35 = "%s: vdev %d cm_id 0x%x: psoc not found";
    }
    else
    {
      v34 = *a2;
      v35 = "%s: vdev %d cm_id 0x%x: pdev not found";
    }
    qdf_trace_msg(
      0x68u,
      2u,
      v35,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "cm_disconnect_complete_ind",
      *(unsigned __int8 *)(a1 + 104),
      v34);
    result = 4;
  }
  else
  {
    qdf_trace_msg(0x68u, 2u, "%s: vdev or rsp is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "cm_disconnect_complete_ind");
    result = 4;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
