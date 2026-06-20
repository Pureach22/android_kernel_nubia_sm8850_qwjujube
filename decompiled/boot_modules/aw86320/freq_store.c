size_t __fastcall freq_store(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v4; // x21
  size_t v5; // x19
  __int64 v6; // x5
  __int64 v7; // x6
  __int64 v9; // x4
  unsigned int v10; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-18h] BYREF
  __int16 v12; // [xsp+10h] [xbp-10h]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = g_aw86320;
  v10 = 0;
  if ( a3 >= 9 )
    v5 = 9;
  else
    v5 = a3;
  v12 = 0;
  v11 = 0;
  _check_object_size(&v11, v5, 0);
  if ( (unsigned int)inline_copy_from_user((__int64)&v11, a2, v5) || (unsigned int)kstrtouint(&v11, 0, &v10) )
  {
    v5 = -22;
  }
  else
  {
    if ( v10 >= 0x1F4 )
      v9 = 500;
    else
      v9 = v10;
    *(_WORD *)(v4 + 20) = v9;
    printk(&unk_A31B, "aw86320", 1005, "freq_store", v9, v6, v7);
    if ( *(int *)(v4 + 16) >= 1 )
      aw86320_play_atsin0(*(_DWORD *)(v4 + 12), *(_DWORD *)(v4 + 8), *(unsigned __int16 *)(v4 + 20));
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
