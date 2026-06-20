__int64 __fastcall ipa_rm_peers_list_add_peer(__int64 result, unsigned int *a2, char a3)
{
  __int64 v3; // x19
  __int64 v4; // x0
  char v5; // w20
  __int64 v6; // x21
  unsigned int *v7; // x22
  int v8; // w0
  int v9; // w8
  __int64 v10; // x21
  int v11; // w8

  if ( result && a2 )
  {
    v3 = result;
    v4 = *a2;
    v5 = a3 & 1;
    v6 = *(_QWORD *)v3;
    if ( (unsigned int)v4 > 0x15 || (v4 & 1) != 0 )
    {
      v9 = -1;
      if ( (v4 & 1) == 0 || (unsigned int)v4 > 0x15 )
      {
LABEL_10:
        *(_QWORD *)(v6 + 16LL * v9) = a2;
        result = *a2;
        v10 = *(_QWORD *)v3;
        if ( (unsigned int)result > 0x15 || (result & 1) != 0 )
        {
          v11 = -1;
          if ( (result & 1) == 0 || (unsigned int)result > 0x15 )
            goto LABEL_17;
          result = ipa_rm_cons_index(result);
        }
        else
        {
          result = ipa_rm_prod_index(result);
        }
        v11 = result;
LABEL_17:
        *(_BYTE *)(v10 + 16LL * v11 + 8) = v5;
        ++*(_DWORD *)(v3 + 12);
        return result;
      }
      v7 = a2;
      v8 = ipa_rm_cons_index(v4);
    }
    else
    {
      v7 = a2;
      v8 = ipa_rm_prod_index(v4);
    }
    a2 = v7;
    v9 = v8;
    goto LABEL_10;
  }
  return result;
}
