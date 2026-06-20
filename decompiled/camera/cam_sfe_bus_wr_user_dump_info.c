_DWORD *__fastcall cam_sfe_bus_wr_user_dump_info(int *a1, _DWORD *a2)
{
  int v4; // w21
  int v5; // w22
  int v6; // w23
  int v7; // w8
  int v9; // w9

  v4 = cam_io_r_mb(*(_QWORD *)(*((_QWORD *)a1 + 1) + 8LL) + *(unsigned int *)(*((_QWORD *)a1 + 2) + 68LL));
  v5 = cam_io_r_mb(*(_QWORD *)(*((_QWORD *)a1 + 1) + 8LL) + *(unsigned int *)(*((_QWORD *)a1 + 2) + 72LL));
  v6 = cam_io_r_mb(*(_QWORD *)(*((_QWORD *)a1 + 1) + 8LL) + *(unsigned int *)(*((_QWORD *)a1 + 2) + 76LL));
  v7 = cam_io_r_mb(*(_QWORD *)(*((_QWORD *)a1 + 1) + 8LL) + *(unsigned int *)(*((_QWORD *)a1 + 2) + 80LL));
  *a2 = *(_DWORD *)(*(_QWORD *)(*((_QWORD *)a1 + 1) + 16LL) + 4LL);
  v9 = *a1;
  a2[3] = v5;
  a2[4] = v6;
  a2[1] = v9;
  a2[2] = v4;
  a2[5] = v7;
  return a2 + 6;
}
