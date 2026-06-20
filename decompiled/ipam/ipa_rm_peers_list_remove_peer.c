__int64 __fastcall ipa_rm_peers_list_remove_peer(__int64 result, unsigned int a2)
{
  __int64 v2; // x21
  __int64 v3; // x19
  __int64 v5; // x21

  if ( result )
  {
    v2 = *(_QWORD *)result;
    v3 = result;
    if ( a2 > 0x15 || (a2 & 1) != 0 )
    {
      if ( (a2 & 1) != 0 && a2 < 0x16 )
      {
        *(_QWORD *)(v2 + 16LL * (int)ipa_rm_cons_index(a2)) = 0;
        v5 = *(_QWORD *)v3;
        result = ipa_rm_cons_index(a2);
      }
      else
      {
        *(_QWORD *)(v2 - 16) = 0;
        result = 0xFFFFFFFFLL;
        v5 = *(_QWORD *)v3;
      }
    }
    else
    {
      *(_QWORD *)(v2 + 16LL * (int)ipa_rm_prod_index(a2)) = 0;
      v5 = *(_QWORD *)v3;
      result = ipa_rm_prod_index(a2);
    }
    *(_BYTE *)(v5 + 16LL * (int)result + 8) = 0;
    --*(_DWORD *)(v3 + 12);
  }
  return result;
}
