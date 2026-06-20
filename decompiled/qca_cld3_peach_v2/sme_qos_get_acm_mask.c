__int64 __fastcall sme_qos_get_acm_mask(__int64 a1, __int64 a2, __int64 a3)
{
  int v6; // w22
  int v7; // w8
  int v8; // w22
  int v9; // w8

  if ( (sme_qos_is_acm(a1, a2, 0, a3) & 1) != 0 )
    v6 = 8;
  else
    v6 = 0;
  if ( (sme_qos_is_acm(a1, a2, 1, a3) & 1) != 0 )
    v7 = 4;
  else
    v7 = 0;
  v8 = v7 | v6;
  if ( (sme_qos_is_acm(a1, a2, 2, a3) & 1) != 0 )
    v9 = 2;
  else
    v9 = 0;
  return (v9 | v8) & 0xFFFFFFFE | sme_qos_is_acm(a1, a2, 3, a3) & 1;
}
