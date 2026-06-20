__int64 __fastcall _cam_node_handle_synx_test(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  int v6; // w8
  int v8; // w7
  __int64 (__fastcall *v9)(__int64, __int64, __int64, __int64, __int64, __int64, __int64); // x8
  __int64 v10; // x0

  v6 = *(_DWORD *)(a1 + 104);
  if ( v6 )
  {
    v8 = 0;
    while ( *(int *)(*(_QWORD *)(a1 + 96) + 552LL * v8 + 60) < 1 )
    {
      if ( v6 == ++v8 )
        goto LABEL_5;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      2,
      1,
      "__cam_node_handle_synx_test",
      759,
      "Node [%s] has active context [%d]",
      a1);
    return 4294967285LL;
  }
  else
  {
LABEL_5:
    v9 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64, __int64, __int64, __int64))(a1 + 272);
    if ( v9 )
    {
      v10 = *(_QWORD *)(a1 + 112);
      if ( *((_DWORD *)v9 - 1) != 1863972096 )
        __break(0x8228u);
      return v9(v10, a2, a3, a4, a5, a6, a1);
    }
    else
    {
      return 4294967274LL;
    }
  }
}
