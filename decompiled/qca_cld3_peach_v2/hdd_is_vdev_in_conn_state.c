__int64 __fastcall hdd_is_vdev_in_conn_state(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w4
  __int64 v10; // x0

  v9 = *(_DWORD *)(*a1 + 40LL);
  if ( v9 > 7 )
    goto LABEL_6;
  if ( ((1 << v9) & 0x85) == 0 )
  {
    if ( ((1 << v9) & 0xA) != 0 )
    {
      v10 = (a1[746] >> 1) & 1LL;
      return v10 & 1;
    }
LABEL_6:
    qdf_trace_msg(0x33u, 2u, "%s: Device mode %d invalid", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_is_vdev_in_conn_state");
    LOBYTE(v10) = 0;
    return v10 & 1;
  }
  LOBYTE(v10) = hdd_cm_is_vdev_associated(a1);
  return v10 & 1;
}
