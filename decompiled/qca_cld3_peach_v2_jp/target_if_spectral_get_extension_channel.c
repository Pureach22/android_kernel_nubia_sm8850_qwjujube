_QWORD *__fastcall target_if_spectral_get_extension_channel(
        __int64 *a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  __int64 v20; // x19
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 (*v23)(void); // x8
  unsigned int *v24; // x8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  const char *v33; // x2

  _ReadStatusReg(SP_EL0);
  if ( !a1 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Null argument.",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_spectral_get_extension_channel");
    goto LABEL_16;
  }
  if ( a2 >= 2 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Invalid Spectral mode %u",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_spectral_get_extension_channel",
      a2);
LABEL_16:
    result = nullptr;
    goto LABEL_17;
  }
  result = target_if_spectral_get_vdev(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    v19 = result[19];
    v20 = (__int64)result;
    if ( v19 && (v21 = *(_QWORD *)(v19 + 80)) != 0 )
    {
      v22 = *(_QWORD *)(v21 + 2136);
      if ( v22 )
      {
        v23 = *(__int64 (**)(void))(v22 + 296);
        if ( *((_DWORD *)v23 - 1) != -341611430 )
          __break(0x8228u);
        if ( (v23() & 0x80000000) == 0 )
        {
          wlan_objmgr_vdev_release_ref(v20, 0x1Bu, v24, v25, v26, v27, v28, v29, v30, v31, v32);
          result = nullptr;
          goto LABEL_17;
        }
LABEL_15:
        wlan_objmgr_vdev_release_ref(v20, 0x1Bu, v24, v25, v26, v27, v28, v29, v30, v31, v32);
        goto LABEL_16;
      }
      v33 = "%s: rx_ops is null";
    }
    else
    {
      v33 = "%s: psoc is NULL";
    }
    qdf_trace_msg(0x56u, 2u, v33, v11, v12, v13, v14, v15, v16, v17, v18, "target_if_vdev_get_sec20chan_freq_mhz");
    goto LABEL_15;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
