__int64 __fastcall init_deinit_populate_power_boost_cap_ext2(
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
  const char *v14; // x2
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned int v24; // w20
  _BYTE v25[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25[0] = 0;
  if ( !a2 )
  {
    v14 = "%s: TPB: event buffer is null";
LABEL_7:
    qdf_trace_msg(0x49u, 2u, v14, a4, a5, a6, a7, a8, a9, a10, a11, "init_deinit_populate_power_boost_cap_ext2");
    goto LABEL_8;
  }
  if ( !target_if_get_psoc_from_scn_hdl(*a1) )
  {
    v14 = "%s: TPB: psoc is null";
    goto LABEL_7;
  }
  if ( *(_DWORD *)(a3 + 788) >= 4u )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: TPB: Invalid num_phy_reg_cap %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "init_deinit_populate_power_boost_cap_ext2");
LABEL_8:
    result = 4294967274LL;
    goto LABEL_9;
  }
  result = wmi_extract_power_boost_capability(a1, a2, 0, v25);
  if ( (_DWORD)result )
  {
    v24 = result;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: TPB: failed to parse power_boost cap ext2",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "init_deinit_populate_power_boost_cap_ext2");
    result = qdf_status_to_os_return(v24);
  }
  else
  {
    *(_BYTE *)(a3 + 1031) = v25[0];
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
