__int64 __fastcall qcom_adc5_gen4_scale_hw_calib_batt_id_10(__int64 a1, __int64 a2, unsigned __int16 a3, int *a4)
{
  if ( *(_DWORD *)(a2 + 16) <= (unsigned int)a3 )
    return 4294967274LL;
  *a4 = 10000 * a3 / ((unsigned __int16)*(_DWORD *)(a2 + 16) - a3);
  return 0;
}
