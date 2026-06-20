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
  __int64 *v22; // x21
  __int64 v23; // x8
  const char *v24; // x2
  unsigned int v25; // w1
  unsigned int *v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  int connection_count_with_mlo; // w23
  unsigned __int8 v37; // w22
  unsigned __int8 v38; // w0
  unsigned int operation_chan_freq; // w0

  v9 = *(_QWORD *)(a1 + 216);
  if ( v9 )
  {
    if ( (unsigned int)wlan_objmgr_vdev_try_get_ref(a1, 0x11u, a2, a3, a4, a5, a6, a7, a8, a9) )
    {
      LOBYTE(v9) = 0;
      return v9 & 1;
    }
    if ( a1 && wlan_objmgr_vdev_get_comp_private_obj(a1, 0xAu) )
    {
      v19 = *(_QWORD *)(a1 + 216);
      if ( v19 && (v20 = *(_QWORD *)(v19 + 80)) != 0 )
      {
        comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v20, 0xAu);
        if ( comp_private_obj && (*(_DWORD *)(a1 + 16) & 0xFFFFFFFD) == 0 )
        {
          v22 = (__int64 *)comp_private_obj;
          if ( (*(_BYTE *)(comp_private_obj + 194) & 1) == 0 )
          {
            if ( (v23 = *(_QWORD *)(a1 + 32), (*(_BYTE *)(comp_private_obj + 194) & 2) != 0)
              && v23
              && *(_DWORD *)(v23 + 28) > 0x1Eu
              || (*(_BYTE *)(comp_private_obj + 194) & 4) != 0 && v23 && *(_DWORD *)(v23 + 28) >= 0x29u )
            {
              v24 = "%s: tdls not enabled %d";
              v25 = 8;
LABEL_21:
              qdf_trace_msg(0, v25, v24, v11, v12, v13, v14, v15, v16, v17, v18, "tdls_check_is_tdls_allowed");
              LOBYTE(v9) = 0;
LABEL_22:
              wlan_objmgr_vdev_release_ref(a1, 0x11u, v26, v27, v28, v29, v30, v31, v32, v33, v34);
              return v9 & 1;
            }
          }
          if ( (wlan_vdev_mlme_is_mlo_vdev(a1, v11, v12, v13, v14, v15, v16, v17, v18) & 1) != 0
            && (wlan_tdls_is_fw_11be_mlo_capable(*v22) & 1) == 0 )
          {
            v24 = "%s: TDLS not supported on MLO vdev";
            v25 = 8;
            goto LABEL_21;
          }
          if ( wlan_nan_is_disc_active(*v22, v11, v12, v13, v14, v15, v16, v17, v18) )
          {
            v24 = "%s: NAN active. NAN+TDLS not supported";
            goto LABEL_20;
          }
          if ( (*((_BYTE *)v22 + 633) & 1) == 0 )
          {
            v24 = "%s: TDLS Disabled from userspace";
            goto LABEL_20;
          }
          connection_count_with_mlo = policy_mgr_get_connection_count_with_mlo(*v22);
          v37 = policy_mgr_mode_specific_connection_count(*v22, 0, nullptr);
          v38 = policy_mgr_mode_specific_connection_count(*v22, 2, nullptr);
          if ( connection_count_with_mlo )
          {
            if ( connection_count_with_mlo == 1 )
            {
              if ( v37 | v38 )
                goto LABEL_32;
            }
            else if ( (tdls_is_concurrency_allowed(*v22) & 1) != 0 )
            {
LABEL_32:
              if ( *(_DWORD *)(a1 + 16) != 2 || !v37 )
              {
                operation_chan_freq = (unsigned int)wlan_get_operation_chan_freq((unsigned __int16 *)a1);
                LOBYTE(v9) = tdls_check_6g_freq_allowed(v9, a1, operation_chan_freq);
                goto LABEL_22;
              }
              v24 = "%s: vdev:%d Concurrent STA exists. TDLS not allowed for P2P vdev";
              goto LABEL_39;
            }
          }
          v24 = "%s: vdev:%d Concurrent sessions exist disable TDLS";
LABEL_39:
          v25 = 3;
          goto LABEL_21;
        }
      }
      else
      {
        qdf_trace_msg(0, 2u, "%s: can't get psoc", v11, v12, v13, v14, v15, v16, v17, v18, "wlan_vdev_get_tdls_soc_obj");
      }
    }
    v24 = "%s: Failed to get TDLS objects";
LABEL_20:
    v25 = 2;
    goto LABEL_21;
  }
  return v9 & 1;
}
