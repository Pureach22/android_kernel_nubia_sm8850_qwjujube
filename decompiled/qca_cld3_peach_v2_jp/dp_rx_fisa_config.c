__int64 __fastcall dp_rx_fisa_config(
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
  char v10; // w20
  int v11; // w8
  __int64 v12; // x0
  __int64 v13; // x8
  _DWORD *v14; // x8
  __int64 result; // x0
  unsigned __int64 *v16; // [xsp+0h] [xbp-20h] BYREF
  unsigned __int64 v17; // [xsp+8h] [xbp-18h] BYREF
  __int64 v18; // [xsp+10h] [xbp-10h]
  __int64 v19; // [xsp+18h] [xbp-8h]

  v10 = 15;
  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(unsigned __int8 *)(a1 + 1499);
  v17 = 0xFFFFFFFF00000000LL;
  LODWORD(v18) = 0;
  if ( v11 == 1 )
  {
    if ( (unsigned int)hal_get_target_type(*(__int64 **)(a1 + 256)) == 38 )
      v10 = 31;
    else
      v10 = 15;
  }
  v12 = *(_QWORD *)(a1 + 240);
  LOBYTE(v18) = v10;
  v16 = &v17;
  if ( !v12 || !*(_QWORD *)v12 )
  {
    qdf_trace_msg(
      0x89u,
      8u,
      "%s: Invalid Instance:",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "cdp_txrx_fisa_config",
      v16,
      v17,
      v18,
      v19);
LABEL_13:
    result = 16;
    goto LABEL_14;
  }
  v13 = *(_QWORD *)(*(_QWORD *)v12 + 8LL);
  if ( !v13 )
    goto LABEL_13;
  v14 = *(_DWORD **)(v13 + 240);
  if ( !v14 )
    goto LABEL_13;
  if ( *(v14 - 1) != -1978174150 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, unsigned __int64 **))v14)(v12, 0, 0, &v16);
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
