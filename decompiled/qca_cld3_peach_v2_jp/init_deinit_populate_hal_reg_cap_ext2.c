__int64 __fastcall init_deinit_populate_hal_reg_cap_ext2(
        __int64 *a1,
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
  __int64 psoc_from_scn_hdl; // x0
  unsigned int v15; // w23
  const char *v16; // x2
  __int64 result; // x0
  __int64 v18; // x22
  unsigned int updated; // w24
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  const char *v28; // x2
  int v29; // w8
  __int64 v30; // x9
  int v31; // w11
  unsigned int sar_cap_service_ready_ext2; // w0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int v41; // w20
  int v42; // w8
  __int64 v43; // x9
  int v44; // w11
  int v45; // w8
  __int64 v46; // x9
  int v47; // w11
  __int64 v48; // [xsp+8h] [xbp-68h] BYREF
  __int64 v49; // [xsp+10h] [xbp-60h]
  __int128 v50; // [xsp+18h] [xbp-58h]
  __int64 v51; // [xsp+28h] [xbp-48h] BYREF
  __int64 v52; // [xsp+30h] [xbp-40h]
  __int128 v53; // [xsp+38h] [xbp-38h]
  __int64 v54; // [xsp+48h] [xbp-28h] BYREF
  __int64 v55; // [xsp+50h] [xbp-20h]
  __int128 v56; // [xsp+58h] [xbp-18h]
  __int64 v57; // [xsp+68h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v56 = 0u;
  v54 = 0;
  v55 = 0;
  v53 = 0u;
  v51 = 0;
  v52 = 0;
  v50 = 0u;
  v48 = 0;
  v49 = 0;
  if ( !a2 )
  {
    v16 = "%s: event buffer is null";
LABEL_7:
    qdf_trace_msg(0x49u, 2u, v16, a4, a5, a6, a7, a8, a9, a10, a11, "init_deinit_populate_hal_reg_cap_ext2");
    goto LABEL_8;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(*a1);
  if ( !psoc_from_scn_hdl )
  {
    v16 = "%s: psoc is null";
    goto LABEL_7;
  }
  v15 = *(_DWORD *)(a3 + 788);
  if ( v15 > 3 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Invalid num_phy_reg_cap %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "init_deinit_populate_hal_reg_cap_ext2",
      v15);
LABEL_8:
    result = 4294967274LL;
    goto LABEL_9;
  }
  if ( v15 )
  {
    v18 = psoc_from_scn_hdl;
    updated = wmi_extract_hal_reg_cap_ext2(a1, a2, 0, &v48);
    if ( updated )
    {
LABEL_12:
      v28 = "%s: failed to parse hal reg cap ext2";
LABEL_15:
      qdf_trace_msg(0x49u, 2u, v28, v20, v21, v22, v23, v24, v25, v26, v27, "init_deinit_populate_hal_reg_cap_ext2");
      result = qdf_status_to_os_return(updated);
      goto LABEL_9;
    }
    v29 = v50;
    v30 = *(_QWORD *)((char *)&v50 + 4);
    v31 = HIDWORD(v50);
    *(_QWORD *)(a3 + 984) = v49;
    *(_DWORD *)(a3 + 992) = v29;
    *(_QWORD *)(a3 + 996) = v30;
    *(_DWORD *)(a3 + 1004) = v31;
    updated = ucfg_reg_update_hal_cap_wireless_modes(v18);
    if ( updated )
      goto LABEL_14;
    if ( v15 != 1 )
    {
      updated = wmi_extract_hal_reg_cap_ext2(a1, a2, 1, &v51);
      if ( updated )
        goto LABEL_12;
      v42 = v53;
      v43 = *(_QWORD *)((char *)&v53 + 4);
      v44 = HIDWORD(v53);
      *(_QWORD *)(a3 + 984) = v52;
      *(_DWORD *)(a3 + 992) = v42;
      *(_QWORD *)(a3 + 996) = v43;
      *(_DWORD *)(a3 + 1004) = v44;
      updated = ucfg_reg_update_hal_cap_wireless_modes(v18);
      if ( updated )
        goto LABEL_14;
      if ( v15 != 2 )
      {
        updated = wmi_extract_hal_reg_cap_ext2(a1, a2, 2, &v54);
        if ( updated )
          goto LABEL_12;
        v45 = v56;
        v46 = *(_QWORD *)((char *)&v56 + 4);
        v47 = HIDWORD(v56);
        *(_QWORD *)(a3 + 984) = v55;
        *(_DWORD *)(a3 + 992) = v45;
        *(_QWORD *)(a3 + 996) = v46;
        *(_DWORD *)(a3 + 1004) = v47;
        updated = ucfg_reg_update_hal_cap_wireless_modes(v18);
        if ( updated )
        {
LABEL_14:
          v28 = "%s: Failed to update hal reg cap";
          goto LABEL_15;
        }
      }
    }
  }
  sar_cap_service_ready_ext2 = wmi_extract_sar_cap_service_ready_ext2(a1, a2, a3 + 920);
  if ( sar_cap_service_ready_ext2 )
  {
    v41 = sar_cap_service_ready_ext2;
    qdf_trace_msg(0x49u, 8u, "%s: failed to parse sar flag", v33, v34, v35, v36, v37, v38, v39, v40, "get_sar_flag");
    qdf_status_to_os_return(v41);
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      8u,
      "%s: sar flag %d",
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      "get_sar_flag",
      *(unsigned int *)(a3 + 1012));
  }
  result = 0;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
