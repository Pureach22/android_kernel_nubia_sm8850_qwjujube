__int64 __fastcall tpd_set_screen_off_awake(__int64 a1, int a2, __int64 a3)
{
  _DWORD *v3; // x8
  int v4; // w9

  v3 = *(_DWORD **)(a1 + 3072);
  v4 = v3[351];
  v3[381] = a2;
  if ( v4 == 1 )
  {
    v3[380] = a2;
    is_screen_off_awake_mode = a2;
  }
  else
  {
    printk(unk_3B5E0, "tpd_set_screen_off_awake", a3);
  }
  return 0;
}
