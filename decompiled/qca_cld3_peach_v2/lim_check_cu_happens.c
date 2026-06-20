__int64 __fastcall lim_check_cu_happens(
        __int64 result,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v13; // x21
  char is_mlo_vdev; // w8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w6
  __int64 v24; // x23
  _BYTE v25[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    v13 = result;
    v25[0] = 0;
    is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(result, a4, a5, a6, a7, a8, a9, a10, a11);
    result = 0;
    if ( (is_mlo_vdev & 1) != 0 )
    {
      if ( (unsigned int)wlan_mlo_get_cu_bpcc(v13, a2, v25) )
        goto LABEL_9;
      v23 = v25[0];
      if ( !((unsigned __int8)a3 | v25[0]) )
        goto LABEL_9;
      v24 = jiffies;
      if ( lim_check_cu_happens___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: link id %d new bpcc %d, old bpcc %d",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "lim_check_cu_happens",
          (unsigned __int8)a2,
          (unsigned __int8)a3);
        v23 = v25[0];
        lim_check_cu_happens___last_ticks = v24;
      }
      if ( (_BYTE)a3 && v23 > (unsigned __int8)a3 )
      {
LABEL_9:
        result = 0;
      }
      else
      {
        wlan_mlo_set_cu_bpcc(v13, a2, a3);
        result = 1;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
