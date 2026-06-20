__int64 __fastcall sub_1DA89C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned __int16 *v6; // x14
  __int64 v7; // x6

  v7 = __ldaxr(v6);
  return dsi_connector_put_modes(a1, a2, a3, a4, a5, a6, v7);
}
