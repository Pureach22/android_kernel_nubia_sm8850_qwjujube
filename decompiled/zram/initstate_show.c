__int64 __fastcall initstate_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x21
  _BOOL4 v5; // w20

  v4 = *(_QWORD *)(*(_QWORD *)(a1 - 224) + 88LL);
  down_read(v4 + 32);
  v5 = *(_QWORD *)(v4 + 216) != 0;
  up_read(v4 + 32);
  return (int)scnprintf(a3, 4096, "%u\n", v5);
}
