__int64 __fastcall hdd_any_valid_peer_present(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned __int64 v9; // x4
  unsigned __int8 *v10; // x8
  char v11; // w19
  bool v12; // cf
  __int64 v14; // x5
  __int64 v15; // x6
  __int64 v16; // x7

  v9 = 0;
  v10 = (unsigned __int8 *)(a1 + 356);
  v11 = 1;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    if ( *(_DWORD *)v10 | *((unsigned __int16 *)v10 + 2) )
    {
      if ( *(_DWORD *)v10 != -1 || *((__int16 *)v10 + 2) != -1 )
        break;
    }
    v12 = v9++ >= 0x1F;
    v10 += 6;
    v11 = !v12;
    if ( v9 == 32 )
      goto LABEL_15;
  }
  if ( v10 )
  {
    v14 = *v10;
    v15 = v10[1];
    v16 = v10[2];
    LODWORD(v10) = v10[5];
  }
  else
  {
    v16 = 0;
    v14 = 0;
    v15 = 0;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: peer: index: %u %02x:%02x:%02x:**:**:%02x",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "hdd_any_valid_peer_present",
    v9,
    v14,
    v15,
    v16,
    (_DWORD)v10);
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return v11 & 1;
}
