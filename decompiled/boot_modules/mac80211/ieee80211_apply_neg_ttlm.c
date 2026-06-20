__int64 __fastcall ieee80211_apply_neg_ttlm(__int64 a1, unsigned __int16 *a2)
{
  int v4; // w8
  int v5; // w10
  int v6; // w9
  __int64 result; // x0
  __int64 v8; // x11
  __int64 v9; // x10
  __int64 v10; // x12
  __int64 v11; // x9

  v4 = a2[7]
     | a2[6]
     | a2[13]
     | a2[14]
     | a2[15]
     | a2[5]
     | a2[4]
     | a2[11]
     | a2[12]
     | a2[3]
     | a2[2]
     | a2[10]
     | a2[1]
     | a2[9]
     | *a2
     | a2[8];
  if ( (*(_BYTE *)(a1 + 5840) & 1) != 0 )
  {
    v5 = *(unsigned __int16 *)(a1 + 5804);
    v6 = v5 & ~*(unsigned __int16 *)(a1 + 5806);
    *(_WORD *)(a1 + 5804) = v5 & ~*(_WORD *)(a1 + 5806);
  }
  else
  {
    v6 = *(unsigned __int16 *)(a1 + 5804);
  }
  result = ieee80211_ttlm_set_links(
             a1,
             v4 & ~v6 & (unsigned int)*(unsigned __int16 *)(a1 + 5800),
             *(unsigned __int16 *)(a1 + 5800) & ~(v6 | v4) | (unsigned int)v6);
  if ( !(_DWORD)result )
  {
    v8 = *((_QWORD *)a2 + 1);
    v10 = *((_QWORD *)a2 + 2);
    v9 = *((_QWORD *)a2 + 3);
    *(_WORD *)(a1 + 5840) = a2[16];
    v11 = *(_QWORD *)a2;
    *(_QWORD *)(a1 + 5824) = v10;
    *(_QWORD *)(a1 + 5832) = v9;
    *(_QWORD *)(a1 + 5808) = v11;
    *(_QWORD *)(a1 + 5816) = v8;
    *(_BYTE *)(a1 + 5840) = 1;
  }
  return result;
}
