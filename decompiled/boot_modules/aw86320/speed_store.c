size_t __fastcall speed_store(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v4; // x21
  size_t v5; // x19
  __int64 v6; // x5
  __int64 v7; // x6
  __int64 v9; // x6
  __int64 v11; // x4
  __int64 v12; // x5
  unsigned int v13; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-18h] BYREF
  __int16 v15; // [xsp+10h] [xbp-10h]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = g_aw86320;
  v13 = 0;
  if ( a3 >= 9 )
    v5 = 9;
  else
    v5 = a3;
  v15 = 0;
  v14 = 0;
  _check_object_size(&v14, v5, 0);
  if ( (unsigned int)inline_copy_from_user((__int64)&v14, a2, v5) )
    goto LABEL_5;
  printk(&unk_9EDE, "aw86320", 827, "speed_store", &v14, v6, v7);
  if ( (_DWORD)v14 == 1751607656 && WORD2(v14) == 10 )
  {
    v12 = 80;
    v11 = 80;
LABEL_20:
    v13 = v12;
    goto LABEL_21;
  }
  if ( !((unsigned int)v14 ^ 0xA64696D | BYTE4(v14)) )
  {
    v12 = 70;
    v11 = 70;
    goto LABEL_20;
  }
  if ( !((unsigned int)v14 ^ 0xA776F6C | BYTE4(v14)) )
  {
    v12 = 60;
    v11 = 60;
    goto LABEL_20;
  }
  if ( (unsigned int)kstrtouint(&v14, 0, &v13) )
  {
LABEL_5:
    v5 = -22;
    goto LABEL_6;
  }
  v11 = v13;
  if ( v13 >= 0x5A )
    v12 = 90;
  else
    v12 = v13;
LABEL_21:
  *(_DWORD *)(v4 + 8) = v12;
  printk(&unk_978B, "aw86320", 849, "speed_store", v11, v12, v9);
  if ( *(int *)(v4 + 16) >= 1 )
    aw86320_play_atsin0(*(_DWORD *)(v4 + 12), *(_DWORD *)(v4 + 8), *(unsigned __int16 *)(v4 + 20));
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return v5;
}
