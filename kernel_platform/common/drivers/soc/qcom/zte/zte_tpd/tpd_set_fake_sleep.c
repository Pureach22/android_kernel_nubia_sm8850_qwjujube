__int64 __fastcall tpd_set_fake_sleep(__int64 a1, int a2, __int64 a3)
{
  _DWORD *v3; // x8
  int v4; // w9

  v3 = *(_DWORD **)(a1 + 3072);
  v4 = v3[351];
  v3[379] = a2;
  if ( v4 == 1 )
  {
    v3[378] = a2;
    is_fake_sleep_mode = a2;
  }
  else
  {
    printk(unk_3B5E0, "tpd_set_fake_sleep", a3);
  }
  return 0;
}
