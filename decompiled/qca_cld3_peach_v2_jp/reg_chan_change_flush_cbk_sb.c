__int64 __usercall reg_chan_change_flush_cbk_sb@<X0>(
        __int64 a1@<X0>,
        unsigned int *a2@<X8>,
        double a3@<D0>,
        double a4@<D1>,
        double a5@<D2>,
        double a6@<D3>,
        double a7@<D4>,
        double a8@<D5>,
        double a9@<D6>,
        double a10@<D7>)
{
  __int64 *v10; // x19
  __int64 v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7

  v10 = *(__int64 **)(a1 + 8);
  v11 = *v10;
  wlan_objmgr_pdev_release_ref(v10[1], 0x15u, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  wlan_objmgr_psoc_release_ref(v11, 0x15u, v12, v13, v14, v15, v16, v17, v18, v19);
  _qdf_mem_free((__int64)v10);
  return 0;
}
