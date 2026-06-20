__int64 __fastcall policy_mgr_is_dbs_allowed_for_concurrency(__int64 a1, unsigned int a2)
{
  __int64 context; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  int connection_count; // w0
  unsigned int v15; // w8
  unsigned int v16; // w8

  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid context",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "policy_mgr_is_dbs_allowed_for_concurrency");
    goto LABEL_13;
  }
  v13 = context;
  connection_count = policy_mgr_get_connection_count(a1);
  LOBYTE(v15) = 1;
  if ( a2 != 17 && connection_count == 1 )
  {
    v16 = *(_DWORD *)(v13 + 2228);
    if ( (unsigned int)(pm_conc_connection_list - 2) < 2 )
    {
      v15 = a2 | (v16 >> 1) & 1;
      if ( !v15 )
        return v15 & 1;
    }
    else
    {
      if ( (_DWORD)pm_conc_connection_list == 5 )
      {
        if ( a2 < 0xC )
        {
          v15 = 0x88Fu >> a2;
          return v15 & 1;
        }
        goto LABEL_20;
      }
      if ( !(_DWORD)pm_conc_connection_list )
      {
        if ( a2 - 2 >= 2 && a2 != 7 )
        {
          if ( !a2 && (v16 & 1) == 0 )
            goto LABEL_20;
          goto LABEL_13;
        }
        if ( (v16 & 2) == 0 )
        {
LABEL_20:
          LOBYTE(v15) = 0;
          return v15 & 1;
        }
      }
    }
LABEL_13:
    LOBYTE(v15) = 1;
  }
  return v15 & 1;
}
