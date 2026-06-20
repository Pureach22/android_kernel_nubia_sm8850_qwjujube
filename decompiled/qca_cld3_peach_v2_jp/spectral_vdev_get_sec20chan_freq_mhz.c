__int64 __fastcall spectral_vdev_get_sec20chan_freq_mhz(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 comp_private_obj; // x0
  __int64 (__fastcall *v15)(__int64, __int64); // x8

  v10 = *(_QWORD *)(a1 + 152);
  if ( v10
    && (v11 = *(_QWORD *)(v10 + 80)) != 0
    && (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v11, 0x13u)) != 0 )
  {
    v15 = *(__int64 (__fastcall **)(__int64, __int64))(comp_private_obj + 40);
    if ( v15 )
    {
      if ( *((_DWORD *)v15 - 1) != -341611430 )
        __break(0x8228u);
      return v15(a1, a2);
    }
    else
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: vdev_get_sec20chan_freq_mhz is not supported",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "spectral_vdev_get_sec20chan_freq_mhz");
      return 4294966772LL;
    }
  }
  else
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: spectral context is Null",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "spectral_vdev_get_sec20chan_freq_mhz");
    return 4294967274LL;
  }
}
