__int64 __fastcall sde_encoder_poll_line_counts(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  __int64 v8; // x8
  __int64 v10; // x0
  __int64 (__fastcall *v11)(_QWORD); // x10
  __int64 v12; // x21
  __int64 v13; // x0
  int v14; // w20
  int v15; // w22
  unsigned int v16; // w23
  __int64 (*v17)(void); // x8
  __int64 v18; // x0
  int v19; // w7
  char v21; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    printk(&unk_26FCAB, "sde_encoder_poll_line_counts");
    return 4294967274LL;
  }
  v8 = *(_QWORD *)(a1 + 328);
  if ( !v8 || !*(_QWORD *)(v8 + 272) )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "enc%d can't get master line count\n", *(_DWORD *)(a1 + 24));
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_encoder_poll_line_counts",
      6698,
      -1,
      *(_DWORD *)(a1 + 24),
      60333,
      -1059143953,
      a8,
      v21);
    return 4294967274LL;
  }
  v10 = ktime_get(a1);
  v11 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 328) + 272LL);
  v12 = v10 + 50000000;
  v13 = *(_QWORD *)(a1 + 328);
  if ( *((_DWORD *)v11 - 1) != -451714968 )
    __break(0x822Au);
  v14 = v11(v13);
  v15 = 5000;
  while ( 1 )
  {
    v16 = v14;
    v17 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 328) + 272LL);
    if ( *((_DWORD *)v17 - 1) != -451714968 )
      __break(0x8228u);
    v18 = v17();
    v14 = v18;
    if ( (unsigned int)v18 < v16 )
      break;
    if ( v12 - ktime_get(v18) >= 1 )
    {
      usleep_range_state(10, 20, 2);
      if ( --v15 )
        continue;
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "sde_encoder_poll_line_counts",
      6723,
      -1,
      *(_DWORD *)(a1 + 24),
      v14,
      60333,
      -1059143953,
      v21);
    return 4294967186LL;
  }
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "sde_encoder_poll_line_counts",
    6712,
    -1,
    *(_DWORD *)(a1 + 24),
    v18,
    -1059143953,
    v19,
    v21);
  return 0;
}
