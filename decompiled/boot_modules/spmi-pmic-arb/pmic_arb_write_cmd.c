__int64 __fastcall pmic_arb_write_cmd(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3,
        unsigned int a4,
        __int64 a5,
        __int64 a6)
{
  _QWORD *v12; // x19
  __int64 v13; // x27
  _DWORD *v14; // x8
  unsigned int v15; // w22
  __int64 v16; // x0
  _DWORD *v17; // x8
  unsigned int v18; // w27
  unsigned int v19; // w26
  __int64 v20; // x28
  int v21; // w8
  __int64 v23; // [xsp+8h] [xbp-18h]
  int dest; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v25; // [xsp+18h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD **)(a1 + 152);
  v13 = *v12;
  v14 = *(_DWORD **)(*(_QWORD *)(*v12 + 56LL) + 40LL);
  if ( *(v14 - 1) != 1307277261 )
    __break(0x8228u);
  v15 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, _QWORD, _QWORD))v14)(v12, a3, a4, 0);
  if ( (v15 & 0x80000000) == 0 )
  {
    if ( (unsigned __int8)(a6 - 1) >= 8u )
    {
      dev_err(v12[5], "pmic-arb supports 1..%d bytes per trans, but:%zu requested\n", 8, a6);
      v15 = -22;
      goto LABEL_23;
    }
    if ( (a2 & 0xE0) == 0x40 )
    {
      v16 = 14;
    }
    else if ( a2 >= 0x10u )
    {
      if ( (a2 & 0xF8) == 0x30 )
      {
        v16 = 0;
      }
      else
      {
        if ( (a2 & 0x80) == 0 )
        {
          v15 = -22;
          goto LABEL_23;
        }
        v16 = 16;
      }
    }
    else
    {
      v16 = 2;
    }
    v17 = *(_DWORD **)(*(_QWORD *)(v13 + 56) + 48LL);
    if ( *(v17 - 1) != 1860309901 )
      __break(0x8228u);
    v18 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v17)(v16, a3, a4);
    v23 = raw_spin_lock_irqsave(v12 + 6);
    v19 = (unsigned __int8)(a6 - 1);
    v20 = **(_QWORD **)(a1 + 152);
    if ( v19 >= 3 )
      v21 = 3;
    else
      v21 = (unsigned __int8)(a6 - 1);
    dest = 0;
    memcpy(&dest, (const void *)a5, (unsigned int)(v21 + 1));
    *(_DWORD *)(*(_QWORD *)(v20 + 8) + v15 + 16LL) = dest;
    if ( v19 >= 4 )
    {
      dest = 0;
      memcpy(&dest, (const void *)(a5 + 4), (((_BYTE)a6 - 1) & 3) + 1LL);
      *(_DWORD *)(*(_QWORD *)(v20 + 8) + v15 + 20LL) = dest;
    }
    writel_relaxed(v18, (unsigned int *)(*(_QWORD *)(v20 + 8) + v15));
    v15 = pmic_arb_wait_for_done(a1, *(_QWORD *)(v20 + 8), a3, a4);
    raw_spin_unlock_irqrestore(v12 + 6, v23);
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return v15;
}
