__int64 __fastcall bcl_throttle_time_us_get(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8
  void (*v5)(void); // x9
  __int64 v6; // x8

  v2 = *(_QWORD *)(a1 + 14264);
  v5 = *(void (**)(void))(*(_QWORD *)(v2 + 40) + 296LL);
  if ( v5 )
  {
    if ( *((_DWORD *)v5 - 1) != 994519391 )
      __break(0x8229u);
    v5();
    v2 = *(_QWORD *)(a1 + 14264);
  }
  if ( (*(_BYTE *)(v2 + 33) & 0x10) != 0 )
    v6 = *(unsigned int *)(a1 + 24008);
  else
    v6 = 0;
  *a2 = v6;
  return 0;
}
