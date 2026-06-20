__int64 __fastcall cam_vfe_top_init_hw(__int64 a1)
{
  unsigned int *v1; // x8
  __int64 v2; // x9
  int v4; // w8

  v1 = *(unsigned int **)(a1 + 8);
  v2 = *(_QWORD *)(a1 + 10432);
  *(_QWORD *)(a1 + 10440) = 0;
  v4 = cam_io_r_mb(*(_QWORD *)(v2 + 288) + *v1);
  *(_DWORD *)(a1 + 10400) = v4;
  return 0;
}
