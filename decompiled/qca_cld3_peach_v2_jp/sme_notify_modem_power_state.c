__int64 __fastcall sme_notify_modem_power_state(__int64 a1, int a2)
{
  _DWORD *v3; // x0
  __int64 v4; // x19
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // [xsp+8h] [xbp-38h] BYREF
  _DWORD *v15; // [xsp+10h] [xbp-30h]
  __int64 v16; // [xsp+18h] [xbp-28h]
  __int64 v17; // [xsp+20h] [xbp-20h]
  __int64 v18; // [xsp+28h] [xbp-18h]
  __int64 v19; // [xsp+30h] [xbp-10h]
  __int64 v20; // [xsp+38h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = nullptr;
  if ( !a1 )
    goto LABEL_5;
  v3 = (_DWORD *)_qdf_mem_malloc(4u, "sme_notify_modem_power_state", 7978);
  if ( !v3 )
  {
    result = 2;
    goto LABEL_7;
  }
  *v3 = a2;
  v4 = (__int64)v3;
  v15 = v3;
  LODWORD(v14) = 4318;
  result = scheduler_post_message_debug(
             0x34u,
             0x36u,
             54,
             (unsigned __int16 *)&v14,
             0x1F36u,
             (__int64)"sme_notify_modem_power_state");
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Not able to post WMA_MODEM_POWER_STATE_IND message to WMA",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "sme_notify_modem_power_state");
    _qdf_mem_free(v4);
LABEL_5:
    result = 16;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
