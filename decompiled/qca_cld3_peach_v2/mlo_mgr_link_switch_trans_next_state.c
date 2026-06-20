__int64 __fastcall mlo_mgr_link_switch_trans_next_state(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x8
  int v11; // w9
  unsigned int v12; // w20

  qdf_mutex_acquire(a1 + 1656);
  v10 = *(_QWORD *)(a1 + 3880);
  v11 = *(_DWORD *)(v10 + 164);
  if ( v11 <= 2 )
  {
    switch ( v11 )
    {
      case 0:
        v12 = 0;
        v11 = 1;
        goto LABEL_17;
      case 1:
        v12 = 0;
        v11 = 2;
        goto LABEL_17;
      case 2:
        v12 = 0;
        v11 = 3;
        goto LABEL_17;
    }
LABEL_13:
    v12 = 0;
    goto LABEL_17;
  }
  if ( v11 > 4 )
  {
    if ( v11 == 5 )
    {
      v12 = 0;
      v11 = 0;
      goto LABEL_17;
    }
    if ( v11 == 6 )
    {
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: State transition not allowed",
        v2,
        v3,
        v4,
        v5,
        v6,
        v7,
        v8,
        v9,
        "mlo_mgr_link_switch_trans_next_state");
      v10 = *(_QWORD *)(a1 + 3880);
      v11 = 6;
      v12 = 12;
      goto LABEL_17;
    }
    goto LABEL_13;
  }
  v12 = 0;
  if ( v11 == 3 )
    v11 = 4;
  else
    v11 = 5;
LABEL_17:
  *(_DWORD *)(v10 + 164) = v11;
  qdf_mutex_release(a1 + 1656);
  return v12;
}
