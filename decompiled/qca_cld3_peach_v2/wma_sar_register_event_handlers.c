__int64 __fastcall wma_sar_register_event_handlers(_QWORD **a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  _QWORD *v10; // x19
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7

  if ( (unsigned int)_wma_validate_handle(a1, "wma_sar_register_event_handlers") )
    return 4;
  v10 = *a1;
  if ( (unsigned int)_wmi_validate_handle(
                       (__int64)v10,
                       (__int64)"wma_sar_register_event_handlers",
                       v2,
                       v3,
                       v4,
                       v5,
                       v6,
                       v7,
                       v8,
                       v9) )
    return 4;
  else
    return wmi_unified_register_event_handler(
             v10,
             0xBCu,
             (__int64)wma_sar_event_handler,
             0,
             v11,
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18);
}
