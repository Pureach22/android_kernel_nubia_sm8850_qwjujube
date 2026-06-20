__int64 __fastcall cld80211_oem_rsp_alloc_skb(unsigned int a1, __int64 *a2, _QWORD *a3, unsigned int *a4)
{
  unsigned __int64 StatusReg; // x8
  __int64 v9; // x1
  __int64 v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w23
  __int64 genl_family; // x0
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x22
  __int64 v31; // x8
  const char *v32; // x2
  unsigned __int64 v33; // x8
  unsigned __int64 v34; // x9

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0
    || (_ReadStatusReg(DAIF) & 0x80) != 0
    || *(_DWORD *)(StatusReg + 16) )
  {
    v9 = 2080;
    *a4 = 2080;
  }
  else
  {
    v9 = *a4;
  }
  v10 = _alloc_skb(7808, v9, 0, 0xFFFFFFFFLL);
  if ( !v10 )
  {
    qdf_trace_msg(0x33u, 2u, "nlmsg malloc fails", v11, v12, v13, v14, v15, v16, v17, v18);
    return v10;
  }
  v19 = *a4;
  genl_family = cld80211_get_genl_family();
  v21 = genlmsg_put(v10, a1, 0, genl_family, v19, 25);
  *a2 = v21;
  if ( v21 )
  {
    v30 = *(_QWORD *)(v10 + 216) + *(unsigned int *)(v10 + 208);
    if ( (int)nla_put(v10, 32769, 0, 0) >= 0 )
      v31 = v30;
    else
      v31 = 0;
    *a3 = v31;
    if ( v31 )
      return v10;
    v32 = "nla_nest_start failed";
  }
  else
  {
    v32 = "nl80211 hdr put failed";
  }
  qdf_trace_msg(0x33u, 2u, v32, v22, v23, v24, v25, v26, v27, v28, v29);
  if ( *a2 )
  {
    v33 = *a2 - 20;
    if ( *a2 != 20 )
    {
      v34 = *(_QWORD *)(v10 + 224);
      if ( v34 > v33 )
      {
        __break(0x800u);
        v34 = *(_QWORD *)(v10 + 224);
      }
      skb_trim(v10, (unsigned int)(v33 - v34));
    }
  }
  sk_skb_reason_drop(0, v10, 2);
  return 0;
}
