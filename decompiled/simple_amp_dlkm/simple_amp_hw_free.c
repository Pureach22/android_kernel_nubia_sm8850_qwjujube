__int64 __fastcall simple_amp_hw_free(__int64 a1, __int64 a2)
{
  unsigned int *v2; // x8
  __int64 v3; // x19
  __int64 v4; // x20
  int v5; // w0
  int v6; // w0
  unsigned int v7; // w1
  __int64 v9; // x8
  unsigned int v10; // w19

  v2 = *(unsigned int **)(a2 + 48);
  if ( !v2 )
    return 0;
  v3 = *(_QWORD *)(a2 + 96);
  v4 = *(_QWORD *)(*(_QWORD *)(v3 + 24) + 152LL);
  v5 = swr_disconnect_port(*(_QWORD *)(v4 + 16), v2 + 1, *v2, v2 + 2, v2 + 3);
  if ( v5 )
    dev_err(*(_QWORD *)(v3 + 24), "%s: swr disconnect port failed: %d\n", "simple_amp_hw_free", v5);
  v6 = swr_slvdev_datapath_control(*(_QWORD *)(v4 + 16), *(unsigned __int8 *)(*(_QWORD *)(v4 + 16) + 64LL), 0);
  v7 = 0;
  if ( v6 )
  {
    v9 = *(_QWORD *)(v3 + 24);
    v10 = v6;
    dev_err(v9, "%s: swr slv dath control failed: %d\n", "simple_amp_hw_free", v6);
    return v10;
  }
  return v7;
}
