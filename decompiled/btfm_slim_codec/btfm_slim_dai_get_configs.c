__int64 __fastcall btfm_slim_dai_get_configs(__int64 a1, __int64 a2, unsigned __int8 a3)
{
  __int64 v3; // x9
  char v4; // w8
  __int64 v5; // x9
  __int64 v6; // x10

  v3 = *(_QWORD *)(*(_QWORD *)a1 + 152LL);
  *(_BYTE *)a2 = a3;
  *(_DWORD *)(a2 + 4) = *(_DWORD *)(v3 + 1128);
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(v3 + 1084);
  v4 = usecase_codec;
  *(_BYTE *)(a2 + 12) = *(_DWORD *)(v3 + 1088);
  *(_BYTE *)(a2 + 15) = v4;
  *(_WORD *)(a2 + 16) = *(_WORD *)(v3 + 1092);
  if ( a3 < 2u )
  {
    if ( a3 )
    {
      v5 = *(_QWORD *)(v3 + 1104);
      v6 = a3;
      goto LABEL_8;
    }
    return 1;
  }
  else
  {
    if ( (unsigned int)a3 - 2 > 1 )
      v5 = 0;
    else
      v5 = *(_QWORD *)(v3 + 1096);
    v6 = a3;
LABEL_8:
    while ( *(_DWORD *)v5 != a3 )
    {
      --v6;
      v5 += 72;
      if ( !v6 )
        return 1;
    }
    *(_BYTE *)(a2 + 13) = 1;
    *(_BYTE *)(a2 + 14) = *(_BYTE *)(v5 + 18);
    return 1;
  }
}
