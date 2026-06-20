__int64 __fastcall wsa884x_get_visense(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 128);
  *(_QWORD *)(a2 + 72) = *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(v2 + 24) + 152LL) + 33LL);
  return 0;
}
