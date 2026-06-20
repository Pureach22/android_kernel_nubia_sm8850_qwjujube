__int64 __fastcall qcom_wdt_hibernation_notifier(__int64 a1, __int64 a2)
{
  char v2; // w8

  if ( a2 == 1 )
  {
    v2 = 1;
    goto LABEL_5;
  }
  if ( a2 == 2 )
  {
    v2 = 0;
LABEL_5:
    *(_BYTE *)(wdog_data + 1000) = v2;
  }
  return 1;
}
