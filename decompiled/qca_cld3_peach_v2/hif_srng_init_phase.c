__int64 __fastcall hif_srng_init_phase(__int64 a1, char a2)
{
  __int64 result; // x0

  result = ce_srng_based(a1);
  if ( (result & 1) != 0 )
    return hal_set_init_phase(*(_QWORD *)(a1 + 2560), a2 & 1);
  return result;
}
