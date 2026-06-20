__int64 __fastcall poll_for_remote_response(__int64 a1, int a2)
{
  int v2; // w10
  int v3; // w20
  int v5; // w21
  __int64 v6; // x22
  int v7; // w8
  __int64 v9; // x9
  __int64 v10; // x19
  __int64 v11; // x20
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x1
  unsigned __int64 v15; // x21
  __int64 v16; // x0
  __int64 v17; // x9
  _QWORD *v18; // x10
  int v19; // w9

  if ( !a2 )
    return 4294967291LL;
  v2 = *(_DWORD *)(a1 + 36);
  v3 = a2;
  v5 = 0;
  v6 = *(_QWORD *)(a1 + 192)
     + 16LL * *(int *)(a1 + 16)
     + 8LL * *(int *)(a1 + 16)
     + 16LL * BYTE2(v2)
     + 16LL * BYTE1(v2)
     + 16LL * (((unsigned __int8)v2 >> 4) + (v2 & 0xFu));
  while ( 1 )
  {
    v7 = *(_DWORD *)(v6 + 384);
    if ( v7 == -1413689890 )
      return 0;
    if ( v7 == 912559 )
      break;
    if ( v5 == 500 )
    {
      __dsb(0xDu);
      v5 = 0;
    }
    _const_udelay(4295);
    --v3;
    ++v5;
    if ( !v3 )
      return 4294967291LL;
  }
  v9 = *(_QWORD *)(a1 + 184);
  *(_DWORD *)(a1 + 24) = 0;
  *(_BYTE *)(a1 + 96) = 1;
  v10 = *(_QWORD *)(a1 + 152);
  v11 = *(_QWORD *)(v9 + 128);
  v12 = ktime_get_with_offset(1);
  v13 = ns_to_timespec64(v12);
  if ( v13 <= 0x225C17D03LL )
  {
    if ( v13 >= (__int64)0xFFFFFFFDDA3E82FDLL )
      v15 = v14 + 1000000000 * v13;
    else
      v15 = 0x8000000000000000LL;
  }
  else
  {
    v15 = 0x7FFFFFFFFFFFFFFFLL;
  }
  v16 = raw_spin_lock_irqsave(v11 + 64036);
  v17 = *(unsigned int *)(v11 + 52764);
  if ( (unsigned int)v17 < 0x81 )
  {
    v18 = (_QWORD *)(v11 + 32 * v17 + 59936);
    if ( (unsigned int)v17 <= 0x7E )
      v19 = v17 + 1;
    else
      v19 = 0;
    *v18 = v10;
    v18[1] = 0x500000000LL;
    v18[2] = 0x200000000LL;
    v18[3] = v15;
    *(_DWORD *)(v11 + 52764) = v19;
    raw_spin_unlock_irqrestore(v11 + 64036, v16);
    return 0;
  }
  __break(0x5512u);
  return inline_copy_to_user(v16);
}
