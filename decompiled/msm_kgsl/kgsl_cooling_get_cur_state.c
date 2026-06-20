__int64 __fastcall kgsl_cooling_get_cur_state(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 944);
  *a2 = *(unsigned int *)(v2 + 10048);
  return 0;
}
