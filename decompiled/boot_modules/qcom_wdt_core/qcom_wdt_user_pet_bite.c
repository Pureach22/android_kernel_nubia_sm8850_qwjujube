void __fastcall qcom_wdt_user_pet_bite(__int64 a1)
{
  if ( (*(_BYTE *)(a1 - 671) & 1) == 0 )
  {
    dev_info(*(_QWORD *)(a1 - 952), "QCOM Apps Watchdog user pet timeout!\n");
    qcom_wdt_trigger_bite();
  }
}
