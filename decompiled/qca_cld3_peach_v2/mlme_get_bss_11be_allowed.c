__int64 __fastcall mlme_get_bss_11be_allowed(__int64 a1, unsigned __int8 *a2, __int64 a3, int a4)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 result; // x0
  __int64 v17; // x4
  __int64 v18; // x5
  __int64 v19; // x6
  __int64 v20; // x7
  __int64 v21; // [xsp+8h] [xbp-28h] BYREF
  __int64 v22; // [xsp+10h] [xbp-20h]
  __int64 v23; // [xsp+18h] [xbp-18h]
  __int64 v24; // [xsp+20h] [xbp-10h]
  __int64 v25; // [xsp+28h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  if ( (wlan_action_oui_is_empty(a1, 9) & 1) != 0
    || (qdf_mem_set(&v21, 0x20u, 0), v21 = a3, LODWORD(v22) = a4, (wlan_action_oui_search(a1, &v21, 9) & 1) != 0) )
  {
    result = 1;
  }
  else
  {
    if ( a2 )
    {
      v17 = *a2;
      v18 = a2[1];
      v19 = a2[2];
      v20 = a2[5];
    }
    else
    {
      v19 = 0;
      v17 = 0;
      v18 = 0;
      v20 = 0;
    }
    qdf_trace_msg(
      0x1Fu,
      8u,
      "%s: AP not in 11be oui allow list %02x:%02x:%02x:**:**:%02x",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "mlme_get_bss_11be_allowed",
      v17,
      v18,
      v19,
      v20);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
