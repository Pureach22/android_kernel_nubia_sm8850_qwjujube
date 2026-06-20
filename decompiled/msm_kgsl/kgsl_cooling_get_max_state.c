__int64 __fastcall kgsl_cooling_get_max_state(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 944);
  *a2 = (unsigned int)(*(_DWORD *)(v2 + 10068) - 1);
  return 0;
}
