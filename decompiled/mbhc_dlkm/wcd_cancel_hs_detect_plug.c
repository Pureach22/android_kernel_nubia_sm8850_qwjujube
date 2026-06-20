__int64 __fastcall wcd_cancel_hs_detect_plug(__int64 a1, __int64 a2)
{
  _DWORD *v4; // x8

  *(_BYTE *)(a1 + 206) = 1;
  mutex_unlock(a1 + 744);
  if ( (cancel_work_sync(a2) & 1) != 0 )
  {
    v4 = *(_DWORD **)(*(_QWORD *)(a1 + 120) + 144LL);
    if ( *(v4 - 1) != 1996337026 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v4)(a1, 0);
  }
  return mutex_lock(a1 + 744);
}
