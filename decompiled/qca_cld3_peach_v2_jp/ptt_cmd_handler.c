__int64 __fastcall ptt_cmd_handler(__int64 a1, unsigned int a2, __int64 a3, unsigned int a4)
{
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  const char *v13; // x2
  __int64 result; // x0
  __int64 v15; // x3
  _QWORD v16[2]; // [xsp+0h] [xbp-40h] BYREF
  __int64 v17; // [xsp+10h] [xbp-30h]
  __int64 v18; // [xsp+18h] [xbp-28h]
  __int64 v19; // [xsp+20h] [xbp-20h]
  __int64 v20; // [xsp+28h] [xbp-18h]
  __int64 v21; // [xsp+30h] [xbp-10h]
  __int64 v22; // [xsp+38h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v16[1] = 0;
  v17 = 0;
  v16[0] = 0;
  if ( (unsigned int)_nla_parse(v16, 6, a1, a2, 0, 31, 0) )
  {
    v13 = "Invalid ATTR";
LABEL_3:
    result = qdf_trace_msg(0x38u, 2u, v13, v5, v6, v7, v8, v9, v10, v11, v12);
    goto LABEL_4;
  }
  if ( !v17 )
  {
    v13 = "attr ATTR_DATA failed";
    goto LABEL_3;
  }
  if ( (unsigned __int16)(*(_WORD *)v17 - 4) <= 7u )
  {
    result = qdf_trace_msg(
               0x38u,
               2u,
               "%s:attr length check fails\n",
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "ptt_cmd_handler");
    goto LABEL_4;
  }
  v15 = bswap32(*(unsigned __int16 *)(v17 + 10)) >> 16;
  if ( ((unsigned int)v15 ^ 0xFFF8) <= 7 )
  {
    result = qdf_trace_msg(0x38u, 2u, "u16 overflow length %d %zu %zu", v5, v6, v7, v8, v9, v10, v11, v12, v15, 4, 4);
    goto LABEL_4;
  }
  if ( v15 + 8 > (unsigned __int64)(unsigned __int16)(*(_WORD *)v17 - 4) )
  {
    v13 = "ATTR_DATA len check failed";
    goto LABEL_3;
  }
  if ( *(_WORD *)(v17 + 8) == 1 )
    result = ptt_sock_send_msg_to_app(
               (unsigned __int16 *)(v17 + 8),
               *(_DWORD *)(v17 + 4),
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               17,
               a4);
  else
    result = qdf_trace_msg(0x38u, 2u, "Unknown msg type %d", v5, v6, v7, v8, v9, v10, v11, v12);
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
