__int64 __fastcall wcd_mbhc_hs_elec_irq(_QWORD *a1, unsigned int a2, char a3)
{
  __int64 result; // x0
  __int64 v7; // x8
  __int64 v8; // x1
  __int64 v9; // x0
  __int64 (__fastcall *v10)(__int64, __int64); // x8
  __int64 v11; // x9
  _QWORD *v12; // x10
  __int64 v13; // x8
  unsigned __int64 v16; // x10
  unsigned __int64 v23; // x10

  result = mutex_is_locked(a1 + 93);
  if ( (result & 1) == 0 && (wcd_mbhc_hs_elec_irq___already_done & 1) == 0 )
  {
    wcd_mbhc_hs_elec_irq___already_done = 1;
    result = _warn_printk("%s: BCL should have acquired\n", "wcd_mbhc_hs_elec_irq");
    __break(0x800u);
    if ( a2 )
      goto LABEL_4;
LABEL_7:
    v7 = 12;
    goto LABEL_8;
  }
  if ( !a2 )
    goto LABEL_7;
LABEL_4:
  if ( a2 != 1 )
    return result;
  v7 = 16;
LABEL_8:
  v8 = *(unsigned int *)(a1[99] + v7);
  if ( ((*(_QWORD *)((char *)a1 + (((unsigned __int64)a2 >> 3) & 0x1FFFFFF8) + 904) >> a2) & 1) != (a3 & 1) )
  {
    v9 = a1[27];
    v10 = *(__int64 (__fastcall **)(__int64, __int64))(a1[15] + 112LL);
    if ( *((_DWORD *)v10 - 1) != 542830841 )
      __break(0x8228u);
    result = v10(v9, v8);
    v11 = a2 >> 6;
    v12 = a1 + 113;
    v13 = 1LL << a2;
    if ( (a3 & 1) != 0 )
    {
      _X9 = &v12[v11];
      __asm { PRFM            #0x11, [X9] }
      do
        v16 = __ldxr(_X9);
      while ( __stxr(v16 | v13, _X9) );
    }
    else
    {
      _X9 = &v12[v11];
      __asm { PRFM            #0x11, [X9] }
      do
        v23 = __ldxr(_X9);
      while ( __stxr(v23 & ~v13, _X9) );
    }
  }
  return result;
}
