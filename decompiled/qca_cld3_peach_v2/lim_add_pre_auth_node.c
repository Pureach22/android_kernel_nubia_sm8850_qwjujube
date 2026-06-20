__int64 __fastcall lim_add_pre_auth_node(__int64 result, _QWORD *a2)
{
  __int64 v2; // x9

  v2 = *(_QWORD *)(result + 11424);
  ++*(_DWORD *)(result + 11404);
  *a2 = v2;
  *(_QWORD *)(result + 11424) = a2;
  return result;
}
