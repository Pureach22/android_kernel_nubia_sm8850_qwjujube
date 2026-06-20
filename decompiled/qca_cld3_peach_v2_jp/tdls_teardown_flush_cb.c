__int64 __fastcall tdls_teardown_flush_cb(
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
  __int64 *v9; // x19

  v9 = *(__int64 **)(a1 + 8);
  wlan_objmgr_psoc_release_ref(*v9, 0x10u, a2, a3, a4, a5, a6, a7, a8, a9);
  _qdf_mem_free((__int64)v9);
  return 0;
}
