bool __fastcall syna_tcm_testing_0100_check_data(unsigned __int8 *a1, unsigned __int8 *a2, int a3)
{
  unsigned int v3; // w21
  unsigned int v4; // w8
  unsigned int v5; // w19
  _BOOL8 result; // x0

  v3 = *a1;
  v4 = *a2;
  v5 = 8 * a3;
  result = (v3 & 1) == (v4 & 1);
  if ( (v3 & 1) != (v4 & 1) )
  {
    printk(&unk_3B2DF, "syna_tcm_testing_0100_check_data", v5);
    v4 = *a2;
    result = 0;
  }
  if ( ((v3 >> 1) & 1) != ((v4 >> 1) & 1) )
  {
    printk(&unk_3B2DF, "syna_tcm_testing_0100_check_data", v5 | 1);
    v4 = *a2;
    result = 0;
  }
  if ( ((v3 >> 2) & 1) != ((v4 >> 2) & 1) )
  {
    printk(&unk_3B2DF, "syna_tcm_testing_0100_check_data", v5 | 2);
    v4 = *a2;
    result = 0;
  }
  if ( ((v3 >> 3) & 1) != ((v4 >> 3) & 1) )
  {
    printk(&unk_3B2DF, "syna_tcm_testing_0100_check_data", v5 | 3);
    v4 = *a2;
    result = 0;
  }
  if ( ((v3 >> 4) & 1) != ((v4 >> 4) & 1) )
  {
    printk(&unk_3B2DF, "syna_tcm_testing_0100_check_data", v5 | 4);
    v4 = *a2;
    result = 0;
  }
  if ( ((v3 >> 5) & 1) != ((v4 >> 5) & 1) )
  {
    printk(&unk_3B2DF, "syna_tcm_testing_0100_check_data", v5 | 5);
    v4 = *a2;
    result = 0;
  }
  if ( ((v3 >> 6) & 1) != ((v4 >> 6) & 1) )
  {
    printk(&unk_3B2DF, "syna_tcm_testing_0100_check_data", v5 | 6);
    v4 = *a2;
    result = 0;
  }
  if ( v3 >> 7 != v4 >> 7 )
  {
    printk(&unk_3B2DF, "syna_tcm_testing_0100_check_data", v5 | 7);
    return 0;
  }
  return result;
}
