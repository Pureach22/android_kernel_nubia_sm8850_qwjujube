__int64 __fastcall init_deinit_populate_hw_mode_capability(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x22
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w23
  __int64 v25; // x24
  unsigned int *v26; // x25
  unsigned int *v27; // x27
  unsigned int hw_mode_cap_service_ready_ext; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w28
  unsigned int v38; // w0
  unsigned int v39; // w9
  char v40; // w0
  unsigned int v41; // w28
  unsigned int sar_cap_service_ready_ext; // w20
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  _QWORD v51[7]; // [xsp+8h] [xbp-38h] BYREF

  v51[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(unsigned int *)(a3 + 824);
  memset(v51, 0, 48);
  if ( (unsigned int)v11 >= 5 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: invalid num_hw_modes %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "init_deinit_populate_hw_mode_capability",
      (unsigned int)v11);
    result = 4294967274LL;
    goto LABEL_32;
  }
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: num_hw_modes %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "init_deinit_populate_hw_mode_capability",
    (unsigned int)v11);
  qdf_mem_set(v51, 0x30u, 0);
  v24 = 11;
  *(_BYTE *)(a3 + 5652) = 0;
  *(_DWORD *)(a3 + 5640) = 11;
  if ( (_DWORD)v11 )
  {
    v25 = 0;
    v26 = (unsigned int *)v51;
    v27 = (unsigned int *)(a3 + 5700);
    do
    {
      hw_mode_cap_service_ready_ext = wmi_extract_hw_mode_cap_service_ready_ext(a1, a2, (unsigned int)v25, v26);
      if ( hw_mode_cap_service_ready_ext )
      {
        v37 = hw_mode_cap_service_ready_ext;
        qdf_trace_msg(
          0x49u,
          2u,
          "%s: failed to parse hw mode capability",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "get_hw_mode");
        v38 = qdf_status_to_os_return(v37);
        if ( v38 )
          goto LABEL_31;
      }
      v39 = v26[1];
      *(v27 - 11) = *v26;
      *v27 = v39;
      ++*(_BYTE *)(a3 + 5652);
      v38 = ((__int64 (__fastcall *)(__int64, __int64, unsigned int *, __int64))init_deinit_populate_mac_phy_capability)(
              a1,
              a2,
              v26,
              a3 + 40);
      if ( v38 )
        goto LABEL_31;
      if ( (_DWORD)v11 == 1
        && *(_BYTE *)(a3 + 5652) == 1
        && *(_DWORD *)(a3 + 5656) == 1
        && (v40 = wmi_service_enabled(a1, 85), a3)
        && (v40 & 1) == 0 )
      {
        *(_DWORD *)(a3 + 504) = 12;
      }
      else
      {
        if ( !a3 )
          goto LABEL_6;
        v41 = *(_DWORD *)(a3 + 504);
        if ( v41 == 11 )
          goto LABEL_6;
        if ( v41 != 12 )
        {
          if ( v41 != *v26 )
            goto LABEL_6;
          goto LABEL_5;
        }
      }
      if ( v24 > 0xB )
        goto LABEL_6;
      v41 = *v26;
      if ( *v26 > 0xB || byte_AD06A0[v24] <= (unsigned int)byte_AD06A0[v41] )
        goto LABEL_6;
LABEL_5:
      qdf_mem_copy((void *)(a3 + 5640), v26, 0xCu);
      v24 = v41;
LABEL_6:
      ++v25;
      v26 += 3;
      ++v27;
    }
    while ( v11 != v25 );
  }
  if ( a3 && *(_DWORD *)(a3 + 504) == 12 )
  {
    qdf_trace_msg(
      0x49u,
      4u,
      "%s: Preferred mode is not set, use mode id %d\n",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "init_deinit_populate_hw_mode_capability",
      v24);
    *(_DWORD *)(a3 + 504) = v24;
    *(_DWORD *)(a3 + 740) = v24;
  }
  sar_cap_service_ready_ext = wmi_extract_sar_cap_service_ready_ext(a1, a2, a3 + 760);
  if ( sar_cap_service_ready_ext )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: failed to parse sar capability",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "get_sar_version");
    sar_cap_service_ready_ext = qdf_status_to_os_return(sar_cap_service_ready_ext);
  }
  qdf_trace_msg(
    0x49u,
    8u,
    "%s: sar version %d",
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    "init_deinit_populate_hw_mode_capability",
    *(unsigned int *)(a3 + 928));
  v38 = sar_cap_service_ready_ext;
LABEL_31:
  result = qdf_status_to_os_return(v38);
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
