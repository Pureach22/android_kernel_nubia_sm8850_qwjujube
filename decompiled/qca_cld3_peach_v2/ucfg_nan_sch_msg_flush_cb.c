__int64 __fastcall ucfg_nan_sch_msg_flush_cb(
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
  unsigned int **v9; // x8
  unsigned int v10; // w9
  unsigned __int64 v11; // t2
  bool v12; // cc
  int v13; // w9
  unsigned int *v15; // x8

  if ( !a1 )
    return 29;
  v9 = *((unsigned int ***)a1 + 1);
  if ( !v9 )
    return 29;
  HIDWORD(v11) = *a1 - 4;
  LODWORD(v11) = HIDWORD(v11);
  v10 = v11 >> 1;
  v12 = v10 > 7;
  v13 = (1 << v10) & 0xC7;
  if ( v12 || v13 == 0 )
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: Invalid NAN msg type during sch flush",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "ucfg_nan_sch_msg_flush_cb");
    return 4;
  }
  else
  {
    v15 = *v9;
    if ( v15 )
    {
      wlan_objmgr_vdev_release_ref((__int64)v15, 0x14u, v15, a2, a3, a4, a5, a6, a7, a8, a9);
      _qdf_mem_free(*((_QWORD *)a1 + 1));
    }
    return 0;
  }
}
