__int64 __fastcall wifi_pos_send_report_resp(__int64 a1, unsigned __int16 a2, int *a3, unsigned __int8 a4)
{
  __int64 psoc; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int *psoc_priv_obj; // x0
  int v18; // w11
  __int16 v19; // w8
  void (__fastcall *v20)(__int64, __int64, __int64, __int64, __int64 *); // x8
  __int64 v21; // x1
  __int64 result; // x0
  __int64 v23; // [xsp+Ch] [xbp-34h] BYREF
  int v24; // [xsp+14h] [xbp-2Ch]
  __int64 v25; // [xsp+18h] [xbp-28h]
  __int64 v26; // [xsp+20h] [xbp-20h]
  __int64 v27; // [xsp+28h] [xbp-18h]
  __int64 v28; // [xsp+30h] [xbp-10h]
  __int64 v29; // [xsp+38h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  psoc = wifi_pos_get_psoc(a1);
  if ( psoc && (psoc_priv_obj = (unsigned int *)wifi_pos_get_psoc_priv_obj(psoc)) != nullptr )
  {
    v18 = *a3;
    v23 = 0x500210018LL;
    v19 = *((_WORD *)a3 + 2);
    v26 = 0x290014FFFFFFFFLL;
    HIDWORD(v27) = v18;
    v24 = a2 | (a4 << 16) | 0x1000000;
    LOWORD(v28) = v19;
    v20 = *((void (__fastcall **)(__int64, __int64, __int64, __int64, __int64 *))psoc_priv_obj + 16);
    v21 = *psoc_priv_obj;
    if ( *((_DWORD *)v20 - 1) != 1562231049 )
      __break(0x8228u);
    v20(a1, v21, 5, 44, &v23);
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x25u,
      2u,
      "%s: wifi_pos priv obj is null",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "wifi_pos_send_report_resp");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
