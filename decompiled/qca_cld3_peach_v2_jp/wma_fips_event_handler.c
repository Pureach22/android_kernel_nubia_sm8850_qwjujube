__int64 __fastcall wma_fips_event_handler(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x20
  __int64 result; // x0
  int fips_event_data; // w19
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  void (__fastcall *v29)(__int64, __int64 *); // x8
  __int64 v30; // x0
  __int64 v31; // [xsp+0h] [xbp-20h] BYREF
  __int64 v32; // [xsp+8h] [xbp-18h]
  __int64 v33; // [xsp+10h] [xbp-10h]
  __int64 v34; // [xsp+18h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32 = 0;
  v33 = 0;
  v31 = 0;
  if ( (unsigned int)_wma_validate_handle(
                       (__int64)a1,
                       (__int64)"wma_fips_event_handler",
                       a2,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9)
    || (v18 = *a1,
        (unsigned int)_wmi_validate_handle(
                        v18,
                        (__int64)"wma_fips_event_handler",
                        v10,
                        v11,
                        v12,
                        v13,
                        v14,
                        v15,
                        v16,
                        v17)) )
  {
    result = 4;
  }
  else
  {
    fips_event_data = wmi_extract_fips_event_data(v18);
    qdf_trace_msg(
      0x36u,
      4u,
      "%s: Received FIPS event, pdev:%u status:%u data_len:%u",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "wma_fips_event_handler",
      (unsigned int)v31,
      HIDWORD(v31),
      (unsigned int)v32);
    if ( fips_event_data )
      HIDWORD(v31) = 1;
    v29 = (void (__fastcall *)(__int64, __int64 *))fips_callback;
    fips_callback = nullptr;
    if ( v29 )
    {
      v30 = fips_context;
      if ( *((_DWORD *)v29 - 1) != -1821191195 )
        __break(0x8228u);
      v29(v30, &v31);
    }
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
