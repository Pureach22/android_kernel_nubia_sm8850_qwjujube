__int64 __fastcall reg_update_conn_chan_list(
        __int64 a1,
        _DWORD *a2,
        unsigned int a3,
        char a4,
        unsigned int a5,
        int *a6,
        unsigned int a7)
{
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x19
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x20
  __int64 v34; // x0
  unsigned int v35; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w22
  __int64 result; // x0
  unsigned int v46; // w28
  int v47; // w27
  int v48; // w9
  unsigned __int64 v49; // x8
  __int64 v50; // x26
  __int64 v51; // x0
  int *v52; // x11
  unsigned __int64 v53; // x9
  int v54; // t1
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  int v63; // w12
  _DWORD *v64; // x8
  int v65; // w9
  int v66; // w11
  int v67; // [xsp+10h] [xbp-20h]
  int v68; // [xsp+14h] [xbp-1Ch] BYREF
  _QWORD v69[3]; // [xsp+18h] [xbp-18h] BYREF

  v69[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v68 = 0;
  v14 = _qdf_mem_malloc(0x198u, "reg_update_conn_chan_list", 3822);
  if ( v14 )
  {
    v23 = v14;
    v24 = _qdf_mem_malloc(0x66u, "reg_update_conn_chan_list", 3830);
    if ( v24 )
    {
      v33 = v24;
      v34 = *(_QWORD *)(a1 + 80);
      if ( !v34 )
      {
        qdf_trace_msg(
          0x51u,
          2u,
          "%s: invalid psoc",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "reg_update_conn_chan_list");
        v44 = 16;
        goto LABEL_27;
      }
      v68 = 102;
      v35 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, int *, __int64, __int64, __int64))policy_mgr_get_pcl)(
              v34,
              a3,
              v23,
              &v68,
              v33,
              102,
              255);
      if ( v35 )
      {
        v44 = v35;
        qdf_trace_msg(
          0x51u,
          2u,
          "%s: get pcl failed for mode: %d",
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          "reg_update_conn_chan_list",
          a3);
LABEL_27:
        _qdf_mem_free(v23);
        _qdf_mem_free(v33);
        result = v44;
        goto LABEL_28;
      }
      v46 = v68;
      v47 = *a6;
      v69[0] = 0;
      v69[1] = 0;
      if ( !v68 || v47 > 101 )
      {
LABEL_26:
        v44 = 0;
        *a6 = v47;
        goto LABEL_27;
      }
      v48 = 0;
      v67 = 1 << a4;
      while ( 1 )
      {
        v49 = (unsigned int)*a6;
        v50 = v48;
        v51 = *(unsigned int *)(v23 + 4LL * v48);
        if ( (int)v49 < 1 )
          goto LABEL_18;
        if ( *a2 != (_DWORD)v51 )
          break;
LABEL_24:
        v48 = v50 + 1;
        if ( (int)v50 + 1 >= v46 || v47 >= 102 )
          goto LABEL_26;
      }
      v52 = a2 + 6;
      v53 = 0;
      while ( v49 - 1 != v53 )
      {
        v54 = *v52;
        v52 += 6;
        ++v53;
        if ( v54 == (_DWORD)v51 )
        {
          if ( v53 < v49 )
            goto LABEL_24;
          break;
        }
      }
LABEL_18:
      if ( ((a5 >> wlan_reg_freq_to_band(v51)) & 1) != 0 )
      {
        LODWORD(v69[0]) = 9;
        reg_set_channel_params_for_pwrmode(
          a1,
          *(_DWORD *)(v23 + 4 * v50),
          0,
          (__int64)v69,
          a7,
          1,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62);
        v63 = v69[0];
        v64 = &a2[6 * v47];
        v65 = BYTE5(v69[0]);
        v66 = v64[4];
        *v64 = *(_DWORD *)(v23 + 4 * v50);
        v64[3] = v63;
        v64[4] = v66 | v67;
        if ( v65 )
          v64[1] = v65;
        if ( BYTE6(v69[0]) )
          v64[2] = BYTE6(v69[0]);
        ++v47;
      }
      goto LABEL_24;
    }
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: weight_list invalid",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "reg_update_conn_chan_list");
    _qdf_mem_free(v23);
    result = 16;
  }
  else
  {
    qdf_trace_msg(0x51u, 2u, "%s: pcl_ch invalid", v15, v16, v17, v18, v19, v20, v21, v22, "reg_update_conn_chan_list");
    result = 16;
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}
