__int64 __fastcall set_game_start_pid(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned int v5; // w0
  __int64 v6; // x2
  unsigned int v8; // w20
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  v5 = kstrtoll(a3, 0, v9);
  if ( v5 )
  {
    v8 = v5;
    printk(&unk_BC07, v5, v6);
    a4 = (int)v8;
  }
  else
  {
    game_status_pid = v9[0];
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
