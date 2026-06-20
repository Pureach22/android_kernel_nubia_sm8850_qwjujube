__int64 __fastcall wma_pdev_temperature_evt_handler(
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
  unsigned int v12; // w19
  const char *v13; // x2
  __int64 v15; // [xsp+8h] [xbp-38h] BYREF
  __int64 v16; // [xsp+10h] [xbp-30h]
  __int64 v17; // [xsp+18h] [xbp-28h]
  __int64 v18; // [xsp+20h] [xbp-20h]
  __int64 v19; // [xsp+28h] [xbp-18h]
  __int64 v20; // [xsp+30h] [xbp-10h]
  __int64 v21; // [xsp+38h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  if ( !a10 )
  {
    v12 = -22;
    v13 = "%s: Invalid pdev_temperature event buffer";
    goto LABEL_5;
  }
  v10 = *a10;
  qdf_trace_msg(
    0x36u,
    4u,
    "%s: temperature: %d",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "wma_pdev_temperature_evt_handler",
    *(unsigned int *)(*a10 + 4));
  v16 = 0;
  v11 = *(_DWORD *)(v10 + 4);
  LOWORD(v15) = 5221;
  HIDWORD(v15) = v11;
  v12 = 0;
  if ( (unsigned int)scheduler_post_message_debug(
                       0x36u,
                       0x34u,
                       52,
                       (unsigned __int16 *)&v15,
                       0x4ADu,
                       (__int64)"wma_pdev_temperature_evt_handler") )
  {
    v13 = "%s: Fail to post get temperature ind msg";
LABEL_5:
    qdf_trace_msg(0x36u, 2u, v13, a1, a2, a3, a4, a5, a6, a7, a8, "wma_pdev_temperature_evt_handler");
  }
  _ReadStatusReg(SP_EL0);
  return v12;
}
