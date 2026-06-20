unsigned __int64 __fastcall msm_vidc_print_stats(__int64 a1)
{
  unsigned __int64 result; // x0
  unsigned __int64 v3; // x20
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x10

  result = ktime_get(a1);
  v3 = result / 0xF4240;
  if ( a1 && (msm_vidc_debug & 0x42) != 0 )
    result = printk(
               &unk_81290,
               "stat",
               a1 + 340,
               (unsigned int)*(_QWORD *)(a1 + 4232) - *(_DWORD *)(a1 + 4264),
               (unsigned int)*(_QWORD *)(a1 + 4256) - *(_DWORD *)(a1 + 4288));
  v4 = *(_QWORD *)(a1 + 4232);
  v5 = *(_QWORD *)(a1 + 4240);
  *(_QWORD *)(a1 + 4296) = 0;
  *(_QWORD *)(a1 + 4312) = 0;
  *(_QWORD *)(a1 + 4264) = v4;
  *(_QWORD *)(a1 + 4272) = v5;
  v6 = *(_QWORD *)(a1 + 4256);
  *(_QWORD *)(a1 + 4280) = *(_QWORD *)(a1 + 4248);
  *(_QWORD *)(a1 + 4288) = v6;
  *(_QWORD *)(a1 + 4304) = v3;
  return result;
}
