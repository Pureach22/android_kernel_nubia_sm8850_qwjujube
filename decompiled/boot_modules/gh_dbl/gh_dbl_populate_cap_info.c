__int64 __fastcall gh_dbl_populate_cap_info(int a1, __int64 a2, int a3, int a4)
{
  _QWORD *v4; // x20
  __int64 v6; // x21
  __int64 v8; // x4
  unsigned int v10; // w22
  void *v11; // x0

  if ( gh_dbl_initialized != 1 )
    return 4294967285LL;
  if ( (unsigned int)(a1 - 266) <= 0xFFFFFFF5 )
  {
    printk(&unk_76E7, 256);
    return 4294967274LL;
  }
  if ( (a1 & 0xFu) >= 0xB )
  {
    __break(0x5512u);
    goto LABEL_24;
  }
  v4 = &gh_dbl_cap_table[12 * (a1 & 0xF)];
  if ( a3 != 1 )
  {
    if ( !a3 )
    {
      if ( a4 < 1 )
      {
        v6 = 96LL * (a1 & 0xF);
        raw_spin_lock(v4 + 1);
        if ( (v6 | 0x10uLL) <= 0x3C0 )
        {
          v4[2] = a2;
          raw_spin_unlock(v4 + 1);
          _wake_up(v4 + 9, 1, 1, 0);
          return 0;
        }
        goto LABEL_24;
      }
      v11 = &unk_7720;
LABEL_21:
      printk(v11, "gh_dbl_populate_cap_info");
      return 4294967290LL;
    }
    printk(&unk_787F, "gh_dbl_populate_cap_info");
    return 4294967274LL;
  }
  if ( a4 <= 0 )
  {
    v11 = &unk_7824;
    goto LABEL_21;
  }
  if ( (a1 & 0xF) == 0xA )
  {
LABEL_24:
    __break(1u);
    return gh_dbl_rx_callback_thread();
  }
  v8 = v4[6];
  *((_DWORD *)v4 + 10) = a4;
  v10 = request_threaded_irq(
          (unsigned int)a4,
          0,
          gh_dbl_rx_callback_thread,
          8193,
          v8,
          &gh_dbl_cap_table[12 * (a1 & 0xF)]);
  if ( (v10 & 0x80000000) != 0 )
  {
    printk(&unk_78EA, "gh_dbl_populate_cap_info");
  }
  else
  {
    irq_set_irq_wake((unsigned int)a4, 1);
    raw_spin_lock(v4 + 1);
    v4[4] = a2;
    raw_spin_unlock(v4 + 1);
    _wake_up(v4 + 9, 1, 1, 0);
  }
  return v10;
}
