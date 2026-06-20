__int64 __fastcall send_packetdump(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        __int64 a11,
        char a12,
        unsigned __int8 a13)
{
  __int64 v13; // x8
  __int64 (__fastcall *v14)(_QWORD); // x8
  __int16 v18; // w10
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  char *v27; // x8
  const char *v28; // x2
  const char *v29; // x3
  unsigned int v30; // w0
  unsigned int v31; // w1
  __int64 v32; // [xsp+0h] [xbp-20h] BYREF
  unsigned __int16 v33[8]; // [xsp+8h] [xbp-18h] BYREF
  __int64 v34; // [xsp+18h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(&v33[1], 0, 14);
  v32 = 0;
  if ( !a11 )
  {
    v28 = "%s: Invalid netbuf";
    v29 = "send_packetdump";
    v30 = 56;
    v31 = 2;
    goto LABEL_12;
  }
  if ( !*(_QWORD *)result || (v13 = *(_QWORD *)(*(_QWORD *)result + 64LL)) == 0 )
  {
    v28 = "%s invalid instance";
    v29 = "cdp_get_opmode";
    v30 = 69;
    v31 = 1;
LABEL_12:
    result = qdf_trace_msg(v30, v31, v28, a2, a3, a4, a5, a6, a7, a8, a9, v29, v32);
    goto LABEL_13;
  }
  v14 = *(__int64 (__fastcall **)(_QWORD))(v13 + 112);
  if ( v14 )
  {
    if ( *((_DWORD *)v14 - 1) != 2077786039 )
      __break(0x8228u);
    result = v14(result);
    if ( (_DWORD)result == 3 )
    {
      v18 = *(_WORD *)(a11 + 112);
      LOBYTE(v32) = a12;
      v33[2] = 11;
      v33[0] = 0x8000;
      v33[3] = v18 + 8;
      BYTE1(v32) = a13;
      *(_DWORD *)((char *)&v32 + 2) = (int)ktime_get_with_offset(1) / 1000;
      if ( (unsigned int)a13 - 3 >= 2 )
      {
        if ( (unsigned int)a13 - 5 > 1 )
        {
LABEL_17:
          result = wlan_pkt_stats_to_logger_thread(
                     v33,
                     &v32,
                     *(const void **)(a11 + 224),
                     v19,
                     v20,
                     v21,
                     v22,
                     v23,
                     v24,
                     v25,
                     v26);
          goto LABEL_13;
        }
        v27 = &grx_count;
      }
      else
      {
        v27 = &gtx_count;
      }
      ++*v27;
      goto LABEL_17;
    }
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
