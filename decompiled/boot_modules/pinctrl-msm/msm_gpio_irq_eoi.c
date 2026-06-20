__int64 __fastcall msm_gpio_irq_eoi(__int64 a1)
{
  __int64 result; // x0
  __int64 (*v2)(void); // x8

  result = *(_QWORD *)(a1 + 40);
  if ( result )
  {
    v2 = *(__int64 (**)(void))(*(_QWORD *)(result + 24) + 72LL);
    if ( *((_DWORD *)v2 - 1) != 270158662 )
      __break(0x8228u);
    return v2();
  }
  return result;
}
