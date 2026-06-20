__int64 __fastcall wlan_hdd_fill_btm_resp(__int64 a1, __int64 a2, int a3)
{
  __int64 v5; // x21
  __int64 v6; // x22
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  _WORD *v15; // x21
  __int64 result; // x0
  const char *v17; // x2
  int v18; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 216);
  v6 = *(unsigned int *)(a1 + 208);
  if ( (nla_put(a1, a3 | 0x8000u, 0, 0) & 0x80000000) != 0 || (v15 = (_WORD *)(v5 + v6)) == nullptr )
  {
    v17 = "%s: nla_nest_start failed";
  }
  else
  {
    if ( !(unsigned int)nla_put(a1, 1, 6, a2) )
    {
      v18 = *(_DWORD *)(a2 + 8);
      result = nla_put(a1, 2, 4, &v18);
      if ( !(_DWORD)result )
      {
        *v15 = *(_WORD *)(a1 + 216) + *(_DWORD *)(a1 + 208) - (_WORD)v15;
        goto LABEL_8;
      }
    }
    v17 = "%s: nla_put failed";
  }
  qdf_trace_msg(0x33u, 2u, v17, v7, v8, v9, v10, v11, v12, v13, v14, "wlan_hdd_fill_btm_resp");
  sk_skb_reason_drop(0, a1, 2);
  result = 4294967274LL;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
