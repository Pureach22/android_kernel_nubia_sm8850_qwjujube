__int64 __fastcall sme_set_bss_max_idle_period(__int64 result, unsigned __int16 a2)
{
  *(_DWORD *)(*(_QWORD *)(result + 8) + 3304LL) = a2;
  return result;
}
