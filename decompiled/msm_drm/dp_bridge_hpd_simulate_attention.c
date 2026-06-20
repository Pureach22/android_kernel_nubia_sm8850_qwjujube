__int64 __fastcall dp_bridge_hpd_simulate_attention(__int64 a1)
{
  __int64 v1; // x9
  void (__fastcall *v2)(_QWORD); // x9
  __int64 v3; // x0

  if ( a1 )
  {
    if ( a1 == 8 )
    {
      printk(&unk_256395, "dp_bridge_hpd_attention");
    }
    else
    {
      v1 = *(_QWORD *)(a1 + 184);
      *(_BYTE *)(a1 + 9) = 1;
      if ( v1 )
      {
        v2 = *(void (__fastcall **)(_QWORD))(v1 + 16);
        if ( v2 )
        {
          v3 = *(_QWORD *)(a1 - 8);
          if ( *((_DWORD *)v2 - 1) != 711998475 )
            __break(0x8229u);
          v2(v3);
        }
      }
    }
    return 0;
  }
  else
  {
    printk(&unk_256395, "dp_bridge_hpd_simulate_attention");
    return 4294967274LL;
  }
}
