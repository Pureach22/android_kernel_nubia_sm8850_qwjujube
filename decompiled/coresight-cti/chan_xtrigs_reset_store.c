unsigned int *__fastcall chan_xtrigs_reset_store(__int64 a1, __int64 a2, __int64 a3, unsigned int *a4)
{
  __int64 v5; // x20
  __int64 v6; // x21
  __int64 v7; // x8
  int v8; // w8
  int v9; // w10

  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  raw_spin_lock(v5 + 56);
  if ( *(int *)(v5 + 68) >= 1 )
  {
    v6 = 0;
    do
    {
      if ( v6 == 128 )
      {
        __break(0x5512u);
        atomic_load(a4);
        JUMPOUT(0xBF64);
      }
      v7 = v5 + 4 * v6;
      *(_DWORD *)(v7 + 140) = 0;
      *(_DWORD *)(v7 + 652) = 0;
      if ( v6 == *(_DWORD *)(*(_QWORD *)(v5 + 1208) + 8LL) )
        cti_trigin_gpio_disable(v5);
      if ( v6 == *(_DWORD *)(*(_QWORD *)(v5 + 1216) + 8LL) )
        cti_trigout_gpio_disable(v5);
      ++v6;
    }
    while ( v6 < *(int *)(v5 + 68) );
  }
  v8 = *(_DWORD *)(v5 + 64);
  v9 = *(unsigned __int8 *)(v5 + 77);
  *(_DWORD *)(v5 + 1168) = 0;
  *(_DWORD *)(v5 + 132) = 0;
  *(_BYTE *)(v5 + 136) = 0;
  *(_BYTE *)(v5 + 129) = 0;
  *(_DWORD *)(v5 + 1164) = 0xFFFFFFFFFFFFFFFFLL >> -(char)v8;
  if ( v9 == 1 && *(_BYTE *)(v5 + 76) == 1 )
    cti_write_all_hw_regs((_QWORD *)v5);
  raw_spin_unlock(v5 + 56);
  return a4;
}
