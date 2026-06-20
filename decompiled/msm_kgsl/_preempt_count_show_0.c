__int64 __fastcall preempt_count_show_0(__int64 a1)
{
  __int64 v2; // x20
  __int64 (__fastcall *v3)(_QWORD); // x8
  unsigned int v4; // w20

  v2 = *(_QWORD *)(a1 + 22784);
  rt_mutex_lock(a1 + 11088);
  v3 = *(__int64 (__fastcall **)(_QWORD))(v2 + 8);
  if ( *((_DWORD *)v3 - 1) != 556668243 )
    __break(0x8228u);
  v4 = v3(a1);
  rt_mutex_unlock(a1 + 11088);
  return v4;
}
