__int64 __fastcall compact_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20

  v5 = *(_QWORD *)(*(_QWORD *)(a1 - 224) + 88LL);
  down_read(v5 + 32);
  if ( *(_QWORD *)(v5 + 216) )
    zs_compact(*(_QWORD *)(v5 + 8));
  else
    a4 = -22;
  up_read(v5 + 32);
  return a4;
}
