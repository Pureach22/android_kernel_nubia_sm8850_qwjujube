__int64 __fastcall lim_process_for_spectrum_mgmt(
        __int64 result,
        unsigned __int8 *a2,
        __int64 a3,
        __int64 a4,
        char a5,
        __int16 a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  unsigned __int8 *v14; // x22
  char v15; // w21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  int v24; // w8
  const char *v25; // x4
  __int64 v26; // x5
  __int64 v27; // x6
  __int64 v28; // x7
  char v29; // w19
  const char *v30; // x4
  __int64 v32; // x5
  __int64 v33; // x6
  unsigned __int8 *v34; // x21
  __int64 v35; // x7
  int v36; // w8
  const char *v37; // x4
  __int64 v38; // x5
  __int64 v39; // x6
  __int64 v40; // x7
  int v41; // w8
  const char *v42; // x2
  __int64 v43; // [xsp+0h] [xbp-10h]

  if ( (a6 & 0x100) == 0 || (*(_WORD *)a4 & 0x100) == 0 )
    return result;
  if ( !*(_BYTE *)(a4 + 3269) )
  {
    v29 = a5;
    if ( a5 )
      v30 = "ReAssoc";
    else
      v30 = "Assoc";
    if ( a2 )
    {
      v32 = *a2;
      v33 = a2[1];
      v34 = a2;
      v35 = a2[2];
      v36 = a2[5];
    }
    else
    {
      v34 = nullptr;
      v35 = 0;
      v32 = 0;
      v33 = 0;
      v36 = 0;
    }
    result = qdf_trace_msg(
               0x35u,
               3u,
               "%s: LIM Info: Missing Power capability IE in %s Req from %02x:%02x:%02x:**:**:%02x",
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               a13,
               a14,
               "lim_process_for_spectrum_mgmt",
               v30,
               v32,
               v33,
               v35,
               v36);
    a2 = v34;
    a5 = v29;
    if ( *(_BYTE *)(a4 + 3270) )
      return result;
LABEL_18:
    if ( a5 )
      v37 = "ReAssoc";
    else
      v37 = "Assoc";
    if ( a2 )
    {
      v38 = *a2;
      v39 = a2[1];
      v40 = a2[2];
      v41 = a2[5];
    }
    else
    {
      v40 = 0;
      v38 = 0;
      v39 = 0;
      v41 = 0;
    }
    v42 = "%s: LIM Info: Missing Supported channel IE in %s Req from %02x:%02x:%02x:**:**:%02x";
    goto LABEL_34;
  }
  if ( !*(_BYTE *)(a4 + 3270) )
    goto LABEL_18;
  v14 = a2;
  v15 = a5;
  if ( (unsigned int)lim_is_dot11h_power_capabilities_in_range(result, a4, a3, a7, a8, a9, a10, a11, a12, a13, a14) )
  {
    v24 = (int)v14;
    if ( v15 )
      v25 = "ReAssoc";
    else
      v25 = "Assoc";
    if ( v14 )
    {
      v26 = *v14;
      v27 = v14[1];
      v28 = v14[2];
      v24 = v14[5];
    }
    else
    {
      v28 = 0;
      v26 = 0;
      v27 = 0;
    }
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: LIM Info: MinTxPower(STA) > MaxTxPower(AP) in %s Req from %02x:%02x:%02x:**:**:%02x",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "lim_process_for_spectrum_mgmt",
      v25,
      v26,
      v27,
      v28,
      v24);
  }
  result = lim_is_dot11h_supported_channels_valid();
  if ( (_DWORD)result )
  {
    if ( v15 )
      v37 = "ReAssoc";
    else
      v37 = "Assoc";
    if ( v14 )
    {
      v38 = *v14;
      v39 = v14[1];
      v42 = "%s: LIM Info: wrong supported channels (STA) in %s Req from %02x:%02x:%02x:**:**:%02x";
      v40 = v14[2];
      v41 = v14[5];
    }
    else
    {
      v40 = 0;
      v38 = 0;
      v39 = 0;
      v41 = 0;
      v42 = "%s: LIM Info: wrong supported channels (STA) in %s Req from %02x:%02x:%02x:**:**:%02x";
    }
LABEL_34:
    LODWORD(v43) = v41;
    return qdf_trace_msg(
             0x35u,
             3u,
             v42,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             a13,
             a14,
             "lim_process_for_spectrum_mgmt",
             v37,
             v38,
             v39,
             v40,
             v43);
  }
  return result;
}
