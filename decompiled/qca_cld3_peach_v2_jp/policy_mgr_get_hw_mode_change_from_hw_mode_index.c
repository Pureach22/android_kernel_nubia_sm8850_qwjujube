__int64 __fastcall policy_mgr_get_hw_mode_change_from_hw_mode_index(__int64 a1, unsigned int a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  const char *v12; // x2
  __int64 result; // x0
  __int64 v14; // [xsp+8h] [xbp-18h] BYREF
  __int64 v15; // [xsp+10h] [xbp-10h]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  v15 = 0;
  if ( !policy_mgr_get_context(a1) )
  {
    v12 = "%s: Invalid Context";
    goto LABEL_5;
  }
  if ( (unsigned int)policy_mgr_get_hw_mode_from_idx(a1, a2, &v14) )
  {
    v12 = "%s: Failed to get HW mode index";
LABEL_5:
    qdf_trace_msg(0x4Fu, 2u, v12, v4, v5, v6, v7, v8, v9, v10, v11, "policy_mgr_get_hw_mode_change_from_hw_mode_index");
    result = 0;
    goto LABEL_6;
  }
  if ( HIBYTE(v14) )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: DBS is requested with HW (%d)",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "policy_mgr_get_hw_mode_change_from_hw_mode_index",
      a2);
    result = 2;
  }
  else if ( BYTE1(v15) )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: SBS is requested with HW (%d)",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "policy_mgr_get_hw_mode_change_from_hw_mode_index",
      a2);
    result = 3;
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: SMM is requested with HW (%d)",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "policy_mgr_get_hw_mode_change_from_hw_mode_index",
      a2);
    result = 1;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
