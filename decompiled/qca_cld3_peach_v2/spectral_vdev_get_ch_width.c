__int64 __fastcall spectral_vdev_get_ch_width(
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
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 comp_private_obj; // x0
  __int64 (__fastcall *v13)(_QWORD); // x8

  v9 = *(_QWORD *)(a1 + 216);
  if ( v9
    && (v10 = *(_QWORD *)(v9 + 80)) != 0
    && (comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v10, 0x13u)) != 0 )
  {
    v13 = *(__int64 (__fastcall **)(_QWORD))(comp_private_obj + 32);
    if ( v13 )
    {
      if ( *((_DWORD *)v13 - 1) != 1246236989 )
        __break(0x8228u);
      return v13(a1);
    }
    else
    {
      qdf_trace_msg(
        0x56u,
        2u,
        "%s: vdev_get_ch_width is not supported",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "spectral_vdev_get_ch_width");
      return 4294966772LL;
    }
  }
  else
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: spectral context is Null",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "spectral_vdev_get_ch_width");
    return 8;
  }
}
