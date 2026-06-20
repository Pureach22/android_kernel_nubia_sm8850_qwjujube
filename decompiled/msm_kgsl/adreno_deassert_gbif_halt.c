__int64 __fastcall adreno_deassert_gbif_halt(__int64 result)
{
  __int64 (*v1)(void); // x8

  v1 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(result + 14264) + 40LL) + 176LL);
  if ( v1 )
  {
    if ( *((_DWORD *)v1 - 1) != 994519391 )
      __break(0x8228u);
    return v1();
  }
  return result;
}
