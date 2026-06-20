__int64 __fastcall policy_mgr_init_sbs_fw_config(__int64 a1, unsigned int a2)
{
  __int64 context; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x4
  unsigned int v13; // w5
  __int64 v14; // x19
  __int64 result; // x0
  const char *v16; // x2
  unsigned int v17; // w1

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    if ( (*(_BYTE *)(context + 2240) & 1) != 0 )
    {
      v12 = *(unsigned int *)(context + 1508);
      v13 = *(_DWORD *)(context + 1516) & 0xFBFFFFFF | (((a2 >> 26) & 1) << 26);
      v14 = context;
      *(_DWORD *)(context + 1516) = v13;
      result = qdf_trace_msg(
                 0x4Fu,
                 8u,
                 "%s: fw_mode config updated from %x to %x",
                 v4,
                 v5,
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 v11,
                 "policy_mgr_init_sbs_fw_config",
                 v12);
      *(_DWORD *)(v14 + 1508) = *(_DWORD *)(v14 + 1516);
      return result;
    }
    v16 = "%s: SBS not enabled from ini";
    v17 = 8;
  }
  else
  {
    v16 = "%s: Invalid Context";
    v17 = 2;
  }
  return qdf_trace_msg(0x4Fu, v17, v16, v4, v5, v6, v7, v8, v9, v10, v11, "policy_mgr_init_sbs_fw_config");
}
