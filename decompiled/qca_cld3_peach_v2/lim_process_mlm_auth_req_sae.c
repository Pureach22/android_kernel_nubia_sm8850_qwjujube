__int64 __fastcall lim_process_mlm_auth_req_sae(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int16 v5; // w2
  int v6; // w8
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7

  result = lim_trigger_auth_req_sae(a1, a2, (int *)(a2 + 24));
  if ( !(_DWORD)result )
  {
    v5 = *(_WORD *)(a2 + 8);
    *(_DWORD *)(a2 + 72) = 29;
    qdf_trace(53, 0, v5, 29);
    *(_BYTE *)(a1 + 3242) = *(_BYTE *)(a2 + 8);
    qdf_trace(53, 0xDu, *(_WORD *)(a2 + 8), 21);
    v6 = tx_timer_activate((char *)(a1 + 3192));
    result = 0;
    if ( v6 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: could not start Auth SAE timer",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "lim_process_mlm_auth_req_sae");
      return 0;
    }
  }
  return result;
}
