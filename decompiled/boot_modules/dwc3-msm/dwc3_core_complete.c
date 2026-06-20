__int64 __fastcall dwc3_core_complete(__int64 a1)
{
  __int64 v1; // x19
  __int64 result; // x0

  v1 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 368LL) + 96LL) + 152LL);
  result = dwc3_dbg_print(
             *(_QWORD *)(v1 + 1256),
             0xFFu,
             "Core PM complete",
             (*(unsigned __int16 *)(a1 + 268) >> 9) & 1,
             (const char *)&unk_16A05);
  if ( (*(_BYTE *)(v1 + 736) & 1) == 0 )
  {
    dwc3_dbg_print(*(_QWORD *)(v1 + 1256), 0xFFu, "Queue ResWrk", 0, (const char *)&unk_16A05);
    return queue_work_on(32, *(_QWORD *)(v1 + 640), v1 + 568);
  }
  return result;
}
