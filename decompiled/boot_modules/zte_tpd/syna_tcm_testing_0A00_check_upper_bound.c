bool __fastcall syna_tcm_testing_0A00_check_upper_bound(__int16 *a1, __int16 *a2, __int64 a3, unsigned int a4)
{
  int v4; // w19
  int v5; // w20

  v4 = *a1;
  v5 = *a2;
  if ( v4 > v5 )
    printk(&unk_3C643, "syna_tcm_testing_0A00_check_upper_bound", a4);
  return v4 <= v5;
}
