__int64 __fastcall wlan_spectral_psoc_open(
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
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 (__fastcall *v19)(_QWORD); // x8
  __int64 v20; // x20
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  if ( a1 )
  {
    if ( (*(_BYTE *)(a1 + 30) & 0x80) != 0 )
    {
      qdf_trace_msg(
        0x56u,
        4u,
        "%s: Spectral feature is disabled",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "wlan_spectral_psoc_open");
      return 39;
    }
    else
    {
      comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x13u);
      if ( comp_private_obj )
      {
        v19 = *(__int64 (__fastcall **)(_QWORD))(comp_private_obj + 80);
        if ( v19 )
        {
          v20 = comp_private_obj;
          if ( *((_DWORD *)v19 - 1) != -373219892 )
            __break(0x8228u);
          v21 = v19(a1);
          if ( v21 )
          {
            *(_QWORD *)(v20 + 8) = v21;
            return 0;
          }
          else
          {
            qdf_trace_msg(
              0x56u,
              2u,
              "%s: Spectral psoc lmac object is NULL!",
              v22,
              v23,
              v24,
              v25,
              v26,
              v27,
              v28,
              v29,
              "wlan_spectral_psoc_target_attach");
            return 16;
          }
        }
        else
        {
          return 0;
        }
      }
      else
      {
        qdf_trace_msg(
          0x56u,
          2u,
          "%s: Spectral context is null",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "wlan_spectral_psoc_target_attach");
        return 2;
      }
    }
  }
  else
  {
    qdf_trace_msg(0x56u, 2u, "%s: psoc is null", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_spectral_psoc_open");
    return 4;
  }
}
