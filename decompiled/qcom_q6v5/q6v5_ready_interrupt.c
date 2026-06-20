__int64 __fastcall q6v5_ready_interrupt(__int64 a1, __int64 a2)
{
  complete(a2 + 144);
  if ( *(_BYTE *)(a2 + 320) == 1 && (completion_done(a2 + 208) & 1) == 0 )
    complete(a2 + 208);
  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 8) + 1204LL) & 1) == 0 )
    _pm_relax(*(_QWORD *)(a2 + 336));
  return 1;
}
