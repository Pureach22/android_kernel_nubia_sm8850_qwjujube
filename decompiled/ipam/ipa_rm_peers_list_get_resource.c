__int64 __fastcall ipa_rm_peers_list_get_resource(unsigned int a1, __int64 a2)
{
  __int64 result; // x0

  result = 0;
  if ( (a1 & 0x80000000) == 0 && *(_DWORD *)(a2 + 8) >= (signed int)a1 )
    return *(_QWORD *)(*(_QWORD *)a2 + 16LL * a1);
  return result;
}
