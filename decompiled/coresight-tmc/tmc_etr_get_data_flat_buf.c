__int64 __fastcall tmc_etr_get_data_flat_buf(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 v4; // x8

  v4 = *(_QWORD *)(a1 + 56);
  *a4 = *(_QWORD *)(v4 + 16) + a2;
  return a3;
}
