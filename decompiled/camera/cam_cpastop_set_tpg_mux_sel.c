__int64 __fastcall cam_cpastop_set_tpg_mux_sel(__int64 a1, char a2)
{
  _DWORD *v2; // x19
  __int64 v3; // x8
  __int64 v4; // x8
  unsigned int v5; // w9
  __int64 v7; // x21
  unsigned int v8; // w0
  __int64 v9; // x8
  unsigned int v10; // w19
  _DWORD *v11; // x8
  int v12; // w20

  v2 = *(_DWORD **)(a1 + 3680);
  v3 = *(_QWORD *)(*(_QWORD *)v2 + 40LL);
  if ( !v3 )
    return 0;
  v4 = *(_QWORD *)(v3 + 56);
  if ( !v4 || *(_BYTE *)(v4 + 8) != 1 )
    return 0;
  v5 = v2[703];
  if ( v5 <= 7 )
  {
    v7 = a1 + 24LL * v5;
    v8 = cam_io_r_mb(*(_QWORD *)(v7 + 384) + *(unsigned int *)(v4 + 4));
    v9 = *(_QWORD *)v2;
    v10 = v8;
    v11 = *(_DWORD **)(*(_QWORD *)(v9 + 40) + 56LL);
    v12 = 1 << a2 << *v11;
    cam_io_w_mb(v12 | v8, *(_QWORD *)(v7 + 384) + (unsigned int)v11[1]);
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpastop_set_tpg_mux_sel",
        1676,
        "SET TPG MUX to 0x%x",
        v12 | v10);
    return 0;
  }
  __break(0x5512u);
  return cam_cpastop_dump_camnoc_buff_fill_info();
}
