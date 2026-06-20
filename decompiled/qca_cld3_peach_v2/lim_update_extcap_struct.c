__int64 __fastcall lim_update_extcap_struct(
        __int64 result,
        _BYTE *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x20
  const char *v12; // x2
  __int64 v13; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  _QWORD v24[3]; // [xsp+8h] [xbp-18h] BYREF

  v24[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v24, 0, 15);
  if ( !a2 )
  {
    v12 = "%s: Invalid Buffer Address";
LABEL_9:
    result = qdf_trace_msg(0x35u, 2u, v12, a4, a5, a6, a7, a8, a9, a10, a11, "lim_update_extcap_struct");
    goto LABEL_10;
  }
  if ( !a3 )
  {
    v12 = "%s: NULL dst pointer";
    goto LABEL_9;
  }
  if ( *a2 == 127 && (unsigned __int8)a2[1] < 0x10u )
  {
    v13 = result;
    qdf_mem_set(v24, 0xFu, 0);
    qdf_mem_copy(v24, a2 + 2, (unsigned __int8)a2[1]);
    result = dot11f_unpack_ie_ext_cap(v13, v24, (unsigned __int8)a2[1], a3, 0);
    if ( (_DWORD)result )
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: dot11f_unpack Parse Error %d",
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 "lim_update_extcap_struct",
                 (unsigned int)result);
  }
  else
  {
    v11 = jiffies;
    if ( lim_update_extcap_struct___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: Invalid IEs eid: %d elem_len: %d",
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 "lim_update_extcap_struct");
      lim_update_extcap_struct___last_ticks = v11;
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
