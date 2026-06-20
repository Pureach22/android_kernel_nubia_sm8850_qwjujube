__int64 __fastcall wcd9378_mbhc_program_btn_thr(__int64 result, __int64 a2, __int16 *a3, int a4)
{
  __int64 v5; // x19
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x8

  v5 = result;
  if ( a4 > 8 )
    return dev_err(*(_QWORD *)(result + 24), "%s: invalid number of buttons: %d\n", "wcd9378_mbhc_program_btn_thr", a4);
  if ( a4 > 0 )
  {
    result = snd_soc_component_update_bits(
               result,
               1075314714,
               252,
               4
             * (((unsigned __int8)((unsigned __int64)(2748779070LL * *a3) >> 35) + (2748779070LL * *a3 < 0)) & 0x3Fu));
    if ( a4 != 1 )
    {
      v7 = 2748779070LL * a3[1];
      result = snd_soc_component_update_bits(
                 v5,
                 1075314715,
                 252,
                 4 * (((unsigned __int8)((unsigned __int64)v7 >> 35) + (v7 < 0)) & 0x3Fu));
      if ( a4 != 2 )
      {
        v8 = 2748779070LL * a3[2];
        result = snd_soc_component_update_bits(
                   v5,
                   1075314716,
                   252,
                   4 * (((unsigned __int8)((unsigned __int64)v8 >> 35) + (v8 < 0)) & 0x3Fu));
        if ( a4 != 3 )
        {
          v9 = 2748779070LL * a3[3];
          result = snd_soc_component_update_bits(
                     v5,
                     1075314717,
                     252,
                     4 * (((unsigned __int8)((unsigned __int64)v9 >> 35) + (v9 < 0)) & 0x3Fu));
          if ( a4 != 4 )
          {
            v10 = 2748779070LL * a3[4];
            result = snd_soc_component_update_bits(
                       v5,
                       1075314718,
                       252,
                       4 * (((unsigned __int8)((unsigned __int64)v10 >> 35) + (v10 < 0)) & 0x3Fu));
            if ( a4 != 5 )
            {
              v11 = 2748779070LL * a3[5];
              result = snd_soc_component_update_bits(
                         v5,
                         1075314719,
                         252,
                         4 * (((unsigned __int8)((unsigned __int64)v11 >> 35) + (v11 < 0)) & 0x3Fu));
              if ( a4 != 6 )
              {
                v12 = 2748779070LL * a3[6];
                result = snd_soc_component_update_bits(
                           v5,
                           1075314720,
                           252,
                           4 * (((unsigned __int8)((unsigned __int64)v12 >> 35) + (v12 < 0)) & 0x3Fu));
                if ( a4 != 7 )
                {
                  v13 = 2748779070LL * a3[7];
                  return snd_soc_component_update_bits(
                           v5,
                           1075314721,
                           252,
                           4 * (((unsigned __int8)((unsigned __int64)v13 >> 35) + (v13 < 0)) & 0x3Fu));
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}
