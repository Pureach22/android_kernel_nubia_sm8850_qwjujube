_DWORD *__fastcall cam_vfe_bus_ver3_user_dump_info(__int64 a1, _DWORD *a2)
{
  __int64 v4; // x24
  int v5; // w21
  int v6; // w22
  int v7; // w23
  int v8; // w8
  int v10; // w9

  v4 = *(_QWORD *)(*(_QWORD *)a1 + 16LL) + *(unsigned int *)(a1 + 156);
  v5 = cam_io_r_mb(v4 + *(unsigned int *)(*(_QWORD *)(a1 + 8) + 96LL));
  v6 = cam_io_r_mb(v4 + *(unsigned int *)(*(_QWORD *)(a1 + 8) + 100LL));
  v7 = cam_io_r_mb(v4 + *(unsigned int *)(*(_QWORD *)(a1 + 8) + 104LL));
  v8 = cam_io_r_mb(v4 + *(unsigned int *)(*(_QWORD *)(a1 + 8) + 108LL));
  *a2 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 24LL) + 4LL);
  v10 = *(_DWORD *)(a1 + 120);
  a2[3] = v6;
  a2[4] = v7;
  a2[1] = v10;
  a2[2] = v5;
  a2[5] = v8;
  return a2 + 6;
}
