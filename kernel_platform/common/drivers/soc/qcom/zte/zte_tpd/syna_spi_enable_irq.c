__int64 __fastcall syna_spi_enable_irq(__int64 *a1, char a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v6; // x2
  unsigned int v7; // w20
  void *v8; // x0
  char v9; // w8

  v3 = *a1;
  if ( !*a1 )
  {
    printk(unk_3A459, "syna_spi_enable_irq", a3);
    return 4294967290LL;
  }
  if ( *(_DWORD *)(v3 + 184) )
  {
    mutex_lock(v3 + 192);
    if ( (a2 & 1) != 0 )
    {
      if ( (*(_BYTE *)(v3 + 188) & 1) != 0 )
      {
        v7 = 0;
        v8 = unk_36B7E;
LABEL_14:
        printk(v8, "syna_spi_enable_irq", v6);
        mutex_unlock(v3 + 192);
        return v7;
      }
      enable_irq(*(unsigned int *)(v3 + 184));
      v8 = unk_3AB5E;
      v9 = 1;
    }
    else
    {
      if ( !*(_BYTE *)(v3 + 188) )
      {
        v7 = 0;
        v8 = unk_3493A;
        goto LABEL_14;
      }
      disable_irq_nosync(*(unsigned int *)(v3 + 184));
      v9 = 0;
      v8 = unk_3C5AA;
    }
    v7 = 1;
    *(_BYTE *)(v3 + 188) = v9;
    goto LABEL_14;
  }
  return 4294967290LL;
}
