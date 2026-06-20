__int64 __fastcall pmic_arb_ppid_to_apid_v1(_QWORD *a1, unsigned __int16 a2)
{
  unsigned __int64 v3; // x21
  int v4; // w8
  __int64 v5; // x22
  unsigned int v7; // w8
  _QWORD *v8; // x23
  int v9; // w24
  __int64 v10; // x9
  __int64 v11; // x26
  __int64 result; // x0
  unsigned __int64 v19; // x10

  v3 = a2;
  v4 = *(__int16 *)(a1[17] + 2LL * a2);
  if ( v4 < 0 )
    return v4 & 0x7FFF;
  v5 = a1[8];
  v7 = 0;
  v8 = a1 + 9;
  v9 = 16;
  while ( 1 )
  {
    v10 = 1LL << v7;
    _X11 = &v8[v7 >> 6];
    __asm { PRFM            #0x11, [X11] }
    do
      v19 = __ldxr(_X11);
    while ( __stlxr(v19 | v10, _X11) );
    __dmb(0xBu);
    v11 = v7;
    if ( (v19 & v10) != 0 )
    {
      LODWORD(result) = *(_DWORD *)(v5 + 4LL * v7);
    }
    else
    {
      LODWORD(result) = readl_relaxed((unsigned int *)(a1[3] + 4 * v7 + 2816LL));
      *(_DWORD *)(v5 + 4 * v11) = result;
    }
    if ( ((v3 >> (((unsigned int)result >> 18) & 0xF)) & 1) == 0 )
      break;
    if ( (result & 0x100) == 0 )
    {
      *(_WORD *)(a1[17] + 2 * v3) = (unsigned __int8)result | 0x8000;
      *(_WORD *)(a1[19] + 4LL * (unsigned __int8)result) = a2;
      return (unsigned __int8)result;
    }
LABEL_4:
    --v9;
    v7 = (unsigned __int8)result;
    if ( !v9 )
      return 4294967277LL;
  }
  if ( (result & 0x20000) != 0 )
  {
    LODWORD(result) = (unsigned int)result >> 9;
    goto LABEL_4;
  }
  *(_WORD *)(a1[17] + 2 * v3) = (unsigned __int8)((unsigned int)result >> 9) | 0x8000;
  *(_WORD *)(a1[19] + 4LL * (unsigned __int8)((unsigned __int64)(unsigned int)result >> 9)) = a2;
  return (unsigned __int8)((unsigned int)result >> 9);
}
