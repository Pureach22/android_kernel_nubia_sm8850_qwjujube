__int64 __fastcall hdd_get_pmkid_modes(__int64 *a1, unsigned int *a2)
{
  __int64 v3; // x0
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  int v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  v13 = 0;
  result = ucfg_mlme_get_pmkid_modes(v3, &v13);
  if ( (_DWORD)result )
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: get pmkid modes fail",
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "hdd_get_pmkid_modes");
  *a2 = *a2 & 0xFFFFFFFC | v13 & 3;
  _ReadStatusReg(SP_EL0);
  return result;
}
