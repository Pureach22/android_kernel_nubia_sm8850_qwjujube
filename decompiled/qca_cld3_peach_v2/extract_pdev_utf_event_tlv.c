__int64 __fastcall extract_pdev_utf_event_tlv(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v11; // w8
  __int64 v15; // x8
  __int64 v16; // x1
  __int64 (__fastcall *v17)(__int64, __int64); // x9

  *(_QWORD *)a3 = *(_QWORD *)a2;
  v11 = *(_DWORD *)(a2 + 8);
  *(_WORD *)(a3 + 8) = v11;
  if ( (v11 & 0xFFF0) != 0 )
  {
    if ( (is_service_enabled_tlv(a1, 0x18Au, a4, a5, a6, a7, a8, a9, a10, a11) & 1) != 0
      && (v15 = *(_QWORD *)(a2 + 16)) != 0
      && *(_DWORD *)(a2 + 24) )
    {
      v16 = *(unsigned int *)(v15 + 4);
      v17 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3688LL);
    }
    else
    {
      v17 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 728) + 3688LL);
      v16 = *(unsigned int *)(*(_QWORD *)a2 + 12LL);
    }
    if ( *((_DWORD *)v17 - 1) != -2112860426 )
      __break(0x8229u);
    *(_DWORD *)(a3 + 12) = v17(a1, v16);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid datalen: %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "extract_pdev_utf_event_tlv",
      v11 & 0xF);
    return 4;
  }
}
