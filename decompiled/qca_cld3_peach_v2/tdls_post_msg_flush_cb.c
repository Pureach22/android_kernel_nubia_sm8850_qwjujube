__int64 __fastcall tdls_post_msg_flush_cb(
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
  __int64 *v10; // x19
  unsigned int v11; // w1

  v9 = (unsigned int *)*a1;
  v10 = *((__int64 **)a1 + 1);
  if ( (_DWORD)v9 == 13 )
  {
    v11 = 17;
    goto LABEL_5;
  }
  if ( (_DWORD)v9 == 24 )
  {
    v11 = 16;
LABEL_5:
    wlan_objmgr_vdev_release_ref(*v10, v11, v9, a2, a3, a4, a5, a6, a7, a8, a9);
    _qdf_mem_free((__int64)v10);
  }
  return 0;
}
