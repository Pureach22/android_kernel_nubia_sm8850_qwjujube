__int64 __fastcall htc_setup_target_buffer_assignments(__int64 result)
{
  unsigned int v1; // w20
  __int64 v2; // x19
  __int64 v3; // x0
  __int16 v4; // w8
  __int64 v5; // x9
  __int64 v6; // x10
  signed int v7; // w9
  int v8; // w8

  v1 = *(_DWORD *)(result + 3412);
  v2 = result;
  if ( *(_DWORD *)(result + 3556) == 8 )
  {
    v3 = *(_QWORD *)result;
    *(_BYTE *)(v2 + 3422) = v1;
    *(_WORD *)(v2 + 3420) = 256;
    result = hif_get_bus_type(v3);
    v4 = 257;
    if ( (_DWORD)result != 5 )
    {
      if ( (_DWORD)result == 4 )
      {
        v5 = 6;
        v6 = 3424;
        goto LABEL_11;
      }
      if ( (_DWORD)result )
        goto LABEL_12;
    }
    v1 >>= 1;
    *(_WORD *)(v2 + 3424) = 257;
    v4 = 258;
    v5 = 10;
    v6 = 3428;
    *(_BYTE *)(v2 + 3426) = v1;
LABEL_11:
    *(_WORD *)(v2 + v6) = v4;
    *(_BYTE *)(v2 + 3420 + v5) = v1;
    goto LABEL_12;
  }
  v7 = *(unsigned __int8 *)(result + 3561);
  if ( (unsigned int)(v7 - 4) < 0xFFFFFFFD )
    return result;
  v8 = (int)v1 / v7;
  *(_WORD *)(result + 3420) = 256;
  *(_BYTE *)(result + 3422) = (int)v1 / v7;
  if ( v7 != 1 )
  {
    *(_BYTE *)(result + 3426) = v8;
    *(_WORD *)(result + 3424) = 261;
    if ( (unsigned int)v7 >= 3 )
    {
      *(_BYTE *)(result + 3430) = v8;
      *(_WORD *)(result + 3428) = 262;
    }
  }
LABEL_12:
  if ( *(_WORD *)(v2 + 3416) && (dword_B804 & 4) != 0 )
    result = qdf_trace_msg(
               56,
               2,
               "%s: SVS Index : %d TX : 0x%2.2X : alloc:%d",
               "htc_setup_target_buffer_assignments",
               0,
               *(unsigned __int16 *)(v2 + 3416),
               *(unsigned __int8 *)(v2 + 3418));
  if ( *(_WORD *)(v2 + 3420) && (dword_B804 & 4) != 0 )
    result = qdf_trace_msg(
               56,
               2,
               "%s: SVS Index : %d TX : 0x%2.2X : alloc:%d",
               "htc_setup_target_buffer_assignments",
               1,
               *(unsigned __int16 *)(v2 + 3420),
               *(unsigned __int8 *)(v2 + 3422));
  if ( *(_WORD *)(v2 + 3424) && (dword_B804 & 4) != 0 )
    result = qdf_trace_msg(
               56,
               2,
               "%s: SVS Index : %d TX : 0x%2.2X : alloc:%d",
               "htc_setup_target_buffer_assignments",
               2,
               *(unsigned __int16 *)(v2 + 3424),
               *(unsigned __int8 *)(v2 + 3426));
  if ( *(_WORD *)(v2 + 3428) && (dword_B804 & 4) != 0 )
    result = qdf_trace_msg(
               56,
               2,
               "%s: SVS Index : %d TX : 0x%2.2X : alloc:%d",
               "htc_setup_target_buffer_assignments",
               3,
               *(unsigned __int16 *)(v2 + 3428),
               *(unsigned __int8 *)(v2 + 3430));
  if ( *(_WORD *)(v2 + 3432) && (dword_B804 & 4) != 0 )
    result = qdf_trace_msg(
               56,
               2,
               "%s: SVS Index : %d TX : 0x%2.2X : alloc:%d",
               "htc_setup_target_buffer_assignments",
               4,
               *(unsigned __int16 *)(v2 + 3432),
               *(unsigned __int8 *)(v2 + 3434));
  if ( *(_WORD *)(v2 + 3436) && (dword_B804 & 4) != 0 )
    result = qdf_trace_msg(
               56,
               2,
               "%s: SVS Index : %d TX : 0x%2.2X : alloc:%d",
               "htc_setup_target_buffer_assignments",
               5,
               *(unsigned __int16 *)(v2 + 3436),
               *(unsigned __int8 *)(v2 + 3438));
  if ( *(_WORD *)(v2 + 3440) && (dword_B804 & 4) != 0 )
    result = qdf_trace_msg(
               56,
               2,
               "%s: SVS Index : %d TX : 0x%2.2X : alloc:%d",
               "htc_setup_target_buffer_assignments",
               6,
               *(unsigned __int16 *)(v2 + 3440),
               *(unsigned __int8 *)(v2 + 3442));
  if ( *(_WORD *)(v2 + 3444) )
  {
    if ( (dword_B804 & 4) != 0 )
      return qdf_trace_msg(
               56,
               2,
               "%s: SVS Index : %d TX : 0x%2.2X : alloc:%d",
               "htc_setup_target_buffer_assignments",
               7,
               *(unsigned __int16 *)(v2 + 3444),
               *(unsigned __int8 *)(v2 + 3446));
  }
  return result;
}
