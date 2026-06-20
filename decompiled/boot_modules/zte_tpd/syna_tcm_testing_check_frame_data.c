__int64 __fastcall syna_tcm_testing_check_frame_data(
        __int64 a1,
        unsigned __int64 a2,
        __int64 a3,
        int a4,
        _DWORD *a5,
        __int64 a6,
        unsigned __int64 a7)
{
  int v12; // w9
  unsigned int v13; // w26
  int v14; // w28
  __int64 v15; // x27
  int v16; // w24
  __int64 v17; // x2
  __int64 v18; // x9
  int v20; // [xsp+4h] [xbp-Ch]
  int v22; // [xsp+Ch] [xbp-4h]

  if ( a5 && a1 && a6 )
  {
    if ( (unsigned int)(2 * a3 * a4) > a2 )
    {
      printk(&unk_39575, "syna_tcm_testing_check_frame_data", (unsigned int)a2);
      LOBYTE(v14) = 0;
    }
    else if ( (int)a3 < 1 )
    {
      LOBYTE(v14) = 1;
    }
    else
    {
      v12 = 0;
      v13 = 0;
      v14 = 1;
      v20 = a3;
      do
      {
        v22 = v12;
        if ( a4 >= 1 )
        {
          v15 = 0;
          v16 = v12;
          do
          {
            v17 = (unsigned int)v15;
            if ( a7 >= a2 )
              v18 = v16;
            else
              v18 = 0;
            if ( *(a5 - 1) != -1556969998 )
              __break(0x8236u);
            ++v15;
            v14 &= ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))a5)(a1 + v16, a6 + v18, v17, v13);
            v16 += 2;
          }
          while ( a4 != v15 );
        }
        ++v13;
        v12 = v22 + 2 * a4;
      }
      while ( v13 != v20 );
    }
  }
  else
  {
    printk(&unk_3380A, "syna_tcm_testing_check_frame_data", a3);
    LOBYTE(v14) = 0;
  }
  return v14 & 1;
}
