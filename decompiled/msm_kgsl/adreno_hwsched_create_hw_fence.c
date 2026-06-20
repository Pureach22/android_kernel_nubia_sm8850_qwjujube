__int64 __fastcall adreno_hwsched_create_hw_fence(__int64 result, __int64 a2)
{
  __int64 v2; // x9
  __int64 (*v3)(void); // x8

  v2 = *(_QWORD *)(*(_QWORD *)(a2 + 72) + 80LL);
  if ( (*(_QWORD *)(result + 22496) & 0x10) != 0
    && v2
    && (*(_QWORD *)(v2 + 32) & 2) == 0
    && (*(_QWORD *)(v2 + 32) & 4) == 0 )
  {
    v3 = *(__int64 (**)(void))(*(_QWORD *)(result + 22784) + 24LL);
    if ( *((_DWORD *)v3 - 1) != -353547434 )
      __break(0x8228u);
    return v3();
  }
  return result;
}
