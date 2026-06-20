__int64 __fastcall qcom_llcc_event_init(__int64 a1)
{
  if ( *(_QWORD *)(a1 + 224) != 4096 )
    return 4294967294LL;
  *(_QWORD *)(a1 + 376) = 4096;
  return 0;
}
