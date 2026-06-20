__int64 __fastcall target_if_cp_stats_extract_pmf_bcn_protect_stats(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w19

  _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(a2 + 1) & 0x80) != 0 )
  {
    qdf_mem_set((void *)(a3 + 168), 0x14u, 0);
    result = wmi_extract_pmf_bcn_protect_stats(a1);
    if ( (_DWORD)result )
    {
      v14 = result;
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: wmi_extract_pmf_bcn_protect_stats failed",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "target_if_cp_stats_extract_pmf_bcn_protect_stats");
      result = v14;
    }
    else
    {
      *(_BYTE *)(a3 + 168) = 1;
      *(_DWORD *)(a3 + 172) = 0;
      *(_QWORD *)(a3 + 176) = 0;
      *(_DWORD *)(a3 + 184) = 0;
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
