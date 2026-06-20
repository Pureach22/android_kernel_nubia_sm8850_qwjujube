__int64 __fastcall sub_3B9768(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v5; // s9
  int v6; // s21

  *(_DWORD *)(a4 + 24) = v6;
  *(_DWORD *)(a4 + 28) = v5;
  return lim_prepare_disconnect_done_ind(a1, a2, a3, a4, a5);
}
