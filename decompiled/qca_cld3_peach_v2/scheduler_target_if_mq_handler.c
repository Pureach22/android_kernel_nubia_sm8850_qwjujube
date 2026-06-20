__int64 __fastcall scheduler_target_if_mq_handler(__int64 a1)
{
  __int64 context; // x0
  unsigned int v3; // w9
  unsigned int (__fastcall *v4)(_QWORD); // x9

  context = scheduler_get_context(a1);
  v3 = 16;
  if ( a1 && context )
  {
    v4 = *(unsigned int (__fastcall **)(_QWORD))(a1 + 16);
    if ( !v4 )
      v4 = *(unsigned int (__fastcall **)(_QWORD))(context + 696);
    if ( *((_DWORD *)v4 - 1) != 1685785071 )
      __break(0x8229u);
    return v4(a1);
  }
  return v3;
}
