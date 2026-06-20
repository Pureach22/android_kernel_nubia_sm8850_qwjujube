__int64 __fastcall hif_config_ce(__int64 a1)
{
  __int64 v1; // x9
  unsigned int v3; // w8
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x9
  int v6; // w10
  unsigned __int64 v7; // x14
  char v8; // w13
  __int64 v9; // x21
  unsigned __int64 v10; // x20
  unsigned int v11; // w19
  __int64 v12; // x1

  v1 = *(_QWORD *)(a1 + 616);
  *(_BYTE *)(a1 + 649) = 1;
  *(_BYTE *)(a1 + 2456) = 32;
  *(_DWORD *)(a1 + 29144) = *(_DWORD *)(v1 + 260);
  v3 = *(_DWORD *)(hif_get_target_info_handle(a1) + 4);
  if ( v3 <= 0x2B && ((1LL << v3) & 0xFBFFFB00000LL) != 0 )
    *(_QWORD *)(a1 + 160) = hif_srng_sleep_state_adjust;
  v4 = *(unsigned int *)(a1 + 656);
  *(_QWORD *)(a1 + 3608) = 0;
  if ( (_DWORD)v4 )
  {
    v5 = 0;
    v6 = 0;
    do
    {
      if ( ((1 << v5) & 0x8E) != 0 )
      {
        if ( v5 >= 0xC )
          goto LABEL_23;
        v8 = v6++;
      }
      else
      {
        if ( v5 > 0xB )
          goto LABEL_23;
        v8 = -1;
      }
      v7 = a1 + v5++;
      *(_BYTE *)(v7 + 2800) = v8;
    }
    while ( v4 != v5 );
    v9 = 0;
    v10 = 0;
    while ( v9 != 416 )
    {
      if ( (*(_BYTE *)(*(_QWORD *)(a1 + 27400) + v9) & 0x40) == 0 )
      {
        if ( (unsigned int)hif_config_ce_by_id(a1, v10) )
          goto LABEL_20;
        v4 = *(unsigned int *)(a1 + 656);
      }
      ++v10;
      v9 += 32;
      if ( v10 >= v4 )
        goto LABEL_19;
    }
LABEL_23:
    __break(0x5512u);
    return hif_srng_sleep_state_adjust();
  }
  else
  {
LABEL_19:
    if ( (unsigned int)athdiag_procfs_init(a1) )
    {
LABEL_20:
      ((void (__fastcall *)(__int64))hif_unconfig_ce)(a1);
      v11 = 1;
      v12 = 5;
    }
    else
    {
      *(_BYTE *)(a1 + 736) = 1;
      qdf_trace_msg(61, 8, "%s: ce_init done", "hif_config_ce");
      v12 = 8;
      v11 = 0;
    }
    qdf_trace_msg(61, v12, "%s: X, ret = %d", "hif_config_ce", 0);
    return v11;
  }
}
