__int64 __fastcall dwc3_core_prepare(__int64 a1)
{
  __int64 v1; // x20
  int v3; // w3

  v1 = *(_QWORD *)(a1 + 152);
  v3 = *(_DWORD *)(a1 + 500) == 2 && (*(_WORD *)(a1 + 488) & 7) == 0;
  dwc3_dbg_print(
    *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 368) + 96LL) + 152LL) + 1256LL),
    0xFFu,
    "Core PM prepare",
    v3,
    (const char *)&unk_16A05);
  if ( (*(_WORD *)(a1 + 488) & 7) == 0 && *(_DWORD *)(a1 + 500) == 2 )
    return 1;
  if ( *(_DWORD *)(v1 + 1124) != 2 || (*(_WORD *)(a1 + 488) & 7) == 0 && *(_DWORD *)(a1 + 500) == 2 )
    return 0;
  dev_info(a1, "%s: peripheral mode still active\n", "dwc3_core_prepare");
  return 4294967280LL;
}
