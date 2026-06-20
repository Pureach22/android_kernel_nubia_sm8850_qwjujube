__int64 __fastcall restart_wdog_handler(__int64 a1, __int64 a2)
{
  if ( *(_BYTE *)(a1 - 147) == 1 )
  {
    printk(&unk_7E2E, a2);
    qcom_wdt_trigger_bite();
  }
  return 0;
}
