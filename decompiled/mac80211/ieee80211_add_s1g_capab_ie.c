__int64 __fastcall ieee80211_add_s1g_capab_ie(__int64 result, _BYTE *a2, __int64 a3)
{
  char v3; // w24
  char v4; // w25
  char v5; // w26
  char v6; // w27
  char v7; // w28
  char v8; // w19
  char v9; // w20
  char v10; // w21
  char v11; // w22
  char v12; // w23
  char v13; // [xsp+Ch] [xbp-74h]
  char v14; // [xsp+10h] [xbp-70h]
  char v15; // [xsp+14h] [xbp-6Ch]
  char v16; // [xsp+18h] [xbp-68h]
  char v17; // [xsp+1Ch] [xbp-64h]

  if ( *(_DWORD *)(result + 4720) == 2 )
  {
    if ( *a2 == 1 )
    {
      v17 = *(_BYTE *)(result + 2612) & *(_BYTE *)(result + 2627) | a2[1] & ~*(_BYTE *)(result + 2627);
      v16 = *(_BYTE *)(result + 2613) & *(_BYTE *)(result + 2628) | a2[2] & ~*(_BYTE *)(result + 2628);
      v15 = *(_BYTE *)(result + 2614) & *(_BYTE *)(result + 2629) | a2[3] & ~*(_BYTE *)(result + 2629);
      v14 = *(_BYTE *)(result + 2615) & *(_BYTE *)(result + 2630) | a2[4] & ~*(_BYTE *)(result + 2630);
      v13 = *(_BYTE *)(result + 2616) & *(_BYTE *)(result + 2631) | a2[5] & ~*(_BYTE *)(result + 2631);
      v3 = *(_BYTE *)(result + 2617) & *(_BYTE *)(result + 2632) | a2[6] & ~*(_BYTE *)(result + 2632);
      v4 = *(_BYTE *)(result + 2618) & *(_BYTE *)(result + 2633) | a2[7] & ~*(_BYTE *)(result + 2633);
      v5 = *(_BYTE *)(result + 2619) & *(_BYTE *)(result + 2634) | a2[8] & ~*(_BYTE *)(result + 2634);
      v6 = *(_BYTE *)(result + 2620) & *(_BYTE *)(result + 2635) | a2[9] & ~*(_BYTE *)(result + 2635);
      v7 = *(_BYTE *)(result + 2621) & *(_BYTE *)(result + 2636) | a2[10] & ~*(_BYTE *)(result + 2636);
      v8 = *(_BYTE *)(result + 2622) & *(_BYTE *)(result + 2637) | a2[11] & ~*(_BYTE *)(result + 2637);
      v9 = *(_BYTE *)(result + 2623) & *(_BYTE *)(result + 2638) | a2[12] & ~*(_BYTE *)(result + 2638);
      v10 = *(_BYTE *)(result + 2624) & *(_BYTE *)(result + 2639) | a2[13] & ~*(_BYTE *)(result + 2639);
      v11 = *(_BYTE *)(result + 2625) & *(_BYTE *)(result + 2640) | a2[14] & ~*(_BYTE *)(result + 2640);
      v12 = *(_BYTE *)(result + 2626) & *(_BYTE *)(result + 2641) | a2[15] & ~*(_BYTE *)(result + 2641);
      result = skb_put(a3, 17);
      *(_BYTE *)(result + 7) = v3;
      *(_WORD *)result = 4057;
      *(_BYTE *)(result + 8) = v4;
      *(_BYTE *)(result + 9) = v5;
      *(_BYTE *)(result + 3) = v16;
      *(_BYTE *)(result + 2) = v17;
      *(_BYTE *)(result + 4) = v15;
      *(_BYTE *)(result + 10) = v6;
      *(_BYTE *)(result + 11) = v7;
      *(_BYTE *)(result + 5) = v14;
      *(_BYTE *)(result + 6) = v13;
      *(_BYTE *)(result + 12) = v8;
      *(_BYTE *)(result + 13) = v9;
      *(_BYTE *)(result + 14) = v10;
      *(_BYTE *)(result + 15) = v11;
      *(_BYTE *)(result + 16) = v12;
    }
  }
  else
  {
    __break(0x800u);
  }
  return result;
}
