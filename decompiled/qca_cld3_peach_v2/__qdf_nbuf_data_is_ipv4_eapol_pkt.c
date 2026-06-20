bool __fastcall _qdf_nbuf_data_is_ipv4_eapol_pkt(__int64 a1)
{
  int v1; // w8
  __int64 v3; // x8

  v1 = *(unsigned __int16 *)(a1 + 12);
  if ( v1 == 129 )
  {
    v3 = 16;
LABEL_6:
    v1 = *(unsigned __int16 *)(a1 + v3);
    return v1 == 36488;
  }
  if ( v1 == 43144 )
  {
    v3 = 20;
    goto LABEL_6;
  }
  return v1 == 36488;
}
