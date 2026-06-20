__int64 __fastcall ucfg_tdls_post_msg_flush_cb(
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
  unsigned int *v9; // x8
  __int64 *v10; // x20

  v9 = (unsigned int *)*a1;
  v10 = *((__int64 **)a1 + 1);
  if ( (unsigned int)v9 <= 0x17 )
  {
    if ( ((1 << (char)v9) & 0xE040FC) != 0 )
    {
      if ( *v10 )
        wlan_objmgr_vdev_release_ref(*v10, 0x11u, v9, a2, a3, a4, a5, a6, a7, a8, a9);
    }
    else if ( (_DWORD)v9 == 18 )
    {
      goto LABEL_7;
    }
  }
  if ( v10 )
    _qdf_mem_free((__int64)v10);
LABEL_7:
  *((_QWORD *)a1 + 1) = 0;
  return 0;
}
