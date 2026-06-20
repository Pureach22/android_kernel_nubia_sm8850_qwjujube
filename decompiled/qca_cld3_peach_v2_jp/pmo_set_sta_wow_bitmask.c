__int64 __fastcall pmo_set_sta_wow_bitmask(
        __int64 result,
        _DWORD *a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x21
  __int64 v14; // x8

  v12 = result;
  if ( !result || (v14 = *(_QWORD *)(result + 32), (v14 & 0x400) != 0) )
  {
    if ( a2 && a3 > 3 )
    {
      a2[0xA / (8 * a3)] |= 1 << (0xA % (8 * a3));
      if ( !result )
        goto LABEL_10;
    }
    else
    {
      result = qdf_trace_msg(
                 0x4Du,
                 2u,
                 "%s: wow bitmask length shorter than %d",
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 "pmo_set_wow_event_bitmap",
                 4);
      if ( !v12 )
        goto LABEL_10;
    }
    v14 = *(_QWORD *)(v12 + 32);
  }
  if ( (v14 & 0x800000) == 0 )
  {
LABEL_16:
    if ( (v14 & 0x200) == 0 || (*(_BYTE *)v12 & 1) == 0 )
      goto LABEL_24;
    goto LABEL_18;
  }
LABEL_10:
  if ( !a2 || a3 <= 3 )
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: wow bitmask length shorter than %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "pmo_set_wow_event_bitmap",
               4);
    if ( !v12 )
      goto LABEL_18;
    goto LABEL_15;
  }
  a2[0x17 / (8 * a3)] |= 1 << (0x17 % (8 * a3));
  if ( v12 )
  {
LABEL_15:
    v14 = *(_QWORD *)(v12 + 32);
    goto LABEL_16;
  }
LABEL_18:
  if ( a2 && a3 > 3 )
  {
    a2[9 / (8 * a3)] |= 1 << (9 % (8 * a3));
    if ( !v12 )
      goto LABEL_26;
  }
  else
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: wow bitmask length shorter than %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "pmo_set_wow_event_bitmap",
               4);
    if ( !v12 )
      goto LABEL_26;
  }
  v14 = *(_QWORD *)(v12 + 32);
LABEL_24:
  if ( (v14 & 8) == 0 || (*(_BYTE *)(v12 + 20) & 1) == 0 )
  {
LABEL_32:
    if ( (v14 & 4) == 0 )
      goto LABEL_39;
    goto LABEL_33;
  }
LABEL_26:
  if ( !a2 || a3 <= 3 )
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: wow bitmask length shorter than %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "pmo_set_wow_event_bitmap",
               4);
    if ( !v12 )
      goto LABEL_33;
    goto LABEL_31;
  }
  a2[3 / (8 * a3)] |= 8u;
  if ( v12 )
  {
LABEL_31:
    v14 = *(_QWORD *)(v12 + 32);
    goto LABEL_32;
  }
LABEL_33:
  if ( a2 && a3 > 3 )
  {
    a2[2 / (8 * a3)] |= 4u;
    if ( !v12 )
      goto LABEL_40;
  }
  else
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: wow bitmask length shorter than %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "pmo_set_wow_event_bitmap",
               4);
    if ( !v12 )
      goto LABEL_40;
  }
  v14 = *(_QWORD *)(v12 + 32);
LABEL_39:
  if ( (v14 & 0x100) == 0 )
    goto LABEL_46;
LABEL_40:
  if ( !a2 || a3 <= 3 )
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: wow bitmask length shorter than %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "pmo_set_wow_event_bitmap",
               4);
    if ( !v12 )
      goto LABEL_47;
    goto LABEL_45;
  }
  a2[8 / (8 * a3)] |= 1 << (8 % (8 * a3));
  if ( v12 )
  {
LABEL_45:
    v14 = *(_QWORD *)(v12 + 32);
LABEL_46:
    if ( (v14 & 1) == 0 )
      goto LABEL_53;
  }
LABEL_47:
  if ( a2 && a3 > 3 )
  {
    *a2 |= 1u;
    if ( !v12 )
      goto LABEL_54;
  }
  else
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: wow bitmask length shorter than %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "pmo_set_wow_event_bitmap",
               4);
    if ( !v12 )
      goto LABEL_54;
  }
  v14 = *(_QWORD *)(v12 + 32);
LABEL_53:
  if ( (v14 & 0x400000) == 0 )
    goto LABEL_60;
LABEL_54:
  if ( !a2 || a3 <= 3 )
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: wow bitmask length shorter than %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "pmo_set_wow_event_bitmap",
               4);
    if ( !v12 )
      goto LABEL_61;
    goto LABEL_59;
  }
  a2[0x16 / (8 * a3)] |= 1 << (0x16 % (8 * a3));
  if ( v12 )
  {
LABEL_59:
    v14 = *(_QWORD *)(v12 + 32);
LABEL_60:
    if ( (v14 & 0x10) == 0 )
      goto LABEL_67;
  }
LABEL_61:
  if ( a2 && a3 > 3 )
  {
    a2[4 / (8 * a3)] |= 0x10u;
    if ( !v12 )
      goto LABEL_68;
  }
  else
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: wow bitmask length shorter than %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "pmo_set_wow_event_bitmap",
               4);
    if ( !v12 )
      goto LABEL_68;
  }
  v14 = *(_QWORD *)(v12 + 32);
LABEL_67:
  if ( (v14 & 2) == 0 )
    goto LABEL_74;
LABEL_68:
  if ( !a2 || a3 <= 3 )
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: wow bitmask length shorter than %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "pmo_set_wow_event_bitmap",
               4);
    if ( !v12 )
      goto LABEL_75;
    goto LABEL_73;
  }
  *a2 |= 2u;
  if ( v12 )
  {
LABEL_73:
    v14 = *(_QWORD *)(v12 + 32);
LABEL_74:
    if ( (v14 & 0x4000) == 0 )
      goto LABEL_81;
  }
LABEL_75:
  if ( a2 && a3 > 3 )
  {
    a2[0xE / (8 * a3)] |= 1 << (0xE % (8 * a3));
    if ( !v12 )
      goto LABEL_82;
  }
  else
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: wow bitmask length shorter than %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "pmo_set_wow_event_bitmap",
               4);
    if ( !v12 )
      goto LABEL_82;
  }
  v14 = *(_QWORD *)(v12 + 32);
LABEL_81:
  if ( (v14 & 0x8000) == 0 )
    goto LABEL_88;
LABEL_82:
  if ( !a2 || a3 <= 3 )
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: wow bitmask length shorter than %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "pmo_set_wow_event_bitmap",
               4);
    if ( !v12 )
      goto LABEL_89;
    goto LABEL_87;
  }
  a2[0xF / (8 * a3)] |= 1 << (0xF % (8 * a3));
  if ( v12 )
  {
LABEL_87:
    v14 = *(_QWORD *)(v12 + 32);
LABEL_88:
    if ( (v14 & 0x80) == 0 )
      goto LABEL_95;
  }
LABEL_89:
  if ( a2 && a3 > 3 )
  {
    a2[7 / (8 * a3)] |= 0x80u;
    if ( !v12 )
      goto LABEL_96;
  }
  else
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: wow bitmask length shorter than %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "pmo_set_wow_event_bitmap",
               4);
    if ( !v12 )
      goto LABEL_96;
  }
  v14 = *(_QWORD *)(v12 + 32);
LABEL_95:
  if ( (v14 & 0x2000000) == 0 )
    goto LABEL_102;
LABEL_96:
  if ( !a2 || a3 <= 3 )
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: wow bitmask length shorter than %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "pmo_set_wow_event_bitmap",
               4);
    if ( !v12 )
      goto LABEL_103;
    goto LABEL_101;
  }
  a2[0x19 / (8 * a3)] |= 1 << (0x19 % (8 * a3));
  if ( v12 )
  {
LABEL_101:
    v14 = *(_QWORD *)(v12 + 32);
LABEL_102:
    if ( (v14 & 0x40000000) == 0 )
      goto LABEL_109;
  }
LABEL_103:
  if ( a2 && a3 > 3 )
  {
    a2[0x1E / (8 * a3)] |= 1 << (0x1E % (8 * a3));
    if ( !v12 )
      goto LABEL_110;
  }
  else
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: wow bitmask length shorter than %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "pmo_set_wow_event_bitmap",
               4);
    if ( !v12 )
      goto LABEL_110;
  }
  v14 = *(_QWORD *)(v12 + 32);
LABEL_109:
  if ( (v14 & 0x80000000) == 0 )
    goto LABEL_116;
LABEL_110:
  if ( !a2 || a3 <= 3 )
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: wow bitmask length shorter than %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "pmo_set_wow_event_bitmap",
               4);
    if ( !v12 )
      goto LABEL_117;
    goto LABEL_115;
  }
  a2[0x1F / (8 * a3)] |= 1 << ~(0x1F / (8 * a3) * 8 * a3);
  if ( v12 )
  {
LABEL_115:
    v14 = *(_QWORD *)(v12 + 32);
LABEL_116:
    if ( (v14 & 0x400000000LL) == 0 )
      goto LABEL_123;
  }
LABEL_117:
  if ( a2 && a3 > 3 )
  {
    a2[0x22 / (8 * a3)] |= 1 << (0x22 % (8 * a3));
    if ( !v12 )
      goto LABEL_124;
  }
  else
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: wow bitmask length shorter than %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "pmo_set_wow_event_bitmap",
               4);
    if ( !v12 )
      goto LABEL_124;
  }
  v14 = *(_QWORD *)(v12 + 32);
LABEL_123:
  if ( (v14 & 0x10000000) == 0 )
    goto LABEL_130;
LABEL_124:
  if ( !a2 || a3 <= 3 )
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: wow bitmask length shorter than %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "pmo_set_wow_event_bitmap",
               4);
    if ( !v12 )
      goto LABEL_131;
    goto LABEL_129;
  }
  a2[0x1C / (8 * a3)] |= 1 << (0x1C % (8 * a3));
  if ( v12 )
  {
LABEL_129:
    v14 = *(_QWORD *)(v12 + 32);
LABEL_130:
    if ( (v14 & 0x4000000000LL) == 0 )
      goto LABEL_137;
  }
LABEL_131:
  if ( a2 && a3 > 3 )
  {
    a2[0x26 / (8 * a3)] |= 1 << (0x26 % (8 * a3));
    if ( !v12 )
      goto LABEL_138;
  }
  else
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: wow bitmask length shorter than %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "pmo_set_wow_event_bitmap",
               4);
    if ( !v12 )
      goto LABEL_138;
  }
  v14 = *(_QWORD *)(v12 + 32);
LABEL_137:
  if ( (v14 & 0x8000000000LL) == 0 )
    goto LABEL_144;
LABEL_138:
  if ( !a2 || a3 <= 3 )
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: wow bitmask length shorter than %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "pmo_set_wow_event_bitmap",
               4);
    if ( !v12 )
      goto LABEL_145;
    goto LABEL_143;
  }
  a2[0x27 / (8 * a3)] |= 1 << (0x27 % (8 * a3));
  if ( v12 )
  {
LABEL_143:
    v14 = *(_QWORD *)(v12 + 32);
LABEL_144:
    if ( (v14 & 0x20000000000LL) == 0 )
      goto LABEL_151;
  }
LABEL_145:
  if ( a2 && a3 > 3 )
  {
    a2[0x29 / (8 * a3)] |= 1 << (0x29 % (8 * a3));
    if ( !v12 )
      goto LABEL_152;
  }
  else
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: wow bitmask length shorter than %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "pmo_set_wow_event_bitmap",
               4);
    if ( !v12 )
      goto LABEL_152;
  }
  v14 = *(_QWORD *)(v12 + 32);
LABEL_151:
  if ( (v14 & 0x40000000000LL) == 0 )
    goto LABEL_158;
LABEL_152:
  if ( !a2 || a3 <= 3 )
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: wow bitmask length shorter than %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "pmo_set_wow_event_bitmap",
               4);
    if ( !v12 )
      goto LABEL_159;
    goto LABEL_157;
  }
  a2[0x2A / (8 * a3)] |= 1 << (0x2A % (8 * a3));
  if ( v12 )
  {
LABEL_157:
    v14 = *(_QWORD *)(v12 + 32);
LABEL_158:
    if ( (v14 & 0x80000000000LL) == 0 )
      goto LABEL_165;
  }
LABEL_159:
  if ( a2 && a3 > 3 )
  {
    a2[0x2B / (8 * a3)] |= 1 << (0x2B % (8 * a3));
    if ( !v12 )
      goto LABEL_166;
  }
  else
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: wow bitmask length shorter than %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "pmo_set_wow_event_bitmap",
               4);
    if ( !v12 )
      goto LABEL_166;
  }
  v14 = *(_QWORD *)(v12 + 32);
LABEL_165:
  if ( (v14 & 0x200000000000LL) == 0 )
    goto LABEL_172;
LABEL_166:
  if ( a2 && a3 > 3 )
  {
    a2[0x2D / (8 * a3)] |= 1 << (0x2D % (8 * a3));
    if ( !v12 )
      goto LABEL_173;
    goto LABEL_171;
  }
  result = qdf_trace_msg(
             0x4Du,
             2u,
             "%s: wow bitmask length shorter than %d",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "pmo_set_wow_event_bitmap",
             4);
  if ( v12 )
  {
LABEL_171:
    v14 = *(_QWORD *)(v12 + 32);
LABEL_172:
    if ( (v14 & 0x1000000000000LL) == 0 )
      return result;
  }
LABEL_173:
  if ( !a2 || a3 <= 3 )
    return qdf_trace_msg(
             0x4Du,
             2u,
             "%s: wow bitmask length shorter than %d",
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             "pmo_set_wow_event_bitmap",
             4);
  a2[0x30 / (8 * a3)] |= 1 << (0x30 % (8 * a3));
  return result;
}
