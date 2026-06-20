__int64 __fastcall wsa883x_get_mute(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 128);
  *(_QWORD *)(a2 + 72) = *(int *)(*(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL) + 184LL);
  return 0;
}
