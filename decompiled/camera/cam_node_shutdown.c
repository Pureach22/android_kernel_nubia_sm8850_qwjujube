__int64 __fastcall cam_node_shutdown(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v2; // w20
  _DWORD *v4; // x8
  __int64 v5; // x0

  if ( !a1 )
    return 4294967274LL;
  v1 = a1;
  if ( *(_DWORD *)(a1 + 104) )
  {
    v2 = 0;
    do
    {
      a1 = *(_QWORD *)(v1 + 96) + 552LL * (int)v2;
      if ( *(int *)(a1 + 60) >= 1 )
      {
        a1 = cam_context_shutdown(a1);
        if ( (debug_mdl & 2) != 0 && !debug_priority )
          a1 = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 debug_mdl & 2,
                 4,
                 "cam_node_shutdown",
                 735,
                 "Node [%s] invoking shutdown on context [%d], rc %d",
                 (const char *)v1,
                 v2,
                 a1);
      }
      ++v2;
    }
    while ( v2 < *(_DWORD *)(v1 + 104) );
  }
  if ( (cam_presil_mode_enabled(a1) & 1) != 0 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      3,
      "cam_node_shutdown",
      740,
      "PRESIL-ICP-B2B-HFI-INIT No Shutdown No Deinit No HFIfreeMem");
  }
  else
  {
    v4 = *(_DWORD **)(v1 + 224);
    if ( v4 )
    {
      v5 = *(_QWORD *)(v1 + 112);
      if ( *(v4 - 1) != 1863972096 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v4)(v5, 0);
    }
  }
  return 0;
}
