__int64 __fastcall _qdf_hrtimer_cb_3(__int64 a1)
{
  __int64 v1; // x0
  __int64 (__fastcall *v2)(_QWORD); // x8
  __int64 v3; // t2

  v3 = a1 + 72;
  v1 = *(_QWORD *)(a1 + 72);
  v2 = *(__int64 (__fastcall **)(_QWORD))(v3 + 8);
  if ( *((_DWORD *)v2 - 1) != 1889326148 )
    __break(0x8228u);
  return v2(v1);
}
