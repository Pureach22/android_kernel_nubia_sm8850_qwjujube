__int64 __fastcall scheduler_timer_q_mq_handler(__int64 a1)
{
  __int64 context; // x0
  unsigned int v3; // w8
  unsigned int (__fastcall *v4)(_QWORD); // x8

  context = scheduler_get_context(a1);
  v3 = 16;
  if ( a1 && context )
  {
    if ( *(__int16 *)(a1 + 2) == -1330 && !*(_WORD *)a1 )
    {
      v4 = *(unsigned int (__fastcall **)(_QWORD))(a1 + 16);
      if ( !v4 )
        return 16;
    }
    else
    {
      v4 = *(unsigned int (__fastcall **)(_QWORD))(context + 704);
    }
    if ( *((_DWORD *)v4 - 1) != 1685785071 )
      __break(0x8228u);
    return v4(a1);
  }
  return v3;
}
