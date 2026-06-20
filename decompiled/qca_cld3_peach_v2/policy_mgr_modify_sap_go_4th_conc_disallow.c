__int64 __fastcall policy_mgr_modify_sap_go_4th_conc_disallow(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        _DWORD *a5)
{
  __int64 context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v20; // x24
  __int64 v21; // x25
  unsigned __int64 v22; // x26

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    if ( *a5 < 0x67u )
    {
      v20 = context;
      qdf_mutex_acquire(context + 56);
      if ( (unsigned int)policy_mgr_get_connection_count(a1) >= 3 )
      {
        if ( *a5 )
        {
          v21 = 0;
          v22 = 0;
          do
          {
            if ( (((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))policy_mgr_allow_4th_new_freq)(
                    a1,
                    *(unsigned int *)(a3 + 4 * v22),
                    a2,
                    0)
                & 1) != 0 )
            {
              *(_DWORD *)(a3 + 4 * v21) = *(_DWORD *)(a3 + 4 * v22);
              *(_BYTE *)(a4 + v21++) = *(_BYTE *)(a4 + v22);
            }
            ++v22;
          }
          while ( v22 < (unsigned int)*a5 );
        }
        else
        {
          LODWORD(v21) = 0;
        }
        *a5 = v21;
      }
      qdf_mutex_release(v20 + 56);
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid PCL List Length %d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "policy_mgr_modify_sap_go_4th_conc_disallow");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "policy_mgr_modify_sap_go_4th_conc_disallow");
    return 16;
  }
}
