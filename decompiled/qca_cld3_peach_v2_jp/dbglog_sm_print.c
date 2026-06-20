__int64 __fastcall dbglog_sm_print(
        __int64 result,
        __int64 a2,
        __int16 a3,
        int *a4,
        __int64 a5,
        __int64 a6,
        unsigned int a7,
        __int64 a8,
        unsigned int a9)
{
  __int64 v11; // x6
  int v12; // w10
  __int64 v13; // x7
  int v14; // w12
  unsigned int v15; // w11
  __int64 v16; // x8
  __int64 v17; // x10
  __int64 v18; // x8
  __int64 v19; // x5
  const char *v20; // x2
  __int64 v21; // x11
  unsigned int v22; // w10
  __int64 v23; // x9
  __int64 v24; // x3
  __int64 v25; // x4
  unsigned int v26; // w11

  if ( a3 == 4 )
  {
    v12 = *a4;
    v11 = (unsigned int)a4[1];
    v13 = (unsigned int)a4[2];
    v14 = a4[3];
    v15 = HIBYTE(*a4);
    if ( v15 == 2 )
    {
      if ( (v12 & 0xFF0000) != 0 )
        return result;
      v26 = (unsigned __int8)*a4;
      v22 = BYTE1(v12);
      if ( v26 < a9 && v22 < a7 )
      {
        v18 = *(_QWORD *)(a8 + 8LL * (unsigned __int8)*a4);
        v19 = *(_QWORD *)(a6 + 8LL * v22);
        v20 = "%s: unhandled event %s in state %s (%#x, %#x, %#x)";
LABEL_15:
        v24 = a5;
        v25 = v18;
        return dbglog_printf(result, a2, v20, v24, v25, v19, v11, v13, v14);
      }
      v20 = "%s: unhandled event %u in state %u (%#x, %#x, %#x)";
      v24 = a5;
      v25 = v26;
    }
    else
    {
      if ( v15 != 1 )
      {
        if ( HIBYTE(*a4) )
          return result;
        v16 = BYTE2(v12);
        v17 = BYTE1(v12);
        if ( (unsigned int)v16 >= a7 || (unsigned int)v17 >= a7 )
        {
          v20 = "%s: %u => %u (%#x, %#x, %#x)";
          v24 = a5;
          v25 = (unsigned int)v16;
          v19 = (unsigned int)v17;
          return dbglog_printf(result, a2, v20, v24, v25, v19, v11, v13, v14);
        }
        v18 = *(_QWORD *)(a6 + 8 * v16);
        v19 = *(_QWORD *)(a6 + 8 * v17);
        v20 = "%s: %s => %s (%#x, %#x, %#x)";
        goto LABEL_15;
      }
      v21 = BYTE2(v12);
      v22 = BYTE1(v12);
      if ( (unsigned int)v21 < a7 && v22 < a9 )
      {
        v23 = *(_QWORD *)(a6 + 8 * v21);
        v19 = *(_QWORD *)(a8 + 8LL * v22);
        v20 = "%s: %s < %s (%#x, %#x, %#x)";
        v24 = a5;
        v25 = v23;
        return dbglog_printf(result, a2, v20, v24, v25, v19, v11, v13, v14);
      }
      v20 = "%s: %u < %u (%#x, %#x, %#x)";
      v24 = a5;
      v25 = (unsigned int)v21;
    }
    v19 = v22;
    return dbglog_printf(result, a2, v20, v24, v25, v19, v11, v13, v14);
  }
  return result;
}
