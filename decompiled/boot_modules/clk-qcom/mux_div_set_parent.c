__int64 __fastcall mux_div_set_parent(__int64 a1, unsigned __int8 a2)
{
  return mux_div_set_src_div(
           (unsigned int *)(a1 - 40),
           *(_DWORD *)(*(_QWORD *)(a1 - 8) + 4LL * a2),
           *(_DWORD *)(a1 - 20));
}
