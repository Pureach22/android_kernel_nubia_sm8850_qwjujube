__int64 __fastcall pmic_mpp_dbg_show(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v5; // x21
  unsigned int v6; // w22

  result = gpiochip_get_data(a2);
  if ( *(_WORD *)(a2 + 172) )
  {
    v5 = result;
    v6 = 0;
    do
    {
      pmic_mpp_config_dbg_show(*(_QWORD *)(v5 + 16), a1, v6);
      result = seq_putc(a1, 10);
      ++v6;
    }
    while ( v6 < *(unsigned __int16 *)(a2 + 172) );
  }
  return result;
}
