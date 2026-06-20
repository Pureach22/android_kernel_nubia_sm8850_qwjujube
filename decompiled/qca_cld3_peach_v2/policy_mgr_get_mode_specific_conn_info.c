__int64 __fastcall policy_mgr_get_mode_specific_conn_info(
        __int64 a1,
        unsigned __int64 a2,
        unsigned __int64 a3,
        unsigned int a4)
{
  __int64 context; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x19
  unsigned int v18; // w20
  __int64 v19; // x9
  __int64 v21; // [xsp+0h] [xbp-20h] BYREF
  __int64 v22; // [xsp+8h] [xbp-18h]
  unsigned int v23; // [xsp+10h] [xbp-10h]
  __int64 v24; // [xsp+18h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v21 = 0;
  v22 = 0;
  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v17 = context;
    qdf_mutex_acquire(context + 56);
    v18 = policy_mgr_mode_specific_connection_count(a1, a4, &v21);
    if ( v18 )
    {
      if ( v18 != 1 )
      {
        if ( a2 )
        {
          if ( (unsigned int)v21 > 4 )
            goto LABEL_50;
          *(_DWORD *)a2 = *((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v21 + 1);
        }
        if ( a3 )
        {
          if ( (unsigned int)v21 > 4 )
            goto LABEL_50;
          *(_BYTE *)a3 = *((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v21 + 6);
        }
        if ( a2 )
        {
          if ( HIDWORD(v21) > 4 )
            goto LABEL_50;
          *(_DWORD *)(a2 + 4) = *((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v21) + 1);
        }
        if ( a3 )
        {
          if ( HIDWORD(v21) > 4 )
            goto LABEL_50;
          *(_BYTE *)(a3 + 1) = *((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v21) + 6);
        }
        if ( v18 == 2 )
          goto LABEL_48;
        if ( a2 )
        {
          if ( (unsigned int)v22 > 4 )
            goto LABEL_50;
          *(_DWORD *)(a2 + 8) = *((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v22 + 1);
        }
        if ( a3 )
        {
          if ( (unsigned int)v22 > 4 )
            goto LABEL_50;
          *(_BYTE *)(a3 + 2) = *((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v22 + 6);
        }
        if ( v18 == 3 )
          goto LABEL_48;
        if ( a2 )
        {
          if ( HIDWORD(v22) > 4 )
            goto LABEL_50;
          *(_DWORD *)(a2 + 12) = *((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v22) + 1);
        }
        if ( a3 )
        {
          if ( HIDWORD(v22) > 4 )
            goto LABEL_50;
          *(_BYTE *)(a3 + 3) = *((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v22) + 6);
        }
        if ( v18 == 4 )
          goto LABEL_48;
        if ( a2 )
        {
          if ( v23 > 4 )
            goto LABEL_50;
          *(_DWORD *)(a2 + 16) = *((_DWORD *)&pm_conc_connection_list + 9 * v23 + 1);
        }
        if ( a3 )
        {
          if ( v23 > 4 )
            goto LABEL_50;
          *(_BYTE *)(a3 + 4) = *((_DWORD *)&pm_conc_connection_list + 9 * v23 + 6);
        }
        if ( v18 == 5 )
          goto LABEL_48;
        v19 = v18 - 5LL;
        while ( !(a2 | a3) )
        {
          if ( !--v19 )
            goto LABEL_48;
        }
LABEL_50:
        __break(0x5512u);
      }
      if ( a2 )
      {
        if ( (unsigned int)v21 > 4 )
          goto LABEL_50;
        *(_DWORD *)a2 = *((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v21 + 1);
      }
      if ( a3 )
      {
        if ( (unsigned int)v21 <= 4 )
        {
          *(_BYTE *)a3 = *((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v21 + 6);
          goto LABEL_48;
        }
        goto LABEL_50;
      }
    }
LABEL_48:
    qdf_mutex_release(v17 + 56);
    goto LABEL_49;
  }
  qdf_trace_msg(
    0x4Fu,
    2u,
    "%s: Invalid Context",
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    "policy_mgr_get_mode_specific_conn_info");
  v18 = 0;
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return v18;
}
