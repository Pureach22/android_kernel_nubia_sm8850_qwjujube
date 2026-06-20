__int64 __fastcall hdd_wmm_is_acm_allowed(
        unsigned __int8 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  __int64 v20; // x8

  result = (__int64)_cds_get_context(51, (__int64)"hdd_wmm_is_acm_allowed", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    result = hdd_get_link_info_by_vdev(result, a1);
    if ( result )
    {
      v19 = result;
      result = !(unsigned int)_hdd_validate_adapter(
                                *(_QWORD *)result,
                                (__int64)"hdd_wmm_is_acm_allowed",
                                v11,
                                v12,
                                v13,
                                v14,
                                v15,
                                v16,
                                v17,
                                v18)
            && ((v20 = *(_QWORD *)v19, *(_BYTE *)(*(_QWORD *)v19 + 3001LL) != 1)
             || *(_BYTE *)(v20 + 3000) != 1
             || *(_BYTE *)(v20 + 2445) == 1);
    }
  }
  return result;
}
