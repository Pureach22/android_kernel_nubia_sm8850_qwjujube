__int64 __fastcall pmo_tgt_psoc_get_runtime_pm_inprogress(__int64 a1)
{
  __int64 (__fastcall *v2)(_QWORD); // x8
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  char v11; // w0

  v2 = *(__int64 (__fastcall **)(_QWORD))(wlan_objmgr_psoc_get_comp_private_obj(a1, 4u) + 416);
  if ( v2 )
  {
    if ( *((_DWORD *)v2 - 1) != -1548408 )
      __break(0x8228u);
    v11 = v2(a1);
  }
  else
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: psoc_get_runtime_pm_in_progress is null",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "pmo_tgt_psoc_get_runtime_pm_inprogress");
    v11 = 1;
  }
  return v11 & 1;
}
