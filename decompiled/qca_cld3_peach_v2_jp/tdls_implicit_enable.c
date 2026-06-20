__int64 __fastcall tdls_implicit_enable(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  __int64 v10; // x22
  __int64 v11; // x21
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  _QWORD *v20; // x1
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 comp_private_obj; // x0
  __int64 v25; // x20
  unsigned __int64 StatusReg; // x8
  __int64 v27; // x8
  __int64 i; // x22
  _QWORD *v29; // x1
  const char *v30; // x2
  __int64 v31; // [xsp+0h] [xbp-10h] BYREF
  __int64 v32; // [xsp+8h] [xbp-8h]

  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v9 = result;
    qdf_trace_msg(
      0,
      8u,
      "%s: vdev:%d Enable Implicit TDLS",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "tdls_implicit_enable",
      *(unsigned __int8 *)(*(_QWORD *)result + 104LL));
    v10 = 0;
    v11 = v9 + 8;
    v31 = 0;
    *(_DWORD *)(v9 + 764) = 0;
    do
    {
      if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(v11 + 24 * v10), &v31) )
      {
        do
        {
          v20 = (_QWORD *)v31;
          *(_BYTE *)(v31 + 41) = 0;
        }
        while ( !(unsigned int)qdf_list_peek_next((_QWORD *)(v11 + 24 * v10), v20, &v31) );
      }
      ++v10;
    }
    while ( v10 != 16 );
    v21 = *(_QWORD *)v9;
    v31 = 0;
    if ( v21 )
    {
      v22 = *(_QWORD *)(v21 + 152);
      if ( v22 )
      {
        v23 = *(_QWORD *)(v22 + 80);
        if ( v23 )
        {
          comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v23, 0xAu);
          if ( comp_private_obj )
          {
            v25 = comp_private_obj;
            if ( (_ReadStatusReg(DAIF) & 0x80) != 0
              || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
              || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            {
              raw_spin_lock(comp_private_obj + 352);
            }
            else
            {
              raw_spin_lock_bh(comp_private_obj + 352);
              *(_QWORD *)(v25 + 360) |= 1uLL;
            }
            *(_BYTE *)(v9 + 944) = 0;
            v27 = *(_QWORD *)(v25 + 360);
            if ( (v27 & 1) != 0 )
            {
              *(_QWORD *)(v25 + 360) = v27 & 0xFFFFFFFFFFFFFFFELL;
              raw_spin_unlock_bh(v25 + 352);
            }
            else
            {
              raw_spin_unlock(v25 + 352);
            }
            for ( i = 0; i != 16; ++i )
            {
              if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(v11 + 24 * i), &v31) )
              {
                do
                {
                  v29 = (_QWORD *)v31;
                  *(_DWORD *)(v31 + 44) = 0;
                }
                while ( !(unsigned int)qdf_list_peek_next((_QWORD *)(v11 + 24 * i), v29, &v31) );
              }
            }
          }
          goto LABEL_25;
        }
      }
      v30 = "%s: can't get psoc";
    }
    else
    {
      v30 = "%s: NULL vdev";
    }
    qdf_trace_msg(0, 2u, v30, v12, v13, v14, v15, v16, v17, v18, v19, "wlan_vdev_get_tdls_soc_obj", v31, v32);
LABEL_25:
    result = tdls_timer_restart(*(_QWORD *)v9, v9 + 392, *(unsigned int *)(v9 + 732));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
