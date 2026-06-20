__int64 __fastcall extract_ani_level_tlv(
        __int64 *a1,
        __int64 *a2,
        _DWORD *a3,
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
  const char *v13; // x2
  __int64 v17; // x0
  int v18; // w10
  _DWORD *v19; // x11
  __int64 v20; // x12
  int v21; // w14

  if ( !a1 )
  {
    v13 = "%s: Invalid ani level event buffer";
    goto LABEL_7;
  }
  v11 = *a1;
  if ( !*a1 )
  {
    v13 = "%s: Invalid fixed param";
    goto LABEL_7;
  }
  v12 = *((unsigned int *)a1 + 6);
  *a3 = v12;
  if ( (unsigned int)v12 > 0x14 )
  {
    v13 = "%s: Invalid number of freqs received";
LABEL_7:
    qdf_trace_msg(0x31u, 2u, v13, a4, a5, a6, a7, a8, a9, a10, a11, "extract_ani_level_tlv");
    return 4;
  }
  v17 = _qdf_mem_malloc(8 * v12, "extract_ani_level_tlv", 20803);
  *a2 = v17;
  if ( !v17 )
    return 2;
  if ( *((_DWORD *)a1 + 6) )
  {
    v18 = 0;
    v19 = (_DWORD *)(v11 + 16);
    do
    {
      v20 = 8LL * (unsigned __int8)v18++;
      *(_DWORD *)(*a2 + v20 + 4) = *v19;
      v21 = *(v19 - 1);
      v19 += 3;
      *(_DWORD *)(*a2 + v20) = v21;
    }
    while ( *((_DWORD *)a1 + 6) > (unsigned int)(unsigned __int8)v18 );
  }
  return 0;
}
