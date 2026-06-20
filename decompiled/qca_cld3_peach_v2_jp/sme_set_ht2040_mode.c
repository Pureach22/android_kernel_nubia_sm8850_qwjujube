__int64 __fastcall sme_set_ht2040_mode(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  __int64 v13; // x23
  int v14; // w20
  unsigned int v17; // w19
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w20
  __int64 result; // x0
  unsigned int v28; // w19

  if ( !a1 || a2 > 5u || (v12 = *(_QWORD *)(a1 + 17224)) == 0 || (v13 = v12 + 96LL * a2, (*(_BYTE *)(v13 + 1) & 1) == 0) )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Session not valid for session id %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "sme_set_ht2040_mode",
      a2);
    return 4;
  }
  v14 = a3;
  v17 = a2;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: Update HT operation beacon IE, channel_type=%d cur cbmode %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "sme_set_ht2040_mode",
    a3,
    *(unsigned int *)(v13 + 44));
  if ( v14 == 3 )
  {
    if ( !*(_DWORD *)(v13 + 44) )
    {
      v26 = 1;
LABEL_18:
      *(_DWORD *)(v13 + 44) = v26;
      result = qdf_mutex_acquire(a1 + 12776);
      if ( !(_DWORD)result )
      {
        v28 = csr_set_ht2040_mode(a1, v17, v26, a4 & 1);
        qdf_mutex_release(a1 + 12776);
        return v28;
      }
      return result;
    }
    return 0;
  }
  if ( v14 == 2 )
  {
    if ( !*(_DWORD *)(v13 + 44) )
    {
      v26 = 3;
      goto LABEL_18;
    }
    return 0;
  }
  if ( v14 != 1 )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Error!!! Invalid HT20/40 mode !",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "sme_set_ht2040_mode");
    return 16;
  }
  v26 = 0;
  result = 0;
  if ( *(_DWORD *)(v13 + 44) )
    goto LABEL_18;
  return result;
}
