__int64 __fastcall smp2p_irq_print_chip(__int64 a1, __int64 a2)
{
  const char **v2; // x8
  const char *v3; // x2

  v2 = **(const char ****)(*(_QWORD *)(a1 + 48) + 16LL);
  v3 = v2[14];
  if ( !v3 )
    v3 = *v2;
  return seq_printf(a2, " %8s", v3);
}
