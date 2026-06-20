__int64 __fastcall cm_adjust_partner_links_based_on_oui(__int64 a1, __int64 a2, unsigned __int8 *a3, __int64 a4)
{
  __int64 v7; // x8
  int v8; // w9
  __int64 result; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // [xsp+28h] [xbp-28h] BYREF
  int v19; // [xsp+30h] [xbp-20h]
  int v20; // [xsp+34h] [xbp-1Ch]
  __int64 v21; // [xsp+38h] [xbp-18h]
  __int64 v22; // [xsp+40h] [xbp-10h]
  __int64 v23; // [xsp+48h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a2 + 1896);
  v8 = *(_DWORD *)(a2 + 1888);
  v21 = 0;
  v22 = 0;
  v18 = v7 + 36;
  v20 = 0;
  v19 = (unsigned __int16)(v8 - 36);
  result = wlan_action_oui_search(a1, &v18, 16);
  if ( (result & 1) != 0 )
  {
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: vdev %d cm_id 0x%x: Downgrade %02x:%02x:%02x:**:**:%02x partner links from %d to %d",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "cm_adjust_partner_links_based_on_oui",
      *(unsigned __int8 *)(a4 + 32),
      *(unsigned int *)(a4 + 16),
      *(unsigned __int8 *)(a2 + 1912),
      *(unsigned __int8 *)(a2 + 1913),
      *(unsigned __int8 *)(a2 + 1914),
      *(unsigned __int8 *)(a2 + 1917),
      *a3,
      1);
    result = (__int64)qdf_mem_set(a3 + 56, 48 * (unsigned int)*a3 - 48, 0);
    *a3 = 1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
