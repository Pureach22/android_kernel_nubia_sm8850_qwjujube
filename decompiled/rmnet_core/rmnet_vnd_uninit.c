__int64 __fastcall rmnet_vnd_uninit(__int64 a1)
{
  __int64 v2; // x0

  gro_cells_destroy(a1 + 2712);
  free_percpu(*(_QWORD *)(a1 + 2704));
  v2 = *(_QWORD *)(a1 + 3168);
  *(_QWORD *)(a1 + 3168) = 0;
  return qmi_rmnet_qos_exit_pre(v2);
}
