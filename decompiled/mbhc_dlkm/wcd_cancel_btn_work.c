__int64 __fastcall wcd_cancel_btn_work(__int64 a1)
{
  char v2; // w20
  _DWORD *v3; // x8

  v2 = cancel_delayed_work_sync();
  if ( (v2 & 1) != 0 )
  {
    v3 = *(_DWORD **)(*(_QWORD *)(a1 + 120) + 144LL);
    if ( *(v3 - 1) != 1996337026 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v3)(a1, 0);
  }
  return v2 & 1;
}
