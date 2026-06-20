__int64 __fastcall prct_mode_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v5; // x23
  unsigned int v6; // w20
  unsigned int v7; // w21
  _DWORD *v8; // x8
  __int64 v10; // [xsp+0h] [xbp-10h] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v10 = 0;
  if ( sscanf(s, "%x %x", &v10, (char *)&v10 + 4) == 2 )
  {
    v6 = v10;
    v7 = HIDWORD(v10);
    mutex_lock(v5 + 584);
    v8 = *(_DWORD **)(*(_QWORD *)(v5 + 1312) + 216LL);
    if ( *(v8 - 1) != 2072477285 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, _QWORD))v8)(v5 - 168, v6, v7);
    mutex_unlock(v5 + 584);
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
