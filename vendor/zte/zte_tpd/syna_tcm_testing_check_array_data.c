__int64 __fastcall syna_tcm_testing_check_array_data(__int64 a1, unsigned __int64 a2, __int64 a3, unsigned __int64 a4)
{
  __int64 v8; // x23
  __int64 v9; // x25
  int v10; // w24
  __int64 v11; // x0
  __int64 v12; // x2
  __int64 v13; // x8

  if ( a1 && a3 )
  {
    if ( (int)a2 < 1 )
    {
      LOBYTE(v10) = 1;
    }
    else
    {
      v8 = 0;
      v9 = a2 & 0x7FFFFFFF;
      v10 = 1;
      do
      {
        v11 = a1 + v8;
        v12 = (unsigned int)v8;
        if ( a4 >= a2 )
          v13 = v8;
        else
          v13 = 0;
        ++v8;
        v10 &= syna_tcm_testing_0100_check_data(v11, a3 + v13, v12);
      }
      while ( v9 != v8 );
    }
  }
  else
  {
    printk(unk_3380A, "syna_tcm_testing_check_array_data", a3);
    LOBYTE(v10) = 0;
  }
  return v10 & 1;
}
