__int64 __fastcall walt_giant_tasks(unsigned int a1)
{
  if ( a1 < 0x20 )
    return *(unsigned int *)((char *)&walt_rq + *((_QWORD *)&_per_cpu_offset + a1) + 32);
  __break(0x5512u);
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return trailblazer_on_prime();
}
