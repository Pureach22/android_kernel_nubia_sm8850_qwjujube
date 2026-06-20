__int64 __fastcall target_if_get_active_mac_phy_number(
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
  __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x10
  __int64 result; // x0
  unsigned int v13; // w11
  unsigned int v14; // w12
  unsigned int *v15; // x13
  __int64 v16; // x15
  unsigned int v17; // w16
  unsigned int v18; // w17
  unsigned int v19; // w16
  unsigned int v20; // w17
  __int64 v21; // x9
  unsigned int *v22; // x8
  unsigned int v23; // t1
  unsigned int v24; // w11

  if ( !a1 || (v9 = *(_QWORD *)(a1 + 2800)) == 0 )
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: invalid psoc info",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_get_active_mac_phy_number");
    return 0;
  }
  v10 = *(unsigned __int8 *)(v9 + 5652);
  if ( !*(_BYTE *)(v9 + 5652) )
    return 0;
  if ( (unsigned int)(v10 - 12) < 0xFFFFFFF5 )
  {
    __break(0x5512u);
    return target_if_peer_set_default_routing();
  }
  if ( (_DWORD)v10 == 1 )
  {
    v11 = 0;
    LODWORD(result) = 0;
LABEL_20:
    v21 = v10 - v11;
    v22 = (unsigned int *)(v9 + 4 * v11 + 5700);
    do
    {
      v23 = *v22++;
      v24 = (16843009
           * ((((v23 - ((v23 >> 1) & 0x55555555)) & 0x33333333)
             + (((v23 - ((v23 >> 1) & 0x55555555)) >> 2) & 0x33333333)
             + ((((v23 - ((v23 >> 1) & 0x55555555)) & 0x33333333)
               + (((v23 - ((v23 >> 1) & 0x55555555)) >> 2) & 0x33333333)) >> 4))
            & 0xF0F0F0F)) >> 24;
      if ( v24 <= (unsigned int)result )
        result = (unsigned int)result;
      else
        result = v24;
      --v21;
    }
    while ( v21 );
    return result;
  }
  v11 = (unsigned __int8)v10 & 0xFE;
  v13 = 0;
  v14 = 0;
  v15 = (unsigned int *)(v9 + 5704);
  v16 = v11;
  do
  {
    v17 = *(v15 - 1);
    v18 = *v15;
    v15 += 2;
    v19 = (16843009
         * ((((v17 - ((v17 >> 1) & 0x55555555)) & 0x33333333)
           + (((v17 - ((v17 >> 1) & 0x55555555)) >> 2) & 0x33333333)
           + ((((v17 - ((v17 >> 1) & 0x55555555)) & 0x33333333) + (((v17 - ((v17 >> 1) & 0x55555555)) >> 2) & 0x33333333)) >> 4))
          & 0xF0F0F0F)) >> 24;
    v20 = (16843009
         * ((((v18 - ((v18 >> 1) & 0x55555555)) & 0x33333333)
           + (((v18 - ((v18 >> 1) & 0x55555555)) >> 2) & 0x33333333)
           + ((((v18 - ((v18 >> 1) & 0x55555555)) & 0x33333333) + (((v18 - ((v18 >> 1) & 0x55555555)) >> 2) & 0x33333333)) >> 4))
          & 0xF0F0F0F)) >> 24;
    if ( v19 > v13 )
      v13 = v19;
    if ( v20 > v14 )
      v14 = v20;
    v16 -= 2;
  }
  while ( v16 );
  if ( v13 <= v14 )
    result = v14;
  else
    result = v13;
  if ( v11 != v10 )
    goto LABEL_20;
  return result;
}
