__int64 __fastcall os_if_dp_flow_classify_result(__int64 a1, __int64 a2, unsigned int a3)
{
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  const char *v11; // x2
  __int64 result; // x0
  char v13; // w8
  __int64 v14; // [xsp+0h] [xbp-C0h] BYREF
  __int64 v15; // [xsp+8h] [xbp-B8h]
  _QWORD v16[2]; // [xsp+10h] [xbp-B0h] BYREF
  _QWORD v17[2]; // [xsp+20h] [xbp-A0h] BYREF
  __int64 v18; // [xsp+30h] [xbp-90h]
  __int64 v19; // [xsp+38h] [xbp-88h]
  __int64 v20; // [xsp+40h] [xbp-80h]
  __int64 v21; // [xsp+48h] [xbp-78h] BYREF
  __int64 v22; // [xsp+50h] [xbp-70h]
  __int64 v23; // [xsp+58h] [xbp-68h]
  __int64 v24; // [xsp+60h] [xbp-60h]
  __int64 v25; // [xsp+68h] [xbp-58h]
  __int64 v26; // [xsp+70h] [xbp-50h]
  __int64 v27; // [xsp+78h] [xbp-48h]
  __int64 v28; // [xsp+80h] [xbp-40h]
  __int64 v29; // [xsp+88h] [xbp-38h] BYREF
  _WORD *v30; // [xsp+90h] [xbp-30h]
  __int64 v31; // [xsp+98h] [xbp-28h]
  __int64 v32; // [xsp+A0h] [xbp-20h]
  __int64 v33; // [xsp+A8h] [xbp-18h] BYREF
  __int64 v34; // [xsp+B0h] [xbp-10h]
  __int64 v35; // [xsp+B8h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = nullptr;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v17[1] = 0;
  v18 = 0;
  v16[1] = 0;
  v17[0] = 0;
  v16[0] = 0;
  if ( (unsigned int)_nla_parse(&v29, 3, a2, a3, &flow_classify_result_policy, 31, 0) )
  {
    v11 = "%s: STC: Invalid flow classify result attributes";
LABEL_9:
    qdf_trace_msg(0x48u, 2u, v11, v3, v4, v5, v6, v7, v8, v9, v10, "os_if_dp_flow_classify_result");
    result = 4;
    goto LABEL_10;
  }
  if ( !v30 )
  {
    v11 = "%s: STC: flow tuple not specified";
    goto LABEL_9;
  }
  if ( ((__int16)v30[1] & 0x80000000) == 0 )
  {
    do_trace_netlink_extack("NLA_F_NESTED is missing");
LABEL_8:
    v11 = "%s: STC: parsing flow tuple failed";
    goto LABEL_9;
  }
  if ( (unsigned int)_nla_parse(&v21, 7, v30 + 2, (unsigned __int16)(*v30 - 4), &flow_tuple_policy, 31, 0) )
    goto LABEL_8;
  if ( v22 && v23 )
  {
    LODWORD(v16[0]) = *(_DWORD *)(v22 + 4);
    LODWORD(v17[0]) = *(_DWORD *)(v23 + 4);
  }
  else
  {
    if ( !v24 || !v25 )
    {
      v11 = "%s: STC: IP address not present in flow tuple";
      goto LABEL_9;
    }
    v33 = 0;
    v34 = 0;
    nla_memcpy(&v33, v24, 16);
    v14 = v33;
    v15 = v34;
    qdf_mem_copy(v16, &v14, 0x10u);
    v33 = 0;
    v34 = 0;
    nla_memcpy(&v33, v25, 16);
    v14 = v33;
    v15 = v34;
    qdf_mem_copy(v17, &v14, 0x10u);
  }
  if ( !v26 )
  {
    v11 = "%s: STC: source port missing in flow tuple";
    goto LABEL_9;
  }
  LOWORD(v18) = *(_WORD *)(v26 + 4);
  if ( !v27 )
  {
    v11 = "%s: STC: destination port missing in flow tuple";
    goto LABEL_9;
  }
  WORD1(v18) = *(_WORD *)(v27 + 4);
  if ( !v28 )
  {
    v11 = "%s: STC: Protocol missing in flow tuple";
    goto LABEL_9;
  }
  BYTE4(v18) = *(_BYTE *)(v28 + 4);
  if ( !v31 )
  {
    v11 = "%s: STC: traffic type not specified";
    goto LABEL_9;
  }
  BYTE4(v20) = *(_BYTE *)(v31 + 4);
  v13 = 31;
  if ( v32 )
  {
    if ( *(unsigned __int8 *)(v32 + 4) <= 0x11u )
      v13 = *(_BYTE *)(v32 + 4);
    else
      v13 = 31;
  }
  BYTE5(v20) = v13;
  ucfg_dp_flow_classify_result((__int64)v16);
  result = 0;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
