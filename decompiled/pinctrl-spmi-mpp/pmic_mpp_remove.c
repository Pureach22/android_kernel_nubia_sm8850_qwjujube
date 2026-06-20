__int64 __fastcall pmic_mpp_remove(__int64 a1)
{
  return gpiochip_remove(*(_QWORD *)(a1 + 168) + 24LL);
}
