__int64 __fastcall spi_slv_abort(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 152);
  complete_all(v1 + 384);
  complete_all(v1 + 416);
  return 0;
}
