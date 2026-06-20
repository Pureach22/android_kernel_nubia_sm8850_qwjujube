__int64 __fastcall dp_bridge_hpd_simulate_connect(__int64 a1, char a2)
{
  __int64 v2; // x10
  void (__fastcall *v3)(_QWORD); // x9
  void (__fastcall *v4)(_QWORD); // x10
  __int64 v5; // x0
  void *v6; // x0

  if ( !a1 )
  {
    printk(&unk_256395, "dp_bridge_hpd_simulate_connect");
    return 4294967274LL;
  }
  if ( a1 == 8 )
  {
    v6 = &unk_256395;
  }
  else
  {
    v2 = *(_QWORD *)(a1 + 184);
    *(_WORD *)(a1 + 8) = a2 & 1;
    *(_BYTE *)(a1 + 10) = a2 & 1;
    if ( v2 )
    {
      v3 = *(void (__fastcall **)(_QWORD))v2;
      if ( *(_QWORD *)v2 )
      {
        v4 = *(void (__fastcall **)(_QWORD))(v2 + 8);
        if ( v4 )
        {
          v5 = *(_QWORD *)(a1 - 8);
          if ( (a2 & 1) != 0 )
          {
            if ( *((_DWORD *)v3 - 1) != 711998475 )
              __break(0x8229u);
            v3(v5);
          }
          else
          {
            if ( *((_DWORD *)v4 - 1) != 711998475 )
              __break(0x822Au);
            v4(v5);
          }
          return 0;
        }
      }
    }
    v6 = &unk_2115E8;
  }
  printk(v6, "dp_bridge_hpd_connect");
  return 0;
}
