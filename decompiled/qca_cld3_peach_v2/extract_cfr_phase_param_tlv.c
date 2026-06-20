__int64 __fastcall extract_cfr_phase_param_tlv(
        __int64 a1,
        __int64 *a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x19
  __int64 (*v13)(void); // x8

  if ( a2 )
  {
    v11 = *a2;
    if ( *a2 )
    {
      a3[1] = *(_DWORD *)(v11 + 8);
      v13 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 3688LL);
      if ( *((_DWORD *)v13 - 1) != -2112860426 )
        __break(0x8228u);
      *a3 = v13();
      a3[2] = *(unsigned __int16 *)(v11 + 12);
      a3[3] = *(unsigned __int16 *)(v11 + 14);
      qdf_mem_copy(a3 + 66, (const void *)(v11 + 264), 8u);
      qdf_mem_copy(a3 + 4, (const void *)(v11 + 16), 0xF8u);
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: CFR phase AoA delta buffer is NULL",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "extract_cfr_phase_param_tlv");
      return 29;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid cfr aoa phase delta buffer",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "extract_cfr_phase_param_tlv");
    return 4;
  }
}
