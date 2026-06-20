__int64 __fastcall tdls_check_is_tdls_allowed(
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
  __int64 v9; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 comp_private_obj; // x0
  __int64 v22; // x8
  const char *v23; // x2
  unsigned int v24; // w1
  const char *v25; // x2
  unsigned int *v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  _QWORD *v36; // x23
  int connection_count_with_mlo; // w22
  unsigned __int8 v38; // w21
  unsigned __int8 v39; // w0
  unsigned int operation_chan_freq; // w0

  v9 = *(_QWORD *)(a1 + 152);
  if ( v9 )
  {
    if ( (unsigned int)wlan_objmgr_vdev_try_get_ref(a1, 0x11u, a2, a3, a4, a5, a6, a7, a8, a9) )
    {
      LOBYTE(v9) = 0;
      return v9 & 1;
    }
    if ( a1 && wlan_objmgr_vdev_get_comp_private_obj(a1, 0xAu) )
    {
      v19 = *(_QWORD *)(a1 + 152);
      if ( v19 && (v20 = *(_QWORD *)(v19 + 80)) != 0 )
      {
        comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v20, 0xAu);
        if ( comp_private_obj && (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) == 0 )
        {
          if ( (*(_BYTE *)(comp_private_obj + 194) & 1) == 0 && (*(_BYTE *)(comp_private_obj + 194) & 2) != 0 )
          {
            v22 = *(_QWORD *)(a1 + 32);
            if ( v22 )
            {
              if ( *(_DWORD *)(v22 + 28) >= 0x1Fu )
              {
                v23 = "%s: tdls not enabled %d";
                v24 = 8;
LABEL_34:
                qdf_trace_msg(0, v24, v23, v11, v12, v13, v14, v15, v16, v17, v18, "tdls_check_is_tdls_allowed");
                goto LABEL_18;
              }
            }
          }
          v36 = (_QWORD *)comp_private_obj;
          if ( wlan_nan_is_disc_active(*(_QWORD *)comp_private_obj, v11, v12, v13, v14, v15, v16, v17, v18) )
          {
            v25 = "%s: NAN active. NAN+TDLS not supported";
            goto LABEL_17;
          }
          if ( (*((_BYTE *)v36 + 625) & 1) == 0 )
          {
            v25 = "%s: TDLS Disabled from userspace";
            goto LABEL_17;
          }
          connection_count_with_mlo = policy_mgr_get_connection_count_with_mlo(*v36);
          v38 = policy_mgr_mode_specific_connection_count(*v36, 0, nullptr);
          v39 = policy_mgr_mode_specific_connection_count(*v36, 2, nullptr);
          if ( connection_count_with_mlo )
          {
            if ( connection_count_with_mlo == 1 )
            {
              if ( v38 | v39 )
                goto LABEL_27;
            }
            else if ( (tdls_is_concurrency_allowed(*v36) & 1) != 0 )
            {
LABEL_27:
              if ( *(_DWORD *)(a1 + 16) != 2 || !v38 )
              {
                operation_chan_freq = (unsigned int)wlan_get_operation_chan_freq((unsigned __int16 *)a1);
                LOBYTE(v9) = tdls_check_6g_freq_allowed(v9, operation_chan_freq);
                goto LABEL_19;
              }
              v23 = "%s: vdev:%d Concurrent STA exists. TDLS not allowed for P2P vdev";
              goto LABEL_33;
            }
          }
          v23 = "%s: vdev:%d Concurrent sessions exist disable TDLS";
LABEL_33:
          v24 = 3;
          goto LABEL_34;
        }
      }
      else
      {
        qdf_trace_msg(0, 2u, "%s: can't get psoc", v11, v12, v13, v14, v15, v16, v17, v18, "wlan_vdev_get_tdls_soc_obj");
      }
    }
    v25 = "%s: Failed to get TDLS objects";
LABEL_17:
    qdf_trace_msg(0, 2u, v25, v11, v12, v13, v14, v15, v16, v17, v18, "tdls_check_is_tdls_allowed");
LABEL_18:
    LOBYTE(v9) = 0;
LABEL_19:
    wlan_objmgr_vdev_release_ref(a1, 0x11u, v26, v27, v28, v29, v30, v31, v32, v33, v34);
  }
  return v9 & 1;
}
