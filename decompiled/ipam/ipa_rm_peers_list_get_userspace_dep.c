__int64 __fastcall ipa_rm_peers_list_get_userspace_dep(unsigned int a1, __int64 a2)
{
  char v2; // w8

  v2 = 0;
  if ( (a1 & 0x80000000) == 0 && *(_DWORD *)(a2 + 8) >= (signed int)a1 )
    v2 = *(_BYTE *)(*(_QWORD *)a2 + 16LL * a1 + 8);
  return v2 & 1;
}
