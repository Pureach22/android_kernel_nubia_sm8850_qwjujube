__int64 __fastcall policy_mgr_get_valid_chans(__int64 a1, void *a2, unsigned int *a3)
{
  __int64 context; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w8
  int v15; // w8
  unsigned int v16; // w21
  __int64 v17; // x22

  *a3 = 0;
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v14 = *(_DWORD *)(context + 2656);
    if ( v14 )
    {
      *a3 = v14;
      qdf_mem_copy(a2, (const void *)(context + 2248), (unsigned int)(4 * *(_DWORD *)(context + 2656)));
      if ( *a3 )
      {
        v15 = 0;
        v16 = 0;
        do
        {
          v17 = v15;
          if ( (wlan_reg_is_dsrc_freq() & 1) == 0 )
            *((_DWORD *)a2 + v16++) = *((_DWORD *)a2 + v17);
          v15 = v17 + 1;
        }
        while ( (int)v17 + 1 < *a3 );
      }
      else
      {
        v16 = 0;
      }
      *a3 = v16;
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid PM valid channel list",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "policy_mgr_get_valid_chans");
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v6, v7, v8, v9, v10, v11, v12, v13, "policy_mgr_get_valid_chans");
    return 16;
  }
}
