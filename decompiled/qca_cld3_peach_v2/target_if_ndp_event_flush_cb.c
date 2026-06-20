__int64 __fastcall target_if_ndp_event_flush_cb(
        unsigned __int16 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // w8
  bool v11; // cc
  int v12; // w8
  __int64 *v14; // x8

  v9 = *a1;
  v11 = v9 > 0x11;
  v12 = (1 << v9) & 0x29EA0;
  if ( !v11 && v12 != 0 )
  {
    v14 = *((__int64 **)a1 + 1);
    if ( *v14 )
      wlan_objmgr_vdev_release_ref(*v14, 0x14u, (unsigned int *)v14, a2, a3, a4, a5, a6, a7, a8, a9);
  }
  _qdf_mem_free(*((_QWORD *)a1 + 1));
  *((_QWORD *)a1 + 1) = 0;
  return 0;
}
