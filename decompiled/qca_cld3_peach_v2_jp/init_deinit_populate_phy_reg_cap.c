__int64 __fastcall init_deinit_populate_phy_reg_cap(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned int v16; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w20
  unsigned int v26; // w0
  unsigned int v27; // w20
  __int64 result; // x0
  unsigned int ready; // w23
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w10
  unsigned int v40; // w11
  __int64 v41; // x4
  int v42; // w8
  int v43; // w8
  int v44; // w9
  __int128 v45; // [xsp+0h] [xbp-C0h] BYREF
  __int128 v46; // [xsp+10h] [xbp-B0h]
  __int64 v47; // [xsp+20h] [xbp-A0h]
  __int64 v48; // [xsp+28h] [xbp-98h] BYREF
  __int64 v49; // [xsp+30h] [xbp-90h]
  __int64 v50; // [xsp+38h] [xbp-88h]
  __int64 v51; // [xsp+40h] [xbp-80h]
  __int64 v52; // [xsp+48h] [xbp-78h]
  unsigned __int64 v53; // [xsp+50h] [xbp-70h]
  __int64 v54; // [xsp+58h] [xbp-68h] BYREF
  __int64 v55; // [xsp+60h] [xbp-60h]
  __int64 v56; // [xsp+68h] [xbp-58h]
  __int64 v57; // [xsp+70h] [xbp-50h]
  __int64 v58; // [xsp+78h] [xbp-48h]
  __int64 v59; // [xsp+80h] [xbp-40h]
  __int64 v60; // [xsp+88h] [xbp-38h] BYREF
  __int64 v61; // [xsp+90h] [xbp-30h]
  __int64 v62; // [xsp+98h] [xbp-28h]
  __int64 v63; // [xsp+A0h] [xbp-20h]
  __int64 v64; // [xsp+A8h] [xbp-18h]
  __int64 v65; // [xsp+B0h] [xbp-10h]
  __int64 v66; // [xsp+B8h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v47) = 0;
  v46 = 0u;
  v45 = 0u;
  v64 = 0;
  v65 = 0;
  v62 = 0;
  v63 = 0;
  v60 = 0;
  v61 = 0;
  v58 = 0;
  v59 = 0;
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  if ( (a5 & 1) != 0 )
  {
    v16 = wmi_extract_hal_reg_cap(a2, a3, &v45);
    if ( v16 )
    {
      v25 = v16;
      qdf_trace_msg(
        0x49u,
        2u,
        "%s: failed to parse hal reg cap",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "init_deinit_populate_phy_reg_cap");
      v26 = v25;
LABEL_11:
      result = qdf_status_to_os_return(v26);
      goto LABEL_12;
    }
    v27 = 1;
    v39 = HIDWORD(v46);
    v40 = v47;
    LODWORD(v48) = 0;
    HIDWORD(v48) = v45;
    v42 = HIDWORD(v45);
    v41 = (unsigned int)v46;
    v49 = *(_QWORD *)((char *)&v45 + 4);
    *(_DWORD *)(a4 + 788) = 1;
    LODWORD(v50) = v42;
    v43 = DWORD1(v46);
    v44 = DWORD2(v46);
    v51 = v41;
    v53 = __PAIR64__(v40, v39);
    v52 = *(_QWORD *)((char *)&v46 + 4);
    *(_QWORD *)(a4 + 896) = v41;
    *(_DWORD *)(a4 + 904) = v43;
    *(_DWORD *)(a4 + 908) = v44;
    *(_DWORD *)(a4 + 912) = v39;
    *(_DWORD *)(a4 + 916) = v40;
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: FW wireless modes 0x%llx",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "init_deinit_populate_phy_reg_cap");
    goto LABEL_10;
  }
  v27 = *(_DWORD *)(a4 + 788);
  if ( v27 < 4 )
  {
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: num_phy_reg_cap %d",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "init_deinit_populate_phy_reg_cap",
      v27);
    if ( v27 )
    {
      ready = wmi_extract_reg_cap_service_ready_ext(a2, a3, 0, &v48);
      if ( ready
        || v27 != 1
        && ((ready = wmi_extract_reg_cap_service_ready_ext(a2, a3, 1, &v54)) != 0
         || v27 != 2 && (ready = wmi_extract_reg_cap_service_ready_ext(a2, a3, 2, &v60)) != 0) )
      {
        qdf_trace_msg(
          0x49u,
          2u,
          "%s: failed to parse reg cap",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          "init_deinit_populate_phy_reg_cap",
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66);
        v26 = ready;
        goto LABEL_11;
      }
    }
LABEL_10:
    v26 = ucfg_reg_set_hal_reg_cap(a1, &v48, v27);
    goto LABEL_11;
  }
  qdf_trace_msg(
    0x49u,
    2u,
    "%s: Invalid num_phy_reg_cap %d",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "init_deinit_populate_phy_reg_cap",
    v27);
  result = 4294967274LL;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
