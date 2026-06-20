_WORD *__fastcall ieee80211_tdls_ch_sw_resp_tmpl_get(__int64 a1, _DWORD *a2)
{
  unsigned int v3; // w8
  __int64 v4; // x20
  char v5; // w9
  _WORD *result; // x0
  _WORD *v7; // x20
  __int64 v8; // x10
  __int64 v9; // x1
  __int64 elem_match; // x0
  int v11; // w8
  __int16 v12; // [xsp+20h] [xbp-10h] BYREF
  int v13; // [xsp+22h] [xbp-Eh]
  __int64 v14; // [xsp+28h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(unsigned __int16 *)(a1 + 2872);
  v4 = *(_QWORD *)(a1 + 80);
  v12 = 1128;
  v5 = *(_BYTE *)(a1 + 2713);
  v13 = 0;
  result = ieee80211_tdls_build_mgmt_packet_data(
             v4,
             (_WORD *)(a1 + 2688),
             __clz(__rbit32(v3)) & 0x1F,
             6u,
             0,
             0,
             (v5 & 1) == 0,
             (char *)&v12,
             6,
             0,
             0);
  if ( result )
  {
    result = (_WORD *)ieee80211_build_data_template(v4, result, 0);
    if ( (unsigned __int64)result <= 0xFFFFFFFFFFFFF000LL )
    {
      if ( !a2 )
        goto LABEL_7;
      v7 = result;
      v8 = *((_QWORD *)result + 28);
      v9 = v8 + *((_DWORD *)result + 54) + (unsigned __int16)result[92] - (int)v8 + 5;
      elem_match = cfg80211_find_elem_match(104, v9, (unsigned int)(*((_DWORD *)result + 28) + v8 - v9), 0, 0, 0);
      if ( elem_match )
      {
        v11 = elem_match;
        result = v7;
        *a2 = v11 - *((_DWORD *)v7 + 56);
        goto LABEL_7;
      }
      dev_kfree_skb_any_reason(v7, 2);
    }
    result = nullptr;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
