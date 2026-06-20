__int64 __fastcall policy_mgr_nss_update(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        int a4,
        unsigned int a5,
        unsigned int a6,
        int a7)
{
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x26
  int v21; // w8
  unsigned int v22; // w0
  __int64 v23; // x27
  __int64 v24; // x23
  const char *v25; // x2
  unsigned int v26; // w8
  _DWORD *v27; // x8
  unsigned int v28; // w19
  int v29; // w24
  unsigned int v30; // w20
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  _DWORD *v39; // x8
  unsigned int v40; // w0
  unsigned int sap_mode_count; // w0
  __int64 v42; // x27
  __int64 i; // x23
  const char *v44; // x2
  unsigned int v45; // w8
  _DWORD *v46; // x8
  unsigned int v47; // w19
  int v48; // w24
  unsigned int v49; // w20
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  _DWORD *v58; // x8
  unsigned int v59; // w0
  unsigned int v61; // [xsp+14h] [xbp-3Ch]
  unsigned int v62; // [xsp+18h] [xbp-38h]
  unsigned int v67; // [xsp+2Ch] [xbp-24h]
  _QWORD v68[2]; // [xsp+30h] [xbp-20h] BYREF
  int v69; // [xsp+40h] [xbp-10h]
  __int64 v70; // [xsp+48h] [xbp-8h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v69 = 0;
  v68[0] = 0;
  v68[1] = 0;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 6u);
  if ( comp_private_obj )
  {
    v19 = comp_private_obj;
    if ( a4 == 1 && (unsigned __int8)a3 == 12 )
      v21 = 1;
    else
      v21 = 9;
    v61 = v21;
    v62 = a3;
    v22 = policy_mgr_mode_specific_connection_count(a1, 3, v68);
    if ( v22 )
    {
      v23 = 4LL * v22;
      v24 = 0;
      v67 = 16;
      while ( 1 )
      {
        qdf_mutex_acquire(v19 + 56);
        if ( v24 == 20 || (v26 = *(_DWORD *)((char *)v68 + v24), v26 > 4) )
        {
LABEL_51:
          __break(0x5512u);
          __break(1u);
        }
        v27 = (_DWORD *)&pm_conc_connection_list + 9 * v26;
        v29 = v27[5];
        v28 = v27[6];
        v30 = v27[1];
        qdf_mutex_release(v19 + 56);
        if ( (unsigned int)policy_mgr_get_connection_for_vdev_id(a1, v28) == 5 )
        {
          v25 = "%s: connection not found for vdev %d";
        }
        else
        {
          if ( v29 != 2 )
            goto LABEL_12;
          if ( a4 != 2 )
          {
            if ( a4 )
            {
              if ( a4 != 1 || !wlan_reg_is_5ghz_ch_freq(v30) )
                goto LABEL_12;
            }
            else if ( !wlan_reg_is_24ghz_ch_freq(v30) )
            {
              goto LABEL_12;
            }
          }
          v39 = *(_DWORD **)(v19 + 416);
          if ( *(v39 - 1) != -1969244178 )
            __break(0x8228u);
          v40 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, __int64 (__fastcall *)(__int64, unsigned __int8, unsigned int, unsigned __int8, unsigned int, unsigned int, unsigned int), _QWORD, __int64, _QWORD, _QWORD, int))v39)(
                  v28,
                  a2,
                  v61,
                  policy_mgr_nss_update_cb,
                  v62,
                  a1,
                  a5,
                  a6,
                  a7);
          if ( !v40 )
          {
            v67 = 0;
            goto LABEL_12;
          }
          v25 = "%s: sme_nss_update_request() failed for vdev %d";
          v67 = v40;
        }
        qdf_trace_msg(0x4Fu, 2u, v25, v31, v32, v33, v34, v35, v36, v37, v38, "policy_mgr_nss_update", v28);
LABEL_12:
        v24 += 4;
        if ( v23 == v24 )
          goto LABEL_30;
      }
    }
    v67 = 16;
LABEL_30:
    sap_mode_count = policy_mgr_get_sap_mode_count(a1, v68);
    if ( sap_mode_count )
    {
      v42 = 4LL * sap_mode_count;
      for ( i = 0; v42 != i; i += 4 )
      {
        qdf_mutex_acquire(v19 + 56);
        if ( i == 20 )
          goto LABEL_51;
        v45 = *(_DWORD *)((char *)v68 + i);
        if ( v45 > 4 )
          goto LABEL_51;
        v46 = (_DWORD *)&pm_conc_connection_list + 9 * v45;
        v48 = v46[5];
        v47 = v46[6];
        v49 = v46[1];
        qdf_mutex_release(v19 + 56);
        if ( (unsigned int)policy_mgr_get_connection_for_vdev_id(a1, v47) == 5 )
        {
          v44 = "%s: connection not found for vdev %d";
        }
        else
        {
          if ( v48 != 2 )
            continue;
          if ( a4 != 2 )
          {
            if ( a4 )
            {
              if ( a4 != 1 || !wlan_reg_is_5ghz_ch_freq(v49) )
                continue;
            }
            else if ( !wlan_reg_is_24ghz_ch_freq(v49) )
            {
              continue;
            }
          }
          v58 = *(_DWORD **)(v19 + 416);
          if ( *(v58 - 1) != -1969244178 )
            __break(0x8228u);
          v59 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, __int64 (__fastcall *)(__int64, unsigned __int8, unsigned int, unsigned __int8, unsigned int, unsigned int, unsigned int), _QWORD, __int64, _QWORD, _QWORD, int))v58)(
                  v47,
                  a2,
                  v61,
                  policy_mgr_nss_update_cb,
                  v62,
                  a1,
                  a5,
                  a6,
                  a7);
          if ( !v59 )
          {
            v67 = 0;
            continue;
          }
          v44 = "%s: sme_nss_update_request() failed for vdev %d";
          v67 = v59;
        }
        qdf_trace_msg(0x4Fu, 2u, v44, v50, v51, v52, v53, v54, v55, v56, v57, "policy_mgr_nss_update", v47);
      }
    }
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v11, v12, v13, v14, v15, v16, v17, v18, "policy_mgr_nss_update");
    v67 = 16;
  }
  _ReadStatusReg(SP_EL0);
  return v67;
}
