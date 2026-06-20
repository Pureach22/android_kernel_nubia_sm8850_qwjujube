__int64 __fastcall qdf_dp_display_record(__int64 result, unsigned __int16 a2, unsigned __int8 a3, unsigned int a4)
{
  __int64 v6; // x19
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  int v15; // w8
  const char *v16; // x2
  _QWORD v17[12]; // [xsp+0h] [xbp-70h] BYREF
  int v18; // [xsp+60h] [xbp-10h]
  __int64 v19; // [xsp+68h] [xbp-8h]

  v6 = result;
  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 == 255 || *(unsigned __int8 *)(result + 80) == a3 )
  {
    v18 = 0;
    memset(v17, 0, sizeof(v17));
    qdf_mem_set(v17, 0x64u, 0);
    qdf_dp_trace_fill_meta_str(v17, 100, a2, a4, v6);
    v15 = *(unsigned __int8 *)(v6 + 8);
    switch ( v15 )
    {
      case 30:
        v16 = " %s: CE Fast Packet Error";
        break;
      case 11:
        v16 = " %s: HDD SoftAP TX Timeout";
        break;
      case 10:
        v16 = " %s: HDD TX Timeout";
        break;
      default:
        result = dump_dp_hex_trace(v17, v6 + 9, *(unsigned __int8 *)(v6 + 75));
        goto LABEL_11;
    }
    result = qdf_trace_msg(0x38u, 8u, v16, v7, v8, v9, v10, v11, v12, v13, v14, v17);
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
