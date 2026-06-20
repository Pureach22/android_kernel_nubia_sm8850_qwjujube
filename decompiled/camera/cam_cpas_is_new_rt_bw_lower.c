__int64 __fastcall cam_cpas_is_new_rt_bw_lower(__int64 a1, __int64 a2)
{
  __int64 v2; // x22
  unsigned __int64 v3; // x25
  unsigned __int64 v4; // x23
  unsigned __int64 v5; // x24
  _QWORD *v6; // x26
  _BOOL4 v7; // w8
  __int64 v9; // [xsp+8h] [xbp-18h]
  __int64 v10; // [xsp+10h] [xbp-10h]

  v2 = *(_QWORD *)(a1 + 3680);
  if ( *(_DWORD *)(v2 + 2780) )
  {
    v3 = 0;
    v4 = 0;
    v5 = 0;
    v6 = (_QWORD *)(v2 + 3096);
    while ( v3 != 7 )
    {
      if ( *((_BYTE *)v6 + 249) == 1 )
      {
        a2 = debug_mdl & 0x2000004;
        v7 = a2 != 0;
        if ( debug_priority )
          v7 = 0;
        if ( *((_BYTE *)v6 + 88) == 1 )
        {
          if ( v7 )
            a1 = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))cam_print_log)(
                   3,
                   a2,
                   4,
                   "cam_cpas_is_new_rt_bw_lower",
                   916,
                   "Port %s DRV ab applied [%llu %llu] new [%llu %llu]",
                   *v6,
                   v6[45],
                   v6[48],
                   v6[37],
                   v6[40]);
        }
        else if ( v7 )
        {
          a1 = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _QWORD, __int64, __int64))cam_print_log)(
                 3,
                 a2,
                 4,
                 "cam_cpas_is_new_rt_bw_lower",
                 924,
                 "Port %s HLOS ab applied %llu new %llu",
                 *v6,
                 v6[45],
                 v6[37],
                 v9,
                 v10);
        }
        v5 += v6[45];
        v4 += v6[37];
      }
      ++v3;
      v6 += 51;
      if ( v3 >= *(unsigned int *)(v2 + 2780) )
        return v4 < v5;
    }
    __break(0x5512u);
    return cam_cpas_apply_smart_qos(a1, a2);
  }
  else
  {
    v5 = 0;
    v4 = 0;
    return v4 < v5;
  }
}
