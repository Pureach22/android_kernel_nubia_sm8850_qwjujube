__int64 __fastcall wlan_register_spectral_tgt_ops(
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
  __int64 comp_private_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 (__fastcall *v21)(__int64, __int64); // x8

  if ( a1 )
  {
    if ( (*(_BYTE *)(a1 + 30) & 0x80) != 0 )
    {
      qdf_trace_msg(
        0x56u,
        4u,
        "%s: Spectral feature is disabled",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wlan_register_spectral_tgt_ops");
      return 39;
    }
    else
    {
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x13u);
      if ( comp_private_obj )
      {
        v21 = *(__int64 (__fastcall **)(__int64, __int64))(comp_private_obj + 184);
        if ( *((_DWORD *)v21 - 1) != 599622670 )
          __break(0x8228u);
        return v21(a1, a2);
      }
      else
      {
        qdf_trace_msg(
          0x56u,
          2u,
          "%s: spectral context is NULL!",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "wlan_register_spectral_tgt_ops");
        return 16;
      }
    }
  }
  else
  {
    qdf_trace_msg(0x56u, 2u, "%s: psoc is NULL!", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_register_spectral_tgt_ops");
    return 4;
  }
}
