__int64 __fastcall wlan_hdd_update_pause_time(__int64 result, unsigned int a2, char a3)
{
  __int64 v3; // x12
  unsigned int v4; // w8
  __int64 v5; // x9

  v3 = *(_QWORD *)(result + 42120);
  v4 = 0;
  v5 = jiffies - *(_QWORD *)(result + 42112);
  *(_QWORD *)(result + 42112) = jiffies;
  *(_QWORD *)(result + 42120) = v3 + v5;
  while ( ((a2 >> v4) & 1) == 0 )
  {
    if ( v4 > 0x10 )
      return result;
LABEL_3:
    ++v4;
  }
  *(_QWORD *)(result + 51744 + 16LL * v4 + 8) += v5;
  if ( v4 <= 0x10 && (a3 & 1) == 0 )
    goto LABEL_3;
  return result;
}
