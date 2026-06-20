bool __fastcall sme_is_lim_session_valid(__int64 a1, unsigned __int8 a2)
{
  return *(unsigned __int16 *)(a1 + 3992) >= (unsigned int)a2
      && *(_BYTE *)(*(_QWORD *)(a1 + 12264) + 14000LL * a2 + 70) != 0;
}
