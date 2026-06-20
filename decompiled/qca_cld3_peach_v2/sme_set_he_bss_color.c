__int64 __fastcall sme_set_he_bss_color(
        __int64 a1,
        char a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v22; // x0

  if ( a1 )
  {
    v11 = a3;
    qdf_trace_msg(0x34u, 8u, "%s: Set HE bss_color  %d", a4, a5, a6, a7, a8, a9, a10, a11, "sme_set_he_bss_color", a3);
    if ( v11 - 64 > 0xFFFFFFC0 )
    {
      v22 = _qdf_mem_malloc(6u, "sme_set_he_bss_color", 13449);
      if ( v22 )
      {
        *(_BYTE *)(v22 + 4) = a2;
        *(_BYTE *)(v22 + 5) = v11;
        *(_DWORD *)v22 = 398477;
        return umac_send_mb_message_to_mac(v22);
      }
      else
      {
        return 2;
      }
    }
    else
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Invalid HE bss_color  %d",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "sme_set_he_bss_color",
        v11);
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: Invalid mac_handle pointer", a4, a5, a6, a7, a8, a9, a10, a11, "sme_set_he_bss_color");
    return 5;
  }
}
