__int64 __fastcall csr_get_config_param(__int64 a1, __int64 a2)
{
  __int64 v2; // x11
  int v3; // w11
  __int64 v5; // x11
  int v6; // w8
  unsigned __int64 v7; // x8
  int *v8; // x12
  _BYTE *v9; // x13
  __int64 v10; // x15
  int v11; // w16
  int v12; // t1
  unsigned __int64 v13; // x15

  if ( !a2 )
    return 4;
  *(_DWORD *)(a2 + 1244) = *(_DWORD *)(a1 + 17164);
  *(_DWORD *)(a2 + 16) = *(_DWORD *)(a1 + 17140);
  *(_BYTE *)(a2 + 20) = *(_BYTE *)(a1 + 17144);
  v2 = *(unsigned int *)(a1 + 17120);
  if ( (unsigned int)v2 > 0xA )
    v3 = 11;
  else
    v3 = dword_A17500[v2];
  *(_DWORD *)a2 = v3;
  v5 = *(unsigned int *)(a1 + 17124);
  if ( (unsigned int)v5 > 0xA )
    v6 = 11;
  else
    v6 = dword_A17500[v5];
  *(_DWORD *)(a2 + 4) = v6;
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(a1 + 17128);
  *(_DWORD *)(a2 + 12) = *(_DWORD *)(a1 + 17136);
  *(_BYTE *)(a2 + 21) = *(_BYTE *)(a1 + 17145);
  *(_BYTE *)(a2 + 1232) = *(_BYTE *)(a1 + 17112);
  *(_BYTE *)(a2 + 22) = *(_BYTE *)(a1 + 17146);
  *(_BYTE *)(a2 + 25) = *(_BYTE *)(a1 + 17149);
  *(_BYTE *)(a2 + 1234) = *(_BYTE *)(a1 + 17157);
  *(_BYTE *)(a2 + 1248) = *(_BYTE *)(a1 + 17168);
  if ( *(_BYTE *)(a1 + 16532) )
  {
    v7 = 0;
    v8 = (int *)(a1 + 15340);
    v9 = (_BYTE *)(a2 + 437);
    while ( v7 != 100 )
    {
      v10 = 4 * v7++;
      v11 = *(_DWORD *)(a1 + 16536 + v10);
      *(_DWORD *)(a2 + v10 + 32) = v11;
      *(_DWORD *)(v9 - 5) = v11;
      *(v9 - 1) = 1;
      v12 = *v8;
      v8 += 3;
      *v9 = v12;
      v9 += 8;
      v13 = *(unsigned __int8 *)(a1 + 16532);
      if ( v7 >= v13 )
        goto LABEL_15;
    }
    __break(0x5512u);
    return csr_prune_channel_list_for_mode(a1, a2);
  }
  else
  {
    LOBYTE(v13) = 0;
LABEL_15:
    *(_BYTE *)(a2 + 28) = v13;
    *(_BYTE *)(a2 + 1235) = *(_BYTE *)(a1 + 17158);
    *(_BYTE *)(a2 + 1236) = *(_BYTE *)(a1 + 17159);
    *(_BYTE *)(a2 + 1237) = *(_BYTE *)(a1 + 17160);
    *(_BYTE *)(a2 + 1238) = *(_BYTE *)(a1 + 17161);
    *(_BYTE *)(a2 + 1239) = *(_BYTE *)(a1 + 13008);
    *(_DWORD *)(a2 + 1240) = *(_DWORD *)(a1 + 21508);
    *(_BYTE *)(a2 + 1233) = *(_BYTE *)(a1 + 17156);
    return 0;
  }
}
