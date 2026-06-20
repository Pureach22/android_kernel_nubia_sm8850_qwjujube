__int64 __fastcall syna_tcm_testing_0002_check_config_id(__int64 a1, __int64 a2, int a3)
{
  int v3; // w8

  if ( a1 && a2 )
  {
    if ( a3 < 0 )
      return 1;
    v3 = 0;
    while ( *(unsigned __int8 *)(a1 + v3) == *(unsigned __int8 *)(a2 + v3) )
    {
      if ( ++v3 > a3 )
        return 1;
    }
    printk(&unk_39A68, "syna_tcm_testing_0002_check_config_id", a1);
  }
  return 0;
}
