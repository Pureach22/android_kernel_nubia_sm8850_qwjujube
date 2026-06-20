__int64 __fastcall pmic_arb_read_cmd(__int64 a1, char a2, unsigned int a3, unsigned int a4, __int64 a5, __int64 a6)
{
  _QWORD *v12; // x20
  __int64 v13; // x27
  _DWORD *v14; // x8
  unsigned int v15; // w22
  __int64 v16; // x0
  __int64 result; // x0
  _DWORD *v18; // x8
  unsigned int v19; // w27
  __int64 v20; // x26
  __int64 *v21; // x28
  unsigned int v22; // w23
  unsigned int v23; // w24
  int v24; // w8
  int src; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v26; // [xsp+8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_QWORD **)(a1 + 152);
  v13 = *v12;
  v14 = *(_DWORD **)(*(_QWORD *)(*v12 + 56LL) + 40LL);
  if ( *(v14 - 1) != 1307277261 )
    __break(0x8228u);
  v15 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, _QWORD, __int64))v14)(v12, a3, a4, 1);
  if ( (v15 & 0x80000000) != 0 )
  {
    result = v15;
  }
  else
  {
    if ( (unsigned __int8)(a6 - 1) >= 8u )
    {
      dev_err(v12[5], "pmic-arb supports 1..%d bytes per trans, but:%zu requested\n", 8, a6);
      result = 4294967274LL;
      goto LABEL_21;
    }
    if ( a2 <= 95 )
    {
      if ( (a2 & 0xF0) == 0x20 )
      {
        v16 = 13;
      }
      else
      {
        if ( (a2 & 0xF8) != 0x38 )
        {
          result = 4294967274LL;
          goto LABEL_21;
        }
        v16 = 1;
      }
    }
    else
    {
      v16 = 15;
    }
    v18 = *(_DWORD **)(*(_QWORD *)(v13 + 56) + 48LL);
    if ( *(v18 - 1) != 1860309901 )
      __break(0x8228u);
    v19 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v18)(v16, a3, a4);
    v20 = raw_spin_lock_irqsave(v12 + 6);
    v21 = **(__int64 ***)(a1 + 152);
    writel_relaxed(v19, (unsigned int *)(*v21 + v15));
    v22 = pmic_arb_wait_for_done(a1, *v21, a3, a4);
    if ( !v22 )
    {
      v23 = (unsigned __int8)(a6 - 1);
      if ( v23 >= 3 )
        v24 = 3;
      else
        v24 = (unsigned __int8)(a6 - 1);
      src = *(_DWORD *)(*v21 + v15 + 24);
      memcpy((void *)a5, &src, (unsigned int)(v24 + 1));
      if ( v23 >= 4 )
      {
        src = *(_DWORD *)(*v21 + v15 + 28);
        memcpy((void *)(a5 + 4), &src, (((int)a6 - 1) & 3LL) + 1);
      }
    }
    raw_spin_unlock_irqrestore(v12 + 6, v20);
    result = v22;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
