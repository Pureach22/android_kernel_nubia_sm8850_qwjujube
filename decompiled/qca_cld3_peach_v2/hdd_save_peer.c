__int64 __fastcall hdd_save_peer(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int64 v11; // x8
  __int64 v12; // x21
  char v13; // w20
  bool v14; // cf
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x7
  int v19; // w9

  v11 = 0;
  v12 = a1 + 276;
  v13 = 1;
  _ReadStatusReg(SP_EL0);
  while ( *(_DWORD *)v12 | *(unsigned __int16 *)(v12 + 4) )
  {
    v14 = v11++ >= 0x1F;
    v12 += 6;
    v13 = !v14;
    if ( v11 == 32 )
      goto LABEL_12;
  }
  if ( a2 )
  {
    v15 = *a2;
    v16 = a2[1];
    v17 = a2[2];
    v18 = a2[5];
  }
  else
  {
    v17 = 0;
    v15 = 0;
    v16 = 0;
    v18 = 0;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: adding peer: %02x:%02x:%02x:**:**:%02x at idx: %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "hdd_save_peer",
    v15,
    v16,
    v17,
    v18,
    v11);
  v19 = *(_DWORD *)a2;
  *(_WORD *)(v12 + 4) = *((_WORD *)a2 + 2);
  *(_DWORD *)v12 = v19;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return v13 & 1;
}
