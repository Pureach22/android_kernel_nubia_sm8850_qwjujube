__int64 __fastcall qmp_mbox_freeze(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 152);
  *(_BYTE *)(v1 + 153) = 1;
  return 0;
}
