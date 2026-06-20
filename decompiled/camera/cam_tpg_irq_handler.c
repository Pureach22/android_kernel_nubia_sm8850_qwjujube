__int64 __fastcall cam_tpg_irq_handler(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 (__fastcall *v4)(_QWORD); // x8

  v2 = *(_QWORD *)(a2 + 4600);
  if ( !v2 )
    return 0;
  v3 = *(_QWORD *)(v2 + 16);
  if ( !v3 )
    return 0;
  v4 = *(__int64 (__fastcall **)(_QWORD))(v3 + 72);
  if ( !v4 )
    return 0;
  if ( *((_DWORD *)v4 - 1) != 543625848 )
    __break(0x8228u);
  return v4(a2 + 4568);
}
