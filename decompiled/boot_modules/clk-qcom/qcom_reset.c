__int64 __fastcall qcom_reset(__int64 a1, __int64 a2)
{
  void (*v4)(void); // x8
  __int64 v5; // x0
  void (__fastcall *v6)(__int64, __int64); // x8

  v4 = *(void (**)(void))(*(_QWORD *)a1 + 8LL);
  if ( *((_DWORD *)v4 - 1) != -626910737 )
    __break(0x8228u);
  v4();
  if ( *(_WORD *)(*(_QWORD *)(a1 - 16) + 12 * a2 + 6) )
    v5 = *(unsigned __int16 *)(*(_QWORD *)(a1 - 16) + 12 * a2 + 6);
  else
    v5 = 4;
  if ( (unsigned int)v5 > 0xA )
  {
    if ( (unsigned int)v5 > 0x4E20 )
      msleep((4294968 * (unsigned __int64)(unsigned int)(v5 + 999)) >> 32);
    else
      usleep_range_state(v5, 2 * v5, 2);
  }
  else
  {
    _udelay();
  }
  v6 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)a1 + 16LL);
  if ( *((_DWORD *)v6 - 1) != -626910737 )
    __break(0x8228u);
  v6(a1, a2);
  return 0;
}
