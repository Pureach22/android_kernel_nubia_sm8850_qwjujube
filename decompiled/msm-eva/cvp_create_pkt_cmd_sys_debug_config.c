__int64 __fastcall cvp_create_pkt_cmd_sys_debug_config(__int64 a1, int a2)
{
  __int64 result; // x0
  int v4; // w9

  if ( !a1 )
    return 4294967274LL;
  *(_DWORD *)(a1 + 16) = a2;
  *(_DWORD *)(a1 + 20) = 1;
  result = 0;
  *(_QWORD *)a1 = 0x110100600000018LL;
  *(_QWORD *)(a1 + 8) = 0x100000001LL;
  if ( msm_cvp_fw_debug_mode >= 4 )
    v4 = 1;
  else
    v4 = msm_cvp_fw_debug_mode;
  *(_DWORD *)(a1 + 20) = v4;
  return result;
}
