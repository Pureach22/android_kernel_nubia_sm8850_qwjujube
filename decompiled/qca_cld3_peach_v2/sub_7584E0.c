__int64 __fastcall sub_7584E0(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, double a6)
{
  __int64 v6; // x10
  __int64 v7; // d23

  *(double *)v6 = a6;
  *(_QWORD *)(v6 + 8) = v7;
  return wlan_dp_spm_get_flow_id_origin(a1, a2, a3, a4, a5);
}
