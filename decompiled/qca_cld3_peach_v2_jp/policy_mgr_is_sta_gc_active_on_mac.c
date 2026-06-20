__int64 __fastcall policy_mgr_is_sta_gc_active_on_mac(__int64 a1, unsigned __int8 a2)
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
  __int64 v13; // x19
  int v14; // w22
  int v15; // w21
  int v16; // w20
  __int64 result; // x0
  __int64 v18; // [xsp+0h] [xbp-20h] BYREF
  __int64 v19; // [xsp+8h] [xbp-18h]
  unsigned int v20; // [xsp+10h] [xbp-10h]
  __int64 v21; // [xsp+18h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v18 = 0;
  v19 = 0;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: Invalid Context",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "policy_mgr_is_sta_gc_active_on_mac");
    goto LABEL_12;
  }
  v13 = context;
  v14 = a2;
  v15 = policy_mgr_mode_specific_connection_count(a1, 0, &v18);
  qdf_mutex_acquire(v13 + 56);
  if ( v15 )
  {
    if ( (unsigned int)v18 >= 5 )
      goto LABEL_40;
    if ( *((unsigned __int8 *)&pm_conc_connection_list + 36 * (unsigned int)v18 + 12) == v14 )
      goto LABEL_28;
    if ( v15 != 1 )
    {
      if ( HIDWORD(v18) > 4 )
        goto LABEL_40;
      if ( *((unsigned __int8 *)&pm_conc_connection_list + 36 * HIDWORD(v18) + 12) == v14 )
        goto LABEL_28;
      if ( v15 != 2 )
      {
        if ( (unsigned int)v19 > 4 )
          goto LABEL_40;
        if ( *((unsigned __int8 *)&pm_conc_connection_list + 36 * (unsigned int)v19 + 12) == v14 )
          goto LABEL_28;
        if ( v15 != 3 )
        {
          if ( HIDWORD(v19) > 4 )
            goto LABEL_40;
          if ( *((unsigned __int8 *)&pm_conc_connection_list + 36 * HIDWORD(v19) + 12) == v14 )
            goto LABEL_28;
          if ( v15 != 4 )
          {
            if ( v20 > 4 )
              goto LABEL_40;
            if ( *((unsigned __int8 *)&pm_conc_connection_list + 36 * v20 + 12) == v14 )
              goto LABEL_28;
            if ( v15 != 5 )
              goto LABEL_40;
          }
        }
      }
    }
  }
  qdf_mutex_release(v13 + 56);
  v16 = policy_mgr_mode_specific_connection_count(a1, 2, &v18);
  qdf_mutex_acquire(v13 + 56);
  if ( v16 )
  {
    if ( (unsigned int)v18 >= 5 )
      goto LABEL_40;
    if ( *((unsigned __int8 *)&pm_conc_connection_list + 36 * (unsigned int)v18 + 12) != v14 )
    {
      if ( v16 == 1 )
        goto LABEL_10;
      if ( HIDWORD(v18) <= 4 )
      {
        if ( *((unsigned __int8 *)&pm_conc_connection_list + 36 * HIDWORD(v18) + 12) == v14 )
          goto LABEL_28;
        if ( v16 == 2 )
          goto LABEL_10;
        if ( (unsigned int)v19 <= 4 )
        {
          if ( *((unsigned __int8 *)&pm_conc_connection_list + 36 * (unsigned int)v19 + 12) == v14 )
            goto LABEL_28;
          if ( v16 == 3 )
            goto LABEL_10;
          if ( HIDWORD(v19) <= 4 )
          {
            if ( *((unsigned __int8 *)&pm_conc_connection_list + 36 * HIDWORD(v19) + 12) == v14 )
              goto LABEL_28;
            if ( v16 == 4 )
              goto LABEL_10;
            if ( v20 <= 4 )
            {
              if ( *((unsigned __int8 *)&pm_conc_connection_list + 36 * v20 + 12) == v14 )
                goto LABEL_28;
              if ( v16 == 5 )
                goto LABEL_10;
            }
          }
        }
      }
LABEL_40:
      __break(0x5512u);
    }
LABEL_28:
    qdf_mutex_release(v13 + 56);
    result = 1;
    goto LABEL_29;
  }
LABEL_10:
  qdf_mutex_release(v13 + 56);
LABEL_12:
  result = 0;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
