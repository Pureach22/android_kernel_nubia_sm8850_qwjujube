__int64 __fastcall has_system_slept(_BYTE *a1)
{
  __int64 v2; // x8
  unsigned __int64 v3; // x9
  char v4; // w22
  char v5; // w23
  int v6; // w26
  char v7; // w27
  __int64 v8; // x20
  int v10; // [xsp+0h] [xbp-10h] BYREF
  unsigned __int8 v11; // [xsp+4h] [xbp-Ch]
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  v10 = 0;
  if ( *(_QWORD *)(*(_QWORD *)(drv + 8) + 24LL) )
  {
    v2 = b_system_stats;
    v3 = 0;
    v4 = 0;
    v5 = 0;
    v6 = 1;
    v7 = 1;
    do
    {
      v8 = 32 * v3;
      v10 = *(_DWORD *)(v2 + 32 * v3);
      strim(&v10);
      v2 = b_system_stats;
      if ( *(_DWORD *)(b_system_stats + v8 + 4) == *(_DWORD *)(a_system_stats + v8 + 4) )
      {
        printk(&unk_A291, &v10);
        v2 = b_system_stats;
        v7 = 0;
      }
      else
      {
        v4 |= (v10 ^ 0x64737863 | v11) == 0;
        v5 |= (v10 ^ 0x64736F61 | v11) == 0;
      }
      v3 = v6++;
    }
    while ( *(_QWORD *)(*(_QWORD *)(drv + 8) + 24LL) > v3 );
    if ( !(v5 & 1 | ((v4 & 1) == 0)) )
      *a1 = 1;
  }
  else
  {
    v7 = 1;
  }
  _ReadStatusReg(SP_EL0);
  return v7 & 1;
}
