__int64 __fastcall dlm_get_delta_of_bssid(int a1, __int64 a2, __int64 *a3)
{
  __int64 system_time; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  __int64 v16; // x9
  int v18; // w8

  system_time = qdf_mc_timer_get_system_time();
  if ( a1 > 2 )
  {
    if ( a1 == 3 )
    {
      v15 = a3[1];
      v16 = *(_QWORD *)(a2 + 112);
      return v16 - system_time + 60000 * v15;
    }
    if ( a1 != 4 )
    {
      if ( a1 == 5 )
        return system_time - *(_QWORD *)(a2 + 128);
LABEL_13:
      qdf_trace_msg(
        0x6Du,
        8u,
        "%s: Wrong list type %d passed",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "dlm_get_delta_of_bssid",
        (unsigned int)a1);
      return 0;
    }
    v18 = *(_DWORD *)(a2 + 56);
    if ( !v18 )
      v18 = 3600000;
    return (v18 + *(_DWORD *)(a2 + 120) - (_DWORD)system_time)
         & (unsigned int)~((v18 + *(_DWORD *)(a2 + 120) - (int)system_time) >> 31);
  }
  else
  {
    if ( !a1 )
    {
      v15 = *a3;
      v16 = *(_QWORD *)(a2 + 88);
      return v16 - system_time + 60000 * v15;
    }
    if ( a1 != 1 )
    {
      if ( a1 == 2 )
      {
        v15 = *a3;
        v16 = *(_QWORD *)(a2 + 96);
        return v16 - system_time + 60000 * v15;
      }
      goto LABEL_13;
    }
    return system_time - *(_QWORD *)(a2 + 104);
  }
}
