__int64 __fastcall qcom_ddump_suspend(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 152);
  if ( *(_BYTE *)(v1 + 337) == 1 )
    pvm_update_record_time(*(__int64 **)(v1 + 344), *(_QWORD *)(v1 + 152) + 16LL);
  return 0;
}
