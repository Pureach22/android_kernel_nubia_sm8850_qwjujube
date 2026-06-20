bool __fastcall ucfg_is_nan_vdev(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x8

  if ( *(_DWORD *)(a1 + 16) == 16 )
    return 1;
  v10 = *(_QWORD *)(a1 + 216);
  if ( v10 )
  {
    if ( (ucfg_nan_is_vdev_creation_allowed(*(_QWORD *)(v10 + 80), a2, a3, a4, a5, a6, a7, a8, a9) & 1) != 0 )
      return 0;
  }
  else if ( (ucfg_nan_is_vdev_creation_allowed(0, a2, a3, a4, a5, a6, a7, a8, a9) & 1) != 0 )
  {
    return 0;
  }
  return !*(_DWORD *)(a1 + 16);
}
