__int64 __fastcall wlan_mlo_check_valid_config(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned int v3; // w21
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  __int64 v15; // x4
  __int64 v16; // x8

  v3 = 16;
  if ( a1 && a2 )
  {
    qdf_mutex_acquire(a1 + 1656);
    v14 = *(_QWORD *)(a1 + 24);
    if ( v14 && (v15 = *(unsigned int *)(v14 + 16), (_DWORD)v15 != a3)
      || (v16 = *(_QWORD *)(a1 + 32)) != 0 && (v15 = *(unsigned int *)(v16 + 16), (_DWORD)v15 != a3) )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: Invalid opmode %d type found expected %d, investigate config",
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        "wlan_mlo_check_valid_config",
        v15,
        a3);
    }
    else
    {
      v3 = 0;
    }
    qdf_mutex_release(a1 + 1656);
  }
  return v3;
}
