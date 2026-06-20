bool __fastcall syna_tcm_testing_0500_check_lower_bound(
        unsigned __int16 *a1,
        unsigned __int16 *a2,
        __int64 a3,
        unsigned int a4)
{
  unsigned int v4; // w19
  unsigned int v5; // w20

  v4 = *a1;
  v5 = *a2;
  if ( v4 < v5 )
    printk(&unk_34372, "syna_tcm_testing_0500_check_lower_bound", a4);
  return v4 >= v5;
}
