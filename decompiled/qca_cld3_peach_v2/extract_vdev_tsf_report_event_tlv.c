__int64 __fastcall extract_vdev_tsf_report_event_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        __int64 a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  __int64 v13; // x8

  if ( a10 )
  {
    v13 = *a10;
    *(_DWORD *)a11 = *(_DWORD *)(*a10 + 4);
    *(_QWORD *)(a11 + 8) = *(_QWORD *)(v13 + 8);
    *(_DWORD *)(a11 + 16) = *(_DWORD *)(v13 + 8);
    *(_DWORD *)(a11 + 20) = *(_DWORD *)(v13 + 12);
    *(_DWORD *)(a11 + 24) = *(_DWORD *)(v13 + 16);
    *(_DWORD *)(a11 + 28) = *(_DWORD *)(v13 + 20);
    *(_DWORD *)(a11 + 32) = *(_DWORD *)(v13 + 24);
    *(_DWORD *)(a11 + 36) = *(_DWORD *)(v13 + 28);
    *(_DWORD *)(a11 + 40) = *(_DWORD *)(v13 + 32);
    *(_DWORD *)(a11 + 44) = *(_DWORD *)(v13 + 36);
    *(_DWORD *)(a11 + 48) = *(_DWORD *)(v13 + 40);
    *(_DWORD *)(a11 + 52) = *(_DWORD *)(v13 + 44);
    *(_DWORD *)(a11 + 56) = *(_DWORD *)(v13 + 48);
    *(_DWORD *)(a11 + 60) = *(_DWORD *)(v13 + 52);
    *(_DWORD *)(a11 + 64) = *(_DWORD *)(v13 + 56);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid tsf report event buffer",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_vdev_tsf_report_event_tlv",
      v11,
      v12);
    return 4;
  }
}
