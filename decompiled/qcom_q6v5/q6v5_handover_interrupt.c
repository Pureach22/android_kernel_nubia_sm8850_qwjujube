__int64 __fastcall q6v5_handover_interrupt(__int64 a1, __int64 a2)
{
  void (__fastcall *v2)(_QWORD); // x8

  v2 = *(void (__fastcall **)(_QWORD))(a2 + 296);
  if ( v2 )
  {
    if ( *((_DWORD *)v2 - 1) != 686387440 )
      __break(0x8228u);
    v2(a2);
  }
  if ( *(_BYTE *)(a2 + 320) == 1 && (completion_done(a2 + 208) & 1) == 0 )
    complete(a2 + 208);
  icc_set_bw(*(_QWORD *)(a2 + 40), 0, 0);
  *(_BYTE *)(a2 + 136) = 1;
  return 1;
}
