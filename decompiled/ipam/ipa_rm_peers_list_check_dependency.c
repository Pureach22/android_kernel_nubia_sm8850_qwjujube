__int64 __fastcall ipa_rm_peers_list_check_dependency(
        _QWORD *a1,
        unsigned int a2,
        _QWORD *a3,
        unsigned int a4,
        _BYTE *a5)
{
  __int64 result; // x0
  unsigned int v9; // w22
  int v10; // w0
  __int64 v11; // x8
  unsigned int v12; // w21
  int v13; // w0
  int v14; // w8
  __int64 v15; // x8

  result = 0;
  if ( a1 && a3 && a5 )
  {
    if ( a4 > 0x15 || (a4 & 1) != 0 )
    {
      v10 = -1;
      if ( (a4 & 1) == 0 || a4 > 0x15 )
      {
LABEL_11:
        v11 = *a1 + 16LL * v10;
        result = *(_QWORD *)v11 != 0;
        if ( *(_QWORD *)v11 )
          *a5 = *(_BYTE *)(v11 + 8);
        if ( a2 > 0x15 || (a2 & 1) != 0 )
        {
          v14 = -1;
          if ( (a2 & 1) == 0 || a2 > 0x15 )
            goto LABEL_20;
          v12 = result;
          v13 = ipa_rm_cons_index(a2);
        }
        else
        {
          v12 = result;
          v13 = ipa_rm_prod_index(a2);
        }
        v14 = v13;
        result = v12;
LABEL_20:
        v15 = *a3 + 16LL * v14;
        if ( *(_QWORD *)v15 )
        {
          *a5 = *(_BYTE *)(v15 + 8);
          return 1;
        }
        return result;
      }
      v9 = a2;
      v10 = ipa_rm_cons_index(a4);
    }
    else
    {
      v9 = a2;
      v10 = ipa_rm_prod_index(a4);
    }
    a2 = v9;
    goto LABEL_11;
  }
  return result;
}
