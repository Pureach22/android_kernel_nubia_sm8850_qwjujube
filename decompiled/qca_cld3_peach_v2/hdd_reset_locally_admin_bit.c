__int64 __fastcall hdd_reset_locally_admin_bit(_BYTE *a1, _BYTE *a2)
{
  _BYTE *v2; // x20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  v2 = a1 + 3696;
  if ( !(unsigned int)qdf_mem_cmp(a2, a1 + 3696, 6u)
    || (v2 = a1 + 3704, !(unsigned int)qdf_mem_cmp(a2, a1 + 3704, 6u))
    || (v2 = a1 + 3712, !(unsigned int)qdf_mem_cmp(a2, a1 + 3712, 6u))
    || (v2 = a1 + 3720, !(unsigned int)qdf_mem_cmp(a2, a1 + 3720, 6u))
    || (v2 = a1 + 3728, !(unsigned int)qdf_mem_cmp(a2, a1 + 3728, 6u))
    || (v2 = a1 + 3736, !(unsigned int)qdf_mem_cmp(a2, a1 + 3736, 6u))
    || (v2 = a1 + 3744, !(unsigned int)qdf_mem_cmp(a2, a1 + 3744, 6u)) )
  {
    *v2 &= ~2u;
  }
  *a2 &= ~2u;
  return qdf_trace_msg(
           0x33u,
           8u,
           "%s: locally administered bit reset in sta mode: %02x:%02x:%02x:**:**:%02x",
           v5,
           v6,
           v7,
           v8,
           v9,
           v10,
           v11,
           v12,
           "hdd_reset_locally_admin_bit");
}
