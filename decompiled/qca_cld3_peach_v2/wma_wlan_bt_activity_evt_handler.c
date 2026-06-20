__int64 __fastcall wma_wlan_bt_activity_evt_handler(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10)
{
  __int64 v10; // x20
  int v11; // w9
  __int64 result; // x0
  const char *v13; // x2
  __int64 v14; // [xsp+8h] [xbp-38h] BYREF
  __int64 v15; // [xsp+10h] [xbp-30h]
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
  v15 = 0;
  if ( !a10 )
  {
    v13 = "%s: Invalid BT activity event buffer";
LABEL_8:
    qdf_trace_msg(0x36u, 2u, v13, a1, a2, a3, a4, a5, a6, a7, a8, "wma_wlan_bt_activity_evt_handler");
    result = 4294967274LL;
    goto LABEL_9;
  }
  v10 = *a10;
  if ( !*a10 )
  {
    v13 = "%s: Invalid BT activity event fixed param buffer";
    goto LABEL_8;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Received BT activity event %u",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "wma_wlan_bt_activity_evt_handler",
    *(unsigned int *)(v10 + 4));
  v15 = 0;
  v11 = *(_DWORD *)(v10 + 4);
  LOWORD(v14) = 5260;
  HIDWORD(v14) = v11;
  if ( (unsigned int)scheduler_post_message_debug(
                       0x36u,
                       0x34u,
                       52,
                       (unsigned __int16 *)&v14,
                       0x188Fu,
                       (__int64)"wma_wlan_bt_activity_evt_handler") )
    result = 4294967274LL;
  else
    result = 0;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
