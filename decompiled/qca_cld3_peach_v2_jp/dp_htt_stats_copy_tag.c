_QWORD *__fastcall dp_htt_stats_copy_tag(
        _QWORD *result,
        __int64 a2,
        const void *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x19
  __int64 v12; // x8
  const void *v13; // x23
  unsigned int v14; // w20
  __int64 v15; // x4
  __int64 v16; // x8
  char *v17; // x21

  v11 = (__int64)result;
  result[11949] |= 1LL << a2;
  if ( (unsigned __int8)a2 <= 0x1Bu )
  {
    if ( (unsigned __int8)a2 <= 1u )
    {
      if ( (_BYTE)a2 )
      {
        v12 = 887;
        goto LABEL_23;
      }
      v13 = a3;
      v14 = 204;
      v15 = 312;
      v16 = 6892;
      goto LABEL_30;
    }
    switch ( (unsigned __int8)a2 )
    {
      case 2u:
        v12 = 888;
        break;
      case 3u:
        v12 = 889;
        break;
      case 4u:
        v12 = 890;
        break;
      default:
        goto LABEL_25;
    }
LABEL_23:
    v17 = (char *)&result[v12];
    v14 = 8;
    if ( !&result[v12] )
      goto LABEL_25;
    goto LABEL_24;
  }
  if ( (unsigned __int8)a2 > 0x1Eu )
  {
    switch ( (unsigned __int8)a2 )
    {
      case 0x1Fu:
        v13 = a3;
        v14 = 24;
        v15 = 48;
        v16 = 7256;
        goto LABEL_30;
      case 0x20u:
        v12 = 910;
        break;
      case 0x21u:
        v12 = 911;
        break;
      default:
        goto LABEL_25;
    }
    goto LABEL_23;
  }
  if ( (unsigned __int8)a2 != 28 )
  {
    if ( (unsigned __int8)a2 == 29 )
    {
      v12 = 950;
    }
    else
    {
      if ( (unsigned __int8)a2 != 30 )
        goto LABEL_25;
      v12 = 951;
    }
    goto LABEL_23;
  }
  v13 = a3;
  v14 = 304;
  v15 = 324;
  v16 = 7296;
LABEL_30:
  v17 = (char *)result + v16;
  result = (_QWORD *)qdf_trace_msg(
                       0x45u,
                       3u,
                       "%s: Buffer Overflow:FW Struct Size:%d Host Struct Size:%d",
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9,
                       a10,
                       a11,
                       "dp_htt_stats_copy_tag",
                       v15,
                       v14);
  a3 = v13;
  if ( v17 )
LABEL_24:
    result = qdf_mem_copy(v17, a3, v14);
LABEL_25:
  if ( (~*(_QWORD *)(v11 + 95592) & 0x3F000000FLL) == 0 )
    return (_QWORD *)qdf_event_set(v11 + 95288, a2);
  return result;
}
