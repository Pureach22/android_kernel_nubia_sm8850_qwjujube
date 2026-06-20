__int64 __fastcall target_if_is_agile_span_overlap_with_operating_span(
        __int64 *a1,
        unsigned int *a2,
        int *a3,
        _BYTE *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x21
  unsigned int v13; // w20
  unsigned int v14; // w19
  __int64 result; // x0
  const char *v16; // x2
  _QWORD *vdev; // x0
  __int64 v20; // x8
  __int64 v21; // x23
  __int64 v22; // x8
  __int64 v23; // x8
  __int64 (*v24)(void); // x8
  signed __int16 v25; // w24
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  const char *v34; // x2
  __int64 v35; // x8
  __int64 v36; // x8
  __int64 v37; // x8
  double (__fastcall *v38)(_QWORD); // x8
  double v39; // d0
  __int16 v40; // w0
  __int16 v41; // w22
  unsigned int *v42; // x8
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  int v50; // w9
  int *v51; // x8
  unsigned int v52; // w23
  const char *v53; // x2
  unsigned int *v54; // x8
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  int v63; // w27
  unsigned int v64; // w24
  _BYTE *v65; // x9
  int v66; // w10
  unsigned int v67; // w10
  __int16 bw_value; // w0
  int v69; // w28
  __int16 v70; // w21
  __int16 v71; // w0
  int v72; // w10
  int v73; // w23
  unsigned int v74; // w22
  unsigned int v75; // w21
  int v76; // w8
  int *v77; // x20
  __int16 v78; // w0
  int v79; // w24
  __int16 v80; // w20
  unsigned __int16 *v81; // [xsp+0h] [xbp-10h] BYREF
  __int64 v82; // [xsp+8h] [xbp-8h]

  v82 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *a1;
  v81 = nullptr;
  if ( !v12 )
  {
    v16 = "%s: pdev object is NULL";
    goto LABEL_8;
  }
  if ( !a2 )
  {
    v16 = "%s: channel width array is null";
    goto LABEL_8;
  }
  v13 = *a2;
  if ( *a2 == 8 || (v14 = a2[1], v14 == 8) )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Invalid channel width",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "target_if_is_agile_span_overlap_with_operating_span",
      v81,
      v82);
    result = 4;
    goto LABEL_9;
  }
  if ( !a4 )
  {
    v16 = "%s: Argument(is_overlapping) is NULL";
    goto LABEL_8;
  }
  *a4 = 0;
  vdev = target_if_spectral_get_vdev(a1, 1u, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !vdev )
  {
    v16 = "%s: vdev is NULL";
    goto LABEL_8;
  }
  v20 = vdev[27];
  v21 = (__int64)vdev;
  if ( !v20 || (v22 = *(_QWORD *)(v20 + 80)) == 0 )
  {
    v34 = "%s: psoc is NULL";
LABEL_20:
    qdf_trace_msg(0x56u, 2u, v34, a5, a6, a7, a8, a9, a10, a11, a12, "target_if_vdev_get_chan_freq", v81, v82);
    v25 = -22;
    goto LABEL_21;
  }
  v23 = *(_QWORD *)(v22 + 2136);
  if ( !v23 )
  {
    v34 = "%s: rx_ops is null";
    goto LABEL_20;
  }
  v24 = *(__int64 (**)(void))(v23 + 272);
  if ( *((_DWORD *)v24 - 1) != -810236724 )
    __break(0x8228u);
  v25 = v24();
LABEL_21:
  v35 = *(_QWORD *)(v21 + 216);
  if ( !v35 || (v36 = *(_QWORD *)(v35 + 80)) == 0 )
  {
    v53 = "%s: psoc is NULL";
LABEL_32:
    qdf_trace_msg(0x56u, 2u, v53, v26, v27, v28, v29, v30, v31, v32, v33, "target_if_vdev_get_chan_freq_seg2", v81);
    wlan_objmgr_vdev_release_ref(v21, 0x1Bu, v54, v55, v56, v57, v58, v59, v60, v61, v62);
LABEL_33:
    v16 = "%s: cfreq2 is invalid";
    goto LABEL_8;
  }
  v37 = *(_QWORD *)(v36 + 2136);
  if ( !v37 )
  {
    v53 = "%s: rx_ops is null";
    goto LABEL_32;
  }
  v38 = *(double (__fastcall **)(_QWORD))(v37 + 280);
  if ( *((_DWORD *)v38 - 1) != -810236724 )
    __break(0x8228u);
  v39 = v38(v21);
  v41 = v40;
  wlan_objmgr_vdev_release_ref(v21, 0x1Bu, v42, v39, v43, v44, v45, v46, v47, v48, v49);
  if ( v41 < 0 )
    goto LABEL_33;
  if ( v13 )
  {
    if ( (wlan_reg_get_5g_bonded_channel_and_state_for_pwrmode(
            v12,
            v25,
            v13,
            &v81,
            0,
            0,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            a12)
        & 0xFFFFFFFB) != 0 )
    {
      if ( v81 )
      {
        v50 = *v81;
        v51 = a3;
        v52 = v81[1] - 10;
        goto LABEL_38;
      }
      v16 = "%s: Bonded channel is not found";
    }
    else
    {
      v16 = "%s: Channel state is disable or invalid";
    }
LABEL_8:
    qdf_trace_msg(
      0x56u,
      2u,
      v16,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "target_if_is_agile_span_overlap_with_operating_span",
      v81);
    result = 16;
    goto LABEL_9;
  }
  v50 = v25;
  v51 = a3;
  v52 = v25 + 10;
LABEL_38:
  v63 = *v51;
  v64 = v50 - 10;
  if ( v14 != 4 )
  {
    bw_value = wlan_reg_get_bw_value(v14);
    v69 = *a3;
    v70 = bw_value;
    v71 = wlan_reg_get_bw_value(v14);
    v51 = a3;
    v65 = a4;
    if ( v69 + ((unsigned __int16)(v71 & 0xFFFE) >> 1) <= v64 )
      goto LABEL_48;
    v67 = v63 - ((unsigned __int16)(v70 & 0xFFFE) >> 1);
    goto LABEL_46;
  }
  v65 = a4;
  if ( v63 + 40 > v64 && v52 > v63 - 40 )
    *a4 = 1;
  v66 = v51[1];
  if ( v66 + 40 > v64 )
  {
    v67 = v66 - 40;
LABEL_46:
    if ( v52 > v67 )
      *v65 = 1;
  }
LABEL_48:
  if ( v13 != 4 )
    goto LABEL_60;
  v72 = v41;
  v73 = *v51;
  v74 = v41 - 40;
  v75 = v72 + 40;
  if ( v14 != 4 )
  {
    v77 = v51;
    v78 = wlan_reg_get_bw_value(v14);
    v79 = *v77;
    v80 = v78;
    if ( v79 + ((unsigned __int16)(wlan_reg_get_bw_value(v14) & 0xFFFE) >> 1) > v74
      && v75 > v73 - ((unsigned __int16)(v80 & 0xFFFE) >> 1) )
    {
      result = 0;
      *a4 = 1;
      goto LABEL_9;
    }
LABEL_60:
    result = 0;
    goto LABEL_9;
  }
  if ( v73 + 40 > v74 && v75 > v73 - 40 )
    *v65 = 1;
  v76 = v51[1];
  result = 0;
  if ( v76 + 40 > v74 && v75 > v76 - 40 )
  {
    result = 0;
    *v65 = 1;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
