__int64 __fastcall wma_set_tx_power(
        __int64 *a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v12; // w8
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x4
  __int64 v22; // x5
  __int64 v23; // x6
  __int64 v24; // x7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 *v33; // x21
  __int64 v34; // x0
  signed __int8 max_reg_power; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 result; // x0
  __int64 v69; // x5
  __int64 v70; // x6
  __int64 v71; // x7
  int v72; // w8
  char v73; // w1
  unsigned __int8 v74[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v75; // [xsp+18h] [xbp-8h]

  v75 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *((_DWORD *)a2 + 4);
  v74[0] = 0;
  if ( (v12 | 2) == 3 )
  {
    if ( (unsigned int)wma_find_vdev_id_by_addr((__int64)a1, (__int64)a2, v74) )
    {
LABEL_3:
      if ( a2 )
      {
        v21 = *a2;
        v22 = a2[1];
        v23 = a2[2];
        v24 = a2[5];
      }
      else
      {
        v23 = 0;
        v21 = 0;
        v22 = 0;
        v24 = 0;
      }
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: vdev id is invalid for %02x:%02x:%02x:**:**:%02x",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wma_set_tx_power",
        v21,
        v22,
        v23,
        v24);
      goto LABEL_23;
    }
  }
  else if ( (unsigned int)wma_find_vdev_id_by_bssid((__int64)a1, (__int64)a2, v74, a3, a4, a5, a6, a7, a8, a9, a10) )
  {
    goto LABEL_3;
  }
  if ( (wma_is_vdev_up(v74[0]) & 1) == 0 )
  {
    if ( a2 )
    {
      v69 = *a2;
      v70 = a2[1];
      v71 = a2[2];
      v72 = a2[5];
    }
    else
    {
      v71 = 0;
      v69 = 0;
      v70 = 0;
      v72 = 0;
    }
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: vdev id %d is not up for %02x:%02x:%02x:**:**:%02x",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "wma_set_tx_power",
      v74[0],
      v69,
      v70,
      v71,
      v72);
    goto LABEL_23;
  }
  v33 = (__int64 *)(a1[65] + 488LL * v74[0]);
  v34 = *v33;
  if ( !a2[12] )
  {
    v73 = 0;
LABEL_22:
    mlme_set_tx_power(v34, v73, v25, v26, v27, v28, v29, v30, v31, v32);
LABEL_23:
    result = _qdf_mem_free((__int64)a2);
    goto LABEL_24;
  }
  max_reg_power = mlme_get_max_reg_power(v34, v25, v26, v27, v28, v29, v30, v31, v32);
  if ( max_reg_power && (char)a2[12] > max_reg_power )
    a2[12] = max_reg_power;
  if ( (unsigned __int8)mlme_get_tx_power(*v33, v36, v37, v38, v39, v40, v41, v42, v43) == a2[12] )
    goto LABEL_23;
  qdf_trace_msg(0x36u, 8u, "TXP[W][set_tx_pwr]: %d", v44, v45, v46, v47, v48, v49, v50, v51);
  if ( !(unsigned int)wma_vdev_set_param(*a1, v74[0], 0x38u, (char)a2[12], v52, v53, v54, v55, v56, v57, v58, v59) )
  {
    v34 = *v33;
    v73 = a2[12];
    goto LABEL_22;
  }
  _qdf_mem_free((__int64)a2);
  result = qdf_trace_msg(
             0x36u,
             2u,
             "%s: Failed to set vdev param wmi_vdev_param_tx_pwrlimit",
             v60,
             v61,
             v62,
             v63,
             v64,
             v65,
             v66,
             v67,
             "wma_set_tx_power");
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
