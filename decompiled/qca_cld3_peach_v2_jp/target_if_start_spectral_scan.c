__int64 __fastcall target_if_start_spectral_scan(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        _DWORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x22
  __int64 v13; // x4
  const char *v14; // x2
  __int64 result; // x0
  const char *v16; // x2
  __int64 v17; // x8
  __int64 (*v18)(void); // x8
  __int64 v22; // x0
  unsigned int (*v23)(void); // x8
  __int64 *v24; // x20
  unsigned int v25; // w0
  __int64 v26; // x1
  int curr_band; // w0
  __int64 v28; // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v37; // x2
  __int64 *v38; // x8
  __int64 *v39; // x22
  unsigned int v40; // w0
  unsigned int v41; // w19
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  const char *v50; // x2
  unsigned int v51; // w0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  unsigned int is_session_info_expected_from_target; // w0
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int v69; // w24
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  _BYTE v78[4]; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v79[2]; // [xsp+10h] [xbp-10h] BYREF

  v79[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a4 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Error code argument is null",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "target_if_start_spectral_scan");
    result = 29;
    goto LABEL_23;
  }
  *a4 = 0;
  if ( !a1 )
  {
    v16 = "%s: pdev object is NUll";
LABEL_20:
    v25 = 86;
LABEL_21:
    qdf_trace_msg(v25, 2u, v16, a5, a6, a7, a8, a9, a10, a11, a12, "target_if_start_spectral_scan");
    goto LABEL_22;
  }
  v12 = *(_QWORD *)(a1 + 80);
  if ( !v12 )
  {
    v16 = "%s: psoc is null";
    goto LABEL_20;
  }
  if ( a3 >= 2 )
  {
    *a4 = 2;
    v13 = a3;
    v14 = "%s: Invalid Spectral mode %u";
LABEL_6:
    qdf_trace_msg(0x56u, 2u, v14, a5, a6, a7, a8, a9, a10, a11, a12, "target_if_start_spectral_scan", v13);
LABEL_22:
    result = 16;
    goto LABEL_23;
  }
  v17 = *(_QWORD *)(v12 + 2136);
  if ( !v17 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: rx_ops is null",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "get_target_if_spectral_handle_from_pdev");
LABEL_19:
    v16 = "%s: Spectral LMAC object is NUll";
    goto LABEL_20;
  }
  v18 = *(__int64 (**)(void))(v17 + 256);
  if ( *((_DWORD *)v18 - 1) != 1565325861 )
    __break(0x8228u);
  v22 = v18();
  if ( !v22 )
    goto LABEL_19;
  v23 = *(unsigned int (**)(void))(v22 + 40);
  v24 = (__int64 *)v22;
  if ( *((_DWORD *)v23 - 1) != 362784388 )
    __break(0x8228u);
  if ( v23() )
  {
    v14 = "%s: spectral in progress in current pdev, mode %d";
    v13 = a3;
    goto LABEL_6;
  }
  v26 = a2;
  *((_BYTE *)v24 + a3 + 360) = a2;
  if ( a3 == 1 )
  {
    LOBYTE(v79[0]) = 0;
    if ( (unsigned int)target_if_is_agile_supported_cur_chmask(v24, v79) )
    {
LABEL_41:
      result = 16;
      *a4 = 2;
      goto LABEL_23;
    }
    if ( (v79[0] & 1) == 0 )
    {
      v37 = "%s: aSpectral unsupported for cur chainmask";
      goto LABEL_40;
    }
    v26 = a2;
  }
  curr_band = target_if_get_curr_band(*v24, v26);
  if ( curr_band == 3 )
  {
    v16 = "%s: Failed to get current band";
    goto LABEL_20;
  }
  if ( a3 == 1 && curr_band == 1 )
  {
    v28 = *(_QWORD *)(v12 + 2800);
    LOBYTE(v79[0]) = 0;
    if ( !v28 )
    {
      v16 = "%s: target_psoc_info is null";
      v25 = 73;
      goto LABEL_21;
    }
    if ( (unsigned int)(*(_DWORD *)(v28 + 504) - 2) <= 3 )
    {
      wlan_objmgr_iterate_obj_list(v12, 1, target_if_is_agile_scan_active_in_5g, (__int64)v79, 0, 0x1Bu);
      if ( (v79[0] & 1) != 0 )
      {
        qdf_trace_msg(
          0x56u,
          2u,
          "%s: Agile Scan in progress in one of the SBS 5G pdev",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "target_if_start_spectral_scan");
        *a4 = 2;
        goto LABEL_22;
      }
    }
    goto LABEL_37;
  }
  if ( a3 == 1 )
  {
LABEL_37:
    LOBYTE(v79[0]) = 0;
    if ( (unsigned int)wlan_objmgr_iterate_obj_list(
                         v12,
                         1,
                         target_if_is_aspectral_prohibited_by_adfs,
                         (__int64)v79,
                         0,
                         0x1Bu) )
    {
      v37 = "%s: Failed to iterate over pdevs";
LABEL_40:
      qdf_trace_msg(0x56u, 2u, v37, a5, a6, a7, a8, a9, a10, a11, a12, "target_if_start_spectral_scan");
      goto LABEL_41;
    }
    if ( (v79[0] & 1) != 0 )
      goto LABEL_41;
  }
  if ( (*((_BYTE *)v24 + a3 + 800) & 1) == 0 )
  {
    target_if_spectral_info_read(
      (__int64)v24,
      a3,
      2,
      (unsigned __int8 *)&v24[10 * a3 + 80],
      80,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12);
    *((_BYTE *)v24 + a3 + 800) = 1;
  }
  qdf_spin_lock_bh_16(v24 + 43);
  if ( a3 == 1 )
  {
    v78[0] = 0;
    v79[0] = 0x800000008LL;
    if ( (unsigned int)target_if_spectral_populate_chwidth(v24, v79, *((_DWORD *)v24 + 196) != 0) )
    {
      qdf_spin_unlock_bh_20(v24 + 43);
      v16 = "%s: Failed to populate channel width";
      goto LABEL_20;
    }
    v38 = &v24[10 * a3];
    if ( !*((_DWORD *)v38 + 175) )
    {
      *a4 = 4;
      qdf_spin_unlock_bh_20(v24 + 43);
      v16 = "%s: Agile Spectral cfreq1 is 0";
      goto LABEL_20;
    }
    if ( HIDWORD(v79[0]) == 4 && !*((_DWORD *)v38 + 176) )
    {
      *a4 = 4;
      qdf_spin_unlock_bh_20(v24 + 43);
      v16 = "%s: Agile Spectral cfreq2 is 0";
      goto LABEL_20;
    }
    if ( (unsigned int)target_if_is_agile_span_overlap_with_operating_span(v24, v79, (char *)v38 + 700, v78) )
    {
LABEL_55:
      qdf_spin_unlock_bh_20(v24 + 43);
      goto LABEL_22;
    }
    if ( v78[0] == 1 )
    {
      *a4 = 3;
      goto LABEL_55;
    }
  }
  v39 = &v24[10 * a3];
  v40 = target_if_spectral_check_buffer_size(*v24, *((unsigned __int16 *)v39 + 327), *((unsigned __int16 *)v39 + 338));
  if ( v40 )
  {
    v41 = v40;
    qdf_spin_unlock_bh_20(v24 + 43);
    v50 = "%s: Check buffer size failed";
LABEL_60:
    qdf_trace_msg(0x56u, 2u, v50, v42, v43, v44, v45, v46, v47, v48, v49, "target_if_start_spectral_scan");
    result = v41;
    goto LABEL_23;
  }
  v51 = target_if_spectral_populate_chwidth(v24, v24 + 148, *((_DWORD *)v24 + 196) != 0);
  if ( v51 )
  {
    v41 = v51;
    qdf_spin_unlock_bh_20(v24 + 43);
    v50 = "%s: Failed to get channel widths";
    goto LABEL_60;
  }
  is_session_info_expected_from_target = spectral_is_session_info_expected_from_target(
                                           *v24,
                                           v79,
                                           v52,
                                           v53,
                                           v54,
                                           v55,
                                           v56,
                                           v57,
                                           v58,
                                           v59);
  if ( is_session_info_expected_from_target )
  {
    v69 = is_session_info_expected_from_target;
    qdf_spin_unlock_bh_20(v24 + 43);
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Failed to check if session info is expected",
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      v77,
      "target_if_start_spectral_scan");
    result = v69;
  }
  else
  {
    target_if_spectral_scan_enable_params(
      v24,
      (__int64)(v39 + 80),
      a3,
      (__int64)a4,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68);
    *((_BYTE *)v24 + a3 + 1192) = 0;
    qdf_spin_unlock_bh_20(v24 + 43);
    result = 0;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}
