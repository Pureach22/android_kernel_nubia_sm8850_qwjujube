__int64 __fastcall soc_reset_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  mhi_soc_reset(*(_QWORD *)(a1 - 24));
  return a4;
}
