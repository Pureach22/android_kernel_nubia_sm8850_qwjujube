__int64 __fastcall qcom_adc5_gen3_scale_hw_calib_batt_id_100(__int64 a1, __int64 a2, unsigned __int16 a3, _DWORD *a4)
{
  if ( *(_DWORD *)(a2 + 16) <= (unsigned int)a3 )
    return 4294967274LL;
  *a4 = 100000LL * a3 / (__int64)((unsigned __int16)*(_DWORD *)(a2 + 16) - (unsigned __int64)a3);
  return 0;
}
