__int64 __fastcall policy_mgr_get_ll_sap_freq(__int64 a1, unsigned int a2)
{
  __int64 context; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x19
  __int64 v14; // x28
  int v15; // w8
  char *v16; // x8
  unsigned int v17; // w25
  unsigned int v18; // w24
  __int64 v19; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x27
  double ap_policy; // d0
  int v30; // w0
  int v31; // w26
  unsigned int *v32; // x8
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x22

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v13 = context;
    qdf_mutex_acquire(context + 56);
    v14 = 0;
    while ( 1 )
    {
      v15 = *(_DWORD *)((char *)&pm_conc_connection_list + v14);
      if ( v15 == 6 || v15 == 1 )
      {
        v16 = (char *)&pm_conc_connection_list + v14;
        if ( *((_BYTE *)&pm_conc_connection_list + v14 + 28) == 1 )
        {
          v17 = *((_DWORD *)v16 + 6);
          v18 = *((_DWORD *)v16 + 1);
          v19 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v17, 24);
          if ( v19 )
          {
            v28 = v19;
            ap_policy = wlan_mlme_get_ap_policy();
            v31 = v30;
            wlan_objmgr_vdev_release_ref(v28, 0x18u, v32, ap_policy, v33, v34, v35, v36, v37, v38, v39);
            if ( a2 == 2 )
            {
              if ( (unsigned int)(v31 - 1) <= 2 )
                goto LABEL_16;
            }
            else if ( a2 == 1 )
            {
              if ( (unsigned int)(v31 - 1) < 2 )
                goto LABEL_16;
            }
            else if ( v31 == 3 )
            {
LABEL_16:
              v48 = jiffies;
              if ( policy_mgr_get_ll_sap_freq___last_ticks - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x4Fu,
                  8u,
                  "%s: LL SAP %d present with vdev_id %d and freq %d",
                  v40,
                  v41,
                  v42,
                  v43,
                  v44,
                  v45,
                  v46,
                  v47,
                  "_policy_mgr_get_ll_sap_freq",
                  a2,
                  v17,
                  v18);
                policy_mgr_get_ll_sap_freq___last_ticks = v48;
              }
              qdf_mutex_release(v13 + 56);
              return v18;
            }
          }
          else
          {
            qdf_trace_msg(
              0x4Fu,
              2u,
              "%s: vdev %d: not a sap vdev",
              v20,
              v21,
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              "_policy_mgr_get_ll_sap_freq",
              v17);
          }
        }
      }
      v14 += 36;
      if ( v14 == 180 )
      {
        qdf_mutex_release(v13 + 56);
        return 0;
      }
    }
  }
  qdf_trace_msg(0x4Fu, 2u, "%s: pm_ctx is NULL", v5, v6, v7, v8, v9, v10, v11, v12, "_policy_mgr_get_ll_sap_freq");
  return 0;
}
